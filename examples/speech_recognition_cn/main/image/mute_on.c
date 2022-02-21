#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
#include "lvgl.h"
#else
#include "lvgl.h"
#endif


#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_MUTE_ON
#define LV_ATTRIBUTE_IMG_MUTE_ON
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_MUTE_ON uint8_t mute_on_map[] = {
#if LV_COLOR_DEPTH == 1 || LV_COLOR_DEPTH == 8
  /*Pixel format: Blue: 2 bit, Green: 3 bit, Red: 3 bit, Alpha 8 bit */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0x07, 0x6d, 0x83, 0x6d, 0xe3, 0x6d, 0xfb, 0x6d, 0xd0, 0x6d, 0x53, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xe8, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6d, 0x08, 0x6d, 0xc8, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0x83, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xe8, 0xb4, 0xe4, 0x8b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6d, 0x70, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xfc, 0x6d, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xe5, 0x07, 0xe4, 0xb0, 0xe5, 0x97, 0xe0, 0x00, 0x00, 0x00, 0x49, 0xb8, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0x6b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0xe5, 0x07, 0xe5, 0xb0, 0xe5, 0x98, 0xe0, 0x00, 0x6d, 0xc7, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0x7b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xe5, 0x07, 0xe5, 0xaf, 0xe5, 0x9b, 0x6d, 0xc7, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x49, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe9, 0x04, 0xe5, 0xac, 0xc9, 0xe8, 0x69, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x49, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x03, 0xc9, 0xeb, 0xc9, 0xff, 0x69, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x49, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x69, 0xc8, 0xc9, 0xff, 0xc5, 0xff, 0x69, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x49, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x6d, 0x23, 0x6d, 0x43, 0x00, 0x00, 0x6d, 0xc7, 0x69, 0xff, 0xc9, 0xff, 0xc5, 0xff, 0x69, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x49, 0x7c, 0x00, 0x00, 0x49, 0x57, 0x49, 0x0f, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x6d, 0x58, 0x6d, 0x94, 0x00, 0x00, 0x6d, 0xc7, 0x6d, 0xff, 0x69, 0xff, 0xc5, 0xff, 0xc5, 0xff, 0x69, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x49, 0x7c, 0x00, 0x00, 0x6d, 0xbc, 0x6d, 0x2f, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x6d, 0x58, 0x6d, 0x94, 0x00, 0x00, 0x6d, 0xc7, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0xa5, 0xff, 0xc5, 0xff, 0x69, 0xff, 0x6d, 0xff, 0x49, 0x7c, 0x00, 0x00, 0x6d, 0xbc, 0x6d, 0x2f, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x6d, 0x58, 0x6d, 0x94, 0x00, 0x00, 0x6d, 0xc7, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0xa5, 0xff, 0xc5, 0xff, 0x69, 0xff, 0x49, 0x7c, 0x00, 0x00, 0x6d, 0xbc, 0x6d, 0x2f, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x6d, 0x4b, 0x49, 0xa3, 0x00, 0x00, 0x6d, 0xb8, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0xa5, 0xff, 0xc5, 0xff, 0x69, 0x70, 0x00, 0x00, 0x6d, 0xcc, 0x6d, 0x1f, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x49, 0x23, 0x6d, 0xd0, 0x00, 0x00, 0x6d, 0x73, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0xa5, 0xff, 0xe5, 0xc0, 0xa5, 0x10, 0x6d, 0xe4, 0x6e, 0x04, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0xcf, 0x6d, 0x34, 0x49, 0x0b, 0x6d, 0xcc, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0x88, 0xe1, 0x8f, 0xe5, 0xd3, 0x69, 0xa4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0x48, 0x6d, 0xcc, 0x49, 0x0b, 0x6d, 0x08, 0x6d, 0x88, 0x6d, 0xeb, 0x6d, 0xff, 0x6d, 0xd7, 0x6d, 0x58, 0x00, 0x00, 0x6d, 0x1c, 0xa5, 0xef, 0xe1, 0xc3, 0xe1, 0x08, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0x7c, 0x6d, 0xc4, 0x49, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6d, 0x33, 0x6d, 0xd7, 0x6d, 0x54, 0xe1, 0x83, 0xe1, 0xc0, 0xe1, 0x0c, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6d, 0x5b, 0x6d, 0xe0, 0x6d, 0xa0, 0x49, 0x60, 0x49, 0x4c, 0x6d, 0x68, 0x6d, 0xb0, 0x6d, 0xd7, 0x6d, 0x3f, 0x00, 0x00, 0x00, 0x00, 0xe1, 0x80, 0xe1, 0xc3, 0xe1, 0x0c, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6d, 0x08, 0x49, 0x53, 0x6d, 0x8c, 0x6d, 0xf3, 0x49, 0x83, 0x6d, 0x44, 0x6d, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe1, 0x80, 0xe1, 0xbc, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0x0b, 0x49, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe1, 0x34, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0x0b, 0x49, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6d, 0x1f, 0x6d, 0xe8, 0x6d, 0xef, 0x6d, 0xef, 0x6d, 0xef, 0x6d, 0xfc, 0x6d, 0xef, 0x6d, 0xef, 0x6d, 0xef, 0x6d, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP == 0
  /*Pixel format: Blue: 5 bit, Green: 6 bit, Red: 5 bit, Alpha 8 bit*/
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0x4a, 0x07, 0x8a, 0x52, 0x83, 0x8a, 0x52, 0xe3, 0x8a, 0x52, 0xfb, 0x8a, 0x52, 0xd0, 0x8a, 0x52, 0x53, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x83, 0xf9, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xab, 0x5a, 0x08, 0x8a, 0x52, 0xc8, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0x83, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x84, 0xf9, 0xb4, 0x64, 0xf9, 0x8b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x8a, 0x52, 0x70, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xfc, 0xaa, 0x52, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x65, 0xf9, 0x07, 0x64, 0xf9, 0xb0, 0x44, 0xf9, 0x97, 0x00, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x8a, 0x52, 0xb8, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0x6b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x65, 0xf9, 0x07, 0x64, 0xf9, 0xb0, 0x45, 0xf9, 0x98, 0x00, 0xf8, 0x00, 0x8a, 0x52, 0xc7, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0x7b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x65, 0xf9, 0x07, 0x45, 0xf9, 0xaf, 0x25, 0xf9, 0x9b, 0x8a, 0x52, 0xc7, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa6, 0xf9, 0x04, 0x25, 0xf9, 0xac, 0xa7, 0xc1, 0xe8, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x03, 0x87, 0xc1, 0xeb, 0xa7, 0xb9, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x8a, 0x52, 0xc8, 0xa7, 0xb9, 0xff, 0x87, 0xb9, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xaa, 0x52, 0x23, 0x8a, 0x52, 0x43, 0x00, 0x00, 0x00, 0x8a, 0x52, 0xc7, 0x8a, 0x52, 0xff, 0x87, 0xb9, 0xff, 0x67, 0xb9, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0x7c, 0x00, 0x00, 0x00, 0x8a, 0x52, 0x57, 0x49, 0x4a, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x8a, 0x52, 0x58, 0x8a, 0x52, 0x94, 0x00, 0x00, 0x00, 0x8a, 0x52, 0xc7, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x88, 0xb9, 0xff, 0x68, 0xb9, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0x7c, 0x00, 0x00, 0x00, 0x8a, 0x52, 0xbc, 0xaa, 0x52, 0x2f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x8a, 0x52, 0x58, 0x8a, 0x52, 0x94, 0x00, 0x00, 0x00, 0x8a, 0x52, 0xc7, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x88, 0xb1, 0xff, 0x48, 0xc1, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0x7c, 0x00, 0x00, 0x00, 0x8a, 0x52, 0xbc, 0xaa, 0x52, 0x2f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x8a, 0x52, 0x58, 0x8a, 0x52, 0x94, 0x00, 0x00, 0x00, 0x8a, 0x52, 0xc7, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x88, 0xb1, 0xff, 0x28, 0xc1, 0xff, 0x8a, 0x5a, 0xff, 0x8a, 0x52, 0x7c, 0x00, 0x00, 0x00, 0x8a, 0x52, 0xbc, 0xaa, 0x52, 0x2f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xaa, 0x52, 0x4b, 0x8a, 0x52, 0xa3, 0x00, 0x00, 0x00, 0x8a, 0x52, 0xb8, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x68, 0xa9, 0xff, 0x28, 0xc1, 0xff, 0x6a, 0x5a, 0x70, 0x00, 0x00, 0x00, 0x8a, 0x52, 0xcc, 0x8a, 0x52, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x8a, 0x52, 0x23, 0x8a, 0x52, 0xd0, 0x00, 0x00, 0x00, 0x8a, 0x52, 0x73, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x68, 0xa9, 0xff, 0x88, 0xe0, 0xc0, 0x8a, 0xa1, 0x10, 0x8a, 0x52, 0xe4, 0x2d, 0x6b, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x8a, 0x52, 0xcf, 0xaa, 0x52, 0x34, 0x6a, 0x52, 0x0b, 0x8a, 0x52, 0xcc, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0x88, 0x68, 0xf0, 0x8f, 0xa8, 0xd8, 0xd3, 0x6a, 0x5a, 0xa4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x8a, 0x52, 0x48, 0x8a, 0x52, 0xcc, 0x6a, 0x52, 0x0b, 0xab, 0x5a, 0x08, 0x8a, 0x52, 0x88, 0x8a, 0x52, 0xeb, 0x8a, 0x52, 0xff, 0x8a, 0x52, 0xd7, 0x8a, 0x52, 0x58, 0x00, 0x00, 0x00, 0x8a, 0x52, 0x1c, 0x69, 0xa9, 0xef, 0x68, 0xe0, 0xc3, 0x07, 0xe0, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x8a, 0x52, 0x7c, 0x8a, 0x52, 0xc4, 0x8a, 0x52, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x8a, 0x52, 0x33, 0x8a, 0x52, 0xd7, 0x8a, 0x52, 0x54, 0x48, 0xe8, 0x83, 0x49, 0xe8, 0xc0, 0x08, 0xe8, 0x0c, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x8a, 0x52, 0x5b, 0x8a, 0x52, 0xe0, 0x8a, 0x52, 0xa0, 0x8a, 0x52, 0x60, 0x8a, 0x52, 0x4c, 0x8a, 0x52, 0x68, 0x8a, 0x52, 0xb0, 0x8a, 0x52, 0xd7, 0x8a, 0x52, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0xe8, 0x80, 0x29, 0xe8, 0xc3, 0x0a, 0xe8, 0x0c, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x63, 0x08, 0x8a, 0x52, 0x53, 0x8a, 0x52, 0x8c, 0x8a, 0x52, 0xf3, 0x8a, 0x52, 0x83, 0x8a, 0x52, 0x44, 0xab, 0x5a, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x29, 0xe8, 0x80, 0x09, 0xe8, 0xbc, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x29, 0x4a, 0x0b, 0x8a, 0x52, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0xe8, 0x34, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x29, 0x4a, 0x0b, 0x8a, 0x52, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xab, 0x5a, 0x1f, 0x8a, 0x52, 0xe8, 0x8a, 0x52, 0xef, 0x8a, 0x52, 0xef, 0x8a, 0x52, 0xef, 0x8a, 0x52, 0xfc, 0x8a, 0x52, 0xef, 0x8a, 0x52, 0xef, 0x8a, 0x52, 0xef, 0x8a, 0x52, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP != 0
  /*Pixel format:  Blue: 5 bit Green: 6 bit, Red: 5 bit, Alpha 8 bit  BUT the 2  color bytes are swapped*/
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4a, 0x49, 0x07, 0x52, 0x8a, 0x83, 0x52, 0x8a, 0xe3, 0x52, 0x8a, 0xfb, 0x52, 0x8a, 0xd0, 0x52, 0x8a, 0x53, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xf9, 0x83, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5a, 0xab, 0x08, 0x52, 0x8a, 0xc8, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0x83, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xf9, 0x84, 0xb4, 0xf9, 0x64, 0x8b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x52, 0x8a, 0x70, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xfc, 0x52, 0xaa, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xf9, 0x65, 0x07, 0xf9, 0x64, 0xb0, 0xf9, 0x44, 0x97, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x52, 0x8a, 0xb8, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0x6b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0xf9, 0x65, 0x07, 0xf9, 0x64, 0xb0, 0xf9, 0x45, 0x98, 0xf8, 0x00, 0x00, 0x52, 0x8a, 0xc7, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0x7b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf9, 0x65, 0x07, 0xf9, 0x45, 0xaf, 0xf9, 0x25, 0x9b, 0x52, 0x8a, 0xc7, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf9, 0xa6, 0x04, 0xf9, 0x25, 0xac, 0xc1, 0xa7, 0xe8, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x00, 0x03, 0xc1, 0x87, 0xeb, 0xb9, 0xa7, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x52, 0x8a, 0xc8, 0xb9, 0xa7, 0xff, 0xb9, 0x87, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x52, 0xaa, 0x23, 0x52, 0x8a, 0x43, 0x00, 0x00, 0x00, 0x52, 0x8a, 0xc7, 0x52, 0x8a, 0xff, 0xb9, 0x87, 0xff, 0xb9, 0x67, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0x7c, 0x00, 0x00, 0x00, 0x52, 0x8a, 0x57, 0x4a, 0x49, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x52, 0x8a, 0x58, 0x52, 0x8a, 0x94, 0x00, 0x00, 0x00, 0x52, 0x8a, 0xc7, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0xb9, 0x88, 0xff, 0xb9, 0x68, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0x7c, 0x00, 0x00, 0x00, 0x52, 0x8a, 0xbc, 0x52, 0xaa, 0x2f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x52, 0x8a, 0x58, 0x52, 0x8a, 0x94, 0x00, 0x00, 0x00, 0x52, 0x8a, 0xc7, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0xb1, 0x88, 0xff, 0xc1, 0x48, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0x7c, 0x00, 0x00, 0x00, 0x52, 0x8a, 0xbc, 0x52, 0xaa, 0x2f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x52, 0x8a, 0x58, 0x52, 0x8a, 0x94, 0x00, 0x00, 0x00, 0x52, 0x8a, 0xc7, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0xb1, 0x88, 0xff, 0xc1, 0x28, 0xff, 0x5a, 0x8a, 0xff, 0x52, 0x8a, 0x7c, 0x00, 0x00, 0x00, 0x52, 0x8a, 0xbc, 0x52, 0xaa, 0x2f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x52, 0xaa, 0x4b, 0x52, 0x8a, 0xa3, 0x00, 0x00, 0x00, 0x52, 0x8a, 0xb8, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0xa9, 0x68, 0xff, 0xc1, 0x28, 0xff, 0x5a, 0x6a, 0x70, 0x00, 0x00, 0x00, 0x52, 0x8a, 0xcc, 0x52, 0x8a, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x52, 0x8a, 0x23, 0x52, 0x8a, 0xd0, 0x00, 0x00, 0x00, 0x52, 0x8a, 0x73, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0xa9, 0x68, 0xff, 0xe0, 0x88, 0xc0, 0xa1, 0x8a, 0x10, 0x52, 0x8a, 0xe4, 0x6b, 0x2d, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x52, 0x8a, 0xcf, 0x52, 0xaa, 0x34, 0x52, 0x6a, 0x0b, 0x52, 0x8a, 0xcc, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0x88, 0xf0, 0x68, 0x8f, 0xd8, 0xa8, 0xd3, 0x5a, 0x6a, 0xa4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x52, 0x8a, 0x48, 0x52, 0x8a, 0xcc, 0x52, 0x6a, 0x0b, 0x5a, 0xab, 0x08, 0x52, 0x8a, 0x88, 0x52, 0x8a, 0xeb, 0x52, 0x8a, 0xff, 0x52, 0x8a, 0xd7, 0x52, 0x8a, 0x58, 0x00, 0x00, 0x00, 0x52, 0x8a, 0x1c, 0xa9, 0x69, 0xef, 0xe0, 0x68, 0xc3, 0xe0, 0x07, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x52, 0x8a, 0x7c, 0x52, 0x8a, 0xc4, 0x52, 0x8a, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x52, 0x8a, 0x33, 0x52, 0x8a, 0xd7, 0x52, 0x8a, 0x54, 0xe8, 0x48, 0x83, 0xe8, 0x49, 0xc0, 0xe8, 0x08, 0x0c, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x52, 0x8a, 0x5b, 0x52, 0x8a, 0xe0, 0x52, 0x8a, 0xa0, 0x52, 0x8a, 0x60, 0x52, 0x8a, 0x4c, 0x52, 0x8a, 0x68, 0x52, 0x8a, 0xb0, 0x52, 0x8a, 0xd7, 0x52, 0x8a, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe8, 0x49, 0x80, 0xe8, 0x29, 0xc3, 0xe8, 0x0a, 0x0c, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x63, 0x0c, 0x08, 0x52, 0x8a, 0x53, 0x52, 0x8a, 0x8c, 0x52, 0x8a, 0xf3, 0x52, 0x8a, 0x83, 0x52, 0x8a, 0x44, 0x5a, 0xab, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe8, 0x29, 0x80, 0xe8, 0x09, 0xbc, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4a, 0x29, 0x0b, 0x52, 0x8a, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe8, 0x09, 0x34, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4a, 0x29, 0x0b, 0x52, 0x8a, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5a, 0xab, 0x1f, 0x52, 0x8a, 0xe8, 0x52, 0x8a, 0xef, 0x52, 0x8a, 0xef, 0x52, 0x8a, 0xef, 0x52, 0x8a, 0xfc, 0x52, 0x8a, 0xef, 0x52, 0x8a, 0xef, 0x52, 0x8a, 0xef, 0x52, 0x8a, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
#endif
#if LV_COLOR_DEPTH == 32
  /*Pixel format:  Blue: 8 bit, Green: 8 bit, Red: 8 bit, Alpha: 8 bit*/
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0x49, 0x49, 0x07, 0x52, 0x52, 0x52, 0x83, 0x51, 0x51, 0x51, 0xe3, 0x51, 0x51, 0x51, 0xfb, 0x51, 0x51, 0x51, 0xd0, 0x51, 0x51, 0x51, 0x53, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x1c, 0x31, 0xff, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x55, 0x55, 0x55, 0x08, 0x51, 0x51, 0x51, 0xc8, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xff, 0x52, 0x52, 0x52, 0x83, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x1e, 0x31, 0xfe, 0xb4, 0x1f, 0x2e, 0xfd, 0x8b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x52, 0x52, 0x52, 0x70, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xfc, 0x53, 0x53, 0x53, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x2b, 0x2b, 0xff, 0x07, 0x20, 0x2e, 0xfe, 0xb0, 0x22, 0x2a, 0xfc, 0x97, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x50, 0x50, 0x50, 0xb8, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0x6b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x2b, 0x2b, 0xff, 0x07, 0x21, 0x2b, 0xfc, 0xb0, 0x25, 0x28, 0xfa, 0x98, 0x00, 0x00, 0xff, 0x00, 0x51, 0x51, 0x51, 0xc7, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0x7b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2b, 0x2b, 0xff, 0x07, 0x25, 0x29, 0xfb, 0xaf, 0x28, 0x26, 0xf8, 0x9b, 0x51, 0x51, 0x53, 0xc7, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xff, 0x50, 0x50, 0x50, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x33, 0x33, 0xff, 0x04, 0x26, 0x26, 0xf9, 0xac, 0x38, 0x33, 0xc0, 0xe8, 0x50, 0x50, 0x52, 0xff, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xff, 0x50, 0x50, 0x50, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x03, 0x35, 0x31, 0xc4, 0xeb, 0x3a, 0x33, 0xb6, 0xff, 0x50, 0x50, 0x52, 0xff, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xff, 0x50, 0x50, 0x50, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4f, 0x4f, 0x53, 0xc8, 0x3a, 0x33, 0xba, 0xff, 0x3b, 0x30, 0xbb, 0xff, 0x51, 0x50, 0x54, 0xff, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xff, 0x50, 0x50, 0x50, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x53, 0x53, 0x53, 0x23, 0x51, 0x51, 0x51, 0x43, 0x00, 0x00, 0x00, 0x00, 0x51, 0x51, 0x51, 0xc7, 0x51, 0x50, 0x53, 0xff, 0x3c, 0x31, 0xb9, 0xff, 0x3c, 0x2e, 0xbc, 0xff, 0x51, 0x50, 0x54, 0xff, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xff, 0x50, 0x50, 0x50, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x50, 0x50, 0x50, 0x57, 0x49, 0x49, 0x49, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x51, 0x51, 0x51, 0x58, 0x51, 0x51, 0x51, 0x94, 0x00, 0x00, 0x00, 0x00, 0x51, 0x51, 0x51, 0xc7, 0x51, 0x51, 0x51, 0xff, 0x51, 0x50, 0x53, 0xff, 0x3d, 0x2f, 0xb6, 0xff, 0x3d, 0x2c, 0xbb, 0xff, 0x51, 0x50, 0x54, 0xff, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xff, 0x50, 0x50, 0x50, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x51, 0x51, 0x51, 0xbc, 0x53, 0x53, 0x53, 0x2f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x51, 0x51, 0x51, 0x58, 0x51, 0x51, 0x51, 0x94, 0x00, 0x00, 0x00, 0x00, 0x51, 0x51, 0x51, 0xc7, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x52, 0xff, 0x40, 0x30, 0xaf, 0xff, 0x3f, 0x2a, 0xbd, 0xff, 0x50, 0x4f, 0x54, 0xff, 0x51, 0x51, 0x51, 0xff, 0x50, 0x50, 0x50, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x51, 0x51, 0x51, 0xbc, 0x53, 0x53, 0x53, 0x2f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x51, 0x51, 0x51, 0x58, 0x51, 0x51, 0x51, 0x94, 0x00, 0x00, 0x00, 0x00, 0x51, 0x51, 0x51, 0xc7, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x52, 0xff, 0x41, 0x2f, 0xae, 0xff, 0x3f, 0x26, 0xc0, 0xff, 0x51, 0x4f, 0x56, 0xff, 0x50, 0x50, 0x50, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x51, 0x51, 0x51, 0xbc, 0x53, 0x53, 0x53, 0x2f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x53, 0x53, 0x53, 0x4b, 0x50, 0x50, 0x50, 0xa3, 0x00, 0x00, 0x00, 0x00, 0x51, 0x51, 0x51, 0xb8, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x52, 0xff, 0x43, 0x2e, 0xac, 0xff, 0x42, 0x24, 0xc1, 0xff, 0x50, 0x4b, 0x5b, 0x70, 0x00, 0x00, 0x00, 0x00, 0x51, 0x51, 0x51, 0xcc, 0x52, 0x52, 0x52, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x50, 0x50, 0x50, 0x23, 0x51, 0x51, 0x51, 0xd0, 0x00, 0x00, 0x00, 0x00, 0x52, 0x52, 0x52, 0x73, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x52, 0xff, 0x44, 0x2d, 0xaa, 0xff, 0x3e, 0x11, 0xe3, 0xc0, 0x50, 0x30, 0x9f, 0x10, 0x51, 0x51, 0x51, 0xe4, 0x66, 0x66, 0x66, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x50, 0x50, 0x50, 0xcf, 0x53, 0x53, 0x53, 0x34, 0x4d, 0x4d, 0x4d, 0x0b, 0x51, 0x51, 0x51, 0xcc, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x53, 0x88, 0x3d, 0x0e, 0xed, 0x8f, 0x42, 0x15, 0xd7, 0xd3, 0x4f, 0x4c, 0x58, 0xa4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x50, 0x50, 0x50, 0x48, 0x51, 0x51, 0x51, 0xcc, 0x4d, 0x4d, 0x4d, 0x0b, 0x55, 0x55, 0x55, 0x08, 0x52, 0x52, 0x52, 0x88, 0x51, 0x51, 0x51, 0xeb, 0x51, 0x51, 0x51, 0xff, 0x51, 0x51, 0x51, 0xd7, 0x51, 0x51, 0x51, 0x58, 0x00, 0x00, 0x00, 0x00, 0x52, 0x52, 0x52, 0x1c, 0x47, 0x2b, 0xa6, 0xef, 0x43, 0x0d, 0xe2, 0xc3, 0x39, 0x00, 0xe3, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x50, 0x50, 0x50, 0x7c, 0x51, 0x51, 0x51, 0xc4, 0x4f, 0x4f, 0x4f, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x52, 0x52, 0x52, 0x33, 0x51, 0x51, 0x51, 0xd7, 0x51, 0x51, 0x51, 0x54, 0x42, 0x0a, 0xea, 0x83, 0x45, 0x07, 0xe9, 0xc0, 0x40, 0x00, 0xea, 0x0c, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x51, 0x51, 0x51, 0x5b, 0x51, 0x51, 0x51, 0xe0, 0x51, 0x51, 0x51, 0xa0, 0x50, 0x50, 0x50, 0x60, 0x4f, 0x4f, 0x4f, 0x4c, 0x51, 0x51, 0x51, 0x68, 0x51, 0x51, 0x51, 0xb0, 0x51, 0x51, 0x51, 0xd7, 0x51, 0x51, 0x51, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x45, 0x08, 0xe7, 0x80, 0x47, 0x04, 0xe7, 0xc3, 0x4e, 0x00, 0xeb, 0x0c, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x60, 0x60, 0x08, 0x50, 0x50, 0x50, 0x53, 0x51, 0x51, 0x51, 0x8c, 0x51, 0x51, 0x51, 0xf3, 0x50, 0x50, 0x50, 0x83, 0x51, 0x51, 0x51, 0x44, 0x55, 0x55, 0x55, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x04, 0xe7, 0x80, 0x4a, 0x01, 0xe5, 0xbc, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46, 0x46, 0x46, 0x0b, 0x50, 0x50, 0x50, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4a, 0x00, 0xe6, 0x34, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46, 0x46, 0x46, 0x0b, 0x50, 0x50, 0x50, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x55, 0x55, 0x55, 0x1f, 0x51, 0x51, 0x51, 0xe8, 0x51, 0x51, 0x51, 0xef, 0x51, 0x51, 0x51, 0xef, 0x51, 0x51, 0x51, 0xef, 0x51, 0x51, 0x51, 0xfc, 0x51, 0x51, 0x51, 0xef, 0x51, 0x51, 0x51, 0xef, 0x51, 0x51, 0x51, 0xef, 0x51, 0x51, 0x51, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
#endif
};

const lv_img_dsc_t mute_on = {
  .header.always_zero = 0,
  .header.w = 19,
  .header.h = 23,
  .data_size = 437 * LV_IMG_PX_SIZE_ALPHA_BYTE,
  .header.cf = LV_IMG_CF_TRUE_COLOR_ALPHA,
  .data = mute_on_map,
};

