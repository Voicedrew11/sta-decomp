#include "m2c.h"
typedef struct { s16 x0; s16 x2; s16 x4; } R;
typedef struct { u8 pad[0x390]; R *x390; u8 pad394[0x462 - 0x394]; u16 x462, x464, x466, x468, x46A, x46C, x46E; } S;
typedef struct { u8 pad[0xC]; u8 v:3; } T;
typedef struct { u8 pad[0x4B0]; T *x4B0; } A;
typedef struct { u8 pad[8]; u16 x8; u8 padA[6]; u32 x10[8]; u8 p30:4; u8 pad30:4; u8 a:2; u8 v:1; } B;
extern s8 *D_002022E4;
s32 func_001AB500(B *, u16 *);
s32 func_001CD450(s32, void *, s32, s32);
void func_001CC830(s32, u16, s32, s32);
void func_001C8570(u32 *);
void func_001C8320(s32, s32, s32, s32);
static inline S *get(void) {
    S *r;
    s8 *base;
    if (D_002022E4 == NULL) {
        r = NULL;
    } else if ((base = *(s8 **)(D_002022E4 + 0x518)) == NULL) {
        r = NULL;
    } else {
        r = (S *)(base + 0x180);
    }
    return r;
}
static inline s32 calc(B *a0, s32 bit) {
    S *s;
    s32 n;
    u16 buf[8];
    R *r;
    s8 *base;
    if (D_002022E4 == NULL) {
        s = NULL;
    } else if ((base = *(s8 **)(D_002022E4 + 0x518)) == NULL) {
        s = NULL;
    } else {
        s = (S *)(base + 0x180);
    }
    n = 0;
    if (s == NULL) return n;
    if (bit) {
        r = s->x390;
        n = r->x0 / 100;
        if (n < r->x4) n = r->x4 - n;
        return n;
    }
    buf[1] = s->x462 / 5;
    buf[2] = s->x464 / 5;
    buf[3] = s->x466 / 5;
    buf[5] = s->x46A / 5;
    buf[6] = s->x46C / 5;
    buf[7] = s->x46E / 5;
    n = func_001AB500(a0, buf);
    return n;
}

s32 func_001C8070(B *a0, A *a1) {
    s32 n;
    u8 k;

    if (get() == NULL) return 1;
    if (a1 == NULL) return 1;
    n = calc(a0, a0->v);
    if (!a0->v && func_001CD450(0x11, &k, 0, 1)) {
        n -= n * k / 100;
        if (n < 0) n = 0;
    }
    func_001CC830(n, a0->x8, a1->x4B0->v, a0->p30);
    func_001C8570(a0->x10);
    func_001C8320(n, 1, 1, 1);
    return 1;
}
