#pragma once

#define LT_BSPC LT(0, KC_BSPC)

bool process_record_user(uint16_t keycode, keyrecord_t *record);

void matrix_scan_user(void);