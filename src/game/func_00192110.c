/* MATCH only with MWCC=mwcps2-3.0b38-030307 (b52 emits addiu at the switch range check) */
#include "common.h"
typedef union {
    u32 w;
    struct { u8 r, g, b, a; } c;
} Col;
typedef struct {
    u64 a, b;
    f32 x, y;
} S;
typedef struct {
    Vec v0;
    Vec v10;
    u8 pad20[8];
    s32 x28;
    Col x2C;
    f32 x30, x34, x38, x3C;
} A;
typedef struct {
    s16 x0, x2, x4, x6;
    u16 x8;
    u8 xA, xB;
    u8 padC[2];
    u8 xE, xF;
} E;
typedef struct {
    u8 pad[0x50];
    E e[10];
} Row;
typedef struct {
    u8 pad0[0xC];
    s32 xC;
    s32 arr[8];
} B;
void func_00181680(s32, Vec *, Vec *, Col *, S *, u32);
void func_001875C0(f32, s8 *, f32, f32, s32, u32);
void sprintf(s8 *, s8 *, ...);
s32 func_001E8290(void);
s8 *func_00188FF0(s32);
void func_001E5E80(B *);
s8 *func_00195AA0(s32);
s8 *func_00195B10(s32);
extern S D_001F2DA0 __attribute__((aligned(16)));
extern Row D_004A0900[];
extern s8 D_001FD128[];
extern s8 D_001FD138[];
extern s8 D_001FD148[];
extern s8 D_001FD158[];
extern s8 D_001FD170[];
extern s8 D_001FD188[];
extern s8 D_001FD190[];

void func_00192110(A *o, s32 unused, u32 kind, s32 idx) {
    S s __attribute__((aligned(16)));
    Col col;
    E *e;
    s32 c;
    s32 f;

    s = D_001F2DA0;
    e = &D_004A0900[func_001E8290()].e[idx];
    c = func_00188FF0(0)[idx];
    {
        s8 buf[0x100] = {0};
        B b = {0};

        func_001E5E80(&b);
        col.w = 0x80808080;
        col.c.a = o->x2C.c.a * 2;
        if (kind < 2000) {
            s.x = o->x30;
            s.y = o->x34;
            func_00181680(o->x28, &o->v0, &o->v10, &o->x2C, &s, kind);
            return;
        }
        f = e->xF;
        if (f != 0 && c == 0) {
            switch (kind) {
            case 2001:
                break;
            case 2002:
                if (e->xE) {
                    col.c.r = 0x20;
                    col.c.g = 0x20;
                }
                sprintf(buf, D_001FD128, idx + 1);
                func_001875C0(o->x38, buf, o->x3C, 1.0f, 0, col.w);
                break;
            case 2003:
                sprintf(buf, D_001FD138, e->x4, e->x0);
                func_001875C0(o->x38, buf, o->x3C, 0.9f, 0, col.w);
                break;
            case 2004:
                sprintf(buf, D_001FD148, e->x6, e->x2);
                func_001875C0(o->x38, buf, o->x3C, 0.9f, 0, col.w);
                break;
            case 2005:
                func_001875C0(o->x38, D_001FD158, o->x3C, 0.9f, 0, col.w);
                break;
            case 2006:
                sprintf(buf, D_001FD170, e->x8, e->xA, e->xB);
                func_001875C0(o->x38, buf, o->x3C, 0.9f, 0, col.w);
                break;
            case 2007:
                func_001875C0(o->x38, func_00195AA0((u8)f / 10), o->x3C, 0.9f, 0, col.w);
                break;
            }
        } else {
            switch (kind) {
            case 2001:
                break;
            case 2002:
                if (b.arr[idx] == 2 || b.xC == 2 || c != 0) {
                    col.w = 0x80404080;
                    col.c.a = o->x2C.c.a * 2;
                    func_001875C0(o->x38, func_00195B10(0x69), o->x3C, 1.0f, 0, col.w);
                } else {
                    func_001875C0(o->x38, D_001FD188, o->x3C, 1.0f, 0, col.w);
                }
                break;
            case 2005:
                func_001875C0(o->x38, D_001FD190, o->x3C, 0.9f, 0, col.w);
                break;
            case 2003:
            case 2004:
            case 2006:
            case 2007:
                func_001875C0(o->x38, D_001FD190, o->x3C, 0.9f, 0, col.w);
                break;
            }
        }
    }
}

