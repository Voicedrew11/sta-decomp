#include "common.h"

typedef struct { char pad[0x154]; void *p; } S;
extern S *D_00201FA8;
typedef struct { char pad[8]; f32 f; } Obj;
void func_0013E620(void *p, s32 v);
void func_0013E450(void *p, f32 f);
void func_0013E470(void *p, f32 f);

void func_00143BD0(Obj *o)
{
    f32 f = o->f;
    void *p = D_00201FA8->p;
    func_0013E620(p, 1);
    func_0013E450(p, f);
    func_0013E470(p, 0.0f);
}
