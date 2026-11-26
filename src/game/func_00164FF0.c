#include "common.h"
typedef struct { s32 a; f32 b; } E;
typedef struct { char pad[0x36C]; E e[1][75]; } Obj;
void func_00164FF0(Obj *o, u8 i, u8 j, f32 f) {
    E *row = o->e[i];
    E *p = &row[j];
    p->a = 6;
    p->b = f;
}
