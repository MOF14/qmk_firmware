/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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


/*
MOF14 notes:
to compile use: qmk compile -kb crkbd

rgb animations disabled due to space

12/20/21 filesize: 27090/28672 (94%, 1582 bytes free)
*/

/* todo lists
TODO: 12/21/21, finish optimizing keymap.
TODO: 12/21/21, look into tap-dance for CAD layers.
TODO: 12/21/21, look into OLED_TIMEOUT (config.h)) for flickering on main screen
TODO: 12/21/21, Look into adding function to brighten and dim OLED (OLED_BRIGHTNESS) with auto off (OLED_OFF) at min.

*/


#include QMK_KEYBOARD_H
#include <stdio.h>

enum layers {
    _QWERTY,
    _COLEMAKDH,
    _CAD_NUM, //CAD functions are lower than "normal" layers in editor.
    _CAD_FN, //CAD functions are lower than "normal" layers in editor.
    _NUMBERS,
    _SYMBOLS,
    _ADJUST,
    
}; //assign variables to layer names

enum my_keycodes {
    OLED_BRIGHTER = SAFE_RANGE,
    OLED_DIMMER,
};

int OLED_BRIGHTNESS_VAL = 255;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                    KC_LGUI,  KC_SPC,   MO(_NUMBERS),     MO(_SYMBOLS), KC_BSPC,  KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),

  [_COLEMAKDH] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,   KC_Y, KC_SCLN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,   KC_I, KC_O, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_LGUI,   KC_SPC, MO(_NUMBERS),    MO(_SYMBOLS), KC_BSPC,  KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),

  [_NUMBERS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,  KC_P7,   KC_P8,   KC_P9,  KC_0,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, XXXXXXX,                       KC_NLCK,  KC_P4,   KC_P5,   KC_P6,  KC_PMNS, KC_PAST,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        KC_P0,  KC_P1,   KC_P2,   KC_P3,  KC_PPLS, KC_PENT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, KC_SPC, KC_TRNS,     MO(_ADJUST), KC_ENT, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [_SYMBOLS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_LGUI, KC_SPC, MO(_ADJUST),   KC_TRNS, KC_ENT,  KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [_ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        RESET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,               TG(_COLEMAKDH), TG(_CAD_NUM), TG(_CAD_FN), XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      KC_VOLU, KC_BRIU, OLED_BRIGHTER, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      KC_VOLD, KC_BRID, OLED_DIMMER, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,  KC_TRNS,KC_SPC,       KC_ENT, KC_TRNS,   KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),


  [_CAD_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_PSLS, KC_PAST, KC_1,      KC_2,   KC_3,  KC_BSPC,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_PMNS, KC_PPLS, KC_4,     KC_5,    KC_6,  KC_DOT,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_7,     KC_8,    KC_9,    KC_0,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX,XXXXXXX,    MO(_ADJUST), XXXXXXX,   XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_CAD_FN] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_ESC,      KC_Q,   KC_W,   KC_E,   KC_R,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_F,      KC_A,   KC_S,   KC_D,   KC_F,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_Z,      KC_Z,   KC_X,   KC_C,   KC_C,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX,  KC_N,  XXXXXXX,    MO(_ADJUST), XXXXXXX,   XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  /*
  [_CAD_1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX,XXXXXXX,    XXXXXXX, XXXXXXX,   XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ), 
  */

};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_keyboard_master()) {
    return OLED_ROTATION_270;  // flips the display 90 degrees if offhand
  }
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}
  
// turned off due to build error

// layer_state_t layer_state_set_user(layer_state_t state) {
//    switch (get_highest_layer(state)) {
//     case _QWERTY:
//         rgblight_setrgb (114, 9, 183);
//         break;
//     case _COLEMAKDH:
//         rgblight_setrgb (20, 33, 61);
//         break;
//     case _NUMBERS:
//         rgblight_setrgb (252, 163, 17);
//         break;
//     case _SYMBOLS:
//         rgblight_setrgb (42, 157, 143);
//         break;
//     case _ADJUST:
//         rgblight_setrgb (138, 21, 43);
//         break;
//     default: //  for any other layers, or the default layer
//         rgblight_setrgb (255, 0, 0);
//         break;   
//     }

//     /* colors set 2
//         purple: rgba(114, 9, 183, 1);
//         oxford-blue: rgba(20, 33, 61, 1);
//         orange-web: rgba(252, 163, 17, 1);
//         persian-green: rgba(42, 157, 143, 1);
//         antique-ruby: rgba(138, 21, 43, 1);
//         red: rgba(255, 0, 0, 1);

//         https://coolors.co/7209b7-14213d-fca311-2a9d8f-8a152b-ff0000
//     */
//   return state;
// } 


// static void gyoza_fairy_logo(void) {
//   static const char PROGMEM gyoza_fairy_logo[] = {
//         // 'gyoza fairy_rotated', 128x32px
        // 0x6d, 0x67, 0x3e, 0xcd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xff, 0x00, 0xff, 
        // 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0x3f, 0xbf, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff, 
        // 0xff, 0xf1, 0xf4, 0x8d, 0x2d, 0x6c, 0x27, 0x99, 0xdf, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0x9f, 0xdf, 
        // 0x67, 0x3f, 0x80, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x89, 0xa4, 
        // 0x6d, 0x6d, 0x67, 0x3e, 0xcd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xff, 0x00, 
        // 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0x7f, 0x7f, 0x3f, 
        // 0xcf, 0xf7, 0xfb, 0x7d, 0x3d, 0x7b, 0xe3, 0x8f, 0x3f, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 
        // 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xdf, 0xef, 0xf7, 0xf7, 0x1b, 0xed, 0x83, 0xff, 0xff, 0xff, 
        // 0xf9, 0xfb, 0xe1, 0xec, 0xe6, 0xf3, 0xf3, 0xe7, 0xcf, 0xdf, 0xc4, 0xee, 0xf3, 0xf9, 0xfc, 0x3f, 
        // 0x8f, 0xb7, 0xb9, 0xb5, 0x2c, 0xea, 0xfa, 0xff, 0xff, 0xf9, 0xfc, 0xff, 0xfe, 0xde, 0x39, 0xf3, 
        // 0x87, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xfd, 0xfc, 0xfe, 0xfe, 0xfc, 0xf9, 0xfb, 0xf8, 0xfd, 
        // 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        // 0xfc, 0xf9, 0xfb, 0xe1, 0xec, 0xe6, 0xf3, 0xf3, 0xe7, 0xcf, 0xdf, 0xc4, 0xee, 0xf3, 0xf9, 0xfc, 
        // 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x07, 0x70, 0xae, 0xdc, 0x7b, 0xff, 0xff, 0xfc, 0xf0, 
        // 0x07, 0xff, 0xff, 0xfb, 0x7f, 0xfe, 0xf9, 0xf7, 0xef, 0xf6, 0xf8, 0xff, 0xff, 0xff, 0xef, 0xdf, 
        // 0x39, 0xe7, 0xff, 0xfe, 0x1d, 0xef, 0xf7, 0xfb, 0xfd, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        // 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x52, 
        // 0x2c, 0x6d, 0x4d, 0xf9, 0x9f, 0x79, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xff, 
        // 0x1f, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        // 0xff, 0xff, 0x7f, 0xbf, 0xcf, 0xaf, 0x67, 0x57, 0xd3, 0xfb, 0xf9, 0xcd, 0xe1, 0xfb, 0xf7, 0xf7, 
        // 0xcf, 0x9f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        // 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xf1, 0xf6, 0xeb, 0xcf, 0xdf, 0xdf, 0xcf, 
        // 0xe0, 0xf7, 0xef, 0xdf, 0xdf, 0xdf, 0xba, 0x72, 0xeb, 0xdb, 0x3b, 0xfb, 0xfb, 0xfb, 0xfb, 0xf5, 
        // 0xee, 0xdf, 0xbf, 0xaf, 0x7d, 0x7e, 0x7d, 0xbb, 0xdb, 0xdb, 0xdb, 0xdb, 0xbb, 0x07, 0xff, 0xff, 
        // 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe2, 
        // 0xe9, 0x1b, 0x5b, 0xd9, 0x4f, 0x33, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xbf, 0xcf, 0x7f, 
        // 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        // 0xff, 0x91, 0x64, 0x6d, 0x6d, 0xcd, 0xf9, 0xcf, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
        // 0xf1, 0xff, 0xfc, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        // 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        // 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xe3, 0xcf, 0xd0, 0xef, 0xff, 0xff, 0xff, 0xff, 
        // 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
//   };
//   oled_write_raw_P(gyoza_fairy_logo, sizeof(gyoza_fairy_logo));
// }

static void behelit_logo(void) {
  static const char PROGMEM behelit_logo[] = {
        // 'behelit', 128x32px
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x80, 0x80, 0xc0, 0xe0, 0xe0, 0xf0, 0xf8, 0xf8, 0xfc, 0xfc, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x3f, 0x1f, 0x1f, 0x2f, 0x0f, 0x97, 0x87, 0xc3, 
        0xc3, 0xe1, 0xe1, 0xf0, 0xf0, 0x71, 0x78, 0x38, 0x38, 0x18, 0x18, 0x18, 0x1c, 0x1f, 0x07, 0x04, 
        0x00, 0x00, 0x00, 0x8c, 0x0c, 0x8d, 0xc4, 0xe6, 0xf3, 0xf9, 0x78, 0x3c, 0x00, 0x00, 0x86, 0x8e, 
        0x1c, 0x9c, 0x1c, 0x1e, 0x9e, 0x9e, 0x9e, 0xde, 0xdf, 0x8f, 0x8f, 0x8f, 0x0f, 0x0f, 0x8f, 0x0f, 
        0x1f, 0x1f, 0x1e, 0xfe, 0xfe, 0xfc, 0xfc, 0xf8, 0xf0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0xfc, 0xfe, 0xff, 
        0xff, 0xff, 0xdf, 0x27, 0x93, 0xc5, 0xf2, 0x70, 0x78, 0x78, 0x78, 0x79, 0x78, 0x70, 0xe1, 0x09, 
        0x01, 0x13, 0x31, 0x01, 0x08, 0x04, 0xc2, 0xe1, 0xf0, 0xf8, 0xfc, 0xfe, 0x7f, 0x3f, 0x1f, 0x0f, 
        0x07, 0x07, 0x03, 0x80, 0xc0, 0xe0, 0xe0, 0x30, 0x10, 0x00, 0xc0, 0xf0, 0xf8, 0xfc, 0xfe, 0xff, 
        0xff, 0xff, 0xc1, 0x9c, 0x3f, 0x7f, 0xff, 0xf3, 0xe1, 0xc0, 0xc8, 0x8c, 0x36, 0x7a, 0xfb, 0x7f, 
        0x7f, 0xbf, 0xfe, 0xff, 0xcf, 0xcf, 0x82, 0xe6, 0xe6, 0xe5, 0xe2, 0xc6, 0x8e, 0x9e, 0x7f, 0xfd, 
        0xd8, 0xc4, 0xd8, 0xa0, 0x21, 0xc1, 0x07, 0x1f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xf8, 0xf0, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x80, 0xc0, 0xf0, 0xf8, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0x07, 0xff, 0xff, 0x00, 0x03, 0x11, 0x7c, 0x7e, 0xe6, 0xc7, 0xe7, 0xff, 0x7e, 0x3c, 0x00, 0x83, 
        0x7c, 0x00, 0x00, 0x80, 0x1c, 0x00, 0xff, 0xff, 0xff, 0x7f, 0x8b, 0x80, 0x80, 0xe0, 0xe0, 0xf0, 
        0xf8, 0x7c, 0x7e, 0x1f, 0xe7, 0xf3, 0xfd, 0xfc, 0xfe, 0xe2, 0xc0, 0x89, 0x85, 0x03, 0x03, 0x03, 
        0x03, 0x07, 0x07, 0x07, 0x0f, 0xfe, 0xf8, 0xe3, 0x8f, 0x1f, 0x7f, 0xff, 0xff, 0xfc, 0xf8, 0x83, 
        0x07, 0x1f, 0x1f, 0x3f, 0xbf, 0xbf, 0xdf, 0xdf, 0xc3, 0x87, 0x0f, 0x1f, 0xff, 0xff, 0xff, 0xfc, 
        0xff, 0xef, 0xff, 0xf7, 0xf3, 0xf0, 0xef, 0xc8, 0x10, 0x40, 0x03, 0x3f, 0xff, 0xff, 0xff, 0xff, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xf0, 0xfc, 
        0x7e, 0x3f, 0x1f, 0x0f, 0x07, 0x83, 0xc5, 0xc1, 0xc1, 0xf3, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0a, 
        0x00, 0x07, 0x7f, 0x80, 0x03, 0x0e, 0x1c, 0x3c, 0x3c, 0x7c, 0x7c, 0x7c, 0x3e, 0x3e, 0x1f, 0x8f, 
        0xc0, 0x30, 0x08, 0x83, 0x40, 0x6c, 0xb3, 0xd1, 0xd8, 0xee, 0xe7, 0xf7, 0xf3, 0xfb, 0xff, 0xfd, 
        0xfc, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xf8, 
        0x00, 0x00, 0x01, 0xe4, 0xf8, 0x80, 0x01, 0x07, 0xff, 0xfe, 0xe0, 0x07, 0x1f, 0xff, 0xff, 0xff, 
        0xfe, 0xf0, 0x00, 0x07, 0x7f, 0x3f, 0xbf, 0xff, 0xff, 0xff, 0xde, 0x80, 0x80, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0x07, 0xf7, 0xf7, 0xf7, 0xf3, 0xf3, 0x30, 0xc3, 0x10, 0x00, 0x01, 0x07, 0xff, 0xff, 

  };
  oled_write_raw_P(behelit_logo, sizeof(behelit_logo));
}

// static void zodd_logo(void) {
//   static const char PROGMEM zodd_logo[] = {
//         // 'flying zodd', 128x32px
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xfc, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xfc, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xff, 
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x7f, 
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xc8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xfb, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xfd, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
//         0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
//         0x00, 0x00, 0x0f, 0xe0, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
//         0x00, 0x00, 0x3f, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
//         0x80, 0x00, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 
//         0xc3, 0x00, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
//         0xff, 0xc0, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00
//   };
//   oled_write_raw_P(zodd_logo, sizeof(zodd_logo));
// }


/* KEYBOARD PET START */

/* settings */
#    define MIN_WALK_SPEED      10
#    define MIN_RUN_SPEED       40

/* advanced settings */
#    define ANIM_FRAME_DURATION 200  // how long each frame lasts in ms
#    define ANIM_SIZE           96   // number of bytes in array. If you change sprites, minimize for adequate firmware size. max is 1024

/* timers */
uint32_t anim_timer = 0;
uint32_t anim_sleep = 0;

/* current frame */
uint8_t current_frame = 0;

/* status variables */
int   current_wpm = 0;
led_t led_usb_state;

bool isSneaking = false;
bool isJumping  = false;
bool showedJump = true;

/* logic */
static void render_luna(int LUNA_X, int LUNA_Y) {
    /* Sit */
    static const char PROGMEM sit[2][ANIM_SIZE] = {
        /* 'sit1', 32x22px */
        {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x68, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x06, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28, 0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        },
        /* 'sit2', 32x22px */
        {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x90, 0x08, 0x18, 0x60, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x0e, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28, 0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        }
    };

    /* Walk */
    static const char PROGMEM walk[2][ANIM_SIZE] = {
        /* 'walk1', 32x22px */
        {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x90, 0x90, 0x90, 0xa0, 0xc0, 0x80, 0x80, 0x80, 0x70, 0x08, 0x14, 0x08, 0x90, 0x10, 0x10, 0x08, 0xa4, 0x78, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0xfc, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x18, 0xea, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x03, 0x06, 0x18, 0x20, 0x20, 0x3c, 0x0c, 0x12, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        },
        /* 'walk2', 32x22px */
        {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x28, 0x10, 0x20, 0x20, 0x20, 0x10, 0x48, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x20, 0xf8, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x10, 0x30, 0xd5, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x02, 0x1c, 0x14, 0x08, 0x10, 0x20, 0x2c, 0x32, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        }
    };

    /* Run */
    static const char PROGMEM run[2][ANIM_SIZE] = {
        /* 'run1', 32x22px */
        {
        0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x08, 0xc8, 0xb0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x40, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0xc4, 0xa4, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x58, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x09, 0x04, 0x04, 0x04, 0x04, 0x02, 0x03, 0x02, 0x01, 0x01, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00,
        },
        /* 'run2', 32x22px */
        {
        0x00, 0x00, 0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x78, 0x28, 0x08, 0x10, 0x20, 0x30, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0xb0, 0x50, 0x55, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x1e, 0x20, 0x20, 0x18, 0x0c, 0x14, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        }
    };

    /* Bark */
    static const char PROGMEM bark[2][ANIM_SIZE] = {
        /* 'bark1', 32x22px */
        {
        0x00, 0xc0, 0x20, 0x10, 0xd0, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        },
        /* 'bark2', 32x22px */
        {
        0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x40, 0x2c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x20, 0x4a, 0x09, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        }
    };

    /* Sneak */
    static const char PROGMEM sneak[2][ANIM_SIZE] = {
        /* 'sneak1', 32x22px */
        {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x40, 0x40, 0x80, 0x00, 0x80, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x21, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x04, 0x04, 0x04, 0x03, 0x01, 0x00, 0x00, 0x09, 0x01, 0x80, 0x80, 0xab, 0x04, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x02, 0x06, 0x18, 0x20, 0x20, 0x38, 0x08, 0x10, 0x18, 0x04, 0x04, 0x02, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00,
        },
        /* 'sneak2', 32x22px */
        {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xa0, 0x20, 0x40, 0x80, 0xc0, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x41, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x02, 0x04, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x04, 0x00, 0x40, 0x40, 0x55, 0x82, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x04, 0x18, 0x10, 0x08, 0x10, 0x20, 0x28, 0x34, 0x06, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
        }
    };

    /* animation */
    void animate_luna(void) {
        /* jump */
        if (isJumping || !showedJump) {
            /* clear */
            oled_set_cursor(LUNA_X, LUNA_Y + 2);
            oled_write("     ", false);

            oled_set_cursor(LUNA_X, LUNA_Y - 1);

            showedJump = true;
        } else {
            /* clear */
            oled_set_cursor(LUNA_X, LUNA_Y - 1);
            oled_write("     ", false);

            oled_set_cursor(LUNA_X, LUNA_Y);
        }

        /* switch frame */
        current_frame = (current_frame + 1) % 2;

        /* current status */
        if (led_usb_state.caps_lock) {
            oled_write_raw_P(bark[abs(1 - current_frame)], ANIM_SIZE);

        } else if (isSneaking) {
            oled_write_raw_P(sneak[abs(1 - current_frame)], ANIM_SIZE);

        } else if (current_wpm <= MIN_WALK_SPEED) {
            oled_write_raw_P(sit[abs(1 - current_frame)], ANIM_SIZE);

        } else if (current_wpm <= MIN_RUN_SPEED) {
            oled_write_raw_P(walk[abs(1 - current_frame)], ANIM_SIZE);

        } else {
            oled_write_raw_P(run[abs(1 - current_frame)], ANIM_SIZE);
        }
    }

    /* animation timer */
    if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
        anim_timer = timer_read32();
        animate_luna();
    }

    /* this fixes the screen on and off bug */
    // if (current_wpm > 0) {
    //     oled_on(); //! likely causing issues related to screen flicker
    //     anim_sleep = timer_read32();
    // } else if (timer_elapsed32(anim_sleep) > OLED_TIMEOUT) {
    //     oled_off(); //! likely causing issues related to screen flicker
    // }
}

/* KEYBOARD PET END */

static void print_status_narrow(void) {
    /* Print current mode */
    oled_set_cursor(0, 2);

    /* Print current layer */
    oled_write("Layer", false);

    oled_set_cursor(0, 3);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("QWERTY\n"), false);
            break;
        case _COLEMAKDH:
            oled_write_P(PSTR("Colemak-DH\n"), false);
            break;
        case _NUMBERS:
            oled_write_P(PSTR("Numbers\n"), false);
            break;
        case _SYMBOLS:
            oled_write_P(PSTR("Symbols\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adjustment\n"), false);
            break;

        case _CAD_NUM:
            oled_write_P(PSTR("CAD #\n"), false);
            break;
        case _CAD_FN:
            oled_write_P(PSTR("CAD fn\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    /* caps lock */
    // oled_set_cursor(0, 6);
    // oled_write("CAPS", led_usb_state.caps_lock);

    /* output brightness val */
    // uint8_t oled_br = OLED_BRIGHTNESS_VAL;
    char    s_oled_br[4];
    itoa(OLED_BRIGHTNESS_VAL, s_oled_br, 10);

    oled_set_cursor(0, 7);
    oled_write("br", false);
    oled_write(s_oled_br, false);




    // Host Keyboard LED Status
    // oled_set_cursor(0, 6);
    // led_t led_state = host_keyboard_led_state();
    // oled_write_P(led_state.num_lock ? PSTR("    ") : PSTR("NUM "), false);
    // oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    // oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

    /* wpm */
    oled_set_cursor(0, 9);
    uint8_t n = get_current_wpm();
    char    wpm_str[4];
    wpm_str[3] = '\0';
    wpm_str[2] = '0' + n % 10;
    wpm_str[1] = '0' + (n /= 10) % 10;
    wpm_str[0] = '0' + n / 10;
    oled_write(wpm_str, false);

    oled_set_cursor(0, 10);
    oled_write(" wpm", false);

    /* KEYBOARD PET RENDER START */
    render_luna(0, 13);
    /* KEYBOARD PET RENDER END */
}

bool oled_task_user(void) {
     /* KEYBOARD PET VARIABLES START */

    current_wpm   = get_current_wpm();
    led_usb_state = host_keyboard_led_state();

    /* KEYBOARD PET VARIABLES END */

    if (is_keyboard_master()) {
        print_status_narrow();
        // gyoza_fairy_logo(); //for animation debugging
    } else {
        behelit_logo();
        // zodd_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record){
     /* KEYBOARD PET STATUS START */
    switch (keycode) {
        case KC_LCTL:
        case KC_RCTL:
            if (record->event.pressed) {
                isSneaking = true;
            } else {
                isSneaking = false;
            }
            break;
        case KC_SPC:
            if (record->event.pressed) {
                isJumping  = true;
                showedJump = false;
            } else {
                isJumping = false;
            }
            break;
            /* KEYBOARD PET STATUS END */
    
    case OLED_BRIGHTER:
        if (record->event.pressed) {

            if (OLED_BRIGHTNESS_VAL != 0 && OLED_BRIGHTNESS_VAL <= 255) {
                OLED_BRIGHTNESS_VAL = OLED_BRIGHTNESS_VAL + 51;
            // OLED_BRIGHTNESS(OLED_BRIGHTNESS_VAL);
            oled_set_brightness(OLED_BRIGHTNESS_VAL);
            }    

            else if (OLED_BRIGHTNESS_VAL == 255 || OLED_BRIGHTNESS_VAL >= 255) {
                OLED_BRIGHTNESS_VAL = 204;
                oled_set_brightness(255);
            } 
            
            else if (OLED_BRIGHTNESS_VAL = = 0)
            oled_on();
            OLED_BRIGHTNESS_VAL = 51;
            // OLED_BRIGHTNESS(OLED_BRIGHTNESS_VAL);
            oled_set_brightness(OLED_BRIGHTNESS_VAL);
            }
        }
    //   break;
      return false; // Skip all further processing of this key

    case OLED_DIMMER:
    if (record->event.pressed) {
      if (OLED_BRIGHTNESS_VAL != 51 && OLED_BRIGHTNESS_VAL >=51) {
        OLED_BRIGHTNESS_VAL = OLED_BRIGHTNESS_VAL - 51;
        // OLED_BRIGHTNESS(OLED_BRIGHTNESS_VAL);
        oled_set_brightness(OLED_BRIGHTNESS_VAL);
      }

      else if (OLED_BRIGHTNESS_VAL >= 0 && OLED_BRIGHTNESS_VAL <= 51) {
                OLED_BRIGHTNESS_VAL = 51;
                oled_set_brightness(51);
            }

      else if (OLED_BRIGHTNESS_VAL == 51)
      {
        oled_off();
        OLED_BRIGHTNESS_VAL = 0;
      }
    }

      
    //   break;
      return false; // Skip all further processing of this key
    default:
      return true; // Process all other keycodes normally
    }
    return true;
}

void suspend_power_down_user(void) {
    rgb_matrix_set_suspend_state(true);
    oled_off();
}

#endif // OLED_ENABLE


