MOUSEKEY_ENABLE = yes   # Mouse keys
OLED_ENABLE     = yes
OLED_DRIVER     = SSD1306
LTO_ENABLE      = yes
WPM_ENABLE = yes
EXTRAKEY_ENABLE = yes
TAP_DANCE_ENABLE = no
BOOTMAGIC_ENABLE = yes
CAPS_WORD_ENABLE = yes
COMBO_ENABLE = yes
SWAP_HANDS_ENABLE = yes

RGBLIGHT_ENABLE = no   # Enable WS2812 RGB underlight.
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no 
MAGIC_ENABLE = no
MUSIC_ENABLE = no 
MIDI_ENABLE = no 
BLUETOOTH_ENABLE = no
NKRO_ENABLE = no
BACKLIGHT_ENABLE = no
AUTO_SHIFT_ENABLE = no


SRC += features/layer_lock.c
SRC += features/oled.c
SRC += features/hrmods.c
SRC += features/functions.c
#SRC += features/dances.c
SRC += features/combos.c
SRC += features/caps_word.c
SRC += features/select_word.c