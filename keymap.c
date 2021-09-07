/* Copyright 2019 ReVanTis Zhao
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"

#if __has_include("password.h")
#  include "password.h"
#endif

#ifndef PASSWORD
#define PASSWORD "Made by ReVanTis"
#endif

#ifndef PINCODE
#define PINCODE "This is a pin code"
#endif

#define BMV846_1                    H__NOTE(_C6), H__NOTE(_E6), H__NOTE(_G6), H__NOTE(_C7), H__NOTE(_E7), H__NOTE(_G6), H__NOTE(_C7), H__NOTE(_E7), H__NOTE(_C6), H__NOTE(_E6), H__NOTE(_G6), H__NOTE(_C7), H__NOTE(_E7), H__NOTE(_G6), H__NOTE(_C7), H__NOTE(_E7), \
                                    H__NOTE(_C6), H__NOTE(_D6), H__NOTE(_A6), H__NOTE(_D7), H__NOTE(_F7), H__NOTE(_A6), H__NOTE(_D7), H__NOTE(_F7), H__NOTE(_C6), H__NOTE(_D6), H__NOTE(_A6), H__NOTE(_D7), H__NOTE(_F7), H__NOTE(_A6), H__NOTE(_D7), H__NOTE(_F7), \
                                    H__NOTE(_A5), H__NOTE(_D6), H__NOTE(_G6), H__NOTE(_D7), H__NOTE(_F7), H__NOTE(_G6), H__NOTE(_D7), H__NOTE(_F7), H__NOTE(_A5), H__NOTE(_D6), H__NOTE(_G6), H__NOTE(_D7), H__NOTE(_F7), H__NOTE(_G6), H__NOTE(_D7), H__NOTE(_F7), \
                                    H__NOTE(_C6), H__NOTE(_E6), H__NOTE(_G6), H__NOTE(_C7), H__NOTE(_E7), H__NOTE(_G6), H__NOTE(_C7), H__NOTE(_E7), H__NOTE(_C6), H__NOTE(_E6), H__NOTE(_G6), H__NOTE(_C7), H__NOTE(_E7), H__NOTE(_G6), H__NOTE(_C7), H__NOTE(_E7),

#define SYM9_4TH                    

#define MY_CAPS_LOCK_ON_SOUND       Q__NOTE(_C5), Q__NOTE(_E5), Q__NOTE(_G5), Q__NOTE(_C6),
#define MY_CAPS_LOCK_OFF_SOUND      Q__NOTE(_C6), Q__NOTE(_G5), Q__NOTE(_E5), Q__NOTE(_C5),
#define MY_SCROLL_LOCK_ON_SOUND     Q__NOTE(_C4), Q__NOTE(_E4), Q__NOTE(_G4), Q__NOTE(_C5),
#define MY_SCROLL_LOCK_OFF_SOUND    Q__NOTE(_C5), Q__NOTE(_G4), Q__NOTE(_E4), Q__NOTE(_C4),
#define MY_NUM_LOCK_ON_SOUND        Q__NOTE(_C6), Q__NOTE(_E6), Q__NOTE(_G6), Q__NOTE(_C7),
#define MY_NUM_LOCK_OFF_SOUND       Q__NOTE(_C7), Q__NOTE(_G6), Q__NOTE(_E6), Q__NOTE(_C6),
float bmv846_1 [][2]       = SONG(BMV846_1);

float tone_caps_on[][2]    = SONG(MY_CAPS_LOCK_ON_SOUND);
float tone_caps_off[][2]   = SONG(MY_CAPS_LOCK_OFF_SOUND);
float tone_numlk_on[][2]   = SONG(MY_NUM_LOCK_ON_SOUND);
float tone_numlk_off[][2]  = SONG(MY_NUM_LOCK_OFF_SOUND);
float tone_scroll_on[][2]  = SONG(MY_SCROLL_LOCK_ON_SOUND);
float tone_scroll_off[][2] = SONG(MY_SCROLL_LOCK_OFF_SOUND);

int mappingmatrix [10][6] = {
{ 0x00, 0x01, 0x02, 0x03, 0x04, 0x05 },
{ 0x10, 0x11, 0x12, 0x13, 0x14, 0x15 },
{ 0x20, 0x21, 0x22, 0x23, 0x24, 0x25 },
{ 0x30, 0x31, 0x32, 0x33, 0x34, 0x35 },
{ 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b },
{ 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b },
{ 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b },
{ 0x36, 0x37, 0x38, 0x39, 0x3a, 0x3b },
{ 0x40, 0x41, 0x42, 0x49, 0x4a, 0x4b },
{ 0x46, 0x47, 0x48, 0x43, 0x44, 0x45 }};



enum preonic_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _FN,
  _ADJUST,

};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  FN,
  BACKLIT,
  BACH,
  PASSWD,
  PINCD,
};

enum {
    TD_ESC_CAPS = 0
};

#define ENCDR_CLKWS_QWERTY KC_PGDN
#define ENCDR_NLKWS_QWERTY KC_PGUP

#define ENCDR_CLKWS_LOWER KC_VOLU
#define ENCDR_NLKWS_LOWER KC_VOLD

#define ENCDR_CLKWS_RAISE KC_MNXT
#define ENCDR_NLKWS_RAISE KC_MPRV

#define ENCDR_CLKWS_FN KC_MS_WH_DOWN
#define ENCDR_NLKWS_FN KC_MS_WH_UP

#define ENCDR_CLKWS_ADJUST RGB_MOD
#define ENCDR_NLKWS_ADJUST RGB_RMOD

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ,  |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   .  |  Up  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  FN  | GUI  | Alt  |Lower |Space |Space |Raise |   /  | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,  \
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_COMM, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_DOT , KC_UP,   KC_ENT,  \
  KC_LCTL, TT(_FN), KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_SLSH, KC_LEFT, KC_DOWN, KC_RGHT  \
),
/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | MUTE |      |      |      |      |      |      |      |   -  |   =  |   \  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   `  |      |      |  INS |      |      |      |      |  Up  |   [  |   ]  |  INS |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  | Left | Down |Right |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |      | PGUP |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      | HOME | PGDN |  END |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid( \
  KC_MUTE, _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_BSLS, KC_BSPC, \
  KC_GRV , _______, _______, KC_INS , _______, _______, _______, _______, KC_UP  , KC_LBRC, KC_RBRC, KC_INS,  \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, KC_PGUP, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_END   \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * | PLAY |      |      |      |      |      |      |      |   _  |   +  |   |  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |      |      |  INS |      |      |      |      |  Up  |   {  |   }  |  INS |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  | Left | Down |Right |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |      | PGUP |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      | HOME | PGDN |  END |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid( \
  KC_MPLY, _______, _______, _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_PIPE, KC_BSPC, \
  KC_TILD, _______, _______, KC_INS , _______, _______, _______, _______, KC_UP  , KC_LCBR, KC_RCBR, KC_INS,  \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, KC_PGUP, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_END   \
),

/* FN
 * ,-----------------------------------------------------------------------------------.
 * |  MMB |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |  INS |      |      |      |      | MS U |      |PRTSCR|      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | MS L | MS D | MS R |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      | MS U |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |  LMB |  RMB |      |      | MS L | MS D | MS R |
 * `-----------------------------------------------------------------------------------'
 */
[_FN] = LAYOUT_preonic_grid( \
  KC_BTN3, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, KC_INS , _______, _______, _______, _______, KC_MS_U, _______, KC_PSCR, _______, \
  _______, _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MS_U, _______, \
  _______, _______, _______, _______, _______, KC_BTN1, KC_BTN2, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R  \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |RGBTOG|PASSWD| PINCD| BACH |      |RGBHUD|RGBHUI|   7  |   8  |   9  |   +  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset| DEBUG|      |      |RGBSAD|RGBSAI|   4  |   5  |   6  |   -  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |AudTog| Ck Up|      |      |RGBVAD|RGBVAI|   1  |   2  |   3  |   *  |   /  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |CkTogg| Ck Dn|MusTog|MusMod|Voice-|Voice+|   0  |NUMLCK|   .  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid( \
  RGB_TOG, PASSWD , PINCD,   BACH   , _______, RGB_HUD, RGB_HUI, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, _______, \
  _______, RESET,   DEBUG,   _______, _______, RGB_SAD, RGB_SAI, KC_P4,   KC_P5,   KC_P6,   KC_PMNS, _______, \
  KC_CAPS, AU_TOG,  CK_UP,   _______, _______, RGB_VAD, RGB_VAI, KC_P1,   KC_P2,   KC_P3,   KC_PAST, KC_PSLS, \
  _______,CK_TOGG,  CK_DOWN, MU_TOG,  MU_MOD,  MUV_DE,  MUV_IN,  KC_P0,   KC_NLCK, KC_PDOT, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
)
};

void keyboard_post_init_user() {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case PASSWD:
      if (record -> event.pressed) {}
      else {
          SEND_STRING(PASSWORD);
      }
      break;
    case BACH:
      if (record -> event.pressed) {}
      else {
          PLAY_SONG(bmv846_1);
      }
      break;
    case PINCD:
      if (record -> event.pressed) {}
      else {
          SEND_STRING(PINCODE);
      }
      break;
    }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
//  clockwise = !clockwise;
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (IS_LAYER_ON(_ADJUST)) {
      if (clockwise)
          rgblight_step();
      else 
          rgblight_step_reverse();
    } else if (IS_LAYER_ON(_LOWER)) {
      if (clockwise)
          tap_code(ENCDR_CLKWS_LOWER);
      else 
          tap_code(ENCDR_NLKWS_LOWER);
    } else if (IS_LAYER_ON(_RAISE)) {
      if (clockwise)
          tap_code(ENCDR_CLKWS_RAISE);
      else 
          tap_code(ENCDR_NLKWS_RAISE);
    } else if (IS_LAYER_ON(_FN)) {
      if (clockwise)
          tap_code(ENCDR_CLKWS_FN);
      else 
          tap_code(ENCDR_NLKWS_FN);
    } else {
      if (clockwise)
          tap_code(ENCDR_CLKWS_QWERTY);
      else 
          tap_code(ENCDR_NLKWS_QWERTY);
    }
  }
  return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
    return true;
}


void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}


void led_set_user(uint8_t usb_led)
{
    static uint8_t old_usb_led = 0;

    //wait_ms(10); // gets rid of tick

    //if (!is_playing_notes())
    {
        if ((usb_led & (1<<USB_LED_CAPS_LOCK)) && !(old_usb_led & (1<<USB_LED_CAPS_LOCK)))
        {
                // If CAPS LK LED is turning on...
                PLAY_SONG(tone_caps_on);
        }
        else if (!(usb_led & (1<<USB_LED_CAPS_LOCK)) && (old_usb_led & (1<<USB_LED_CAPS_LOCK)))
        {
                // If CAPS LK LED is turning off...
                PLAY_SONG(tone_caps_off);
        }
        else if ((usb_led & (1<<USB_LED_NUM_LOCK)) && !(old_usb_led & (1<<USB_LED_NUM_LOCK)))
        {
                // If NUM LK LED is turning on...
                PLAY_SONG(tone_numlk_on);
        }
        else if (!(usb_led & (1<<USB_LED_NUM_LOCK)) && (old_usb_led & (1<<USB_LED_NUM_LOCK)))
        {
                // If NUM LED is turning off...
                PLAY_SONG(tone_numlk_off);
        }
        else if ((usb_led & (1<<USB_LED_SCROLL_LOCK)) && !(old_usb_led & (1<<USB_LED_SCROLL_LOCK)))
        {
                // If SCROLL LK LED is turning on...
                PLAY_SONG(tone_scroll_on);
        }
        else if (!(usb_led & (1<<USB_LED_SCROLL_LOCK)) && (old_usb_led & (1<<USB_LED_SCROLL_LOCK)))
        {
                // If SCROLL LED is turning off...
                PLAY_SONG(tone_scroll_off);
        }
    }

    old_usb_led = usb_led;
}


qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_ESC_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS)
};
