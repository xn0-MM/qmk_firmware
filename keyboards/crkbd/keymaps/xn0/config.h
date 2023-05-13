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
#define EE_HANDS
//#define MASTER_LEFT

// Usb Magic, without split usb detect my promicro doesn´t work 
#define SPLIT_USB_DETECT
#define SPLIT_USB_TIMEOUT 2000
#define SPLIT_WATCHDOG_ENABLE
#define SPLIT_WATCHDOG_TIMEOUT 2500



//Features 

// layer lock 
#define LAYER_LOCK_IDLE_TIMEOUT 60000 

// caps word
#define CAPS_WORD_IDLE_TIMEOUT 5000 

//combos
#define COMBO_TERM 60
#define COMBO_TERM_PER_COMBO
//#define EXTRA_LONG_COMBOS
//#define COMBO_SHOULD_TRIGGER 

//Swap hands 
#define TAPPING_TOGGLE 2

//Home row mods
#define TAPPING_TERM 180
#define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD
#define PERMISSIVE_HOLD_PER_KEY
//#define IGNORE_MOD_TAP_INTERRUPT
#define HOLD_ON_OTHER_KEY_PRESS
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

//Mousekeys y wheel
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_DELAY 50
#define MOUSEKEY_MAX_SPEED 20
#define MOUSEKEY_TIME_TO_MAX 80

#define MOUSEKEY_WHEEL_DELAY 50
#define MOUSEKEY_WHEEL_INTERVAL 80
#define MOUSEKEY_WHEEL_TIME_TO_MAX 40
#define MOUSEKEY_WHEEL_MAX_SPEED 0

//Oled
#define OLED_FONT_H "keyboards/crkbd/keymaps/xn0/glcdfont.c"

#define OLED_TIMEOUT 60000
#define OLED_FADE_OUT
#define OLED_FADE_OUT_INTERVAL 10

// Disabling features to save memory
#define NO_MUSIC_MODE
#define NO_ACTION_ONESHOT