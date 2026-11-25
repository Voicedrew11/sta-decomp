#include "common.h"

void func_001536F0(s32 x, u8 *p);
void func_001746A0(void);

s32 func_00174620(u8 *o, s32 x)
{
    if (x == 0)
        return 0;
    if (o == NULL)
        return 0;
    *(s32 *)o = x;
    func_001536F0(x, o + 4);
    func_001536F0(x, o + 0x34);
    func_001746A0();
    return 1;
}
