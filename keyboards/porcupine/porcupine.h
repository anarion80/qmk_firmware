// Copyright 2023 Anarion (@anarion80)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

#include "quantum.h"

#define ___ KC_NO

#define LAYOUT_5x3_3( \
        L01, L02, L03, L04, L05, R01, R02, R03, R04, R05, \
        L06, L07, L08, L09, L10, R06, R07, R08, R09, R10, \
        L11, L12, L13, L14, L15, R11, R12, R13, R14, R15, \
                  L16, L17, L18, R16, R17, R18       \
    ) \
    { \
        { ___, L01, L02, L03, L04, L05 }, \
        { ___, L06, L07, L08, L09, L10 }, \
        { ___, L11, L12, L13, L14, L15 }, \
        { ___, ___, ___, L16, L17, L18 }, \
        { ___, R05, R04, R03, R02, R01 }, \
        { ___, R10, R09, R08, R07, R06 }, \
        { ___, R15, R14, R13, R12, R11 }, \
        { ___, ___, ___, R18, R17, R16 }  \
    }

#define LAYOUT_5x3_4( \
        L01, L02, L03, L04, L05, R01, R02, R03, R04, R05, \
        L06, L07, L08, L09, L10, R06, R07, R08, R09, R10, \
        L11, L12, L13, L14, L15, R11, R12, R13, R14, R15, \
             L16, L17, L18, L19, R16, R17, R18, R19       \
    ) \
    { \
        { ___, L01, L02, L03, L04, L05 }, \
        { ___, L06, L07, L08, L09, L10 }, \
        { ___, L11, L12, L13, L14, L15 }, \
        { ___, ___, L16, L17, L18, L19 }, \
        { ___, R05, R04, R03, R02, R01 }, \
        { ___, R10, R09, R08, R07, R06 }, \
        { ___, R15, R14, R13, R12, R11 }, \
        { ___, ___, R19, R18, R17, R16 }  \
    }

#define LAYOUT_6x3_4( \
        L01, L02, L03, L04, L05, L06, R01, R02, R03, R04, R05, R06, \
        L07, L08, L09, L10, L11, L12, R07, R08, R09, R10, R11, R12, \
             L13, L14, L15, L16, L17, R13, R14, R15, R16, R17,      \
                  L18, L19, L20, L21, R18, R19, R20, R21           \
    ) \
    { \
        { L01, L02, L03, L04, L05, L06 }, \
        { L07, L08, L09, L10, L11, L12 }, \
        { ___, L13, L14, L15, L16, L17 }, \
        { ___, ___, L18, L19, L20, L21 }, \
        { R06, R05, R04, R03, R02, R01 }, \
        { R12, R11, R10, R09, R08, R07 }, \
        { ___, R17, R16, R15, R14, R13 }, \
        { ___, ___, R21, R20, R19, R18 }  \
    }

#define LAYOUT LAYOUT_5x3_3
