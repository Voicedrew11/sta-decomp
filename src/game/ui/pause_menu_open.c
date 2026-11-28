#include "m2c.h"
typedef struct { u128 q[2]; } Q2;
typedef struct { s32 p; s32 n; f32 f; void *fn; s32 a; s32 b; void *cb; } Arg;
typedef struct { s32 x0; } Ev;
void UiAnim_SetColor_0_0017F890(s32, Q2 *, Arg *);
void UiAnim_SetVisible_1_0017F7C0(s32, s32, s32);
s32 UiAnim_SetTarget_1_0017F470(f32, s32, s32);
void PauseMenu_Update_0_0019E400(Ev *);
void PauseMenu_GetEntry_0_0019E780(void);
extern Q2 D_001F31C0;
extern s32 D_001F3160[];
extern s32 D_004A32C8[];
extern f32 D_004A32CC[];
extern s32 D_00202208;

void PauseMenu_Open_0_0019E2F0(Ev *arg0) {
    Q2 q;
    Arg a;

    switch (arg0->x0) {
    case 0x19:
        D_004A32C8[0] = 0;
        D_00202208 = 0;
        q = D_001F31C0;
        a.p = (s32)D_001F3160;
        a.n = 5;
        a.fn = PauseMenu_GetEntry_0_0019E780;
        a.f = -3.0f;
        a.a = 0;
        a.b = 0;
        a.cb = 0;
        UiAnim_SetColor_0_0017F890(0, &q, &a);
        UiAnim_SetVisible_1_0017F7C0(0, 1, 1);
        UiAnim_SetTarget_1_0017F470(D_004A32C8[0], 0, 1);
        break;
    case 0x16:
        if (!(D_004A32CC[0] <= 0.0f)) {
            D_004A32CC[0] -= 1.0f;
        } else {
            PauseMenu_Update_0_0019E400(arg0);
        }
        break;
    }
}
