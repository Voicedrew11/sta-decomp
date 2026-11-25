#include "common.h"

typedef struct { char pad[0x80]; char sub[1]; } T;
T *func_001C9BA0(void);
void func_001CCF50(void *p, s32 a, s32 b);
void func_001CEDC0(s32 v);

void func_001CCF00(s32 a, s32 b)
{
    T *t = func_001C9BA0();
    func_001CCF50(t->sub, a, b);
    func_001CEDC0(3);
}
