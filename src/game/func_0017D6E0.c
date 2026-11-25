#include "m2c.h"
void func_001B7B30(s32, s32, f32 (*)[4]);
void func_0015EBB0(f32 (*)[4], f32 *, f32);
void func_001B7A30(s32, s32, f32 (*)[4]);
void func_001027E0(void *, void *, void *);

void func_0017D6E0(s8 *arg0) {
    f32 f[4][4];
    f32 d[4][4];
    f32 c[4];
    f32 a[4][4];
    f32 b[4][4];
    s32 s1;
    s32 s0;
    f32 ang;
    f32 x, y, z;
    s32 i;
    f32 *p;
    f32 *q;
    f32 *r;
    s32 j;

    s0 = *(s32 *)(arg0 + 0x10);
    s1 = *(s32 *)(arg0 + 8);
    x = *(f32 *)(arg0 + 0x18);
    y = *(f32 *)(arg0 + 0x20);
    z = *(f32 *)(arg0 + 0x28);
    ang = *(f32 *)(arg0 + 0x30);
    c[0] = x;
    c[1] = y;
    c[2] = z;
    c[3] = 1.0f;
    func_001B7B30(s1, s0, a);
    r = f[0];
    i = 0;
    p = a[0];
    q = r;
    do {
        i++;
        q[0] = p[0];
        q[1] = p[1];
        q[2] = p[2];
        q[3] = p[3];
        p += 4;
        q += 4;
    } while (i < 4);
    func_0015EBB0(d, c, ang);
    func_001027E0(f, f, d);
    j = 0;
    q = b[0];
    do {
        j++;
        q[0] = r[0];
        q[1] = r[1];
        q[2] = r[2];
        q[3] = r[3];
        r += 4;
        q += 4;
    } while (j < 4);
    func_001B7A30(s1, s0, b);
}
