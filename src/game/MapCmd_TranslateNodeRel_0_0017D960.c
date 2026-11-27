#include "m2c.h"
typedef struct { s32 pad0[2]; s32 x8; s32 padC; s32 x10; s32 pad14; f32 x18; s32 pad1C; f32 x20; s32 pad24; f32 x28; } S;
void MapObj_GetNodeMatrix_0_001B7B30(s32, s32, f32 (*)[4]);
void MapObj_SetNodeMatrixB_0_001B7A30(s32, s32, f32 (*)[4]);

void MapCmd_TranslateNodeRel_0_0017D960(S *arg0) {
    f32 b[4][4];
    f32 a[4][4];
    f32 c[4][4];
    s32 i;
    s32 j;
    s32 k;
    s32 l;
    s32 s1 = arg0->x10;
    f32 x = arg0->x18;
    f32 y = arg0->x20;
    s32 s0 = arg0->x8;
    f32 z = arg0->x28;

    MapObj_GetNodeMatrix_0_001B7B30(s0, s1, a);
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            b[i][j] = a[i][j];
        }
    }
    b[3][0] = x;
    b[3][1] = y;
    b[3][2] = z;
    for (k = 0; k < 4; k++) {
        for (l = 0; l < 4; l++) {
            c[k][l] = b[k][l];
        }
    }
    MapObj_SetNodeMatrixB_0_001B7A30(s0, s1, c);
}
