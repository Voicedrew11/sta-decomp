#include "common.h"

typedef struct { char pad[0x48]; char sub[0x60]; s32 xa8; } Obj;
extern volatile s32 D_004BDECC[];
extern s32 D_004BDEC8[];
void func_001EB060(void *p);
void func_001E9EF0(Obj *o);

void func_001EA060(Obj *o)
{
    func_001EB060(o->sub);
    D_004BDECC[0] = 0;
    D_004BDEC8[0] = 0;
    func_001E9EF0(o);
    while (D_004BDECC[0]) {
    }
    o->xa8 = 3;
}
