#include "common.h"
typedef struct { s32 a, b; } E;
typedef struct { u8 pad[0x258]; } S;
void Script_SetArgU8_1_00165070(u8 *p, u8 i, u8 j, u8 v) {
    E *e = &((E *)((u8 *)&((S *)p)[i] + 0x36C))[j];
    e->a = 1;
    e->b = v;
}
