/* Copyright 2020 LAZYDESIGNERS
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

#define LT2_TAB LT(2, KC_TAB)
#define LT1_SPC LT(1, KC_SPC)
#define LT2_SPC LT(2, KC_SPC)
#define CT_CAPS MT(MOD_LCTL, KC_CAPS)
#define M_L C(A(KC_A))
#define M_R C(A(KC_D))

// Custom Keycode Declarations
enum {
   TD_TAB_ESC,
   TD_SCLN_QUOT,
   TD_QUOT_ENT,
   TD_MINS_EQL,
   // M_LEFT,
   // M_RIGHT,
};

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Tab, twice for Escape
    [TD_TAB_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_TAB, KC_ESC),
    [TD_SCLN_QUOT] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_QUOT),
    [TD_QUOT_ENT] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_ENT),
    [TD_MINS_EQL] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_EQL)
};

// Macro Definitions

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   switch (keycode) {
//     case M_LEFT:
//       if (record->event.pressed) {
//         SEND_STRING()
//       }
//   }


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
               TD(TD_TAB_ESC),  KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,                        KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,             KC_BSPC,
               CT_CAPS,         KC_A,      KC_S,      KC_D,      KC_F,      KC_G,                        KC_H,      KC_J,      KC_K,      KC_L,      TD(TD_SCLN_QUOT), KC_ENT,
               KC_LSFT,         KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,             KC_B,      KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,          KC_RSFT,
               KC_F5,           KC_LWIN,                         KC_LALT,   LT1_SPC,          LT2_SPC,   KC_RALT,                         KC_RWIN,   KC_DEL,           TG(3)
             ),
    [1] = LAYOUT(
               KC_GRV,          KC_EXLM,   KC_AT,     KC_HASH,   KC_DLR,    KC_PERC,                     KC_CIRC,   KC_AMPR,   KC_ASTR,   KC_LPRN,   KC_RPRN,          TD(TD_MINS_EQL),
               KC_INS,          KC_1,      KC_2,      KC_3,      KC_4,      KC_5,                        KC_6,      KC_7,      KC_8,      KC_9,      KC_0,             KC_BSLS,
               KC_TRNS,         KC_MPLY,   KC_VOLD,   KC_VOLU,   KC_MUTE,   KC_LBRC,          KC_RBRC,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,          KC_TRNS,
               KC_VOLD,         KC_MUTE,                         KC_VOLU,   KC_TRNS,          KC_TRNS,   KC_TRNS,                         KC_TRNS,   KC_TRNS,          KC_TRNS
             ),
    [2] = LAYOUT(
               RESET,           KC_TRNS,   M_L,       KC_UP,     M_R,       KC_TRNS,                     KC_TRNS,   M_L,       KC_UP,     M_R,       KC_F12,           KC_TRNS,
               KC_TRNS,         KC_TRNS,   KC_LEFT,   KC_DOWN,   KC_RIGHT,  KC_TRNS,                     KC_TRNS,   KC_LEFT,   KC_DOWN,   KC_RIGHT,  KC_F11,           KC_TRNS,
               KC_TRNS,         KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,            KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_TRNS,          RGB_TOG,
               KC_TRNS,         KC_TRNS,                         KC_TRNS,   KC_TRNS,          KC_TRNS,   KC_TRNS,                         RGB_HUI,   RGB_SAI,          RGB_VAI
             ),
    [3] = LAYOUT(
	       KC_TAB,          KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,                        KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,             KC_BSPC,
	       KC_LCTL,         KC_A,      KC_S,      KC_D,      KC_F,      KC_G,                        KC_H,      KC_J,      KC_K,      KC_L,      TD(TD_SCLN_QUOT), KC_ENT,
	       KC_LSFT,         KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,             KC_B,      KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,          KC_RSFT,
	       KC_ESC,          KC_UP,                           KC_LALT,   KC_SPC,           KC_2,      KC_TRNS,                         KC_RWIN,   KC_TRNS,          TG(3)
	     ),
};

// Activate underglow when layer 3 is active
// RGB begins on top left, bolt begins on 9
const rgblight_segment_t PROGMEM gaming_underglow[] = RGBLIGHT_LAYER_SEGMENTS(
	{1, 8, 145, 200, 115}
);

const rgblight_segment_t PROGMEM layer_1[] = RGBLIGHT_LAYER_SEGMENTS(
	{9, 3, 145, 200, 115}
);

const rgblight_segment_t PROGMEM layer_2[] = RGBLIGHT_LAYER_SEGMENTS(
	{11, 3, 145, 200, 115}
);

// Defining the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
	layer_1,
	layer_2,
	gaming_underglow
);

void keyboard_post_init_user(void) {
	// Enable the LED layers
	rgblight_layers = my_rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
	rgblight_set_layer_state(0, layer_state_cmp(state, 1));
	rgblight_set_layer_state(1, layer_state_cmp(state, 2));
	rgblight_set_layer_state(2, layer_state_cmp(state, 3));
	return state;
}
