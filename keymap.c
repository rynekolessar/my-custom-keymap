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

enum preonic_layers {
  _MAIN,
  _RAISE,
  _LOWER
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	/* MAIN
	* ,-----------------------------------------------------------------------------------.
	* | ~  ` |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
	* |------+------+------+------+------+------+------+------+------+------+------+------|
	* | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
	* |------+------+------+------+------+-------------+------+------+------+------+------|
	* | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  | ;  : | "  ' |
	* |------+------+------+------+------+------|------+------+------+------+------+------|
	* | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  | ,  < | .  > |   /  |Enter |
	* |------+------+------+------+------+------+------+------+------+------+------+------|
	* | Find | Ctrl |  OS  | Alt  | LWR  |    Space    |  RS  | Left | Down |  Up  |Right |
	* `-----------------------------------------------------------------------------------'
	*/
	[_MAIN] = LAYOUT_preonic_1x2uC (     
		KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,  KC_5,   KC_6,  KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, 
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,  KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, 
		KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,  KC_G,   KC_H,  KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, 
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   KC_N,  KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT, 
		KC_MYCM, KC_LCTL, KC_LGUI, KC_LALT, MO(1), KC_SPC, 		  MO(2),   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
		),
	
	/* RAISE
	* ,-----------------------------------------------------------------------------------.
	* |      | RGB1 | RGB2 | RGB3 | RGB4 | RGB5 | RGB6 | RGB7 | RGB8 | RGB9 |      |      |
	* |------+------+------+------+------+------+------+------+------+------+------+------|
	* |      | RGB  | Hue+ | Sat+ | BRT+ |      |      |      |      |      |      |      |
	* |------+------+------+------+------+------+------+------+------+------+------+------|
	* |      |      | Hue- | Sat- | BRT- |      |      |      |      |      |      |      |
	* |------+------+------+------+------+------+------+------+------+------+------+------|
	* |      |      |      |      |      |      |      |      |      |      |      |      |
	* |------+------+------+------+------+------+------+------+------+------+------+------|
	* |      |      |      |      |  LWR | Pause/Play  |  RS  | Next | Vol+ | Vol- | Prev |
	* `-----------------------------------------------------------------------------------'
	*/
	[_LOWER] = LAYOUT_preonic_1x2uC (
		KC_TRNS, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T, KC_NO,   KC_TRNS, 
		KC_TRNS, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI,  KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS, 
		KC_TRNS, KC_NO,   RGB_HUD, RGB_SAD, RGB_VAD,  KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS, 
		KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS, 
		KC_TRNS, KC_LCTL, KC_LGUI, KC_LALT, KC_TRNS,  KC_MSTP,  		 KC_TRNS, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT
	),
	
	/* LOWER
	* ,-----------------------------------------------------------------------------------.
	* |      |  f1  |  f2  |  f3  |  f4  |  f5  |  f6  |  f7  | - _  | +  = | +  = |      |
	* |------+------+------+------+------+------+------+------+------+------+------+------|
	* |      |      |      |      |      |      |      |      |  {   |  }   |      |      |
	* |------+------+------+------+------+------+------+------+------+------+------+------|
	* |      |      |      |      |      |      |      |      |  [   |  ]   |      |      |
	* |------+------+------+------+------+------+------+------+------+------+------+------|
	* |      |      |      |      |      |      |      |      | ,  < | .  > | |  \ |      |
	* |------+------+------+------+------+------+------+------+------+------+------+------|
	* |      |      |      |      |  LWR |    Space    |  RS  |      |      |      |      |
	* `-----------------------------------------------------------------------------------'
	*/
	[_RAISE] = LAYOUT_preonic_1x2uC (
		KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_MINS, KC_EQL,  KC_TRNS, 
		KC_TRNS, KC_F9,   KC_F10,  KC_F12,  KC_F11,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LCBR, KC_RCBR, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MINS, KC_BSLS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 		   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
	)
};
