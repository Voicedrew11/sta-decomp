#include "common.h"

typedef struct { char pad[0x188]; unsigned char a : 1; unsigned char : 2; unsigned char c : 1; unsigned char b : 1; } Obj;
extern char D_003407E0[];
/* .bss, from the top down (CodeWarrior writes it in reverse) */
char D_0042C910[0xed0];
void Sfx_Free_1_001670E0(Obj *o);

s32 Sfx_Release_1_00167030(char *p)
{
    Obj *o = (Obj *)p;
    if (p < D_003407E0 || p > D_0042C910)
        return 0;
    Sfx_Free_1_001670E0(o);
    o->a = 1;
    o->b = 1;
    o->c = 1;
    return 1;
}
