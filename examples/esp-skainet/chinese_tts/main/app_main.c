#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "esp_system.h"

#include "es8311.h"
#include "bsp_i2s.h"

#include "esp_tts.h"
#include "esp_tts_voice_xiaole.h"
#include "esp_tts_voice_template.h"
#include "esp_tts_player.h"
#include "ringbuf.h"

#include "tts_urat.h"

static const char *TAG = "main";

struct RingBuf *urat_rb = NULL;

void app_main()
{
    /* Initialize I2C 400KHz */
    ESP_ERROR_CHECK(bsp_i2c_init(I2C_NUM_0, 400000));

    es8311_codec_config(AUDIO_HAL_16K_SAMPLES);
    es8311_codec_set_voice_volume(70);
    bsp_i2s_config(I2S_NUM_0, 16000, false, true);

    /*** 1. create esp tts handle ***/
    // method1: use pre-define xiaole voice lib.
    // This method is not recommended because the method may make app bin exceed the limit of esp32  
    esp_tts_voice_t *voice=&esp_tts_voice_xiaole;

    // method2: initial voice set from separate voice data partition
    /* 
    const esp_partition_t* part=esp_partition_find_first(ESP_PARTITION_TYPE_DATA, ESP_PARTITION_SUBTYPE_ANY, "voice_data");
    if (part==NULL) { 
        printf("Couldn't find voice data partition!\n"); 
        return 0;
    } else {
        printf("voice_data paration size:%d\n", part->size);
    }
    spi_flash_mmap_handle_t mmap;
    uint16_t* voicedata;
    esp_err_t err=esp_partition_mmap(part, 0, part->size, SPI_FLASH_MMAP_DATA, &voicedata, &mmap);
    if (err != ESP_OK) {
        printf("Couldn't map voice data partition!\n"); 
        return 0;
    }
    esp_tts_voice_t *voice=esp_tts_voice_set_init(&esp_tts_voice_template, voicedata); 
    */

    esp_tts_handle_t *tts_handle=esp_tts_create(voice);

    /*** 2. play prompt text ***/
    char *prompt1="欢迎使用乐鑫语音合成助手";  
    printf("%s\n", prompt1);
    if (esp_tts_parse_chinese(tts_handle, prompt1)) {
            int len[1]={0};
            do {
                short *pcm_data=esp_tts_stream_play(tts_handle, len, 3);
                i2s_audio_play(pcm_data, len[0]*2, portMAX_DELAY);
                // printf("data:%d \n", len[0]);
            } while(len[0]>0);
            // i2s_zero_dma_buffer(0);
    }
    esp_tts_stream_reset(tts_handle);
#if 1
    ESP_LOGI(TAG, "tts play end");
    while(1)
    {
        vTaskDelay(5000 / portTICK_PERIOD_MS);
    }
#else
    /*** 3. play urat input text ***/
    urat_rb = rb_init(BUFFER_PROCESS+1, URAT_BUF_LEN, 1, NULL);  // urat ringbuf init
    char data[URAT_BUF_LEN+1];
    char in;
    int data_len=0;

    xTaskCreatePinnedToCore(&uartTask, "urat", 3 * 1024, NULL, 5, NULL, 0);
    char *prompt2="\n请输入短语:";
    printf("%s\n", prompt2);

    while (1) 
    {
        rb_read(urat_rb, (uint8_t *)&in, 1, portMAX_DELAY);

        if(in=='\n') {
            // start to run tts
            data[data_len]='\0'; 
            printf("tts input:%s\n", data);
            if (esp_tts_parse_chinese(tts_handle, data)) {
                int len[1]={0};
                do {
                    short *pcm_data=esp_tts_stream_play(tts_handle, len, 3);
                    i2s_audio_play(pcm_data, len[0]*2, portMAX_DELAY);
                } while(len[0]>0);
                i2s_zero_dma_buffer(0);
            }
            esp_tts_stream_reset(tts_handle);
            printf("%s\n", prompt2);
            data_len=0;
        } else if(data_len<URAT_BUF_LEN) {
            // append urat buffer into data
            data[data_len]=in; 
            data_len++;
        } else {
            printf("ERROR: out of range\n");
            data_len=0;
        }
    }
#endif
}
