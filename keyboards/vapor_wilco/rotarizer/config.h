
/**
MIT License

Copyright (c) 2022 ayan4m1 & QMK Firmware

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#pragma once
#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID 0x534C
#define PRODUCT_ID 0x5E9A
#define DEVICE_VER 0x0001
#define MANUFACTURER ayan4m1
#define PRODUCT Rotarizer

/* key matrix size */
#define MATRIX_ROWS 2
#define MATRIX_COLS 4

/* key matrix pins */
#define MATRIX_ROW_PINS \
    { D1, D0 }
#define MATRIX_COL_PINS \
    { D4, C6, D7, E6 }
#define UNUSED_PINS

/* rotary encoders */
#define ENCODERS_PAD_A \
    { B4, B6, B3 }
#define ENCODERS_PAD_B \
    { B5, B2, B1 }

/* PEC11H-4220F-S0024 */
#define ENCODER_RESOLUTION 24

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION ROW2COL

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

#define RGB_DI_PIN F7
#define RGBLED_NUM 4
#define RGBLIGHT_SLEEP
#define RGBLIGHT_LAYERS
#define RGBLIGHT_ANIMATIONS

#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_BREATHING
#define RGBLIGHT_DEFAULT_HUE 148

#define DRIVER_LED_TOTAL RGBLED_NUM

#define HSV_ROTARIZER_ORANGE 21, 255, 255
#define HSV_ROTARIZER_PURPLE 184, 255, 255
#define HSV_ROTARIZER_BLUE 148, 255, 255
