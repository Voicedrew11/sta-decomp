#include "common.h"
typedef struct { s32 st; s32 fl; s8 x8; } S;
extern f32 D_00202264;
void Title_HandleEvent_0_001A3EC0(S *s) {
    switch (s->st) {
    case 25:
        D_00202264 = 0.0f;
        break;
    case 27:
    case 0:
        break;
    case 22:
        if (!(D_00202264 < 150.0f)) {
            s->x8 = 4;
            s->fl = 0;
            s->st = 26;
        }
        D_00202264 += 1.0f;
        break;
    case 26:
    case 28:
    case 30:
        break;
    }
    if (s->fl & 8) {
        s->x8 = 4;
        s->fl = 0;
        s->st = 26;
    }
}

