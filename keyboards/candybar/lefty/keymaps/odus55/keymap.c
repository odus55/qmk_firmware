/* Copyright 2018 Jack Humbert
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

#define _BL 0
#define _L1 1
#define _L2 2
#define _GM 3
// Tap Dance declarations
enum {
	TD_TAB_ESC,
        TD_SCLN_QUOT,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Tab, twice for Escape
    [TD_TAB_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_TAB, KC_ESC),
    [TD_SCLN_QUOT] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_QUOT)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: Base Layer (Default Layer)
   */
  [_BL] = LAYOUT(
  KC_P7, KC_P8, KC_P9  , KC_PAST, TD(TD_TAB_ESC)       , KC_Q   , KC_W   , KC_E   , KC_R          , KC_T   , KC_Y           ,    KC_U   , KC_I   , KC_O    , KC_P            , KC_DEL , KC_BSPC , \
  KC_P4, KC_P5, KC_P6  , KC_PMNS, MT(MOD_LCTL, KC_CAPS), KC_A   , KC_S   , KC_D   , KC_F          , KC_G   , KC_H           ,    KC_J   , KC_K   , KC_L    , TD(TD_SCLN_QUOT),          KC_ENT  , \
  KC_P1, KC_P2, KC_P3  , KC_PPLS, KC_LSFT              , KC_Z   , KC_X   , KC_C   , KC_V          , KC_B   , KC_N           ,    KC_M   , KC_COMM, KC_DOT  , KC_SLSH         ,          KC_RSFT , \
  KC_F5, KC_P0, KC_PDOT, KC_PENT, KC_LCTL              , KC_LWIN, KC_LALT,          LT(_L1,KC_SPC), KC_SPC , LT(_L2, KC_SPC),             KC_RALT, KC_RWIN , KC_RCTL         ,          TG(_GM)),

  /* Keymap _L1: Function Layer
  */
  [_L1] = LAYOUT(
  KC_P7, KC_P8, KC_P9  , KC_PAST, KC_GRV               , KC_EXLM, KC_AT  , KC_HASH, KC_DLR        , KC_PERC, KC_CIRC        ,    KC_AMPR, KC_ASTR, KC_LPRN , KC_RPRN         , KC_MINS, KC_EQL  , \
  KC_P4, KC_P5, KC_P6  , KC_PMNS, KC_TRNS              , KC_1   , KC_2   , KC_3   , KC_4          , KC_5   , KC_6           ,    KC_7   , KC_8   , KC_9    , KC_0            ,          KC_BSLS , \
  KC_P1, KC_P2, KC_P3  , KC_PPLS, KC_TRNS              , KC_MPLY, KC_VOLD, KC_VOLU, KC_MUTE       , KC_LBRC, KC_RBRC        ,    KC_SPC , KC_TRNS, KC_TRNS , KC_TRNS         ,          KC_TRNS , \
  KC_F5, KC_P0, KC_PDOT, KC_PENT, KC_TRNS              , KC_TRNS, KC_TRNS,          KC_TRNS       , KC_SPC , KC_TRNS        ,             KC_TRNS, KC_TRNS , KC_TRNS         ,          KC_TRNS),

  /* Keymap _L2: Function Layer
  */
  [_L2] = LAYOUT(
  KC_P7, KC_P8, KC_P9  , KC_PAST, KC_TRNS              , KC_TRNS, KC_TRNS, KC_UP  , KC_TRNS       , KC_TRNS, KC_TRNS        ,    KC_TRNS, KC_UP  , KC_TRNS , KC_F12          , KC_TRNS, KC_TRNS , \
  KC_P4, KC_P5, KC_P6  , KC_PMNS, KC_TRNS              , KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT      , KC_TRNS, KC_TRNS        ,    KC_LEFT, KC_DOWN, KC_RIGHT, KC_F11          ,          KC_ENT  , \
  KC_P1, KC_P2, KC_P3  , KC_PPLS, KC_TRNS              , KC_F1  , KC_F2  , KC_F3  , KC_F4         , KC_F5  , KC_F6          ,    KC_F7  , KC_F8  , KC_F9   , KC_F10          ,          KC_TRNS , \
  RESET, KC_P0, KC_PDOT, KC_PENT, KC_TRNS              , KC_TRNS, KC_TRNS,          KC_TRNS       , KC_SPC , KC_TRNS        ,             KC_TRNS, KC_TRNS , KC_TRNS         ,          KC_TRNS),

  /* Keymap _GM: Function Layer
  */
  [_GM] = LAYOUT(
  KC_P7, KC_P8, KC_P9  , KC_PAST, TD(TD_TAB_ESC)       , KC_Q   , KC_W   , KC_E   , KC_R          , KC_T   , KC_Y           ,    KC_U   , KC_I   , KC_O    , KC_P            , KC_DEL , KC_BSPC , \
  KC_P4, KC_P5, KC_P6  , KC_PMNS, KC_TRNS              , KC_A   , KC_S   , KC_D   , KC_F          , KC_G   , KC_H           ,    KC_J   , KC_K   , KC_L    , TD(TD_SCLN_QUOT),          KC_ENT  , \
  KC_P1, KC_P2, KC_P3  , KC_PPLS, KC_TRNS              , KC_Z   , KC_X   , KC_C   , KC_V          , KC_B   , KC_N           ,    KC_M   , KC_COMM, KC_DOT  , KC_UP           ,          KC_RSFT , \
  KC_F5, KC_P0, KC_PDOT, KC_PENT, KC_TRNS              , KC_LGUI, KC_LALT,          KC_SPC        , KC_SPC , KC_2           ,             KC_APP , KC_LEFT , KC_DOWN         ,          TG(_GM)),
};
