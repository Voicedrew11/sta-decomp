#include "m2c.h"
typedef struct {
    s8 pad0[0x40];
    f32 v40[4];
    f32 v50[4];
    f32 x60;
    f32 x64;
    f32 x68;
    f32 x6C;
    s8 pad70[0x10];
    s32 x80;
    s8 pad84[0x18];
    s16 h9C;
    s8 pad9E[8];
    s8 xA6;
    s8 xA7;
    u8 b0:1;
    u8 b1:1;
    u8 b2:1;
    u8 b3:5;
    s8 padA9[5];
    s16 xAE;
    s8 padB0[4];
    f32 xB4;
    s8 padB8[0x18];
} Obj;
typedef struct { s8 pad[0x10]; s32 x10; s8 pad14[0x6C]; s8 x80[0x10]; } Ent;
void sceVu0CopyMatrix(void *, void *);
extern f32 D_001F2170[];
extern Obj *D_00202288;
extern Ent *D_002022B0;
extern Obj D_004AC630[4];

Obj *ItemObj_Spawn_0_001AE7C0(s16 id) {
    Obj *s = 0;
    Ent *t = D_002022B0;
    s32 i;

    for (i = 0; i < 4; i++) {
        if (D_004AC630[i].h9C == -1) {
            s = &D_004AC630[i];
            break;
        }
    }
    if (s == 0) {
        return 0;
    }
    s->h9C = id;
    s->xAE = -1;
    s->xA6 = -1;
    s->xA7 = -1;
    s->b0 = 0;
    s->b1 = 0;
    s->b2 = 1;
    s->x80 = t[id].x10;
    s->xB4 = 1.0f;
    sceVu0CopyMatrix(s, D_001F2170);
    if (D_00202288 == 0) {
        D_00202288 = s;
    }
    return s;
}
