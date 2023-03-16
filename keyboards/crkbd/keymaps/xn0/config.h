/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

#pragma once

//#define USE_MATRIX_I2C

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define SPLIT_USB_DETECT
#define SPLIT_USB_TIMEOUT 2500
//#define SPLIT_LAYER_STATE_ENABLE
//#define SPLIT_TRANSPORT_MIRROR
//#define SPLIT_WPM_ENABLE
//#define SPLIT_MODS_ENABLE
//#define SPLIT_LED_STATE_ENABLE
//#define SPLIT_OLED_ENABLE


//features 
#define LAYER_LOCK_IDLE_TIMEOUT 60000 

// caps word
// #define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

//combos
#define COMBO_TERM 60
#define COMBO_REF_DEFAULT _QWERTY
//#define COMBO_ONLY_FROM_LAYER 0

//Swap hands 
#define TAPPING_TOGGLE 1

//Home row mods

#define TAPPING_TERM 180
#define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD
#define PERMISSIVE_HOLD_PER_KEY
#define IGNORE_MOD_TAP_INTERRUPT
#define HOLD_ON_OTHER_KEY_PRESS
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY



//#define TAPPING_FORCE_HOLD
//#define TAPPING_FORCE_HOLD_PER_KEY

//Mousekeys y wheel

#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_DELAY 20
#define MOUSEKEY_MAX_SPEED 20
#define MOUSEKEY_TIME_TO_MAX 64

#define MOUSEKEY_WHEEL_DELAY 20
#define MOUSEKEY_WHEEL_INTERVAL 80
#define MOUSEKEY_WHEEL_TIME_TO_MAX 40
#define MOUSEKEY_WHEEL_MAX_SPEED 0

//#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"
#define OLED_FONT_H "keyboards/crkbd/keymaps/xn0/glcdfont.c"
//#define OLED_FONT_H "keyboards/crkbd/keymaps/xn0/glcdfontL.c"
#define OLED_TIMEOUT 60000
//#define OLED_FADE_OUT
//#define OLED_FADE_OUT_INTERVAL 10


#define NO_MUSIC_MODE
#define NO_ACTION_ONESHOT