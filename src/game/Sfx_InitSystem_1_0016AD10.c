#include "m2c.h"
void Pool_Init_2_00128A60(void *, s32, s32, s32);
s32 Mdl_InitPool_0_00174620(void *, void *);
void Noise_InitWrap_2_0015ED70(void);
void CosTable_Init_3_00146C00(void);
void Arc_LoadFile_2_00159DD0(s32, s8 *, void *, s32 *);
void Sfx_LoadSystemStam_1_0016AE30(void);
void GlowFx_Init_0_001E1200(void);
void Sfx_ClearAll_1_0016AB50(void);
extern s32 D_00222B64[];
extern s32 D_00222B84[];
extern s8 D_0042D850[];
extern s8 D_0042D7E0[];
extern s8 *D_00201FC0;
extern u32 D_00201FAC;
extern s8 *D_00201FD0;
extern s8 *D_00201FD4;
extern s32 D_00201FE8;

s32 Sfx_InitSystem_1_0016AD10(s32 a0, u32 a1, s32 a2) {
    s32 t;
    Pool_Init_2_00128A60(D_0042D850, D_00222B64[0], D_00222B84[0], 0x200);
    if (!Mdl_InitPool_0_00174620(D_0042D7E0, D_0042D850)) {
        return 0;
    }
    D_00201FC0 = (s8 *)a0;
    D_00201FAC = a1 / 390;
    D_00201FD0 = D_00201FC0 + D_00201FAC * 0x120;
    D_00201FD4 = D_00201FD0 + D_00201FAC * 0x60;
    Noise_InitWrap_2_0015ED70();
    CosTable_Init_3_00146C00();
    Arc_LoadFile_2_00159DD0(a2, D_0042D850, &D_00201FE8, &t);
    Sfx_LoadSystemStam_1_0016AE30();
    GlowFx_Init_0_001E1200();
    Sfx_ClearAll_1_0016AB50();
    return 1;
}
