/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *

 */

#include QMK_KEYBOARD_H

enum layers {
  ONE,
  TWO,
};

enum custom_keycodes {
  TG_ENC = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Layer One
   *        ,-----.
   *        | ESC |
   *        |-----|
   *        | TAB |
   *        |-----|
   *   SC UP| CTL |
   *    (  )|-----|  * Press encodes to toggle between mouse scroll / up & down
   *   SC DN| ENT |  * Tap for Enter, hold for Layer Two
   *        `-----'
   */
  [ONE] = LAYOUT_ct(
      KC_ESC,
      KC_TAB,
      KC_LCTL,
      TG_ENC,
      LT(TWO, KC_ENT)
    ),

  /* Layer Two
   *        ,-----.
   *        |  UP |
   *        |-----|
   *        |  -> |
   *        |-----|
   *  VOL UP| DWN |
   *    (  )|-----|
   *  VOL DN|     |
   *        `-----'
   */
  [TWO] = LAYOUT_ct(
      KC_UP,
      KC_RIGHT,
      KC_DOWN,
      TG_ENC,
      _______
    )
};

bool alt_enc = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case TG_ENC:
    if (record->event.pressed) {
      alt_enc = !alt_enc;
    }
    break;
  }
  return true;
};

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (alt_enc) {
    clockwise ? tap_code(KC_UP) : tap_code(KC_DOWN);
    return true;
  }

  if (IS_LAYER_ON(TWO)) {
    clockwise ? tap_code(KC_VOLU) : tap_code(KC_VOLD);
    return true;
  }

  clockwise ? tap_code16(KC_WH_U) : tap_code16(KC_WH_D);
  return true;
}
