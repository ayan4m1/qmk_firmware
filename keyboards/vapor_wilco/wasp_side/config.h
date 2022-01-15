
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
#define PRODUCT_ID 0x5E99
#define DEVICE_VER 0x0001
#define MANUFACTURER ayan4m1
#define PRODUCT Wasp Side

/* key matrix size */
#define MATRIX_ROWS 10
#define MATRIX_COLS 8

/* key matrix pins */
#define MATRIX_ROW_PINS \
    { D7, C6, D4, D0, D1, D2, F1, F0, B2, B3 }
#define MATRIX_COL_PINS \
    { B1, F7, F6, F5, F4, E6, B7, B4 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION ROW2COL

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

#define RGB_DI_PIN C7
#define RGBLED_NUM 5
