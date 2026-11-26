#include "common.h"
typedef struct { u8 pad[0x1C]; u16 x1C; u8 p[0xA]; } T;
typedef struct { s32 x0; s32 x4; } U;
typedef struct { s32 id; u8 pad[0x6E]; u16 x72; u8 p74[0xCC]; T *x140; u8 p144[0x40]; U *x184; } O;
extern O **D_00201E80[2];
#define C (D_00201E80[2])
#define D (D_00201E80[3])
void func_001AE0E0(O **, s32, O *);

void func_001B0880(u16 a0, u16 a1) {
    O **h;
    s32 i;
    O *o;
    h = 0;
    if (C) { O *t = *C; if (t && t->id == a0) h = C; }
    if (D) { O *t = *D; if (t && t->id == a0) h = D; }
    if (h == 0) return;
    i = 0;
    if (0 < (*h)->x72) {
        do {
            U *u;
            T *t;
            t = &(*h)->x140[i];
            u = &(*h)->x184[i];
            if (t->x1C == a1) func_001AE0E0(h, u->x0, *h);
            i++;
        } while (i < (*h)->x72);
    }
}
