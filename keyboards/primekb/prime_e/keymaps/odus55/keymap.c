/* Copyright 2018 Holten Campbell
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

enum layer_names {
    _BASE,
    _FN1,
    _FN2,
    _Gaming,
};


// Tap Dance declarations
enum {
	TD_TAB_ESC,
        TD_SCLN_QUOT,
        TD_QUOT_ENT,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Tab, twice for Escape
    [TD_TAB_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_TAB, KC_ESC),
    [TD_SCLN_QUOT] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_QUOT),	
    [TD_QUOT_ENT] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_ENT)
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
		TD(TD_TAB_ESC),             KC_Q,      KC_W,      KC_E,       KC_R,              KC_T,          KC_Y,               KC_U,      KC_I,      KC_O,       KC_P,               KC_DEL,    KC_BSPC,
		MT(MOD_LCTL, KC_CAPS),      KC_A,      KC_S,      KC_D,       KC_F,              KC_G,          KC_H,               KC_J,      KC_K,      KC_L,       TD(TD_SCLN_QUOT),              KC_ENT,
		KC_LSFT,                    KC_Z,      KC_X,      KC_C,       KC_V,              KC_B,          KC_B,               KC_N,      KC_M,      KC_COMM,    KC_DOT,             KC_SLSH,   KC_LSFT,
		KC_F5,                   KC_LWIN,                          KC_LALT,   LT(_FN1,KC_SPC),          LT(_FN2, KC_SPC),   KC_RALT,                                              KC_RWIN,   TG(_Gaming)
    ),

    [_FN1] = LAYOUT(
		KC_GRV,                  KC_EXLM,     KC_AT,   KC_HASH,     KC_DLR,           KC_PERC,          KC_CIRC,            KC_AMPR,   KC_ASTR,   KC_LPRN,    KC_RPRN,            KC_MINS,   KC_EQL,
		KC_TRNS,                    KC_1,      KC_2,      KC_3,       KC_4,              KC_5,          KC_6,               KC_7,      KC_8,      KC_9,       KC_0,                          KC_BSLS,
		KC_TRNS,                 KC_MPLY,   KC_VOLD,   KC_VOLU,    KC_MUTE,           KC_LBRC,          KC_RBRC,            KC_SPC,    KC_TRNS,   KC_TRNS,    KC_TRNS,            KC_TRNS,   KC_TRNS,
		KC_TRNS,                 KC_TRNS,                          KC_TRNS,           KC_TRNS,	        KC_TRNS,            KC_TRNS,                                              KC_TRNS,   KC_TRNS
    ),

    [_FN2] = LAYOUT(
		KC_TRNS,                 KC_TRNS,   KC_TRNS,     KC_UP,    KC_TRNS,           KC_TRNS,          KC_TRNS,            KC_TRNS,   KC_UP,     KC_TRNS,    KC_F12,             KC_TRNS,   KC_TRNS,
		KC_TRNS,                 KC_TRNS,   KC_LEFT,   KC_DOWN,   KC_RIGHT,           KC_TRNS,          KC_TRNS,            KC_LEFT,   KC_DOWN,   KC_RIGHT,   KC_F11,                        KC_TRNS,
		KC_TRNS,                   KC_F1,     KC_F2,     KC_F3,      KC_F4,             KC_F5,          KC_F6,              KC_F7,     KC_F8,     KC_F9,      KC_F10,             KC_TRNS,   KC_TRNS,
		KC_TRNS,                 KC_TRNS,                          KC_TRNS,           KC_TRNS,	        KC_PENT,            KC_PDOT,                                              KC_TRNS,   KC_TRNS
    ),

    [_Gaming] = LAYOUT(
		KC_TAB,                     KC_Q,      KC_W,      KC_E,       KC_R,              KC_T,          KC_Y,               KC_U,      KC_I,      KC_O,       KC_P,               KC_DEL,    KC_BSPC,
		KC_LCTL,                    KC_A,      KC_S,      KC_D,       KC_F,              KC_G,          KC_H,               KC_J,      KC_K,      KC_L,       TD(TD_SCLN_QUOT),              KC_ENT,
		KC_LSFT,                    KC_Z,      KC_X,      KC_C,       KC_V,              KC_B,          KC_B,               KC_N,      KC_M,      KC_COMM,    KC_DOT,             KC_SLSH,   KC_TRNS,
		KC_ESC,                     KC_3,                          KC_LALT,            KC_SPC,	        KC_2,               KC_TRNS,                                              KC_CAPS,   TG(_Gaming)
    )
};

void matrix_init_user(void) {
  // set CapsLock LED to output and low
  setPinOutput(B1);
  writePinLow(B1);
  // set NumLock LED to output and low
  setPinOutput(B2);
  writePinLow(B2);
  // set ScrollLock LED to output and low
  setPinOutput(B3);
  writePinLow(B3);  
}

void matrix_scan_user(void) {

}


/*void led_set_user(uint8_t usb_led) {
  if (IS_LED_ON(usb_led, USB_LED_NUM_LOCK)) {
    writePinHigh(B2);
  } else {
    writePinLow(B2);
  }
  if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
    writePinHigh(B1);
  } else {
    writePinLow(B1);
  }
  if (IS_LED_ON(usb_led, USB_LED_SCROLL_LOCK)) {
    writePinHigh(B3);
  } else {
    writePinLow(B3);
  }

}*/

//function for layer indicator LED
layer_state_t layer_state_set_user(layer_state_t state)
{
    if (get_highest_layer(state) == _FN1) {
    writePinHigh(B1);
	} else {
		writePinLow(B1);
    }
    if (get_highest_layer(state) == _FN2) {
    writePinHigh(B2);
	} else {
		writePinLow(B2);
    }
    if (get_highest_layer(state) == _Gaming) {
    writePinHigh(B3);
	} else {
		writePinLow(B3);
    }
    return state;
}
