
#include "combos.h"
#include "enums.h"
#include "hrmods.h"

uint16_t COMBO_LEN = COMBO_LENGTH;


//Common combos 
 const uint16_t PROGMEM bspc_combo[] = {LT(_MACRO, KC_BSPC), LT(_SYM, KC_SPC), COMBO_END};

//qwerty combos 

const uint16_t PROGMEM qwe_a_til_combo[] = {HOME_A, HOME_J, COMBO_END};
const uint16_t PROGMEM qwe_e_til_combo[] = {KC_E, HOME_J, COMBO_END};
const uint16_t PROGMEM qwe_i_til_combo[] = {HOME_F, KC_I, COMBO_END};
const uint16_t PROGMEM qwe_o_til_combo[] = {HOME_F, KC_O, COMBO_END};
const uint16_t PROGMEM qwe_u_til_combo[] = {HOME_F, KC_U, COMBO_END};
const uint16_t PROGMEM caps_combo[] = {KC_R, KC_U, COMBO_END};

//dvorak combos 

//Tilde chords for dvk
const uint16_t PROGMEM dvk_a_til_combo[] = {HOME_A, SFT_R, COMBO_END};
const uint16_t PROGMEM dvk_o_til_combo[] = {ALT_O, SFT_R, COMBO_END};
const uint16_t PROGMEM dvk_e_til_combo[] = {CTL_E, SFT_R, COMBO_END};
const uint16_t PROGMEM dvk_u_til_combo[] = {SFT_U, SFT_R, COMBO_END};
const uint16_t PROGMEM dvk_i_til_combo[] = {KC_I, SFT_R, COMBO_END};
// other combos for dvk
const uint16_t PROGMEM dvcaps_combo[] = {KC_P, KC_G, COMBO_END};


combo_t key_combos[] = {
  [CB_LT_BSPC] = COMBO(bspc_combo, LCTL(KC_BSPC) ),

  [CB_TIL_A] = COMBO(qwe_a_til_combo, TIL_A ),
  [CB_TIL_E] = COMBO(qwe_e_til_combo, TIL_E ),
  [CB_TIL_I] = COMBO(qwe_i_til_combo, TIL_I ),
  [CB_TIL_O] = COMBO(qwe_o_til_combo, TIL_O),
  [CB_TIL_U] = COMBO(qwe_u_til_combo, TIL_U ),
  [CB_CAPSW_COMBO] = COMBO(caps_combo, CAPSW_COMBO ),
  
  [CB_DVK_TIL_A] = COMBO(dvk_a_til_combo, TIL_A ),
  [CB_DVK_TIL_O] = COMBO(dvk_o_til_combo, TIL_O ),
  [CB_DVK_TIL_E] = COMBO(dvk_e_til_combo, TIL_E ),
  [CB_DVK_TIL_U] = COMBO(dvk_u_til_combo, TIL_U),
  [CB_DVK_TIL_I] = COMBO(dvk_i_til_combo, TIL_I ),
  [CB_DVCAPSW_COMBO] = COMBO(dvcaps_combo, CAPSW_COMBO )
  };

uint16_t get_combo_term(uint16_t index, combo_t *combo) {

    // or with combo index, i.e. its name from enum.
    switch (index) {
        case CB_CAPSW_COMBO:
        case CB_DVCAPSW_COMBO:
            return 40;
        case  CB_TIL_A:
        case  CB_TIL_E:   
        case  CB_TIL_I:
        case  CB_TIL_O:
        case  CB_TIL_U:
        case  CB_DVK_TIL_A:
        case  CB_DVK_TIL_O:
        case  CB_DVK_TIL_E:
        case  CB_DVK_TIL_U:
        case  CB_DVK_TIL_I:
            return 80;
    }
    return COMBO_TERM;
};


/*
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    // Disable combo `SOME_COMBO` on layer `_LAYER_A` 
    switch (combo_index) {
        case TIL_A:
        case TIL_O:
        case TIL_E:
        case TIL_U:
        case TIL_I:
            if (layer_state_is(_QWERTY)) {
                return false;
            }
        default:
            return true;
    }

    return true;
}; */



