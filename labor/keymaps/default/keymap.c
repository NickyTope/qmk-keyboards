/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *

 */

#include QMK_KEYBOARD_H

enum layers {
  BASE,
  SYMB,
  NUMB,
  ARRW,
};

enum combos {
  LCOLON_ENTER,
  DF_TAB,
};

const uint16_t PROGMEM lc_combo[] = {KC_L, KC_SCLN, COMBO_END};
const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [LCOLON_ENTER] = COMBO(lc_combo, KC_ENT),
  [DF_TAB] = COMBO(df_combo, KC_TAB)
};

enum custom_keycodes {
                      TG_ENC = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT_labor(
                      KC_ESC,      KC_Q,      KC_W,  KC_E,   KC_R,   KC_T, KC_Y,    KC_U, KC_I, KC_O,   KC_P,    KC_BSPC,
                      MT(MOD_LCTL, KC_BSPC),  KC_A,  KC_S,   KC_D,   KC_F, KC_G, KC_H,    KC_J, KC_K, KC_L,   KC_SCLN, KC_QUOT,
                      KC_LSFT,     KC_Z,      KC_X,  KC_C,   KC_V,   KC_B, KC_N, KC_M,    KC_COMM, KC_DOT, KC_SLSH, MT(MOD_RSFT, KC_ENT),
                      KC_LGUI, LT(SYMB, KC_ESC), LT(NUMB, KC_SPC),  TG_ENC,    KC_NO, LT(ARRW, KC_SPC), KC_RALT, KC_RGUI
    ),
[SYMB] = LAYOUT_labor(
                      KC_GRV , KC_EXLM, KC_AT,   KC_HASH, KC_DLR, KC_PERC,  KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSLS,
                      _______, KC_GRV , _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_PIPE, KC_UNDS, KC_PLUS,
                      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                      _______, _______, KC_SCLN, _______,       _______, _______, _______, _______
    ),
[NUMB] = LAYOUT_labor(
                      KC_TILD, KC_1, 	  KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
                      KC_LGUI, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, KC_LCBR, KC_RCBR, KC_BSLS, KC_MINS, KC_EQL, 
                      _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,
                      _______, _______, _______, _______,  _______,  _______, _______, RESET
    ),

[ARRW] = LAYOUT_labor(
                      _______, _______, _______, _______, _______, _______, _______, KC_HOME, _______, KC_END,  _______, _______,
                      _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
                      _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,
                      _______, _______, _______, _______,         _______, _______, _______, _______
    )
};

bool alt_enc = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case TG_ENC:
    if (record->event.pressed) {
      // when keycode QMKBEST is pressed
      alt_enc = !alt_enc;
    } else {
      // when keycode QMKBEST is released
    }
    break;
  }
  return true;
};

void encoder_update_user(uint8_t index, bool clockwise) {
  // 3 ifs.. surely we can do better than this?
  if (index == 0) {
    if (clockwise) {
      if (alt_enc) {
        tap_code(KC_PGDN);
      } else {
        tap_code(KC_DOWN);
      }
    } else {
      if (alt_enc) {
        tap_code(KC_PGUP);
      } else {
        tap_code(KC_UP);
      }
    }
  }
}
