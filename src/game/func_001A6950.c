#include "common.h"
typedef struct { u8 pad[0x10]; s32 *x10; } M;
typedef struct A {
    u16 m0;
    u8 pad2[2];
    M **m4;
    s32 *m8;
    s32 mC;
    s32 m10;
    s32 m14;
    s32 m18[0x19];
    s32 m7C;
    u8 pad80[0x4B0 - 0x80];
    s32 m4B0;
    s32 m4B4[0x18];
    s32 m514;
    s32 m518;
    s32 m51C;
    u8 pad520[0x80];
    Flags8 f5A0;
} A;
extern A **D_004A4570[];
void func_001A6950(void) {
    s32 i;
    for (i = 0; i < 0x81; i++) {
        A **p = D_004A4570[i];
        if (p) {
            A *a = *p;
            if (a->f5A0.b & 1) {
                s32 j;
                s32 base = *(*a->m4)->x10;
                a->m4B0 = base + a->m10;
                a->m514 = base + a->m14;
                for (j = 0; j < a->m7C; j++) {
                    a->m4B4[j] = base + a->m18[j];
                }
                a->m518 = *a->m8;
                a->m51C = a->m518 + 0x640;
            }
        }
    }
}
