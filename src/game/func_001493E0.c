#include "common.h"
u32 func_0013E110(u16 *);
void sceVu0CopyVector(void *, void *);
u16 *func_001A5460(s32 *);
extern s32 D_003139A0[];
typedef struct { u8 pad[0x10]; Vec v; u8 p2[0x68]; f32 x88; u8 p3[0x1C]; s32 xA8; u8 p4[0xC]; f32 xB8; } O;
void func_001493E0(O *o) {
    s32 it;
    u16 *e;
    o->xA8 = 0;
    o->x88 = 600.0f;
    sceVu0CopyVector(&o->v, D_003139A0);
    it = 0;
    do {
        e = func_001A5460(&it);
    } while (e != NULL && *e != 0x3C);
    if (e != NULL) {
        o->xB8 = func_0013E110(e);
        return;
    }
    o->xB8 = 0.0f;
}
