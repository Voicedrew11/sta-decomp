#include "m2c.h"
typedef struct { f32 m[4]; f32 x; f32 y; } S;
typedef union { u32 w; struct { u8 r, g, b, a; } c; } Col;
typedef struct { s16 x0, x2, x4, x6; u16 x8; u8 xA, xB; u8 padC[2]; u8 xE, xF; } Ent;
typedef struct { u8 pad0[0x50]; Ent e[10]; } Slot;
typedef struct { s32 a[4]; s32 arr[8]; } Buf;
typedef struct {
    u8 pad0[0x28];
    s32 x28;
    u8 pad2C[3];
    u8 x2F;
    f32 x30, x34, x38, x3C;
} O;
extern S D_001F2A10[] __attribute__((aligned(16)));
extern Slot D_004A0900[];
extern char D_001FCD00[];
extern char D_001FCD10[];
extern char D_001FCD20[];
extern char D_001FCD30[];
extern char D_001FCD40[];
extern char D_001FCD58[];
extern char D_001FCD60[];
s32 func_001E8290(void);
s8 *func_00188FF0(s32);
void func_001E5E80(Buf *);
void func_00181680(s32, void *, void *, void *, S *, u32);
void func_001256E0(char *, char *, ...);
void func_001875C0(f32, f32, f32, char *, s32, u32);
char *func_00195AA0(s32);
char *func_00195B10(s32);
static inline u32 sub(u32 x) {
    u32 t;
    asm("addi %0, %1, -0x7D1" : "=r"(t) : "r"(x));
    return t;
}

void func_0018BCC0(O *o, s32 unused, u32 id, s32 n) {
    S t __attribute__((aligned(16))) = D_001F2A10[0];
    Ent *e = &D_004A0900[func_001E8290()].e[n];
    s32 s0 = func_00188FF0(0)[n];
    char buf[0x100] = {0};
    Buf b = {0};
    Col col;
    u8 f;
    col.w = 0x80808080;
    col.c.a = o->x2F * 2;
    func_001E5E80(&b);
    if (id < 2000) {
        t.x = o->x30;
        t.y = o->x34;
        func_00181680(o->x28, o, (u8 *)o + 0x10, (u8 *)o + 0x2C, &t, id);
        return;
    }
    if ((f = e->xF) != 0 && s0 == 0) {
        switch (sub(id)) {
        case 0:
            break;
        case 1:
            if (e->xE) {
                col.c.r = 0x20;
                col.c.g = 0x20;
            }
            func_001256E0(buf, D_001FCD00, n + 1);
            func_001875C0(o->x38, o->x3C, 1.0f, buf, 0, col.w);
            break;
        case 2:
            func_001256E0(buf, D_001FCD10, e->x4, e->x0);
            func_001875C0(o->x38, o->x3C, 0.9f, buf, 0, col.w);
            break;
        case 3:
            func_001256E0(buf, D_001FCD20, e->x6, e->x2);
            func_001875C0(o->x38, o->x3C, 0.9f, buf, 0, col.w);
            break;
        case 4:
            func_001875C0(o->x38, o->x3C, 0.9f, D_001FCD30, 0, col.w);
            break;
        case 5:
            func_001256E0(buf, D_001FCD40, e->x8, e->xA, e->xB);
            func_001875C0(o->x38, o->x3C, 0.9f, buf, 0, col.w);
            break;
        case 6:
            func_001875C0(o->x38, o->x3C, 0.9f, func_00195AA0(f / 10), 0, col.w);
            break;
        }
    } else {
        switch (sub(id)) {
        case 0:
            break;
        case 1:
            if (b.arr[n] == 2 || b.a[3] == 2 || s0 != 0) {
                col.w = 0x80404080;
                col.c.a = o->x2F * 2;
                func_001875C0(o->x38, o->x3C, 1.0f, func_00195B10(0x69), 0, col.w);
            } else {
                func_001875C0(o->x38, o->x3C, 1.0f, D_001FCD58, 0, col.w);
            }
            break;
        case 4:
            func_001875C0(o->x38, o->x3C, 0.9f, D_001FCD30, 0, col.w);
            break;
        case 2:
        case 3:
        case 5:
        case 6:
            func_001875C0(o->x38, o->x3C, 0.9f, D_001FCD60, 0, col.w);
            break;
        }
    }
}
