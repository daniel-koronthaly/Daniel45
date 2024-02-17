// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

/*
     * Layer Base/FN0
     *   0   1   2   3   4   5   6   7   8   9   10  11
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │Esc│ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │Bck│
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │Tab│ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │Ent│
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │Sft│ Z │ X │ C │ V │ B │ N │ M │ , │ . │Up │FN2│
     * ├───┴┬──┴─┬─┴──┬┴───┴──┬┴───┴──┬┴───┼───┼───┼───┤
     * │Ctl │GUI │Alt │ Space │  Bck  │FN1 │Lft│Dwn│Rgt│
     * └────┴────┴────┴───────┴───────┴────┴───┴───┴───┘

     * Layer FN1
     *   0   1   2   3   4   5   6   7   8   9   10  11
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │FN0│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │Del│
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │   │   │   │   │   │   │   │ [ │ ] │ - │ = │ ' │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │   │   │   │   │   │   │   │   │   │ / │ \ │   │
     * ├───┴┬──┴─┬─┴──┬┴───┴──┬┴───┴──┬┴───┼───┼───┼───┤
     * │    │    │    │       │       │    │   │   │   │
     * └────┴────┴────┴───────┴───────┴────┴───┴───┴───┘

    * Layer FN2
     *   0   1   2   3   4   5   6   7   8   9   10  11
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │FN0│F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│   │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │   │Nxt│Prv│   │   │   │   │   │   │   │   │   │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │   │V+ │V- │MUT│P/P│   │   │   │   │   │   │   │
     * ├───┴┬──┴─┬─┴──┬┴───┴──┬┴───┴──┬┴───┼───┼───┼───┤
     * │    │    │    │       │       │    │   │   │   │
     * └────┴────┴────┴───────┴───────┴────┴───┴───┴───┘
     */


enum layer_names {
    _BASE,
    _FN1,
    _FN2
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        QK_GESC,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,    KC_BSPC,
        KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,     KC_L,    KC_SCLN, KC_ENT,
        KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,  KC_DOT,  KC_UP,   TG(_FN2),
        KC_LCTL,   KC_LGUI,          KC_LALT, KC_SPC,           KC_BSPC,          TG(_FN1), KC_LEFT, KC_DOWN, KC_RIGHT    
    ),
    [_FN1] = LAYOUT(
        TO(_BASE), KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,     KC_9,    KC_0,    KC_DEL,
        KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC,  KC_MINS, KC_EQL,  KC_QUOT,
        KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_SLSH, KC_BSLS, KC_TRNS,
        KC_TRNS,   KC_TRNS,          KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS     
    ),
    [_FN2] = LAYOUT(
        TO(_BASE), KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,    KC_F9,   KC_F10,  KC_TRNS, 
        KC_TRNS,   KC_MNXT, KC_MPRV, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,   KC_VOLU, KC_VOLD, KC_MUTE, KC_MPLY, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,  
        KC_TRNS,   KC_TRNS,          KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
};

