#include "who_lcd.h"
#include "esp_camera.h"
#include <stdio.h>
#include <string.h>
#include "logo_en_240x240_lcd.h"

static const char *TAG = "who_lcd";

static scr_driver_t g_lcd;
static scr_info_t g_lcd_info;

static QueueHandle_t xQueueFrameI = NULL;
static QueueHandle_t xQueueFrameO = NULL;
static bool gReturnFB = true;

static void task_process_handler(void *arg)
{
    camera_fb_t *frame = NULL;

    while (true)
    {
        if (xQueueReceive(xQueueFrameI, &frame, portMAX_DELAY))
        {
            g_lcd.draw_bitmap(0, 0, frame->width, frame->height, (uint16_t *)frame->buf);

            if (xQueueFrameO)
            {
                xQueueSend(xQueueFrameO, &frame, portMAX_DELAY);
            }
            else if (gReturnFB)
            {
                esp_camera_fb_return(frame);
            }
            else
            {
                free(frame);
            }
        }
    }
}

esp_err_t register_lcd(const QueueHandle_t frame_i, const QueueHandle_t frame_o, const bool return_fb)
{
    spi_config_t bus_conf = {
        .miso_io_num = BOARD_LCD_MISO,
        .mosi_io_num = BOARD_LCD_MOSI,
        .sclk_io_num = BOARD_LCD_SCK,
        .max_transfer_sz = 240 * 320 * sizeof(uint16_t) + 10,
    };
    spi_bus_handle_t spi_bus = spi_bus_create(SPI2_HOST, &bus_conf);

    scr_interface_spi_config_t spi_lcd_cfg = {
        .spi_bus = spi_bus,
        .pin_num_cs = BOARD_LCD_CS,
        .pin_num_dc = BOARD_LCD_DC,
        .clk_freq = 40 * 1000000,
        .swap_data = 0,
    };

    scr_interface_driver_t *iface_drv;
    scr_interface_create(SCREEN_IFACE_SPI, &spi_lcd_cfg, &iface_drv);
    esp_err_t ret = scr_find_driver(SCREEN_CONTROLLER_ST7789, &g_lcd);
    if (ESP_OK != ret)
    {
        return ret;
        ESP_LOGE(TAG, "screen find failed");
    }

    scr_controller_config_t lcd_cfg = {
        .interface_drv = iface_drv,
        .pin_num_rst = BOARD_LCD_RST,
        .pin_num_bckl = BOARD_LCD_BL,
        .rst_active_level = 0,
        .bckl_active_level = 0,
        .offset_hor = 0,
        .offset_ver = 0,
        .width = BOARD_LCD_H_RES,
        .height = BOARD_LCD_V_RES,
        .rotate = SCR_DIR_BTLR, //SCR_DIR_LRTB  SCR_DIR_TBRL
    };
    ret = g_lcd.init(&lcd_cfg);
    if (ESP_OK != ret)
    {
        return ESP_FAIL;
        ESP_LOGE(TAG, "screen initialize failed");
    }

    g_lcd.get_info(&g_lcd_info);
    ESP_LOGI(TAG, "Screen name:%s | width:%d | height:%d", g_lcd_info.name, g_lcd_info.width, g_lcd_info.height);

    app_lcd_set_color(COLOR_WHITE);
    vTaskDelay(pdMS_TO_TICKS(100));
    app_lcd_draw_wallpaper();
    vTaskDelay(pdMS_TO_TICKS(1000));

    xQueueFrameI = frame_i;
    xQueueFrameO = frame_o;
    gReturnFB = return_fb;
    xTaskCreatePinnedToCore(task_process_handler, TAG, 4 * 1024, NULL, 5, NULL, 0);

    return ESP_OK;
}

void app_lcd_draw_wallpaper()
{
    scr_info_t lcd_info;
    g_lcd.get_info(&lcd_info);

    uint16_t *pixels = (uint16_t *)heap_caps_malloc((logo_en_240x240_lcd_width * logo_en_240x240_lcd_height) * sizeof(uint16_t), MALLOC_CAP_8BIT | MALLOC_CAP_SPIRAM);
    if (NULL == pixels)
    {
        ESP_LOGE(TAG, "Memory for bitmap is not enough");
        return;
    }
    memcpy(pixels, logo_en_240x240_lcd, (logo_en_240x240_lcd_width * logo_en_240x240_lcd_height) * sizeof(uint16_t));
    g_lcd.draw_bitmap(40, 0, logo_en_240x240_lcd_width, logo_en_240x240_lcd_height, (uint16_t *)pixels);
    heap_caps_free(pixels);
}

void app_lcd_set_color(int color)
{
    scr_info_t lcd_info;
    g_lcd.get_info(&lcd_info);
    uint16_t *buffer = (uint16_t *)malloc(lcd_info.width * sizeof(uint16_t));
    if (NULL == buffer)
    {
        ESP_LOGE(TAG, "Memory for bitmap is not enough");
    }
    else
    {
        for (size_t i = 0; i < lcd_info.width; i++)
        {
            buffer[i] = color;
        }

        for (int y = 0; y < lcd_info.height; y++)
        {
            g_lcd.draw_bitmap(0, y, lcd_info.width, 1, buffer);
        }

        free(buffer);
    }
}

void app_lcd_draw_point(uint16_t x,uint16_t y,int color)
{
    g_lcd.draw_bitmap(x, y, 1, 1, &color);
} 

void app_lcd_draw_circle(uint16_t x0,uint16_t y0,uint8_t r,int color)
{
	int a = 0,b = r;
	  
	while(a <= b)
	{
		g_lcd.draw_bitmap(x0-b, y0-a, 1, 1, &color);             //3           
		g_lcd.draw_bitmap(x0+b, y0-a, 1, 1, &color);             //0           
		g_lcd.draw_bitmap(x0-a, y0+b, 1, 1, &color);             //1                
		g_lcd.draw_bitmap(x0-a, y0-b, 1, 1, &color);             //2             
		g_lcd.draw_bitmap(x0+b, y0+a, 1, 1, &color);             //4               
		g_lcd.draw_bitmap(x0+a, y0-b, 1, 1, &color);             //5
		g_lcd.draw_bitmap(x0+a, y0+b, 1, 1, &color);             //6 
		g_lcd.draw_bitmap(x0-b, y0+a, 1, 1, &color);             //7
		a++;
		if((a*a+b*b)>(r*r))
		{
			b--;
		}
	}
}

void app_lcd_draw_touch_point(uint16_t x,uint16_t y, int color)
{
    uint16_t buffer[30];
    for (uint16_t i = 0; i < 30; i++)
    {
        buffer[i] = color;
    }
    g_lcd.draw_bitmap(x - 12, y, 25, 1, buffer);   //draw horizontal line
    g_lcd.draw_bitmap(x, y - 12, 1, 25, buffer);   //draw vertical line
    g_lcd.draw_bitmap(x - 1, y - 1, 3, 1, buffer); //draw dot
    g_lcd.draw_bitmap(x - 1, y + 1, 3, 1, buffer);
	app_lcd_draw_circle(x, y, 6, buffer[0]);       //draw circle
}




