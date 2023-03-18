
#include "combos.h"
#include "enums.h"
#include "hrmods.h"

uint16_t COMBO_LEN = COMBO_LENGTH;

//qwerty combos 

const uint16_t PROGMEM fj_til_combo[] = {HOME_F, HOME_J, COMBO_END};
const uint16_t PROGMEM bspc_combo[] = {LT(_MACRO, KC_BSPC), LT(_SYM, KC_SPC), COMBO_END};
const uint16_t PROGMEM caps_combo[] = {KC_R, KC_U, COMBO_END};
//dvorak combos 

const uint16_t PROGMEM dvk_til_combo[] = {SFT_U, SFT_R, COMBO_END};

combo_t key_combos[] = {
  [FJ_TILDE] = COMBO(fj_til_combo, KC_QUOT ),
  [LT_BSPC_CB] = COMBO(bspc_combo, LCTL(KC_BSPC) ),
  [DVK_TILDE] = COMBO(dvk_til_combo, KC_QUOT ),
  [CAPSW_COMBO] = COMBO(caps_combo, CAPSW_COMBO ),



};







uint8_t combo_ref_from_layer(uint8_t layer){
    switch (get_highest_layer(layer_state)){
        case _DVORAK: return _QWERTY;
        case _FUNC: return _FUNC;
        case _NUM: return _NUM;
        case _MACRO: return _MACRO;
        case _SYM: return _SYM;
        case _NAV: return _NAV;
        case _MEDIA: return _MEDIA;
        default: return _QWERTY;
    }
   return layer;  // important if default is not in case.
};

