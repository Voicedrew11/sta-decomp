#include "common.h"
s32 ItemType_GetCategory_0_001D1CB0(s32 x);
s32 ItemType_IsWeapon_0_001D1D50(s32 x);
s32 ItemType_IsShield_0_001D1DA0(s32 v);
s32 ItemType_IsGun_0_001D1DD0(s32 v);
s32 ItemType_IsMagic_0_001D1E00(s32 arg0);

/* ItemType_GetCategory_0_001D1CB0 */
s32 ItemType_GetCategory_0_001D1CB0(s32 x) { switch (x) { case 2: case 4: case 6: case 9: case 11: case 12: case 13: case 15: case 16: case 17: case 18: case 19: return 1; } return 0; }

/* ItemType_IsWeapon_0_001D1D50 */
/* MATCH only with MWCC=mwcps2-3.0b38-030307 (b52 emits addiu at the switch range check) */
s32 ItemType_IsWeapon_0_001D1D50(s32 x) {
    switch (x) {
    case 7: case 8: case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18:
        return 1;
    case 9: case 19:
        return 2;
    }
    return 0;
}

/* ItemType_IsShield_0_001D1DA0 */
s32 ItemType_IsShield_0_001D1DA0(s32 v) { if (v == 9 || v == 19) return 1; return 0; }

/* ItemType_IsGun_0_001D1DD0 */
s32 ItemType_IsGun_0_001D1DD0(s32 v) { if (v == 15 || v == 16) return 1; return 0; }

/* ItemType_IsMagic_0_001D1E00 */
s32 ItemType_IsMagic_0_001D1E00(s32 arg0) {
    return arg0 == 0xC;
}
