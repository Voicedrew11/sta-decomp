#include "m2c.h"
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; } B8;
typedef struct { u8 pad[0x10]; s32 x10; u8 pad14[0x28]; B8 x3C; } Q;
typedef struct { u8 pad[0xC]; B8 xC; } F;
typedef struct { u8 pad[0xB0]; s32 xB0; u8 padB4[0x70]; s32 x124[8]; } S;
typedef struct { u8 pad[0x164]; s32 x164; u8 pad168[8]; } E;
typedef struct {
    u16 x0;
    u16 x2;
    Q **x4;
    s32 x8;
    u8 padC[0x70];
    s32 x7C;
    u8 pad80[0x41C];
    s32 x49C;
    u8 pad4A0[4];
    s32 x4A4;
    u8 pad4A8[8];
    F *x4B0;
    u8 pad4B4[0x64];
    S *x518;
    E *x51C;
    u8 pad520[0x60];
    u8 x580[0x20];
    u16 pad5A0a:3;
    u16 x5A0:8;
} P;
extern s32 D_004A4570[];
extern s16 D_004A4774[];
extern u16 D_004A4776[];
extern s32 D_00202278;
extern s32 D_00202280;
void func_00167030(s32);
void func_00178030(s32);
void func_001745D0(s32, s32);
void func_00128580(s32, void *);
void func_00169D00(void *, s32);
void func_001A5070(P **);

void func_001A6A10(P **a0) {
    P *p;
    Q **q;
    s32 i;
    S *s;

    p = *a0;
    q = p->x4;
    D_004A4570[p->x2] = 0;
    { u16 v = (*a0)->x2; s16 n = D_004A4774[0]++; D_004A4776[n] = v; }
    if (p->x8 != 0) {
        for (i = 0; i < p->x7C; i++) {
            if (p->x51C[i].x164 != 0) {
                func_00167030(p->x51C[i].x164);
            }
        }
        if ((*q)->x3C.b4) {
            func_00178030((*q)->x10);
        }
        if (p->x518->xB0 != 0) {
            func_001745D0(D_00202280, p->x518->xB0);
        }
        if (p->x49C != 0) {
            func_00128580(D_00202278, (void *)p->x49C);
        }
        if (p->x4A4 != 0) {
            func_00128580(D_00202278, (void *)p->x4A4);
        }
        func_00128580(D_00202278, (void *)p->x8);
    }
    if (p->x4B0 != NULL && (s = p->x518) != NULL && p->x4B0->xC.b6) {
        for (i = 0; i < 8; i++) {
            if (s->x124[i] != 0) {
                func_00167030(s->x124[i]);
            }
        }
    }
    func_00169D00(p->x580, 8);
    if (p->x5A0 != 0xFF) {
        func_001A5070(a0);
    }
    func_00128580(D_00202278, a0);
}
