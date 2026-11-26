#include "actor.h"
typedef struct { f32 m[4][4]; } MtxF;
typedef struct {
    u8 pad0[0x10];
    s8 *x10;
    u8 pad14[4];
    s8 *o;
    u8 pad1C[0x40 - 0x1C];
    Vec pos;
    u8 pad50[0xB0 - 0x50];
    Vec vB0;
    Vec vC0;
    MtxF mD0;
    Vec v110;
    Vec v120;
    Vec m130;
    Vec v140;
    u8 pad150[4];
    s32 x154;
    u8 pad158[0x3A2 - 0x158];
    u8 b0:1; u8 b1:7;
} P;
extern s32 D_00201E80;
extern s32 D_002022BC;
extern s32 D_002022D8;
void sceVu0CopyVector(Vec *, Vec *);
void memset(void *, s32, s32);
void sceVu0SubVector(Vec *, Vec *, void *);
void sceVu0AddVector(Vec *, void *, Vec *);
void func_00102870(Vec *, Vec *);
void sceVu0ScaleVector(Vec *, Vec *, f32);
f32 func_0015DEE0(Vec *, void *);
f32 func_0015DF50(Vec *, void *);
s32 func_001B34B0(s8 *, Vec *, Vec *, s32, s32);
s32 func_001B2B90(s8 *, Vec *, Vec *, u16, s32, s32);
s32 func_001B3240(s8 *, Vec *, Vec *, s32, s32);
s32 func_001B2800(s8 *, Vec *, Vec *, u16, s32, s32);

void func_001C5150(Actor *a) {
    P *p;
    s32 close;
    s32 hit;
    s32 i1; s8 ***q1; s32 j2; s8 *n2; s8 ***q2; s32 i2; s8 ***q3; s32 i3; s8 *n4; s8 ***q4; s32 i4; s32 j4;
    f32 d;
    f32 t;
    f32 end;
    Vec v;
    Vec dir;

    p = (P *)(a->unk518 + 0x180);
    if (D_002022BC == (&D_00201E80)[2]) D_002022D8 = 0;
    if (D_002022BC == (&D_00201E80)[3]) D_002022D8 = 1;
    memset(&p->m130, 0, 0x40);
    close = 0;
    sceVu0SubVector(&dir, &p->pos, p->o + 0x10);
    func_00102870(&dir, &dir);
    if (func_0015DEE0(&p->pos, p->o + 0x10) < 20.0f && !p->b0) close = 1;
    d = func_0015DF50(&p->pos, p->o + 0x10);
    if (close) t = d; else t = 20.0f;
    for (end = 20.0f + d; t < end; t += 20.0f) {
        if (!(t <= d)) t = d;
        sceVu0ScaleVector(&v, &dir, t);
        sceVu0AddVector(&p->v110, p->o + 0x10, &v);
        p->v110.y = p->v110.y + 220.0f;
        p->v110.y = p->v110.y - 100.0f;
        p->v110.w = 100.0f;
        hit = 0;
        for (i1 = 0, q1 = (s8 ***)(&D_00201E80 + 2); i1 < 2; i1++, q1++) {
            if (*q1 != 0 && **q1 != 0 && func_001B34B0(**q1, &p->m130, &p->v110, 3, 0)) hit = 1;
        }
        for (i2 = 0, q2 = (s8 ***)(&D_00201E80 + 2); i2 < 2; i2++, q2++) {
            if (*q2 != 0 && (n2 = **q2) != 0) {
                for (j2 = 0; j2 < *(u16 *)(n2 + 0x6E); j2++) {
                    if (func_001B2B90(n2, &p->m130, &p->v110, j2, 3, 0)) hit = 1;
                }
            }
        }
        if (hit) break;
    }
    if (p->x154) {
        sceVu0ScaleVector(&p->vB0, &p->v140, 100.0f);
        sceVu0AddVector(&p->vB0, &p->vB0, &p->m130);
        p->vB0.w = 1.0f;
        sceVu0CopyVector(&p->vC0, &p->vB0);
        p->vB0.y = *(f32 *)(p->x10 + 0x14);
        p->vB0.y = p->vB0.y + 220.0f;
        p->vB0.y = p->vB0.y - 80.0f;
        p->vC0.y = p->vC0.y + 103.0f;
    } else {
        sceVu0CopyVector(&p->vB0, &p->pos);
        p->vB0.w = 1.0f;
        sceVu0CopyVector(&p->vC0, &p->pos);
        p->vC0.w = 1.0f;
        p->vB0.y = *(f32 *)(p->x10 + 0x14);
        p->vB0.y = p->vB0.y + 220.0f;
        p->vB0.y = p->vB0.y - 80.0f;
        p->vC0.y = p->vC0.y + 223.0f;
    }
    memset(&p->mD0, 0, 0x40);
    for (i3 = 0, q3 = (s8 ***)(&D_00201E80 + 2); i3 < 2; i3++, q3++) {
        if (*q3 != 0 && **q3 != 0) func_001B3240(**q3, (Vec *)&p->mD0, &p->vB0, 4, 0);
    }
    for (i4 = 0, q4 = (s8 ***)(&D_00201E80 + 2); i4 < 2; i4++, q4++) {
        if (*q4 != 0 && (n4 = **q4) != 0) {
            for (j4 = 0; j4 < *(u16 *)(n4 + 0x6E); j4++) {
                func_001B2800(n4, (Vec *)&p->mD0, &p->vB0, j4, 4, 0);
            }
        }
    }
}
