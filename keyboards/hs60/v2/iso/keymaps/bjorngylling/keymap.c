#include QMK_KEYBOARD_H

enum custom_keycodes {
    TMUX_NAV_UP = SAFE_RANGE,
    TMUX_NAV_RIGHT,
    TMUX_NAV_DOWN,
    TMUX_NAV_LEFT,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TMUX_NAV_UP:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b") SS_TAP(X_UP));
            }
            break;

        case TMUX_NAV_RIGHT:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b") SS_TAP(X_RIGHT));
            }
            break;

        case TMUX_NAV_DOWN:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b") SS_TAP(X_DOWN));
            }
            break;

        case TMUX_NAV_LEFT:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b") SS_TAP(X_LEFT));
            }
            break;
    }
    return true;
};

enum layers { LAYER_BASE, LAYER_LOWER, LAYER_RAISE, LAYER_ADJUST };

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[LAYER_BASE] = LAYOUT_60_iso( /* Base */
    KC_GRV,  KC_1,    KC_2,    KC_3, KC_4, KC_5, KC_6,   KC_7, KC_8, KC_9,    KC_0,    KC_MINS,         KC_EQL,          KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E, KC_R, KC_T, KC_Y,   KC_U, KC_I, KC_O,    KC_P,    KC_LBRC,         KC_RBRC,
    QK_GESC, KC_A,    KC_S,    KC_D, KC_F, KC_G, KC_H,   KC_J, KC_K, KC_L,    KC_SCLN, KC_QUOT,         KC_NUHS,         KC_ENT,
    KC_LSFT, KC_NUBS, KC_Z,    KC_X, KC_C, KC_V, KC_B,   KC_N, KC_M, KC_COMM, KC_DOT,  KC_SLSH,                               KC_RSFT,
    KC_LCTL, KC_LALT, KC_LGUI,                               KC_SPC,                                  KC_RALT, MO(LAYER_LOWER), MO(LAYER_RAISE), KC_RCTL),

[LAYER_LOWER] = LAYOUT_60_iso( /* FN */
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_F12,  KC_DEL ,
    KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, QK_BOOT,
    KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,               BR_INC,
    KC_VOLU, KC_VOLD, KC_MUTE,                                           KC_TRNS,                                         KC_TRNS, KC_TRNS, KC_TRNS, BR_DEC),

[LAYER_RAISE] = LAYOUT_60_iso( /* Empty for dynamic keymaps */
    KC_TRNS, KC_TRNS,       KC_TRNS,       KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,       TMUX_NAV_UP,   KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, TMUX_NAV_LEFT, TMUX_NAV_DOWN, TMUX_NAV_RIGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,       KC_TRNS,       KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS,
    KC_TRNS, KC_TRNS,       KC_TRNS,                                                     KC_TRNS,                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

[LAYER_ADJUST] = LAYOUT_60_iso( /* Empty for dynamic keymaps */
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                 KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,                                            KC_TRNS,                                            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),
};
// clang-format on
