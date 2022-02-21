/********************************
按下BOOT键：切换输出显示模式。
按下MENU：切换录入模式和检测模式。
按下PLAY键（录入模式）： 录入指示框内的颜色。
按下PLAY键（检测模式）： 删除最后一个被录入的颜色。
按下UP键（录入模式）： 增大指示框的尺寸。
按下UP键（检测模式）： 增大颜色检测过滤的最小色块的面积。
按下DN键（录入模式）： 减小指示框的尺寸。
按下DN键（检测模式）： 减小颜色检测过滤的最小色块的面积。
Press the Boot button: Switch the output display mode.
Press the MENU: Switch between color entry mode and color detection mode.
Press the PLAY (entry mode): Entry the color in the indicator box.
Press the PLAY (detection mode): Delete the last color that are entered.
Press the UP (entry mode): Increase the size of the indicator box.
Press the UP (detection mode): Increase the area of the smallest color block filtered by color detection.
Press the DN (entry mode): Decrease the size of the indicator box.
Press the DN (detection mode): Decrease the area of the smallest color block filtered by color detection.
***********************************/

#include "who_camera.h"
#include "who_color_detection.hpp"
#include "who_lcd.h"
#include "who_button.h"
#include "event_logic.hpp"
#include "who_adc_button.h"

static QueueHandle_t xQueueAIFrame = NULL;
static QueueHandle_t xQueueLCDFrame = NULL;
static QueueHandle_t xQueueADCKeyState = NULL;
static QueueHandle_t xQueueGPIOKeyState = NULL;
static QueueHandle_t xQueueEventLogic = NULL;

extern "C" void app_main()
{
    gpio_config_t gpio_conf;
    gpio_conf.mode = GPIO_MODE_OUTPUT_OD;
    gpio_conf.intr_type = GPIO_INTR_DISABLE;
    gpio_conf.pin_bit_mask = 1LL << GPIO_NUM_3;   //Status LED
    gpio_config(&gpio_conf);
    
    xQueueAIFrame = xQueueCreate(2, sizeof(camera_fb_t *));
    xQueueLCDFrame = xQueueCreate(2, sizeof(camera_fb_t *));
    xQueueADCKeyState = xQueueCreate(1, sizeof(int));
    xQueueGPIOKeyState = xQueueCreate(1, sizeof(int));
    xQueueEventLogic = xQueueCreate(1, sizeof(int));

    register_camera(PIXFORMAT_RGB565, FRAMESIZE_QVGA, 2, xQueueAIFrame);
    register_adc_button(NULL, 4, xQueueADCKeyState);
    register_button(GPIO_NUM_0, xQueueGPIOKeyState);
    register_event(xQueueADCKeyState, xQueueGPIOKeyState, xQueueEventLogic);
    register_color_detection(xQueueAIFrame, xQueueEventLogic, NULL, xQueueLCDFrame, false);
    register_lcd(xQueueLCDFrame, NULL, true);
}
