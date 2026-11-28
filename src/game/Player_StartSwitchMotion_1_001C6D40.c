#include "actor.h"
#include "common.h"
typedef struct { u8 pad[0x16]; u16 n; } H;
typedef struct { u16 lo:5; u16 mid:5; u16 rest:6; } B;
typedef struct { u8 a; u8 b; B q; } E;
typedef struct { u8 pad[0xC]; f32 c; f32 x10; u8 pad14[0xC]; f32 x20; } R;
typedef struct {
    u8 pad0[0xC];
    H **h;
    u8 pad10[8];
    s8 *x18;
    u8 pad1C[4];
    E *tbl;
    u8 pad24[4];
    R *r;
    u8 pad2C[0x3AA];
    Flags8 f3D6;
    Flags8 f3D7;
} S_Player_StartSwitchMotion_1_001C6D40;
typedef union {
    u8 b;
    struct { u8 b0:1; u8 b1:2; u8 b3:5; } f;
} F3;
typedef struct { u8 pad[0x3E0]; u16 ids[8]; } S_Player_IsHitTarget_0_001C7320;
extern u8 D_003139A0[];
inline s8* get(void);
void Player_StartSwitchMotion_1_001C6D40(u8 a0);
void Player_SetArmMotion_1_001C7020(u16 idx, f32 t, s32 flags, f32 b, f32 c);
s32 Player_IsHitTarget_0_001C7320(u16 *a0);
void Player_Nop_2_001C73B0(void);
s32 Equip_GetSlotItem_1_001CCD90(s32);
s32 Item_GetMotionId_0_001CC390(s16);
void Mdl_SetBoneRotation_0_001710D0(R *, s16, f32, f32, f32);
void sceVu0CopyVector(s8 *, void *);
f32 Mdl_GetMotionLength_0_00173F70(H *, u16);
void Player_SetArmMotion_1_001C7020__as_Player_StartSwitchMotion_1_001C6D40(f32, u16, s32, f32, f32);

/* Player_StartSwitchMotion_1_001C6D40_ */
/* Player_StartSwitchMotion_1_001C6D40_ */
/* Player_StartSwitchMotion_1_001C6D40 */
inline s8 *get(void) {
    if (D_002022E4 == NULL) {
        return NULL;
    }
    if (D_002022E4->unk518 == NULL) {
        return NULL;
    }
    return D_002022E4->unk518 + 0x180;
}

void Player_StartSwitchMotion_1_001C6D40(u8 a0) {
    s8 *p;
    s32 k;
    f32 f;
    f32 s;
    s32 i;
    s32 n;
    f32 c = 0.01f;
    u16 base;

    p = get();
    k = 0;
    f = 0.0f;
    s = 1.0f;
    if (p != NULL) {
        i = (s16)Equip_GetSlotItem_1_001CCD90(*(u8 *)(*(s8 **)(p + 0x390) + 0x94) & 1);
        if (i != -1) {
            n = Item_GetMotionId_0_001CC390(i);
        } else {
            n = 0;
        }
        if (n > 3) {
            n += 25;
        }
        base = *(u8 *)(p + 0x39C) * 100;
        switch (a0) {
        case 0:
            *(s8 *)(p + 0x3CF) = 0;
            *(s8 *)(p + 0x3CD) = 0;
            base = 0;
            *(s8 *)(p + 0x3D5) = 0;
            k = 2;
            break;
        case 1:
            *(s8 *)(p + 0x3CF) = 1;
            *(s8 *)(p + 0x3CD) = 3;
            *(s8 *)(p + 0x3D5) = 4;
            s -= n * c;
            break;
        case 2:
            *(s8 *)(p + 0x3CF) = 1;
            if (*(u8 *)(*(s8 **)(p + 0x390) + 0x94) & 1) {
                *(s8 *)(p + 0x3CD) = 2;
            } else {
                *(s8 *)(p + 0x3CD) = 4;
            }
            *(s8 *)(p + 0x3D5) = 4;
            s -= n * c;
            break;
        case 3:
            *(s8 *)(p + 0x3CF) = 1;
            *(s8 *)(p + 0x3CD) = 1;
            *(s8 *)(p + 0x3D5) = 4;
            s -= n * c;
            break;
        case 4:
            *(s8 *)(p + 0x3CF) = 1;
            if (*(u8 *)(*(s8 **)(p + 0x390) + 0x94) & 1) {
                *(s8 *)(p + 0x3CD) = 4;
            } else {
                *(s8 *)(p + 0x3CD) = 2;
            }
            *(s8 *)(p + 0x3D5) = 4;
            s -= n * c;
            break;
        case 5:
            *(s8 *)(p + 0x3D5) = 8;
            k = 4;
            f = *(f32 *)(*(s8 **)(p + 0x28) + 0xC);
            break;
        }
        if (s < 0.25f) {
            s = 0.25f;
        }
        base += (u16)(*(s8 *)(p + 0x3CD) + *(s8 *)(p + 0x3CF) * 10);
        Player_SetArmMotion_1_001C7020__as_Player_StartSwitchMotion_1_001C6D40(f, base, k, 0.0f, s);
    }
}

/* Player_SetArmMotion_1_001C7020 */
static inline f32 u2f(u32 x) { return x; }

void Player_SetArmMotion_1_001C7020(u16 idx, f32 t, s32 flags, f32 b, f32 c) {
    H **h;
    S_Player_StartSwitchMotion_1_001C6D40 *s;
    B *q;
    u8 a;
    E *e;
    f32 res;

    if (D_002022E4 == NULL) {
        s = NULL;
    } else if (D_002022E4->unk518 == NULL) {
        s = NULL;
    } else {
        s = (S_Player_StartSwitchMotion_1_001C6D40 *)(D_002022E4->unk518 + 0x180);
    }
    if (s == NULL) {
        return;
    }
    h = s->h;
    if (h == NULL || *h == NULL) {
        return;
    }
    if ((*h)->n <= 0) {
        return;
    }
    e = &s->tbl[idx];
    a = e->a;
    if (a == 0xFF) {
        return;
    }
    q = &e->q;
    Mdl_SetBoneRotation_0_001710D0(s->r, a, c * (0.0078125f * u2f(e->b)), 0.033333335f * (b + u2f(q->lo)), 0.033333335f * u2f(q->mid));
    sceVu0CopyVector(s->x18 + 0xA0, D_003139A0);
    if (flags & 2) {
        s->f3D6.f.b7 = 1;
    } else {
        s->f3D6.f.b7 = 0;
    }
    if (flags & 4) {
        s->f3D7.f.b0 = 1;
    } else {
        s->f3D7.f.b0 = 0;
    }
    res = Mdl_GetMotionLength_0_00173F70(*h, s->tbl[idx].a);
    if (!(flags & 1)) {
        s->r->c = t;
        s->r->x10 = s->r->c;
        s->r->x20 = s->r->c;
    } else {
        s->r->c = res - t;
        if (s->r->c < 0.0f) {
            s->r->c = 0.0f;
        }
        s->r->x10 = s->r->c;
        s->r->x20 = s->r->c;
    }
    ((F3 *)&s->f3D7)->f.b1 = 0;
}

/* Player_IsHitTarget_0_001C7320 */
static inline S_Player_IsHitTarget_0_001C7320 *getp(void) {
    if (D_002022E4 == 0) return 0;
    if (D_002022E4->unk518 == 0) return 0;
    return (S_Player_IsHitTarget_0_001C7320 *)(D_002022E4->unk518 + 0x180);
}
s32 Player_IsHitTarget_0_001C7320(u16 *a0) {
    S_Player_IsHitTarget_0_001C7320 *p;
    s32 i;
    p = getp();
    if (p == 0) return 0;
    for (i = 0; i < 8; i++) {
        if (p->ids[i] == a0[1]) return 1;
    }
    return 0;
}

/* Player_Nop_2_001C73B0 */
void Player_Nop_2_001C73B0(void) {

}
