#include "common.h"

typedef struct { char pad[0x2A]; u8 idx; } Ent;
typedef struct { char pad[0x39A]; u8 b[0x11A]; Ent *ents[1]; } Obj;
void func_001A8510(Obj *o, u8 i);
void func_001A8670(Obj *o, u8 i);
void func_0013F0C0(Obj *o, u8 v);

void func_0013F1B0(Obj *o, u8 i)
{
    func_001A8510(o, i);
    func_001A8670(o, i);
    func_0013F0C0(o, o->b[o->ents[i]->idx]);
}
