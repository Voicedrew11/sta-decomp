#include "m2c.h"
typedef struct { s32 type; union { s32 i; f32 f; } v; } Val;
typedef struct { u8 pad[8]; u32 *pc; } Ctx;
void func_00165940(void *, Ctx *, u32 *, Val *);

void func_00165DF0(void *o, Ctx *s) {
    u8 res[32];
    Val a;
    Val b;
    u16 i;
    u32 w;
    s32 skip;
    s32 n;
    u8 mode;
    u8 op;
    u8 r;
    f32 fa;
    f32 fb;

    w = *s->pc;
    s->pc++;
    mode = w & 0xFF;
    skip = *s->pc;
    s->pc++;
    n = (u8)((w & 0xFF00) >> 8);
    for (i = 0; i < n; i++) {
        func_00165940(o, s, s->pc, &a);
        s->pc += 2;
        op = *(u8 *)s->pc;
        s->pc++;
        func_00165940(o, s, s->pc, &b);
        s->pc += 2;
        if (a.type == 6 || b.type == 6) {
            fa = a.v.f;
            fb = b.v.f;
            switch (op) {
            case 0: res[i] = fa == fb; break;
            case 1: res[i] = fa != fb; break;
            case 2: res[i] = fa > fb; break;
            case 3: res[i] = fa < fb; break;
            case 4: res[i] = fa >= fb; break;
            case 5: res[i] = fa <= fb; break;
            }
        } else {
            switch (op) {
            case 0: res[i] = a.v.i == b.v.i; break;
            case 1: res[i] = a.v.i != b.v.i; break;
            case 2: res[i] = a.v.i > b.v.i; break;
            case 3: res[i] = a.v.i < b.v.i; break;
            case 4: res[i] = a.v.i >= b.v.i; break;
            case 5: res[i] = a.v.i <= b.v.i; break;
            }
        }
    }
    if (n == 1) {
        r = res[0];
    } else {
        r = res[0];
        if (mode == 0) {
        for (i = 1; i < n; i++) {
            r = r || res[i];
        }
    } else {
        for (i = 1; i < n; i++) {
            r = r && res[i];
        }
    }
    }
    if (!r) {
        s->pc += skip;
    }
}
