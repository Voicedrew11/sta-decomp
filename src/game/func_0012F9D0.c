#include "m2c.h"
typedef struct { f32 x, y, z, w; } Vec;
typedef struct {
    Vec a;          /* 0x00 */
    Vec b;          /* 0x10 */
    u16 id;         /* 0x20 */
    u16 type;       /* 0x22 */
    f32 f24;        /* 0x24 */
    s32 f28;        /* 0x28 */
    s32 pad2c;
    u8 f30;
    u8 f31;
    u16 f32_;
    f32 s34, s38, s3c;
} Src;
typedef struct {
    s32 id;     /* 0 */
    s32 m1;     /* 4 */
    f32 f8;     /* 8 */
    s32 fc;     /* c */
    f32 f10;    /* 10 */
    s32 f14;    /* 14 */
    s32 f18;    /* 18 */
    u8 f1c;     /* 1c */
    s8 used;    /* 1d */
    u16 type;   /* 1e */
    Vec v20;    /* 20 */
    Vec v30;    /* 30 */
    f32 s40, s44, s48;
    s32 pad4c;
} Obj;
extern Obj D_0026F0D0[];
void func_00102A60(Vec *, Vec *);
void func_001029D0(Vec *, Vec *, Vec *);

void func_0012F9D0(s8 *arg0) {
    Src *s;
    Obj *o;
    s32 i;
    s32 j;
    for (i = 0; i < *(u16 *)(arg0 + 0x7A); i++) {
        s = &(*(Src **)(arg0 + 0x14C))[i];
        o = NULL;
        for (j = 0; j < 0x40; j++) {
            if (D_0026F0D0[j].used == 0) { o = &D_0026F0D0[j]; break; }
        }

        if (o == NULL) return;
        o->id = s->id;
        o->m1 = -1;
        o->f8 = s->a.w;
        if (s->type == 2 || s->type == 3) {
            o->f14 = s->f32_;
            o->f18 = -1;
        } else {
            *(f32 *)&o->f18 = *(f32 *)&s->f28;
            *(f32 *)&o->f14 = s->b.w;
        }
        o->f10 = s->f24;
        o->f1c = s->f30;
        func_00102A60(&o->v20, &s->a);
        func_001029D0(&o->v20, &o->v20, (Vec *)(arg0 + 0x10));
        func_00102A60(&o->v30, &s->b);
        o->v20.w = 1.0f;
        o->v30.w = 1.0f;
        o->type = s->type;
        o->fc = s->f31;
        o->s40 = 0.5f * s->s34;
        o->s44 = 0.5f * s->s38;
        o->s48 = 0.5f * s->s3c;
        o->used = 1;
    }
}
