#include "common.h"
void func_001E19A0();
void func_0014DAD0(s32);                         /* extern */
void func_0014DB10(void (*)());                  /* extern */
void memset(s32 *, s32, s32);            /* extern */
extern s32 D_004BC2D0[];
extern s32 D_004BC2D4[];
extern s32 D_004BC2D8[];
extern s32 D_004BC2DC[];
extern s32 D_004BC2E0[];

void func_001E1D70(void) {
    if ((*D_004BC2E0) != 0) {
        func_0014DAD0((*D_004BC2E0));
        (*D_004BC2E0) = 0;
    }
    (*D_004BC2D8) = 0;
    (*D_004BC2E0) = 0;
    (*D_004BC2D4) = -1;
    (*D_004BC2D0) = -1;
    (*D_004BC2DC) = 0;
    func_0014DB10(func_001E19A0);
    memset(D_004BC2D0, 0, 0x20);
    (*D_004BC2D4) = -1;
    (*D_004BC2D0) = -1;
}
