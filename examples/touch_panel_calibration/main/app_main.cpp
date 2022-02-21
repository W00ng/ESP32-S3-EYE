#include "who_camera.h"
#include "who_human_face_detection.hpp"
#include "who_lcd.h"
#include "esp_log.h"
#include "ns2009.h"

static const char *TAG = "main";

static QueueHandle_t xQueueAIFrame = NULL;
static QueueHandle_t xQueueLCDFrame = NULL;

extern "C" void app_main()
{
    /* Initialize I2C 400KHz */
    ESP_ERROR_CHECK(bsp_i2c_init(I2C_NUM_0, 400000));
    
    xQueueLCDFrame = xQueueCreate(2, sizeof(camera_fb_t *));
    register_lcd(xQueueLCDFrame, NULL, true);

    ns2009_init();
    touch_panel_calibration();

    uint16_t x, y;    
    while (1)
    {
        if(ESP_OK == ns2009_get_pos(&x, &y)){
            app_lcd_draw_point(x, y, COLOR_BLACK);
        }
        vTaskDelay(30/portTICK_PERIOD_MS);
    }
}
