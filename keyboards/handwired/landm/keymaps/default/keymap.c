#include QMK_KEYBOARD_H
#define HEART_KEY  LT(0, KC_1)

enum custom_keycodes {
  LAURA = SAFE_RANGE,
  MARKUS,
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {

    case LAURA:  // Types Laura
      if (record->event.pressed) {
        SEND_STRING("Laura & Markus");
      } return false;
      
    case MARKUS:  // Types Markus
      if (record->event.pressed) {
        SEND_STRING("Markus & Laura");
      } return false;

    case HEART_KEY:
    if (record->tap.count > 0) {    // Key is being tapped.
        if (record->event.pressed) {
          SEND_STRING("Moin");
        } else {
        // Handle tap release event...
        }
    } else {                        // Key is being held.
        if (record->event.pressed) {
          SEND_STRING("Hier kann Ihre Werbung stehen");
        } else {
        // Handle hold release event...
        }
    }
    return false;  // Skip default handling.
    // Other macros...
  }
  return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
    * 1x3 keyboard
    */
    [0] = LAYOUT_ortho_1x3(
        MARKUS, HEART_KEY, LAURA
    )
};

