#include "common.h"

typedef struct { char pad[0x20]; f32 r[3]; } R;
typedef struct { char pad[0x18]; R *r; } T;
typedef struct { char pad[0x518]; u8 *p; } S;
extern S *D_002022E4;
typedef struct { char pad[8]; f32 x; char p0[4]; f32 y; char p1[4]; f32 z; } Obj;

void func_0017CF40(Obj *o)
{
    T *t = (T *)(D_002022E4->p + 0x180);
    if (t) {
        t->r->r[0] = 3.1415927f * o->x / 180.0f;
        t->r->r[1] = 3.1415927f * o->y / 180.0f;
        t->r->r[2] = 3.1415927f * o->z / 180.0f;
    }
}
