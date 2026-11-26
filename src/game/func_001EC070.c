#include "common.h"
typedef struct { s64 a; s64 b; s32 pos; s32 len; } E;
typedef struct { u8 p0[8]; u8 *src; u32 len; s64 a; s64 b; } P;
void SignalSema(s32);
void WaitSema(s32);
void func_00123A88(s32, s32, s32);
void func_001EA4D0(s32 *, E *);
void func_001EAF60(s32 *, s32 *, s32 *, s32 *, s32 *);
typedef struct { s32 x0; u8 p4[0x10]; s32 x14; u8 p18[0x28]; s32 sema; u8 p44[4]; s64 tot; E *ents; s32 n; s32 cnt; s32 head; } O;
extern O D_004BDF88;

s32 func_001EC070(s32 a0, P *p, u8 *buf) {
    s32 pb;
    s32 r;
    u8 *bb;
    u32 n1;
    s32 n2;
    s32 pa;
    s32 total;
    u8 *src;
    s32 n;
    u32 len;
    s32 a;
    s32 b;
    s32 an;
    s32 bn;
    E e;

    src = p->src;
    len = p->len;
    bb = buf;
    n1 = bb + *(s32 *)(bb + 0x50008) - src;
    n1 = len < n1 ? len : n1;
    n2 = len - n1;
    func_001EAF60((s32 *)&D_004BDF88, &a, &an, &b, &bn);
    n = an;
    total = n1 + n2;
    pa = ((u32)a & 0x0FFFFFFF) | 0x20000000;
    pb = ((u32)b & 0x0FFFFFFF) | 0x20000000;
    if (n + bn < total) {
        total = 0;
    } else if ((s32)n1 >= n) {
        func_00123A88(pa, (s32)src, n);
        func_00123A88(pb, (s32)src + n, n1 - n);
        func_00123A88(pb + n1 - n, (s32)bb, n2);
    } else {
        r = n - n1;
        if (n2 >= r) {
            func_00123A88(pa, (s32)src, n1);
            func_00123A88(pa + n1, (s32)bb, r);
            func_00123A88(pb, (s32)bb + n - n1, n2 - r);
        } else {
            func_00123A88(pa, (s32)src, n1);
            func_00123A88(pa + n1, (s32)bb, n2);
        }
    }
    if (total > 0) {
        { s64 ta = p->a; s64 tb = p->b; e.a = ta; e.b = tb; }
        e.pos = a - D_004BDF88.x0;
        e.len = total;
        WaitSema(D_004BDF88.sema);
        if (D_004BDF88.cnt < D_004BDF88.n) {
            func_001EA4D0((s32 *)&D_004BDF88, &e);
            D_004BDF88.ents[D_004BDF88.head].a = e.a;
            D_004BDF88.ents[D_004BDF88.head].b = e.b;
            D_004BDF88.ents[D_004BDF88.head].pos = e.pos;
            D_004BDF88.ents[D_004BDF88.head].len = e.len;
            D_004BDF88.cnt++;
            D_004BDF88.head = (D_004BDF88.head + 1) % D_004BDF88.n;
        }
        SignalSema(D_004BDF88.sema);
    }
    WaitSema(D_004BDF88.sema);
    D_004BDF88.x14 += total;
    D_004BDF88.tot += total;
    SignalSema(D_004BDF88.sema);
    return total > 0;
}
