#pragma once

#include "quantum.h"


enum combos {
  FJ_TILDE,
  LT_BSPC_CB,
  DVK_TILDE,
  CAPSW_COMBO,
  DVCAPSW_COMBO,
  COMBO_LENGTH
};

uint16_t get_combo_term(uint16_t index, combo_t *combo);


