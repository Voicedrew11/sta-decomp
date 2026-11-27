#include "common.h"
typedef struct { s32 x0; s32 x4; } A;
s32 Menu_GetCursor_1_0018B820(s32);
void LoadMenu_SelectSlot_0_001929C0(A *);
s32 SaveSys_GetPort_1_001E8290(void);
extern f32 D_0020213C;
extern s32 D_004A1120[];
extern f32 D_004A1138[];
extern Flags8 D_004A1140[];
void LoadMenu_HandleEvent_0_00192900(A *a) {

    switch (a->x0) {
    case 25:
        D_0020213C = 0.0f;
        D_004A1120[0] = Menu_GetCursor_1_0018B820(SaveSys_GetPort_1_001E8290());
        D_004A1138[0] = 0.0f;
        D_0020213C = D_004A1120[0] + 1;
        D_004A1140[0].f.b0 = 1;
        break;
    case 22:
        if (D_004A1140[0].f.b0) {
            LoadMenu_SelectSlot_0_001929C0(a);
            a->x4 = 0;
        }
        break;
    }
}

