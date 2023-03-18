#pragma once


#include "quantum.h"

enum layer_number {
    _QWERTY = 0,
    _DVORAK,
    _FUNC,
    _NUM,
    _MACRO,
    _SYM,
    _NAV,
    _MEDIA,
};

enum custom_keycodes {
    KC_QWE= SAFE_RANGE,
    KC_DVO,
    KC_KVM,
    KC_ALT_TB,
    KC_CTL_TB,
    KC_SEL_LN,
    LAYER_LOCK,
    CLOSE,
    BRACES,
    
};