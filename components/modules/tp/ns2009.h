/**
 * @file ns2009.h
 * @brief 
 * @version 0.1
 * @date 2021-09-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "esp_err.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "bsp_i2c.h"
#include "i2c_bus.h"
#include "who_lcd.h"

#ifdef __cplusplus
extern "C" {
#endif

/** @brief NS2009 register map and function codes */
#define NS2009_ADDR            (0x48)

#define NS2009_MEASURE_X		(0xc << 4)
#define NS2009_MEASURE_Y		(0xd << 4)
#define NS2009_MEASURE_Z1		(0xe << 4)
#define NS2009_MEASURE_Z2		(0xf << 4)

#define NS2009_IRQ_EN           (0x0 << 2)
#define NS2009_IRQ_DIS          (0x1 << 2)

#define NS2009_ADC_12BIT        (0x0 << 1)
#define NS2009_ADC_8BIT         (0x1 << 1)


#define NS2009_READ_X		(NS2009_IRQ_EN | NS2009_ADC_12BIT | NS2009_MEASURE_X)
#define NS2009_READ_Y		(NS2009_IRQ_EN | NS2009_ADC_12BIT | NS2009_MEASURE_Y)
#define NS2009_READ_Z1		(NS2009_IRQ_EN | NS2009_ADC_12BIT | NS2009_MEASURE_Z1)
#define NS2009_READ_Z2		(NS2009_IRQ_EN | NS2009_ADC_12BIT | NS2009_MEASURE_Z2)

#define NS2009_Z1_THRESHOLD_MIN		70
#define NS2009_Z1_THRESHOLD_MAX		2000

typedef struct {
    float xfac;
    float yfac;
    int xoff;
    int yoff;
}tp_dev_t;


esp_err_t ns2009_init(void);
esp_err_t ns2009_get_press(uint16_t *data);
esp_err_t ns2009_get_pos(uint16_t *x, uint16_t *y);
esp_err_t ns2009_get_pos2(uint16_t *x, uint16_t *y);
esp_err_t touch_panel_calibration(void);

#ifdef __cplusplus
}
#endif
