#include "actor.h"
typedef struct { u8 pad[0x54]; } E54;
typedef struct { u8 pad[0x10]; Vec x10; u8 pad2[0x13C - 0x20]; E54 *x13C; } Mdl;
void func_001B59E0(E54 *, Vec *, Vec *, Vec *);
void func_001029D0(Vec *, Vec *, Vec *);
void func_00102A60(Vec *, Vec *);
void func_001A6DC0(Actor *);
void func_00136700(Actor *);
void func_001A7030(Actor *, s32, s32);

void func_001A6C90(Actor *a) {
    Mdl *m;
    Vec *v;

    if (a != NULL) {
        if (!((Flags8 *)&a->pad520[0x80])->f.b0) {
            a->flags5A1.f.b4 = 1;
            return;
        }
        a->flags5A1.f.b4 = 0;
        ((Flags8 *)&a->pad520[0x80])->f.b2 = 1;
        if (a->unk4A8 != 0) {
            m = *(Mdl **)a->unk4A8;
            v = (Vec *)a->unk518;
            func_001B59E0(&m->x13C[a->unk4AC], v, v + 2, v + 5);
            func_001029D0(v, v, &m->x10);
            func_00102A60(v + 1, v);
            func_00102A60(v + 3, v + 2);
        }
        func_001A6DC0(a);
        if (*(u16 *)a != 0) {
            func_00136700(a);
            func_001A7030(a, 1, 0);
        }
    }
}
