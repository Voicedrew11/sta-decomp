#include "common.h"
typedef struct { s32 type; s32 a; s32 b; s32 c; f32 x, y, z, w; f32 h; f32 p; f32 r; s32 f; } Msg;
extern u16 D_00317238[];
s32 func_00179F80(Msg *);
s32 func_00179F10(void) {
    Msg msg;
    msg.type = 4;
    msg.r = 0.0f;
    msg.c = -1;
    msg.b = -1;
    msg.a = -1;
    msg.p = 0.0f;
    msg.h = 0.0f;
    msg.w = 0.0f;
    msg.z = 0.0f;
    msg.y = 0.0f;
    msg.x = 0.0f;
    msg.f = (D_00317238[0] & 0x2000) != 0;
    func_00179F80(&msg);
    return 0;
}
