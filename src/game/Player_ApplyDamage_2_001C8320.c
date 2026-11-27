#include "m2c.h"
typedef struct { s16 x0; s16 x2; s16 x4; } R;
typedef struct {
    u8 pad[0x390];
    R *x390;
    u8 pad394[0x39E - 0x394];
    union { struct { u16 a:6; u16 b:6; u16 c:4; } h; struct { u8 lo; u8 b0:4; u8 b4:1; } c; } x39E;
    u8 pad3A0;
    u8 b0:6; u8 b6:1; u8 b7:1;
    u8 pad3A2[0x3BE - 0x3A2];
    u8 x3BE;
    u8 pad3BF[0x410 - 0x3BF];
    s32 x410;
    u8 pad414[0x430 - 0x414];
    f32 x430, x434, x438, x43C, x440, x444;
} S;
extern s8 *D_002022E4;
s32 Game_GetBusy_0_0012C020(void);
void Player_AddExp_0_001CEAA0(s32);
void Vibe_StartB_0_0015FE20(f32, f32, f32, f32, f32);
void Vibe_StartA_0_0015FD90(f32, f32, f32, f32, f32);
void Player_PlayHurtSe_0_001CA2B0(s32);
static inline S *get(void) {
    S *r;
    s8 *base;
    if (D_002022E4 == NULL) {
        r = NULL;
    } else if ((base = *(s8 **)(D_002022E4 + 0x518)) == NULL) {
        r = NULL;
    } else {
        r = (S *)(base + 0x180);
    }
    return r;
}

s32 Player_ApplyDamage_2_001C8320(s32 n, s32 a1, s32 a2, s32 a3) {
    S *s;
    S *t;

    s = get();
    if (s == NULL) return 0;
    if (s->x390->x4 <= 0) return 0;
    if (Game_GetBusy_0_0012C020()) return 0;
    Player_AddExp_0_001CEAA0(-n);
    s->b6 = 1;
    s->x410 = n;
    if (a1) s->x3BE = 15;
    if (a2) {
        Vibe_StartB_0_0015FE20(1.0f, n / 100.0f, 0.0f, 1.0f, 16.0f);
        Vibe_StartA_0_0015FD90(1.0f, n / 10.0f, 0.0f, 1.0f, 16.0f);
    }
    if (a3) Player_PlayHurtSe_0_001CA2B0(n);
    if (n * 100 / s->x390->x0 >= 30) {
        t = get();
        if (t != NULL) {
            t->x438 = 10.0f;
            t->x43C = 30.0f;
            t->x440 = 0.9f;
            t->x444 = 10.0f;
            t->x434 = 0.0f;
            t->x430 = 0.0f;
        }
    }
    s->x39E.c.b4 = 0;
    s->x39E.h.b = 0;
    return s->x390->x4;
}
