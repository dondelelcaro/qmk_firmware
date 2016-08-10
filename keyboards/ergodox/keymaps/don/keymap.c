/*
Copyright 2016 Fred Sundvik <fsundvik@gmail.com>
Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0
#define SYMB 1
#define MOUS 2
#define FNXN 3
#define NUMP 4


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_ESC, KC_1,  KC_2,   KC_3,   KC_4,   KC_5,   KC_EQL,
        KC_BSLS,KC_Q,  KC_W,   KC_E,   KC_R,   KC_T,   TG(MOUS),
        KC_TAB, KC_A,  KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,KC_Z,  KC_X,   KC_C,   KC_V,   KC_B,   MO(SYMB),
        KC_EQL,KC_GRV, KC_BSLS,KC_LEFT,KC_RGHT,
                                      KC_LALT,KC_LGUI,
                                           KC_HOME,
                                 KC_BSPC,KC_LCTL, KC_END,
        // right hand
        TG(NUMP), KC_6,KC_7, KC_8,   KC_9,   KC_0,   KC_MINS,
          KC_LBRC,KC_Y,KC_U, KC_I,   KC_O,   KC_P,   KC_RBRC,
                  KC_H,KC_J, KC_K,   KC_L,   KC_SCLN,KC_QUOT,
        TG(SYMB), KC_N,KC_M, KC_COMM,KC_DOT, KC_SLSH,KC_RSFT,
                      KC_UP, KC_DOWN,KC_LEFT,  KC_RGHT,KC_RGUI,
        KC_DEL,KC_RGUI,
        KC_PGUP,
        KC_PGDN,KC_ENT, KC_SPC
    ),

    [SYMB] = KEYMAP(  // layer 1 : function and symbol keys
        // left hand
        KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F11,
        KC_TRNS,KC_LBRC,KC_RBRC,KC_LBRC,KC_RBRC,KC_SCLN,KC_TRNS,
        KC_TRNS,KC_BSLS,KC_SLSH,KC_9   ,KC_0   ,KC_SCLN,
        KC_TRNS,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,KC_TRNS,
       TG(FNXN),KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                      KC_TRNS,KC_TRNS,
                                           KC_TRNS,
                                 KC_TRNS,KC_TRNS,KC_TRNS,
        // right hand
             KC_F12, KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_PWR ,
             KC_TRNS,KC_TRNS,KC_EQL ,KC_EQL ,KC_MINS,KC_MINS,KC_VOLU,
                     KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,KC_TRNS,KC_VOLD,
             KC_FN5 ,KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_MUTE,
                     KC_MRWD,KC_MSTP,KC_MPLY,KC_MPRV,KC_MNXT,
        KC_TRNS,KC_TRNS,
        KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS
    ),
    [MOUS] = KEYMAP(  // layer 2 : Mouse
        // left hand
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS ,
        KC_TRNS,KC_BTN4,KC_BTN2,KC_BTN3,KC_BTN1,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                      KC_TRNS,KC_TRNS,
                                           KC_TRNS,
                                 KC_TRNS,KC_TRNS,KC_TRNS,
        // right hand
             KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
             KC_TRNS,KC_ACL0,KC_TRNS,KC_WH_D,KC_WH_U,KC_TRNS,KC_TRNS,
                     KC_ACL1,KC_MS_L,KC_MS_D,KC_MS_U,KC_MS_R,KC_TRNS,
             KC_TRNS,KC_ACL2,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                             KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,
        KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS
    ),

    [FNXN] = KEYMAP(  // layer 3 : keyboard functions
        // left hand
        RESET,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_FN5,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_FN5,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                      KC_TRNS,KC_TRNS,
                                           KC_TRNS,
                                 KC_TRNS,KC_TRNS,KC_TRNS,
        // right hand
            KC_FN5, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
            KC_FN5, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
            KC_FN5, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,
        KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS
    ),

    [NUMP] = KEYMAP(  // layer 4: numpad
        // left hand
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                      KC_TRNS,KC_TRNS,
                                           KC_TRNS,
                                 KC_TRNS,KC_TRNS,KC_TRNS,
        // right hand
             KC_FN5,KC_NLCK, KC_PSLS,KC_PAST,KC_PAST,KC_PMNS,KC_BSPC,
             KC_FN5 ,KC_NO,  KC_P7,  KC_P8,  KC_P9,  KC_PMNS,KC_BSPC,
                     KC_NO,  KC_P4,  KC_P5,  KC_P6,  KC_PPLS,KC_PENT,
             KC_FN5 ,KC_NO,  KC_P1,  KC_P2,  KC_P3,  KC_PPLS,KC_PENT,
                     KC_P0,  KC_PDOT,KC_SLSH,KC_PENT,KC_PENT,
        KC_TRNS,KC_TRNS,
        KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS
    ),
};
const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_SET(BASE, ON_PRESS),                  // FN0 - push Layer0
    [1] = ACTION_LAYER_MOMENTARY(SYMB),                      // FN1 - switch to Layer1
    [2] = ACTION_LAYER_SET(MOUS, ON_PRESS),                  // FN2 - push Layer2
    [3] = ACTION_LAYER_SET(FNXN, ON_PRESS),                  // FN3 - push Layer3
    [4] = ACTION_LAYER_SET(NUMP, ON_PRESS),                  // FN4 - push Layer4
    [5] = ACTION_LAYER_SET(BASE, ON_PRESS),                  // FN5 - push Layer0
    [6] = ACTION_LAYER_SET(SYMB, ON_PRESS),                  // FN6 - push Layer1
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};
