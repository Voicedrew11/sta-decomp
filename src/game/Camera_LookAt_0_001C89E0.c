#include "actor.h"
#include "common.h"
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; } Bits;
typedef struct { u8 pad[0x20]; f32 x20; f32 x24; } R;
typedef struct { char pad[0x518]; u8 *p; } S;
typedef struct { char pad[0x37C]; f32 f; char p380[0x22]; unsigned char : 1; unsigned char b : 1; char p3a3[0x5D]; f32 v[4]; } T_Camera_SetPosition_0_001C8EA0;
typedef struct { char pad[0x430]; s32 a; s32 b; f32 v[4]; } T_Camera_SetParams_0_001C8F30;
typedef struct { f32 m[4][4]; } MtxF;
typedef struct { u8 pad[0x18]; s8 *o; u8 pad1C[0x370 - 0x1C]; f32 f370; u8 p374[0x39C - 0x374]; u8 b39C; u8 p39D[0x3A1 - 0x39D]; u8 r:5; u8 b5:1; u8 r2:2; u8 p3A2[2]; f32 f3A4; u8 p3A8[0x3D0 - 0x3A8]; f32 f3D0; u8 p3D4[0x430 - 0x3D4]; f32 f430; f32 f434; u8 p438[0x454 - 0x438]; f32 f454; } P;
extern MtxF D_001F2170;
extern Vec D_001F2140;
extern f32 D_00222A40[];
inline s8* get(void);
void Camera_LookAt_0_001C89E0(Vec *dir, f32 t);
void Camera_SetPosition_0_001C8EA0(f32 *v, f32 f);
void Camera_SetParams_0_001C8F30(f32 x, f32 y, f32 z, f32 w);
void Camera_Update_1_001C8F90(void *a0);
void sceVu0CopyVector(void *, void *);
void sceVu0SubVector(Vec*, void *, Vec*);
f32 Vec_YawAngle_2_0013FC10(Vec *);
f32 sceVu0InnerProduct(Vec *, Vec *);
f32 atan2f(f32, f32);
f32 sqrtf(f32);
void sceVu0CopyMatrix(MtxF *, MtxF *);
void sceVu0RotMatrixX(MtxF *, MtxF *, f32);
void sceVu0RotMatrixZ(MtxF *, MtxF *, f32);
void sceVu0RotMatrixY(MtxF *, MtxF *, f32);
void sceVu0ScaleVector(Vec *, Vec *, f32);
void sceVu0ApplyMatrix(Vec *, MtxF *, Vec *);
void sceVu0AddVector(Vec *, Vec *, Vec *);
void sceVu0CameraMatrix(void *, Vec *, Vec *, Vec *);
s32 ItemType_IsMagic_0_001D1E00(u8);

/* Camera_LookAt_0_001C89E0 */
#define WRAPV(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + *(volatile f32 *)&(x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
#define sceVu0CopyVector sceVu0CopyVector__as_Camera_LookAt_0_001C89E0
void sceVu0CopyVector__as_Camera_LookAt_0_001C89E0(Vec *, s8 *);
#define sceVu0SubVector sceVu0SubVector__as_Camera_LookAt_0_001C89E0
void sceVu0SubVector__as_Camera_LookAt_0_001C89E0(Vec *, Vec *, Vec *);
inline s8 *get(void) {
    if (D_002022E4 == NULL) {
        return NULL;
    }
    if (D_002022E4->unk518 == NULL) {
        return NULL;
    }
    return D_002022E4->unk518 + 0x180;
}
#define RR (*(R **)(p + 0x18))

void Camera_LookAt_0_001C89E0(Vec *dir, f32 t) {
    Vec v;
    s8 *p;
    s8 *q;
    f32 w;
    f32 d;
    f32 y;
    f32 *a;

    p = get();
    if (p == NULL) return;
    q = get();
    if (q != NULL) {
        sceVu0CopyVector(&v, q + 0x40);
    }
    sceVu0SubVector(&v, dir, &v);
    w = Vec_YawAngle_2_0013FC10(&v);
    w = WRAP(w);
    RR->x24 = WRAP(RR->x24);
    d = RR->x24 - w;
    if (d > 3.1415927f) d -= 6.2831855f;
    if (d < -3.1415927f) d += 6.2831855f;
    RR->x24 = w + d * t;
    RR->x24 = WRAP(RR->x24);
    y = v.y;
    v.y = 0.0f;
    w = -atan2f(y, sqrtf(sceVu0InnerProduct(&v, &v)));
    w = WRAP(w);
    RR->x20 = WRAP(RR->x20);
    d = RR->x20 - w;
    if (d > 3.1415927f) d -= 6.2831855f;
    if (d < -3.1415927f) d += 6.2831855f;
    RR->x20 = w + d * t;
    RR->x20 = WRAP(RR->x20);
    ((Bits *)(p + 0x3A2))->b1 = 0;
}
#undef sceVu0CopyVector
#undef sceVu0SubVector
#undef RR

/* Camera_SetPosition_0_001C8EA0 */
#define D_002022E4 D_002022E4__as_Camera_SetPosition_0_001C8EA0
extern S *D_002022E4__as_Camera_SetPosition_0_001C8EA0;
#define sceVu0CopyVector sceVu0CopyVector__as_Camera_SetPosition_0_001C8EA0
void sceVu0CopyVector__as_Camera_SetPosition_0_001C8EA0(f32 *v0, f32 *v1);

void Camera_SetPosition_0_001C8EA0(f32 *v, f32 f)
{
    T_Camera_SetPosition_0_001C8EA0 *t;
    if (D_002022E4 == NULL) {
        t = NULL;
    } else {
        u8 *p = D_002022E4->p;
        if (p == NULL)
            t = NULL;
        else
            t = (T_Camera_SetPosition_0_001C8EA0 *)(p + 0x180);
    }
    if (t != NULL) {
        sceVu0CopyVector(t->v, v);
        t->f = f;
        t->b = 1;
    }
}
#undef sceVu0CopyVector
#undef D_002022E4

/* Camera_SetParams_0_001C8F30 */
#define D_002022E4 D_002022E4__as_Camera_SetParams_0_001C8F30
extern S *D_002022E4__as_Camera_SetParams_0_001C8F30;

void Camera_SetParams_0_001C8F30(f32 x, f32 y, f32 z, f32 w)
{
    T_Camera_SetParams_0_001C8F30 *t;
    if (D_002022E4 == NULL) {
        t = NULL;
    } else {
        u8 *p = D_002022E4->p;
        if (p == NULL)
            t = NULL;
        else
            t = (T_Camera_SetParams_0_001C8F30 *)(p + 0x180);
    }
    if (t != NULL) {
        t->v[0] = x;
        t->v[1] = y;
        t->v[2] = z;
        t->v[3] = w;
        t->b = 0;
        t->a = 0;
    }
}
#undef D_002022E4

/* Camera_Update_1_001C8F90 */
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
#define sceVu0SubVector sceVu0SubVector__as_Camera_Update_1_001C8F90
void sceVu0SubVector__as_Camera_Update_1_001C8F90(Vec *, s8 *, Vec *);
static inline P *cur(void) {
    if (D_002022E4 == 0) return 0;
    if (D_002022E4->unk518 == 0) return 0;
    return (P *)(D_002022E4->unk518 + 0x180);
}

void Camera_Update_1_001C8F90(void *a0) {
    P *p;
    MtxF m;
    Vec v;
    Vec t;


    p = cur();
    if (p == 0) return;
    sceVu0CopyMatrix(&m, &D_001F2170);
    sceVu0RotMatrixX(&m, &m, p->f3A4 + WRAP(*(f32 *)(p->o + 0x30)));
    sceVu0RotMatrixZ(&m, &m, WRAP(*(f32 *)(p->o + 0x38)));
    sceVu0RotMatrixY(&m, &m, WRAP(3.1415927f + *(f32 *)(p->o + 0x34)));
    sceVu0ScaleVector(&v, &D_001F2140, p->f370);
    sceVu0SubVector(&v, p->o, &v);
    if (p->b5) {
        v.y += 4.0f * p->f454;
    } else {
        v.y += 2.0f * p->f454;
    }
    t.x = p->f430;
    t.y = p->f434;
    t.w = 1.0f;
    t.z = 0.0f;
    sceVu0ApplyMatrix(&t, &m, &t);
    sceVu0AddVector(&v, &v, &t);
    sceVu0CameraMatrix(a0, &v, (Vec *)m.m[2], (Vec *)m.m[1]);
    if (ItemType_IsMagic_0_001D1E00(p->b39C)) {
        D_00222A40[0] = 75.0f * (1.0f - -0.6f * (p->f3D0 / -0.17453294f));
    } else {
        D_00222A40[0] = 75.0f;
    }
}
#undef sceVu0SubVector
