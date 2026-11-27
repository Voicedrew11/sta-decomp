#include "m2c.h"
typedef union { u128 q[2]; s32 w[8]; f32 f[8]; void *p[8]; } Q2;
typedef struct { s32 *p; s32 n; f32 f; void *fn; s32 a; s32 b; void *cb; } Arg;
typedef struct { s32 x0; } O;
void UiAnim_SetColor_0_0017F890(s32, Q2 *, Arg *);
void UiAnim_SetVisible_1_0017F7C0(s32, s32, s32);
void UiAnim_SetTarget_1_0017F470(f32, s32, s32);
void Storage_Update_0_001A3380(O *);
void StorageProc_Pos_0_001A3500();
void Storage_GetEntry_0_001A3560();
extern Q2 D_001F32F0;
extern s32 D_001F32A0[];
extern s32 D_004A4350[];

void Storage_Open_0_001A32A0(O *p) {
    Q2 q;
    Arg a;

    switch (p->x0) {
    case 0x19:
        D_004A4350[0] = 0;
        q = D_001F32F0;
        a.p = D_001F32A0;
        a.n = 4;
        a.fn = Storage_GetEntry_0_001A3560;
        a.f = -3.0f;
        a.cb = StorageProc_Pos_0_001A3500;
        a.a = 0;
        a.b = 0;
        UiAnim_SetColor_0_0017F890(0, &q, &a);
        UiAnim_SetVisible_1_0017F7C0(0, 1, 1);
        UiAnim_SetTarget_1_0017F470(D_004A4350[0], 0, 1);
        break;
    case 0x16:
        Storage_Update_0_001A3380(p);
        break;
    }
}
