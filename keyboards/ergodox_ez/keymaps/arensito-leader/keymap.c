#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "sendchar.h"
#include "virtser.h"
#include "keymap_french.h"

#define _______ KC_TRNS
#define UC(x) 0

#define _DFT  0 // default layer
#define _SYMB 1 // symbols
#define _MED  2 // media keys

#define FR_LABK KC_NUBS
#define FR_RABK LSFT(FR_LABK)

enum tap_dance_names {
    TAP_A,
    TAP_R,
    TAP_J,
    TAP_E,
    TAP_DOT,
    TAP_U,
    TAP_C,
    TAP_COL,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* DFT: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  | F6   |           |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   L  |   J ê|   P  |      |      |           |      |   V  |   F  |   U ù|   D  |   K  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   A à|   R è|   E é|   N  |   B  |------|           |------|   G  |   S  |   I  |   T  |   O  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   Z  |   W  |  . , |   H  |      |      |           |      |      |   C ç|   Y  |   M  |   X  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      | Ctrl | Mod4 |  : ; |                                       | Esc  | LP2  | Alt  |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      | LP1  |      |       |      | Shift|      |
 *                                 | Space| LP1  |------|       |------| Shift|Enter |
 *                                 |      |TLP1  | Tab  |       |Bck/Sp|TShift|      |
 *                                 `--------------------'       `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[_DFT] = KEYMAP(  // layer 0 : default
        // left hand
        _______, KC_F1,     KC_F2,         KC_F3,         KC_F4,        KC_F5,   KC_F6,
        _______, FR_Q,      KC_L,          TD(TAP_J),     KC_P,         _______, _______,
        _______, TD(TAP_A), TD(TAP_R),     TD(TAP_E),     KC_N,         KC_B,
        _______, FR_Z,      FR_W,          TD(TAP_DOT),   KC_H,         _______, _______,
        _______, _______,   OSM(MOD_LCTL), OSM(MOD_LGUI), TD(TAP_COL),
                                                        _______,    _______,
                                                                    _______,
                                               KC_SPC , OSL(_SYMB), KC_TAB ,
        // right hand
             KC_F7,       KC_F8,   KC_F9,     KC_F10,    KC_F11,        KC_F12,    _______,
             _______,     KC_V,    KC_F,      TD(TAP_U), KC_D,          KC_K,      _______,
                          KC_G,    KC_S,      KC_I,      KC_T,          KC_O,      _______,
             _______,     _______, TD(TAP_C), KC_Y,      FR_M,          KC_X,      _______,
                                   KC_ESC,    OSL(_MED), OSM(MOD_LALT), _______,   _______,
             _______, _______,
             _______,
             KC_BSPC, OSM(MOD_LSFT), KC_ENT
    ),
// SYMBOLS
/* SYMB: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   '  |   #  |   _  |   \  |   ?  |      |           |      |   ^  |   +  |   -  |   *  |   @  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   &  |   =  |   {  |   (  |   $  |------|           |------|   `  |   )  |   }  |   /  |   ~  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   "  |   <  |   %  |   [  |      |      |           |      |      |   ]  |   !  |   >  |   |  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_SYMB] = KEYMAP(
       // left hand
       _______, _______, _______, _______, _______, _______, _______,
       _______, FR_APOS, FR_HASH, FR_UNDS, FR_BSLS, FR_QUES, _______,
       _______, FR_AMP,  FR_EQL,  FR_LCBR, FR_LPRN, FR_DLR, 
       _______, FR_QUOT, FR_LABK, FR_PERC, FR_LBRC, _______, _______,
       _______, _______, _______, _______, _______,
                                       _______,_______,
                                               _______,
                               _______,_______,_______,
       // right hand
       _______, _______, _______, _______, _______, _______, _______,
       _______, FR_CIRC, FR_PLUS, FR_MINS, FR_ASTR, FR_AT,   _______,
                FR_GRV,  FR_RPRN, FR_RCBR, FR_SLSH, FR_TILD, _______,
       _______, _______, FR_RBRC, FR_EXLM, FR_RABK, FR_PIPE, _______,
                         _______, _______, _______, _______, _______,
       _______, _______,
       _______,
       _______, _______, _______
),
/* MED: media keys and numbers
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        | Beg  | Top  |Bottom| End  |      |      |           |      |      |   4  |  5   |   6  |  E   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | Left | Up   | Down | Right|      |------|           |------|      |   1  |  2   |   3  |  0   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   A  |  B   |  C   |  D   |      |      |           |      |      |   7  |  8   |   9  |  F   |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_MED] = KEYMAP(
       // left hand
       _______, _______, _______, _______, _______, _______, _______,
       _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  _______, _______,
       _______, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, _______, 
       _______, FR_A,    KC_B,    KC_C,    KC_D,    _______, _______,
       _______, _______, _______, _______, _______,
                                       _______,_______,
                                               _______,
                               _______,_______,_______,
       // right hand
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, FR_4,    FR_5,    FR_6,    KC_E,    _______,
                _______, FR_1,    FR_2,    FR_3,    FR_0,    _______,
       _______, _______, FR_7,    FR_8,    FR_9,    KC_F,    _______,
                         _______, _______, _______, _______, _______,
       _______, _______,
       _______,
       _______, _______, _______
),
};

const uint16_t PROGMEM fn_actions[] = {
};

enum custom_keycodes {
    FST_CUSTOM = SAFE_RANGE,
    MC_ECRC
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TAP_A]   = ACTION_TAP_DANCE_DOUBLE(FR_A,    FR_AGRV), // a -> à
    [TAP_R]   = ACTION_TAP_DANCE_DOUBLE(KC_R,    FR_EGRV), // r -> è
    [TAP_J]   = ACTION_TAP_DANCE_DOUBLE(KC_J,    MC_ECRC), // j -> ê
    [TAP_E]   = ACTION_TAP_DANCE_DOUBLE(KC_E,    FR_EACU), // e -> é
    [TAP_DOT] = ACTION_TAP_DANCE_DOUBLE(FR_DOT,  FR_COMM), // . -> ,
    [TAP_U]   = ACTION_TAP_DANCE_DOUBLE(KC_U,    FR_UGRV), // u -> ù
    [TAP_C]   = ACTION_TAP_DANCE_DOUBLE(KC_C,    FR_CCED), // c -> ç
    [TAP_COL] = ACTION_TAP_DANCE_DOUBLE(FR_COLN, FR_SCLN),
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    ergodox_right_led_1_on();
    wait_ms(200);
    ergodox_right_led_2_on();
    wait_ms(200);
    ergodox_right_led_3_on();
    wait_ms(200);
    ergodox_right_led_1_on();
    wait_ms(200);
    ergodox_right_led_2_on();
    wait_ms(200);
    ergodox_right_led_3_on();
    wait_ms(200);
    ergodox_right_led_1_on();
    ergodox_right_led_2_on();
    ergodox_right_led_3_on();
    wait_ms(200);
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if(record->event.pressed) {
        switch(keycode) {
            case MC_ECRC:
                SEND_STRING("<e"); // Should be ê
                return false;
        }
    }
    return true;
}

