#include "m2c.h"
s32 func_00166F80(void *, s32, void *);
void func_00165030(void *, u8, s32, s32);
void func_00165070(void *, u8, s32, u32);
s8 func_00166C10(void *, s32);
s8 func_00164F90(void *, u8, s32);
typedef struct { u8 pad[0x4A4]; void **p; } Obj;
#define H(a) (*(a)->p)

void func_00140770(Obj *a0, s8 *a1, u32 a2, u32 a3, u32 a4) {
    s32 id;
    id = func_00166F80(H(a0), 0x2025, a0);
    func_00165030(H(a0), id, 0, a1[0]);
    func_00165030(H(a0), id, 1, a1[1]);
    func_00165030(H(a0), id, 2, a1[2]);
    func_00165030(H(a0), id, 3, a1[3]);
    func_00165030(H(a0), id, 4, a1[4]);
    func_00165030(H(a0), id, 5, a1[5]);
    func_00165030(H(a0), id, 6, a1[6]);
    func_00165070(H(a0), id, 7, a2);
    func_00165070(H(a0), id, 8, a3);
    func_00165070(H(a0), id, 9, a4);
    while (func_00166C10(H(a0), id) != 0) {}
    a1[0] = func_00164F90(H(a0), id, 0);
    a1[1] = func_00164F90(H(a0), id, 1);
    a1[2] = func_00164F90(H(a0), id, 2);
    a1[3] = func_00164F90(H(a0), id, 3);
    a1[4] = func_00164F90(H(a0), id, 4);
    a1[5] = func_00164F90(H(a0), id, 5);
    a1[6] = func_00164F90(H(a0), id, 6);
}
