#include "common.h"
typedef struct { u8 b0:2; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:2; } B5B2;
typedef struct { u8 pad[0xBD]; u8 xBD; u8 pad2[5]; u8 xC3; } Stat;
typedef struct { u8 pad[0x158]; Stat *st; } Chr;
typedef struct { u8 pad[0x120]; u8 x120; } S190;
typedef struct { u8 pad[0x190]; S190 *p190; u8 pad194[4]; Vec *p198; } S518;
typedef struct {
    u16 x0;
    u8 pad2[0x4A6];
    Chr **p4A8;
    u8 pad4AC[0x6C];
    S518 *p518;
    u8 pad51C[0x96];
    B5B2 f5B2;
    u8 f5B3;
} Obj;
s32 EnemyScr_Event2021_1_00140E50(Obj *);
void Player_GetPos_1_001C9410(Vec *);
void Player_GetForwardVector_2_001456B0(Vec *);
void sceVu0ScaleVector(Vec *, Vec *, f32);
void sceVu0AddVector(Vec *, Vec *, Vec *);
void sceVu0SubVector(Vec *, Vec *, Vec *);
f32 sceVu0InnerProduct(Vec *, Vec *);
static inline f32 u2f(u32 x) { return x; }

s32 Enemy_CheckReachable_0_0013F8E0(Obj *a) {
    f32 r;
    Vec p;
    Vec d;
    Vec e;

    if ((u8)(a->x0 == 0)) {
        return 0;
    }
    if ((a->f5B3 & 3) < 3) {
        return 0;
    }
    if (a->f5B2.b2) {
        return 0;
    }
    if (a->f5B2.b6 == 2) {
        return 0;
    }
    if (a->f5B2.b6 == 1) {
        return 0;
    }
    if (a->f5B2.b6 == 0 && !a->f5B2.b5) {
        return 0;
    }
    if (a->p518->p190->x120 & 1) {
        return 0;
    }
    if (EnemyScr_Event2021_1_00140E50(a)) {
        return 0;
    }
    if ((a->f5B3 & 3) == 3) {
        r = 1000.0f;
        if (a->p4A8 && *a->p4A8) {
            r = 100.0f * u2f((*a->p4A8)->st->xC3);
        }
        Player_GetPos_1_001C9410(&p);
        {
            f32 dy = p.y - a->p518->p198->y;
            if (dy < -r || !(dy <= r)) {
                return 1;
            }
        }
        r = 4000.0f;
        if (a->p4A8 && *a->p4A8) {
            r = 100.0f * u2f((*a->p4A8)->st->xBD);
        }
        Player_GetForwardVector_2_001456B0(&d);
        sceVu0ScaleVector(&d, &d, 0.5f * r);
        sceVu0AddVector(&d, &d, &p);
        sceVu0SubVector(&e, a->p518->p198, &d);
        if (!(sceVu0InnerProduct(&e, &e) <= r * r)) {
            return 1;
        }
    }
    return 0;
}
