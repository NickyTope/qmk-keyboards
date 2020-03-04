#include "ntope.h"

#define _______ KC_TRNS

enum layers {
  _QWERTY,
  _RAISE,
  _LOWER,
  _NUMPAD,
  _VIMARROWS,
  _LIGHTS
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define RAISE_S  LM(_RAISE, MOD_LGUI)
#define ARROWS MO(_VIMARROWS)
#define NUMPAD MO(_NUMPAD)
#define LIGHTS MO(_LIGHTS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = KEYMAP(
  KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_DEL,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
  KC_LCTL,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_TAB,         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
  KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    NUMPAD,         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS, KC_RSFT,
             KC_LCTL, KC_LALT, KC_LGUI,     LOWER,        KC_LGUI,        KC_RGUI,  KC_SPC,  KC_RALT, LIGHTS,   KC_ENT,
                                                          RAISE,          ARROWS
),
[_RAISE] = KEYMAP(
  KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL, _______,
  KC_TAB,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,         KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_MINS,  KC_EQL, _______,
  _______,   KC_F10,  KC_F11,  KC_F12, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______,
             _______, _______, _______,     _______,      _______,         _______, _______, KC_VOLD, KC_MPLY, KC_VOLU,
                                                          _______,        _______
),
[_LOWER] = KEYMAP(
  KC_TILD,   KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,         KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, KC_PLUS, _______,
  KC_TAB,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,         KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_UNDS, KC_PLUS, _______,
  _______,   KC_F10,  KC_F11,  KC_F12, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______,
             _______, _______, _______,     _______,      _______,         _______, _______, KC_VOLD, KC_MPLY, KC_VOLU,
                                                          _______,        _______
),
[_VIMARROWS] = KEYMAP(
  _______,   _______, _______, _______, _______, _______, _______,         _______, KC_HOME,   KC_UP, KC_END,  _______, _______, _______, KC_DEL,
  _______,   _______, _______, _______, _______, _______, _______,         KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______, _______, _______,
  _______,   _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______,
             _______, _______, _______,     _______,      _______,         _______, _______, _______, _______, _______,
                                                          _______,        _______
),
[_NUMPAD] = KEYMAP(
  _______,   _______, _______, _______, _______, _______, _______,         KC_NLCK, KC_KP_7, KC_KP_8, KC_KP_9, _______, _______, _______, _______,
  _______,   _______, _______, _______, _______, _______, _______,         _______, KC_KP_4, KC_KP_5, KC_KP_6, _______, _______, _______,
  _______,   _______, _______, _______, _______, _______, _______,         _______, KC_KP_1, KC_KP_2, KC_KP_3, _______, _______, _______,
             _______, _______, _______,     _______,      _______,         KC_KP_0, KC_PDOT, _______, _______, _______,
                                                          _______,        _______
),
[_LIGHTS] = KEYMAP(
  RESET,   _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______,
  _______,   RGB_VAI, RGB_SAI, RGB_HUI, RGB_TOG, _______, _______,         _______, _______, _______, _______, _______, _______, _______,
  _______,   RGB_VAD, RGB_SAD, RGB_HUD, RGB_MOD, _______, _______,         _______, _______, _______, _______, _______, _______, _______,
             _______, _______, _______,     _______,      _______,         _______, _______, _______, _______, _______,
                                                          _______,        _______
),
};


const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  return MACRO_NONE;
};

void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) {
    if (clockwise) {
      SEND_STRING("seb");
      // switch (layer_state) {
      //   case 2:
      //     tap_code(KC_DOWN);
      //     break;
      //   case 1:
      //     SEND_STRING(SS_LCTRL("e"));
      //     break;
      //   case 0:
      //     SEND_STRING(SS_LCTRL("u"));
      //     break;
      // }
    } else {
      SEND_STRING("dad");
      // switch (layer_state) {
      //   case 2:
      //     tap_code(KC_UP);
      //     break;
      //   case 1:
      //     SEND_STRING(SS_LCTRL("y"));
      //     break;
      //   case 0:
      //     SEND_STRING(SS_LCTRL("d"));
      //     break;
      // }
    }
  }
}
