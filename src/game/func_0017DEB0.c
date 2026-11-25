#include "common.h"

typedef struct { char pad[8]; s32 a; char pad2[4]; s32 b; } S;
void func_001B7C10(u32 arg0, u64 arg1);

void func_0017DEB0(S *s)
{
    func_001B7C10(s->a, s->b);
}
