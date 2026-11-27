#include "common.h"
extern s32 D_004A4878[];

s32 ActorList_SetCount_1_001A5440(s32 arg0) {
    s32 temp_2;

    temp_2 = (*D_004A4878);
    (*D_004A4878) = arg0;
    return temp_2;
}
