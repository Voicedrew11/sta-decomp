#include "common.h"
typedef struct { s32 x0; s32 x4; } A;
void SaveMenu_SelectDevice_0_0018D7B0(A *);
void SaveMenu_UpdateCardFlags_1_0018E120(s32, s32 *);
s32 SaveSys_GetPort_1_001E8290(void);
extern s32 D_004A1050[];
extern s32 D_004A1054[];
extern s32 D_004A105C[];
extern f32 D_004A1060[];
extern s32 D_004A1068[];
extern s32 D_004A106C[];
void SaveMenu_Open_1_0018D360(A *a) {
    SaveMenu_UpdateCardFlags_1_0018E120(0, D_004A1068);
    SaveMenu_UpdateCardFlags_1_0018E120(1, D_004A106C);
    switch (a->x0) {
    case 25:
        D_004A1060[0] = 0.0f;
        D_004A105C[0] = 0;
        D_004A1054[0] = 0;
        D_004A1050[0] = SaveSys_GetPort_1_001E8290();
        break;
    case 22:
        SaveMenu_SelectDevice_0_0018D7B0(a);
        D_004A1060[0] += 0.1f;
        a->x4 = 0;
        break;
    }
}
