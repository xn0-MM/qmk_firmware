#pragma once

#include "quantum.h"


enum combos {
  CB_QWE_TILDE,
  CB_LT_BSPC,
  CB_CAPSW_COMBO,
  CB_DVCAPSW_COMBO,
 CB_TIL_A,
  CB_TIL_E,
  CB_TIL_I,
  CB_TIL_O,
  CB_TIL_U,
  CB_DVK_TIL_A,
  CB_DVK_TIL_O,
  CB_DVK_TIL_E,
  CB_DVK_TIL_U,
  CB_DVK_TIL_I,
  COMBO_LENGTH
};

uint16_t get_combo_term(uint16_t index, combo_t *combo);
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record);


