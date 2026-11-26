#include "m2c.h"
typedef struct {
    u8 pad[0x50];
    s16 x50;
    u8 x52;
    u8 lo:6;
    u8 hi:2;
    u8 x54;
    u8 pad55[3];
} S;
void memset(void *, s32, s32);
void func_001D7290(s32);
void func_001D7350(void);
void func_001D72F8(u32, s32, s32);
void func_001D7C80(u32, s32, s32);
void func_001D7C08(u32, s32, s32, s32, s32);
extern S D_00317230[];

void func_0015FC60(void) {
    u32 i;
    memset(D_00317230, 0, 0xB0);
    func_001D7290(0);
    func_001D7350();
    for (i = 0; i < 2; i++) {
        D_00317230[i].hi = 3;
        D_00317230[i].x54 = 10;
        func_001D72F8(i, 0, 0xC0);
    }
    for (i = 0; i < 2; i++) {
        D_00317230[i].x50 = 0xF0;
        D_00317230[i].x52 = 0xF;
        D_00317230[i].lo = 4;
        func_001D7C80(i, 0, 0xFFFF);
        func_001D7C08(i, 0, 0xF0, 0xF, 4);
    }
}
