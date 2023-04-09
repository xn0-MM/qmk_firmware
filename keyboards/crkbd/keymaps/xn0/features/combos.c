
#include "combos.h"
#include "enums.h"
#include "hrmods.h"

uint16_t COMBO_LEN = COMBO_LENGTH;


//Common combos 
 const uint16_t PROGMEM bspc_combo[] = {LT(_MACRO, KC_BSPC), LT(_SYM, KC_SPC), COMBO_END};

//qwerty combos 

const uint16_t PROGMEM fj_til_combo[] = {HOME_F, HOME_J, COMBO_END};
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

  [CB_QWE_TILDE] = COMBO(fj_til_combo, KC_QUOT ),
  [CB_CAPSW_COMBO] = COMBO(caps_combo, CAPSW_COMBO ),
  
  [CB_TIL_A] = COMBO(dvk_a_til_combo, TIL_A ),
  [CB_TIL_O] = COMBO(dvk_o_til_combo, TIL_O ),
  [CB_TIL_E] = COMBO(dvk_e_til_combo, TIL_E ),
  [CB_TIL_U] = COMBO(dvk_u_til_combo, TIL_U),
  [CB_TIL_I] = COMBO(dvk_i_til_combo, TIL_I ),
  [CB_DVCAPSW_COMBO] = COMBO(dvcaps_combo, CAPSW_COMBO )
  };

uint16_t get_combo_term(uint16_t index, combo_t *combo) {

    // or with combo index, i.e. its name from enum.
    switch (index) {
        case CB_CAPSW_COMBO:
        case CB_DVCAPSW_COMBO:
            return 40;
        
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



