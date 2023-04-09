#pragma once

#include "quantum.h"


enum combos {
  FJ_TILDE,
  LT_BSPC_CB,
  CAPSW_COMBO,
  DVCAPSW_COMBO,
  TIL_A,
  TIL_O,
  TIL_E,
  TIL_U,
  TIL_I,
  COMBO_LENGTH
};

uint16_t get_combo_term(uint16_t index, combo_t *combo);
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record);


