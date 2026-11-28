#include "m2c.h"
#include "common.h"
typedef struct { u8 pad[0x4A4]; void **p; } Obj_EnemyScr_Event2026_1_00140480;
typedef struct { u8 pad[0x4A4]; void **p; } Obj_EnemyScr_Event2025_1_00140770;
typedef struct { u8 pad[0x4A4]; void **p; } Obj_EnemyScr_Event2024GetMove_1_001409A0;
typedef struct { u8 pad[0x4A4]; void **p; } Obj_EnemyScr_Event2023_1_00140CB0;
typedef struct { char pad[0x4A4]; s32 *p; } Obj_EnemyScr_Event2022_1_00140DE0;
typedef struct { char pad[0x4A4]; s32 *p; } Obj_EnemyScr_Event2021_1_00140E50;
typedef struct { char pad[0x4A4]; s32 *p; } Obj_EnemyScr_Event2020_1_00140EF0;
typedef struct { u8 pad[0x4A4]; void **p; } Obj_EnemyScr_BroadcastFrameEvent_0_001410C0;
typedef struct { char pad[0x4A4]; s32 *p; } Obj_EnemyScr_Event2018_1_001411F0;
typedef struct { char pad[0x4A4]; s32 *p; } Obj_EnemyScr_Event2017OnDeath_1_00141260;
typedef struct { char pad[0x4A4]; s32 *p; } Obj_EnemyScr_Event2016_1_001412E0;
typedef struct { u8 pad[0x4A4]; void **p; } Obj_EnemyScr_BroadcastQuery_0_00141380;
typedef struct { u8 pad[0x4A4]; void **p; } Obj_EnemyScr_Event2015_1_00141510;
typedef struct { char pad[0x4A4]; s32 *p; } Obj_EnemyScr_Event2014_1_00141610;
typedef struct { u8 pad[0x4A4]; void **p; } Obj_EnemyScr_Event2013GetMove_1_001416B0;
typedef struct { u8 pad[0x4A4]; void **p; } Obj_EnemyScr_Event2012_1_001419C0;
typedef struct { u8 pad[0x4A4]; void **p; } Obj_EnemyScr_Event2011GetWeights_1_00141A50;
typedef struct { char pad[0x4A4]; s32 *p; } Obj_EnemyScr_Event2010_1_00141DA0;
typedef struct { u8 pad[0x4A4]; s32 *x4A4; } A;
typedef struct { char pad[0x4A4]; s32 *p; } Obj_EnemyScr_Event200E_1_00142010;
typedef struct { u8 pad[0x4A4]; void **p; } Obj_EnemyScr_Event200DGetStats_1_00142090;
typedef struct { u8 pad[0x4A4]; void **p; } Obj_EnemyScr_Event200COnHit_1_00142320;
typedef struct { char pad[0x4A4]; s32 *p; } Obj_EnemyScr_Event200B_1_001423E0;
typedef struct { u8 pad[0x4A4]; void **p; } Obj_EnemyScr_Event2009Move_1_00142470;
typedef struct { u8 pad[0x4A4]; void **p; } Obj_EnemyScr_Event2005Turn_1_00142530;
typedef struct { u8 pad[0x4A4]; void **p; } Obj_EnemyScr_Event2004Attack_1_001425F0;
typedef struct { u8 pad[0x4A4]; void **p; } Obj_EnemyScr_Event2003React_1_001426C0;
typedef struct { char pad[0x4A4]; s32 *p; } Obj_EnemyScr_Event2002_1_00142780;
typedef struct { char pad[0x4A4]; s32 *p; } Obj_EnemyScr_Event2001_1_00142820;
typedef struct { char pad[0x4A4]; s32 *p; } Obj_EnemyScr_EventInit_1_001428C0;
extern s32 D_001FAD20[];
extern s32 D_001FAD40[];
extern s32 D_001FAD60[];
extern s32 D_001FAD80[];
extern s32 D_001FADA0[];
extern s32 D_001FADC0[];
extern s32 D_001FADE0[];
extern s32 D_001FAE00[];
extern s32 D_001FAE20[];
extern s32 D_001FAE40[];
extern s32 D_001FAE60[];
extern s32 D_001FAE80[];
extern s32 D_001FAEA0[];
extern s32 D_001FAEC0[];
extern s32 D_001FAEE0[];
extern s32 D_001FAF00[];
extern s32 D_001FAF20[];
extern s32 D_001FAF40[];
extern s32 D_001FAF60[];
extern s32 D_001FAF80[];
extern s32 D_001FAFA0[];
extern s32 D_001FAFC0[];
extern s32 D_001FAFE0[];
extern s32 D_001FB000[];
extern s32 D_001FB020[];
extern s32 D_001FB040[];
extern s32 D_001FB060[];
extern s32 D_001FB080[];
extern s32 D_001FB0A0[];
extern s32 D_001FB0C0[];
extern s32 D_001FB0E0[];
extern s32 D_001FB100[];
extern s32 D_001FB120[];
extern s32 D_001FB140[];
extern s32 D_001FB160[];
extern s32 D_001FB180[];
extern s32 D_001FB1A0[];
extern s32 D_001FB1C0[];
extern s32 D_001FB1E0[];
extern s32 D_001FB200[];
extern s32 D_001FB220[];
extern s32 D_001FB240[];
extern s32 D_001FB260[];
extern s32 D_001FB280[];
extern s32 D_001FB2A0[];
extern s32 D_001FB2C0[];
extern s32 D_001FB2E0[];
extern s32 D_001FB300[];
extern s32 D_001FB320[];
extern s32 D_001FB340[];
extern s32 D_001FB360[];
extern s32 D_001FB380[];
extern s32 D_001FB3A0[];
extern s32 D_001FB3C0[];
extern s32 D_001FB3E0[];
extern s32 D_001FB400[];
extern s32 D_001FB420[];
extern s32 D_001FB440[];
extern s32 D_001FB460[];
extern s32 D_001FB480[];
extern s32 D_001FB4A0[];
extern s32 D_001FB4C0[];
extern s32 D_001FB4E0[];
extern s32 D_001FB500[];
extern s32 D_001FB520[];
extern s32 D_001FB540[];
extern s32 D_001FB560[];
extern s32 D_001FB580[];
extern s32 D_001FB5A0[];
extern s32 D_001FB5C0[];
extern s32 D_001FB5E0[];
extern s32 D_001FB600[];
extern s32 D_001FB620[];
extern s32 D_001FB640[];
extern s32 D_001FB660[];
extern s32 D_001FB680[];
extern s32 D_001FB6A0[];
extern s32 D_001FB6C0[];
extern s32 D_001FB6E0[];
extern s32 D_001FB700[];
extern s32 D_001FB720[];
u8 EnemyScr_Event2026_1_00140480(Obj_EnemyScr_Event2026_1_00140480 *a0, s32 a1, s32 a2, f32 f0, f32 f1, f32 f2, f32 f3);
void EnemyScr_Event2025_1_00140770(Obj_EnemyScr_Event2025_1_00140770 *a0, s8 *a1, u32 a2, u32 a3, u32 a4);
u16 EnemyScr_Event2024GetMove_1_001409A0(Obj_EnemyScr_Event2024GetMove_1_001409A0 *a0, s32 a1, f32 *px, f32 *py, f32 *pz);
void EnemyScr_Event2023_1_00140CB0(Obj_EnemyScr_Event2023_1_00140CB0 *a0, u8 *pa, f32 *pb, f32 *pc);
void EnemyScr_Event2022_1_00140DE0(Obj_EnemyScr_Event2022_1_00140DE0 *o);
u8 EnemyScr_Event2021_1_00140E50(Obj_EnemyScr_Event2021_1_00140E50 *o);
u8 EnemyScr_Event2020_1_00140EF0(Obj_EnemyScr_Event2020_1_00140EF0 *o);
void EnemyScr_BroadcastMotionEvent_0_00140F90(u8 a, u8 b, u32 c, u32 d);
void EnemyScr_BroadcastFrameEvent_0_001410C0(u8 a0, u8 a1, u32 a2, u32 a3);
void EnemyScr_Event2018_1_001411F0(Obj_EnemyScr_Event2018_1_001411F0 *o);
void EnemyScr_Event2017OnDeath_1_00141260(Obj_EnemyScr_Event2017OnDeath_1_00141260 *o, s32 d);
u8 EnemyScr_Event2016_1_001412E0(Obj_EnemyScr_Event2016_1_001412E0 *o);
u8 EnemyScr_BroadcastQuery_0_00141380(u32 a0, u32 a1);
u8 EnemyScr_Event2015_1_00141510(Obj_EnemyScr_Event2015_1_00141510 *a0, u32 a1, u32 a2, u32 a3);
u8 EnemyScr_Event2014_1_00141610(Obj_EnemyScr_Event2014_1_00141610 *o);
u16 EnemyScr_Event2013GetMove_1_001416B0(Obj_EnemyScr_Event2013GetMove_1_001416B0 *a0, s32 a1, f32 *px, f32 *py, f32 *pz);
void EnemyScr_Event2012_1_001419C0(Obj_EnemyScr_Event2012_1_001419C0 *a0, f32 f);
void EnemyScr_Event2011GetWeights_1_00141A50(Obj_EnemyScr_Event2011GetWeights_1_00141A50 *a0, f32 *p0, f32 *p1, f32 *p2, f32 *p3, f32 *p4);
void EnemyScr_Event2010_1_00141DA0(Obj_EnemyScr_Event2010_1_00141DA0 *o);
void EnemyScr_Event200F_1_00141E10(A *a, s32 a1, f32 x, f32 y, f32 z, f32 w);
void EnemyScr_Event200E_1_00142010(Obj_EnemyScr_Event200E_1_00142010 *o, s32 d);
void EnemyScr_Event200DGetStats_1_00142090(Obj_EnemyScr_Event200DGetStats_1_00142090 *a0, f32 *p0, f32 *p1, f32 *p2, f32 *p3);
void EnemyScr_Event200COnHit_1_00142320(Obj_EnemyScr_Event200COnHit_1_00142320 *a0, s32 a1, s32 a2);
void EnemyScr_Event200B_1_001423E0(Obj_EnemyScr_Event200B_1_001423E0 *o, s32 d);
u8 EnemyScr_Event2009Move_1_00142470(Obj_EnemyScr_Event2009Move_1_00142470 *a0, s32 a1);
u8 EnemyScr_Event2005Turn_1_00142530(Obj_EnemyScr_Event2005Turn_1_00142530 *a0, s32 a1);
u8 EnemyScr_Event2004Attack_1_001425F0(Obj_EnemyScr_Event2004Attack_1_001425F0 *a0, s32 a1, s32 a2);
u8 EnemyScr_Event2003React_1_001426C0(Obj_EnemyScr_Event2003React_1_001426C0 *a0, s32 a1);
u8 EnemyScr_Event2002_1_00142780(Obj_EnemyScr_Event2002_1_00142780 *o);
u8 EnemyScr_Event2001_1_00142820(Obj_EnemyScr_Event2001_1_00142820 *o, s32 d);
void EnemyScr_EventInit_1_001428C0(Obj_EnemyScr_EventInit_1_001428C0 *o);
void EnemyScr_GetScriptPath_3_00142930(s32 arg0, void *arg1);
s32 Script_SendEvent_2_00166F80(void *, s32, void *);
void Script_SetArgU8_1_00165070(void *, u8, s32, u32);
void Script_SetArgU16_1_001650F0(void *, u8, s32, u32);
s8 Script_RunEvent_2_00166C10(void *, s32);
s32 Script_GetResultU8_1_00164FC0(void *, u8, s32);
void Script_SetArgS8_1_00165030(void *, u8, s32, s32);
s8 Script_GetResultS8_1_00164F90(void *, u8, s32);
void Script_SetArgF32_1_00164FF0(void *, u8, s32, f32);
f32 Script_GetResultF32_1_00164F60(void *, u8, s32);
f32* Enemy_GetPositionPtr_2_00140460(void *);
f32* Enemy_GetRotationPtr_1_00140430(void *);
f32* Enemy_PtrVec660_1_00140340(void *);
f32* Enemy_PtrVec670_1_00140320(void *);
s8* ActorList_Next_2_001A5460(s32 *);
s32 Ent_IsNull0_1_0013EE30(void *);
s32 Enemy_GetTargetHandle_0_0013EDE0(void *);
s32 Enemy_GetMotionId_0_0013ED20(s8 *);
s32 Enemy_GetMotionFrame_0_0013ECA0(Obj_EnemyScr_BroadcastFrameEvent_0_001410C0 *);
s32 Ent_GetTypeByte_1_0013E220(Obj_EnemyScr_BroadcastQuery_0_00141380 *);
s32 Enemy_IsDead_1_0013EEE0(Obj_EnemyScr_BroadcastQuery_0_00141380 *);
u32 Enemy_Get5B5mF_1_0013E5E0(void *);
f32 Enemy_GetParam298_1_0013DD40(Obj_EnemyScr_Event200COnHit_1_00142320 *);
void Enemy_Set5D8_1_0013E430(Obj_EnemyScr_Event200COnHit_1_00142320 *, f32);
void Enemy_IncCounter6B8_1_0013EF50(Obj_EnemyScr_Event200COnHit_1_00142320 *);
void Enemy_IncCounter6B9_1_0013EF10(Obj_EnemyScr_Event200B_1_001423E0 *o);
void Script_SetArgS16_1_001650B0(void *, u8, s32, s32);
void sprintf(void *, s32 *);

/* EnemyScr_Event2026_1_00140480 */
static inline u32 cv(f32 x) { return (u32)x; }
#define H(a) (*(a)->p)

u8 EnemyScr_Event2026_1_00140480(Obj_EnemyScr_Event2026_1_00140480 *a0, s32 a1, s32 a2, f32 f0, f32 f1, f32 f2, f32 f3) {
    s32 id;
    id = Script_SendEvent_2_00166F80(H(a0), 0x2026, a0);
    Script_SetArgU8_1_00165070(H(a0), id, 0, a1);
    if (f0 > 1.0f) f0 = 1.0f;
    if (f0 < 0.0f) f0 = 0.0f;
    Script_SetArgU8_1_00165070(H(a0), id, 1, cv(100.0f * f0));
    if (f1 > 1.2f) f1 = 1.2f;
    Script_SetArgU8_1_00165070(H(a0), id, 2, cv(100.0f * f1));
    if (f2 > 1.2f) f2 = 1.2f;
    Script_SetArgU8_1_00165070(H(a0), id, 3, cv(100.0f * f2));
    Script_SetArgU16_1_001650F0(H(a0), id, 4, (u32)f3);
    Script_SetArgU8_1_00165070(H(a0), id, 5, a2);
    while (Script_RunEvent_2_00166C10(H(a0), id) != 0) {}
    return Script_GetResultU8_1_00164FC0(H(a0), id, 0);
}

/* EnemyScr_Event2025_1_00140770 */
#define H(a) (*(a)->p)

void EnemyScr_Event2025_1_00140770(Obj_EnemyScr_Event2025_1_00140770 *a0, s8 *a1, u32 a2, u32 a3, u32 a4) {
    s32 id;
    id = Script_SendEvent_2_00166F80(H(a0), 0x2025, a0);
    Script_SetArgS8_1_00165030(H(a0), id, 0, a1[0]);
    Script_SetArgS8_1_00165030(H(a0), id, 1, a1[1]);
    Script_SetArgS8_1_00165030(H(a0), id, 2, a1[2]);
    Script_SetArgS8_1_00165030(H(a0), id, 3, a1[3]);
    Script_SetArgS8_1_00165030(H(a0), id, 4, a1[4]);
    Script_SetArgS8_1_00165030(H(a0), id, 5, a1[5]);
    Script_SetArgS8_1_00165030(H(a0), id, 6, a1[6]);
    Script_SetArgU8_1_00165070(H(a0), id, 7, a2);
    Script_SetArgU8_1_00165070(H(a0), id, 8, a3);
    Script_SetArgU8_1_00165070(H(a0), id, 9, a4);
    while (Script_RunEvent_2_00166C10(H(a0), id) != 0) {}
    a1[0] = Script_GetResultS8_1_00164F90(H(a0), id, 0);
    a1[1] = Script_GetResultS8_1_00164F90(H(a0), id, 1);
    a1[2] = Script_GetResultS8_1_00164F90(H(a0), id, 2);
    a1[3] = Script_GetResultS8_1_00164F90(H(a0), id, 3);
    a1[4] = Script_GetResultS8_1_00164F90(H(a0), id, 4);
    a1[5] = Script_GetResultS8_1_00164F90(H(a0), id, 5);
    a1[6] = Script_GetResultS8_1_00164F90(H(a0), id, 6);
}

/* EnemyScr_Event2024GetMove_1_001409A0 */
#define Script_GetResultU8_1_00164FC0 Script_GetResultU8_1_00164FC0__as_EnemyScr_Event2024GetMove_1_001409A0
u8 Script_GetResultU8_1_00164FC0__as_EnemyScr_Event2024GetMove_1_001409A0(void *, u8, s32);
static inline u16 mk_EnemyScr_Event2024GetMove_1_001409A0(u16 lo, u16 hi) { return (u8)lo | ((u8)hi << 8); }
#define H(a) (*(a)->p)

u16 EnemyScr_Event2024GetMove_1_001409A0(Obj_EnemyScr_Event2024GetMove_1_001409A0 *a0, s32 a1, f32 *px, f32 *py, f32 *pz) {
    s32 h4;
    s32 h5;
    u16 r;
    h5 = Script_SendEvent_2_00166F80(H(a0), 0x2024, a0);
    h4 = Script_SendEvent_2_00166F80(H(a0), 0x2020, a0);
    Script_SetArgU8_1_00165070(H(a0), h4, 0, 0);
    while (Script_RunEvent_2_00166C10(H(a0), h4) != 0) {}
    if ((u8)Script_GetResultU8_1_00164FC0(H(a0), h4, 0) != 0) {
        Script_SetArgU8_1_00165070(H(a0), h5, 0, 1);
        Script_SetArgU8_1_00165070(H(a0), h5, 1, 1);
        Script_SetArgU8_1_00165070(H(a0), h5, 2, a1);
        Script_SetArgF32_1_00164FF0(H(a0), h5, 3, Enemy_GetPositionPtr_2_00140460(a0)[0]);
        Script_SetArgF32_1_00164FF0(H(a0), h5, 4, Enemy_GetPositionPtr_2_00140460(a0)[2]);
        Script_SetArgF32_1_00164FF0(H(a0), h5, 5, Enemy_GetRotationPtr_1_00140430(a0)[1]);
    } else {
        Script_SetArgU8_1_00165070(H(a0), h5, 0, 8);
        Script_SetArgU8_1_00165070(H(a0), h5, 1, 6);
        Script_SetArgU8_1_00165070(H(a0), h5, 2, a1);
        Script_SetArgF32_1_00164FF0(H(a0), h5, 3, Enemy_PtrVec660_1_00140340(a0)[0]);
        Script_SetArgF32_1_00164FF0(H(a0), h5, 4, Enemy_PtrVec660_1_00140340(a0)[2]);
        Script_SetArgF32_1_00164FF0(H(a0), h5, 5, Enemy_PtrVec670_1_00140320(a0)[1]);
    }
    while (Script_RunEvent_2_00166C10(H(a0), h5) != 0) {}
    h4 = Script_GetResultU8_1_00164FC0(H(a0), h5, 0);
    r = mk_EnemyScr_Event2024GetMove_1_001409A0(h4, Script_GetResultU8_1_00164FC0(H(a0), h5, 1));
    if (px) *px = Script_GetResultF32_1_00164F60(H(a0), h5, 3);
    if (py) *py = Script_GetResultF32_1_00164F60(H(a0), h5, 4);
    if (pz) *pz = Script_GetResultF32_1_00164F60(H(a0), h5, 5);
    return r;
}
#undef Script_GetResultU8_1_00164FC0

/* EnemyScr_Event2023_1_00140CB0 */
#define Script_GetResultU8_1_00164FC0 Script_GetResultU8_1_00164FC0__as_EnemyScr_Event2023_1_00140CB0
u8 Script_GetResultU8_1_00164FC0__as_EnemyScr_Event2023_1_00140CB0(void *, u8, s32);
#define H(a) (*(a)->p)

void EnemyScr_Event2023_1_00140CB0(Obj_EnemyScr_Event2023_1_00140CB0 *a0, u8 *pa, f32 *pb, f32 *pc) {
    s32 h;
    h = Script_SendEvent_2_00166F80(H(a0), 0x2023, a0);
    Script_SetArgU8_1_00165070(H(a0), h, 0, 0);
    Script_SetArgF32_1_00164FF0(H(a0), h, 1, 2.0f);
    Script_SetArgF32_1_00164FF0(H(a0), h, 2, 0.0f);
    while (Script_RunEvent_2_00166C10(H(a0), h) != 0) {}
    if (pa) *pa = Script_GetResultU8_1_00164FC0(H(a0), h, 0);
    if (pb) *pb = Script_GetResultF32_1_00164F60(H(a0), h, 1);
    if (pc) *pc = Script_GetResultF32_1_00164F60(H(a0), h, 2);
}
#undef Script_GetResultU8_1_00164FC0

/* EnemyScr_Event2022_1_00140DE0 */
#define Script_SendEvent_2_00166F80 Script_SendEvent_2_00166F80__as_EnemyScr_Event2022_1_00140DE0
s32 Script_SendEvent_2_00166F80__as_EnemyScr_Event2022_1_00140DE0(s32 a, s32 b, Obj_EnemyScr_Event2022_1_00140DE0 *o);
#define Script_RunEvent_2_00166C10 Script_RunEvent_2_00166C10__as_EnemyScr_Event2022_1_00140DE0
s32 Script_RunEvent_2_00166C10__as_EnemyScr_Event2022_1_00140DE0(s32 a, s32 h);

void EnemyScr_Event2022_1_00140DE0(Obj_EnemyScr_Event2022_1_00140DE0 *o)
{
    s32 h = Script_SendEvent_2_00166F80(*o->p, 0x2022, o);
    while ((s8)Script_RunEvent_2_00166C10(*o->p, h)) {
    }
}
#undef Script_SendEvent_2_00166F80
#undef Script_RunEvent_2_00166C10

/* EnemyScr_Event2021_1_00140E50 */
#define Script_SendEvent_2_00166F80 Script_SendEvent_2_00166F80__as_EnemyScr_Event2021_1_00140E50
s32 Script_SendEvent_2_00166F80__as_EnemyScr_Event2021_1_00140E50(s32 a, s32 b, Obj_EnemyScr_Event2021_1_00140E50 *o);
#define Script_SetArgU8_1_00165070 Script_SetArgU8_1_00165070__as_EnemyScr_Event2021_1_00140E50
void Script_SetArgU8_1_00165070__as_EnemyScr_Event2021_1_00140E50(s32 a, u8 h, s32 c, s32 d);
#define Script_RunEvent_2_00166C10 Script_RunEvent_2_00166C10__as_EnemyScr_Event2021_1_00140E50
s32 Script_RunEvent_2_00166C10__as_EnemyScr_Event2021_1_00140E50(s32 a, s32 h);
#define Script_GetResultU8_1_00164FC0 Script_GetResultU8_1_00164FC0__as_EnemyScr_Event2021_1_00140E50
s32 Script_GetResultU8_1_00164FC0__as_EnemyScr_Event2021_1_00140E50(s32 a, u8 h, u8 c);

u8 EnemyScr_Event2021_1_00140E50(Obj_EnemyScr_Event2021_1_00140E50 *o)
{
    s32 h = Script_SendEvent_2_00166F80(*o->p, 0x2021, o);
    Script_SetArgU8_1_00165070(*o->p, h, 0, 0);
    while ((s8)Script_RunEvent_2_00166C10(*o->p, h)) {
    }
    return (u8)Script_GetResultU8_1_00164FC0(*o->p, h, 0);
}
#undef Script_SendEvent_2_00166F80
#undef Script_SetArgU8_1_00165070
#undef Script_RunEvent_2_00166C10
#undef Script_GetResultU8_1_00164FC0

/* EnemyScr_Event2020_1_00140EF0 */
#define Script_SendEvent_2_00166F80 Script_SendEvent_2_00166F80__as_EnemyScr_Event2020_1_00140EF0
s32 Script_SendEvent_2_00166F80__as_EnemyScr_Event2020_1_00140EF0(s32 a, s32 b, Obj_EnemyScr_Event2020_1_00140EF0 *o);
#define Script_SetArgU8_1_00165070 Script_SetArgU8_1_00165070__as_EnemyScr_Event2020_1_00140EF0
void Script_SetArgU8_1_00165070__as_EnemyScr_Event2020_1_00140EF0(s32 a, u8 h, s32 c, s32 d);
#define Script_RunEvent_2_00166C10 Script_RunEvent_2_00166C10__as_EnemyScr_Event2020_1_00140EF0
s32 Script_RunEvent_2_00166C10__as_EnemyScr_Event2020_1_00140EF0(s32 a, s32 h);
#define Script_GetResultU8_1_00164FC0 Script_GetResultU8_1_00164FC0__as_EnemyScr_Event2020_1_00140EF0
s32 Script_GetResultU8_1_00164FC0__as_EnemyScr_Event2020_1_00140EF0(s32 a, u8 h, u8 c);

u8 EnemyScr_Event2020_1_00140EF0(Obj_EnemyScr_Event2020_1_00140EF0 *o)
{
    s32 h = Script_SendEvent_2_00166F80(*o->p, 0x2020, o);
    Script_SetArgU8_1_00165070(*o->p, h, 0, 0);
    while ((s8)Script_RunEvent_2_00166C10(*o->p, h)) {
    }
    return (u8)Script_GetResultU8_1_00164FC0(*o->p, h, 0);
}
#undef Script_SendEvent_2_00166F80
#undef Script_SetArgU8_1_00165070
#undef Script_RunEvent_2_00166C10
#undef Script_GetResultU8_1_00164FC0

/* EnemyScr_BroadcastMotionEvent_0_00140F90 */
#define Ent_IsNull0_1_0013EE30 Ent_IsNull0_1_0013EE30__as_EnemyScr_BroadcastMotionEvent_0_00140F90
s32 Ent_IsNull0_1_0013EE30__as_EnemyScr_BroadcastMotionEvent_0_00140F90(s8 *);
#define Enemy_GetTargetHandle_0_0013EDE0 Enemy_GetTargetHandle_0_0013EDE0__as_EnemyScr_BroadcastMotionEvent_0_00140F90
s32 Enemy_GetTargetHandle_0_0013EDE0__as_EnemyScr_BroadcastMotionEvent_0_00140F90(s8 *);
#define Script_RunEvent_2_00166C10 Script_RunEvent_2_00166C10__as_EnemyScr_BroadcastMotionEvent_0_00140F90
s32 Script_RunEvent_2_00166C10__as_EnemyScr_BroadcastMotionEvent_0_00140F90(void *, s32);
#define H(o) (**(void ***)((o) + 0x4A4))

void EnemyScr_BroadcastMotionEvent_0_00140F90(u8 a, u8 b, u32 c, u32 d) {
    s32 it;
    s8 *o;
    s32 h;
    it = 0;
    o = ActorList_Next_2_001A5460(&it);
    while (o != NULL) {
        if (!Ent_IsNull0_1_0013EE30(o) && a == Enemy_GetTargetHandle_0_0013EDE0(o) && b == (u8)Enemy_GetMotionId_0_0013ED20(o)) {
            h = Script_SendEvent_2_00166F80(H(o), 0x2019, o);
            Script_SetArgU8_1_00165070(H(o), h, 0, c);
            Script_SetArgU8_1_00165070(H(o), h, 1, d);
            while ((s8)Script_RunEvent_2_00166C10(H(o), h)) {
            }
            return;
        }
        o = ActorList_Next_2_001A5460(&it);
    }
}
#undef Ent_IsNull0_1_0013EE30
#undef Enemy_GetTargetHandle_0_0013EDE0
#undef Script_RunEvent_2_00166C10

/* EnemyScr_BroadcastFrameEvent_0_001410C0 */
#define H(a) (*(a)->p)
#define ActorList_Next_2_001A5460 ActorList_Next_2_001A5460__as_EnemyScr_BroadcastFrameEvent_0_001410C0
Obj_EnemyScr_BroadcastFrameEvent_0_001410C0 *ActorList_Next_2_001A5460__as_EnemyScr_BroadcastFrameEvent_0_001410C0(s32 *);
#define Ent_IsNull0_1_0013EE30 Ent_IsNull0_1_0013EE30__as_EnemyScr_BroadcastFrameEvent_0_001410C0
s32 Ent_IsNull0_1_0013EE30__as_EnemyScr_BroadcastFrameEvent_0_001410C0(Obj_EnemyScr_BroadcastFrameEvent_0_001410C0 *);
#define Enemy_GetTargetHandle_0_0013EDE0 Enemy_GetTargetHandle_0_0013EDE0__as_EnemyScr_BroadcastFrameEvent_0_001410C0
s32 Enemy_GetTargetHandle_0_0013EDE0__as_EnemyScr_BroadcastFrameEvent_0_001410C0(Obj_EnemyScr_BroadcastFrameEvent_0_001410C0 *);

void EnemyScr_BroadcastFrameEvent_0_001410C0(u8 a0, u8 a1, u32 a2, u32 a3) {
    s32 it;
    Obj_EnemyScr_BroadcastFrameEvent_0_001410C0 *cur;
    s32 id;
    it = 0;
    cur = ActorList_Next_2_001A5460(&it);
    if (cur != NULL) {
        do {
            if (!Ent_IsNull0_1_0013EE30(cur) && Enemy_GetTargetHandle_0_0013EDE0(cur) == a0 && (u8)Enemy_GetMotionFrame_0_0013ECA0(cur) == a1) {
                id = Script_SendEvent_2_00166F80(H(cur), 0x2019, cur);
                Script_SetArgU8_1_00165070(H(cur), id, 0, a2);
                Script_SetArgU8_1_00165070(H(cur), id, 1, a3);
                while (Script_RunEvent_2_00166C10(H(cur), id) != 0) {}
            }
            cur = ActorList_Next_2_001A5460(&it);
        } while (cur != NULL);
    }
}
#undef ActorList_Next_2_001A5460
#undef Ent_IsNull0_1_0013EE30
#undef Enemy_GetTargetHandle_0_0013EDE0

/* EnemyScr_Event2018_1_001411F0 */
#define Script_SendEvent_2_00166F80 Script_SendEvent_2_00166F80__as_EnemyScr_Event2018_1_001411F0
s32 Script_SendEvent_2_00166F80__as_EnemyScr_Event2018_1_001411F0(s32 a, s32 b, Obj_EnemyScr_Event2018_1_001411F0 *o);
#define Script_RunEvent_2_00166C10 Script_RunEvent_2_00166C10__as_EnemyScr_Event2018_1_001411F0
s32 Script_RunEvent_2_00166C10__as_EnemyScr_Event2018_1_001411F0(s32 a, s32 h);

void EnemyScr_Event2018_1_001411F0(Obj_EnemyScr_Event2018_1_001411F0 *o)
{
    s32 h = Script_SendEvent_2_00166F80(*o->p, 0x2018, o);
    while ((s8)Script_RunEvent_2_00166C10(*o->p, h)) {
    }
}
#undef Script_SendEvent_2_00166F80
#undef Script_RunEvent_2_00166C10

/* EnemyScr_Event2017OnDeath_1_00141260 */
#define Script_SendEvent_2_00166F80 Script_SendEvent_2_00166F80__as_EnemyScr_Event2017OnDeath_1_00141260
s32 Script_SendEvent_2_00166F80__as_EnemyScr_Event2017OnDeath_1_00141260(s32 a, s32 b, Obj_EnemyScr_Event2017OnDeath_1_00141260 *o);
#define Script_SetArgU8_1_00165070 Script_SetArgU8_1_00165070__as_EnemyScr_Event2017OnDeath_1_00141260
void Script_SetArgU8_1_00165070__as_EnemyScr_Event2017OnDeath_1_00141260(s32 a, u8 h, s32 c, s32 d);
#define Script_RunEvent_2_00166C10 Script_RunEvent_2_00166C10__as_EnemyScr_Event2017OnDeath_1_00141260
s32 Script_RunEvent_2_00166C10__as_EnemyScr_Event2017OnDeath_1_00141260(s32 a, s32 h);

void EnemyScr_Event2017OnDeath_1_00141260(Obj_EnemyScr_Event2017OnDeath_1_00141260 *o, s32 d)
{
    s32 h = Script_SendEvent_2_00166F80(*o->p, 0x2017, o);
    Script_SetArgU8_1_00165070(*o->p, h, 0, d);
    while ((s8)Script_RunEvent_2_00166C10(*o->p, h)) {
    }
}
#undef Script_SendEvent_2_00166F80
#undef Script_SetArgU8_1_00165070
#undef Script_RunEvent_2_00166C10

/* EnemyScr_Event2016_1_001412E0 */
#define Script_SendEvent_2_00166F80 Script_SendEvent_2_00166F80__as_EnemyScr_Event2016_1_001412E0
s32 Script_SendEvent_2_00166F80__as_EnemyScr_Event2016_1_001412E0(s32 a, s32 b, Obj_EnemyScr_Event2016_1_001412E0 *o);
#define Script_SetArgU8_1_00165070 Script_SetArgU8_1_00165070__as_EnemyScr_Event2016_1_001412E0
void Script_SetArgU8_1_00165070__as_EnemyScr_Event2016_1_001412E0(s32 a, u8 h, s32 c, s32 d);
#define Script_RunEvent_2_00166C10 Script_RunEvent_2_00166C10__as_EnemyScr_Event2016_1_001412E0
s32 Script_RunEvent_2_00166C10__as_EnemyScr_Event2016_1_001412E0(s32 a, s32 h);
#define Script_GetResultU8_1_00164FC0 Script_GetResultU8_1_00164FC0__as_EnemyScr_Event2016_1_001412E0
s32 Script_GetResultU8_1_00164FC0__as_EnemyScr_Event2016_1_001412E0(s32 a, u8 h, u8 c);

u8 EnemyScr_Event2016_1_001412E0(Obj_EnemyScr_Event2016_1_001412E0 *o)
{
    s32 h = Script_SendEvent_2_00166F80(*o->p, 0x2016, o);
    Script_SetArgU8_1_00165070(*o->p, h, 0, 0);
    while ((s8)Script_RunEvent_2_00166C10(*o->p, h)) {
    }
    return (u8)Script_GetResultU8_1_00164FC0(*o->p, h, 0);
}
#undef Script_SendEvent_2_00166F80
#undef Script_SetArgU8_1_00165070
#undef Script_RunEvent_2_00166C10
#undef Script_GetResultU8_1_00164FC0

/* EnemyScr_BroadcastQuery_0_00141380 */
#define H(a) (*(a)->p)
#define ActorList_Next_2_001A5460 ActorList_Next_2_001A5460__as_EnemyScr_BroadcastQuery_0_00141380
Obj_EnemyScr_BroadcastQuery_0_00141380 *ActorList_Next_2_001A5460__as_EnemyScr_BroadcastQuery_0_00141380(s32 *);
#define Ent_IsNull0_1_0013EE30 Ent_IsNull0_1_0013EE30__as_EnemyScr_BroadcastQuery_0_00141380
s32 Ent_IsNull0_1_0013EE30__as_EnemyScr_BroadcastQuery_0_00141380(Obj_EnemyScr_BroadcastQuery_0_00141380 *);
#define Enemy_GetTargetHandle_0_0013EDE0 Enemy_GetTargetHandle_0_0013EDE0__as_EnemyScr_BroadcastQuery_0_00141380
s32 Enemy_GetTargetHandle_0_0013EDE0__as_EnemyScr_BroadcastQuery_0_00141380(Obj_EnemyScr_BroadcastQuery_0_00141380 *);

u8 EnemyScr_BroadcastQuery_0_00141380(u32 a0, u32 a1) {
    s32 it;
    u8 n;
    Obj_EnemyScr_BroadcastQuery_0_00141380 *cur;
    s32 k;
    s32 id;
    u8 v;
    n = 0;
    it = 0;
    cur = ActorList_Next_2_001A5460(&it);
    if (cur != NULL) {
        do {
            if (!Ent_IsNull0_1_0013EE30(cur)) {
                k = (u8)Enemy_GetTargetHandle_0_0013EDE0(cur);
                v = Ent_GetTypeByte_1_0013E220(cur);
                if (v >= 0x25 && v <= 0x28 && !Enemy_IsDead_1_0013EEE0(cur)) {
                    id = Script_SendEvent_2_00166F80(H(cur), 0x2015, cur);
                    Script_SetArgU8_1_00165070(H(cur), id, 0, 0);
                    Script_SetArgU8_1_00165070(H(cur), id, 1, k);
                    Script_SetArgU8_1_00165070(H(cur), id, 2, a0);
                    Script_SetArgU8_1_00165070(H(cur), id, 3, a1);
                    while (Script_RunEvent_2_00166C10(H(cur), id) != 0) {}
                    n += (u8)Script_GetResultU8_1_00164FC0(H(cur), id, 0);
                }
            }
            cur = ActorList_Next_2_001A5460(&it);
        } while (cur != NULL);
    }
    return n;
}
#undef ActorList_Next_2_001A5460
#undef Ent_IsNull0_1_0013EE30
#undef Enemy_GetTargetHandle_0_0013EDE0

/* EnemyScr_Event2015_1_00141510 */
#define H(a) (*(a)->p)

u8 EnemyScr_Event2015_1_00141510(Obj_EnemyScr_Event2015_1_00141510 *a0, u32 a1, u32 a2, u32 a3) {
    s32 id;
    id = Script_SendEvent_2_00166F80(H(a0), 0x2015, a0);
    Script_SetArgU8_1_00165070(H(a0), id, 0, 0);
    Script_SetArgU8_1_00165070(H(a0), id, 1, a1);
    Script_SetArgU8_1_00165070(H(a0), id, 2, a2);
    Script_SetArgU8_1_00165070(H(a0), id, 3, a3);
    while (Script_RunEvent_2_00166C10(H(a0), id) != 0) {}
    return Script_GetResultU8_1_00164FC0(H(a0), id, 0);
}

/* EnemyScr_Event2014_1_00141610 */
#define Script_SendEvent_2_00166F80 Script_SendEvent_2_00166F80__as_EnemyScr_Event2014_1_00141610
s32 Script_SendEvent_2_00166F80__as_EnemyScr_Event2014_1_00141610(s32 a, s32 b, Obj_EnemyScr_Event2014_1_00141610 *o);
#define Script_SetArgU8_1_00165070 Script_SetArgU8_1_00165070__as_EnemyScr_Event2014_1_00141610
void Script_SetArgU8_1_00165070__as_EnemyScr_Event2014_1_00141610(s32 a, u8 h, s32 c, s32 d);
#define Script_RunEvent_2_00166C10 Script_RunEvent_2_00166C10__as_EnemyScr_Event2014_1_00141610
s32 Script_RunEvent_2_00166C10__as_EnemyScr_Event2014_1_00141610(s32 a, s32 h);
#define Script_GetResultU8_1_00164FC0 Script_GetResultU8_1_00164FC0__as_EnemyScr_Event2014_1_00141610
s32 Script_GetResultU8_1_00164FC0__as_EnemyScr_Event2014_1_00141610(s32 a, u8 h, u8 c);

u8 EnemyScr_Event2014_1_00141610(Obj_EnemyScr_Event2014_1_00141610 *o)
{
    s32 h = Script_SendEvent_2_00166F80(*o->p, 0x2014, o);
    Script_SetArgU8_1_00165070(*o->p, h, 0, 0);
    while ((s8)Script_RunEvent_2_00166C10(*o->p, h)) {
    }
    return (u8)Script_GetResultU8_1_00164FC0(*o->p, h, 0);
}
#undef Script_SendEvent_2_00166F80
#undef Script_SetArgU8_1_00165070
#undef Script_RunEvent_2_00166C10
#undef Script_GetResultU8_1_00164FC0

/* EnemyScr_Event2013GetMove_1_001416B0 */
#define Script_GetResultU8_1_00164FC0 Script_GetResultU8_1_00164FC0__as_EnemyScr_Event2013GetMove_1_001416B0
u8 Script_GetResultU8_1_00164FC0__as_EnemyScr_Event2013GetMove_1_001416B0(void *, u8, s32);
static inline u16 mk_EnemyScr_Event2013GetMove_1_001416B0(u16 lo, u16 hi) { return (u8)lo | ((u8)hi << 8); }
#define H(a) (*(a)->p)

u16 EnemyScr_Event2013GetMove_1_001416B0(Obj_EnemyScr_Event2013GetMove_1_001416B0 *a0, s32 a1, f32 *px, f32 *py, f32 *pz) {
    s32 h4;
    s32 h5;
    u16 r;
    h5 = Script_SendEvent_2_00166F80(H(a0), 0x2013, a0);
    h4 = Script_SendEvent_2_00166F80(H(a0), 0x2020, a0);
    Script_SetArgU8_1_00165070(H(a0), h4, 0, 0);
    while (Script_RunEvent_2_00166C10(H(a0), h4) != 0) {}
    if ((u8)Script_GetResultU8_1_00164FC0(H(a0), h4, 0) != 0) {
        Script_SetArgU8_1_00165070(H(a0), h5, 0, 1);
        Script_SetArgU8_1_00165070(H(a0), h5, 1, 1);
        Script_SetArgU8_1_00165070(H(a0), h5, 2, a1);
        Script_SetArgF32_1_00164FF0(H(a0), h5, 3, Enemy_GetPositionPtr_2_00140460(a0)[0]);
        Script_SetArgF32_1_00164FF0(H(a0), h5, 4, Enemy_GetPositionPtr_2_00140460(a0)[2]);
        Script_SetArgF32_1_00164FF0(H(a0), h5, 5, Enemy_GetRotationPtr_1_00140430(a0)[1]);
    } else {
        Script_SetArgU8_1_00165070(H(a0), h5, 0, 8);
        Script_SetArgU8_1_00165070(H(a0), h5, 1, 6);
        Script_SetArgU8_1_00165070(H(a0), h5, 2, a1);
        Script_SetArgF32_1_00164FF0(H(a0), h5, 3, Enemy_PtrVec660_1_00140340(a0)[0]);
        Script_SetArgF32_1_00164FF0(H(a0), h5, 4, Enemy_PtrVec660_1_00140340(a0)[2]);
        Script_SetArgF32_1_00164FF0(H(a0), h5, 5, Enemy_PtrVec670_1_00140320(a0)[1]);
    }
    while (Script_RunEvent_2_00166C10(H(a0), h5) != 0) {}
    h4 = Script_GetResultU8_1_00164FC0(H(a0), h5, 0);
    r = mk_EnemyScr_Event2013GetMove_1_001416B0(h4, Script_GetResultU8_1_00164FC0(H(a0), h5, 1));
    if (px) *px = Script_GetResultF32_1_00164F60(H(a0), h5, 3);
    if (py) *py = Script_GetResultF32_1_00164F60(H(a0), h5, 4);
    if (pz) *pz = Script_GetResultF32_1_00164F60(H(a0), h5, 5);
    return r;
}
#undef Script_GetResultU8_1_00164FC0

/* EnemyScr_Event2012_1_001419C0 */
#define H(a) (*(a)->p)
void EnemyScr_Event2012_1_001419C0(Obj_EnemyScr_Event2012_1_001419C0 *a0, f32 f) {
    s32 id;
    id = Script_SendEvent_2_00166F80(H(a0), 0x2012, a0);
    Script_SetArgF32_1_00164FF0(H(a0), id, 0, f);
    while (Script_RunEvent_2_00166C10(H(a0), id) != 0) {}
}

/* EnemyScr_Event2011GetWeights_1_00141A50 */
#define Script_GetResultU8_1_00164FC0 Script_GetResultU8_1_00164FC0__as_EnemyScr_Event2011GetWeights_1_00141A50
u8 Script_GetResultU8_1_00164FC0__as_EnemyScr_Event2011GetWeights_1_00141A50(void *, u8, s32);
#define H(a) (*(a)->p)

void EnemyScr_Event2011GetWeights_1_00141A50(Obj_EnemyScr_Event2011GetWeights_1_00141A50 *a0, f32 *p0, f32 *p1, f32 *p2, f32 *p3, f32 *p4) {
    s32 h;
    u32 v0, v1, v2, v3, v4;
    h = Script_SendEvent_2_00166F80(H(a0), 0x2011, a0);
    Script_SetArgU8_1_00165070(H(a0), h, 0, 100);
    Script_SetArgU8_1_00165070(H(a0), h, 1, 100);
    Script_SetArgU8_1_00165070(H(a0), h, 2, 100);
    Script_SetArgU8_1_00165070(H(a0), h, 3, 100);
    Script_SetArgU8_1_00165070(H(a0), h, 4, 100);
    while (Script_RunEvent_2_00166C10(H(a0), h) != 0) {}
    v0 = Script_GetResultU8_1_00164FC0(H(a0), h, 0);
    v1 = Script_GetResultU8_1_00164FC0(H(a0), h, 1);
    v2 = Script_GetResultU8_1_00164FC0(H(a0), h, 2);
    v3 = Script_GetResultU8_1_00164FC0(H(a0), h, 3);
    v4 = Script_GetResultU8_1_00164FC0(H(a0), h, 4);
    if (p0) *p0 = v0 / 100.0f;
    if (p1) *p1 = v1 / 100.0f;
    if (p2) *p2 = v2 / 100.0f;
    if (p3) *p3 = v3 / 100.0f;
    if (p4) *p4 = v4 / 100.0f;
    if (((u8)Enemy_Get5B5mF_1_0013E5E0(a0) & 2) && p0) *p0 /= 2.0f;
}
#undef Script_GetResultU8_1_00164FC0

/* EnemyScr_Event2010_1_00141DA0 */
#define Script_SendEvent_2_00166F80 Script_SendEvent_2_00166F80__as_EnemyScr_Event2010_1_00141DA0
s32 Script_SendEvent_2_00166F80__as_EnemyScr_Event2010_1_00141DA0(s32 a, s32 b, Obj_EnemyScr_Event2010_1_00141DA0 *o);
#define Script_RunEvent_2_00166C10 Script_RunEvent_2_00166C10__as_EnemyScr_Event2010_1_00141DA0
s32 Script_RunEvent_2_00166C10__as_EnemyScr_Event2010_1_00141DA0(s32 a, s32 h);

void EnemyScr_Event2010_1_00141DA0(Obj_EnemyScr_Event2010_1_00141DA0 *o)
{
    s32 h = Script_SendEvent_2_00166F80(*o->p, 0x2010, o);
    while ((s8)Script_RunEvent_2_00166C10(*o->p, h)) {
    }
}
#undef Script_SendEvent_2_00166F80
#undef Script_RunEvent_2_00166C10

/* EnemyScr_Event200F_1_00141E10 */
#define Script_SendEvent_2_00166F80 Script_SendEvent_2_00166F80__as_EnemyScr_Event200F_1_00141E10
s32 Script_SendEvent_2_00166F80__as_EnemyScr_Event200F_1_00141E10(s32, s32, A *);
#define Script_SetArgU8_1_00165070 Script_SetArgU8_1_00165070__as_EnemyScr_Event200F_1_00141E10
void Script_SetArgU8_1_00165070__as_EnemyScr_Event200F_1_00141E10(s32, u8, s32, s32);
#define Script_SetArgU16_1_001650F0 Script_SetArgU16_1_001650F0__as_EnemyScr_Event200F_1_00141E10
void Script_SetArgU16_1_001650F0__as_EnemyScr_Event200F_1_00141E10(s32, u8, s32, u16);
#define Script_SetArgF32_1_00164FF0 Script_SetArgF32_1_00164FF0__as_EnemyScr_Event200F_1_00141E10
void Script_SetArgF32_1_00164FF0__as_EnemyScr_Event200F_1_00141E10(s32, u8, s32, f32);
#define Script_RunEvent_2_00166C10 Script_RunEvent_2_00166C10__as_EnemyScr_Event200F_1_00141E10
s32 Script_RunEvent_2_00166C10__as_EnemyScr_Event200F_1_00141E10(s32, s32);

void EnemyScr_Event200F_1_00141E10(A *a, s32 a1, f32 x, f32 y, f32 z, f32 w) {
    s32 h;
    u16 p;
    s32 q;
    h = Script_SendEvent_2_00166F80(*a->x4A4, 0x200F, a);
    p = (x < 30000.0f) ? (u16)(u32)x : 30000;

    q = (z < 30000.0f) ? (u16)(u32)z : 30000;
    Script_SetArgU8_1_00165070(*a->x4A4, h, 0, a1);
    Script_SetArgU16_1_001650F0(*a->x4A4, h, 1, p);
    Script_SetArgF32_1_00164FF0(*a->x4A4, h, 2, y);
    Script_SetArgF32_1_00164FF0(*a->x4A4, h, 3, w);
    Script_SetArgU16_1_001650F0(*a->x4A4, h, 4, q);
    while ((s8)Script_RunEvent_2_00166C10(*a->x4A4, h)) {
    }
}
#undef Script_SendEvent_2_00166F80
#undef Script_SetArgU8_1_00165070
#undef Script_SetArgU16_1_001650F0
#undef Script_SetArgF32_1_00164FF0
#undef Script_RunEvent_2_00166C10

/* EnemyScr_Event200E_1_00142010 */
#define Script_SendEvent_2_00166F80 Script_SendEvent_2_00166F80__as_EnemyScr_Event200E_1_00142010
s32 Script_SendEvent_2_00166F80__as_EnemyScr_Event200E_1_00142010(s32 a, s32 b, Obj_EnemyScr_Event200E_1_00142010 *o);
#define Script_SetArgU8_1_00165070 Script_SetArgU8_1_00165070__as_EnemyScr_Event200E_1_00142010
void Script_SetArgU8_1_00165070__as_EnemyScr_Event200E_1_00142010(s32 a, u8 h, s32 c, s32 d);
#define Script_RunEvent_2_00166C10 Script_RunEvent_2_00166C10__as_EnemyScr_Event200E_1_00142010
s32 Script_RunEvent_2_00166C10__as_EnemyScr_Event200E_1_00142010(s32 a, s32 h);

void EnemyScr_Event200E_1_00142010(Obj_EnemyScr_Event200E_1_00142010 *o, s32 d)
{
    s32 h = Script_SendEvent_2_00166F80(*o->p, 0x200E, o);
    Script_SetArgU8_1_00165070(*o->p, h, 0, d);
    while ((s8)Script_RunEvent_2_00166C10(*o->p, h)) {
    }
}
#undef Script_SendEvent_2_00166F80
#undef Script_SetArgU8_1_00165070
#undef Script_RunEvent_2_00166C10

/* EnemyScr_Event200DGetStats_1_00142090 */
#define Script_GetResultU8_1_00164FC0 Script_GetResultU8_1_00164FC0__as_EnemyScr_Event200DGetStats_1_00142090
u8 Script_GetResultU8_1_00164FC0__as_EnemyScr_Event200DGetStats_1_00142090(void *, u8, s32);
static inline f32 u2f(u32 x) { return x; }
#define H(a) (*(a)->p)

void EnemyScr_Event200DGetStats_1_00142090(Obj_EnemyScr_Event200DGetStats_1_00142090 *a0, f32 *p0, f32 *p1, f32 *p2, f32 *p3) {
    s32 id;
    u32 a, b, c, d;
    id = Script_SendEvent_2_00166F80(H(a0), 0x200D, a0);
    Script_SetArgU8_1_00165070(H(a0), id, 0, 100);
    Script_SetArgU8_1_00165070(H(a0), id, 1, 100);
    Script_SetArgU8_1_00165070(H(a0), id, 2, 100);
    Script_SetArgU8_1_00165070(H(a0), id, 3, 100);
    while (Script_RunEvent_2_00166C10(H(a0), id) != 0) {}
    a = Script_GetResultU8_1_00164FC0(H(a0), id, 0);
    b = Script_GetResultU8_1_00164FC0(H(a0), id, 1);
    c = Script_GetResultU8_1_00164FC0(H(a0), id, 2);
    d = Script_GetResultU8_1_00164FC0(H(a0), id, 3);
    if (p0) *p0 = u2f(a) / 100.0f;
    if (p1) *p1 = u2f(b) / 100.0f;
    if (p2) *p2 = u2f(c) / 100.0f;
    if (p3) *p3 = u2f(d) / 100.0f;
}
#undef Script_GetResultU8_1_00164FC0

/* EnemyScr_Event200COnHit_1_00142320 */
#define H(a) (*(a)->p)
void EnemyScr_Event200COnHit_1_00142320(Obj_EnemyScr_Event200COnHit_1_00142320 *a0, s32 a1, s32 a2) {
    s32 id;
    id = Script_SendEvent_2_00166F80(H(a0), 0x200C, a0);
    Script_SetArgU8_1_00165070(H(a0), id, 0, a1);
    Script_SetArgU8_1_00165070(H(a0), id, 1, a2);
    while (Script_RunEvent_2_00166C10(H(a0), id) != 0) {}
    Enemy_Set5D8_1_0013E430(a0, Enemy_GetParam298_1_0013DD40(a0));
    Enemy_IncCounter6B8_1_0013EF50(a0);
}

/* EnemyScr_Event200B_1_001423E0 */
#define Script_SendEvent_2_00166F80 Script_SendEvent_2_00166F80__as_EnemyScr_Event200B_1_001423E0
s32 Script_SendEvent_2_00166F80__as_EnemyScr_Event200B_1_001423E0(s32 a, s32 b, Obj_EnemyScr_Event200B_1_001423E0 *o);
#define Script_SetArgU8_1_00165070 Script_SetArgU8_1_00165070__as_EnemyScr_Event200B_1_001423E0
void Script_SetArgU8_1_00165070__as_EnemyScr_Event200B_1_001423E0(s32 a, u8 h, s32 c, s32 d);
#define Script_RunEvent_2_00166C10 Script_RunEvent_2_00166C10__as_EnemyScr_Event200B_1_001423E0
s32 Script_RunEvent_2_00166C10__as_EnemyScr_Event200B_1_001423E0(s32 a, s32 h);

void EnemyScr_Event200B_1_001423E0(Obj_EnemyScr_Event200B_1_001423E0 *o, s32 d)
{
    s32 h = Script_SendEvent_2_00166F80(*o->p, 0x200B, o);
    Script_SetArgU8_1_00165070(*o->p, h, 0, d);
    while ((s8)Script_RunEvent_2_00166C10(*o->p, h)) {
    }
    Enemy_IncCounter6B9_1_0013EF10(o);
}
#undef Script_SendEvent_2_00166F80
#undef Script_SetArgU8_1_00165070
#undef Script_RunEvent_2_00166C10

/* EnemyScr_Event2009Move_1_00142470 */
#define H(a) (*(a)->p)
u8 EnemyScr_Event2009Move_1_00142470(Obj_EnemyScr_Event2009Move_1_00142470 *a0, s32 a1) {
    s32 id;
    id = Script_SendEvent_2_00166F80(H(a0), 0x2009, a0);
    Script_SetArgU8_1_00165070(H(a0), id, 0, 0);
    Script_SetArgS16_1_001650B0(H(a0), id, 1, a1);
    while (Script_RunEvent_2_00166C10(H(a0), id) != 0) {}
    return Script_GetResultU8_1_00164FC0(H(a0), id, 0);
}

/* EnemyScr_Event2005Turn_1_00142530 */
#define H(a) (*(a)->p)
u8 EnemyScr_Event2005Turn_1_00142530(Obj_EnemyScr_Event2005Turn_1_00142530 *a0, s32 a1) {
    s32 id;
    id = Script_SendEvent_2_00166F80(H(a0), 0x2005, a0);
    Script_SetArgU8_1_00165070(H(a0), id, 0, 0);
    Script_SetArgS16_1_001650B0(H(a0), id, 1, a1);
    while (Script_RunEvent_2_00166C10(H(a0), id) != 0) {}
    return Script_GetResultU8_1_00164FC0(H(a0), id, 0);
}

/* EnemyScr_Event2004Attack_1_001425F0 */
#define H(a) (*(a)->p)

u8 EnemyScr_Event2004Attack_1_001425F0(Obj_EnemyScr_Event2004Attack_1_001425F0 *a0, s32 a1, s32 a2) {
    s32 id;
    id = Script_SendEvent_2_00166F80(H(a0), 0x2004, a0);
    Script_SetArgU8_1_00165070(H(a0), id, 0, 0);
    Script_SetArgS16_1_001650B0(H(a0), id, 1, a2);
    Script_SetArgU8_1_00165070(H(a0), id, 2, (u8)a2);
    while (Script_RunEvent_2_00166C10(H(a0), id) != 0) {}
    return Script_GetResultU8_1_00164FC0(H(a0), id, 0);
}

/* EnemyScr_Event2003React_1_001426C0 */
#define H(a) (*(a)->p)
u8 EnemyScr_Event2003React_1_001426C0(Obj_EnemyScr_Event2003React_1_001426C0 *a0, s32 a1) {
    s32 id;
    id = Script_SendEvent_2_00166F80(H(a0), 0x2003, a0);
    Script_SetArgU8_1_00165070(H(a0), id, 0, 0);
    Script_SetArgS16_1_001650B0(H(a0), id, 1, a1);
    while (Script_RunEvent_2_00166C10(H(a0), id) != 0) {}
    return Script_GetResultU8_1_00164FC0(H(a0), id, 0);
}

/* EnemyScr_Event2002_1_00142780 */
#define Script_SendEvent_2_00166F80 Script_SendEvent_2_00166F80__as_EnemyScr_Event2002_1_00142780
s32 Script_SendEvent_2_00166F80__as_EnemyScr_Event2002_1_00142780(s32 a, s32 b, Obj_EnemyScr_Event2002_1_00142780 *o);
#define Script_SetArgU8_1_00165070 Script_SetArgU8_1_00165070__as_EnemyScr_Event2002_1_00142780
void Script_SetArgU8_1_00165070__as_EnemyScr_Event2002_1_00142780(s32 a, u8 h, s32 c, s32 d);
#define Script_RunEvent_2_00166C10 Script_RunEvent_2_00166C10__as_EnemyScr_Event2002_1_00142780
s32 Script_RunEvent_2_00166C10__as_EnemyScr_Event2002_1_00142780(s32 a, s32 h);
#define Script_GetResultU8_1_00164FC0 Script_GetResultU8_1_00164FC0__as_EnemyScr_Event2002_1_00142780
s32 Script_GetResultU8_1_00164FC0__as_EnemyScr_Event2002_1_00142780(s32 a, u8 h, u8 c);

u8 EnemyScr_Event2002_1_00142780(Obj_EnemyScr_Event2002_1_00142780 *o)
{
    s32 h = Script_SendEvent_2_00166F80(*o->p, 0x2002, o);
    Script_SetArgU8_1_00165070(*o->p, h, 0, 0);
    while ((s8)Script_RunEvent_2_00166C10(*o->p, h)) {
    }
    return (u8)Script_GetResultU8_1_00164FC0(*o->p, h, 0);
}
#undef Script_SendEvent_2_00166F80
#undef Script_SetArgU8_1_00165070
#undef Script_RunEvent_2_00166C10
#undef Script_GetResultU8_1_00164FC0

/* EnemyScr_Event2001_1_00142820 */
#define Script_SendEvent_2_00166F80 Script_SendEvent_2_00166F80__as_EnemyScr_Event2001_1_00142820
s32 Script_SendEvent_2_00166F80__as_EnemyScr_Event2001_1_00142820(s32 a, s32 b, Obj_EnemyScr_Event2001_1_00142820 *o);
#define Script_SetArgU8_1_00165070 Script_SetArgU8_1_00165070__as_EnemyScr_Event2001_1_00142820
void Script_SetArgU8_1_00165070__as_EnemyScr_Event2001_1_00142820(s32 a, u8 h, s32 c, s32 d);
#define Script_RunEvent_2_00166C10 Script_RunEvent_2_00166C10__as_EnemyScr_Event2001_1_00142820
s32 Script_RunEvent_2_00166C10__as_EnemyScr_Event2001_1_00142820(s32 a, s32 h);
#define Script_GetResultU8_1_00164FC0 Script_GetResultU8_1_00164FC0__as_EnemyScr_Event2001_1_00142820
s32 Script_GetResultU8_1_00164FC0__as_EnemyScr_Event2001_1_00142820(s32 a, u8 h, u8 c);

u8 EnemyScr_Event2001_1_00142820(Obj_EnemyScr_Event2001_1_00142820 *o, s32 d)
{
    s32 h = Script_SendEvent_2_00166F80(*o->p, 0x2001, o);
    Script_SetArgU8_1_00165070(*o->p, h, 0, d);
    while ((s8)Script_RunEvent_2_00166C10(*o->p, h)) {
    }
    return (u8)Script_GetResultU8_1_00164FC0(*o->p, h, 0);
}
#undef Script_SendEvent_2_00166F80
#undef Script_SetArgU8_1_00165070
#undef Script_RunEvent_2_00166C10
#undef Script_GetResultU8_1_00164FC0

/* EnemyScr_EventInit_1_001428C0 */
#define Script_SendEvent_2_00166F80 Script_SendEvent_2_00166F80__as_EnemyScr_EventInit_1_001428C0
s32 Script_SendEvent_2_00166F80__as_EnemyScr_EventInit_1_001428C0(s32 a, s32 b, Obj_EnemyScr_EventInit_1_001428C0 *o);
#define Script_RunEvent_2_00166C10 Script_RunEvent_2_00166C10__as_EnemyScr_EventInit_1_001428C0
s32 Script_RunEvent_2_00166C10__as_EnemyScr_EventInit_1_001428C0(s32 a, s32 h);

void EnemyScr_EventInit_1_001428C0(Obj_EnemyScr_EventInit_1_001428C0 *o)
{
    s32 h = Script_SendEvent_2_00166F80(*o->p, 0x7FFF, o);
    while ((s8)Script_RunEvent_2_00166C10(*o->p, h)) {
    }
}
#undef Script_SendEvent_2_00166F80
#undef Script_RunEvent_2_00166C10

/* EnemyScr_GetScriptPath_3_00142930 */
void EnemyScr_GetScriptPath_3_00142930(s32 arg0, void *arg1) {
    s32 temp_16;

    sprintf(arg1, D_001FAD20);
    temp_16 = arg0 & 0xFF;
    if (temp_16 == 0x15) {
        sprintf(arg1, D_001FAD40);
    }
    if (temp_16 == 0x16) {
        sprintf(arg1, D_001FAD60);
    }
    if (temp_16 == 0x17) {
        sprintf(arg1, D_001FAD80);
    }
    if (temp_16 == 0x18) {
        sprintf(arg1, D_001FADA0);
    }
    if (temp_16 == 0x19) {
        sprintf(arg1, D_001FADC0);
    }
    if (temp_16 == 0x1A) {
        sprintf(arg1, D_001FADE0);
    }
    if (temp_16 == 0x1B) {
        sprintf(arg1, D_001FAE00);
    }
    if (temp_16 == 0x1C) {
        sprintf(arg1, D_001FAE20);
    }
    if (temp_16 == 0x1D) {
        sprintf(arg1, D_001FAE40);
    }
    if (temp_16 == 0x1E) {
        sprintf(arg1, D_001FAE60);
    }
    if (temp_16 == 0x1F) {
        sprintf(arg1, D_001FAE80);
    }
    if (temp_16 == 0x20) {
        sprintf(arg1, D_001FAEA0);
    }
    if (temp_16 == 0x21) {
        sprintf(arg1, D_001FAEC0);
    }
    if (temp_16 == 0x22) {
        sprintf(arg1, D_001FAEE0);
    }
    if (temp_16 == 0x23) {
        sprintf(arg1, D_001FAF00);
    }
    if (temp_16 == 0x24) {
        sprintf(arg1, D_001FAF20);
    }
    if (temp_16 == 0x25) {
        sprintf(arg1, D_001FAF40);
    }
    if (temp_16 == 0x26) {
        sprintf(arg1, D_001FAF60);
    }
    if (temp_16 == 0x27) {
        sprintf(arg1, D_001FAF80);
    }
    if (temp_16 == 0x28) {
        sprintf(arg1, D_001FAFA0);
    }
    if (temp_16 == 0x29) {
        sprintf(arg1, D_001FAFC0);
    }
    if (temp_16 == 0x2A) {
        sprintf(arg1, D_001FAFE0);
    }
    if (temp_16 == 0x2B) {
        sprintf(arg1, D_001FB000);
    }
    if (temp_16 == 0x2C) {
        sprintf(arg1, D_001FB020);
    }
    if (temp_16 == 0x2D) {
        sprintf(arg1, D_001FB040);
    }
    if (temp_16 == 0x2E) {
        sprintf(arg1, D_001FB060);
    }
    if (temp_16 == 0x2F) {
        sprintf(arg1, D_001FB080);
    }
    if (temp_16 == 0x30) {
        sprintf(arg1, D_001FB0A0);
    }
    if (temp_16 == 0x31) {
        sprintf(arg1, D_001FB0C0);
    }
    if (temp_16 == 0x32) {
        sprintf(arg1, D_001FB0E0);
    }
    if (temp_16 == 0x33) {
        sprintf(arg1, D_001FB100);
    }
    if (temp_16 == 0x34) {
        sprintf(arg1, D_001FB120);
    }
    if (temp_16 == 0x35) {
        sprintf(arg1, D_001FB140);
    }
    if (temp_16 == 0x36) {
        sprintf(arg1, D_001FB160);
    }
    if (temp_16 == 0x37) {
        sprintf(arg1, D_001FB180);
    }
    if (temp_16 == 0x38) {
        sprintf(arg1, D_001FB1A0);
    }
    if (temp_16 == 0x39) {
        sprintf(arg1, D_001FB1C0);
    }
    if (temp_16 == 0x3A) {
        sprintf(arg1, D_001FB1E0);
    }
    if (temp_16 == 0x3B) {
        sprintf(arg1, D_001FB200);
    }
    if (temp_16 == 0x3C) {
        sprintf(arg1, D_001FB220);
    }
    if (temp_16 == 0x3D) {
        sprintf(arg1, D_001FB240);
    }
    if (temp_16 == 0x3E) {
        sprintf(arg1, D_001FB260);
    }
    if (temp_16 == 0x3F) {
        sprintf(arg1, D_001FB280);
    }
    if (temp_16 == 0x40) {
        sprintf(arg1, D_001FB2A0);
    }
    if (temp_16 == 0x41) {
        sprintf(arg1, D_001FB2C0);
    }
    if (temp_16 == 0x42) {
        sprintf(arg1, D_001FB2E0);
    }
    if (temp_16 == 0x43) {
        sprintf(arg1, D_001FB300);
    }
    if (temp_16 == 0x44) {
        sprintf(arg1, D_001FB320);
    }
    if (temp_16 == 0x45) {
        sprintf(arg1, D_001FB340);
    }
    if (temp_16 == 0x46) {
        sprintf(arg1, D_001FB360);
    }
    if (temp_16 == 0x47) {
        sprintf(arg1, D_001FB380);
    }
    if (temp_16 == 0x48) {
        sprintf(arg1, D_001FB3A0);
    }
    if (temp_16 == 0x49) {
        sprintf(arg1, D_001FB3C0);
    }
    if (temp_16 == 0x51) {
        sprintf(arg1, D_001FB3E0);
    }
    if (temp_16 == 0x52) {
        sprintf(arg1, D_001FB400);
    }
    if (temp_16 == 0x53) {
        sprintf(arg1, D_001FB420);
    }
    if (temp_16 == 0x5B) {
        sprintf(arg1, D_001FB440);
    }
    if (temp_16 == 0x5C) {
        sprintf(arg1, D_001FB460);
    }
    if (temp_16 == 0x5E) {
        sprintf(arg1, D_001FB480);
    }
    if (temp_16 == 0x5F) {
        sprintf(arg1, D_001FB4A0);
    }
    if (temp_16 == 0x62) {
        sprintf(arg1, D_001FB4C0);
    }
    if (temp_16 == 0x65) {
        sprintf(arg1, D_001FB4E0);
    }
    if (temp_16 == 0x66) {
        sprintf(arg1, D_001FB500);
    }
    if (temp_16 == 0x67) {
        sprintf(arg1, D_001FB520);
    }
    if (temp_16 == 0x68) {
        sprintf(arg1, D_001FB540);
    }
    if (temp_16 == 0x69) {
        sprintf(arg1, D_001FB560);
    }
    if (temp_16 == 0x6B) {
        sprintf(arg1, D_001FB580);
    }
    if (temp_16 == 0x6C) {
        sprintf(arg1, D_001FB5A0);
    }
    if (temp_16 == 0x6D) {
        sprintf(arg1, D_001FB5C0);
    }
    if (temp_16 == 0x6E) {
        sprintf(arg1, D_001FB5E0);
    }
    if (temp_16 == 0x76) {
        sprintf(arg1, D_001FB600);
    }
    if (temp_16 == 0x77) {
        sprintf(arg1, D_001FB620);
    }
    if (temp_16 == 0x78) {
        sprintf(arg1, D_001FB640);
    }
    if (temp_16 == 0x7A) {
        sprintf(arg1, D_001FB660);
    }
    if (temp_16 == 0x7B) {
        sprintf(arg1, D_001FB680);
    }
    if (temp_16 == 0x7C) {
        sprintf(arg1, D_001FB6A0);
    }
    if (temp_16 == 0x7D) {
        sprintf(arg1, D_001FB6C0);
    }
    if (temp_16 == 0x7E) {
        sprintf(arg1, D_001FB6E0);
    }
    if (temp_16 == 0x7F) {
        sprintf(arg1, D_001FB700);
    }
    if (temp_16 == 0xBE) {
        sprintf(arg1, D_001FB720);
    }
    if (temp_16 == 0xBF) {
        sprintf(arg1, D_001FB720);
    }
    if (temp_16 == 0xC0) {
        sprintf(arg1, D_001FB720);
    }
    if (temp_16 == 0xC1) {
        sprintf(arg1, D_001FB720);
    }
    if (arg1 != NULL) {
        M2C_FIELD(arg1, s8 *, 0xB) = 0x42;
    }
}
