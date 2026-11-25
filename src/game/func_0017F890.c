#include "m2c.h"
typedef struct { f32 v[8]; } M8;
typedef struct { M8 a; M8 b; f32 c; u8 pad[0x4C - 0x44]; } E;
extern E D_00486990[];

void func_0017F890(s32 arg0, M8 *a1, M8 *a2) {
    arg0 %= 24;
    if (a1 != NULL) {
        D_00486990[arg0].a = *a1;
    }
    if (a2 != NULL) {
        D_00486990[arg0].b = *a2;
        D_00486990[arg0].c = a2->v[2];
    }
}
