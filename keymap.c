#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#define NO KC_NO
#define UN KC_TRANSPARENT
#define NOL {0,0,0}

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  GREEN,
  RED,
  PINK,
  BLUE,
  SMTD_KEYCODES_BEGIN,

  CTRLA,
  ALTR,
  SHFTS,
  METAT,

  METAN,
  SHFTE,
  ALTI,
  CTRLO,

  HMSUB,
  ENDEQ,

  PARENS,
  CURLYB,
  SQUARB,
  VOLBUP,
  VOLBDN,
  PLAY_MUTE,

  TAPOUT,
  DUAL,
  SOLO,

  SMTD_KEYCODES_END,
};
// NOTE real layer order defined here
#define COLEMAK 0
#define UTIR 1
#define MEDIA 2
#define UTIL 3
#define COLOR 4
#define NUMPAD 5
// #define MOUSE 6

#define GAMESOLO 6
#define GAMEDUAL 7
#define LAYER_COUNT 8

// import after custom_keycodes for 4.0 bug
#include "sm_td.h"

/*/
typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;
tap_dance_action_t *action;
//*/

// OLD, standard TD implementation
#define CTRLZ MT(MOD_LCTL, KC_Z)
#define ALTX  MT(MOD_LALT, KC_X)
#define SHIFC MT(MOD_LSFT, KC_C)
#define METAV MT(MOD_LGUI, KC_V)

#define METAM MT(MOD_LGUI, KC_M)
#define SFTCO MT(MOD_LSFT, KC_COMMA)
#define ALDOT MT(MOD_LALT, KC_DOT)
#define CTLSL MT(MOD_LCTL, KC_SLASH)
#define MEHTAB MEH_T(KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [COLEMAK] = LAYOUT_voyager(
  KC_ESCAPE, KC_1, KC_2, KC_3, KC_4, KC_5,
                                                              KC_6, KC_7, KC_8, KC_9, KC_0, TAPOUT,
  MEHTAB, KC_Q, KC_W, KC_F, KC_P, KC_G,
                                                              KC_J, KC_L, KC_U, KC_Y, KC_SCLN, MEHTAB,
  KC_BSPC, CTRLA, ALTR, SHFTS, METAT, KC_D,
                                                              KC_H, METAN, SHFTE, ALTI, CTRLO, KC_QUOTE,
  KC_RIGHT_ALT, KC_Z, KC_X, KC_C, KC_V, KC_B,
                                                              KC_K, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_BSLS,
                    KC_SPACE, MO(UTIL),
                                                              MO(UTIR), KC_RIGHT_SHIFT
  ),
  [UTIR] = LAYOUT_voyager(
    UN, UN, UN, UN, UN, UN,
                                                              KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, 
    UN, UN, UN, UN, UN, UN,
                                                              KC_TILD, HMSUB, ENDEQ, KC_BSPC, KC_DELETE, KC_F12, 
    UN, UN, UN, UN, UN, UN,
                                                              KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_COLN, MO(MEDIA),
    UN, UN, UN, UN, UN, UN,
                                                              TO(NUMPAD), KC_ENTER, PARENS, CURLYB, SQUARB, TG(GAMESOLO),
                    UN, UN,
                                                              UN, UN
  ),
  #define NEXT KC_MEDIA_NEXT_TRACK
  #define PREV KC_MEDIA_PREV_TRACK
  [MEDIA] = LAYOUT_voyager(
    UN, UN, UN, UN, UN, UN,
                                                              UN, UN, UN, UN, UN, UN, 
    UN, UN, UN, UN, UN, UN,
                                                              UN, UN, UN, UN, UN, UN, 
    UN, UN, UN, UN, UN, UN,
                                                              PREV, VOLBDN, VOLBUP, NEXT, PLAY_MUTE, UN, 
    UN, UN, UN, UN, UN, UN,
                                                              UN, UN, UN, UN, UN, UN, 
                    UN, UN,
                                                              UN, UN
  ),
  [UTIL] = LAYOUT_voyager(
    UN, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,
                                                              UN, UN, UN, UN, UN, NO, 
    UN, KC_ESCAPE, KC_GRAVE, KC_PAGE_UP, KC_PGDN, UN,
                                                              UN, UN, UN, UN, UN, UN, 
    MO(COLOR), KC_LEFT_CTRL, KC_LEFT, KC_UP, KC_DOWN, KC_RIGHT,
                                                              UN, UN, UN, UN, UN, UN, 
    UN, KC_TAB, KC_PSCR, KC_MS_WH_UP, KC_MS_WH_DOWN, TOGGLE_LAYER_COLOR,
                                                              UN, UN, UN, UN, UN, UN, 
                    UN, UN,
                                                              UN, UN
  ),
  [COLOR] = LAYOUT_voyager(
    UN, UN, UN, UN, UN, UN,
                                                              UN, UN, UN, UN, UN, UN, 
    UN, UN, GREEN, RED, PINK, BLUE,
                                                              UN, UN, UN, UN, UN, UN, 
    UN, UN, RGB_SPD, TOGGLE_LAYER_COLOR,RGB_TOG, RGB_SPI,
                                                              UN, UN, UN, UN, UN, UN, 
    UN, UN, UN, UN, UN, UN,
                                                              UN, UN, UN, UN, UN, UN, 
                    RGB_MODE_FORWARD,UN,
                                                              UN, UN
  ),
  [NUMPAD] = LAYOUT_voyager(
    UN, UN, UN, UN, UN, UN,
                                                              UN, OSM(MOD_LSFT), KC_KP_SLASH, KC_KP_ASTERISK, KC_KP_MINUS, NO, 
    UN, UN, UN, UN, UN, UN,
                                                              UN, KC_7, KC_8, KC_9, KC_KP_PLUS, UN, 
    UN, UN, UN, UN, UN, UN,
                                                              KC_EQUAL, KC_4, KC_5, KC_6, KC_ENTER, UN, 
    UN, UN, UN, UN, UN, UN,
                                                              KC_EQUAL, KC_1, KC_2, KC_3, KC_DOT, UN, 
                    UN, UN,
                                                              TO(COLEMAK), KC_0
  ),
  [GAMESOLO] = LAYOUT_voyager(
    KC_LEFT_ALT, KC_1, KC_2, KC_3, KC_4, KC_5,
                                                              KC_6, KC_7, KC_8, KC_9, KC_0, DUAL, 
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,
                                                              KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, 
    KC_LEFT_SHIFT, KC_A, KC_S, KC_D, KC_F, KC_G,
                                                              KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOTE, 
    KC_LEFT_CTRL, KC_Z, KC_X, KC_C, KC_V, KC_B,
                                                              KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, UN, 
                    KC_SPACE, KC_ESCAPE,
                                                              UN, UN
  ),
  [GAMEDUAL] = LAYOUT_voyager(
    SOLO, KC_1, KC_2, KC_3, KC_4, KC_5,
                                                              KC_6, KC_7, KC_8, KC_9, KC_0, SOLO, 
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,
                                                              KC_U, KC_I, KC_O, KC_UP, KC_P, KC_ENTER, 
    KC_LEFT_SHIFT, KC_A, KC_S, KC_D, KC_F, KC_G,
                                                              KC_H, KC_J, KC_LEFT, KC_DOWN, KC_RIGHT, KC_RIGHT_SHIFT, 
    KC_LEFT_CTRL, KC_Z, KC_X, KC_C, KC_V, KC_B,
                                                              KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_RIGHT_CTRL, 
                    KC_SPACE, KC_ESCAPE,
                                                              KC_ESCAPE, KC_TAB
  ),
};



extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [COLEMAK] = {
    {81,213,255}, NOL, NOL, NOL, NOL, NOL,
    NOL, NOL, NOL, NOL, NOL, NOL,
    {170,49,150}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, NOL,
    {170,49,150}, NOL, NOL, NOL, NOL, NOL,
                        {170,49,150}, {12,255,255},

            NOL, NOL, NOL, NOL, NOL, {201,255,255},
            NOL, NOL, NOL, NOL, {170,49,150}, NOL,
            NOL, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {170,49,150},
            NOL, NOL, NOL, NOL, NOL, {170,49,150},
            {12,255,255}, {170,49,150}
},

    [UTIR] = {
    NOL, NOL, NOL, NOL, NOL, NOL,
    NOL, NOL, NOL, NOL, NOL, NOL,
    NOL, NOL, NOL, NOL, NOL, NOL,
    NOL, NOL, NOL, NOL, NOL, NOL,
                        NOL, NOL,
            {170,49,150}, {170,49,150}, {170,49,150}, {170,49,150}, {170,49,150}, {170,49,150},
            NOL, {169,255,255}, {169,255,255}, NOL, NOL, {170,49,150},
            NOL, NOL, NOL, NOL, NOL, NOL,
            {12,255,255}, NOL, {169,255,255}, {169,255,255}, {169,255,255}, {12,255,255},
            {169,255,255}, NOL
},

    [MEDIA] = {
    NOL, NOL, NOL, NOL, NOL, NOL,
    NOL, NOL, NOL, NOL, NOL, NOL,
    NOL, NOL, NOL, NOL, NOL, NOL,
    NOL, NOL, NOL, NOL, NOL, NOL,
                        NOL, NOL,
            NOL, NOL, NOL, NOL, NOL, NOL,
            NOL, NOL, NOL, NOL, NOL, NOL,
            {100,255,255}, {100,255,255}, {100,255,255}, {100,255,255}, {169,255,255}, NOL,
            NOL, NOL, NOL, NOL, NOL, NOL,
            NOL, NOL
},

    [UTIL] = {
    NOL, {170,49,150}, {170,49,150}, {170,49,150}, {170,49,150}, {170,49,150},
    NOL, NOL, NOL, NOL, NOL, NOL,
    NOL, NOL, NOL, NOL, NOL, NOL,
    NOL, NOL, NOL, NOL, NOL, NOL,
                        NOL, {169,255,255},
            NOL, NOL, NOL, NOL, NOL, NOL,
            NOL, NOL, NOL, NOL, NOL, NOL,
            NOL, NOL, NOL, NOL, NOL, NOL,
            NOL, NOL, NOL, NOL, NOL, NOL,
            NOL, NOL
},

    [COLOR] = {
    NOL, NOL, NOL, NOL, NOL, NOL,
    NOL, NOL, {81,213,255}, {255,255,255}, {204,189,255}, {169,255,255},
    NOL, NOL, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255},
    NOL, NOL, NOL, NOL, NOL, NOL,
                        {169,255,255}, NOL,
            NOL, NOL, NOL, NOL, NOL, NOL,
            NOL, NOL, NOL, NOL, NOL, NOL,
            NOL, NOL, NOL, NOL, NOL, NOL,
            NOL, NOL, NOL, NOL, NOL, NOL,
            NOL, NOL
},

    [NUMPAD] = {
    NOL, NOL, NOL, NOL, NOL, NOL,
    NOL, NOL, NOL, NOL, NOL, NOL,
    NOL, NOL, NOL, NOL, NOL, NOL,
    NOL, NOL, NOL, NOL, NOL, NOL,
                        NOL, NOL,
            NOL, {100,255,255}, {171,177,242}, {171,177,242}, {171,177,242}, NOL,
            NOL, NOL, NOL, NOL, {171,177,242}, NOL,
            {171,177,242}, NOL, NOL, NOL, {100,255,255}, NOL,
            {171,177,242}, NOL, NOL, NOL, {171,177,242}, NOL,
            {12,255,255}, NOL
},

    [GAMESOLO] = {
    {169,255,255}, NOL, NOL, NOL, NOL, NOL,
    NOL, NOL, {81,213,255}, NOL, NOL, NOL,
    {169,255,255}, {81,213,255}, {81,213,255}, {81,213,255}, NOL, NOL,
    {169,255,255}, NOL, NOL, NOL, NOL, NOL,
                        NOL, NOL,
            NOL, NOL, NOL, NOL, NOL, {12,255,255},
            NOL, NOL, NOL, NOL, NOL, NOL,
            NOL, NOL, NOL, NOL, NOL, NOL,
            NOL, NOL, NOL, NOL, NOL, {12,255,255},
            NOL, NOL
},

    [GAMEDUAL] = {
    {12,255,255}, NOL, NOL, NOL, NOL, NOL,
    NOL, NOL, {100,255,255}, NOL, NOL, NOL,
    {169,255,255}, {100,255,255}, {100,255,255}, {100,255,255}, NOL, NOL,
    {169,255,255}, NOL, NOL, NOL, NOL, NOL,
                        NOL, NOL,
            NOL, NOL, NOL, NOL, NOL, {12,255,255},
            NOL, NOL, NOL, {100,255,255}, NOL, NOL,
            NOL, NOL, {100,255,255}, {100,255,255}, {100,255,255}, {169,255,255},
            NOL, NOL, NOL, NOL, NOL, {169,255,255},
            NOL, NOL
}

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (keyboard_config.disable_layer_led) { return false; }
  int layer = biton32(layer_state);
  if (layer < LAYER_COUNT)
    set_layer_color(layer);
  else if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
  return true;
}

void on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count) {
    switch (keycode) {
        // (now removed) MTE variant sends the modifier immediately (friendly to mouse usage)
        // non-eager variants for safety w/ software (mainly alt and meta)
        SMTD_MT(CTRLA, KC_A, KC_LEFT_CTRL)
        SMTD_MT(ALTR,  KC_R, KC_LEFT_ALT)
        SMTD_MT(SHFTS, KC_S, KC_LEFT_SHIFT)
        SMTD_MT(METAT, KC_T, KC_LEFT_GUI)

        SMTD_MT(METAN, KC_N, KC_LEFT_GUI)
        SMTD_MT(SHFTE, KC_E, KC_LEFT_SHIFT)
        SMTD_MT(ALTI,  KC_I, KC_LEFT_ALT)
        SMTD_MT(CTRLO, KC_O, KC_LEFT_CTRL)

        SMTD_TD(HMSUB, KC_MINUS, KC_HOME)
        SMTD_TD(ENDEQ, KC_EQUAL, KC_END)
        SMTD_TD(PARENS, KC_LPRN, KC_RPRN)
        SMTD_TD(CURLYB, KC_LCBR, KC_RCBR)
        SMTD_TD(SQUARB, KC_LBRC, KC_RBRC)
        SMTD_TD(VOLBDN, KC_AUDIO_VOL_DOWN, KC_BRIGHTNESS_DOWN)
        SMTD_TD(VOLBUP, KC_AUDIO_VOL_UP, KC_BRIGHTNESS_UP)
        SMTD_TD(PLAY_MUTE, KC_MEDIA_PLAY_PAUSE, KC_AUDIO_MUTE)

        SMTD_TK(TAPOUT, LGUI(KC_L))

        SMTD_TTO(DUAL, GAMEDUAL)
        SMTD_TTO(SOLO, GAMESOLO)

    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_smtd(keycode, record)) {
      return false;
  }
  /*/ TODO evaluate if this check can precede SMTD check
  if (keycode > SMTD_KEYCODES_END) {
    action = &tap_dance_actions[TD_INDEX(keycode)];
    if (!record->event.pressed && action->state.count && !action->state.finished) {
        tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
        tap_code16(tap_hold->tap);
    }
    return true;
  }
  //*/

  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case GREEN:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(81,213,255);
      }
      return false;
    case RED:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(255,255,255);
      }
      return false;
    case PINK:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(204,189,255);
      }
      return false;
    case BLUE:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(169,255,255);
      }
      return false;
  }
  return true;
}
/*/
void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
// TODO look into selective permissive hold
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        } else {
            register_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}

void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[4];

uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        // per-key rollover handle hint?
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


#define DANCE_LAYER_RESET(N) wait_ms(10); dance_state[N].step = 0;


void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case DOUBLE_TAP: register_code16(LGUI(KC_L)); break;
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case DOUBLE_TAP: unregister_code16(LGUI(KC_L)); break;
    }
    dance_state[0].step = 0;
}
void dance_9_finished(tap_dance_state_t *state, void *user_data);
void dance_9_reset(tap_dance_state_t *state, void *user_data);

void dance_9_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case DOUBLE_TAP: layer_move(GAMEDUAL); break;
    }
}

void dance_9_reset(tap_dance_state_t *state, void *user_data) {
    DANCE_LAYER_RESET(1)
}
void dance_10_finished(tap_dance_state_t *state, void *user_data);
void dance_10_reset(tap_dance_state_t *state, void *user_data);

void dance_10_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case DOUBLE_TAP: layer_move(GAMESOLO); break;
    }
}

void dance_10_reset(tap_dance_state_t *state, void *user_data) {
    DANCE_LAYER_RESET(2)
}
void dance_11_finished(tap_dance_state_t *state, void *user_data);
void dance_11_reset(tap_dance_state_t *state, void *user_data);

void dance_11_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case DOUBLE_TAP: layer_move(GAMESOLO); break;
    }
}

void dance_11_reset(tap_dance_state_t *state, void *user_data) {
    DANCE_LAYER_RESET(3)
}

tap_dance_action_t tap_dance_actions[] = {
        [MHOME] = ACTION_TAP_DANCE_TAP_HOLD(KC_MINUS, KC_HOME),
        [EQEND] = ACTION_TAP_DANCE_TAP_HOLD(KC_EQUAL, KC_END),
        [PARENS] = ACTION_TAP_DANCE_TAP_HOLD(KC_LPRN, KC_RPRN),
        [CURLYB] = ACTION_TAP_DANCE_TAP_HOLD(KC_LCBR, KC_RCBR),
        [SQUARB] = ACTION_TAP_DANCE_TAP_HOLD(KC_LBRC, KC_RBRC),
        [V_B_DN] = ACTION_TAP_DANCE_TAP_HOLD(KC_AUDIO_VOL_DOWN, KC_BRIGHTNESS_DOWN),
        [V_B_UP] = ACTION_TAP_DANCE_TAP_HOLD(KC_AUDIO_VOL_UP, KC_BRIGHTNESS_UP),
        [PLAY_MUTE] = ACTION_TAP_DANCE_TAP_HOLD(KC_MEDIA_PLAY_PAUSE, KC_AUDIO_MUTE),
        [LOCK_BTN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_0_finished, dance_0_reset),
        [TO_DUAL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_9_finished, dance_9_reset),
        [TO_SOLO] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_11_finished, dance_11_reset),
};
//*/
