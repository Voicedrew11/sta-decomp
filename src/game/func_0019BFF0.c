/* MATCH only with MWCC=mwcps2-3.0b38-030307 (b52 emits addiu at the switch range check) */
#include "m2c.h"
typedef struct { u8 pad[0x20]; u16 x20; u8 pad22[0x6E]; } E;
typedef struct { s32 k0; s32 k4; u8 t8; u8 pad[7]; } K;
s32 func_001CCD90(s32);
u8 *func_001CCD30(s32);
E *func_001AFC90(void);
extern s16 D_001FD3F8[];
extern K D_004A30E0[];
static inline void sub5(E *e1) {
    switch (e1->x20) {
    case 5:
        D_004A30E0[4].k4 = 0x2717;
        break;
    case 6:
        D_004A30E0[4].k4 = 0x2727;
        break;
    case 7: case 8: case 10: case 14:
        break;
    case 9:
        D_004A30E0[4].k4 = 0x2713;
        break;
    case 11: case 12: case 13: case 15: case 16: case 17: case 18: case 19:
        D_004A30E0[4].k4 = -1;
        break;
    }
}

void func_0019BFF0(void) {
    s32 i1;
    u8 *c1;
    u8 *c0;
    E *e0;
    s32 i0;
    E *e1;

    D_004A30E0[0].k0 = 0x2715;
    D_004A30E0[1].k0 = 0x2716;
    D_004A30E0[2].k0 = 0x272D;
    i0 = (s16)func_001CCD90(D_001FD3F8[5]);
    c0 = func_001CCD30(D_001FD3F8[5]);
    if (i0 != -1) {
        e0 = &func_001AFC90()[i0];
    } else {
        e0 = 0;
    }
    i1 = (s16)func_001CCD90(D_001FD3F8[6]);
    c1 = func_001CCD30(D_001FD3F8[6]);
    if (i1 != -1) {
        e1 = &func_001AFC90()[i1];
    } else {
        e1 = 0;
    }
    if (c0 == 0 && c1 == 0) {
        D_004A30E0[6].k0 = -1;
        D_004A30E0[5].k0 = -1;
        D_004A30E0[6].k4 = -1;
        D_004A30E0[5].k4 = -1;
        D_004A30E0[4].k0 = 0x271B;
        D_004A30E0[4].k4 = 0x271F;
        D_004A30E0[3].k0 = 0x2711;
        return;
    }
    D_004A30E0[3].k0 = 0x2714;
    if (e1 != 0 && e1->x20 == 10) {
        D_004A30E0[3].k0 = 0x2711;
    }
    D_004A30E0[4].k0 = 0x271B;
    if (e1 != 0) {
        switch (e1->x20) {
        case 7: case 8: case 9: case 10: case 14:
            D_004A30E0[4].k0 = 0x2721;
            break;
        case 1: case 2: case 3: case 4: case 5: case 6:
            D_004A30E0[4].k0 = 0x272F;
            break;
        case 11: case 12: case 13: case 16: case 17: case 18: case 19:
            D_004A30E0[4].k0 = 0x2725;
            break;
        case 15:
            D_004A30E0[4].k0 = 0x2730;
            break;
        default:
            D_004A30E0[4].k0 = 0x271B;
            break;
        }
    }
    D_004A30E0[4].k4 = 0x271F;
    if (e0 != 0) {
        switch (e0->x20) {
        case 1:
            if (e1 != 0) {
                if (e1->x20 == 1) {
                    D_004A30E0[4].k4 = 0x2726;
                } else {
                    D_004A30E0[4].k4 = 0x2717;
                }
            } else {
                D_004A30E0[4].k4 = 0x2717;
            }
            break;
        case 14: case 7: case 8: case 10:
            D_004A30E0[4].k4 = 0x2726;
            break;
        case 3: case 5:
            D_004A30E0[4].k4 = 0x2717;
            break;
        case 2: case 4:
            D_004A30E0[4].k4 = 0x272B;
            break;
        default:
            D_004A30E0[4].k4 = 0x271F;
            if (e1 != 0) {
                sub5(e1);
            }
            break;
        }
    }
    D_004A30E0[6].k0 = -1;
    D_004A30E0[6].k4 = -1;
    if (e1 != 0) {
        switch (e1->x20) {
        case 0:
            break;
        case 7: case 8: case 10: case 14:
            D_004A30E0[6].k0 = 0x2723;
            break;
        case 9:
            D_004A30E0[6].k0 = 0x2710;
            break;
        case 1:
            D_004A30E0[6].k0 = 0x271A;
            break;
        case 2:
            D_004A30E0[6].k0 = 0x271D;
            break;
        case 3:
            D_004A30E0[6].k0 = 0x2724;
            break;
        case 4:
            D_004A30E0[6].k0 = 0x271E;
            break;
        case 5:
            D_004A30E0[6].k0 = 0x2718;
            break;
        case 6:
            D_004A30E0[6].k0 = 0x2722;
            break;
        case 19:
            D_004A30E0[6].k0 = 0x2712;
            break;
        case 11: case 12: case 13: case 16: case 17:
            D_004A30E0[6].k0 = 0x271C;
            break;
        case 15:
            D_004A30E0[6].k0 = 0x2734;
            D_004A30E0[6].k4 = 0x2735;
            break;
        case 18:
            D_004A30E0[6].k0 = 0x2731;
            D_004A30E0[6].k4 = 0x2732;
            break;
        }
    }
    D_004A30E0[5].k0 = -1;
    D_004A30E0[5].k4 = -1;
    if (e0 != 0) {
        switch (e0->x20) {
        case 14: case 7: case 8: case 10:
            D_004A30E0[5].k0 = 0x272C;
            break;
        case 1:
            D_004A30E0[5].k0 = 0x2729;
            if (D_004A30E0[6].k0 == 0x271A) {
                D_004A30E0[5].k0 = 0x272E;
            }
            break;
        case 3:
            D_004A30E0[5].k0 = 0x2728;
            break;
        case 5:
            D_004A30E0[5].k0 = 0x2719;
            break;
        case 18:
            D_004A30E0[5].k0 = 0x2733;
            break;
        }
    }
}

