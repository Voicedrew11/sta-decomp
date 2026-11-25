#include "common.h"

typedef struct { char pad[0x40]; f32 v[3]; f32 f4c; unsigned char on : 1; char p51[3]; f32 f54; char rest[8]; } E;
extern E D_0030D9A0[256];
void sceVu0AddVector(f32 *v0, f32 *v1, f32 *v2);

void func_0015D5A0(f32 *d)
{
    s32 i;
    E *e = D_0030D9A0;
    for (i = 0; i < 256; i++, e++) {
        if (e->on) {
            f32 s = e->f54;
            sceVu0AddVector(e->v, e->v, d);
            e->f4c = -1.0 * (s * s);
        }
    }
}
