#include "actor.h"
typedef struct { u8 pad[0x120]; Flags8 x120; } C;
typedef struct { u8 pad[0x190]; C *x190; } B;
void Enemy_UpdateBlend5CC_0_0013DA20(Actor *a, f32 d) {
    f32 v = a->unk5CC;
    if (((B *)a->unk518)->x190->x120.f.b1) {
        v += d;
        if (!(v < 1.0f)) v = 1.0f;
    } else if (!(v <= d)) {
        v -= d;
    } else {
        v = 0.0f;
    }
    a->unk5CC = v;
}
