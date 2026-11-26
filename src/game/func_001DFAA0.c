#include "common.h"
typedef struct { u8 stat, second, minute, hour, pad, day, month, year; } Clk;
extern Clk D_00202380;
extern Clk D_00202388;
extern s32 D_00202390;
void sceCdReadClock(Clk *);
#define BCD(x) (((x) & 0xF) + ((x) >> 4) * 10)
void func_001DFAA0(Clk *a) {
    D_00202390 = 0;
    D_00202388.second = a->second;
    D_00202388.minute = a->minute;
    D_00202388.hour = a->hour;
    D_00202388.day = a->day;
    D_00202388.month = a->month;
    D_00202388.year = a->year;
    sceCdReadClock(&D_00202380);
    D_00202380.second = BCD(D_00202380.second);
    D_00202380.minute = BCD(D_00202380.minute);
    D_00202380.hour = BCD(D_00202380.hour);
    D_00202380.day = BCD(D_00202380.day);
    D_00202380.month = BCD(D_00202380.month);
    D_00202380.year = BCD(D_00202380.year);
}
