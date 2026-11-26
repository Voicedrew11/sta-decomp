#include "common.h"
typedef struct { Vec v[8]; } V8;
typedef struct { u8 pad[0xA0]; } A0;
typedef struct {
    u8 pad0[0x74];
    u16 n74;
    u8 pad76[0x144 - 0x76];
    V8 *x144;
    u8 pad148[0x188 - 0x148];
    A0 *x188;
} A;
extern Vec D_003139A0;
void func_0015CD30(A0 *, Vec *, Vec *, Vec *, Vec *, Vec *, Vec *, Vec *, Vec *, Vec *, Vec *);
void func_001B4100(A *a) {
    s32 i;
    for (i = 0; i < a->n74; i++) {
        V8 *q = &a->x144[i];
        func_0015CD30(&a->x188[i], &q->v[0], &q->v[2], &D_003139A0, &D_003139A0, &q->v[1], &q->v[3], &D_003139A0, &D_003139A0, &q->v[5], &q->v[4]);
    }
}
