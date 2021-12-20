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
                                          KC_LGUI, KC_SPC, _______,     MO(_ADJUST), KC_ENT, KC_RALT
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
                                        KC_LGUI, KC_SPC, MO(_ADJUST),   _______, KC_ENT,  KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [_ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        RESET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,               DF(_COLEMAKDH), DF(_QWERTY), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      KC_VOLU, KC_BRIU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      KC_VOLD, KC_BRID, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,_______,KC_SPC,       KC_ENT,_______,   KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_270;  // flips the display 180 degrees if offhand
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
        rgblight_setrgb (0x00,  0x00, 0xFF);
        break;
    case _COLEMAKDH:
        rgblight_setrgb (0xFF,  0x00, 0x00);
        break;
    case _NUMBERS:
        rgblight_setrgb (0x00,  0xFF, 0x00);
        break;
    case _SYMBOLS:
        rgblight_setrgb (0x7A,  0x00, 0xFF);
        break;
    case _ADJUST:
        rgblight_setrgb (0x7A,  0xFF, 0xFF);
        break;
    default: //  for any other layers, or the default layer
        rgblight_setrgb (0x00,  0xFF, 0xFF);
        break;
    }
  return state;
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}



static void render_logo(void) {
  static const char PROGMEM my_logo[] = {
    // Paste the code from the previous step below this line!
    // 'gyoza fairy', 32x128px
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0x63, 0x0b, 0x98, 0xf2, 0xe7, 0xf8, 0xfb, 0xf7, 0xf4, 0xfd, 0xff, 0xf6, 0xfb, 
0xff, 0xff, 0xff, 0x7f, 0x7f, 0x7f, 0xff, 0x7f, 0x7f, 0xff, 0x7f, 0xff, 0x7f, 0x7f, 0xff, 0x7f, 
0x7f, 0x7f, 0xf8, 0xf2, 0xeb, 0xcf, 0x9b, 0xb3, 0xaf, 0xaf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 
0xc9, 0x9d, 0xe1, 0xee, 0xdf, 0xd0, 0xf6, 0xff, 0xd8, 0xee, 0xeb, 0xf8, 0xff, 0xd7, 0xd0, 0xbe, 
0xef, 0xe0, 0xfe, 0xce, 0xf5, 0x9b, 0xe3, 0x8f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0x6f, 0xcf, 0xbf, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 
0xbf, 0xbf, 0xdf, 0xff, 0x7f, 0x3d, 0xb9, 0xcb, 0xf2, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfc, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 
0xfd, 0xfc, 0xfe, 0xfe, 0xfe, 0xff, 0x3f, 0xbf, 0x8f, 0x27, 0x77, 0x87, 0xb9, 0x7d, 0x41, 0xdb, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0x26, 0xb0, 0xf9, 0xbf, 0x3e, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xe3, 0xfd, 0x5d, 0x43, 0xf9, 0xbd, 0x81, 0xfb, 0x3b, 0xd7, 0x6f, 0x8f, 0x3f, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0xf9, 0xfb, 0xfa, 0xfa, 0xfb, 0xfb, 0xfb, 
0xff, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xf6, 0xe7, 0x2e, 0xc8, 0xe3, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xbf, 0x3f, 0x7f, 0xbf, 0x3f, 0x7f, 
0xf7, 0xf7, 0xf7, 0xf7, 0xf6, 0xf6, 0xf2, 0xfb, 0xfb, 0xf9, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xc7, 0x17, 0x31, 0xe4, 0xce, 0xf0, 0xf7, 0xef, 0xe8, 0xfb, 0xff, 0xec, 0xf7, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xf1, 0xe4, 0xd6, 0x9f, 0x37, 0x67, 0x5f, 0x5f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x67, 0xf9, 0xf5, 0xfc, 0xfa, 
0xf6, 0xfd, 0xfb, 0xfd, 0x7e, 0x76, 0x3a, 0x38, 0x07, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0x7f, 0xbf, 0xc7, 0xfa, 0x7c, 0x3e, 0xfe, 0x3e, 
0xee, 0xfe, 0xfe, 0xfe, 0x7e, 0xb7, 0xbf, 0xdf, 0xc7, 0x6f, 0x7e, 0x3e, 0xbd, 0x9b, 0xe7, 0xff, 
0xff, 0xff, 0xf9, 0xf4, 0xfa, 0xfa, 0xfb, 0xfb, 0xfb, 0xfb, 0xfd, 0xfe, 0x7f, 0x80, 0x7f, 0xff, 
0xff, 0xff, 0x7f, 0xbe, 0xfd, 0xfb, 0xfb, 0xf9, 0xfe, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0x73, 0xfd, 0xf6, 0xff, 0x7f, 0xaf, 0xde, 
0xee, 0xee, 0xef, 0xdd, 0xbd, 0x7e, 0xee, 0xf7, 0xff, 0xc0, 0xbf, 0x7f, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xcf, 0xd0, 0xdf, 0xdf, 0xe0, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfd, 0xfb, 0xeb, 0xeb, 0xe7, 0xec, 0xeb, 0xf7, 0xff

  };

  oled_write_raw_P(my_logo, sizeof(my_logo));
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_layer_callout();
    } else {
        render_logo();
    }
    return false;
}

#endif // OLED_ENABLE


