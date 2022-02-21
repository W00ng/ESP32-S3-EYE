/**
 * @file bsp_i2s.h
 * @brief 
 * @version 0.1
 * @date 2021-08-02
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

#pragma once

#include "driver/gpio.h"
#include "driver/i2s.h"

#include "esp_err.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"

#include "audio_hal.h"

#ifdef __cplusplus
extern "C" {
#endif

#define GPIO_I2S_MCLK    (GPIO_NUM_46)
#define GPIO_I2S_SCLK    (GPIO_NUM_43)
#define GPIO_I2S_LRCK    (GPIO_NUM_42)
#define GPIO_I2S_DOUT    (GPIO_NUM_41)
#define GPIO_I2S_DIN     (GPIO_NUM_44)


/**
 * @brief Init I2S bus
 * 
 * @param i2s_num I2S port num
 * @param sample_rate Audio sample rate. For I2S signal, it refers to LRCK/WS frequency
 * @return 
 *    - ESP_OK: Success
 *    - Others: Fail
 */
esp_err_t bsp_i2s_init(i2s_port_t i2s_num, uint32_t sample_rate, bool fmt_mono, bool bits_32);

/**
 * @brief Deinit I2S bus
 * 
 * @param i2s_num I2S port num
 * @return 
 *    - ESP_OK: Success
 *    - Others: Fail
 */
esp_err_t bsp_i2s_deinit(i2s_port_t i2s_num);

esp_err_t bsp_i2s_config(i2s_port_t i2s_num, uint32_t sample_rate, bool fmt_mono, bool bits_32);
esp_err_t bsp_get_feed_data(int16_t *buffer, int buffer_len);
int bsp_get_feed_channel(void);
esp_err_t i2s_audio_play(const int16_t* data, int length, TickType_t ticks_to_wait);

#ifdef __cplusplus
}
#endif
