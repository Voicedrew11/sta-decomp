#include "common.h"
typedef struct { char pad[0x160]; u8 flags; } S;
typedef struct { u8 pad[0x5A0]; u8 b0:1; u8 b1:1; u8 b2:1; } Ent;
typedef struct { char pad[0x1A4]; s32 v; } B;
typedef struct { char pad[0x518]; B *b; } Obj;
u8 Actor_IsFlag1Clear_1_0013BA70(s32 arg0, s32 arg1, S *s);
u8 Actor_CanTarget_0_0013BA90(s8 *a0, Ent *a1);
void Actor_UpdateAllVisibility_0_0013BB70(void);
s32 Enemy_IsAiDisabled_0_0013D6B0(void);
s32 Ent_IsNull0_1_0013EE30(Ent *);
s32 Ent_GetTypeByte_1_0013E220(Ent *);
u8 EnemyScr_Event2001_1_00142820(Ent *, s32);
Ent* Sfx_GetOwner_1_001675D0(s8 *);
Obj* ActorList_Next_2_001A5460(s32 *it);
void Mdl_ResetBones_0_00171610(s32 v);

/* Actor_IsFlag1Clear_1_0013BA70 */
u8 Actor_IsFlag1Clear_1_0013BA70(s32 arg0, s32 arg1, S *s)
{
    return !(s->flags & 1);
}

/* Actor_CanTarget_0_0013BA90 */
static inline u8 can(Ent *a0, Ent *a2) {
    if (Ent_IsNull0_1_0013EE30(a0)) {
        if (Ent_IsNull0_1_0013EE30(a2)) return 0;
        return 1;
    }
    return EnemyScr_Event2001_1_00142820(a0, Ent_GetTypeByte_1_0013E220(a2));
}

u8 Actor_CanTarget_0_0013BA90(s8 *a0, Ent *a1) {
    u8 ok;
    Ent *o;
    u8 r;
    ok = 1;
    o = Sfx_GetOwner_1_001675D0(a0);
    if (o && o->b0 && o->b2) {
        if (Enemy_IsAiDisabled_0_0013D6B0()) r = 0; else r = can(o, a1);
        ok = r;
    }
    return ok;
}

/* Actor_UpdateAllVisibility_0_0013BB70 */
void Actor_UpdateAllVisibility_0_0013BB70(void)
{
    s32 it = 0;
    Obj *o;
    for (o = ActorList_Next_2_001A5460(&it); o; o = ActorList_Next_2_001A5460(&it))
        Mdl_ResetBones_0_00171610(o->b->v);
}
