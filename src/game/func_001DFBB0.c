#include "common.h"
typedef struct { u8 stat, second, minute, hour, pad, day, month, year; } Clk;
extern Clk D_00202380;
extern Clk D_00202388;
extern s32 D_00202390;
void sceCdReadClock(Clk *);
#define BCD(x) (((x) & 0xF) + ((x) >> 4) * 10)
void func_001DFBB0(void) {
    D_00202390 = 0;
    D_00202388.second = 0;
    D_00202388.minute = 0;
    D_00202388.hour = 0;
    D_00202388.day = 0;
    D_00202388.month = 0;
    D_00202388.year = 0;
    sceCdReadClock(&D_00202380);
    D_00202380.second = BCD(D_00202380.second);
    D_00202380.minute = BCD(D_00202380.minute);
    D_00202380.hour = BCD(D_00202380.hour);
    D_00202380.day = BCD(D_00202380.day);
    D_00202380.month = BCD(D_00202380.month);
    D_00202380.year = BCD(D_00202380.year);
}
