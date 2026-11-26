#include "common.h"
typedef union { u32 w; u8 c[4]; } Col;
typedef struct { s32 idx; u8 pad4[0x28]; f32 f2C; f32 f30; u8 pad34[8]; Col c; } Item;
typedef struct { u32 n; Item *items; } List;
typedef struct { u8 pad[4]; List *list; } Res;
typedef struct { s32 v[8]; } Tbl;
typedef struct { s32 x0; s32 x4; u8 x8; } Obj;
Res *func_00189050(s32);
s8 *func_00189020(s32);
void func_0018A310(s32);
void func_00181420(void);
void func_00182050(s32);
f32 func_00187770(f32, f32, f32);
void func_0018C140(f32 *, f32 *, Col *, f32);
void func_001829B0(Item *, s8 *, void (*)(), s32);
void func_0018BCC0();
void func_0017EDC0(s32, s32, s32, s32, s32);
extern Tbl D_001F2A30 __attribute__((aligned(16)));
extern f32 D_0020211C;
extern s32 D_004A0FF0[];
extern s32 D_004A0FFC[];
extern f32 D_004A1008[];
extern f32 D_004A100C[];
extern Flags8 D_004A1010[];

void func_0018B860(Obj *o) {
    f32 x;
    f32 y;
    Col c;
    Tbl tbl __attribute__((aligned(16)));
    Item it;
    List *l;
    s8 *base;
    s32 off;
    u32 j;
    s32 i;
    s32 v;
    s32 *p;
    s32 t;
    u32 k;

    tbl = D_001F2A30;
    l = func_00189050(4)->list;
    base = func_00189020(4);
    func_0018A310(8);
    func_00181420();
    if (o->x0 == 0x16) {
        D_004A1008[0] += 8.0f;
    }
    func_00182050((s32)D_004A1008[0]);
    switch (D_004A0FFC[0]) {
    case 1:
        D_0020211C = func_00187770(D_0020211C, 2.0f, 2.0f);
        if (D_004A100C[0] < 0.0f) {
            D_004A100C[0] = 10.0f;
            D_004A0FFC[0] = 10;
            D_004A0FF0[0] = 6;
            D_0020211C = 15.0f;
        } else {
            D_004A100C[0] -= 1.0f;
        }
        break;
    case 3:
        D_0020211C = func_00187770(D_0020211C, 13.0f, 2.0f);
        if (D_004A100C[0] < 0.0f) {
            D_004A100C[0] = 10.0f;
            D_0020211C = 0.0f;
            D_004A0FFC[0] = 10;
            D_004A0FF0[0] = 0;
        } else {
            D_004A100C[0] -= 1.0f;
        }
        break;
    case 10:
        D_0020211C = func_00187770(D_0020211C, D_004A0FF0[0] + 4, 5.0f);
        if (D_004A100C[0] < 0.0f) {
            D_004A0FFC[0] = 0;
            D_004A1010[0].f.b0 = 1;
        } else {
            D_004A100C[0] -= 1.0f;
        }
        break;
    default:
        D_0020211C = D_0020211C - (D_0020211C - (f32)(D_004A0FF0[0] + 4)) / 4.0f;
        break;
    }
    i = 0;
    v = (s32)D_0020211C;
    p = tbl.v;
    for (; i < 5; i++) {
        if (v - 5 >= 0 && v - 5 < 7) {
            *p = v - 5;
        } else {
            *p = -1;
        }
        v++;
        p++;
    }
    for (j = 0, off = 0; j < l->n; j++) {
        it = *(Item *)((s8 *)l->items + off);
        func_0018C140(&x, &y, &c, D_0020211C + (f32)(s32)j);
        it.f2C = x;
        it.f30 = y;
        it.c = c;
        t = tbl.v[((s32)D_0020211C + j) % l->n];
        if (t != -1) {
            func_001829B0(&it, base + it.idx * 8, func_0018BCC0, t);
        }
        off += 0x40;
    }
    func_0017EDC0(o->x8 == 0xB, D_004A1010[0].f.b1, 1, 7, D_004A0FF0[0]);
    func_00181420();
    func_00182050(0x80);
}
