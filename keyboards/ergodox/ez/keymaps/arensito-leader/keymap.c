#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "sendchar.h"
#include "virtser.h"

#define _______ KC_TRNS

#define _DFT  0 // default layer
#define _SYMB 1 // symbols
#define _MED  2 // media keys

enum tap_dance_names {
    TAP_A,
    TAP_R,
    TAP_K,
    TAP_E,
    TAP_N,
    TAP_DOT,
    TAP_U,
    TAP_I,
    TAP_O,
    TAP_C,
    TAP_COL,
    TAP_SPC,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* DFT: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  | F6   |           |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   H  |   J  |   K ê|   L  |      |      |           |      |   V  |   F  |   U ù|   D  |   P  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   A à|   R è|   E é|   N~n|   B  |------|           |------|   G  |   S  |   I ï|   T  |   Ooe|        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   Z  |   W  |  . , |   Q  |      |      |           |      |      |   C ç|   Y  |   M  |   X  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Mod4 |  : ; |                                       |Esc   | LP2  |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      | LP1  |      |       |      | Shift|      |
 *                                 | Space| LP1  |------|       |------| Shift|Enter |
 *                                 | Tab  |TLP1  | LEAD |       |Bck/Sp|TShift|      |
 *                                 `--------------------'       `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[_DFT] = KEYMAP(  // layer 0 : default
        // left hand
        _______, KC_F1,     KC_F2,     KC_F3,         KC_F4,        KC_F5,   KC_F6,
        _______, KC_H,      KC_J,      TD(TAP_K),     KC_L,         _______, _______,
        _______, TD(TAP_A), TD(TAP_R), TD(TAP_E),     TD(TAP_N),    KC_B,
        _______, KC_Z,      KC_W,      TD(TAP_DOT),   KC_Q,         _______, _______,
        _______, _______,   _______,   OSM(MOD_LGUI), TD(TAP_COL),
                                                        _______,    _______,
                                                                    _______,
                                           TD(TAP_SPC), OSL(_SYMB), KC_LEAD,
        // right hand
             KC_F7,       KC_F8,   KC_F9,     KC_F10,    KC_F11,  KC_F12,    _______,
             _______,     KC_V,    KC_F,      TD(TAP_U), KC_D,    KC_P,      _______,
                          KC_G,    KC_S,      TD(TAP_I), KC_T,    TD(TAP_O), _______,
             _______,     _______, TD(TAP_C), KC_Y,      KC_M,    KC_X,      _______,
                                   KC_ESC,    OSL(_MED), _______, _______,   _______,
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
 * |        |   '  |   #  |   _  |   \  |   ?  |      |           |      |      |   +  |   -  |   *  |   @  |        |
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
       _______, KC_QUOT, KC_HASH, KC_UNDS, KC_BSLS, KC_QUES, _______,
       _______, KC_AMPR, KC_EQL,  KC_LCBR, KC_LPRN, KC_DLR, 
       _______, KC_DQUO, KC_LABK, KC_PERC, KC_LBRC, _______, _______,
       _______, _______, _______, _______, _______,
                                       _______,_______,
                                               _______,
                               _______,_______,_______,
       // right hand
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, KC_PLUS, KC_MINS, KC_ASTR, KC_AT,   _______,
                KC_GRV,  KC_RPRN, KC_RCBR, KC_SLSH, KC_TILD, _______,
       _______, _______, KC_RBRC, KC_EXLM, KC_RABK, KC_PIPE, _______,
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
       _______, KC_A,    KC_B,    KC_C,    KC_D,    _______, _______,
       _______, _______, _______, _______, _______,
                                       _______,_______,
                                               _______,
                               _______,_______,_______,
       // right hand
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, KC_4,    KC_5,    KC_6,    KC_E,    _______,
                _______, KC_1,    KC_2,    KC_3,    KC_0,    _______,
       _______, _______, KC_7,    KC_8,    KC_9,    KC_F,    _______,
                         _______, _______, _______, _______, _______,
       _______, _______,
       _______,
       _______, _______, _______
),
};

const uint16_t PROGMEM fn_actions[] = {
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TAP_A]   = ACTION_TAP_DANCE_DOUBLE(KC_A,    UC(0x00e0)),
    [TAP_R]   = ACTION_TAP_DANCE_DOUBLE(KC_R,    UC(0x00e8)),
    [TAP_K]   = ACTION_TAP_DANCE_DOUBLE(KC_K,    UC(0x00ea)),
    [TAP_E]   = ACTION_TAP_DANCE_DOUBLE(KC_E,    UC(0x00e9)),
    [TAP_N]   = ACTION_TAP_DANCE_DOUBLE(KC_N,    UC(0x00f1)),
    [TAP_DOT] = ACTION_TAP_DANCE_DOUBLE(KC_DOT,  KC_COMM),
    [TAP_U]   = ACTION_TAP_DANCE_DOUBLE(KC_U,    UC(0x00f9)),
    [TAP_I]   = ACTION_TAP_DANCE_DOUBLE(KC_I,    UC(0x00ef)),
    [TAP_O]   = ACTION_TAP_DANCE_DOUBLE(KC_O,    UC(0x0153)),
    [TAP_C]   = ACTION_TAP_DANCE_DOUBLE(KC_C,    UC(0x00e7)),
    [TAP_COL] = ACTION_TAP_DANCE_DOUBLE(KC_COLN, KC_SCLN),
    [TAP_SPC] = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_TAB),
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
