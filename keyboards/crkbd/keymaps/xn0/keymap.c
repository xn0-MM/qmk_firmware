/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>
#include "keymap_spanish.h"
#include "sendstring_spanish.h"
#include "features/layer_lock.h"
#include "features/oled.h"
#include "features/enums.h"


extern uint8_t is_master;

bool is_alt_tab_active = false; 
bool is_ctrl_tab_active = false;

uint16_t alt_tab_timer = 0;     
uint16_t ctrl_tab_timer = 0;





// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LCTL_T(KC_D)
#define HOME_F LSFT_T(KC_F)

// Right-hand home row mods
#define HOME_J RSFT_T(KC_J)
#define HOME_K LCTL_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_NTIL RGUI_T(KC_SCLN)    

// Left-hand home row mods Dvorak

#define ALT_O LALT_T(KC_O)
#define CTL_E LCTL_T(KC_E)
#define SFT_U LSFT_T(KC_U)

// Right-hand home row mods Dvorak
#define SFT_R RSFT_T(KC_R)
#define CTL_TT LCTL_T(KC_T)
#define ALT_N LALT_T(KC_N)
#define GUI_S RGUI_T(KC_S)



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_ESC,    ES_Q,    ES_W,    ES_E,    ES_R,    ES_T,                        ES_Y,    ES_U,    ES_I,    ES_O,   ES_P,   LCTL(KC_BSPC), 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      CW_TOGG,  HOME_A,  HOME_S,  HOME_D,  HOME_F,    ES_G,                       ES_H,   HOME_J,  HOME_K, HOME_L, HOME_NTIL, ES_ACUT, 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      ES_LABK,    ES_Z,  ES_X,    ES_C,    ES_V,    ES_B,                         ES_N,    ES_M, ES_COMM,  ES_DOT, ES_QUOT,  ES_MINS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
         LT(_FUNC,KC_ESC),   LT(_NUM, KC_ENTER),  LT(_MACRO, KC_BSPC),     LT(_SYM, KC_SPC), LT(_NAV, KC_TAB ), LT(_MEDIA, KC_DEL)
                                      //`--------------------------'  `--------------------------'

  ),            

  [_DVORAK] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_ESC, KC_COMMA, KC_DOT, KC_SEMICOLON, KC_P,   KC_Y,                          KC_F,   KC_G,   KC_C,     KC_H,   KC_L,  LCTL(KC_BSPC),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     CW_TOGG,   HOME_A,   ALT_O,  CTL_E,   SFT_U,   KC_I,                         KC_D,   SFT_R,   CTL_TT,    ALT_N,  GUI_S,  ES_ACUT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    ES_LABK, ES_MINS, KC_Q,  KC_J,    KC_K,   KC_X,                         KC_B,   KC_M,   KC_W,     KC_V,  KC_Z,  KC_MINS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
       LT(_FUNC,KC_ESC), LT(_NUM, KC_ENTER), LT(_MACRO, KC_BSPC),          LT(_SYM, KC_SPC), LT(_NAV, KC_TAB), LT(_MEDIA, KC_DEL)
  ),

  [_FUNC] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX,   KC_F7,   KC_F8,   KC_F9,  KC_F12, KC_F15,
  //|--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                      XXXXXXX,   KC_F4,   KC_F5,   KC_F6,  KC_F11, KC_F14,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,   KC_F1,   KC_F2,   KC_F3,  KC_F10, KC_F13,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                       MO(_FUNC), XXXXXXX, XXXXXXX,     KC_SPC, KC_BSPC, KC_DEL
                                      //`--------------------------'  `--------------------------'
  ),


      [_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LAYER_LOCK,                      ES_PLUS ,  ES_7,    ES_8,    ES_9, ES_ASTR , XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                      ES_MINS ,  ES_4,    ES_5,    ES_6, ES_SLSH , XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      ES_0,      ES_1,    ES_2,    ES_3,  ES_EQL,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                       XXXXXXX, MO(_NUM),XXXXXXX,      KC_SPC, KC_BSPC, KC_DEL
                                      //`--------------------------'  `--------------------------'
  ),

    [_MACRO] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, LCTL(KC_W),  KC_UP, LCTL(KC_T), LAYER_LOCK,                     CLOSE, LGUI(KC_LEFT), LGUI(KC_RIGHT), LGUI(KC_UP), LGUI(KC_DOWN), KC_KVM,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX,  KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX,                    KC_ALT_TB,RCS(KC_TAB),KC_CTL_TB, LALT(KC_LEFT),LALT(KC_RIGHT) , XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    LCTL(KC_Y),LCTL(KC_Z),LCTL(KC_X),LCTL(KC_C),LCTL(KC_V), XXXXXXX,    LALT(KC_SPC),RCS(KC_LEFT), RCS(KC_RIGHT),  KC_SEL_LN, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                       XXXXXXX, XXXXXXX,  MO(_MACRO),     KC_SPC, KC_BSPC, KC_DEL
                                      //`--------------------------'  `--------------------------'
  ),

   [_SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      ES_NOT,  ES_SLSH, ES_PERC,   ES_AT, ES_DQUO,  BRACES,                     LAYER_LOCK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      ES_CIRC, ES_PIPE, ES_AMPR, ES_SLSH, ES_QUES,  ES_EXLM ,                      XXXXXXX, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      ES_BULT, ES_BSLS, ES_HASH, ES_IEXL, ES_IQUE, ES_EURO,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_ESC, KC_ENTER,  KC_BSPC,     MO(_SYM), XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

    [_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, KC_HOME, KC_UP, KC_END,  KC_PGUP,                       LAYER_LOCK, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    XXXXXXX, LCTL(KC_F), KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN,                  XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_RGUI, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  LCTL(KC_Y),LCTL(KC_Z),LCTL(KC_X),LCTL(KC_C),LCTL(KC_V), KC_BSPC,             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_ESC, KC_ENTER, KC_BSPC,   XXXXXXX, MO(_NAV), XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

    [_MEDIA] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_BRIU, KC_VOLU, KC_BTN2, KC_MS_UP, KC_BTN1, KC_WH_U,                      LAYER_LOCK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_BRID, KC_VOLD, KC_MS_L,KC_MS_D, KC_MS_R, KC_WH_D,                       XXXXXXX, KC_QWE, KC_DVO, XXXXXXX, XXXXXXX, XXXXXXX,
  //-------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_MUTE, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_ESC,KC_ENTER,  KC_BSPC,     XXXXXXX, XXXXXXX, MO(_MEDIA)
                                      //`--------------------------'  `--------------------------'
  ),


};


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
        case LT(_MACRO, KC_BSPC):
            return TAPPING_TERM_CUSTOM;
        default:
            return TAPPING_TERM;
    }
}


/* bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(_FUNC,KC_ESC):
        case LT(_MACRO, KC_TAB):
        case LT(_NUM, KC_ENTER):
        case LT(_SYM, KC_SPC):
        case LT(_NAV, KC_BSPC):
        case LT(_MEDIA, KC_DEL):
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}*/


bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {  

        //qwerty                 
       // case HOME_A:
            // Immediately select the hold action when another key is tapped.
        //    return true;
 
        //case HOME_S:
            // Immediately select the hold action when another key is tapped.
        //    return true;
 
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
 
        //case HOME_L:
            // Immediately select the hold action when another key is tapped.
        //    return true;
 
        //case HOME_NTIL:
            // Immediately select the hold action when another key is tapped.
        //    return true;
 
        case KC_LSFT:
            // Immediately select the hold action when another key is tapped.
            return true;
 
        case KC_RSFT:
            // Immediately select the hold action when another key is tapped.
            return true;

            // Dvorak
            
        //case ALT_O:
            // Immediately select the hold action when another key is tapped.
        //    return true;
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
        //case ALT_N:
            // Immediately select the hold action when another key is tapped.
        //    return true; 
        //case GUI_S:
            // Immediately select the hold action when another key is tapped.
        //    return true;           
        default:
            // Do not select the hold action when another key is tapped.
            return false;
    }
}

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
            break;
            }
    return true;
}

void matrix_scan_user(void) { // The very important timer.

  layer_lock_task();

  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
  if (is_ctrl_tab_active) {
    if (timer_elapsed(ctrl_tab_timer) > 1000) {
      unregister_code(KC_LCTL);
      is_ctrl_tab_active = false;
    }
  } 
}



