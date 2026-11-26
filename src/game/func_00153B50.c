#include "common.h"
typedef union { u128 q; u64 d[2]; u32 w[4]; } Q;
typedef struct { s32 buf, size, n, cur; s32 stk[16]; s32 x50, x54, x58, x5C, x60, x64, x68, x6C; } G;
extern G D_002F1940;
extern s32 D_00201F28;
void func_001549D0(void);
void func_001544C0(void);
void func_00155AC0(s32, s32, s32, s32, s32);
void func_00164320(void);
static inline void chk(void) {
    if ((u32)((D_002F1940.cur - D_002F1940.x68) / 32) < 0x660) {
        D_00201F28 = 1;
    } else {
        D_00201F28 = 0;
    }
}
static inline void push(s32 off) {
    if (D_002F1940.x54) func_001549D0();
    D_002F1940.cur = D_002F1940.x68 + off;
    D_002F1940.stk[D_002F1940.n] = D_002F1940.cur;
    D_002F1940.n++;
    chk();
}
static inline void pop(void) {
    if (D_002F1940.x54) func_001549D0();
    D_002F1940.n--;
    D_002F1940.cur = D_002F1940.stk[D_002F1940.n];
    chk();
}

void func_00153B50(s32 a0) {
    Q a;
    Q b;
    s32 p;

    push(0x1C0);
    if (D_002F1940.x54 == 0) {
        D_002F1940.x54 = D_002F1940.x50;
    }
    D_002F1940.x58 = D_002F1940.x54;
    D_002F1940.x54 += 0x20;
    a.d[0] = 0x30000;
    a.d[1] = 0x47;
    p = D_002F1940.x54;
    D_002F1940.x54 = p + 0x10;
    *(Q *)p = a;
    b.d[0] = 0x3A000118;
    b.d[1] = 0x4E;
    p = D_002F1940.x54;
    D_002F1940.x54 = p + 0x10;
    *(Q *)p = b;
    func_001544C0();
    func_00155AC0(0, 0, 0x280, 0x1C0, a0);
    pop();
    func_00164320();
}
