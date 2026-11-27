#include "m2c.h"
typedef struct { u128 q[2]; } Q2;
typedef struct { s32 p; s32 n; f32 f; void *fn; s32 a; s32 b; void *cb; } Arg;
typedef struct { u32 id; s32 x; s32 y; } Ent;
typedef struct { s32 h0; u32 n; s32 h8; s32 hC; Ent e[1]; } Tbl;
Tbl *DbItem_GetCount_1_001958A0(void);
s32 Save_TestItemBit_1_001A9B40(s16);
void UiAnim_SetColor_0_0017F890(s32, Q2 *, Arg *);
void UiAnim_SetVisible_1_0017F7C0(s32, s32, s32);
void UiAnim_SetTarget_1_0017F470(f32, s32, s32);
void DbItem_GetListName_1_00197F30(void);
void DbItemProc_Pos_0_00198100(void);
extern Q2 D_001F2F40;
extern s32 D_00201D38;
extern s32 D_00201D3C;
extern u32 D_00202190;
extern s32 D_00202198;
extern s32 D_004A1430[];

void DbItem_ResetLayout_0_00197DD0(void) {
    Q2 q;
    Arg a;
    Tbl *t;
    Ent *e;
    u32 i;
    s32 hit;
    u32 cnt;

    t = DbItem_GetCount_1_001958A0();
    if (t != 0) {
        hit = 0;
        cnt = 0;
        e = t->e;
        for (i = 0; i < t->n; i++, e++) {
            if (e->id >= 100) {
                if (Save_TestItemBit_1_001A9B40(e->id) != 0) {
                    hit++;
                }
                cnt++;
            }
        }
        D_00202190 = (u32)(hit * 100) / cnt;
        q = D_001F2F40;
        a.fn = DbItem_GetListName_1_00197F30;
        a.f = -3.0f;
        a.cb = DbItemProc_Pos_0_00198100;
        a.a = 0;
        a.b = 0;
        a.p = D_00201D3C;
        a.n = D_00202198;
        UiAnim_SetColor_0_0017F890(D_00201D38, &q, &a);
        UiAnim_SetVisible_1_0017F7C0(D_00201D38, 1, 1);
        UiAnim_SetTarget_1_0017F470(D_004A1430[0], D_00201D38, 1);
    }
}
