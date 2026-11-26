#include "common.h"
typedef struct { Vec a; Vec b; Vec c; f32 x30; f32 x34; u8 x38; u8 pad[7]; } EA;
typedef struct { Vec a; f32 x10; f32 x14; f32 x18; u8 b1C; u8 b1D; u8 b1E; u8 b1F; u16 h20; u8 b22; u8 used; u8 pad[0xC]; } EB;
typedef struct {
    s32 id;
    u8 pad4[0xC];
    Vec pos;
    u8 pad20[0x5C];
    u16 x7C;
    u16 x7E;
    u8 pad80[0xE8];
    EA *x168;
    EB *x16C;
    u8 pad170[0x68];
    Flags8 x1D8;
} S;
typedef struct { u8 pad0[0x10]; s32 x10; u8 pad14[4]; S **x18; u8 pad1C[4]; } Info;
typedef struct { u16 key; s16 x; s16 y; s16 z; } K;
extern s32 D_00201E80;
#define PP(i) (((S ***)(&D_00201E80 + 2))[i])
extern s32 D_002022C0;
extern Vec D_004B4BD0;
void sceVu0CopyVector(Vec *, Vec *);
void sceVu0AddVector(Vec *, Vec *, Vec *);
s32 func_001B0660(Info *);
void func_001B06E0(u16, Vec *, s32);
void func_001B0450(void);
void func_001B03E0(void);
void func_001B5640(S **);
void func_0015B890(s32);
void func_0015C6D0(s32);
s32 func_0015B980(s32 idx, Vec *a, Vec *b, Vec *c, f32 f0, f32 f1, f32 f2, f32 f3);
s32 func_0015C730(s32 idx, Vec *v, f32 f0, f32 f1, f32 f2, f32 f3, u8 c0, u8 c1, u8 c2, u8 c3, u16 h, u8 c4);

void func_001B51F0(S *a0, K *k, s32 a2) {
    Info info;
    Vec v;
    Vec b0;
    Vec t;
    Vec b1;
    Vec t2;
    s16 side;
    S *o2;
    s32 r;
    s32 cur;
    EB *e2;
    f32 w;
    s32 j;
    EA *e;
    s32 i;
    S *o;
    s16 n;

    if (a0->id == k->key) return;
    side = -1;
    if (((S **)(&D_00201E80)[2]) && *((S **)(&D_00201E80)[2]) == a0) side = 0;
    if (((S **)(&D_00201E80)[3]) && *((S **)(&D_00201E80)[3]) == a0) side = 1;
    n = !side;
    if ((&D_00201E80)[1] != n && PP(side)) {
        sceVu0CopyVector(&v, &(*PP(side))->pos);
        if (v.x != 0.0f || v.y != 0.0f || v.z != 0.0f) {
            D_002022C0 = 1;
            v.w = 0.0f;
            sceVu0CopyVector(&D_004B4BD0, &v);
        }
    }
    if (((S **)(&D_00201E80)[2])) sceVu0CopyVector(&v, &(*((S **)(&D_00201E80)[2]))->pos);
    if (((S **)(&D_00201E80)[3])) sceVu0CopyVector(&v, &(*((S **)(&D_00201E80)[3]))->pos);
    cur = n;
    (&D_00201E80)[1] = cur;
    v.x = -1.0f * k->x;
    v.y = -1.0f * k->y;
    v.z = -1.0f * k->z;
    v.w = 0.0f;
    if (PP(n)) {
        o = *PP(n);
        if (o->id == k->key) return;
        if (!o->x1D8.f.b3) {
            o->x1D8.f.b3 = 1;
            return;
        }
        func_0015B890(cur);
        func_0015C6D0(cur);
        func_001B5640(PP(n));
        PP(n) = 0;
        return;
    }
    r = func_001B0660(&info);
    if (info.x10 != -1) {
        if (info.x10 == k->key) {
            if (a2 != 0 && (u8)r != 0 && (u8)r != 2) {
                func_001B0450();
                    PP(n) = info.x18;
                    o = *PP(n);
                    sceVu0CopyVector(&b0, &o->pos);
                    func_0015B890(cur);
                    for (i = 0; i < o->x7C; i++) {
                        e = &o->x168[i];
                        if (e->x38 == 0) {
                            sceVu0CopyVector(&t, &e->a);
                            sceVu0AddVector(&t, &t, &b0);
                            t.w = e->a.w;
                            func_0015B980(cur, &t, &e->b, &e->c, t.w, e->b.w, e->x30, e->x34);
                        }
                    }
                    o2 = *PP(n);
                    sceVu0CopyVector(&b1, &o2->pos);
                    func_0015C6D0(cur);
                    for (j = 0; j < o2->x7E; j++) {
                        e2 = &o2->x16C[j];
                        sceVu0CopyVector(&t2, &e2->a);
                        sceVu0AddVector(&t2, &t2, &b1);
                        t2.w = e2->a.w;
                        func_0015C730(cur, &t2, t2.w, e2->x18, e2->x10, e2->x14, e2->b1C, e2->b1D, e2->b1E, e2->b1F, e2->h20, e2->b22);
                    }
            }
        } else {
            func_001B5640(info.x18);
            info.x18 = 0;
            func_001B03E0();
        }
    } else {
        func_001B06E0(k->key, &v, 0);
    }
}
