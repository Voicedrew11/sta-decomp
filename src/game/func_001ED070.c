#include "common.h"

extern char D_004BDF40[];
extern s32 D_004BE038[];
extern char D_004BE04C[];
void func_001EC5E0(s32 a);
s32 func_001ECAB0(void *a, s32 b, void *c, s32 d);
void func_001EC3E0(void);

s32 func_001ED070(s32 a, s32 b)
{
    s32 r;
    func_001EC5E0(a);
    r = func_001ECAB0(D_004BDF40, D_004BE038[0], D_004BE04C, b);
    func_001EC3E0();
    return r;
}
