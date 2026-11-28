#include "m2c.h"
#include "common.h"
typedef struct {
    u8 p0[0xA]; u16 xA; u8 pC[0x14]; u16 x20; u8 p22[0xA]; u16 x2C[8]; u8 x3C; u8 p3D[3];
    union { struct { f32 x40, x44, x48, x4C; } f; u16 h[0x28]; } u;
} __attribute__((aligned(16))) E;
void Item_GetStatBlock_0_001D1240(E *d, s16 idx, u8 k);
s32 ItemType_GetCategory_0_001D1CB0(s32 x);
s32 ItemType_IsWeapon_0_001D1D50(s32 x);
s32 ItemType_IsShield_0_001D1DA0(s32 v);
s32 ItemType_IsGun_0_001D1DD0(s32 v);
s32 ItemType_IsMagic_0_001D1E00(s32 arg0);
E* Item_GetTable_1_001AFC90(void);
void memset(void *, s32, s32);

/* Item_GetStatBlock_0_001D1240 */
static inline u16 sc(u16 v, u8 k, u8 n) {
    s32 b;
    if (n == 0) return 0;
    b = v * 70 / 100;
    return b + (v - b) * k / n;
}

void Item_GetStatBlock_0_001D1240(E *d, s16 idx, u8 k) {
    E *src;

    src = Item_GetTable_1_001AFC90();
    memset(d, 0, 0x90);
    if (idx <= 0 || idx >= 800) {
        d->u.f.x40 = d->u.f.x44 = d->u.f.x48 = d->u.f.x4C = 1.0f;
    }
    if (idx <= 0 || k == 0) return;
    {
        *d = src[idx];
        if (d->xA == 1) {
            d->x2C[0] = sc(d->x2C[0], k, d->x3C);
            d->x2C[1] = sc(d->x2C[1], k, d->x3C);
            d->x2C[2] = sc(d->x2C[2], k, d->x3C);
            d->x2C[3] = sc(d->x2C[3], k, d->x3C);
            d->x2C[4] = sc(d->x2C[4], k, d->x3C);
            d->x2C[5] = sc(d->x2C[5], k, d->x3C);
            d->x2C[6] = sc(d->x2C[6], k, d->x3C);
            d->x2C[7] = sc(d->x2C[7], k, d->x3C);
            if (d->x20 == 4) {
                d->u.h[5] = sc(d->u.h[5], k, d->x3C);
                d->u.h[6] = sc(d->u.h[6], k, d->x3C);
                d->u.h[7] = sc(d->u.h[7], k, d->x3C);
                d->u.h[8] = sc(d->u.h[8], k, d->x3C);
                d->u.h[9] = sc(d->u.h[9], k, d->x3C);
                d->u.h[10] = sc(d->u.h[10], k, d->x3C);
            }
        } else if (d->xA == 2) {
            d->x2C[2] = sc(d->x2C[2], k, d->x3C);
            d->x2C[3] = sc(d->x2C[3], k, d->x3C);
            d->x2C[4] = sc(d->x2C[4], k, d->x3C);
            d->x2C[5] = sc(d->x2C[5], k, d->x3C);
            d->x2C[6] = sc(d->x2C[6], k, d->x3C);
            d->x2C[7] = sc(d->x2C[7], k, d->x3C);
        }
    }
}

/* ItemType_GetCategory_0_001D1CB0 */
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
