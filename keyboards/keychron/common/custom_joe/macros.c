#include QMK_KEYBOARD_H
#include "macros.h"
#include "custom_joe_rgb.h"

void selectBlock(void);
void debugBlock(uint16_t keycode);

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode)
    {
        case MC_SBLK:
            if (record->event.pressed)
            {
                selectBlock();
            }
            return false;
        case MC_DBJS:
        case MC_DBCS:
            if (record->event.pressed)
            {
                debugBlock(keycode);
            }
            return false;
        case LT_CLNX:
            if (record->event.pressed)
            {
                incrementCapslockRGB();
            }
            return false;
    }
    return true;
}

void selectBlock()
{
    register_code(KC_LCTL); // hold Ctrl
    tap_code(KC_K);           // press K
    tap_code(KC_C);           // press C
    unregister_code(KC_LCTL);
}

void debugBlock(uint16_t keycode)
{
    selectBlock();
    wait_ms(10);
    tap_code16(MC_COMM);
    wait_ms(10);
    tap_code16(MC_CUT);
    wait_ms(10);

    SEND_STRING("try\n{\n");
    tap_code16(KC_DOWN);

    if (keycode == MC_DBJS)
    {
        SEND_STRING("\ncatch(error)\n{\n\tlet x = 0;");
    }
    else if(keycode == MC_DBCS)
    {
        SEND_STRING("\ncatch(Exception e)\n{\nvar x = 0;");
    }

    tap_code16(KC_F9);

    tap_code16(KC_UP);
    tap_code16(KC_UP);
    tap_code16(KC_UP);
    tap_code16(KC_UP);

    tap_code16(MC_PSTE);
}
