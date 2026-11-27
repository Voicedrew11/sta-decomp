/* MATCH only with MWCC=mwcps2-3.0b38-030307 (b52 emits addiu at the switch range check) */
#include "common.h"
s32 ItemType_IsWeapon_0_001D1D50(s32 x) {
    switch (x) {
    case 7: case 8: case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18:
        return 1;
    case 9: case 19:
        return 2;
    }
    return 0;
}
