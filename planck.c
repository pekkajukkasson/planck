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

#include "planck.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  QWERTY,
  LOWER,
  RAISE,
  BACKLIT,
};

enum custom_keycodes{
	PEKKA = SAFE_RANGE,
	SHIFTED_EXCLAIM,
	SHIFTED_CIT,
	SHIFTED_HASH,
	SHIFTED_AND,
	SHIFTED_QUESTION,
	SHIFTED_PERCENT,
	SHIFTED_AT,
	SHIFTED_FSLASH,
	SHIFTED_BSLASH,
	SHIFTED_LBRACKET,
	SHIFTED_RBRACKET,
	SHIFTED_LPAREN,
	SHIFTED_RPAREN,
	SHIFTED_LBRACE,
	SHIFTED_RBRACE,
	SHIFTED_LTHAN,
	SHIFTED_RTHAN
};





const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* PEKKA
 * ,-----------------------------------------------------------------------------------.
 * |  Q   |   Ö  |   Å  |   U  |   Y  | ESC  | Tab  |   K  |   D  |   M  |   G  |  W   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  Ä   |   I  |   A  |   E  |   O  |   ,  | BkSp |   S  |   N  |   T  |   R  |  L   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  Z   |   X  |   C  |   V  |   J  |   .  | Del  |   P  |   H  |   F  |  Up  |   B  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | Meta |Enter |      | Lower| Raise|Shift | Play | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[PEKKA] = {
  {KC_Q,	KC_SCLN, KC_LBRC, KC_U,    KC_Y,    KC_ESC,  KC_DEL,  KC_K,    KC_D,    KC_M,    KC_G, 	  KC_W},
  {KC_QUOT, KC_I,    KC_A,    KC_E,    KC_O,    KC_TAB,  KC_BSPC, KC_S,    KC_N,    KC_T,    KC_R,    KC_L},
  {KC_MEDIA_PLAY_PAUSE, KC_X, KC_C,    KC_B,    KC_J,    KC_COMM, KC_DOT,  KC_P,    KC_H,    KC_F,    KC_V,   KC_Z},
  {KC_LGUI, KC_LCTL, KC_LALT, KC_ENT,  KC_SPC,  LOWER,  RAISE,  KC_LSFT,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   Ä  |  Ö   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   Å  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Meta | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
  {BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},


/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   !  |   "  |   #  |   &  |   ?  | ESC  | Tab  |   §  |   /  |   \  |   [  |   ]  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   1  |   2  |   3  |   4  |   5  |   ,  | BkSp |   %  |   (  |   )  |   {  |   }  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |   6  |   7  |   8  |   9  |   0  |   .  | Del  |   @  |   <  |   >  |  Up  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | Meta |Enter |      | Lower| Raise|Shift | Play | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {SHIFTED_EXCLAIM, SHIFTED_CIT, SHIFTED_HASH, SHIFTED_AND, SHIFTED_QUESTION, KC_ESC, KC_DEL, KC_GRV, SHIFTED_FSLASH, SHIFTED_BSLASH, SHIFTED_LBRACKET, SHIFTED_RBRACKET},
  {KC_1, KC_2, KC_3, KC_4, KC_5, KC_TRNS, KC_TRNS, SHIFTED_PERCENT, SHIFTED_LPAREN, SHIFTED_RPAREN, SHIFTED_LBRACE, SHIFTED_RBRACE},
  {KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS, KC_TRNS, SHIFTED_AT, SHIFTED_LTHAN, SHIFTED_RTHAN, SHIFTED_LEQTHAN, SHIFTED_REQTHAN},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, _______, _______, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  | Ins  | ESC  | Tab  |  (±) |   _  |   *  |  (≈) |   ¨  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  F5  |  F6  |  F7  |  F8  |CpsLk |   ,  | BkSp |   +  |   -  |   '  |   =  |   ´  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  F9  | F10  | F11  | F12  |PtScr |   .  | Del  |      |   |  |      | PgUp |   ^  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | Meta |Enter |      | Lower| Raise|Shift | Play | Home | PgDn | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC},
  {KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY}
},



/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |Reset |      |      |      |      |      |      |      |      |      |      |QWERTY|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Mus+ | Mus- |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Mus On|Mus Of|MusMod|      |      |             |      |      |      |      |PEKKA |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {_______, RESET,   DEBUG,    RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL },
  {_______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  PEKKA, _______,  _______,  _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}

/* MOLD
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      | ESC  | Tab  |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |   ,  | BkSp |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |   .  | Del  |      |      |      |  Up  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | Meta |Enter |      | Lower| Raise|Shift | Play | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */

};



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case PEKKA:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_PEKKA);
      }
      return false;
      break;
    
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
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        PORTE &= ~(1<<6);
      } else {
        unregister_code(KC_RSFT);
        PORTE |= (1<<6);
      }
      return false;
      break;
	{	//MY MACROS
		case MAC_SHIFTED1:
                SEND_STRING(SS_DOWN(X_LSHIFT) SS_TAP(X_) SS_UP(X_LSHIFT)); // this is our macro!
                return false; 
				break;
	}
  }
  return true;
}
