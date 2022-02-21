#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "esp_system.h"
#include "lvgl.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"
#include "lv_port_fs.h"

#include "ui_main.h"
#include "app_audio.h"
#include "app_sr.h"
#include "app_led.h"
#include "app_network.h"


static const char *TAG = "main";

void lv_tick_task(void *arg)
{
    while(1) 
    {
        vTaskDelay((10) / portTICK_PERIOD_MS);
        lv_task_handler();        
    }
}

extern "C" void app_main()
{
    /* Initialize I2C 400KHz */
    ESP_ERROR_CHECK(bsp_i2c_init(I2C_NUM_0, 400000));

    /* LVGL init */
    lv_init();                
    lv_port_disp_init();	  
    lv_port_indev_init();     
    lv_port_fs_init();         
    lv_port_tick_init();

    ESP_ERROR_CHECK(ui_main_start());
    lv_task_handler();

    /* Start speech recognition task. I2S is initialized in task pinned to core 1 */
    ESP_ERROR_CHECK(app_audio_start());
    ESP_ERROR_CHECK(app_sr_start(false));

    ESP_ERROR_CHECK(app_led_init(GPIO_NUM_3));
    ESP_ERROR_CHECK(app_network_start("ESP-Box"));

    ESP_LOGI(TAG, "init done");

    /* Run LVGL task handler */
    while (vTaskDelay(2), true) {
        lv_task_handler();
    }
    // xTaskCreate(lv_tick_task, "lv_tick_task", 4096, NULL, 1, NULL);
}
