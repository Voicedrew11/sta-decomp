#include "common.h"
#include "m2c.h"
typedef struct { char pad[0x25]; unsigned char : 1; unsigned char f : 1; } BF_25_1_1;
extern s32 D_002022E4;
extern u8 D_00201E24;
extern f32 D_004B4CE0[4];
extern s32 D_00202278;
extern M2C_UNK D_004B4BE0[];
extern s32 D_00201E20;
extern char D_001FDC08[];
extern char D_001FDC10[];
extern char D_001FDC18[];
extern char D_001FDC20[];
extern char D_001FDC28[];
s32 Player_Exists_3_001C9BF0(void);
u8 Player_CopyLightPos_0_001C9C00(f32 *v);
void Player_Destroy_1_001C9C30(void);
void Player_LoadModel_1_001C9CD0(s8 *a);
void Player_Respawn_1_001C9E30(void);
void sceVu0CopyVector(f32 *v0, f32 *v1);
M2C_UNK memset(M2C_UNK *, M2C_UNK, M2C_UNK);
M2C_UNK Pool_Free_2_00128580(s32, s32);
s8** ActorList_FromHandle_1_001A5970(s8 *);
void Enemy_UpdateModelMatrix_0_001A7E60(void);
void PlayerProc_Animate_0_001C5750(void);
void PlayerProc_Collide_0_001C5150(void);
void PlayerProc_Update_0_001BEFA0(void);
void PlayerProc_UpdateMove_0_001BE7B0(void);
void PlayerProc_Attack_0_001C55A0(void);
void Arc_LoadFile_2_00159DD0(s32, s32, void *, s32 *);
s32 Tex_HashName_2_00177F80(void *);
s32 Tex_Find_1_00177AF0(s32, s32);
void Player_RefreshEquipModel_0_001CEA50(s32);

/* Player_Exists_3_001C9BF0 */
s32 Player_Exists_3_001C9BF0(void) {
    return D_002022E4 != 0;
}

/* Player_CopyLightPos_0_001C9C00 */
u8 Player_CopyLightPos_0_001C9C00(f32 *v)
{
    if (v)
        sceVu0CopyVector(v, D_004B4CE0);
    return D_00201E24;
}

/* Player_Destroy_1_001C9C30 */
#define D_002022E4 D_002022E4__as_Player_Destroy_1_001C9C30
extern s8 *D_002022E4__as_Player_Destroy_1_001C9C30;

void Player_Destroy_1_001C9C30(void) {
    s8 *temp_s0;

    if (D_002022E4 != NULL) {
        temp_s0 = (signed char *)(M2C_FIELD(D_002022E4, s32 *, 0x518) + 0x180);
        memset(D_004B4BE0, 0, 0x58);
        Tex_Release_1_00177570(M2C_FIELD(temp_s0, s8 **, 0x448));
        Tex_Release_1_00177570(M2C_FIELD(temp_s0, s8 **, 0x44C));
        Tex_Release_1_00177570(M2C_FIELD(temp_s0, s8 **, 0x3B0));
        Tex_Release_1_00177570(M2C_FIELD(temp_s0, s8 **, 0x3B4));
        Tex_Release_1_00177570(M2C_FIELD(temp_s0, s8 **, 0x450));
        Pool_Free_2_00128580(D_00202278, M2C_FIELD(temp_s0, s32 *, 0x3A8));
        Enemy_Destroy_0_001A6A10(ActorList_FromHandle_1_001A5970(D_002022E4));
        D_002022E4 = NULL;
    }
    Player_ReleaseHeldItem_0_001CAE90();
}
#undef D_002022E4

/* Player_LoadModel_1_001C9CD0 */
#define D_002022E4 D_002022E4__as_Player_LoadModel_1_001C9CD0
extern s8 *D_002022E4__as_Player_LoadModel_1_001C9CD0;
#define D_004B4BE0 D_004B4BE0__as_Player_LoadModel_1_001C9CD0
extern u8 D_004B4BE0__as_Player_LoadModel_1_001C9CD0[];
#define memset memset__as_Player_LoadModel_1_001C9CD0
void memset__as_Player_LoadModel_1_001C9CD0(void *, s32, s32);

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
#undef memset
#undef D_002022E4
#undef D_004B4BE0

/* Player_Respawn_1_001C9E30 */
#define D_002022E4 D_002022E4__as_Player_Respawn_1_001C9E30
extern void *D_002022E4__as_Player_Respawn_1_001C9E30;

void Player_Respawn_1_001C9E30(void) {
    void **temp_3;
    void *temp_5;

    Enemy_Respawn_1_001A6C90(D_002022E4);
    temp_3 = M2C_FIELD(M2C_FIELD(D_002022E4, void **, 0x518), void ***, 0xB0);
    if ((temp_3 != NULL) || (*temp_3 != NULL)) {
        temp_5 = *temp_3;
        ((BF_25_1_1 *)temp_5)->f = 1;
    }
    Player_RecalcStats_1_001CEDC0(3);
    Player_RefreshEquipModel_0_001CEA50(1);
}
#undef D_002022E4
