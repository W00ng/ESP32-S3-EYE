/**
 * @file bsp_i2s.c
 * @brief 
 * @version 0.1
 * @date 2021-07-23
 * 
 * @copyright Copyright 2021 Espressif Systems (Shanghai) Co. Ltd.
 *
 *      Licensed under the Apache License, Version 2.0 (the "License");
 *      you may not use this file except in compliance with the License.
 *      You may obtain a copy of the License at
 *
 *               http://www.apache.org/licenses/LICENSE-2.0
 *
 *      Unless required by applicable law or agreed to in writing, software
 *      distributed under the License is distributed on an "AS IS" BASIS,
 *      WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *      See the License for the specific language governing permissions and
 *      limitations under the License.
 */

#include "bsp_i2s.h"

#define ADC_I2S_CHANNEL 2

static i2s_port_t I2S_CHN = I2S_NUM_0;
static int s_play_sample_rate = 16000;
static int s_play_channel_format = 1;
static int s_bits_per_chan = 16;

#define I2S_CONFIG_DEFAULT() { \
    .mode                   = I2S_MODE_MASTER | I2S_MODE_TX | I2S_MODE_RX, \
    .sample_rate            = sample_rate, \
    .bits_per_sample        = I2S_BITS_PER_SAMPLE_16BIT, \
    .channel_format         = I2S_CHANNEL_FMT_RIGHT_LEFT, \
    .communication_format   = I2S_COMM_FORMAT_STAND_I2S, \
    .intr_alloc_flags       = ESP_INTR_FLAG_LEVEL1, \
    .dma_buf_count          = 6, \
    .dma_buf_len            = 160, \
    .use_apll               = false, \
    .tx_desc_auto_clear     = true, \
    .fixed_mclk             = 0, \
    .mclk_multiple          = I2S_MCLK_MULTIPLE_DEFAULT, \
    .bits_per_chan          = I2S_BITS_PER_CHAN_16BIT, \
}

esp_err_t bsp_i2s_init(i2s_port_t i2s_num, uint32_t sample_rate, bool fmt_mono, bool bits_32)
{
    esp_err_t ret_val = ESP_OK;

    i2s_config_t i2s_config = I2S_CONFIG_DEFAULT();

    if(true == fmt_mono){
        i2s_config.channel_format = I2S_CHANNEL_FMT_ONLY_RIGHT;
        ESP_LOGI("i2s fmt", "channel format mono");
    }else {
        i2s_config.channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT;
    }

    if(true == bits_32){
        i2s_config.bits_per_sample = I2S_BITS_PER_SAMPLE_32BIT;
        i2s_config.bits_per_chan = I2S_BITS_PER_CHAN_32BIT;
        ESP_LOGI("i2s fmt", "i2s_bits_32");
    }else{
        i2s_config.bits_per_sample = I2S_BITS_PER_SAMPLE_16BIT;
        i2s_config.bits_per_chan = I2S_BITS_PER_CHAN_16BIT;
    }

    i2s_pin_config_t pin_config = {
        .bck_io_num = GPIO_I2S_SCLK,
        .ws_io_num = GPIO_I2S_LRCK,
        .data_out_num = GPIO_I2S_DOUT,
        .data_in_num = GPIO_I2S_DIN,
        .mck_io_num = GPIO_I2S_MCLK,
    };

    ret_val |= i2s_driver_install(i2s_num, &i2s_config, 0, NULL);
    ret_val |= i2s_set_pin(i2s_num, &pin_config);

    return ret_val;
}

esp_err_t bsp_i2s_deinit(i2s_port_t i2s_num)
{
    esp_err_t ret_val = ESP_OK;

    ret_val |= i2s_stop(i2s_num);
    ret_val |= i2s_driver_uninstall(i2s_num);

    return ret_val;
}

esp_err_t bsp_i2s_config(i2s_port_t i2s_num, uint32_t sample_rate, bool fmt_mono, bool bits_32)
{
    I2S_CHN = i2s_num;
    s_play_sample_rate = sample_rate;
    s_play_channel_format = 1;
    s_bits_per_chan = 16;

    bsp_i2s_init(i2s_num, sample_rate, fmt_mono, bits_32);

    return ESP_OK;
}

esp_err_t bsp_get_feed_data(int16_t *buffer, int buffer_len)
{
    esp_err_t ret = ESP_OK;
    size_t bytes_read;
    int audio_chunksize = buffer_len / (sizeof(int32_t));
    ret = i2s_read(I2S_CHN, buffer, buffer_len, &bytes_read, portMAX_DELAY);

    int32_t *tmp_buff = buffer;
    for (int i = 0; i < audio_chunksize; i++) {
        tmp_buff[i] = tmp_buff[i] >> 14; // 32:8为有效位， 8:0为低8位， 全为0， AFE的输入为16位语音数据，拿29：13位是为了对语音信号放大。
    }

    return ret;
}

int bsp_get_feed_channel(void)
{
    return ADC_I2S_CHANNEL;
}

esp_err_t i2s_audio_play(const int16_t* data, int length, TickType_t ticks_to_wait)
{
    // ESP_LOGI("debug", "sample_rate=%d channel_format=%d bits=%d", s_play_sample_rate, s_play_channel_format, s_bits_per_chan);
    size_t bytes_write = 0;
    esp_err_t ret = ESP_OK;
    int out_length= length;
    int audio_time = 1;
    audio_time *= (16000 / s_play_sample_rate);
    audio_time *= (2 / s_play_channel_format);

    int *data_out = NULL;
    if (s_bits_per_chan != 32) {
        out_length = length * 2;
        data_out = malloc(out_length);
        for (int i = 0; i < length / sizeof(int16_t); i++) {
            int ret = data[i];
            data_out[i] = ret << 16;
        }
    }

    int *data_out_1 = NULL;
    if (s_play_channel_format != 2 || s_play_sample_rate != 16000) {
        out_length *= audio_time;
        data_out_1 = malloc(out_length);
        int *tmp_data = NULL;
        if (data_out != NULL) {
            tmp_data = data_out;
        } else {
            tmp_data = data;
        }

        for (int i = 0; i < out_length / (audio_time * sizeof(int)); i++) {
            for (int j = 0; j < audio_time; j++) {
                data_out_1[audio_time * i + j] = tmp_data[i];
            }
        }
        if (data_out != NULL) {
            free(data_out);
            data_out = NULL;
        }
    }

    if (data_out != NULL) {
        ret = i2s_write(I2S_CHN, (const char*) data_out, out_length, &bytes_write, ticks_to_wait);
        free(data_out);
    } else if (data_out_1 != NULL) {
        ret = i2s_write(I2S_CHN, (const char*) data_out_1, out_length, &bytes_write, ticks_to_wait);
        free(data_out_1);
    } else {
        ret = i2s_write(I2S_CHN, (const char*) data_out, length, &bytes_write, ticks_to_wait);
    }

    return ret;
}




