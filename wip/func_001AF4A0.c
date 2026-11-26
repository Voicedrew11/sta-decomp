#include "m2c.h"
typedef struct O {
    u8 pad[0x84];
    s8 *m84;
    u8 pad88[0x14];
    s16 m9C;
    s16 m9E;
    u8 padA0[7];
    s8 mA7;
    union { u16 h; u8 b; } mA8;
    u8 padAA[4];
    s16 mAE;
    u8 padB0[4];
    f32 mB4;
    s32 mB8;
    s32 mBC;
    s32 mC0[2][2];
} O;
typedef struct { s16 a[2]; s16 n[2]; O *list[2][16]; } G;
extern O *D_00202288;
extern s32 D_0020228C;
extern s32 D_002022A0;
extern volatile G D_004AC5A0;
void memset(void *, s32, s32);
void func_00167030(s32);
void func_001745D0(s32, s8 *);

void func_001AF4A0(O *o) {
    s32 i;
    s32 t;
    s32 k;
    O * volatile *p;
    volatile s16 *np;

    if (o != 0 && o->m9C != -1) {
    if (o == D_00202288) {
        D_0020228C = 1;
    }
    if (o->mA8.b & 1) {
        if (o->mB8 != 0) {
            func_00167030(o->mB8);
        }
        if (o->mBC != 0) {
            func_00167030(o->mBC);
        }
        for (i = 0; i < 4; i++) {
            if (o->mC0[i / 2][i % 2] != 0) {
                func_00167030(o->mC0[i / 2][i % 2]);
            }
        }
        func_001745D0(D_002022A0, o->m84);
        o->m84 = 0;
    }
    o->m9C = -1;
    o->mA8.h = 0;
    switch (o->m9E) {
    case 0:
        memset(o, 0, 0xD0);
        o->m9C = -1;
        o->m9E = 0;
        break;
    case 1:
        memset(o, 0, 0xD0);
        o->m9C = -1;
        o->m9E = 1;
        for (t = 0; t < 2; t++) {
            for (k = 0; k < D_004AC5A0.n[t]; k++) {
                if (D_004AC5A0.list[t][k] == o) {
                    break;
                }
            }
            if (k < D_004AC5A0.n[t]) {
                p = &D_004AC5A0.list[t][k];
                np = &D_004AC5A0.n[t];
                while (k < *np - 1) {
                    p[0] = p[1];
                    k++;
                    p++;
                }
                D_004AC5A0.n[t]--;
                break;
            }
        }
        break;
    case 2:
        memset(o, 0, 0xD0);
        o->m9C = -1;
        o->m9E = 2;
        break;
    }
    o->mB4 = 1.0f;
    o->mAE = -1;
    o->mA7 = -1;
    }
}
