#include "common.h"
#include "m2c.h"
typedef struct { s32 a; s32 b; char p8[0x10]; s32 x18; char p1c[2]; s16 h1e; char p20[0x30]; } E_SndEmit_StopAllA_1_0012F640;
typedef struct { u8 pad[0x1D]; s8 b1D; s16 h1E; u8 pad2[0x30]; } S_SndEmit_Update_1_0012F6F0;
typedef struct { char p0[0x1D]; s8 b1d; s16 h1e; f32 v20[4]; f32 v30[4]; char p40[0x10]; } E_SndEmit_OffsetPositions_1_0012F7E0;
typedef struct { s32 a; s32 b; char p8[0x10]; s32 x18; char p1c; u8 b1d; s16 h1e; char p20[0x30]; } E_SndEmit_StopAllB_1_0012F880;
typedef struct { s32 a; s32 b; char p8[0x10]; s32 x18; char p1c; u8 b1d; s16 h1e; char p20[0x30]; } E_SndEmit_KillAll_1_0012F920;
typedef struct {
    Vec a;
    Vec b;
    u16 id;
    u16 type;
    f32 f24;
    s32 f28;
    s32 pad2c;
    u8 f30;
    u8 f31;
    u16 f32_;
    f32 s34, s38, s3c;
} Src;
typedef struct {
    s32 id;
    s32 m1;
    f32 f8;
    s32 fc;
    f32 f10;
    s32 f14;
    s32 f18;
    u8 f1c;
    s8 used;
    u16 type;
    Vec v20;
    Vec v30;
    f32 s40, s44, s48;
    s32 pad4c;
} Obj;
typedef struct { s32 a; s32 b; s32 x8; char pc[4]; s32 x10; s32 x14; s32 x18; u8 b1c; u8 b1d; s16 h1e; f32 v20[4]; f32 v30[4]; char p40[0x10]; } E_SndEmit_Init_1_0012FB80;
typedef struct {
    s32 id;
    s32 h;
    f32 r;
    s32 xC;
    f32 f10;
    s32 id2;
    s32 h2;
    s8 s1C;
    u8 pad1D;
    s16 x1E;
    f32 pos[4];
    f32 pad30[4];
    f32 box[4];
} S_SndEmit_Update3D_1_0012FC20;
typedef struct {
    s32 id;
    s32 h;
    f32 r;
    f32 pad0C;
    f32 f10;
    f32 f14;
    f32 f18;
    s8 s1C;
    f32 pos[4];
    f32 v[4];
} S_SndEmit_UpdateAmbientRandom_1_00130090;
typedef struct {
    s32 id;
    s32 h;
    f32 r;
    f32 pad0C;
    f32 f10;
    f32 f14;
    f32 f18;
    s8 s1C;
    f32 pos[4];
    f32 v[4];
} S_SndEmit_UpdateLooping_1_001302A0;
extern E_SndEmit_StopAllA_1_0012F640 D_0026F0D0[64];
extern s8 D_00201C38;
extern s32 D_00201ED8;
extern f32 D_0026F090[];
extern f32 D_002F16C0[];
extern f32 D_001F2160[4];
void SndEmit_StopAllA_1_0012F640(void);
void SndEmit_SetEnabled_0_0012F6E0(s8 arg0);
void SndEmit_Update_1_0012F6F0(void);
void SndEmit_OffsetPositions_1_0012F7E0(f32 *v);
void SndEmit_StopAllB_1_0012F880(void);
void SndEmit_KillAll_1_0012F920(void);
void SndEmit_SpawnFromMap_0_0012F9D0(s8 *arg0);
void SndEmit_Init_1_0012FB80(void);
void SndEmit_Update3D_1_0012FC20(S_SndEmit_Update3D_1_0012FC20 *o);
void SndEmit_UpdateAmbientRandom_1_00130090(S_SndEmit_UpdateAmbientRandom_1_00130090 *o);
void SndEmit_UpdateLooping_1_001302A0(S_SndEmit_UpdateLooping_1_001302A0 *o);
void SndCh_Stop_2_00131440(s32 h);
void sceVu0InversMatrix(void *, void *);
void sceVu0AddVector(void *, void *, void *);
void SndCh_OffsetPositions_1_0012C440(f32 *v);
void SndCh_StopNow_1_001314A0(s32 h);
void sceVu0CopyVector(void *, void *);
f32 sqrtf(f32);
void sceVu0ApplyMatrix(f32 *, f32 *, f32 *);
f32 sceVu0InnerProduct(f32 *, f32 *);
f32 fabsf(f32);
f32 expf(f32);
s32 Snd_PlaySe_3_00131600(s32, s8);
void SndCh_SetPitch_1_00131130(s32, s32);
void SndCh_SetVolume_2_001310B0(s32, s16);
s32 SndCh_IsPlaying_1_00131060(s32);
f32 cosf(f32);
f32 sinf(f32);
s32 Snd_PlaySeAttached_1_00131560(s32, s8, f32 *);
u32 Rand_Next_3_0015ED20(void);
void SndCh_SetFalloff_0_001312C0(s32, f32);
void SndCh_SetRange_0_00131250(s32, f32);
void SndCh_GetPosition_1_00131180(s32, f32 *);
void SndCh_SetPosition_2_001311E0(s32, f32 *);

/* SndEmit_StopAllA_1_0012F640 */
void SndEmit_StopAllA_1_0012F640(void)
{
    s32 n = 64;
    E_SndEmit_StopAllA_1_0012F640 *e = D_0026F0D0;
    while (n--) {
        if (e->b != -1) {
            SndCh_Stop_2_00131440(e->b);
            e->b = -1;
        }
        if (e->h1e == 2 || e->h1e == 3) {
            SndCh_Stop_2_00131440(e->x18);
            e->x18 = -1;
        }
        e++;
    }
}

/* SndEmit_SetEnabled_0_0012F6E0 */
void SndEmit_SetEnabled_0_0012F6E0(s8 arg0) {
    D_00201C38 = arg0;
}

/* SndEmit_Update_1_0012F6F0 */
#define SndEmit_Update3D_1_0012FC20 SndEmit_Update3D_1_0012FC20__as_SndEmit_Update_1_0012F6F0
void SndEmit_Update3D_1_0012FC20__as_SndEmit_Update_1_0012F6F0(S_SndEmit_Update_1_0012F6F0 *);
#define SndEmit_UpdateAmbientRandom_1_00130090 SndEmit_UpdateAmbientRandom_1_00130090__as_SndEmit_Update_1_0012F6F0
void SndEmit_UpdateAmbientRandom_1_00130090__as_SndEmit_Update_1_0012F6F0(S_SndEmit_Update_1_0012F6F0 *);
#define SndEmit_UpdateLooping_1_001302A0 SndEmit_UpdateLooping_1_001302A0__as_SndEmit_Update_1_0012F6F0
void SndEmit_UpdateLooping_1_001302A0__as_SndEmit_Update_1_0012F6F0(S_SndEmit_Update_1_0012F6F0 *);
#define D_00201C38 D_00201C38__as_SndEmit_Update_1_0012F6F0
extern u8 D_00201C38__as_SndEmit_Update_1_0012F6F0;
#define D_0026F0D0 D_0026F0D0__as_SndEmit_Update_1_0012F6F0
extern S_SndEmit_Update_1_0012F6F0 D_0026F0D0__as_SndEmit_Update_1_0012F6F0[];

void SndEmit_Update_1_0012F6F0(void) {
    S_SndEmit_Update_1_0012F6F0 *p;
    s32 n;

    if (D_00201ED8 != 0) {
        D_00201ED8 = 0;
        return;
    }
    if (D_00201C38 != 0) {
        sceVu0InversMatrix(D_0026F090, D_002F16C0);
        n = 0x40;
        p = D_0026F0D0;
        while (n--) {
            if (p->b1D) {
                if (p->h1E == 0) SndEmit_UpdateLooping_1_001302A0(p);
                else if (p->h1E == 1) SndEmit_UpdateAmbientRandom_1_00130090(p);
                else if (p->h1E == 2 || p->h1E == 3) SndEmit_Update3D_1_0012FC20(p);
            }
            p++;
        }
    }
}
#undef SndEmit_Update3D_1_0012FC20
#undef SndEmit_UpdateAmbientRandom_1_00130090
#undef SndEmit_UpdateLooping_1_001302A0
#undef D_00201C38
#undef D_0026F0D0

/* SndEmit_OffsetPositions_1_0012F7E0 */
#define D_0026F0D0 D_0026F0D0__as_SndEmit_OffsetPositions_1_0012F7E0
extern E_SndEmit_OffsetPositions_1_0012F7E0 D_0026F0D0__as_SndEmit_OffsetPositions_1_0012F7E0[64];
#define sceVu0AddVector sceVu0AddVector__as_SndEmit_OffsetPositions_1_0012F7E0
void sceVu0AddVector__as_SndEmit_OffsetPositions_1_0012F7E0(f32 *v0, f32 *v1, f32 *v2);

void SndEmit_OffsetPositions_1_0012F7E0(f32 *v)
{
    s32 n = 64;
    E_SndEmit_OffsetPositions_1_0012F7E0 *e = D_0026F0D0;
    while (n--) {
        if (e->b1d) {
            sceVu0AddVector(e->v20, e->v20, v);
            if (e->h1e == 1)
                sceVu0AddVector(e->v30, e->v30, v);
        }
        e++;
    }
    SndCh_OffsetPositions_1_0012C440(v);
    D_00201ED8 = 1;
}
#undef sceVu0AddVector
#undef D_0026F0D0

/* SndEmit_StopAllB_1_0012F880 */
#define D_0026F0D0 D_0026F0D0__as_SndEmit_StopAllB_1_0012F880
extern E_SndEmit_StopAllB_1_0012F880 D_0026F0D0__as_SndEmit_StopAllB_1_0012F880[64];

void SndEmit_StopAllB_1_0012F880(void)
{
    s32 n = 64;
    E_SndEmit_StopAllB_1_0012F880 *e = D_0026F0D0;
    while (n--) {
        if (e->b != -1) {
            SndCh_Stop_2_00131440(e->b);
            e->b = -1;
        }
        if (e->h1e == 2 || e->h1e == 3) {
            SndCh_Stop_2_00131440(e->x18);
            e->x18 = -1;
        }
        e->b1d = 0;
        e++;
    }
}
#undef D_0026F0D0

/* SndEmit_KillAll_1_0012F920 */
#define D_0026F0D0 D_0026F0D0__as_SndEmit_KillAll_1_0012F920
extern E_SndEmit_KillAll_1_0012F920 D_0026F0D0__as_SndEmit_KillAll_1_0012F920[64];

void SndEmit_KillAll_1_0012F920(void)
{
    s32 n = 64;
    E_SndEmit_KillAll_1_0012F920 *e = D_0026F0D0;
    while (n--) {
        if (e->b != -1) {
            SndCh_StopNow_1_001314A0(e->b);
            e->b = -1;
        }
        if ((e->h1e == 2 || e->h1e == 3) && e->h1e != -1) {
            SndCh_StopNow_1_001314A0(e->x18);
            e->x18 = -1;
        }
        e->b1d = 0;
        e++;
    }
}
#undef D_0026F0D0

/* SndEmit_SpawnFromMap_0_0012F9D0 */
#define D_0026F0D0 D_0026F0D0__as_SndEmit_SpawnFromMap_0_0012F9D0
extern Obj D_0026F0D0__as_SndEmit_SpawnFromMap_0_0012F9D0[];
#define sceVu0CopyVector sceVu0CopyVector__as_SndEmit_SpawnFromMap_0_0012F9D0
void sceVu0CopyVector__as_SndEmit_SpawnFromMap_0_0012F9D0(Vec *, Vec *);
#define sceVu0AddVector sceVu0AddVector__as_SndEmit_SpawnFromMap_0_0012F9D0
void sceVu0AddVector__as_SndEmit_SpawnFromMap_0_0012F9D0(Vec *, Vec *, Vec *);

void SndEmit_SpawnFromMap_0_0012F9D0(s8 *arg0) {
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
        sceVu0CopyVector(&o->v20, &s->a);
        sceVu0AddVector(&o->v20, &o->v20, (Vec *)(arg0 + 0x10));
        sceVu0CopyVector(&o->v30, &s->b);
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
#undef sceVu0CopyVector
#undef sceVu0AddVector
#undef D_0026F0D0

/* SndEmit_Init_1_0012FB80 */
#define D_0026F0D0 D_0026F0D0__as_SndEmit_Init_1_0012FB80
extern E_SndEmit_Init_1_0012FB80 D_0026F0D0__as_SndEmit_Init_1_0012FB80[64];
#define sceVu0CopyVector sceVu0CopyVector__as_SndEmit_Init_1_0012FB80
void sceVu0CopyVector__as_SndEmit_Init_1_0012FB80(f32 *v0, f32 *v1);

void SndEmit_Init_1_0012FB80(void)
{
    s32 n = 64;
    E_SndEmit_Init_1_0012FB80 *e = D_0026F0D0;
    while (n--) {
        e->a = -1;
        e->b = -1;
        e->x18 = 0;
        e->x14 = 0;
        e->x10 = 0;
        e->x8 = 0;
        e->b1c = 0;
        e->b1d = 0;
        e->h1e = 0;
        sceVu0CopyVector(e->v20, D_001F2160);
        sceVu0CopyVector(e->v30, D_001F2160);
        e++;
    }
}
#undef sceVu0CopyVector
#undef D_0026F0D0

/* SndEmit_Update3D_1_0012FC20 */
void SndEmit_Update3D_1_0012FC20(S_SndEmit_Update3D_1_0012FC20 *o) {
    f32 d[4];
    f32 e[4];
    f32 w[4];
    s32 in;
    s16 vol;
    f32 dist;
    f32 g;
    f32 ex;
    f32 v;
    f32 dd;

    sceVu0ApplyMatrix(d, D_002F16C0, o->pos);
    if (o->xC == 0) {
        dist = sceVu0InnerProduct(d, d);
        g = o->r + o->f10;
        in = dist < g * g;
    } else {
        sceVu0ApplyMatrix(e, D_0026F090, D_001F2160);
        d[0] = fabsf(o->pos[0] - e[0]);
        d[1] = fabsf(o->pos[1] - e[1]);
        d[2] = fabsf(o->pos[2] - e[2]);
        if (d[0] <= o->box[0] + o->f10 && d[1] <= o->box[1] + o->f10 && d[2] <= o->box[2] + o->f10) {
            in = 1;
        } else {
            in = 0;
        }
    }
    if (o->x1E == 3) {
        if (o->xC == 0) {
            if (in) {
                dist = sqrtf(sceVu0InnerProduct(d, d));
                ex = o->r;
                if (!(dist <= ex)) {
                    ex = dist - ex;
                    g = 0.0f;
                    if (!(o->f10 <= g)) g = expf(-4.84418678f / o->f10 * ex);
                    vol = (s32)(o->s1C * g);
                } else {
                    vol = o->s1C;
                }
            }
        } else {
            if (in) {
                w[0] = d[0] > o->box[0] ? d[0] - o->box[0] : 0.0f;
                w[1] = d[1] > o->box[1] ? d[1] - o->box[1] : 0.0f;
                w[2] = d[2] > o->box[2] ? d[2] - o->box[2] : 0.0f;
                w[3] = 1.0f;
                dd = sqrtf(sceVu0InnerProduct(w, w));
                if (!(o->f10 <= dd)) {
                    if (!(o->f10 <= 0.0f)) expf(-4.84418678f / o->f10 * dd);
                } else {
                    vol = o->s1C;
                }
            }
        }
    }
    if (o->h == -1) {
        if (in) {
            o->h = Snd_PlaySe_3_00131600(o->id, o->s1C);
            if (o->x1E == 2) {
                SndCh_SetPitch_1_00131130(o->h, 0);
                SndCh_SetVolume_2_001310B0(o->h, -1);
            } else {
                SndCh_SetVolume_2_001310B0(o->h, vol);
            }
        }
    } else {
        if (!in) {
            SndCh_Stop_2_00131440(o->h);
            o->h = -1;
        }
        if (SndCh_IsPlaying_1_00131060(o->h) == 0) {
            o->h = -1;
        } else {
            SndCh_SetVolume_2_001310B0(o->h, vol);
        }
    }
    if (o->h2 == -1) {
        if (in) {
            o->h2 = Snd_PlaySe_3_00131600(o->id2, o->s1C);
            if (o->x1E == 2) {
                SndCh_SetPitch_1_00131130(o->h2, 0);
                SndCh_SetVolume_2_001310B0(o->h2, -1);
            } else {
                SndCh_SetVolume_2_001310B0(o->h2, vol);
            }
        }
    } else {
        if (!in) {
            SndCh_Stop_2_00131440(o->h2);
            o->h2 = -1;
        }
        if (SndCh_IsPlaying_1_00131060(o->h2) == 0) {
            o->h2 = -1;
        } else {
            SndCh_SetVolume_2_001310B0(o->h2, vol);
        }
    }
}

/* SndEmit_UpdateAmbientRandom_1_00130090 */
void SndEmit_UpdateAmbientRandom_1_00130090(S_SndEmit_UpdateAmbientRandom_1_00130090 *o) {
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

/* SndEmit_UpdateLooping_1_001302A0 */
void SndEmit_UpdateLooping_1_001302A0(S_SndEmit_UpdateLooping_1_001302A0 *o) {
    f32 d[4];
    f32 t[2];
    f32 a;

    if (o->h != -1) {
        sceVu0ApplyMatrix(d, D_002F16C0, o->pos);
        a = sceVu0InnerProduct(d, d);
        if (!(a <= (o->r + o->f10) * (o->r + o->f10))) {
            SndCh_StopNow_1_001314A0(o->h);
            o->h = -1;
        }
    } else {
        sceVu0ApplyMatrix(d, D_002F16C0, o->pos);
        a = sceVu0InnerProduct(d, d);
        if (a < (o->r + o->f10) * (o->r + o->f10)) {
            o->h = Snd_PlaySeAttached_1_00131560(o->id, o->s1C, o->pos);
            if (o->h != -1) {
                SndCh_SetFalloff_0_001312C0(o->h, o->f14);
                SndCh_SetRange_0_00131250(o->h, o->f18);
                t[0] = o->r;
                t[1] = o->f10;
                SndCh_GetPosition_1_00131180(o->h, t);
                SndCh_SetPosition_2_001311E0(o->h, o->v);
            }
        }
    }
}
