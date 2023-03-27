#pragma once

#ifdef AUDIO_ENABLE
   #define AUDIO_INIT_DELAY
    
   #ifdef STARTUP_SONG
   #undef STARTUP_SONG
   #endif
   #define STARTUP_SONG SONG(PREONIC_SOUND)
   //#define STARTUP_SONG SONG(NO_SOUND)
   
   #define MY_GOODBYE_SOUND      E__NOTE(_C6), E__NOTE(_G5), E__NOTE(_E5), E__NOTE(_C5), E__NOTE(_C5), E__NOTE(_E5), E__NOTE(_G5), E__NOTE(_C5)
   #ifdef GOODBYE_SONG
   #undef GOODBYE_SONG
   #endif
   #define GOODBYE_SONG SONG(MY_GOODBYE_SOUND)
    

   #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                 SONG(COLEMAK_SOUND), \
                                 SONG(DVORAK_SOUND) \
                              }
   #ifdef TEMPO_DEFAULT
   #undef TEMPO_DEFAULT
   #endif
   #define TEMPO_DEFAULT 240

   #define AUDIO_DAC_SAMPLE_MAX 1023U
   #define AUDIO_CLICKY
   #define AUDIO_CLICKY_FREQ_RANDOMNESS 0.2f

   //#define AUDIO_VOICES
#endif

#define MUSIC_MASK (keycode != KC_NO)

/*
 * MIDI options
 */

/* Prevent use of disabled MIDI features in the keymap */
//#define MIDI_ENABLE_STRICT 1

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2


#define TAPPING_TERM 200
#define TAP_CODE_DELAY 20
#define TAPPING_TOGGLE 2

#define RGBLIGHT_LED_MAP { 4, 0, 1, 2 ,3 ,5 ,6 ,7 ,8 }

#ifdef RGBLIGHT_ANIMATIONS
#undef RGBLIGHT_ANIMATIONS
#endif

#define RGBLIGHT_EFFECT_ALTERNATING
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
