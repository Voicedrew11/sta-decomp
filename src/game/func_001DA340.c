#include "common.h"
s16 func_001DBEA0(s32);
s16 func_001DC0F0(s32);

void func_001DA340(s32 *x, s32 *y, s32 k, s32 a, s32 lim)
{
    s16 (*fs)(s32);
    s16 (*fc)(s32);
    if (k > 127) k = 127;
    if (k < 0) k = 0;
    if (a > lim) a = lim;
    if (a < -lim) a = -lim;
    fc = func_001DC0F0;
    fs = func_001DBEA0;
    if (a >= 0) {
        *x = k * fs(a) / 127;
        *y = k * fc(a) / 127;
    } else {
        a = -a;
        *x = k * fs(a) / 127;
        *y = -k * fc(a) / 127;
    }
}
