#pragma once

#include "quantum.h"


enum combos {
  FJ_TILDE,
  LT_BSPC_CB,
  DVK_TILDE,
  CAPSW_COMBO,
  COMBO_LENGTH
};


uint8_t combo_ref_from_layer(uint8_t layer);
