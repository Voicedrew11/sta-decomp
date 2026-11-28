#include "common.h"
typedef struct { u8 pad[0x5A0]; Flags8 f; } A_ActorList_Next_2_001A5460;
typedef struct { u8 pad[0x5A0]; Flags8 f; } A_ActorList_AllocSlot_0_001A5530;
typedef struct { u8 pad[0x5A0]; Flags8 f5A0; } A_ActorList_NextTargetable_0_001A5660;
extern s32 D_004A4878[];
extern A_ActorList_Next_2_001A5460 **D_004A4570[];
extern s32 D_00202274;
s32 ActorList_GetCount_1_001A5430(void);
s32 ActorList_SetCount_1_001A5440(s32 arg0);
A_ActorList_Next_2_001A5460* ActorList_Next_2_001A5460(s32 *it);
A_ActorList_AllocSlot_0_001A5530** ActorList_AllocSlot_0_001A5530(void);
u8** ActorList_FindFree_0_001A55E0(void);
A_ActorList_NextTargetable_0_001A5660* ActorList_NextTargetable_0_001A5660(void);
u8* ActorList_NextB_0_001A5710(void);
u8 Enemy_Get5B2b3_1_0013E830(A_ActorList_Next_2_001A5460 *);

/* ActorList_GetCount_1_001A5430 */
s32 ActorList_GetCount_1_001A5430(void) {
    return (*D_004A4878);
}

/* ActorList_SetCount_1_001A5440 */
s32 ActorList_SetCount_1_001A5440(s32 arg0) {
    s32 temp_2;

    temp_2 = (*D_004A4878);
    (*D_004A4878) = arg0;
    return temp_2;
}

/* ActorList_Next_2_001A5460 */
A_ActorList_Next_2_001A5460 *ActorList_Next_2_001A5460(s32 *it) {
 A_ActorList_Next_2_001A5460 *r; s32 i; A_ActorList_Next_2_001A5460 **o;
 i = *it; r = 0;
 while (i < 0x81) { o = D_004A4570[0x80 - i]; i++; if (o != 0 && (*o)->f.f.b0 && (*o)->f.f.b2 && Enemy_Get5B2b3_1_0013E830(*o) == 0) { r = *o; break; } }
 *it = i; return r;
}

/* ActorList_AllocSlot_0_001A5530 */
#define D_004A4570 D_004A4570__as_ActorList_AllocSlot_0_001A5530
extern A_ActorList_AllocSlot_0_001A5530 **D_004A4570__as_ActorList_AllocSlot_0_001A5530[];
A_ActorList_AllocSlot_0_001A5530 **ActorList_AllocSlot_0_001A5530(void) {
    s32 i;
    A_ActorList_AllocSlot_0_001A5530 ***p;
    i = D_00202274;
    if (i >= 0x81) return NULL;
    goto setup;
body:
    if (*p != NULL && ((**p)->f.f.b0 || (**p)->f.f.b1)) {
        D_00202274 = i + 1;
        return D_004A4570[i];
    }
    p++;
    i++;
cond:
    if (i < 0x81) goto body;
    return NULL;
setup:
    p = &D_004A4570[i];
    goto cond;
}
#undef D_004A4570

/* ActorList_FindFree_0_001A55E0 */
#define D_004A4570 D_004A4570__as_ActorList_FindFree_0_001A55E0
extern u8 **D_004A4570__as_ActorList_FindFree_0_001A55E0[];

u8 **ActorList_FindFree_0_001A55E0(void) {
    s32 var_5;
    u8 ***var_4;
    u8 **temp_2;
    u8 temp_3;

    D_00202274 = 0;
    var_5 = 0;
    var_4 = (u8 ***) (D_004A4570);
loop_1:
    temp_2 = (u8 **) (*var_4);
    if ((temp_2 != NULL) && ((temp_3 = M2C_FIELD(*temp_2, u8 *, 0x5A0), ((temp_3 & 1) != 0)) || (((u64) ((s64) temp_3 << 0x3E) >> 0x3F) != 0))) {
        D_00202274 = var_5 + 1;
        return (u8 **) ((D_004A4570)[var_5]);
    }
    var_5 += 1;
    var_4 = (u8***)((u8 *)var_4 + 4);
    if (var_5 >= 0x81) {
        return NULL;
    }
    goto loop_1;
}
#undef D_004A4570

/* ActorList_NextTargetable_0_001A5660 */
#define D_004A4570 D_004A4570__as_ActorList_NextTargetable_0_001A5660
extern A_ActorList_NextTargetable_0_001A5660 **D_004A4570__as_ActorList_NextTargetable_0_001A5660[];
A_ActorList_NextTargetable_0_001A5660 *ActorList_NextTargetable_0_001A5660(void) {
    s32 i = D_00202274; A_ActorList_NextTargetable_0_001A5660 ***p; if (!(i < 0x81)) return NULL; goto setup; body: if (*p && ((**p)->f5A0.b & 1) && (**p)->f5A0.f.b2) { D_00202274 = i + 1; return *D_004A4570[i]; } p++; i++; cond: if (!(i < 0x81)) return NULL; goto body; setup: p = &D_004A4570[i]; goto cond;
}
#undef D_004A4570

/* ActorList_NextB_0_001A5710 */
#define D_004A4570 D_004A4570__as_ActorList_NextB_0_001A5710
extern u8 **D_004A4570__as_ActorList_NextB_0_001A5710[];

u8 *ActorList_NextB_0_001A5710(void) {
    s32 var_5;
    u8 ***var_4;
    u8 **temp_2;
    u8 temp_3;

    D_00202274 = 0;
    var_5 = 0;
    var_4 = (u8 ***) (D_004A4570);
loop_1:
    temp_2 = (u8 **) (*var_4);
    if (temp_2 != NULL) {
        temp_3 = M2C_FIELD(*temp_2, u8 *, 0x5A0);
        if ((temp_3 & 1) && (((u64) ((s64) temp_3 << 0x3D) >> 0x3F) != 0)) {
            D_00202274 = var_5 + 1;
            return (u8 *) (*(D_004A4570)[var_5]);
        }
    }
    var_5 += 1;
    var_4 = (u8***)((u8 *)var_4 + 4);
    if (var_5 >= 0x81) {
        return NULL;
    }
    goto loop_1;
}
#undef D_004A4570
