
#include "enums.h"
#include "hrmods.h"





// Home Row Mod tweaks

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case HOME_A:
        case HOME_S:
        case HOME_L:
        case HOME_NTIL: 
        case ALT_O:
        case ALT_N:
        case GUI_S:
            return TAPPING_TERM + 70;
        case LT(_SYM, KC_SPC):
            return TAPPING_TERM + 20;
        default:
            return TAPPING_TERM;
    }
}   


bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(_FUNC,KC_ESC):
        case LT(_NUM, KC_ENTER):
        case LT(_MACRO, KC_BSPC):
        case LT(_NAV, KC_TAB ):
        case LT(_MEDIA, KC_DEL):
        // Immediately select the hold action when another key is pressed.
            return true;
        case LT(_SYM, KC_SPC):
            return false;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}


bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {  

        //qwerty                 
        case HOME_D:
            // Immediately select the hold action when another key is tapped.
            return true;
        case HOME_F:
            // Immediately select the hold action when another key is tapped.
            return true;
        case HOME_J:
            // Immediately select the hold action when another key is tapped.
            return true;
        case HOME_K:
            // Immediately select the hold action when another key is tapped.
            return true;
        case LT(_MACRO, KC_BSPC):
            return true;

    // Dvorak
            
        case CTL_E:
            // Immediately select the hold action when another key is tapped.
            return true;
        case SFT_U:
            // Immediately select the hold action when another key is tapped.
            return true;
        case SFT_R:
            // Immediately select the hold action when another key is tapped.
            return true;
        case CTL_TT:
            // Immediately select the hold action when another key is tapped.
            return true;  
        default:
            // Do not select the hold action when another key is tapped.
            return false;
    }
}