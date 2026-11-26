#include "common.h"
typedef struct { s32 a; s32 b; } E8;
typedef struct { E8 e[75]; } Row;
void func_00165030(u8 *a0, u8 a1, u8 a2, s8 a3) {
    E8 *p = (E8 *)(a0 + 0x36C + a1 * 0x258) + a2;
    p->a = 0;
    p->b = a3;
}
