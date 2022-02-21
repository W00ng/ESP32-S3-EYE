/**
 * @file ns2009.h
 * @brief 
 * @version 0.1
 * @date 2021-09-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "ns2009.h"

static const char *TAG = "ns2009";

#define I2C_ACK_CHECK_EN 0x1  /*!< I2C master will check ack from slave*/
#define I2C_ACK_CHECK_DIS 0x0 /*!< I2C master will not check ack from slave */

static uint16_t lcd_width = 320, lcd_height = 240;
static tp_dev_t tp_dev;
static i2c_bus_device_handle_t ns2009_handle = NULL;

static esp_err_t ns2009_read(uint8_t command, uint16_t *data)
{
    uint8_t temp[2];
    i2c_cmd_handle_t cmd = i2c_cmd_link_create();

    i2c_master_start(cmd);
    i2c_master_write_byte(cmd, (NS2009_ADDR << 1) | I2C_MASTER_WRITE, I2C_ACK_CHECK_EN);
    i2c_master_write_byte(cmd, command, I2C_ACK_CHECK_EN);
    i2c_master_stop(cmd);

    i2c_bus_cmd_begin(ns2009_handle, cmd);
    i2c_cmd_link_delete(cmd);

    cmd = i2c_cmd_link_create();
    i2c_master_start(cmd);
    i2c_master_write_byte(cmd, (NS2009_ADDR << 1) | I2C_MASTER_READ, I2C_ACK_CHECK_EN);
    i2c_master_read(cmd, temp, 2, I2C_MASTER_LAST_NACK);
    i2c_master_stop(cmd);

    i2c_bus_cmd_begin(ns2009_handle, cmd);
    i2c_cmd_link_delete(cmd);

    if ((command & 0x02) == NS2009_ADC_8BIT)
    {
        *data = temp[0]; //8 bits mode
    }
    else
    {
        *data = ((temp[0] << 8) | temp[1]) >> 4; //12 bits mode
    }

    return ESP_OK;
}

esp_err_t ns2009_init(void)
{
    if (NULL != ns2009_handle){
        return ESP_FAIL;
    }

    bsp_i2c_add_device(&ns2009_handle, NS2009_ADDR);

    if (NULL == ns2009_handle){
        return ESP_FAIL;
    }

    esp_err_t ret;
    ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ESP_ERROR_CHECK(nvs_flash_init());
    }

    nvs_handle_t nvs_handle;
    nvs_open("List", NVS_READONLY, &nvs_handle);
    
    int16_t temp[4] = {0,0,0,0}; 
    ret = nvs_get_i16(nvs_handle, "xfac", temp + 0);
    if(ret != ESP_OK)
    {
        ESP_LOGI(TAG,"touch panel uncalibrated, use default parameters");
        tp_dev.xfac = -0.090;
        tp_dev.xoff = 332;
        tp_dev.yfac = 0.067;
        tp_dev.yoff = -18;
    }else
    {
        nvs_get_i16(nvs_handle, "xoff", temp + 1);
        nvs_get_i16(nvs_handle, "yfac", temp + 2);
        nvs_get_i16(nvs_handle, "yoff", temp + 3);
        for(uint8_t i = 0; i < 4; i++)
        {
            if(temp[i] & 0x8000){  //negative number
                temp[i] = temp[i] - 65536;
            }   
        }
        tp_dev.xfac = (float)temp[0] / 1000.0;
        tp_dev.xoff = temp[1];
        tp_dev.yfac = (float)temp[2] / 1000.0;
        tp_dev.yoff = temp[3];
    }
    ESP_LOGI(TAG, "xfac=%.3f xoff=%d yfac=%0.3f yoff=%d", tp_dev.xfac, tp_dev.xoff, tp_dev.yfac, tp_dev.yoff);
    nvs_close(nvs_handle);

    ESP_LOGI(TAG, "ns2009 init ok");
    return ESP_OK;
}

esp_err_t ns2009_get_press(uint16_t *press)
{
    ns2009_read(NS2009_READ_Z1, press);
    // ESP_LOGI(TAG, "%d", *press);
    if ((*press > NS2009_Z1_THRESHOLD_MIN) && (*press < NS2009_Z1_THRESHOLD_MAX))
    {
        return ESP_OK;
    }
    else
    {
        return ESP_FAIL;
    }
}

#define ERR_RANGE 50
esp_err_t ns2009_get_XY(uint16_t *x, uint16_t *y)
{
    uint16_t x1, y1;
    uint16_t x2, y2;

    ns2009_read(NS2009_READ_X, &x1);
    ns2009_read(NS2009_READ_Y, &y1);
    ns2009_read(NS2009_READ_X, &x2);
    ns2009_read(NS2009_READ_Y, &y2);
    if (((x2 <= x1 && x1 < x2 + ERR_RANGE) || (x1 <= x2 && x2 < x1 + ERR_RANGE)) && ((y2 <= y1 && y1 < y2 + ERR_RANGE) || (y1 <= y2 && y2 < y1 + ERR_RANGE)))
    {
        *x = (x1 + x2) / 2;
        *y = (y1 + y2) / 2;
        return ESP_OK;
    }
    else
    {
        *x = 0;
        *y = 0;
        return ESP_FAIL;
    }
}

esp_err_t ns2009_get_pos(uint16_t *x, uint16_t *y)
{
    uint16_t press, posx, posy;
    int temp;

    if (ESP_OK == ns2009_get_press(&press))
    {
        if(ESP_OK == ns2009_get_XY(&posx, &posy))
        {
            temp = tp_dev.xfac * posy + tp_dev.xoff;
            if (temp < 0) temp = 0;
            else if (temp > lcd_width - 1) temp = lcd_width - 1;
            *x = temp;

            temp = tp_dev.yfac * posx + tp_dev.yoff;
            if (temp < 0) temp = 0;
            else if (temp > lcd_height - 1) temp = lcd_height - 1;
            *y = temp;

            ESP_LOGI(TAG, "x=%d y=%d", *x, *y);
            return ESP_OK;
        }else{
            return ESP_FAIL;            
        }
    }
    else
    {
        return ESP_FAIL;
    }
}

esp_err_t ns2009_get_pos2(uint16_t *x, uint16_t *y)
{
    uint16_t posx, posy;
    int temp;

    if(ESP_OK == ns2009_get_XY(&posx, &posy))
    {
        temp = tp_dev.xfac * posy + tp_dev.xoff;
        if (temp < 0) temp = 0;
        else if (temp > lcd_width - 1) temp = lcd_width - 1;
        *x = temp;

        temp = tp_dev.yfac * posx + tp_dev.yoff;
        if (temp < 0) temp = 0;
        else if (temp > lcd_height - 1) temp = lcd_height - 1;
        *y = temp;

        return ESP_OK;
    }else{
        return ESP_FAIL;            
    }
}

esp_err_t touch_panel_calibration(void)
{
    uint16_t pos_temp[4][2]; //坐标缓存值
    uint16_t press, posx, posy;
    uint8_t cnt = 0;
    uint16_t d1, d2;
    uint32_t tem1, tem2;
    double fac;

    app_lcd_set_color(COLOR_WHITE);
    app_lcd_draw_touch_point(lcd_width - 20, 20, COLOR_BLACK);

    while (1)
    {
        if (ESP_OK == ns2009_get_press(&press))
        {
            ESP_ERROR_CHECK(ns2009_get_XY(&posx, &posy));
            pos_temp[cnt][0] = posx;
            pos_temp[cnt][1] = posy;
            while (1)
            {
                ns2009_get_press(&press);
                if (press < 10)
                    break;        //release
                vTaskDelay(100 / portTICK_PERIOD_MS);
            }

            cnt++;
            switch (cnt)
            {
            case 1:
                app_lcd_draw_touch_point(lcd_width - 20, 20, COLOR_WHITE);              
                app_lcd_draw_touch_point(lcd_width - 20, lcd_height - 20, COLOR_BLACK); 
                break;
            case 2:
                app_lcd_draw_touch_point(lcd_width - 20, lcd_height - 20, COLOR_WHITE); 
                app_lcd_draw_touch_point(20, 20, COLOR_BLACK);                         
                break;
            case 3:
                app_lcd_draw_touch_point(20, 20, COLOR_WHITE);         
                app_lcd_draw_touch_point(20, lcd_height - 20, COLOR_BLACK);
                break;
            case 4:
                app_lcd_draw_touch_point(20, lcd_height - 20, COLOR_WHITE);

                tem1 = abs(pos_temp[0][0] - pos_temp[1][0]); //x1-x2
                tem2 = abs(pos_temp[0][1] - pos_temp[1][1]); //y1-y2
                tem1 *= tem1;
                tem2 *= tem2;
                d1 = sqrt(tem1 + tem2);

                tem1 = abs(pos_temp[2][0] - pos_temp[3][0]); //x3-x4
                tem2 = abs(pos_temp[2][1] - pos_temp[3][1]); //y3-y4
                tem1 *= tem1;
                tem2 *= tem2;
                d2 = sqrt(tem1 + tem2);
                fac = (float)d1 / d2;
                if (fac < 0.95 || fac > 1.05 || d1 == 0 || d2 == 0) //fail
                {
                    cnt = 0;
                    app_lcd_set_color(COLOR_BLACK);
                    ESP_LOGI(TAG, "touch panel calibration filed! please try again!");
                    vTaskDelay(500 / portTICK_PERIOD_MS);
                    app_lcd_set_color(COLOR_WHITE);
                    app_lcd_draw_touch_point(lcd_width - 20, 20, COLOR_BLACK);
                    continue;
                }
                tem1 = abs(pos_temp[0][0] - pos_temp[2][0]); //x1-x3
                tem2 = abs(pos_temp[0][1] - pos_temp[2][1]); //y1-y3
                tem1 *= tem1;
                tem2 *= tem2;
                d1 = sqrt(tem1 + tem2);

                tem1 = abs(pos_temp[1][0] - pos_temp[3][0]); //x2-x4
                tem2 = abs(pos_temp[1][1] - pos_temp[3][1]); //y2-y4
                tem1 *= tem1;
                tem2 *= tem2;
                d2 = sqrt(tem1 + tem2);
                fac = (float)d1 / d2;
                if (fac < 0.95 || fac > 1.05) //fail
                {
                    cnt = 0;
                    app_lcd_set_color(COLOR_BLACK);
                    ESP_LOGI(TAG, "touch panel calibration filed! please try again!");
                    vTaskDelay(500 / portTICK_PERIOD_MS);
                    app_lcd_set_color(COLOR_WHITE);
                    app_lcd_draw_touch_point(lcd_width - 20, 20, COLOR_BLACK);
                    continue;
                }

                tem1 = abs(pos_temp[1][0] - pos_temp[2][0]); //x1-x3
                tem2 = abs(pos_temp[1][1] - pos_temp[2][1]); //y1-y3
                tem1 *= tem1;
                tem2 *= tem2;
                d1 = sqrt(tem1 + tem2);

                tem1 = abs(pos_temp[0][0] - pos_temp[3][0]); //x2-x4
                tem2 = abs(pos_temp[0][1] - pos_temp[3][1]); //y2-y4
                tem1 *= tem1;
                tem2 *= tem2;
                d2 = sqrt(tem1 + tem2);
                fac = (float)d1 / d2;
                if (fac < 0.95 || fac > 1.05) //fail
                {
                    cnt = 0;
                    app_lcd_set_color(COLOR_BLACK);
                    ESP_LOGI(TAG, "touch panel calibration filed! please try again!");
                    vTaskDelay(500 / portTICK_PERIOD_MS);
                    app_lcd_set_color(COLOR_WHITE);
                    app_lcd_draw_touch_point(lcd_width - 20, 20, COLOR_BLACK);
                    continue;
                }

                ESP_LOGI(TAG, "touch panel calibration success");
                tp_dev.xfac = (float)(lcd_width - 40) / (pos_temp[0][1] - pos_temp[2][1]);
                tp_dev.xoff = (lcd_width - tp_dev.xfac * (pos_temp[0][1] + pos_temp[2][1])) / 2;
                tp_dev.yfac = (float)(lcd_height - 40) / (pos_temp[1][0] - pos_temp[0][0]);
                tp_dev.yoff = (lcd_height - tp_dev.yfac * (pos_temp[1][0] + pos_temp[0][0])) / 2;
                ESP_LOGI(TAG, "xfac=%.3f xoff=%d yfac=%0.3f yoff=%d", tp_dev.xfac, tp_dev.xoff, tp_dev.yfac, tp_dev.yoff);

                nvs_handle_t nvs_handle;
                nvs_open("List", NVS_READWRITE, &nvs_handle);
                nvs_set_i16(nvs_handle, "xfac", tp_dev.xfac * 1000);
                nvs_set_i16(nvs_handle, "xoff", tp_dev.xoff);
                nvs_set_i16(nvs_handle, "yfac", tp_dev.yfac * 1000);
                nvs_set_i16(nvs_handle, "yoff", tp_dev.yoff);
                if(ESP_OK != nvs_commit(nvs_handle))
                {
                    ESP_LOGI(TAG, "NVS write fail");
                    continue;
                }
                nvs_close(nvs_handle);

                return ESP_OK;
            }
        }
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}
