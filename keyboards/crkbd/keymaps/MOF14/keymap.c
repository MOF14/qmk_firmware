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

12/20/21 filesize: 25316/28672 (88%, 3356 bytes free)
*/

/* todo lists
TODO: 12/20/21, finish optimizing keymap. can probably remove toggle on qwerty.
TODO: 12/20/21, look into implementing a more complex OLED animation.

*/


#include QMK_KEYBOARD_H
#include <stdio.h>

enum layers {
    _QWERTY,
    _COLEMAKDH,
    _NUMBERS,
    _SYMBOLS,
    _ADJUST,
}; //assign variables to layer names

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
        RESET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,               TG(_COLEMAKDH), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      KC_VOLU, KC_BRIU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      KC_VOLD, KC_BRID, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,  KC_TRNS,KC_SPC,       KC_ENT, KC_TRNS,   KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

void oled_layer_callout(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

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
            oled_write_P(PSTR("FN\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("ADJ\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
}

layer_state_t layer_state_set_user(layer_state_t state) {
   switch (get_highest_layer(state)) {
    case _QWERTY:
        rgblight_setrgb (114, 9, 183);
        break;
    case _COLEMAKDH:
        rgblight_setrgb (20, 33, 61);
        break;
    case _NUMBERS:
        rgblight_setrgb (252, 163, 17);
        break;
    case _SYMBOLS:
        rgblight_setrgb (42, 157, 143);
        break;
    case _ADJUST:
        rgblight_setrgb (138, 21, 43);
        break;
    default: //  for any other layers, or the default layer
        rgblight_setrgb (255, 0, 0);
        break;   
    }

    /* colors set 2
        purple: rgba(114, 9, 183, 1);
        oxford-blue: rgba(20, 33, 61, 1);
        orange-web: rgba(252, 163, 17, 1);
        persian-green: rgba(42, 157, 143, 1);
        antique-ruby: rgba(138, 21, 43, 1);
        red: rgba(255, 0, 0, 1);

        https://coolors.co/7209b7-14213d-fca311-2a9d8f-8a152b-ff0000
    */
  return state;
}

static void gyoza_fairy_logo(void) {
  static const char PROGMEM gyoza_fairy_logo[] = {
        // 'gyoza fairy_rotated', 128x32px
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x08, 0xf4, 0x0c, 0x38, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xc0, 0x00, 0x70, 
        0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x0c, 0x60, 0x4c, 0x49, 0x49, 0xd9, 0x76, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 
        0x01, 0x0c, 0x02, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x33, 0x0d, 0x64, 0x25, 0x27, 0x68, 
        0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x1f, 0x22, 0x24, 0x24, 0x24, 0x24, 0x22, 0x41, 0x81, 0x41, 0x0a, 0x02, 0x04, 0x88, 
        0x50, 0x20, 0x20, 0x20, 0x20, 0x23, 0x24, 0x28, 0xb1, 0xa2, 0x04, 0x04, 0x04, 0x08, 0x10, 0xf8, 
        0x0c, 0x04, 0x04, 0x0c, 0x28, 0x90, 0x70, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x06, 0x0c, 
        0x10, 0x10, 0x20, 0x78, 0x4c, 0x60, 0x20, 0x34, 0x15, 0x19, 0x0a, 0x0c, 0x02, 0x01, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x07, 
        0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x61, 0x06, 0x60, 0x4d, 0x49, 0xcb, 
        0xb5, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x08, 0x47, 0x80, 0x00, 0x18, 0x63, 
        0x04, 0x08, 0x00, 0x00, 0x00, 0xe0, 0x90, 0x08, 0x10, 0x60, 0x80, 0x01, 0x20, 0x00, 0x00, 0x1f, 
        0xf0, 0xc0, 0x00, 0x00, 0x21, 0xc4, 0x8a, 0xf1, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0xc0, 0x60, 0x30, 0x88, 0xdc, 0x04, 0x0c, 0x18, 0x30, 0x30, 0x98, 0xc8, 0x78, 0x20, 0x60, 0xc0, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 
        0x40, 0xe0, 0x20, 0x60, 0xc0, 0x80, 0x80, 0xc0, 0x40, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1e, 
        0x30, 0x63, 0x84, 0x80, 0x00, 0xc0, 0x60, 0x00, 0x00, 0xa0, 0xa8, 0xcb, 0x52, 0x62, 0x12, 0x0e, 
        0x03, 0xc0, 0x60, 0x30, 0x88, 0xdc, 0x04, 0x0c, 0x18, 0x30, 0x30, 0x98, 0xc8, 0x78, 0x20, 0x60, 
        0x00, 0x00, 0x00, 0x3e, 0x48, 0x27, 0x10, 0x10, 0x08, 0x04, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 
        0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x03, 0x0e, 0x38, 0x21, 0x43, 0x41, 0x20, 0x10, 0x0c, 
        0x03, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0xff, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x83, 0x19, 0x49, 0x49, 
        0xda, 0x6e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x03, 0x19, 
        0x04, 0x06, 0x00, 0x00, 0x00, 0x01, 0x01, 0x04, 0x66, 0x1b, 0xc9, 0x4b, 0x4e, 0xd0, 0x70, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x02, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0xff, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x83, 0x19, 0x49
  };
  oled_write_raw_P(gyoza_fairy_logo, sizeof(gyoza_fairy_logo));
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_layer_callout();
        // gyoza_fairy_logo(); //for animation debugging
    } else {
        gyoza_fairy_logo();
    }
    return false;
}

#endif // OLED_ENABLE


