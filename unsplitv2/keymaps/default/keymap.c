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
  LGHT,
};

enum combos {
  LCOLON_ENTER,
  DF_TAB,
  FAT_ARROW,
  CAPW,
};

enum custom_keycodes {
  TG_ENC = SAFE_RANGE
};

//void keyboard_post_init_user(void) {
  //rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL);
//}

const uint16_t PROGMEM lc_combo[] = {MT(MOD_RCTL, KC_L), MT(MOD_RSFT, KC_SCLN), COMBO_END};
const uint16_t PROGMEM df_combo[] = {MT(MOD_LALT, KC_D), MT(MOD_LGUI, KC_F), COMBO_END};
const uint16_t PROGMEM comma_period_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM caps_word_combo[] = {MT(MOD_LGUI, KC_F), MT(MOD_RGUI, KC_J), COMBO_END};

combo_t key_combos[] = {
  [LCOLON_ENTER] = COMBO(lc_combo, KC_ENT),
  [DF_TAB] = COMBO(df_combo, KC_TAB),
  [FAT_ARROW] = COMBO_ACTION(comma_period_combo),
  [CAPW] = COMBO(caps_word_combo, QK_CAPS_WORD_TOGGLE),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Base layer
   *  CTBS = Control (hold), Backspace (tap)
   *  WINDEL = Win (hold), Delete (tap)
   *  SHENT = Shift (hold), Enter (tap)
   *  SYMENT = Symbols (hold), Enter (tap)
   *  NUMSPC = Numbers (hold), Space (tap)
   *  ARWSPC = Arrows (hold), Space (tap)
   *  WINNUM = Numbers Layer with Win held
   * ,----------------------------------------.             ,----------------------------------------.
   * | ESC |  Q   |  W   |  E   |  R   |  T   |     S-U     |   Y  |   U  |  I   |  O   |  P   | BSPC|
   * |-----+------+------+------+------+------|             |------+------+------+------+------+-----|
   * |CTBS |  A   |  S   |  D  tab F   |  G   |    TG_ENC   |   H  |  J   |  K   |  L  ent ;   | ' " |
   * |-----+------+------+------+------+------|             |------+------+------+------+------+-----|
   * |SHFT |  Z   |  X   |  C   |  V   |  B   |             |   N  |  M   |  ,   |  .   |  / ? |SHENT|
   * `-----+------+------+------+------+------'             `------+------+------+------+------+-----'
   *
   * CTRL                 DEL    WINDEL SYMESC NUMENT ARWSPC ALT  WINNUM   LIGHTS               ENTER
   */
  [BASE] = LAYOUT_unsplit(
      KC_ESC,      KC_Q,      KC_W,  KC_E,   KC_R,   KC_T, G(KC_U), KC_Y,    KC_U, KC_I, KC_O,   KC_P,    KC_BSPC,
      MT(MOD_LCTL, KC_BSPC),  MT(MOD_LSFT, KC_A),  MT(MOD_LCTL, KC_S),   MT(MOD_LALT, KC_D),   MT(MOD_LGUI, KC_F), KC_G, KC_H,    MT(MOD_RGUI, KC_J), MT(MOD_RALT, KC_K), MT(MOD_RCTL, KC_L),   MT(MOD_RSFT, KC_SCLN), MT(MOD_RCTL, KC_QUOT),
      KC_LSFT,     KC_Z,      KC_X,  KC_C,   KC_V,   KC_B, TG_ENC, KC_N, KC_M,    KC_COMM, KC_DOT, KC_SLSH, MT(MOD_RSFT, KC_ENT),
      KC_LCTL, KC_DEL, MT(MOD_LGUI, KC_DEL), LT(SYMB, KC_ESC), LT(NUMB, KC_ENT), LT(ARRW, KC_SPC), KC_RALT, LM(NUMB, MOD_LGUI), MO(LGHT), KC_ENT
      ),

  /* Symbols layer
   *
   * ,----------------------------------------.             ,-----------------------------------------.
   * |  `  |  !   |  @   |  #   |  $   |  %   |             |   ^  |  &   |  *   |  (   |  )   |  \ | |
   * |-----+------+------+------+------+------|             |------+------+------+------+------+------|
   * |     |  `   |      |      |      |      |             |      |  [   |  ]   |  |   |  _   |  +   |
   * |-----+------+------+------+------+------|             |------+------+------+------+------+------|
   * |     |      |      |      |      |      |             |      |  (   |  )   |      |      |      |
   * `-----+------+------+------+------+------'             `------+------+------+------+------+------'
   *
   */
  [SYMB] = LAYOUT_unsplit(
      KC_GRV, KC_EXLM, KC_AT,   KC_HASH, KC_DLR, KC_PERC, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSLS,
      _______, KC_GRV, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_PIPE, KC_UNDS, KC_PLUS,
      _______, _______, _______, _______, _______, _______, _______, _______, KC_LPRN, KC_RPRN, _______, _______, _______,
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
   *
   *                                                    WIN
   */
  [NUMB] = LAYOUT_unsplit(
      KC_TILD, KC_1, 	  KC_2,    KC_3,    KC_4,    KC_5, _______,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6, KC_LCBR, KC_RCBR, KC_BSLS, KC_MINS, KC_EQL, 
      _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, _______,  KC_F12, _______, _______, _______,  _______, _______,
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
   *
   *                                                                       
   */
  [ARRW] = LAYOUT_unsplit(
      _______, _______, _______, KC_VOLD, KC_VOLU, _______, _______, _______, KC_HOME, KC_END,  KC_END,  _______, _______,
      _______, _______, _______, KC_MPRV, KC_MNXT, KC_MPLY, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
      _______, _______, _______, KC_BRID, KC_BRIU, _______, _______, _______, KC_PGDN, KC_PGUP, _______, _______, _______,
      _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______
      ),

  /* Lights layer
   *
   * ,----------------------------------------.             ,-----------------------------------------.
   * |     |      |      | HUI  | SAI  | VAI  |             |      |      |      |      |      |      |
   * |-----+------+------+------+------+------|             |------+------+------+------+------+------|
   * |     |      |      | HUD  | SAD  | VAD  |             |      |      |      |      |      |      |
   * |-----+------+------+------+------+------|             |------+------+------+------+------+------|
   * |     |      |      | TOGG | MODE | MODR |             |      |      |      |      |      |      |
   * `-----+------+------+------+------+------'             `------+------+------+------+------+------'
   *
   * RESET                                                                        
   */
  [LGHT] = LAYOUT_unsplit(
      _______, _______, _______, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, _______, _______, _______,  _______, _______,
      _______, _______, _______, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, RGB_TOG, RGB_MOD, RGB_RMOD,_______, _______, _______, _______, _______, _______, _______,
      QK_BOOT,  _______, _______, _______,         _______, _______, _______, _______, _______, _______
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

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case FAT_ARROW:
      if (pressed) {
        SEND_STRING("=>");
      }
      break;
  }
}

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (IS_LAYER_ON(NUMB)) {
    clockwise ? tap_code16(KC_LCBR) : tap_code16(KC_RCBR);
    return false;
  }

  if (IS_LAYER_ON(SYMB)) {
    clockwise ? tap_code(KC_B) : tap_code(KC_E);
    return false;
  }

  if (IS_LAYER_ON(ARRW)) {
    clockwise ? tap_code(KC_VOLD) : tap_code(KC_VOLU);
    return false;
  }

  if (alt_enc) {
    clockwise ? SEND_STRING(SS_LCTL("u")) : SEND_STRING(SS_LCTL("d"));
    return false;
  }

  clockwise ? tap_code(KC_UP) : tap_code(KC_DOWN);
  return false;
}
