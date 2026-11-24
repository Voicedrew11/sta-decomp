#include "m2c.h"
M2C_UNK func_00102A60(M2C_UNK *, M2C_UNK *);        /* extern */
extern s8 *D_002022F0;
extern s32 D_002022F4;
extern s32 D_002022F8;
extern M2C_UNK D_003139A0[];
extern M2C_UNK D_004B5DB0[];
extern M2C_UNK D_004B5DC0[];

void func_001CAE90(void) {
    if (D_002022F0 != NULL) {
        func_001AF4A0(D_002022F0);
    }
    D_002022F0 = NULL;
    D_002022F4 = 0;
    D_002022F8 = 0;
    func_00102A60(D_004B5DB0, D_003139A0);
    func_00102A60(D_004B5DC0, D_003139A0);
}
