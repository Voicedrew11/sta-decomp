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
f32 cosf(f32);
f32 sinf(f32);
s32 SndCh_IsPlaying_1_00131060(s32);
s32 Snd_PlaySeAttached_1_00131560(s32, s8, f32 *);
u32 Rand_Next_3_0015ED20(void);
extern f32 D_0026F090[];
extern f32 D_002F16C0[];

void SndEmit_UpdateAmbientRandom_1_00130090(S *o) {
    f32 d[4];
    f32 a;

    if (o->h == -1) {
        sceVu0ApplyMatrix(d, D_002F16C0, o->pos);
        a = sceVu0InnerProduct(d, d);
        if (a < o->r * o->r) {
            if (!(o->f10 <= 0.000015259022f * (f32)(Rand_Next_3_0015ED20() & 0xFFFF) + o->f14 * (0.000015259022f * (f32)(Rand_Next_3_0015ED20() & 0xFFFF) - 0.5f))) {
                a = 6.283184f * (0.000015259022f * (f32)(Rand_Next_3_0015ED20() & 0xFFFF) - 0.5f);
                o->v[0] = o->f18 * cosf(a);
                o->v[1] = o->pos[1];
                o->v[2] = o->f18 * sinf(a);
                o->v[3] = 1.0f;
                sceVu0ApplyMatrix(o->v, D_0026F090, o->v);
                o->h = Snd_PlaySeAttached_1_00131560(o->id, o->s1C, o->v);
            }
        }
    } else if (SndCh_IsPlaying_1_00131060(o->h) == 0) {
        o->h = -1;
    }
}
