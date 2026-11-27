#include "m2c.h"
extern s8 *D_002022E4;
extern s32 D_00201E20;
extern s32 D_00202278;
extern char D_001FDC08[], D_001FDC10[], D_001FDC18[], D_001FDC20[], D_001FDC28[];
extern u8 D_004B4BE0[];
void Enemy_UpdateModelMatrix_0_001A7E60(void);
void PlayerProc_Animate_0_001C5750(void);
void PlayerProc_Collide_0_001C5150(void);
void PlayerProc_Update_0_001BEFA0(void);
void PlayerProc_UpdateMove_0_001BE7B0(void);
void PlayerProc_Attack_0_001C55A0(void);
void Arc_LoadFile_2_00159DD0(s32, s32, void *, s32 *);
s32 Tex_HashName_2_00177F80(void *);
s32 Tex_Find_1_00177AF0(s32, s32);
void memset(void *, s32, s32);

void Player_LoadModel_1_001C9CD0(s8 *a) {
    s8 *o;
    s32 tmp;
    o = *(s8 **)(a + 0x518) + 0x180;
    D_002022E4 = a;
    Enemy_UpdateModelMatrix_0_001A7E60();
    *(void **)(a + 0x538) = PlayerProc_Animate_0_001C5750;
    *(void **)(a + 0x53C) = PlayerProc_Collide_0_001C5150;
    *(void **)(a + 0x540) = PlayerProc_Update_0_001BEFA0;
    *(void **)(a + 0x544) = PlayerProc_UpdateMove_0_001BE7B0;
    *(void **)(a + 0x548) = PlayerProc_Attack_0_001C55A0;
    *(s16 *)(a + 0x4AE) = -1;
    *(s32 *)(*(s8 **)(o + 0x18) + 0x4F0) = 0;
    *(s32 *)(*(s8 **)(o + 0x18) + 0x510) = D_00201E20;
    *(s16 *)(*(s8 **)(o + 0x18) + 0x538) = -1;
    *(s16 *)(*(s8 **)(o + 0x18) + 0x53A) = -1;
    *(u8 *)(o + 0x39C) = 0;
    Arc_LoadFile_2_00159DD0(0x374169A, D_00202278, o + 0x3A8, &tmp);
    *(s32 *)(o + 0x3B0) = Tex_Find_1_00177AF0(Tex_HashName_2_00177F80(D_001FDC08), *(s32 *)(o + 0x3A8));
    *(s32 *)(o + 0x3B4) = Tex_Find_1_00177AF0(Tex_HashName_2_00177F80(D_001FDC10), *(s32 *)(o + 0x3A8));
    *(s32 *)(o + 0x448) = Tex_Find_1_00177AF0(Tex_HashName_2_00177F80(D_001FDC18), *(s32 *)(o + 0x3A8));
    *(s32 *)(o + 0x44C) = Tex_Find_1_00177AF0(Tex_HashName_2_00177F80(D_001FDC20), *(s32 *)(o + 0x3A8));
    *(s32 *)(o + 0x450) = Tex_Find_1_00177AF0(Tex_HashName_2_00177F80(D_001FDC28), *(s32 *)(o + 0x3A8));
    memset(D_004B4BE0, 0, 0x58);
}
