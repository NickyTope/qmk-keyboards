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
/* Base layer
  *  CTBS = Control (hold), Backspace (tap)
  *  SHENT = Shift (hold), Enter (tap)
  *  SYMESC = Symbols (hold), Esc (tap)
  *  NUMSPC = Numbers (hold), Space (tap)
  *  ARWSPC = Arrows (hold), Space (tap)
  * ,----------------------------------------.             ,----------------------------------------.
  * | ESC |  Q   |  W   |  E   |  R   |  T   |             |   Y  |   U  |  I   |  O   |  P   | BSPC|
  * |-----+------+------+------+------+------|             |------+------+------+------+------+-----|
  * |CTBS |  A   |  S   |  D   |  F   |  G   |             |   H  |  J   |  K   |  L   |  ;   | ' " |
  * |-----+------+------+------+------+------|             |------+------+------+------+------+-----|
  * |SHFT |  Z   |  X   |  C   |  V   |  B   |             |   N  |  M   |  ,   |  .   |  / ? |SHENT|
  * `-----+------+------+------+------+------'             `------+------+------+------+------+-----'
  *             .------.   .------.   .------.  .----.     .------.   .------.   .------.
  *             | WIN  |   |SYMESC|   |NUMSPC|  | TG |     |ARWSPC|   | ALT  |   | WIN  |
  *             '------'   '------'   '------'  '----'     '------'   '------'   '------'
  */
[BASE] = LAYOUT_labor(
      KC_ESC,      KC_Q,      KC_W,  KC_E,   KC_R,   KC_T, KC_Y,    KC_U, KC_I, KC_O,   KC_P,    KC_BSPC,
      MT(MOD_LCTL, KC_BSPC),  KC_A,  KC_S,   KC_D,   KC_F, KC_G, KC_H,    KC_J, KC_K, KC_L,   KC_SCLN, KC_QUOT,
      KC_LSFT,     KC_Z,      KC_X,  KC_C,   KC_V,   KC_B, KC_N, KC_M,    KC_COMM, KC_DOT, KC_SLSH, MT(MOD_RSFT, KC_ENT),
      KC_LGUI, LT(SYMB, KC_ESC), LT(NUMB, KC_SPC),  TG_ENC,    KC_NO, LT(ARRW, KC_SPC), KC_RALT, KC_RGUI
    ),
/* Symbols layer
 *
 * ,----------------------------------------.             ,-----------------------------------------.
 * |     |  !   |  @   |  {   |  }   |  |   |             |      |      |      |      |      |  \ | |
 * |-----+------+------+------+------+------|             |------+------+------+------+------+------|
 * |     |  #   |  $   |  (   |  )   |  `   |             |   +  |  -   |  /   |  *   |  %   |  ' " |
 * |-----+------+------+------+------+------|             |------+------+------+------+------+------|
 * |     |  %   |  ^   |  [   |  ]   |  ~   |             |   &  |  =   |  ,   |  .   |  / ? | - _  |
 * `-----+------+------+------+------+------'             `------+------+------+------+------+------'
 *             .------.   .------.   .------.  .----.     .------.   .------.   .------.
 *             |      |   |      |   |      |  |    |     |      |   |      |   |      |
 *             '------'   '------'   '------'  '----'     '------'   '------'   '------'
 */
[SYMB] = LAYOUT_labor(
                      _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE,  _______,  _______, _______, _______, _______, KC_BSLS,
                      _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,  KC_PLUS, KC_MINS, KC_SLSH, KC_ASTR, KC_PERC, KC_QUOT,
                      _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_AMPR, KC_EQL,  KC_COMM, KC_DOT,  KC_SLSH, KC_MINS,
                      _______, _______, _______, _______,       _______, _______, _______, _______
    ),
/* Numbers layer
 *
 * ,----------------------------------------.             ,-----------------------------------------.
 * |     |      |  F1  |  F2  |  F3  |  F4  |             |      |  7   |  8   |  9   |      |      |
 * |-----+------+------+------+------+------|             |------+------+------+------+------+------|
 * |     |      |  F5  |  F6  |  F7  |  F8  |             |      |  4   |   5  |  6   |  +   |      |
 * |-----+------+------+------+------+------|             |------+------+------+------+------+------|
 * |     |      |  F8  |  F9  |  F11 |  F12 |             |      |  1   |   2  |  3   |  =   |      |
 * `-----+------+------+------+------+------'             `------+------+------+------+------+------'
 *             .------.   .------.   .------.  .----.     .------.   .------.   .------.
 *             |      |   |      |   |      |  |    |     |  0   |   |  ,   |   |  .   |
 *             '------'   '------'   '------'  '----'     '------'   '------'   '------'
 */
[NUMB] = LAYOUT_labor(
                      _______, _______, KC_F1, KC_F2, KC_F3, KC_F4, _______, KC_7, KC_8, KC_9, _______, _______,
                      _______, _______, KC_F5, KC_F6, KC_F7, KC_F8, _______, KC_4, KC_5, KC_6, KC_PPLS, _______,
                      _______, _______, KC_F9, KC_F10, KC_F11, KC_F12, _______, KC_1, KC_2, KC_3, KC_PEQL, _______,
                      _______, _______, _______, _______,       _______, KC_0, KC_COMM, KC_PDOT
                      ),

/* Numbers layer
 *
 * ,----------------------------------------.             ,-----------------------------------------.
 * |     |      |      | VOLD | VOLU |      |             |      | HOME | END  |      |      | DEL  |
 * |-----+------+------+------+------+------|             |------+------+------+------+------+------|
 * |     |      |      | PREV | NEXT | PLAY |             | LEFT | DOWN | UP   | RGHT |      |      |
 * |-----+------+------+------+------+------|             |------+------+------+------+------+------|
 * |     |      |      |      |      |      |             |      | PGDN | PGUP |      |      |      |
 * `-----+------+------+------+------+------'             `------+------+------+------+------+------'
 *             .------.   .------.   .------.  .----.     .------.   .------.   .------.
 *             |      |   |      |   |      |  |    |     |      |   |      |   |      |
 *             '------'   '------'   '------'  '----'     '------'   '------'   '------'
 */
[ARRW] = LAYOUT_labor(
                      _______, _______, _______, KC_VOLD, KC_VOLU, _______, _______, KC_HOME, KC_END,  _______, _______, _______,
                      _______, _______, _______, KC_MPRV, KC_MNXT, KC_MPLY, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
                      _______, _______, _______, _______, _______, _______, _______, KC_PGDN, KC_PGUP, _______, _______, _______,
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
