#include "m2c.h"
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; } BF;
typedef struct {
    u8 pad0[0x18]; s8 *x18; u8 pad1[0x39C - 0x1C]; u8 x39C; u8 pad2[0x3D6 - 0x39D]; BF f;
} Sub;
typedef struct { u8 pad[0x518]; s8 *x518; } Obj;
typedef struct { u8 pad[8]; u16 mode; } Arg;
typedef struct { f32 x, y, z; } Vec;
extern Obj *D_002022E4;
void Attack_PlaySe_0_001D1E80(s32, s32, Arg *, s32, s32);
s32 Attack_SpawnSfx_0_001D1F20(s32, s8 *, s32, s32, Arg *, s32, s32);
void Sfx_SetOwner_1_00167600(s32, Obj *);
void Combat_UpdateAttackWrap_0_0013B950(s32, s32, s32, Arg *, s32, s32);
void sceVu0CopyVector(void *, void *);
void MapObj_SnapToGround_0_001B9F10(void *, s8 *, f32, f32);
static inline Sub *getsub(void) {
    Obj *o = D_002022E4;
    if (o == NULL) return NULL;
    if (o->x518 == NULL) return NULL;
    return (Sub *)(o->x518 + 0x180);
}
void PlayerProc_Attack_0_001C55A0(s32 a0, s32 a1, s32 a2, Arg *a3, s32 a4, s32 a5) {
    Sub *s = getsub();
    s32 v;
    Vec pos;
    if (s != NULL) {
        switch (a3->mode) {
        case 0:
            if (a5 != 0) Attack_PlaySe_0_001D1E80(a0, a2, a3, a4, a5);
            break;
        case 1:
            if (a5 != 0) {
                v = Attack_SpawnSfx_0_001D1F20(a0, (s8 *)D_002022E4 + 0x580, a1, a2, a3, a4, a5);
                if (v != 0) Sfx_SetOwner_1_00167600(v, D_002022E4);
            }
            break;
        case 2:
            Combat_UpdateAttackWrap_0_0013B950(a0, a1, a2, a3, a4, a5);
            if (s->x39C != 0) {
                Sub *p = getsub();
                if (p != NULL) sceVu0CopyVector(&pos, (s8 *)p + 0x40);
                pos.y += 220.0f;
                MapObj_SnapToGround_0_001B9F10(&pos, s->x18 + 0x20, 300.0f, 500.0f);
            }
            s->f.b2 = 1;
            break;
        case 3:
            break;
        }
    }
}

