#include "common.h"
extern s32 D_004A0FAC[];

f32 Msg_GetAlpha_0_0018B110(void) {
    if ((*D_004A0FAC) < 0x40) {
        return 0.0f;
    }
    return (f32) (*D_004A0FAC);
}
