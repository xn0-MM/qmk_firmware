#pragma once


// Tap Dance keycodes
enum td_keycodes {
    LT_BSPC 
};

// Define a type containing as many tapdance states as you need
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
} td_state_t;

void lt_bspc_finished(tap_dance_state_t *state, void *user_data);
void lt_bspc_reset(tap_dance_state_t *state, void *user_data);
