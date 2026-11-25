#include "m2c.h"
typedef struct { s32 state; s32 buttons; u8 next; u8 pad[5]; u8 pad_e; } Menu;
typedef struct { u8 b0:1; } BF;
void func_00131600(s32, u8);
void func_001C9BA0(void);
void func_001CB980(void *);
void func_00123C40(void *, s32, s32);
void func_001CEDC0(s32);
void func_001CEA50(s32);
void func_001CBED0(s16, s32, s32);
void func_0019DCF0(void);
extern s32 *D_00201D68;
extern s32 D_002021E0;
extern s32 D_002021E8;
extern s32 D_002021EC;
extern s32 D_002021F0;
extern s32 D_002021FC;
extern s32 D_004A3290[];
extern s32 D_004A3294[];
extern f32 D_004A3298[];
extern BF D_004A329C[];
extern u16 D_004A32A0[];

void func_0019D580(Menu *m) {
    s32 n;

    func_001C9BA0();
    if (m->buttons & 0x10) {
        D_002021E0--;
        D_002021FC = 0;
        if (D_002021E0 < 0) {
            D_002021E0 = 0;
        } else {
            func_00131600(0x66, m->pad_e);
        }
    } else if (m->buttons & 0x40) {
        D_002021E0++;
        D_002021FC = 0;
        if (D_002021E0 > 7) {
            D_002021E0 = 7;
        } else {
            func_00131600(0x66, m->pad_e);
        }
    } else if (m->buttons & 0x20) {
        if (D_002021EC > 0) {
            switch (D_002021E0) {
            case 0: D_004A32A0[0]++; break;
            case 1: D_004A32A0[1]++; break;
            case 2: D_004A32A0[2]++; break;
            case 3: D_004A32A0[3]++; break;
            case 4: D_004A32A0[4]++; break;
            case 5: D_004A32A0[5]++; break;
            case 6: D_004A32A0[6]++; break;
            case 7: D_004A32A0[7]++; break;
            }
            D_002021EC--;
            func_00131600(0x6A, m->pad_e);
        }
    } else if (m->buttons & 0x80) {
        n = D_002021EC;
        if (n < D_002021F0) {
            switch (D_002021E0) {
            case 0: if (D_004A32A0[0] > 0) { D_004A32A0[0]--; D_002021EC = n + 1; func_00131600(0x6A, m->pad_e); } break;
            case 1: if (D_004A32A0[1] > 0) { D_004A32A0[1]--; D_002021EC = n + 1; func_00131600(0x6A, m->pad_e); } break;
            case 2: if (D_004A32A0[2] > 0) { D_004A32A0[2]--; D_002021EC = n + 1; func_00131600(0x6A, m->pad_e); } break;
            case 3: if (D_004A32A0[3] > 0) { D_004A32A0[3]--; D_002021EC = n + 1; func_00131600(0x6A, m->pad_e); } break;
            case 4: if (D_004A32A0[4] > 0) { D_004A32A0[4]--; D_002021EC = n + 1; func_00131600(0x6A, m->pad_e); } break;
            case 5: if (D_004A32A0[5] > 0) { D_004A32A0[5]--; D_002021EC = n + 1; func_00131600(0x6A, m->pad_e); } break;
            case 6: if (D_004A32A0[6] > 0) { D_004A32A0[6]--; D_002021EC = n + 1; func_00131600(0x6A, m->pad_e); } break;
            case 7: if (D_004A32A0[7] > 0) { D_004A32A0[7]--; D_002021EC = n + 1; func_00131600(0x6A, m->pad_e); } break;
            }
        }
    } else if (m->buttons & 0x2000) {
        if (D_002021EC == 0) {
            func_001CB980(D_004A32A0);
            func_00123C40(D_004A32A0, 0, 0x10);
            func_001CEDC0(3);
            func_001CEA50(1);
            D_004A3298[0] = 15.0f;
            D_004A329C[0].b0 = 0;
            D_004A3294[0] = 1;
            func_001CBED0(D_00201D68[D_004A3290[0]], -1, -1);
            func_0019DCF0();
            func_00131600(0x67, m->pad_e);
        } else {
            func_00131600(0x68, m->pad_e);
        }
    } else if (m->buttons & 0x4000) {
        D_002021E8 = 0;
        func_00131600(0x68, m->pad_e);
    }
    m->buttons = 0;
}
