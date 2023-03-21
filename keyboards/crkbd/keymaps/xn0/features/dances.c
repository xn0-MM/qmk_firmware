#include QMK_KEYBOARD_H

#include "dances.h"
#include "enums.h"


static td_state_t td_state;

td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if ( !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (!state->pressed) return TD_DOUBLE_TAP ;
        else return TD_DOUBLE_HOLD;
    } else return TD_UNKNOWN;
}

// Handle the possible states for each tapdance keycode you define:

void lt_bspc_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            register_code16(KC_BSPC);
            break;
        case TD_SINGLE_HOLD:
            layer_on(_MACRO);
            break;
        case TD_DOUBLE_TAP: 
            register_mods(MOD_BIT(KC_LCTL)); 
            register_code16(KC_BSPC);
            break;
        case TD_DOUBLE_SINGLE_TAP:
            tap_code16(KC_BSPC);
            register_code16(KC_BSPC);
            break;
        case TD_DOUBLE_HOLD: 
            register_code16(KC_BSPC); 
            break;
        case TD_UNKNOWN:   
            register_code16(KC_BSPC);
            break;
        default:
            break;
    }
}

void lt_bspc_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP:
            unregister_code16(KC_BSPC);
            break;
        case TD_SINGLE_HOLD:
            layer_off(_MACRO);
            break;
        case TD_DOUBLE_TAP:
            unregister_mods(MOD_BIT(KC_LCTL)); 
            unregister_code16(KC_BSPC);
            break;
        case TD_DOUBLE_SINGLE_TAP:
            unregister_code16(KC_BSPC);
            break;
        case TD_DOUBLE_HOLD: 
            unregister_code16(KC_BSPC); 
            break;
        case TD_UNKNOWN:   
            unregister_code16(KC_BSPC);
            break;
        default:
            break;
    }
}

// Define `ACTION_TAP_DANCE_FN_ADVANCED()` for each tapdance keycode, passing in `finished` and `reset` functions
tap_dance_action_t tap_dance_actions[] = {
    [LT_BSPC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lt_bspc_finished, lt_bspc_reset)
};
