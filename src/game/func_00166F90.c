#include "common.h"
typedef struct { u8 b[0x258]; } R;
typedef struct { s32 id; u32 n; s32 a; s32 b; s32 x10; u8 m[0x200]; u8 k[0x80]; R r[1]; } H;
void memset(void *, s32, s32);
void func_00166F90(H **arg0, s32 arg1, s32 arg2, u32 arg3) {
    u32 i;
    H *p = *arg0;
    p->id = -1;
    p->n = arg3;
    p->a = arg1;
    p->b = arg2;
    memset(p->m, 0, 0x200);
    memset(p->k, 0, 0x80);
    for (i = 0; i < arg3; i++) {
        memset(&p->r[i], 0, 0x258);
    }
}
