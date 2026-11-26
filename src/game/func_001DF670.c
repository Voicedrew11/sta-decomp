#include "common.h"
typedef struct { u8 stat, second, minute, hour, pad, day, month, year; } Clk;
extern Clk D_00202388;
extern Clk D_00202398;
s32 func_001DF910(void);

s32 func_001DF670(void) {
    s32 r;
    Clk t;
    r = func_001DF910();
    t = D_00202388;
    r += t.second + (t.minute + (t.hour + t.day * 99) * 60) * 60;
    D_00202398.second = r % 60;
    D_00202398.minute = (r / 60) % 60;
    D_00202398.hour = (r / 3600) % 99;
    D_00202398.day = r / 356400;
    return 1;
}
