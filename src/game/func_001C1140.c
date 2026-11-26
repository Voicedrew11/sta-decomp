#include "actor.h"
typedef struct { f32 a[4]; f32 b[4]; } Ray;
typedef struct { s32 w[9]; s32 hit; s32 pad; u8 *tri; s32 w2[4]; } Res;
typedef struct { u8 pad[0x18]; s8 *m18; u8 pad1C[0x382]; u16 lo:6; u16 f6:6; u16 b12:1; u16 f13:3; u8 m3A0[0x1F]; u8 m3BF; } P;
extern s32 D_00201E80;
extern s8 D_004B4CF0[];
extern f32 D_004B4D00[];
extern f32 D_004B4D04[];
extern f32 D_004B4D08[];
extern f32 D_004B4D0C[];
void sceVu0CopyVector(f32 *, s8 *);
void func_00102870(f32 *, f32 *);
void sceVu0ScaleVector(f32 *, f32 *, f32);
void sceVu0AddVector(f32 *, f32 *, s8 *);
void func_001502A0(Ray *, f32 *, f32 *, f32);
void memset(void *, s32, s32);
void func_001B2160(s32, Res *, Ray *, s32, s32);
inline s8 *get(void) {
    if (D_002022E4 == NULL) {
        return NULL;
    }
    if (D_002022E4->unk518 == NULL) {
        return NULL;
    }
    return D_002022E4->unk518 + 0x180;
}

s32 func_001C1140(void) {
    Res res;
    Ray ray;
    f32 a[4];
    f32 b[4];
    s32 i;
    P *p;
    s32 **q;
    s32 t;

    p = (P *)get();
    if (p->m3BF != 0xC && p->m3BF != 0xD) {
        return 0;
    }
    sceVu0CopyVector(a, p->m18 + 0x80);
    a[1] = 0.0f;
    func_00102870(a, a);
    sceVu0ScaleVector(a, a, -125.0f);
    sceVu0CopyVector(b, (s8 *)a);
    a[1] -= 10.0f;
    b[1] += 300.0f;
    sceVu0AddVector(a, a, p->m18 + 0x90);
    sceVu0AddVector(b, b, p->m18 + 0x90);
    func_001502A0(&ray, a, b, 50.0f);
    for (i = 0, q = (s32 **)(&D_00201E80 + 2); i < 2; i++, q++) {
        if (*q != 0 && **q != 0) {
            memset(&res, 0, 0x40);
            func_001B2160(**q, &res, &ray, 2, -2);
            if (res.hit != 0) {
                t = res.tri[0xC] & 0xF;
                if (t == 0xC || t == 0xD) {
                    D_004B4D00[0] = *(f32 *)(res.tri + 0x10);
                    D_004B4D04[0] = *(f32 *)(res.tri + 0x14);
                    D_004B4D08[0] = *(f32 *)(res.tri + 0x18);
                    D_004B4D0C[0] = 1.0f;
                    sceVu0CopyVector((f32 *)D_004B4CF0, (s8 *)&res);
                    p->f6 = 1;
                    p->b12 = 1;
                    p->f13 = 0;
                    return 1;
                }
            }
        }
    }
    return 0;
}
