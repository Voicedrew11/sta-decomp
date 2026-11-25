#include "common.h"

typedef struct { u64 a, b; u64 pad[2]; } T;
typedef struct { char pad[8]; u64 a; u64 b; } Obj;
extern char D_004BDF88[];
void func_001EA2E0(void *p, T *t);

s32 func_001E9DC0(void *unused, Obj *o)
{
    T t;
    func_001EA2E0(D_004BDF88, &t);
    o->a = t.a;
    o->b = t.b;
    return 1;
}
