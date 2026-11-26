#include "common.h"
typedef struct { u64 a:6; u64 b:2; } BF;
extern BF D_004A4340[];
extern s32 D_004A3330[];
u8 *func_001A97D0(s16);

void func_001A2DE0(void) {
    s32 i;
    if (D_004A4340[0].b) {
        for (i = 0; i < 0x400; i++) {
            D_004A3330[i] = 0;
            if (func_001A97D0(i)[5] == 3) {
                func_001A97D0(i)[5] = 1;
            }
        }
    }
    D_004A4340[0].b = 0;
}

