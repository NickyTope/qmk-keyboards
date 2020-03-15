/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *

 */

#include QMK_KEYBOARD_H

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define NUMB 2 // numbers/motion
#define ARRW 3 // numbers/motion

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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT_labor(
    LT(NUMB, KC_ESC),       KC_Q,  KC_W,   KC_E,   KC_R, KC_T, KC_Y,    KC_U, KC_I, KC_O,   KC_P,    KC_LBRC,
    MT(MOD_LCTL, KC_BSPC),  KC_A,  KC_S,   KC_D,   KC_F, KC_G, KC_H,    KC_J, KC_K, KC_L,   KC_SCLN, KC_QUOT,
    KC_RSFT,                KC_Z,  KC_X,   KC_C,   KC_V, KC_B, KC_N,    KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT,
    MT(MOD_LGUI, KC_ENT), LT(SYMB, KC_SPC), LT(NUMB, KC_ESC), KC_NO,    KC_NO, LT(ARRW, KC_SPC), KC_RALT, KC_RGUI
    ),
[SYMB] = LAYOUT_labor(
    KC_GRV , KC_EXLM, KC_AT,   KC_HASH, KC_DLR, KC_PERC,  KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSLS,
    KC_TRNS, KC_GRV , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_PIPE, KC_UNDS, KC_PLUS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_SCLN, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
[NUMB] = LAYOUT_labor(
    KC_TILD, KC_1, 	  KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS,
    KC_LGUI, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS, KC_LCBR, KC_RCBR, KC_BSLS, KC_MINS, KC_EQL, 
    KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_TRNS, KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS,  KC_TRNS, KC_TRNS, RESET
    ),

[ARRW] = LAYOUT_labor(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_TRNS, KC_END,  KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_TRNS, KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
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
