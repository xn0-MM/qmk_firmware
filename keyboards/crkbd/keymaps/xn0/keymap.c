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
#include "features/layer_lock.h"
#include "features/oled.h"
#include "features/enums.h"
#include "features/hrmods.h"
//#include "features/dances.h"
#include "features/functions.h"
#include "features/combos.h"
#include "features/caps_word.h"
//#include "features/select_word.h"


extern uint8_t is_master;


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      CW_TOGG,    ES_Q,    ES_W,    ES_E,    ES_R,    ES_T,                        ES_Y,    ES_U,    ES_I,    ES_O,   ES_P,   KC_BSPC, 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      SH_TT,  HOME_A,  HOME_S,  HOME_D,  HOME_F,    ES_G,                       ES_H,   HOME_J,  HOME_K, HOME_L, HOME_NTIL, SH_TT, 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      ES_LABK,    ES_Z,  ES_X,    ES_C,    ES_V,    ES_B,                         ES_N,    ES_M, ES_COMM,  ES_DOT, ES_MINS,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
         LT(_FUNC,KC_ESC),   LT(_NUM, KC_ENTER),    LT(_MACRO, KC_BSPC),     LT(_SYM, KC_SPC), LT(_NAV, KC_TAB ), LT(_MEDIA, KC_DEL)
                                      //`--------------------------'  `--------------------------'

  ),            

  [_DVORAK] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     CW_TOGG, KC_COMMA, KC_DOT, KC_SEMICOLON, KC_P,   KC_Y,                          KC_F,   KC_G,   KC_C,     KC_H,   KC_L,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     SH_TT,   HOME_A,   ALT_O,  CTL_E,   SFT_U,   KC_I,                         KC_D,   SFT_R,   CTL_TT,    ALT_N,  GUI_S,  SH_TT,
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
      QK_BOOT, XXXXXXX, LCTL(KC_W),  KC_UP, LCTL(KC_T), LAYER_LOCK,             CLOSE, LGUI(KC_LEFT), LGUI(KC_RIGHT), LGUI(KC_UP), LGUI(KC_DOWN), KC_KVM,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX,  KC_LEFT, KC_DOWN, KC_RIGHT, UPDIR,                    KC_ALT_TB,RCS(KC_TAB),KC_CTL_TB, LALT(KC_LEFT),LALT(KC_RIGHT) , XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    LCTL(KC_Y),LCTL(KC_Z),LCTL(KC_X),LCTL(KC_C),LCTL(KC_V), HMTERM,    LALT(KC_SPC),RCS(KC_LEFT), RCS(KC_RIGHT),  SELWORD, KC_SEL_LN, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                       XXXXXXX, XXXXXXX,  XXXXXXX,      LT(_SYM, KC_SPC), KC_BSPC, KC_DEL
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

    [_MACRO2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     KC_PSCR,   LCTL(ES_PLUS),   LCTL(ES_MINS),   XXXXXXX,  XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------|
      XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,  XXXXXXX, XXXXXXX,              XXXXXXX,   LCTL(KC_LEFT),   LCTL(KC_RIGHT),   XXXXXXX,  XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,  XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                       MO(_FUNC), XXXXXXX, XXXXXXX,     KC_SPC, KC_BSPC, KC_DEL
                                      //`--------------------------'  `--------------------------'
  ),


};







