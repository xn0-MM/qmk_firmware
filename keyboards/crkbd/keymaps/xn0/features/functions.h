#pragma once

#include "quantum.h"


bool process_record_user(uint16_t keycode, keyrecord_t *record);

void matrix_scan_user(void);

layer_state_t layer_state_set_user(layer_state_t state);