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

enum custom_keycodes {
    COPY_ALL = SAFE_RANGE,
    PASTE,
    CLOSE_APP,
    NEXT_TAB,
    PREV_TAB,
    CLOSE_WINDOW,
    REOPEN_WINDOW,
    SELECT_END,
    SELECT_BEGINNING
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case COPY_ALL:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("ac"));
      }
      break;
    case PASTE:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_TAP(X_V)));
      }
      break;
    case CLOSE_APP:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_F4)));
      }
      break;
    case NEXT_TAB:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_TAP(X_TAB)));
      }
      break;
    case PREV_TAB:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_TAB))));
      }
      break;
    case CLOSE_WINDOW:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_TAP(X_W)));
      }
      break;
    case REOPEN_WINDOW:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_T))));
      }
      break;
    case SELECT_END:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT(SS_TAP(X_END)));
      }
      break;
    case SELECT_BEGINNING:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT(SS_TAP(X_HOME)));
      }
      break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    COPY_ALL, PASTE, CLOSE_APP,
    NEXT_TAB, CLOSE_WINDOW, SELECT_BEGINNING,
    PREV_TAB, REOPEN_WINDOW, SELECT_END
  ),
};
