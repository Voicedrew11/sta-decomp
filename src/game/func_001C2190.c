#include "actor.h"
typedef struct { u8 pad[0x30]; u32 x30; u32 x34; } Pad;
typedef struct { u8 pad[3]; u8 x3; } R;
typedef struct {
    u8 pad[0x39C]; u8 m39C; u8 pad2[0x3D5 - 0x39D]; u8 m3D5; u8 pad3[0x3E0 - 0x3D6]; u16 h[8];
} S;
u8 func_001A9450(void);
s32 func_001CBC20(s32);
void func_001C69A0(s32);
R *func_001D1E10(void);
void func_001CA940(void);
void func_001CA870(void);
void func_001CBA80(s16, u8);
static inline s8 *get(void) {
    if (D_002022E4 == NULL) {
        return NULL;
    }
    if (D_002022E4->unk518 == NULL) {
        return NULL;
    }
    return D_002022E4->unk518 + 0x180;
}

void func_001C2190(Actor *a, Pad *pad) {
    S *s;
    u32 mask;
    S *t;

    s = (S *)(a->unk518 + 0x180);
    mask = (func_001A9450() < 2) ? 4 : 0x800;
    if (s->m39C == 9) {
        if (func_001CBC20(0x12) <= 0) {
            if (s->m3D5 == 3) {
                func_001C69A0(5);
            }
            return;
        }
    } else {
        if (func_001CBC20(0x13) <= 0) {
            if (s->m3D5 == 3) {
                func_001C69A0(5);
            }
            return;
        }
    }
    if (s->m3D5 == 0) {
        if (pad->x30 & mask) {
            func_001C69A0(1);
            func_001D1E10()->x3 = 1;
            func_001CA940();
        }
    } else if (s->m3D5 == 1) {
        if (!(pad->x34 & mask)) {
            func_001C69A0(2);
            func_001D1E10()->x3 = 0;
        }
    } else if (s->m3D5 == 3) {
        if (!(pad->x34 & mask)) {
            func_001C69A0(4);
            func_001D1E10()->x3 = 0;
            if (s->m39C == 9) {
                func_001CBA80(0x12, 1);
            } else {
                func_001CBA80(0x13, 1);
            }
            t = (S *)get();
            if (t != NULL) {
                t->h[0] = 0xFFFF;
                t->h[1] = 0xFFFF;
                t->h[2] = 0xFFFF;
                t->h[3] = 0xFFFF;
                t->h[4] = 0xFFFF;
                t->h[5] = 0xFFFF;
                t->h[6] = 0xFFFF;
                t->h[7] = 0xFFFF;
            }
            func_001CA870();
        } else if (func_001A9450() >= 2 && (pad->x30 & 0x400)) {
            func_001C69A0(5);
            func_001D1E10()->x3 = 0;
        }
    }
}
