#include "common.h"

typedef struct { s32 id; char p[0x24]; s32 h; } Sub;
typedef struct { char pad[8]; Sub s; char rest[0x310 - 8 - sizeof(Sub)]; } E;
extern E D_00437DC0[4];
void Tex_Release_1_00177570(s32 h);

void TexAnim_FreeAll_0_00175B40(void)
{
    s32 i;
    for (i = 0; i < 4; i++) {
        Sub *s = &D_00437DC0[i].s;
        if (s->id != -1) {
            Tex_Release_1_00177570(s->h);
            s->h = 0;
        }
    }
}
