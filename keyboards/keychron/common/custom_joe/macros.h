#pragma once
#include QMK_KEYBOARD_H

// Basic Macros
#define MC_COMM RCTL(KC_SLSH)       // Comment Line
#define MC_SAVE LCTL(KC_S)          // Save
#define MC_COPY LCTL(KC_C)          // Copy
#define MC_CUT LCTL(KC_X)           // Cut
#define MC_PSTE LCTL(KC_V)          // Paste
#define MC_SNIP LSG(KC_S)           // Screenshot/Snip
#define MC_CTAB LCTL(KC_W)          // Close Tab
#define MC_OTAB LCS(KC_T)           // Re-open Last Closed Tab
#define MC_BACK LALT(KC_LEFT)       // Back
#define MC_FORW LALT(KC_RGHT)       // Forward
//...

// Complicated Macros
enum custom_joe_keycodes 
{
    MC_DBJS = SAFE_RANGE,           // Debug Block JavaScript
    MC_DBCS,                        // Debug Block C#
    MC_SBLK,                        // Select Block
};