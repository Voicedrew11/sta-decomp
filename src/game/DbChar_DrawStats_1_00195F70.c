#include "common.h"
typedef struct { f32 v[4]; } H;
typedef struct { u8 pad[4]; u16 x4; } R;
void memset(void *, s32, s32);
void Menu_DrawFrame_0_00185390(f32, s32, s32, s32);
void Menu_DrawStatRing_0_00186440(f32, H *, H *, H *, H *);
R *DbChar_Find_0_00195770(s32);
void DbChar_CalcStatBars_0_00196D10(H *, H *, H *, H *, R *);
s32 Bestiary_IsSeen_2_001A9EC0(s16);
extern s32 D_00202188;
extern s32 D_0020218C;
extern s32 D_004A11A0[];
extern s32 D_004A13E0[];

void DbChar_DrawStats_1_00195F70(f32 f) {
    H a;
    H b;
    H c;
    H d;
    R *r;
    s32 id;
    id = D_004A11A0[D_004A13E0[0]];
    r = DbChar_Find_0_00195770(id);
    DbChar_CalcStatBars_0_00196D10(&a, &b, &c, &d, r);
    if (Bestiary_IsSeen_2_001A9EC0(id)) {
        Menu_DrawStatRing_0_00186440(f, &a, &b, &c, &d);
        D_00202188 = r->x4;
    } else {
        memset(&a, -1, 0x10);
        memset(&b, -1, 0x10);
        Menu_DrawStatRing_0_00186440(f, &a, &b, 0, 0);
        D_00202188 = 0;
    }
    Menu_DrawFrame_0_00185390(f, 1, D_0020218C, D_004A13E0[0]);
}
