#include "m2c.h"
void func_001CE270(s32);
void func_001A95A0(s16, u8);
void func_001A9510(s16);
void func_0018B0C0(void);
void func_0017E150(s32, s32, s32);
void func_00131600(s32, s32);
void func_00131440(s32);
void func_001ED620(s32);

void func_0017E050(s8 *arg0) {
    s32 mode;
    s32 a;
    s32 b;
    s32 c;
    mode = *(s32 *)(arg0 + 8);
    a = *(s32 *)(arg0 + 0x10);
    b = *(s32 *)(arg0 + 0x18);
    c = *(s32 *)(arg0 + 0x20);
    if (mode == 2) func_001CE270(a);
    if (mode == 3) func_001A95A0(a, b);
    if (mode == 4) func_001A9510(a);
    if (mode == 5) func_0018B0C0();
    if (mode == 6) func_0017E150(a, b, c);
    if (mode == 7) func_00131600(a, b);
    if (mode == 8) func_00131440(a);
    if (mode == 9) func_001ED620(a);
}
