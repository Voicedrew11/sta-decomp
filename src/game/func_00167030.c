#include "common.h"

typedef struct { char pad[0x188]; unsigned char a : 1; unsigned char : 2; unsigned char c : 1; unsigned char b : 1; } Obj;
extern char D_003407E0[];
extern char D_0042C910[];
void func_001670E0(Obj *o);

s32 func_00167030(char *p)
{
    Obj *o = (Obj *)p;
    if (p < D_003407E0 || p > D_0042C910)
        return 0;
    func_001670E0(o);
    o->a = 1;
    o->b = 1;
    o->c = 1;
    return 1;
}
