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
    KC_MUTE, OSL(1), OSL(2),
    KC_F1, KC_F2, KC_F3, KC_F4
  ),
  [1] = LAYOUT(
    KC_MPLY, KC_MPRV, KC_MNXT,
    KC_1, KC_2, KC_3, KC_4
  )
  [2] = LAYOUT(
    RGB_TOG, RGB_MODE_FORWARD, RGB_MODE_RAINBOW,
    KC_A, KC_B, KC_C, KC_D
  )
};

bool encoder_update_user(uint8_t index, bool clockwise) {
  switch (get_highest_layer(layer_state)) {
    case 0:
      switch (index) {
        case 0:
          if (clockwise) {
            tap_code_delay(KC_VOLU, 10);
          } else {
            tap_code_delay(KC_VOLD, 10);
          }
          break;
        case 1:
          if (clockwise) {
            tap_code_delay(C(KC_TAB), 250);
          } else {
            tap_code_delay(S(C(KC_TAB)), 250);
          }
          break;
        case 2:
          if (clockwise) {
            tap_code_delay(A(KC_TAB), 250);
          } else {
            tap_code_delay(S(A(KC_TAB)), 250);
          }
          break;
      }
      break;
    case 1:
      switch (index) {
        case 0:
          if (clockwise) {
            tap_code_delay(KC_VOLU, 10);
          } else {
            tap_code_delay(KC_VOLD, 10);
          }
          break;
        case 1:
          if (clockwise) {
            tap_code_delay(KC_MNXT, 250);
          } else {
            tap_code_delay(KC_MPRV, 250);
          }
          break;
      }
      break;
    case 2:
      switch (index) {
        case 0:
          if (clockwise) {
            rgblight_increase_hue();
          } else {
            rgblight_decrease_hue();
          }
          break;
        case 1:
          if (clockwise) {
            rgblight_increase_sat();
          } else {
            rgblight_decrease_sat();
          }
          break;
        case 2:
          if (clockwise) {
            rgblight_increase_val();
          } else {
            rgblight_decrease_val();
          }
          break;
      }
      break;
  }
  
  return true;
}