/* Good on you for modifying your layout! if you don't have 
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * There's also a template for adding new layers at the bottom of this file!
 */

#include QMK_KEYBOARD_H

#define FIESTA   0 // default layer
#define TACOTIME 1 // symbols

// Blank template at the bottom
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[FIESTA] = LAYOUT(  
   KC_Q, KC_W, KC_E, KC_R,
   KC_A, KC_S, KC_D, KC_F 
),
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
};

#ifdef OLED_DRIVER_ENABLE
void oled_task_user(void) {

  uint8_t wpm = get_current_wpm();

  if (wpm > 30) {
    oled_write_P(PSTR("Now that's typing!!\n"), false);
  } else if (wpm > 10) {
    oled_write_P(PSTR("Go Faster!\n"), false);
  } else {
    oled_write_P(PSTR("Type something\n"), false);
  }

}
#endif
