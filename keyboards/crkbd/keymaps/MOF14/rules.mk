OLED_ENABLE = yes
OLED_DRIVER = SSD1306

SPLIT_KEYBOARD = yes


WPM_ENABLE = yes
# TAP_DANCE_ENABLE = yes 

#from rules.mk of main repo
RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = yes


# if firmware size over limit, try this option
LTO_ENABLE = yes

EXTRAKEY_ENABLE = yes        # Audio control and System control(+450)

# space saving efforts
MOUSEKEY_ENABLE  = no # Mouse keys(+4700)
COMMAND_ENABLE   = no # Commands for debug and configuration
BOOTMAGIC_ENABLE = no #bootmagic, use reset button rather than keyboard command


CONSOLE_ENABLE = no         # Console for debug(+400)
NKRO_ENABLE = no            # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
MIDI_ENABLE = no            # MIDI controls
AUDIO_ENABLE = no           # Audio output on port C6
UNICODE_ENABLE = no         # Unicode
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
SWAP_HANDS_ENABLE = no      # Enable one-hand typing