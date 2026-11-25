#include "common.h"
typedef struct { char pad[0x170]; s32 v; } Obj;
s32 func_001A5970(void *p);
void func_00167600(void *a, void *p) { Obj *o = a; if (a && p) o->v = func_001A5970(p); }
