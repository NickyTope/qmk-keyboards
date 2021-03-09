#include "kb.h"

enum layers {
  ARRW,
  NUMB,
  LGHT
};

enum combos {
  C_ENTER,
  C_PLUS,
  C_LAYER_SWITCH
};

const uint16_t PROGMEM cb_ent[] = {KC_END, KC_RIGHT, COMBO_END};
const uint16_t PROGMEM cb_plus[] = {KC_LEFT, KC_RIGHT, COMBO_END};
const uint16_t PROGMEM cb_lyr[] = {KC_P7, KC_P9, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [C_ENTER] = COMBO_ACTION(cb_ent),
  [C_PLUS] = COMBO_ACTION(cb_plus),
  [C_LAYER_SWITCH] = COMBO_ACTION(cb_lyr)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[ARRW] = KEYMAP(
		KC_PGUP, TO(NUMB), KC_PGDN, 
		KC_HOME, KC_UP, KC_END, 
		KC_LEFT, KC_DOWN, KC_RIGHT),

	[NUMB] = KEYMAP(
		KC_P7, KC_P8, KC_P9, 
		KC_P4, KC_P5, KC_P6, 
		KC_P1, KC_P2, KC_P3),

	[LGHT] = KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS)

};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case C_ENTER:
      if (pressed) {
        tap_code16(KC_ENT);
      }
      break;
    case C_PLUS:
      if (pressed) {
        tap_code16(KC_PLUS);
      }
      break;
    case C_LAYER_SWITCH:
      if (pressed) {
        layer_move(ARRW);
      }
      break;
  }
}

const rgblight_segment_t PROGMEM lt_arrw[] = RGBLIGHT_LAYER_SEGMENTS(
    {4,1,HSV_RED},
    {6,3,HSV_RED}
);

const rgblight_segment_t PROGMEM lt_numb[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,9,HSV_GREEN}
);

const rgblight_segment_t PROGMEM lt_lght[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,9,HSV_BLUE}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
  lt_arrw,
  lt_numb,
  lt_lght
);

void keyboard_post_init_user(void) {
  rgblight_disable();
  rgblight_layers = my_rgb_layers;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
  rgblight_set_layer_state(0, layer_state_cmp(state, ARRW));
  return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  rgblight_set_layer_state(1, layer_state_cmp(state, NUMB));
  rgblight_set_layer_state(2, layer_state_cmp(state, LGHT));
  return state;
}
