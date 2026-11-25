#include "common.h"
void sceVu0CopyVector(s32 *, s32 *);     /* extern */
extern void *D_002022F0;
extern s32 D_002022F4;
extern s32 D_002022F8;
extern s32 D_003139A0[];
extern s32 D_004B5DB0[];
extern s32 D_004B5DC0[];

void func_001CAE90(void) {
    if (D_002022F0 != NULL) {
        func_001AF4A0(D_002022F0);
    }
    D_002022F0 = NULL;
    D_002022F4 = 0;
    D_002022F8 = 0;
    sceVu0CopyVector(D_004B5DB0, D_003139A0);
    sceVu0CopyVector(D_004B5DC0, D_003139A0);
}
