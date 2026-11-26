#include "m2c.h"
extern s32 D_002F1990[];
extern s32 D_002F1994[];
extern volatile s32 D_002F1998[];
extern s32 D_00201F2C;
extern volatile u64 D_002F14E0[];
extern volatile u64 D_002F1500[];
extern volatile u64 D_002F1510[];
extern volatile u64 D_002F13F0[];
extern volatile u64 D_002F1410[];
extern volatile u64 D_002F1420[];
typedef union { u128 q; u64 d[2]; u32 w[4]; } Q;

static inline void push(u64 v, u64 r) {
    Q q;
    s32 p;
    q.d[0] = v;
    q.d[1] = r;
    p = (D_002F1994[0] += 0x10) - 0x10;
    *(Q *)p = q;
}

static inline void end(void) {
    Q a;
    Q b;
    s32 n;
    s32 p;

    p = D_002F1998[0];
    n = (D_002F1994[0] - p) / 16 - 2;
    a.q = 0;
    a.w[1] = 0;
    a.w[0] = (n + 1) | 0x10000000;
    a.w[3] = (n + 1) | 0x51000000;
    *(Q *)p = a;
    b.q = 0;
    b.d[0] = (u64)(u32)n | (0x8000 | ((u64)0x10000000 << 32));
    b.d[1] = 0xE;
    *(Q *)(D_002F1998[0] + 0x10) = b;
}

void func_00153770(void) {
    if (D_002F1994[0] == 0) {
        D_002F1994[0] = D_002F1990[0];
    }
    D_002F1998[0] = D_002F1994[0];
    D_002F1994[0] += 0x20;
    if (D_00201F2C) {
        push(D_002F14E0[0], 0x4C);
        push(D_002F1510[0], 0x40);
        push(D_002F1500[0], 0x18);
        push(D_002F14E0[0], 0x4D);
        push(D_002F1510[0], 0x41);
        push(D_002F1500[0], 0x19);
    } else {
        push(D_002F13F0[0], 0x4C);
        push(D_002F1420[0], 0x40);
        push(D_002F1410[0], 0x18);
        push(D_002F13F0[0], 0x4D);
        push(D_002F1420[0], 0x41);
        push(D_002F1410[0], 0x19);
    }
    push(0x50000, 0x48);
    push(0, 9);
    push(0x48, 0x43);
    end();
}

