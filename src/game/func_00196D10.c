#include "m2c.h"
void func_00123C40(void *, s32, s32);
typedef struct { u8 pad[8]; u16 a[8]; u16 b[6]; } Src;

void func_00196D10(u16 *a0, u16 *a1, void *a2, void *a3, Src *s) {
    func_00123C40(a1, 0, 0x10);
    func_00123C40(a0, 0, 0x10);
    func_00123C40(a3, 0, 0x10);
    func_00123C40(a2, 0, 0x10);
    if (s != NULL) {
        a0[0] = s->a[0];
        a0[1] = s->a[1];
        a0[2] = s->a[2];
        a0[3] = s->a[3];
        a0[4] = s->a[4];
        a0[5] = s->a[5];
        a0[6] = s->a[6];
        a0[7] = s->a[7];
        a1[0] = s->b[0];
        a1[1] = s->b[1];
        a1[2] = s->b[2];
        a1[3] = s->b[3];
        a1[4] = s->b[4];
        a1[5] = s->b[5];
    }
}
