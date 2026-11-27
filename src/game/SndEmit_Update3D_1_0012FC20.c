#include "m2c.h"
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
} S;
f32 sqrtf(f32);
void sceVu0ApplyMatrix(f32 *, f32 *, f32 *);
f32 sceVu0InnerProduct(f32 *, f32 *);
f32 fabsf(f32);
f32 expf(f32);
s32 Snd_PlaySe_3_00131600(s32, s8);
void SndCh_SetPitch_1_00131130(s32, s32);
void SndCh_SetVolume_2_001310B0(s32, s16);
void SndCh_Stop_2_00131440(s32);
s32 SndCh_IsPlaying_1_00131060(s32);
extern f32 D_0026F090[];
extern f32 D_002F16C0[];
extern f32 D_001F2160[];

void SndEmit_Update3D_1_0012FC20(S *o) {
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
