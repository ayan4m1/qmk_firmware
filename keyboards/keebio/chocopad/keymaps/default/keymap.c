// Copyright 2023 Danny Nguyen (danny@keeb.io)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define _BASE 0
#define _FN1 1
#define _FN2 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_ortho_4x4(
    MI_E3,  MI_F3,  MI_Fs3,    MI_G3	 ,
    MI_C3,  MI_Cs3,  MI_D3,  MI_Ds3,
    MO(_FN2), KC_VOLU,  KC_MPLY,  MI_ON,
    MO(_FN1), KC_VOLD,  KC_MUTE,  MI_OFF
  ),
  [_FN1] = LAYOUT_ortho_4x4(
    KC_ESC,   KC_P7,    KC_P8,    KC_P9,
    KC_TAB,   KC_P4,    KC_P5,    KC_P6,
    KC_ENT,   KC_P1,    KC_P2,    KC_P3,
    _______,  KC_P0,    KC_P0,    KC_DOT
  ),
  [_FN2] = LAYOUT_ortho_4x4(
    RGB_TOG,  RGB_HUI,  RGB_SAI,  RGB_VAI,
    RGB_MOD,  RGB_HUD,  RGB_SAD,  RGB_VAD,
    _______,  _______,  _______,  QK_BOOT,
    BL_STEP,  _______,  _______,  _______
  )

};