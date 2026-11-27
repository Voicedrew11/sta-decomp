#include "common.h"
typedef union { u128 q; u32 w[4]; } Q;
typedef struct { Vec amb; Vec dir[4]; Vec col[4]; Vec x90; } L;
typedef struct {
    u8 pad0[4];
    s32 x4;
    u8 pad8[8];
    L x10;
} O;
extern s32 D_00201F2C;
extern s32 D_00201FF0;
void sceVu0CopyVector(Vec *, void *);
void sceVu0AddVector(Vec *, Vec *, Vec *);
void sceVu0SubVector(Vec *, void *, Vec *);
f32 sceVu0InnerProduct(Vec *, Vec *);
void sceVu0Normalize(Vec *, Vec *);
void sceVu0ScaleVector(Vec *, void *, f32);
s32 Glow_FindNear_0_0015DA00(s64, u8, s32 *, Vec *, s32);
void Glow_DrawList_0_0015D900(s32, s32 *);
s8 *TextColour_Get_1_0015D580(s32);
Q *GsPkt_Alloc_3_00154A80(s32);

void Mdl_DrawLit_0_0016B970(O *o, L *m, Vec *v, s8 *a3, s32 t0, s32 t1, s32 t2) {
    s32 buf[12];
    Vec p;
    Vec d;
    Q tag;
    Q tag2;
    L *dst;
    s32 n;
    u32 cnt;
    s32 k;
    s32 *b;
    s32 idx;
    s8 *e;
    f32 dot;
    f32 w;
    f32 r;
    f32 f;
    s32 fl;
    Q *q;

    if (t0 != 0 || t1 != 0) {
        sceVu0CopyVector(&p, a3 + 0x30);
        p.w = 0.0f;
        sceVu0AddVector(&p, &p, v);
        if (t0) {
            cnt = o->x4 = Glow_FindNear_0_0015DA00(0xFFFF, t0, buf, &p, 0);
        } else {
            cnt = o->x4 = Glow_FindNear_0_0015DA00(0xFFFF, t1, buf, &p, 0);
        }
        if (cnt != 0) {
            if (t0) {
                Glow_DrawList_0_0015D900(cnt, buf);
            } else {
                dst = m ? m : &o->x10;
                if ((u8)t1 < cnt) cnt = (u8)t1;
                o->x4 = 0;
                for (k = 0; k < (n = cnt); k++) {
                    e = TextColour_Get_1_0015D580(buf[k]);
                    r = *(f32 *)(e + 0x54);
                    w = -((Vec *)(e + (D_00201F2C << 5)))->w;
                    sceVu0SubVector(&d, e + (D_00201F2C << 5), &p);
                    d.w = 0.0f;
                    dot = sceVu0InnerProduct(&d, &d);
                    sceVu0Normalize(&d, &d);
                    idx = 4 - (u8)t1 + k;
                    sceVu0CopyVector(&dst->dir[idx], &d);
                    f = w * (r * r - dot);
                    if (f < 0.0f) f = 0.0f;
                    f = f * f;
                    f = f * f;
                    sceVu0ScaleVector(&dst->col[idx], e + (D_00201F2C << 5) + 0x10, f);
                    dst->dir[idx].w = *(f32 *)(e + 0x58);
                }
            }
        }
    }
    if (m != NULL) {
        fl = t2 & 1;
        q = GsPkt_Alloc_3_00154A80(fl ? 0xD : 3);
        tag.w[0] = 0x10000001;
        tag.w[1] = 0;
        tag.w[2] = 0x10000000;
        tag.w[3] = 0x6C01002A;
        q[0].q = tag.q;
        q[1].q = *(u128 *)o;
        if (fl) {
            tag.q = 0;
            tag.w[0] = 0x1000000A;
            tag.w[3] = 0x6C0A002B;
            q[2].q = tag.q;
            q[3].q = ((Q *)m)[0].q;
            q[4].q = ((Q *)m)[1].q;
            q[5].q = ((Q *)m)[2].q;
            q[6].q = ((Q *)m)[3].q;
            q[7].q = ((Q *)m)[4].q;
            q[8].q = ((Q *)m)[5].q;
            q[9].q = ((Q *)m)[6].q;
            q[10].q = ((Q *)m)[7].q;
            q[11].q = ((Q *)m)[8].q;
            q[12].q = ((Q *)m)[9].q;
        } else {
            tag.w[0] = 0x3000000A;
            tag.w[1] = (u32)m;
            tag.w[2] = 0;
            tag.w[3] = 0x6C0A002B;
            q[2].q = tag.q;
        }
        D_00201FF0 = (s32)m;
    } else {
        q = GsPkt_Alloc_3_00154A80(1);
        tag2.w[0] = 0x3000000B;
        tag2.w[1] = (u32)((s8 *)o + *(s32 *)((s8 *)o + 0xB0));
        tag2.w[2] = 0x10000000;
        tag2.w[3] = 0x6C0B002A;
        q[0].q = tag2.q;
        D_00201FF0 = tag2.w[1] + 0x10;
    }
}
