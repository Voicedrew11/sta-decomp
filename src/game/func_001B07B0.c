#include "common.h"
void func_001B0020();
void func_0014DAD0(s32);                         /* extern */
void func_0014DB10(void (*)());                  /* extern */
void memset(s32 *, s32, s32);            /* extern */
extern s32 D_004B4B90[];
extern s32 D_004B4B94[];
extern s32 D_004B4B98[];
extern s32 D_004B4B9C[];
extern s32 D_004B4BB0[];
extern s32 D_004B4BB4[];
extern s32 D_004B4BB8[];
extern s16 D_004B4BBC[];
extern s16 D_004B4BBE[];
extern s32 D_004B4BC0[];
extern s32 D_004B4BC4[];

void func_001B07B0(void) {
    if ((*D_004B4BC0) != 0) {
        func_0014DAD0((*D_004B4BC0));
        (*D_004B4BC0) = 0;
    }
    (*D_004B4BB8) = 0;
    (*D_004B4BC0) = 0;
    (*D_004B4BB4) = -1;
    (*D_004B4BB0) = -1;
    (*D_004B4BBC) = 0;
    (*D_004B4BC4) = 0;
    (*D_004B4BBE) = 0;
    (*D_004B4B90) = 0;
    (*D_004B4B94) = 0;
    (*D_004B4B98) = 0;
    (*D_004B4B9C) = 0;
    func_0014DB10(func_001B0020);
    memset(D_004B4B90, 0, 0x40);
    (*D_004B4BB4) = -1;
    (*D_004B4BB0) = -1;
}
