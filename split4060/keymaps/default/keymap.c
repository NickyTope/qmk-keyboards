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
  TG_ENC = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Base layer
   *  CTBS = Control (hold), Backspace (tap)
   *  WINDEL = Win (hold), Delete (tap)
   *  SHENT = Shift (hold), Enter (tap)
   *  SYMENT = Symbols (hold), Enter (tap)
   *  NUMSPC = Numbers (hold), Space (tap)
   *  ARWSPC = Arrows (hold), Space (tap)
   * ,----------------------------------------.   -------   ,----------------------------------------.
   * | ESC |  Q   |  W   |  E   |  R   |  T   |   |BSPC |   |   Y  |   U  |  I   |  O   |  P   | BSPC|
   * |-----+------+------+------+------+------|   -------   |------+------+------+------+------+-----|
   * |CTBS |  A   |  S   |  D   |  F  tab G   |    -----    |   H  |  J   |  K   |  L  ent ;   | ' " |
   * |-----+------+------+------+------+------|    |   |    |------+------+------+------+------+-----|
   * |SHFT |  Z   |  X   |  C   |  V   |  B   |    -----    |   N  |  M   |  ,   |  .   |  / ? |SHENT|
   * `-----+------+------+------+------+------'             `------+------+------+------+------+-----'
   *
   * CTRL                 DEL    WINDEL SYMENT NUMSPC ARWSPC ALT    WIN    RESET
   */
  [BASE] = LAYOUT_4060(
      KC_ESC,      KC_Q,      KC_W,  KC_E,   KC_R,   KC_T, KC_BSPC, KC_Y,    KC_U, KC_I, KC_O,   KC_P,    KC_BSPC,
      MT(MOD_LCTL, KC_BSPC),  KC_A,  KC_S,   KC_D,   KC_F, KC_G, KC_H,    KC_J, KC_K, KC_L,   KC_SCLN, KC_QUOT,
      KC_LSFT,     KC_Z,      KC_X,  KC_C,   KC_V,   KC_B, TG_ENC, KC_N, KC_M,    KC_COMM, KC_DOT, KC_SLSH, MT(MOD_RSFT, KC_ENT),
      KC_LCTL, KC_DEL, MT(MOD_LGUI, KC_DEL), LT(SYMB, KC_ENT), LT(NUMB, KC_SPC), LT(ARRW, KC_SPC), KC_RALT, KC_RGUI, RESET, KC_ENT
      ),

  /* Symbols layer
   *
   * ,----------------------------------------.             ,-----------------------------------------.
   * |  `  |  !   |  @   |  #   |  $   |  %   |             |   ^  |  &   |  *   |  (   |  )   |  \ | |
   * |-----+------+------+------+------+------|             |------+------+------+------+------+------|
   * |     |  `   |      |      |      |      |             |      |  [   |  ]   |  |   |  _   |  +   |
   * |-----+------+------+------+------+------|             |------+------+------+------+------+------|
   * |     |      |      |      |      |      |             |      |      |      |      |      |      |
   * `-----+------+------+------+------+------'             `------+------+------+------+------+------'
   *             .------.   .------.   .------.  .----.     .------.   .------.   .------.
   *             |      |   |      |   |      |  |    |     |      |   |      |   |      |
   *             '------'   '------'   '------'  '----'     '------'   '------'   '------'
   */
  [SYMB] = LAYOUT_4060(
      KC_GRV , KC_EXLM, KC_AT,   KC_HASH, KC_DLR, KC_PERC, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSLS,
      _______, KC_GRV , _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_PIPE, KC_UNDS, KC_PLUS,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
      ),

  /* Numbers layer
   *
   * ,----------------------------------------.             ,-----------------------------------------.
   * |  ~  |   1  |  2   |   3  |   4  |   5  |             |  6   |  7   |  8   |  9   |  0   |      |
   * |-----+------+------+------+------+------|             |------+------+------+------+------+------|
   * |     |  F1  |  F2  |  F3  |  F4  |  F5  |             |  F6  |  {   |   }  |  \   |  -   |  =   |
   * |-----+------+------+------+------+------|             |------+------+------+------+------+------|
   * |     | F7   |  F8  |  F9  |  F10 |  F11 |             | F12  |      |      |      |      |      |
   * `-----+------+------+------+------+------'             `------+------+------+------+------+------'
   *             .------.   .------.   .------.  .----.     .------.   .------.   .------.
   *             |      |   |      |   |      |  |    |     | WIN  |   |  ,   |   |  .   |
   *             '------'   '------'   '------'  '----'     '------'   '------'   '------'
   */
  [NUMB] = LAYOUT_4060(
      KC_TILD, KC_1, 	  KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6, KC_LCBR, KC_RCBR, KC_BSLS, KC_MINS, KC_EQL, 
      _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, _______, _______, _______,  _______, _______,
      _______, _______, _______, _______, _______,      KC_RGUI, _______, _______, _______, _______
      ),

  /* Arrows layer
   *
   * ,----------------------------------------.             ,-----------------------------------------.
   * |     |      |      | VOLD | VOLU |      |             |      | HOME | END  |      |      | DEL  |
   * |-----+------+------+------+------+------|             |------+------+------+------+------+------|
   * |     |      |      | PREV | NEXT | PLAY |             | LEFT | DOWN | UP   | RGHT |      |      |
   * |-----+------+------+------+------+------|             |------+------+------+------+------+------|
   * |     |      |      | BRID | BRIU |      |             |      | PGDN | PGUP |      |      |      |
   * `-----+------+------+------+------+------'             `------+------+------+------+------+------'
   *             .------.   .------.   .------.  .----.     .------.   .------.   .------.
   *             |      |   |      |   |      |  |    |     |      |   |      |   |      |
   *             '------'   '------'   '------'  '----'     '------'   '------'   '------'
   */
  [ARRW] = LAYOUT_4060(
      _______, _______, _______, KC_VOLD, KC_VOLU, ________, ______, _______, KC_HOME, KC_END,  KC_END,  _______, _______,
      _______, _______, _______, KC_MPRV, KC_MNXT, KC_MPLY, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
      _______, _______, _______, KC_BRID, KC_BRIU, ________, ______, _______, KC_PGDN, KC_PGUP, _______, _______, _______,
      _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______
      )
};

bool alt_enc= false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case TG_ENC:
    if (record->event.pressed) {
      alt_enc= !alt_enc;
    }
    break;
  }
  return true;
};


void encoder_update_user(uint8_t index, bool clockwise) {
  if (alt_enc) {
    clockwise ? SEND_STRING(SS_LCTRL("d")) : SEND_STRING(SS_LCTRL("u"));
    return;d
  }

  if (IS_LAYER_ON(NUMB)) {
    clockwise ? tap_code(KC_VOLU) : tap_code(KC_VOLD);
    return;
  }

  if (IS_LAYER_ON(ARRW)) {
    clockwise ? tap_code(KC_VOLU) : tap_code(KC_VOLD);
    return;
  }

  clockwise ? tap_code(KC_UP) : tap_code(KC_DOWN);
}