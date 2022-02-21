#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "esp_system.h"
#include "lvgl.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"
#include "lv_port_fs.h"


#include "hdc1080.h"

#include "ws2812.h"

static const char *TAG = "main";

void my_task(void *arg)
{
    float temp, humid;

    while (1)
    {
        temp = hdc1080_get_temp();
        humid = hdc1080_get_humid();
        ESP_LOGI(TAG, "temp=%.1f°C", temp);
        ESP_LOGI(TAG, "humid=%.1f%%", humid);        

        ws2812_set_rgb(0, 255, 0, 0);
        ws2812_refresh();
        vTaskDelay(1000/portTICK_PERIOD_MS);    

        ws2812_set_rgb(0, 0, 0, 255);
        ws2812_refresh();
        vTaskDelay(1000/portTICK_PERIOD_MS);        
    }
    vTaskDelete(NULL);
}

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
    // lv_port_fs_init();         
    lv_port_tick_init();

    /* Init temp and humid sensor */
    ESP_ERROR_CHECK(hdc1080_init());

    /* Init WS2812 */
    ESP_ERROR_CHECK(ws2812_init());

    ESP_LOGI(TAG, "init done");

    xTaskCreate(lv_tick_task, "lv_tick_task", 4096, NULL, 1, NULL);
    xTaskCreate(my_task, "my_task", 4096 * 4, NULL, 3, NULL);
}
