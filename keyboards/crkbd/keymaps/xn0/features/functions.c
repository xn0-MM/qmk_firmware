

#include "enums.h"
#include "functions.h"
#include "layer_lock.h"
#include "sendstring_spanish.h"
#include "combos.h"



bool is_alt_tab_active = false; 
bool is_ctrl_tab_active = false;

uint16_t alt_tab_timer = 0;     
uint16_t ctrl_tab_timer = 0;




bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    if (!process_layer_lock(keycode, record, LAYER_LOCK)) { return false; }


    switch (keycode) {
        case KC_QWE:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_DVO:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_DVORAK);
            }
            return false;
        case KC_KVM:
            if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_HOME)SS_TAP(X_HOME)SS_TAP(X_UP));
            } 
            return false;
        case KC_ALT_TB:
          if (record->event.pressed) {
            if (!is_alt_tab_active) {
                is_alt_tab_active = true;
                register_code(KC_LALT);
                }
                alt_tab_timer = timer_read();
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            return false;
        case KC_CTL_TB:
          if (record->event.pressed) {
            if (!is_ctrl_tab_active) {
                is_ctrl_tab_active = true;
                register_code(KC_LCTL);
                }
                ctrl_tab_timer = timer_read();
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            return false;
        case KC_SEL_LN:  // Selects the current line.
            if (record->event.pressed) {
                 SEND_STRING(SS_TAP(X_HOME) SS_LSFT(SS_TAP(X_END)));
            }
            return false;
        case CLOSE:
            if (record->event.pressed) {
                 SEND_STRING(SS_LALT(SS_TAP(X_F4)));
            }
            return false; 
        case BRACES:  // Types [], {}, or <> and puts cursor between braces.
            if (record->event.pressed) {

                // uint8_t shifted = get_mods() & (MOD_MASK_SHIFT);
                //uint8_t oneshot_mods = get_oneshot_mods();
                uint8_t shifted = get_mods() & (MOD_MASK_SHIFT);
                uint8_t ctrled = get_mods() & (MOD_MASK_CTRL);
                uint8_t alted = get_mods() & (MOD_MASK_ALT);

                if (shifted) {
                        unregister_code(KC_LSFT);
                        unregister_code(KC_RSFT);
                        SEND_STRING("{}"SS_TAP(X_LEFT));
                    } else if (ctrled) {
                        unregister_code(KC_LCTL);
                        unregister_code(KC_RCTL);
                        SEND_STRING("[]"SS_TAP(X_LEFT));
                    } else if (alted) {
                        unregister_code(KC_LALT);
                        SEND_STRING("<>"SS_TAP(X_LEFT));
                    }else {
                        SEND_STRING("()"SS_TAP(X_LEFT));
                    }
                
                }
                return false;
        case CAPSW_COMBO:
            if (record->event.pressed) {
                 caps_word_toggle();
            }
            return false; 
        }
    return true;
}

void matrix_scan_user(void) { // The very important timer.

  layer_lock_task();

  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 2000) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
  if (is_ctrl_tab_active) {
    if (timer_elapsed(ctrl_tab_timer) > 2000) {
      unregister_code(KC_LCTL);
      is_ctrl_tab_active = false;
    }
  } 
}



