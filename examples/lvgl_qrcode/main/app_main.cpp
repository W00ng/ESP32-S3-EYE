#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "esp_system.h"
#include "lvgl.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"
#include "lv_port_fs.h"

static const char *TAG = "main";

void ui_task(void *arg)
{
    static lv_obj_t *default_src;
    default_src = lv_scr_act();

    lv_style_t style2;
    // lv_style_set_bg_color(&style2, lv_color_white());
    lv_style_set_bg_color(&style2, lv_color_white());  //LV_PALETTE_RED
    lv_obj_add_style(default_src, &style2, _LV_STYLE_STATE_CMP_SAME);

    lv_obj_t * label = lv_label_create(default_src);          /*Add a label to the button*/
    lv_label_set_text(label, "hello_world\n1234567");        /*Set the labels text*/
    lv_obj_align(label, LV_ALIGN_TOP_LEFT, 10, 10);
    lv_style_t style;
    lv_style_init(&style);
    lv_style_set_text_color(&style, lv_palette_main(LV_PALETTE_BLUE));
    lv_style_set_text_font(&style, &lv_font_montserrat_14);
    lv_style_set_text_opa(&style, LV_OPA_90);
    lv_style_set_text_letter_space(&style, 3);
    lv_style_set_text_line_space(&style, 10);
    lv_obj_add_style(label, &style, 0); 

    lv_obj_t *slid = lv_slider_create(default_src);
    lv_slider_set_range(slid, 0, 100);
    lv_slider_set_value(slid, 80, LV_ANIM_ON);
    lv_obj_align(slid, LV_ALIGN_BOTTOM_MID, 0, -20);

    lv_obj_t *arc = lv_arc_create(default_src);
    lv_arc_set_range(arc, 0 , 300);
    lv_arc_set_value(arc, 100);
    lv_obj_set_pos(arc, 10, 60);

    static char *str = "this is test qrcode!";
    lv_obj_t *qrcode = lv_qrcode_create(default_src, 150, lv_color_black(), lv_color_white());
    lv_qrcode_update(qrcode, str, strlen(str));
    // lv_obj_align(qrcode, LV_ALIGN_TOP_MID, 100, 50); 
    lv_obj_set_pos(qrcode, 160, 30);
    // vTaskDelay((3000) / portTICK_PERIOD_MS);
    // lv_qrcode_delete(qrcode);

    while(1) 
    {
        vTaskDelay((1000) / portTICK_PERIOD_MS);
    }
}

void lv_tick_task(void *arg)
{
    while(1) 
    {
        vTaskDelay((20) / portTICK_PERIOD_MS);
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

    xTaskCreate(lv_tick_task, "lv_tick_task", 4096, NULL, 1, NULL);
    xTaskCreate(ui_task, "ui_task", 4096*4, NULL, 3, NULL);

}
