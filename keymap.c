/* Copyright 2015-2017 Jack Humbert
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

enum preonic_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE
};

float terminalbeep[][2] = SONG(TERMINAL_SOUND);
float raise_sound[][2] = SONG(TERMINAL_SOUND);
float lower_sounds[][2] = SONG(UNICODE_LINUX);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
  * ,-----------------------------------------------------------------------------------.
  * | ~  ` |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  | ;  : | "  ' |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  | ,  < | .  > |   /  |Enter |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | RGB  | Ctrl |  OS  | Alt  | Lower|    Space    | Raise| Left | Down |  Up  |Right |
  * `-----------------------------------------------------------------------------------'
  */
  [_QWERTY] = LAYOUT_preonic_1x2uC (     
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,  KC_5,   KC_6,  KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, 
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,  KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, 
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,  KC_G,   KC_H,  KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, 
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   KC_N,  KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT, 
    RGB_TOG, KC_LCTL, KC_LGUI, KC_LALT, LOWER, KC_SPC, 		    RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
  ),

	/* LOWER
	* ,-----------------------------------------------------------------------------------.
	* |   ~  |  !   |  @   |  #   |  $   |  %   |  ^   |  &   |  *   |  -   | +  = |  Del |
	* |------+------+------+------+------+------+------+------+------+------+------+------|
	* |   ~  |  f1  |  f2  |  f3  |  f4  |  f5  |  f6  |  f7  |  f8  |  {   |  }   | Bksp |
	* |------+------+------+------+------+------+------+------+------+------+------+------|
	* |      |  f9  |  f10 |  f11 |  f12 |      |      |      |      |  [   |  ]   |  |   |
	* |------+------+------+------+------+------+------+------+------+------+------+------|
	* |      |      |      |      |      |      |      |      |      |  _   |  \   |      |
	* |------+------+------+------+------+------+------+------+------+------+------+------|
	* |      |      |      |      |      |             |      | Left | Down |  Up  | Right|
	* `-----------------------------------------------------------------------------------'
	*/
	[_LOWER] = LAYOUT_preonic_1x2uC (
		KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_EQL,  KC_TRNS, 
		KC_TILD, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_LCBR, KC_RCBR, KC_TRNS, 
		_______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_PIPE, 
		_______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UNDS, KC_BSLS, KC_TRNS, 
		_______, _______, _______, _______, _______, _______, 		     _______, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
	),

	/* RAISE
	* ,-----------------------------------------------------------------------------------.
	* |      | RGB1 | RGB2 | RGB3 | RGB4 | RGB5 | RGB6 | RGB7 | RGB8 | RGB9 |      |      |
	* |------+------+------+------+------+------+------+------+------+------+------+------|
	* |      | RGB  | Hue+ | Sat+ | BRT+ |      |      |      |      |      | PSCR |      |
	* |------+------+------+------+------+------+------+------+------+------+------+------|
	* |      |      | Hue- | Sat- | BRT- |      |      |      |      |      |      |      |
	* |------+------+------+------+------+------+------+------+------+------+------+------|
	* |      |      |      |      |      |      |      |      |      |      |      |      |
	* |------+------+------+------+------+------+------+------+------+------+------+------|
	* |      |      |      |      |  LWR | Pause/Play  |  RS  | Next | Vol+ | Vol- | Prev |
	* `-----------------------------------------------------------------------------------'
	*/
	[_RAISE] = LAYOUT_preonic_1x2uC (
		_______, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T, _______,    _______, 
		_______, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI,  _______,  _______, _______, _______, _______, KC_PSCREEN, _______, 
		_______, _______, RGB_HUD, RGB_SAD, RGB_VAD,  _______,  _______, _______, _______, _______, _______,    _______, 
		_______, _______, _______, _______, _______,  _______,  _______, _______, _______, _______, _______,    _______, 
		_______, KC_LCTL, KC_LGUI, KC_LALT, _______,  KC_MSTP,  		      _______, KC_MPRV, KC_VOLD, KC_VOLU,    KC_MNXT
	),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset| Debug|      |      |      |      |TermOf|TermOn|      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |Aud cy|Aud on|AudOff|AGnorm|AGswap|      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_F12,
  _______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF, _______, _______, KC_DEL,
  _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______,  _______, _______, _______,
  _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______,  _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(lower_sound);
        #endif
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
        #ifdef AUDIO_ENABLE
          PLAY_SONG(raise_sound);
        #endif
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
  }
  return true;
};

bool      muse_mode       = false;
uint8_t   last_muse_note  = 0;
uint16_t  muse_counter    = 0;
uint8_t   muse_offset     = 70;
uint16_t  muse_tempo      = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
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
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
    return true;
}

void dip_switch_update_user(uint8_t index, bool active) {
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
