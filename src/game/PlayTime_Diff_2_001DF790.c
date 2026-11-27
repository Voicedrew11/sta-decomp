#include "common.h"
typedef struct { u8 stat, second, minute, hour, pad, day, month, year; } Clk;
struct tm { s32 tm_sec, tm_min, tm_hour, tm_mday, tm_mon, tm_year, tm_wday, tm_yday, tm_isdst; };
s32 mktime(struct tm *);
static inline s32 yday(Clk c) {
    struct tm t;
    t.tm_sec = c.second;
    t.tm_min = c.minute;
    t.tm_hour = c.hour;
    t.tm_mday = c.day - 1;
    t.tm_mon = c.month - 1;
    t.tm_year = c.year + 100;
    mktime(&t);
    return t.tm_yday;
}
s32 PlayTime_Diff_2_001DF790(Clk a, Clk b) {
    s32 d1 = yday(a);
    s32 d2 = yday(b);
    if (a.year != b.year) {
        s32 k; if (a.year % 4) k = (b.year - a.year) * 365; else k = (b.year - a.year) * 366; d2 += k;
    }
    return (b.second - a.second) + ((b.minute - a.minute) + ((b.hour - a.hour) + (d2 - d1) * 24) * 60) * 60;
}
