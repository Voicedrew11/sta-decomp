#include "common.h"
typedef struct { char pad[8]; s32 a; char pad2[4]; void * b; char pad3[4]; u16 c; } S;
void func_001C88E0(s32 arg0, void * arg1, s32 arg2);
void func_0017CD00(S *s) { func_001C88E0(s->a, s->b, s->c); }
