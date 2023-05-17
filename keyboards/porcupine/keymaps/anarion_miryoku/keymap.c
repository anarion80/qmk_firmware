/*

╭━╮╱╱╱╱╱╱╱╱╱╭╮
┃╋┣━┳┳┳━┳┳┳━╋╋━┳┳━╮
┃╭┫╋┃╭┫━┫┃┃╋┃┃┃┃┃┻┫
╰╯╰━┻╯╰━┻━┫╭┻┻┻━┻━╯
╱╱╱╱╱╱╱╱╱╱╰╯

*/

#include QMK_KEYBOARD_H

#if !defined(MIRYOKU_LAYER_LIST)

#define MIRYOKU_LAYER_LIST      \
    MIRYOKU_X(BASE, "Base")     \
    MIRYOKU_X(EXTRA, "Extra")   \
    MIRYOKU_X(TAP, "Tap")       \
    MIRYOKU_X(BUTTON, "Button") \
    MIRYOKU_X(NAV, "Nav")       \
    MIRYOKU_X(MOUSE, "Mouse")   \
    MIRYOKU_X(MEDIA, "Media")   \
    MIRYOKU_X(NUM, "Num")       \
    MIRYOKU_X(SYM, "Sym")       \
    MIRYOKU_X(FUN, "Fun")

#endif

#define U_NP KC_NO // key is not present
#define U_NA KC_NO // present but not available for use
#define U_NU KC_NO // available but not used

#define MIRYOKU_CLIPBOARD_WIN

#if defined(MIRYOKU_CLIPBOARD_FUN)
#    define U_RDO KC_AGIN
#    define U_PST KC_PSTE
#    define U_CPY KC_COPY
#    define U_CUT KC_CUT
#    define U_UND KC_UNDO
#elif defined(MIRYOKU_CLIPBOARD_MAC)
#    define U_RDO SCMD(KC_Z)
#    define U_PST LCMD(KC_V)
#    define U_CPY LCMD(KC_C)
#    define U_CUT LCMD(KC_X)
#    define U_UND LCMD(KC_Z)
#elif defined(MIRYOKU_CLIPBOARD_WIN)
#    define U_RDO C(KC_Y)
#    define U_PST C(KC_V)
#    define U_CPY C(KC_C)
#    define U_CUT C(KC_X)
#    define U_UND C(KC_Z)
#else
#    define U_RDO KC_AGIN
#    define U_PST S(KC_INS)
#    define U_CPY C(KC_INS)
#    define U_CUT S(KC_DEL)
#    define U_UND KC_UNDO
#endif

enum porcupine_layers {
#define MIRYOKU_X(LAYER, STRING) U_##LAYER,
    MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
};

enum {
    U_TD_BOOT,
#define MIRYOKU_X(LAYER, STRING) U_TD_U_##LAYER,
    MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
};

void u_td_fn_boot(tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        reset_keyboard();
    }
}

#define MIRYOKU_X(LAYER, STRING)                                        \
    void u_td_fn_U_##LAYER(tap_dance_state_t *state, void *user_data) { \
        if (state->count == 2) {                                        \
            default_layer_set((layer_state_t)1 << U_##LAYER);           \
        }                                                               \
    }
MIRYOKU_LAYER_LIST
#undef MIRYOKU_X

enum tap_dance_codes {
    DANCE_TAB,
    DANCE_ESC,
};

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ K E Y M A P S                                                                                                                              │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
    ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

    ┌───────────────────────────────────────────────────────────┐
    │ q w e r t y  -  b a s e  l a y e r                        │
    └───────────────────────────────────────────────────────────┘
    ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
    │   ESC   │    Q    │    W    │    E    │    R    │    T    │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │    Y    │    U    │    I    │    O    │    P    │ BSPACE  │
    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
    │   TAB   │    A    │    S    │    D    │    F    │    G    ├─╯                ╰─┤    H    │    J    │    K    │    L    │    '    │ ENTER   │
    └─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┘
              │    Z    │    X    │    C    │    V    │    B    │                    │    N    │    M    │    ,    │    .    │    /    │
              └─────────┴─────────┼─────────┼─────────┼─────────┼─────────┐┌─────────┼─────────┼─────────┼─────────┼─────────┴─────────┘
                                  │ SPACE   │  SPACE  │ TAB     │ DELETE  ││ DELETE  │  RALT   │  BSPACE │  ENTER  │
                                  └─────────┴─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┴─────────┘                            */

    [U_BASE] = LAYOUT_6x3_4(
            //╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
                   TD(DANCE_ESC),    KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,      KC_O,    KC_P,    KC_BSPC,
                TD(DANCE_TAB), LGUI_T(KC_A),LALT_T(KC_S),LCTL_T(KC_D),LSFT_T(KC_F),  KC_G,     KC_H,   LSFT_T(KC_J),LCTL_T(KC_K),LALT_T(KC_L),LGUI_T(KC_QUOT),  KC_ENTER,
                        LT(U_BUTTON,KC_Z),   ALGR_T(KC_X),KC_C,     KC_V,     KC_B,     KC_N,     KC_M,    KC_COMM,  ALGR_T(KC_DOT), KC_SLSH,
                    LT(U_MEDIA,KC_SPC),LT(U_NAV,KC_SPC),  LT(U_NUM,KC_TAB), KC_DEL,   KC_DEL, LT(U_SYM,KC_ALGR),  LT(U_MOUSE,KC_BSPC), LT(U_FUN,KC_ENT)
    ),
/*
    ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

    ┌───────────────────────────────────────────────────────────┐
    │ n a v i g a t i o n                                       │
    └───────────────────────────────────────────────────────────┘
    ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
    │   ESC   │   BOOT  │   TAP   │  EXTRA  │   BASE  │         │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │ BACK    │   HOME  │    ↑    │   PGUP  │  COPY   │ BSPACE  │
    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
    │   TAB   │   LGUI  │  LALT   │ LCTRL   │ LSHIFT  │         ├─╯                ╰─┤ CAPSWORD│    ←    │    ↓    │    →    │  PASTE  │ ENTER   │
    └─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┘
              │         │  RLAT   │  NUM    │  NAV    │         │                    │ INSERT  │   END   │   INS   │   PGDN  │  CUT    │
              └─────────┴─────────┼─────────┼─────────┼─────────┼─────────┐┌─────────┼─────────┼─────────┼─────────┼─────────┴─────────┘
                                  │         │         │         │         ││ DELETE  │ RALT    │ BSPACE  │ ENTER   │
                                  └─────────┴─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┴─────────┘                            */

    [U_NAV] = LAYOUT_6x3_4(
            //╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
                TD(DANCE_ESC), TD(U_TD_BOOT), TD(U_TD_U_TAP), TD(U_TD_U_EXTRA), TD(U_TD_U_BASE), U_NA,   KC_WBAK,    KC_HOME,  KC_UP,    KC_PGUP, U_CPY, KC_BSPC,
                  TD(DANCE_TAB),   KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,    U_NA,    CW_TOGG,  KC_LEFT,  KC_DOWN,   KC_RGHT,  U_PST,  KC_ENTER,
                            U_NA,   KC_ALGR,  TD(U_TD_U_NUM), TD(U_TD_U_NAV), U_NA,    KC_INS,   KC_END,  KC_INS,   KC_PGDN,  U_CUT,
                                     U_NP,     U_NP,      U_NA,    U_NA,      KC_DEL,  KC_ALGR, KC_BSPC,  KC_ENT
),

/*
    ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

    ┌───────────────────────────────────────────────────────────┐
    │ m o u s e                                                 │
    └───────────────────────────────────────────────────────────┘
    ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
    │   ESC   │   REDO  │    ←M   │    M↑   │    W→   │  UNDO   │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │         │  BOOT   │   TAP   │  EXTRA  │  BASE   │  BSPACE │
    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
    │   TAB   │         │    ←M   │    M↓   │    M→   │         ├─╯                ╰─┤         │ LSHIFT  │  LCTRL  │  LALT   │  LGUI   │  ENTER  │
    └─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┘
              │         │         │    W↓   │    W↑   │         │                    │         │  MOUSE  │  SYMBOL │  RALT   │         │
              └─────────┴─────────┼─────────┼─────────┼─────────┼─────────┐┌─────────┼─────────┼─────────┼─────────┼─────────┴─────────┘
                                  │  MOUSE3 │  MOUSE1 │  MOUSE2 │         ││         │         │         │         │
                                  └─────────┴─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┴─────────┘                            */

    [U_MOUSE] = LAYOUT_6x3_4(
            //╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
                TD(DANCE_ESC), U_RDO,  KC_WH_L,  KC_MS_U,  KC_WH_R,  U_UND,  U_NA, TD(U_TD_BOOT), TD(U_TD_U_TAP), TD(U_TD_U_EXTRA), TD(U_TD_U_BASE),  KC_BSPC,
                    TD(DANCE_TAB),    U_NU,   KC_MS_L,  KC_MS_D,  KC_MS_R,  U_NU,       U_NA,    KC_LSFT,  KC_LCTL,  KC_LALT,  KC_LGUI,  KC_ENTER,
                                      U_NU,    U_NU,    KC_WH_D,  KC_WH_U,  U_NU,       U_NA, TD(U_TD_U_MOUSE), TD(U_TD_U_SYM), KC_ALGR,  U_NA,
                                             KC_BTN3,   KC_BTN1,  KC_BTN2,  U_NP,       U_NA,     U_NA,     U_NA,    U_NA
    ),

    /*
    ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

    ┌───────────────────────────────────────────────────────────┐
    │ m e d i a                                                 │
    └───────────────────────────────────────────────────────────┘
    ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
    │   ESC   │   BOOT  │   TAP   │  EXTRA  │   BASE  │         │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │  RGBTOG │ RGBMOD  │ RGBHUI  │  RGBSAI │  RGBVAI │  BSPACE │
    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
    │   TAB   │   LGUI  │  LALT   │ LCTRL   │ LSHIFT  │         ├─╯                ╰─┤         │  PREV   │  VOL↓   │  VOL↑   │  NEXT   │  ENTER  │
    └─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┘
              │         │  RLAT   │  NUM    │  MEDIA  │         │                    │ OU_AUTO │         │         │         │         │
              └─────────┴─────────┼─────────┼─────────┼─────────┼─────────┐┌─────────┼─────────┼─────────┼─────────┼─────────┴─────────┘
                                  │         │         │         │         ││         │  STOP   │  PLAY   │  MUTE   │
                                  └─────────┴─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┴─────────┘                            */

    [U_MEDIA] = LAYOUT_6x3_4(
            //╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
                TD(DANCE_ESC),TD(U_TD_BOOT), TD(U_TD_U_TAP), TD(U_TD_U_EXTRA),TD(U_TD_U_BASE), U_NA,    RGB_TOG,  RGB_MOD,  RGB_HUI,  RGB_SAI,  RGB_VAI,  KC_BSPC,
                    TD(DANCE_TAB),  KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,    U_NA,     U_NU,    KC_MPRV,  KC_VOLD,  KC_VOLU,  KC_MNXT, KC_ENTER,
                           U_NA,    KC_ALGR,TD(U_TD_U_FUN),TD(U_TD_U_MEDIA),  U_NA,    OU_AUTO,   U_NU,     U_NU,      U_NU,    U_NU,
                                            U_NA,   U_NA,  U_NA,   U_NA,                U_NU,    KC_MSTP,  KC_MPLY,  KC_MUTE
    ),

        /*
    ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

    ┌───────────────────────────────────────────────────────────┐
    │ s y m b o l s                                             │
    └───────────────────────────────────────────────────────────┘
    ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
    │  ESC    │    {    │    &    │    *    │    (    │    }    │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │         │   BASE  │  EXTRA  │   TAP   │  BOOT   │  BSPACE │
    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
    │  TAB    │    ;    │    $    │    %    │    ^    │    +    ├─╯                ╰─┤         │  LSHIFT │  LCTRL  │  LALT   │  LGUI   │  ENTER  │
    └─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┘
              │    ~    │    !    │    @    │    #    │    |    │                    │         │  SYMBOL │  MOUSE  │  RALT   │         │
              └─────────┴─────────┼─────────┼─────────┼─────────┼─────────┐┌─────────┼─────────┼─────────┼─────────┼─────────┴─────────┘
                                  │    (    │    )    │    _    │         ││         │         │         │         │
                                  └─────────┴─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┴─────────┘                            */

    [U_SYM] = LAYOUT_6x3_4(
            //╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
                    TD(DANCE_ESC),   KC_LCBR,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RCBR,   U_NA, TD(U_TD_U_BASE), TD(U_TD_U_EXTRA), TD(U_TD_U_TAP), TD(U_TD_BOOT), KC_BSPC,
                    TD(DANCE_TAB),  KC_COLN,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_PLUS,    U_NA,    KC_LSFT,  KC_LCTL,  KC_LALT,  KC_LGUI, KC_ENTER,
                                    KC_TILD,  KC_EXLM,   KC_AT,   KC_HASH,  KC_PIPE,    U_NA,  TD(U_TD_U_SYM), TD(U_TD_U_MOUSE), KC_ALGR, U_NA,
                                              KC_LPRN,  KC_RPRN,   KC_UNDS,   U_NA,     U_NU,      U_NA,    U_NA,      U_NA
    ),

        /*
    ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

    ┌───────────────────────────────────────────────────────────┐
    │ n u m b e r s                                             │
    └───────────────────────────────────────────────────────────┘
    ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
    │   ESC   │   BOOT  │   TAP   │  EXTRA  │   BASE  │         │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │    [    │    7    │    8    │    9    │    ]    │  BSPACE │
    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
    │   TAB   │   LGUI  │  LALT   │ LCTRL   │ LSHIFT  │         ├─╯                ╰─┤    ;    │    4    │    5    │    6    │    =    │  ENTER  │
    └─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┘
              │         │  RLAT   │  NUM    │  MEDIA  │         │                    │    `    │    1    │    2    │    3    │    \    │
              └─────────┴─────────┼─────────┼─────────┼─────────┼─────────┐┌─────────┼─────────┼─────────┼─────────┼─────────┴─────────┘
                                  │         │         │         │         ││         │    -    │    0    │    .    │
                                  └─────────┴─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┴─────────┘                            */

    [U_NUM] = LAYOUT_6x3_4(
            //╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
       TD(DANCE_ESC),TD(U_TD_BOOT), TD(U_TD_U_TAP), TD(U_TD_U_EXTRA),TD(U_TD_U_BASE), U_NA,   KC_LBRC,    KC_7,     KC_8,     KC_9,   KC_RBRC,  KC_BSPC,
                     TD(DANCE_TAB),  KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,    U_NA,   KC_SCLN,    KC_4,     KC_5,     KC_6,   KC_EQL,   KC_ENTER,
                            U_NA,    KC_ALGR,TD(U_TD_U_FUN),TD(U_TD_U_MEDIA),  U_NA,   KC_GRV,     KC_1,     KC_2,     KC_3,   KC_BSLS,
                                               U_NA,     U_NA,     U_NA,      U_NA,     U_NP,    KC_MINS,    KC_0,     KC_DOT
    ),


        /*
    ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

    ┌───────────────────────────────────────────────────────────┐
    │ f u n c t i o n  k e y s                                  │
    └───────────────────────────────────────────────────────────┘
    ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
    │  ESC    │   F12   │   F7    │   F8    │   F9    │ P.SCREEN│ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │         │   BASE  │  EXTRA  │   TAP   │  BOOT   │  BSPACE │
    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
    │  TAB    │   F11   │   F4    │   F5    │   F6    │ SCRLLOCK├─╯                ╰─┤         │  LSHIFT │  LCTRL  │  LALT   │  LGUI   │  ENTER  │
    └─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┘
              │   F10   │   F1    │   F2    │   F3    │  PAUSE  │                    │         │ FUNCTION│  MEDIA  │  RALT   │         │
              └─────────┴─────────┼─────────┼─────────┼─────────┼─────────┐┌─────────┼─────────┼─────────┼─────────┼─────────┴─────────┘
                                  │  MENU   │  SPACE  │   TAB   │         ││         │         │         │         │
                                  └─────────┴─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┴─────────┘                            */

    [U_FUN] = LAYOUT_6x3_4(
            //╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
                    TD(DANCE_ESC),  KC_F12,    KC_F7,    KC_F8,    KC_F9,    KC_PSCR,   U_NA, TD(U_TD_U_BASE), TD(U_TD_U_EXTRA), TD(U_TD_U_TAP), TD(U_TD_BOOT), KC_BSPC,
                    TD(DANCE_TAB),  KC_F11,    KC_F4,    KC_F5,    KC_F6,    KC_SCRL,   U_NA,    KC_LSFT,  KC_LCTL,  KC_LALT,  KC_LGUI, KC_ENTER,
                                    KC_F10,    KC_F1,    KC_F2,    KC_F3,    KC_PAUS,   U_NA, TD(U_TD_U_FUN), TD(U_TD_U_MEDIA), KC_ALGR,  U_NA,
                                    KC_APP,    KC_SPC,   KC_TAB,   U_NA,     U_NA,     U_NA,     U_NA,     U_NP
    ),

/*
    ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

    ┌───────────────────────────────────────────────────────────┐
    │ t a p                                                     │
    └───────────────────────────────────────────────────────────┘
    ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
    │   ESC   │    Q    │    W    │    E    │    R    │    T    │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │    Y    │    U    │    I    │    O    │    P    │ BSPACE  │
    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
    │   TAB   │    A    │    S    │    D    │    F    │    G    ├─╯                ╰─┤    H    │    J    │    K    │    L    │    '    │ ENTER   │
    └─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┘
              │    Z    │    X    │    C    │    V    │    B    │                    │    N    │    M    │    ,    │    .    │    /    │
              └─────────┴─────────┼─────────┼─────────┼─────────┼─────────┐┌─────────┼─────────┼─────────┼─────────┼─────────┴─────────┘
                                  │ SPACE   │  SPACE  │   TAB   │  BASE   ││ DELETE  │  RALT   │  BSPACE │  ENTER  │
                                  └─────────┴─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┴─────────┘                            */

    [U_TAP] = LAYOUT_6x3_4(
            //╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
                          KC_ESC,    KC_Q,     KC_W,      KC_E,    KC_R,      KC_T,      KC_Y,    KC_U,     KC_I,     KC_O,     KC_P,    KC_BSPC,
                          KC_TAB,    KC_A,     KC_S,      KC_D,    KC_F,      KC_G,      KC_H,    KC_J,     KC_K,     KC_L,     KC_QUOT, KC_ENTER,
                                     KC_Z,     KC_X,      KC_C,    KC_V,      KC_B,      KC_N,    KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,
                                     KC_SPC,   KC_SPC,    KC_TAB,  TD(U_TD_U_BASE),    KC_DEL,    KC_ALGR, KC_BSPC,  KC_ENTER
    ),

};



// ┌───────────────────────────────────────────────────────────┐
// │ d e b u g                                                 │
// └───────────────────────────────────────────────────────────┘

typedef struct {
    bool    is_press_action;
    uint8_t step;
} tap;

enum { SINGLE_TAP = 1, SINGLE_HOLD, DOUBLE_TAP, DOUBLE_HOLD, DOUBLE_SINGLE_TAP, MORE_TAPS };

static tap dance_state[2];

uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed)
            return SINGLE_TAP;
        else
            return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted)
            return DOUBLE_SINGLE_TAP;
        else if (state->pressed)
            return DOUBLE_HOLD;
        else
            return DOUBLE_TAP;
    }
    return MORE_TAPS;
}

void on_dance_tab(tap_dance_state_t *state, void *user_data);
void dance_tab_finished(tap_dance_state_t *state, void *user_data);
void dance_tab_reset(tap_dance_state_t *state, void *user_data);

void on_dance_tab(tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
    }
    if (state->count > 3) {
        tap_code16(KC_TAB);
    }
}

void dance_tab_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP:
            register_code16(KC_TAB);
            break;
        case DOUBLE_TAP:
            register_code16(KC_TAB);
            register_code16(KC_TAB);
            break;
        case DOUBLE_HOLD:
            register_code16(LALT(KC_TAB));
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_TAB);
            register_code16(KC_TAB);
    }
}

void dance_tab_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP:
            unregister_code16(KC_TAB);
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_TAB);
            break;
        case DOUBLE_HOLD:
            unregister_code16(LALT(KC_TAB));
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_TAB);
            break;
    }
    dance_state[0].step = 0;
}

void on_dance_esc(tap_dance_state_t *state, void *user_data);
void dance_esc_finished(tap_dance_state_t *state, void *user_data);
void dance_esc_reset(tap_dance_state_t *state, void *user_data);

void on_dance_esc(tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_ESC);
        tap_code16(KC_ESC);
        tap_code16(KC_ESC);
    }
    if (state->count > 3) {
        tap_code16(KC_ESC);
    }
}

void dance_esc_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP:
            register_code16(KC_ESC);
            break;
        case DOUBLE_TAP:
            register_code16(KC_ESC);
            register_code16(KC_ESC);
            break;
        case DOUBLE_HOLD:
            register_code16(LCTL(LALT(KC_Q)));
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_ESC);
            register_code16(KC_ESC);
    }
}

void dance_esc_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP:
            unregister_code16(KC_ESC);
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_ESC);
            break;
        case DOUBLE_HOLD:
            unregister_code16(LCTL(LALT(KC_Q)));
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_ESC);
            break;
    }
    dance_state[1].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
    [U_TD_BOOT] = ACTION_TAP_DANCE_FN(u_td_fn_boot),
#define MIRYOKU_X(LAYER, STRING) [U_TD_U_##LAYER] = ACTION_TAP_DANCE_FN(u_td_fn_U_##LAYER),
    MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
    [DANCE_TAB] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_tab, dance_tab_finished, dance_tab_reset),
    [DANCE_ESC]     = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_esc, dance_esc_finished, dance_esc_reset),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
  return true;
}
