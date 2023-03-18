#pragma once

#include "quantum.h"


// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LCTL_T(KC_D)
#define HOME_F LSFT_T(KC_F)

// Right-hand home row mods
#define HOME_J RSFT_T(KC_J)
#define HOME_K LCTL_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_NTIL RGUI_T(KC_SCLN)    

// Left-hand home row mods Dvorak

#define ALT_O LALT_T(KC_O)
#define CTL_E LCTL_T(KC_E)
#define SFT_U LSFT_T(KC_U)

// Right-hand home row mods Dvorak
#define SFT_R RSFT_T(KC_R)
#define CTL_TT LCTL_T(KC_T)
#define ALT_N LALT_T(KC_N)
#define GUI_S RGUI_T(KC_S)

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record);
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record);
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record);
