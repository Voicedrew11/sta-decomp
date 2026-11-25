#include "common.h"
typedef struct { char pad[8]; s32 a; char pad2[4]; s32 b; } S;
void func_001B7CD0(s64 arg0, s64 arg1);
void func_0017DEA0(S *s) { func_001B7CD0(s->a, s->b); }
