#include "common.h"
typedef struct { s32 x0; u8 pad4[8]; u16 xC; u8 padE[10]; u8 x18[8]; u8 x20[8]; s32 x28; } Sub;
typedef struct { u8 pad[8]; Sub s; u8 pad2[0x310 - 8 - sizeof(Sub)]; } E;
extern E D_00437DC0[4];
void func_001547F0(s32, s32);
s32 func_001777C0(u16, void *, void *);
void func_001549D0(void);
void func_00175150(Sub *);
void func_00176AE0(void);
void func_00155900(void);

void func_00175BB0(void) {
    s32 i;
    Sub *s;
    E *e;
    E *f;
    s32 j;
    func_001547F0(0, 0);
    for (i = 0, e = D_00437DC0; i < 4; i++, e++) {
        s = &e->s;
        if (e->s.x0 != -1) {
            s->x28 = func_001777C0(s->xC, s->x18, s->x20);
        }
    }
    func_001549D0();
    for (j = 0, f = D_00437DC0; j < 4; j++, f++) {
        if (f->s.x0 != -1) {
            func_00175150(&f->s);
        }
    }
    func_00176AE0();
    func_00155900();
}
