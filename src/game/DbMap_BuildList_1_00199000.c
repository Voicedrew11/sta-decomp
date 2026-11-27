#include "m2c.h"
extern s32 D_002021A8;
extern s32 D_004A1450[];
s32 *DbMap_GetCount_1_001958E0(void);
s32 MapState_IsVisited_1_001AA440(u32);

void DbMap_BuildList_1_00199000(void) {
    s32 *p;
    u32 i;
    u32 j;
    s32 found;
    s32 base;

    p = DbMap_GetCount_1_001958E0();
    if (p != 0) {
        D_002021A8 = 0;
        for (i = 1; i < (u32)(p[1] + 1); i++) {
            found = 0;
            for (j = 0; j < 10; j++) {
                if (MapState_IsVisited_1_001AA440(i * 10 + j) != 0) {
                    found = 1;
                }
            }
            if (found != 0) {
                D_004A1450[D_002021A8] = i;
            } else {
                D_004A1450[D_002021A8] = -1;
            }
            D_002021A8++;
        }
    }
}
