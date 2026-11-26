#include "m2c.h"
typedef struct {
    s32 id;     /* 0x00 */
    s32 h;      /* 0x04 */
    f32 r;      /* 0x08 */
    f32 pad0C;
    f32 f10;    /* 0x10 */
    f32 f14;    /* 0x14 */
    f32 f18;    /* 0x18 */
    s8 s1C;     /* 0x1C */
    f32 pos[4]; /* 0x20 */
    f32 v[4];   /* 0x30 */
} S;
void sceVu0ApplyMatrix(f32 *, f32 *, f32 *);
f32 sceVu0InnerProduct(f32 *, f32 *);
s32 func_00131560(s32, s8, f32 *);
void func_001314A0(s32);
void func_001312C0(s32, f32);
void func_00131250(s32, f32);
void func_00131180(s32, f32 *);
void func_001311E0(s32, f32 *);
extern f32 D_002F16C0[];

void func_001302A0(S *o) {
    f32 d[4];
    f32 t[2];
    f32 a;

    if (o->h != -1) {
        sceVu0ApplyMatrix(d, D_002F16C0, o->pos);
        a = sceVu0InnerProduct(d, d);
        if (!(a <= (o->r + o->f10) * (o->r + o->f10))) {
            func_001314A0(o->h);
            o->h = -1;
        }
    } else {
        sceVu0ApplyMatrix(d, D_002F16C0, o->pos);
        a = sceVu0InnerProduct(d, d);
        if (a < (o->r + o->f10) * (o->r + o->f10)) {
            o->h = func_00131560(o->id, o->s1C, o->pos);
            if (o->h != -1) {
                func_001312C0(o->h, o->f14);
                func_00131250(o->h, o->f18);
                t[0] = o->r;
                t[1] = o->f10;
                func_00131180(o->h, t);
                func_001311E0(o->h, o->v);
            }
        }
    }
}
