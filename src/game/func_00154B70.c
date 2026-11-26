#include "common.h"
typedef union { u128 q; u32 w[4]; } Q;
typedef struct { s32 buf, size, n, cur; s32 stk[16]; s32 x50, x54, x58, x5C, x60, x64, x68, x6C; } G;
extern G D_002F1940;
extern s32 D_00201F28;
extern f32 D_00201F30, D_00201F34;
extern s32 D_00201C64, D_00201C68, D_00201C6C, D_00201C70, D_00201C74, D_00201C78;
extern s32 D_002F1120[], D_002F1124[], D_002F1128[], D_002F112C[];
extern s32 D_002F1130[], D_002F1134[], D_002F1138[], D_002F113C[];
extern u64 D_002F1140[], D_002F1148[], D_002F1150[], D_002F1158[];
extern u8 D_002F1840[], D_002F16C0[];
void FlushCache(s32);
void func_001789E0(u32, u32, s32);
void func_001549D0(void);
s32 func_0012C0E0(void);
void func_00155090(void);
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

void func_00154B70(void) {
    u128 *p;
    Q t;
    D_002F1940.x6C = (s32)((u128 *)D_002F1940.x68 + 0x1982);

    FlushCache(0);
    func_001789E0(D_002F1940.x68 & 0x0FFFFFFF, (D_002F1940.x68 - 0x19820) & 0x0FFFFFFF, 0x1982);
    D_002F1940.x54 = 0;
    D_002F1940.x58 = 0;
    D_002F1940.n = 0;
    D_002F1940.x50 = D_002F1940.x6C;
    push(0x1E0);
    push(0x40);
    if (!(p = (u128 *)D_002F1940.x54)) {
        p = (u128 *)D_002F1940.x50;
        D_002F1940.x54 = (s32)p;
    }
    D_002F1940.x54 += 0x50;
    t.q = 0;
    t.w[0] = 0x30000010;
    t.w[1] = (u32)D_002F1840;
    t.w[3] = 0x6C100000;
    p[0] = t.q;
    t.q = 0;
    t.w[0] = 0x30000004;
    t.w[1] = (u32)D_002F16C0;
    t.w[3] = 0x6C040010;
    p[1] = t.q;
    if (!func_0012C0E0()) D_00201F30 += 0.02f;
    if (!(D_00201F30 <= 1.0f)) D_00201F30 -= 1.0f;
    D_002F1120[0] = *(s32 *)&D_00201F30;
    D_002F1124[0] = D_00201C64;
    D_002F1128[0] = D_00201C68;
    D_002F112C[0] = D_00201C6C;
    t.q = 0;
    t.w[0] = 0x30000001;
    t.w[1] = (u32)D_002F1120;
    t.w[3] = 0x6C01005B;
    p[2] = t.q;
    if (!func_0012C0E0()) D_00201F34 += 0.02f;
    if (!(D_00201F34 <= 1.0f)) D_00201F34 -= 1.0f;
    D_002F1130[0] = *(s32 *)&D_00201F34;
    D_002F1134[0] = D_00201C70;
    D_002F1138[0] = D_00201C74;
    D_002F113C[0] = D_00201C78;
    t.q = 0;
    t.w[0] = 0x30000001;
    t.w[1] = (u32)D_002F1130;
    t.w[3] = 0x6C01005E;
    p[3] = t.q;
    D_002F1140[0] = 0x8001 | ((u64)0x10000000 << 32);
    D_002F1148[0] = 6 | ((u64)-1 << 32);
    D_002F1150[0] = 0x20016BC0 | ((u64)0xE << 32);
    D_002F1158[0] = 0;
    t.q = 0;
    t.w[0] = 0x30000002;
    t.w[1] = (u32)D_002F1140;
    t.w[3] = 0x6C02005C;
    p[4] = t.q;
    func_001549D0();
    func_00155090();
    pop();
    func_00164320();
}
