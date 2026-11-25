#include "common.h"

typedef struct { s32 x0; s32 x4; u8 b8; char p9[3]; u8 bC; } Obj;
extern s32 D_00202270;
void func_0012C0C0(void);

void func_001A4930(Obj *o)
{
    o->bC = 0;
    if (o->x0 == 25)
        D_00202270 = 1;
    if (o->x0 == 22 && !D_00202270) {
        o->b8 = 18;
        o->x4 = 0;
        o->x0 = 31;
        func_0012C0C0();
    }
}
