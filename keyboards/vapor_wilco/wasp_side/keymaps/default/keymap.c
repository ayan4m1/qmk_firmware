/* Copyright (c) 2022 ayan4m1 & QMK Firmware
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    KC_ESC, KC_2, KC_4, KC_6, KC_8, KC_0, KC_PLUS, KC_HOME,
    KC_1, KC_3, KC_5, KC_7, KC_9, KC_MINS, KC_BSPC, KC_PGUP,
    KC_TAB, KC_W, KC_R, KC_Y, KC_I, KC_P, KC_RBRC, KC_END,
    KC_Q, KC_E, KC_T, KC_U, KC_O, KC_LBRC, KC_BSLS, KC_PGDN,
    KC_CAPS, KC_S, KC_F, KC_H, KC_K, KC_SCLN, KC_ENT,
    KC_A, KC_D, KC_G, KC_J, KC_L, KC_QUOT,
    KC_LSFT, KC_X, KC_V, KC_N, KC_COMM, KC_SLSH, KC_NO,
    KC_Z, KC_C, KC_B, KC_M, KC_DOT, KC_RSFT, KC_UP,
    KC_LCTL, KC_LALT, KC_RALT, KC_RCTL, KC_DOWN,
    KC_LGUI, KC_SPC, KC_RGUI, KC_LEFT, KC_RIGHT
  )
};

