/* Copyright 2019-present Tomek Wójcik <contact@bthlabs.pl>
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

enum {
    TD_0_ENT,
};
// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_0_ENT] = ACTION_TAP_DANCE_DOUBLE(KC_P0, KC_PENT),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT( /* Base */
    LT(1, KC_F1), LT(2, KC_F2), LT(3, KC_F5),
    KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK,
    KC_AUDIO_VOL_DOWN, KC_AUDIO_MUTE, KC_AUDIO_VOL_UP
  ),
  [1] = LAYOUT (/* layer 1*/
    LT(0, KC_P7), KC_P8, KC_P9,
    KC_P6, KC_P5, KC_P4,
    KC_P1, KC_P2, KC_P3
  ),
  [2] = LAYOUT (/* layer 2*/
    LT(0, KC_PPLS), KC_PMNS, TD(TD_0_ENT),
    KC_PSLS, KC_UP, KC_PAST,
    KC_LEFT, KC_DOWN, KC_RGHT
  ),
};
