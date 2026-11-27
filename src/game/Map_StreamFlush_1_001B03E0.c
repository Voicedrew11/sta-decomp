#include "common.h"
extern s32 D_004B4BB0[];
extern s32 D_004B4BB4[];
extern s32 D_004B4BB8[];
extern s16 D_004B4BBC[];
extern s16 D_004B4BBE[];
extern s32 D_004B4BC0[];
extern s32 D_004B4BC4[];

void Map_StreamFlush_1_001B03E0(void) {
    if ((*D_004B4BC0) != 0) {
        Task_AddWrap_0_0014DAD0((*D_004B4BC0));
        (*D_004B4BC0) = 0;
    }
    (*D_004B4BB8) = 0;
    (*D_004B4BC0) = 0;
    (*D_004B4BB4) = -1;
    (*D_004B4BB0) = -1;
    (*D_004B4BBC) = 0;
    (*D_004B4BC4) = 0;
    (*D_004B4BBE) = 0;
}
