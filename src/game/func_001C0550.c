#include "m2c.h"
typedef struct {
    u8 pad[0x39C];
    u32 b39C:8;
    u32 b8:6;
    u32 m:4;
    u32 n:4;
    u32 o:6;
    u32 r:4;
    u8 pad3A0[0x414 - 0x3A0];
    void *x414;
} S;
typedef struct { u8 pad[0x9C]; s16 x9C; } R;
typedef struct { u8 pad[0x518]; u8 *x518; } A;
R *func_001AC3E0(void);
s32 func_001CBE40(s32);
void func_0018B0E0(s32);
R *func_001B9360(void);

s32 func_001C0550(A *a0) {
    S *s;
    R *r;
    s = (S *)(a0->x518 + 0x180);
    s->x414 = 0;
    r = func_001AC3E0();
    if (r) {
        if (func_001CBE40(r->x9C)) {
            s->m = 1;
            s->n = 0;
            s->x414 = r;
        } else {
            func_0018B0E0(0xCC);
        }
        return 1;
    }
    r = func_001B9360();
    if (r) {
        s->m = 1;
        s->n = 0;
        s->x414 = r;
        return 1;
    }
    return 0;
}
