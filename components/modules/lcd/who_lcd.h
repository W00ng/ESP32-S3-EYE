#pragma once

#include <stdint.h>
#include "esp_log.h"
#include "screen_driver.h"

#define BOARD_LCD_MOSI      (GPIO_NUM_40)
#define BOARD_LCD_MISO      (GPIO_NUM_NC)
#define BOARD_LCD_SCK       (GPIO_NUM_38)
#define BOARD_LCD_CS        (GPIO_NUM_45)
#define BOARD_LCD_DC        (GPIO_NUM_39)
#define BOARD_LCD_RST       (GPIO_NUM_NC)
#define BOARD_LCD_BL        (GPIO_NUM_2)
#define BOARD_LCD_PIXEL_CLOCK_HZ    (40 * 1000 * 1000)
#define BOARD_LCD_BK_LIGHT_ON_LEVEL 0
#define BOARD_LCD_BK_LIGHT_OFF_LEVEL !BOARD_LCD_BK_LIGHT_ON_LEVEL
#define BOARD_LCD_H_RES 240
#define BOARD_LCD_V_RES 320
#define BOARD_LCD_CMD_BITS 8
#define BOARD_LCD_PARAM_BITS 8
#define LCD_HOST SPI2_HOST

/* Color definitions, RGB565 format */
#define COLOR_BLACK       0x0000
#define COLOR_NAVY        0x000F
#define COLOR_DARKGREEN   0x03E0
#define COLOR_DARKCYAN    0x03EF
#define COLOR_MAROON      0x7800
#define COLOR_PURPLE      0x780F
#define COLOR_OLIVE       0x7BE0
#define COLOR_LIGHTGREY   0xC618
#define COLOR_DARKGREY    0x7BEF
#define COLOR_BLUE        0x001F
#define COLOR_GREEN       0x07E0
#define COLOR_CYAN        0x07FF
#define COLOR_RED         0xF800
#define COLOR_MAGENTA     0xF81F
#define COLOR_YELLOW      0xFFE0
#define COLOR_WHITE       0xFFFF
#define COLOR_ORANGE      0xFD20
#define COLOR_GREENYELLOW 0xAFE5
#define COLOR_PINK        0xF81F
#define COLOR_SILVER      0xC618
#define COLOR_GRAY        0x8410
#define COLOR_LIME        0x07E0
#define COLOR_TEAL        0x0410
#define COLOR_FUCHSIA     0xF81F
#define COLOR_ESP_BKGD    0xD185

#ifdef __cplusplus
extern "C"
{
#endif

esp_err_t register_lcd(const QueueHandle_t frame_i, const QueueHandle_t frame_o, const bool return_fb);

void app_lcd_draw_wallpaper();
void app_lcd_set_color(int color);
void app_lcd_draw_touch_point(uint16_t x,uint16_t y, int color);
void app_lcd_draw_point(uint16_t x,uint16_t y,int color);

#ifdef __cplusplus
}
#endif
