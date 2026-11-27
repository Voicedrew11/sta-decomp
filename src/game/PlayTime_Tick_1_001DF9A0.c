#include "common.h"
typedef struct { u8 stat, second, minute, hour, pad, day, month, year; } CdClock;
void sceCdReadClock(CdClock *);
void PlayTime_Update_1_001DF670(void);
extern s32 D_00202390;
extern CdClock D_002023A0;
#define BCD(x) (((x) & 0xF) + ((x) >> 4) * 10)
s32 PlayTime_Tick_1_001DF9A0(void) {
    if (D_00202390 != 0) return 0;
    sceCdReadClock(&D_002023A0);
    D_002023A0.second = BCD(D_002023A0.second);
    D_002023A0.minute = BCD(D_002023A0.minute);
    D_002023A0.hour = BCD(D_002023A0.hour);
    D_002023A0.day = BCD(D_002023A0.day);
    D_002023A0.month = BCD(D_002023A0.month);
    D_002023A0.year = BCD(D_002023A0.year);
    PlayTime_Update_1_001DF670();
    return 1;
}
