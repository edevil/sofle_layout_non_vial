// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    BASE,  // default layer
    MDIA,  // media keys
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | CAPS |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  Mute |    | Pause |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTL | LALT | LCMD | LGUI | /Enter  /       \Space \  | RGUI | DEL  | RALT | RCTL |
 *            |      |      |      |  LT1 |/       /         \      \ | LT1  |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[BASE] = LAYOUT_split_4x6_5(
    KC_ESC,          KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                           KC_6,     KC_7,     KC_8,    KC_9,    KC_0,    KC_BACKSPACE,
    KC_TAB,          KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                           KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,    KC_NONUS_HASH,
    KC_NONUS_BACKSLASH, LCTL_T(KC_A), LALT_T(KC_S), LGUI_T(KC_D), LSFT_T(KC_F), KC_G,   KC_H, RSFT_T(KC_J), LGUI_T(KC_K), LALT_T(KC_L), RCTL_T(KC_RBRC), KC_QUOT,
    SC_LSPO,         KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,   KC_MPLY,    KC_N,     KC_M,     KC_COMM, KC_DOT,  KC_LBRC, SC_RSPC,
    KC_DELETE, KC_LCTL, KC_LALT, LGUI_T(KC_KP_ASTERISK), LT(MDIA, KC_SPACE),       LT(MDIA, KC_ENTER), LCTL_T(KC_SLASH), KC_EQUAL, KC_KP_SLASH, KC_MINUS
),
[MDIA] = LAYOUT_split_4x6_5(
    _______,_______,_______,_______,_______,_______,                              KC_PGUP,   LCTL(KC_A),     KC_UP,      LCTL(KC_E),  _______,LSFT(KC_MINUS),
    RM_TOGG,_______,_______,_______,_______,_______,                              KC_PGDN,      KC_LEFT,      KC_DOWN,     KC_RIGHT,  _______,_______,
    RM_NEXT,_______,_______,_______,_______,LALT(KC_8),                           LSA(KC_8),  0xc50, LGUI(KC_NONUS_BACKSLASH),  0xc4f,_______,_______,
    RM_HUEU,_______,_______,_______,_______,LALT(KC_9),   _______,     _______,   LSA(KC_9),_______,_______,_______,_______,_______,
                    _______,_______,_______,_______,      _______,     _______,   _______,_______,_______,_______
)
};

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_WH_D, KC_WH_U) },
    [MDIA] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) }
};
