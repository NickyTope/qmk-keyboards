#include QMK_KEYBOARD_H

#define LEADER_TIMEOUT 350

enum layers {
  base,
  func,
  num,
  lights
};

enum {
  NT_MODI = SAFE_RANGE,
  NT_MODD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* qwerty base layer
   * ,------------------------------------------------------------.
   * |Esc~| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | - | = | Backsp|
   * |------------------------------------------------------------|
   * |Tab  | Q | W | E | R | T | Y | U | I | O | P | [ | ] |  \   |
   * |------------------------------------------------------------|
   * |~Num   | A | S | D | F | G | H | J | K | L | ; | ' | Enter  |
   * |------------------------------------------------------------|
   * |Shift   | Z | X | C | V | B | N | M | , | . | /| Shft/Up|End|
   * |------------------------------------------------------------|
   * |Ctrl|Gui |Alt | Space | Fn | Space |Fn |Home|Left|Down|Right|
   * `------------------------------------------------------------'
   *
   * ~Num is tap for `` or ~ and hold for num layer
   * Yellow LEDS (all)
   * When caps lock is on the leds on the left show a warning in red and purple because something is wrong
   */

	[base] = LAYOUT(
	  KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_NO, KC_BSPC,
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
		LT(num, KC_GRV), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
		KC_LSFT, KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_UP), KC_END,
		KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, MO(func), KC_SPC, MO(func), KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT
  ),

  /* Function layer
   * ,------------------------------------------------------------.
   * | ~ | F1| F2| F3| F4| F5| F6| F7| F8| F9| F10| F11| F12| Del |
   * |------------------------------------------------------------|
   * |     |   |   |   |   |   |   |Hme| Up|End|PrScr |  |   |    |
   * |------------------------------------------------------------|
   * |Caps   |   |   |   |   |git|   |Lft|Dwn|Rgt|   |   |        |
   * |------------------------------------------------------------|
   * |        |   |   |   |   |   |   |   |   |   |   | Pg Up |   |
   * |------------------------------------------------------------|
   * |    |    |    | Lights  |    |       |   |   |    |    |    |
   * `------------------------------------------------------------'
   *
   * Caps key here so you can turn it off!
   * Top Row leds purple, middle Fn blue
   * Git key (g) is lead key for git macros below (s, a, c, k, pp) status, add, commit, gitk, pull/push
   */

	[func] = LAYOUT(
		KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______, KC_DEL,
		_______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_UP, KC_END, KC_PSCR, _______, _______, _______,
		KC_CAPS, _______, _______, _______, _______, KC_LEAD, _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGUP, _______,
		_______, _______, _______, TO(lights), _______, _______, _______, _______, _______, KC_PGDN, _______
  ),

  /* Numpad layer
   * ,------------------------------------------------------------.
   * |   |   |   |   |   |   |   | 7 | 8 | 9 |    |    |    |     |
   * |------------------------------------------------------------|
   * |     |   |   |   |   |   |   | 4 | 5 | 6 | - |    |    |    |
   * |------------------------------------------------------------|
   * |      |NumLck|  |  |  |   |   | 1 | 2 | 3 | + |    |        |
   * |------------------------------------------------------------|
   * |        |   |   |   |   |   |   | 0  | .  |Ent |   |    |   |
   * |------------------------------------------------------------|
   * |    |    |    |        |    |        |   |   |    |    |    |
   * `------------------------------------------------------------'
   *
   * Leds around numpad green
   * when num lock is off theres a red led indicator at the bottom
   */

	[num] = LAYOUT(
		_______, _______, _______, _______, _______, _______, _______, KC_P7, KC_P8, KC_P9, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, KC_P4, KC_P5, KC_P6, KC_PMNS, _______, _______, _______,
		_______, KC_NLCK, _______, _______, _______, _______, _______, KC_P1, KC_P2, KC_P3, KC_PPLS, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______,  KC_P0, KC_PDOT, KC_PDOT, KC_PENT, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  /* Lighting layer
   * ,------------------------------------------------------------.
   * |base|TOG|MOD|HUI|HUD|SAI|SAD|VAI|VAD |  |   |   |   |Reset  |
   * |------------------------------------------------------------|
   * |     |   |   |   |   |   |   |   |   |   |   |    |    |    |
   * |------------------------------------------------------------|
   * |      |   |   |   |   |   |   |   |   |   |   |    |        |
   * |------------------------------------------------------------|
   * |        |   |   |   |   |   |    |    |    |   |   |Modi|   |
   * |------------------------------------------------------------|
   * |    |    |    |        |base|        |   |   |    |Modd|    |
   * `------------------------------------------------------------'
   *
   * Note this layer is toggled on so has escape/fn to return to base
   * Escape led green, Reset red
   * Modi/d: increase/decrease brightness of layer leds
   */

	[lights] = LAYOUT(
		TO(base), RGB_TOG, _______, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, _______, RESET,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, NT_MODI, _______,
		_______, _______, _______, _______, _______, TO(base), _______, _______, _______, NT_MODD, _______
  )
};

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();
    SEQ_ONE_KEY(KC_K) {
      SEND_STRING("gitk"SS_TAP(X_ENTER));
    }
    SEQ_ONE_KEY(KC_S) {
      SEND_STRING("git status"SS_TAP(X_ENTER));
    }
    SEQ_ONE_KEY(KC_A) {
      SEND_STRING("git add . -A");
    }
    SEQ_ONE_KEY(KC_C) {
      SEND_STRING("git commit -m \"\""SS_TAP(X_LEFT));
    }
    SEQ_ONE_KEY(KC_P) {
      SEND_STRING("git pull ;and git push");
    }
  }
}

uint8_t prev = base;
uint16_t hue = 40;
uint16_t sat = 255;
uint16_t val = 120;
uint16_t mod_value = 220;
bool numlck = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case NT_MODI: {
      if (record->event.pressed) {
        if (mod_value <= 220){
           mod_value += 20;
           rgblight_sethsv_at(210, 150, mod_value, 8);
           rgblight_sethsv_at(153, 255, mod_value, 9);
         }
      }
      return false;
    }
    case NT_MODD:
    if (record->event.pressed) {
      if (mod_value >= 20){
         mod_value -= 20;
         rgblight_sethsv_at(210, 150, mod_value, 8);
         rgblight_sethsv_at(153, 255, mod_value, 9);
       }
    }
    return false;
    default:
      return true;
  }
}

void get_hsv(void) {
    hue = rgblight_get_hue();
    sat = rgblight_get_sat();
    val = rgblight_get_val();
}

void reset_hsv(void) {
    rgblight_sethsv(hue, sat, val);
}

void matrix_init_user() {
    rgblight_mode(1);
    rgblight_enable();
    reset_hsv();
}

uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);
  if (prev != lights) {
    switch (layer) {
      case base:
        reset_hsv();
        break;
      case func:
        for (uint8_t i = 0; i < 8; i++) {
          rgblight_sethsv_at(280, 200, mod_value, i);
        }
        rgblight_sethsv_at(210, 150, mod_value, 12);
        break;
      case num:
        rgblight_sethsv_at(153, 255, mod_value, 3);
        rgblight_sethsv_at(153, 255, mod_value, 4);
        rgblight_sethsv_at(153, 255, mod_value, 5);
        rgblight_sethsv_at(153, 255, mod_value, 9);
        if (numlck) {
          rgblight_sethsv_at(359, 255, mod_value, 10);
        } else {
          rgblight_sethsv_at(153, 255, mod_value, 10);
        }
        rgblight_sethsv_at(153, 255, mod_value, 11);
        break;
      case lights:
        rgblight_sethsv_at(359, 255, mod_value, 7);
        rgblight_sethsv_at(210, 150, mod_value, 8);
        rgblight_sethsv_at(153, 255, mod_value, 9);
        rgblight_sethsv_at(100, 255, mod_value, 0);
        break;
    }
  } else {
    get_hsv();
  }

  prev = layer;
  return state;
}

void led_set_user(uint8_t usb_led) {
  if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
    rgblight_sethsv_at(359, 255, 255, 0);
    rgblight_sethsv_at(300, 255, 255, 15);
  }
  if (usb_led & (1<<USB_LED_NUM_LOCK)) {
    numlck = false;
    if (prev == num) {
      rgblight_sethsv_at(153, 255, mod_value, 10);
    }
  } else {
    numlck = true;
    if (prev == num) {
      rgblight_sethsv_at(359, 255, mod_value, 10);
    }
  }
}
