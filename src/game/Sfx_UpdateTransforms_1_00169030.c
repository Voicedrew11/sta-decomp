#include "actor.h"
typedef struct { u8 pad[0x4C]; f32 x, y, z; } M;
typedef struct { s32 off; u8 pad4[6]; u16 xA; u8 pad[0x80 - 0xC]; } Sub;
typedef struct {
    u8 pad0[0x30];
    Vec pos;
    u8 pad40[0x188 - 0x40];
    u16 b0:1; u16 b1:1; u16 b2:1; u16 b3:1; u16 b4:1; u16 b5:1; u16 b6:1; u16 cnt:8; u16 b15:1;
    u8 g0:1; u8 g1:7;
    u8 pad2[0x210 - 0x18B];
    M *m[(0x270 - 0x210) / 4];
    Sub sub[24];
    s8 **xE70;
    u8 padE74[8];
    s32 xE7C;
    u8 padE80[0x40];
    Vec xEC0;
} E;
typedef struct { u8 pad[0xBA]; u16 xBA; } T;
typedef struct { u8 pad[0x158]; T *p158; } S;
void sceVu0CopyVector(void *, void *);
void sceVu0CopyMatrix(Mtx *, void *);
void Camera_Update_1_001C8F90(Mtx *);
void sceVu0InversMatrix(Mtx *, Mtx *);
void sceVu0MulMatrix(void *, Mtx *, Mtx *);
void Sfx_Free_1_001670E0(E *);
s32 Sfx_UpdateNode_1_001697A0(E *, f32);
f32 Vec_Distance_3_00146940(Vec *, s8 *);
extern s8 D_001F2160[];
extern s8 D_001F2170[];
extern s32 D_00201C98;
extern S **D_002022BC;
extern E D_003407E0[];
static inline f32 u2f(u32 x) { return x; }
static inline s32 busy(E *e) {
    u32 n; u32 j; s32 found = 0;
    n = e->cnt; for (j = 1; j < n; j++) { if (0 < e->sub[j].xA) { found = 1; break; } }
    return found;
}
static inline void reloc(E *e) {
    if (e != NULL) {
        s32 n; s8 *base; s32 j;
        n = e->cnt; base = *e->xE70 + e->xE7C;
        for (j = 0; j < n; j++) {
            e->m[j] = (M *)(base + e->sub[j].off);
        }
    }
}

s32 Sfx_UpdateTransforms_1_00169030(f32 f) {
    s32 i;
    s32 n;
    E *e;
    s32 v;
    f32 d;
    f32 r;
    Mtx m1;
    Mtx m2;

    n = 0;
    for (i = 0, e = D_003407E0; i < 0x100; i++, e++) {
        if (!e->b0) continue;
        n++;
        if (e->b5) {
            e->g0 = 1;
        } else {
            if (D_00201C98 == 0) {
                v = 1;
            } else {
                d = Vec_Distance_3_00146940(&e->pos, (D_002022E4 != NULL && D_002022E4->unk518 != NULL) ? D_002022E4->unk518 + 0x1C0 : D_001F2160);
                if (D_002022BC != NULL && (*D_002022BC)->p158 != NULL) {
                    r = u2f((*D_002022BC)->p158->xBA);
                } else {
                    r = 0.0f;
                }
                v = d < r;
            }
            e->g0 = v;
        }
        if (e->b5) {
            sceVu0CopyMatrix(&m1, D_001F2170);
            m1.m[3].x = e->m[0]->x;
            m1.m[3].y = e->m[0]->y;
            m1.m[3].z = e->m[0]->z;
            *(s32 *)&m1.m[3].w = 0;
            m1.m[3].w = 1.0f;
            Camera_Update_1_001C8F90(&m2);
            sceVu0InversMatrix(&m2, &m2);
            sceVu0MulMatrix(e, &m2, &m1);
        }
        if (e->b3) {
            if (!busy(e)) {
                Sfx_Free_1_001670E0(e);
            }
        } else {
            reloc(e);
            if (Sfx_UpdateNode_1_001697A0(e, f)) {
                e->b3 = 1;
            }
            sceVu0CopyVector(&e->xEC0, &e->pos);
        }
    }
    return n;
}
