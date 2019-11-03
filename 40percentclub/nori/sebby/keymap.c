#include QMK_KEYBOARD_H

enum layers {
  _GAMING,
  _LIGHTS,
};

#define LIGHTS  MO(_LIGHTS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_GAMING] = LAYOUT_ortho_4x4( /* Base */
    KC_1,     KC_2,     KC_3,   KC_4, \
    KC_Q,     KC_W,     KC_E,   KC_R,  \
    KC_A,     KC_S,     KC_D,   KC_F,  \
    KC_LSFT,  KC_LCTL,  LIGHTS,   KC_SPC   \
  ),
  [_LIGHTS] = LAYOUT_ortho_4x4( /* Base */
    _______,     _______,     _______,   _______, \
    RGB_VAI, RGB_SAI, RGB_HUI,   RGB_TOG,  \
    RGB_VAD, RGB_SAD, RGB_HUD, RGB_MOD,  \
    _______,     _______,     _______,   _______   \
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
