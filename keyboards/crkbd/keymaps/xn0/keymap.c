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
#include "config.h"
#include "keymap_spanish.h"
#include "features/layer_lock.h"
#include "features/oled.h"
#include "features/enums.h"
#include "features/hrmods.h"
#include "features/functions.h"
#include "features/dances.h"
#include "features/caps_word.h"



extern uint8_t is_master;


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
  CB_DVK_TIL_I
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_CAPS,    ES_Q,    ES_W,  ES_E,    ES_R,    ES_T,                       ES_Y,    ES_U,    ES_I,    ES_O,   ES_P,    TD(TD_MORD_DIER), 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      SH_TT,  HOME_A,  HOME_S,  HOME_D,  HOME_F,    ES_G,                       ES_H,   HOME_J,  HOME_K, HOME_L, ES_NTIL, SH_TT, 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      ES_LABK,    ES_Z,  ES_X,    ES_C,    ES_V,    ES_B,                       ES_N,    ES_M, ES_COMM,  ES_DOT, ES_MINS, ES_TILD   ,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
         LT(_FUNC,KC_ESC),   LT(_NUM, KC_ENTER),    LT(_MACRO, KC_BSPC),     LT(_SYM, KC_SPC), LT(_NAV, KC_TAB ), LT(_MEDIA, KC_DEL)
                                      //`--------------------------'  `--------------------------'

  ),            

  [_DVORAK] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     XXXXXXX, KC_COMMA, KC_DOT, KC_SCLN, KC_P,   KC_Y,                          KC_F,   KC_G,   KC_C,     KC_H,   KC_L,  TD(TD_MORD_DIER), 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     SH_TT,   HOME_A,   ALT_O,  CTL_E,   SFT_U,   KC_I,                         KC_D,   SFT_R,   CTL_TT,    ALT_N,  GUI_S,  SH_TT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     ES_LABK, ES_MINS, KC_Q,  KC_J,    KC_K,   KC_X,                            KC_B,   KC_M,   KC_W,     KC_V,  KC_Z,  ES_MINS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
       LT(_FUNC,KC_ESC), LT(_NUM, KC_ENTER), LT(_MACRO, KC_BSPC),          LT(_SYM, KC_SPC), LT(_NAV, KC_TAB), LT(_MEDIA, KC_DEL)
  ),

    [_COLEMAK] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_CAPS,     ES_Q,    ES_W,    ES_F,    ES_P,    ES_B,                        ES_J,    ES_L,    ES_U,    ES_Y, ES_NTIL,    TD(TD_MORD_DIER), 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      SH_TT,  HOME_A,  ALT_R,  CTL_S,  SFT_TT,    ES_G,                               ES_M,    SFT_N,  CTL_E,  ALT_I, GUI_O, ES_ACUT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      ES_LABK,     ES_Z,    ES_X,    ES_C,    ES_D,    ES_V,                        ES_K,    ES_H, ES_COMM,  ES_DOT, ES_MINS, ES_TILD   ,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
         LT(_FUNC,KC_ESC),   LT(_NUM, KC_ENTER),    LT(_MACRO, KC_BSPC),     LT(_SYM, KC_SPC), LT(_NAV, KC_TAB ), LT(_MEDIA, KC_DEL)
                                      //`--------------------------'  `--------------------------'

  ),            

  [_FUNC] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX,   KC_F7,   KC_F8,   KC_F9,  KC_F12, KC_F15,
  //|--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                      XXXXXXX,   KC_F4,   KC_F5,   KC_F6,  KC_F11, KC_F14,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,   KC_F1,   KC_F2,   KC_F3,  KC_F10, KC_F13,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                       XXXXXXX, XXXXXXX, XXXXXXX,     KC_SPC, KC_BSPC, KC_DEL
                                      //`--------------------------'  `--------------------------'
  ),


      [_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LAYER_LOCK,                      ES_PLUS ,  ES_7,    ES_8,    ES_9, ES_ASTR , XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                      ES_MINS ,  ES_4,    ES_5,    ES_6, ES_SLSH , ES_MORD,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      ES_0,      ES_1,    ES_2,    ES_3,  ES_EQL,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                       XXXXXXX, XXXXXXX, XXXXXXX,      KC_SPC, KC_BSPC, KC_DEL
                                      //`--------------------------'  `--------------------------'
  ),

    [_MACRO] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, LCTL(KC_W),  KC_UP, LCTL(KC_T), LAYER_LOCK,             CLOSE, LGUI(KC_LEFT), LGUI(KC_RIGHT), LGUI(KC_UP), LGUI(KC_DOWN), KC_KVM,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX,  KC_LEFT, LCTL_T(KC_DOWN), LSFT_T(KC_RIGHT), UPDIR,     KC_ALT_TB,SEL_LFT,SEL_RGT, LALT(KC_LEFT),LALT(KC_RIGHT) , XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    LCTL(KC_Y),LCTL(KC_Z),LCTL(KC_X),LCTL(KC_C),LCTL(KC_V), HMTERM,             LALT(KC_SPC),RCS(KC_TAB), KC_CTL_TB, KC_SEL_LN , XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                       XXXXXXX, XXXXXXX,  XXXXXXX,      LT(_SYM, KC_SPC), KC_BSPC, KC_DEL
                                      //`--------------------------'  `--------------------------'
  ),

  

   [_SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      ES_NOT,  ES_SLSH, ES_PERC,   ES_AT, COMMAS,  BRACES,                     LAYER_LOCK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      ES_CIRC, ES_PIPE, ES_AMPR, ES_SLSH, ES_QUES,  ES_EXLM ,                      XXXXXXX, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      ES_BULT, ES_BSLS, ES_HASH, ES_IEXL, ES_IQUE, ES_EURO,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_ESC, KC_ENTER,  KC_BSPC,    XXXXXXX, XXXXXXX, XXXXXXX
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
                                           KC_ESC, KC_ENTER, KC_BSPC,   XXXXXXX,XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

    [_MEDIA] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_BRIU, KC_VOLU, KC_BTN2, KC_MS_UP, KC_BTN1, KC_WH_U,                      LAYER_LOCK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_BRID, KC_VOLD, KC_MS_L,KC_MS_D, KC_MS_R, KC_WH_D,                       XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_RGUI, XXXXXXX,
  //-------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_MUTE, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_ESC,KC_ENTER,  KC_BSPC,     XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

    [_MACRO2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    KC_PSCR, LCTL(ES_PLUS), LCTL(ES_MINS), XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX,   KC_QWE,   KC_DVO,   KC_COLMK,  XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                       XXXXXXX, XXXXXXX, XXXXXXX,       KC_SPC, KC_BSPC, KC_DEL
                                      //`--------------------------'  `--------------------------'
  ),


};


//Combo Settings




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






