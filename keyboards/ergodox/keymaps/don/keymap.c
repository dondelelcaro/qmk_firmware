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
#include "keymap_plover.h"

#define BASE 0
#define SYMB 1
#define MOUS 2
#define FNXN 3
#define NUMP 4
#define PLVR 5


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
                      KC_UP, KC_DOWN,KC_LEFT,KC_RGHT,KC_RGUI,
        KC_DEL,KC_RGUI,
        KC_PGUP,
        KC_PGDN,KC_ENT, KC_SPC
    ),

    [SYMB] = KEYMAP(  // layer 1 : function and symbol keys
        // left hand
       TG(PLVR),KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F11,
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
             KC_TRNS,KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_MUTE,
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
        RESET,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_FN0,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_FN0,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,BL_TOGG,BL_STEP,BL_OFF,BL_ON,KC_TRNS,KC_FN0,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                      KC_TRNS,KC_TRNS,
                                           KC_TRNS,
                                 KC_TRNS,KC_TRNS,KC_TRNS,
        // right hand
            KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
            KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
            KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
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
             KC_TRNS,KC_NLCK, KC_PSLS,KC_PAST,KC_PAST,KC_PMNS,KC_BSPC,
             KC_TRNS,KC_NO,  KC_P7,  KC_P8,  KC_P9,  KC_PMNS,KC_BSPC,
                     KC_NO,  KC_P4,  KC_P5,  KC_P6,  KC_PPLS,KC_PENT,
             KC_TRNS,KC_NO,  KC_P1,  KC_P2,  KC_P3,  KC_PPLS,KC_PENT,
                     KC_P0,  KC_PDOT,KC_SLSH,KC_PENT,KC_PENT,
        KC_TRNS,KC_TRNS,
        KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS
    ),
/* Keymap 8: Steno for Plover
 *
 * ,--------------------------------------------------.           ,----------------------------------------
 * |        |      |      |      |      |      | BASE |           |      |      |      |      |      |     
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+-----
 * |        |   #  |   #  |   #  |   #  |   #  |   #  |           |  #   |  #   |  #   |   #  |   #  |  #  
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+-----
 * |        |      |   T  |   P  |   H  |      |------|           |------|      |  F   |   P  |   L  |  T  
 * |--------+   S  +------+------+------+   *  |   *  |           |  *   |  *   +------+------+------+-----
 * |        |      |   K  |   W  |   R  |      |      |           |      |      |  R   |   B  |   G  |  S  
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+-----
 *   |      |      |      |      |      |                                       |      |      |      |     
 *   `----------------------------------'                                       `--------------------------
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |   A  |   O  |------|       |------|  E   |  U   |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

[PLVR] = KEYMAP(
// left hand
KC_TRNS,KC_NO,  KC_NO,  KC_NO,   KC_NO,  KC_NO,   KC_FN0,
KC_NO,  PV_NUM, PV_NUM, PV_NUM,  PV_NUM, PV_NUM,  PV_NUM,
KC_NO,  PV_LS,  PV_LT,  PV_LP,   PV_LH,  PV_STAR,
KC_NO,  PV_LS,  PV_LK,  PV_LW,   PV_LR,  PV_STAR, PV_STAR,
KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO,
                                           KC_NO, KC_NO,
                                                         KC_NO,
                                           PV_A,  PV_O,  KC_NO,

        // right hand
KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
PV_NUM,  PV_NUM,  PV_NUM,  PV_NUM,  PV_NUM,  PV_NUM,  PV_NUM,
PV_STAR, PV_RF,   PV_RP,   PV_RL,   PV_RT,   PV_RD,
PV_STAR, PV_STAR, PV_RR,   PV_RB,   PV_RG,   PV_RS,   PV_RZ,
KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_NO, KC_NO,
  KC_NO,
  KC_NO,PV_E, PV_U
 ),
};
const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_SET(BASE, ON_PRESS),                  // FN0 - push Layer0
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
#ifdef LEFT_LEDS
   uint8_t layer = biton32(layer_state);
   switch (layer) {
     // TODO: Make this relevant to the ErgoDox EZ.
   case SYMB:
     ergodox_left_led_1_on();
     ergodox_right_led_1_on();
     break;
   case MOUS:
     ergodox_left_led_2_on();
     ergodox_right_led_2_on();
     break;
   case NUMP:
     ergodox_left_led_3_on();
     ergodox_right_led_3_on();
     break;
   default:
     ergodox_left_led_1_off();
     ergodox_left_led_2_off();
     ergodox_left_led_3_off();
     ergodox_right_led_1_off();
     ergodox_right_led_2_off();
     ergodox_right_led_3_off();
     // none
     break;
   }
#endif
  
};

// if this is my ergodox ez, I have left LEDs.
#ifdef LEFT_LEDS

extern bool ergodox_left_led_1;
extern bool ergodox_left_led_2;
extern bool ergodox_left_led_3;


uint8_t ergodox_left_leds_update(void) {
    if (mcp23018_status) { // if there was an error
        return mcp23018_status;
    }
#define LEFT_LED_1_SHIFT        7       // in MCP23018 port B
#define LEFT_LED_2_SHIFT        6       // in MCP23018 port B
#define LEFT_LED_3_SHIFT        7       // in MCP23018 port A

    // set logical value (doesn't matter on inputs)
    // - unused  : hi-Z : 1
    // - input   : hi-Z : 1
    // - driving : hi-Z : 1
    mcp23018_status = i2c_start(I2C_ADDR_WRITE);
    if (mcp23018_status) goto out;
    mcp23018_status = i2c_write(OLATA);
    if (mcp23018_status) goto out;
    mcp23018_status = i2c_write(0b11111111
                                & ~(ergodox_left_led_3<<LEFT_LED_3_SHIFT)
                                );
    if (mcp23018_status) goto out;
    mcp23018_status = i2c_write(0b11111111
                                & ~(ergodox_left_led_2<<LEFT_LED_2_SHIFT)
                                & ~(ergodox_left_led_1<<LEFT_LED_1_SHIFT)
                                );
    if (mcp23018_status) goto out;

 out:
    i2c_stop();
    return mcp23018_status;
}
#endif
