#include "common.h"
typedef struct { u8 pad[0x14]; s32 x14; Flags8 f18; } A;
typedef struct { u8 pad[0x90]; s32 x90; u8 pad2[0x8]; s16 h9C; s16 h9E; u8 pad3[8]; Flags8 fA8; } B;
typedef struct { u8 a:3; u8 f:3; u8 c:2; } F3b;
extern A *D_00202290;
extern s32 D_0020228C;
extern B *D_00202288;
extern s32 D_002022A0;
extern s32 D_004B4B70[];
extern s32 D_004B4B74[];
extern s32 D_004B4B78[];
extern s32 D_004B4B7C[];
extern s32 *D_004B4B80[];
extern s32 *D_004B4B84[];
extern s32 D_004B4B88[];
extern F3b D_00222A54[];
extern s8 D_001FD9D0[];
extern s8 D_001FD9F0[];
extern s8 D_00270F40[];
void func_00128580(A *, s32 *);
void func_0014DAB0(s32);
B *func_001ABB20(void);
void func_001256E0(s8 *, s8 *, s32);
void func_00125CE8(s8 *, s8 *);
s32 func_00159D10(s8 *);
s32 func_0015ABD0(s32);
s32 func_0015A300(s32);
void func_0015AB80(s32);
s32 *func_001288C0(A *, s32);
s32 func_0014DB00(s8 *, s32, s8 *);
s32 func_0014DA70(s32);
void func_0014DAC0(s32, s32);
u8 func_0014DAF0(s32);
void func_0010BCA0(s32);
void func_001789E0(s32, s8 *, s32);
void func_00123A88(s32, s8 *, s32);
void func_0014DAE0(s32);
s32 func_0014DA90(s32, s32, s32, s32);
s32 func_0014DA80(s32, s32);
s32 *func_0016F950(s32, s32 *);
s32 func_0016FF80(s32);
void func_001ABCC0(B *, s32 *);
static inline void cleanup(void) {
    if (D_004B4B80[0]) func_00128580(D_00202290, D_004B4B80[0]);
    if (D_004B4B74[0]) {
        func_0014DAB0(D_004B4B74[0]);
        D_004B4B74[0] = 0;
    }
    D_004B4B80[0] = 0;
    D_00202288 = 0;
    D_004B4B74[0] = 0;
    D_0020228C = 0;
    D_004B4B70[0] = 0;
    D_004B4B88[0] = 0;
}

void func_001AB690(void) {
    s8 buf2[0x100];
    s8 buf1[0x100];
    s32 s;
    u32 n;
    s32 r;
    s32 q;
    s32 p;
    B *b;
    s32 c;
    s32 k;

    if (D_00202290 == NULL) return;
    if (D_00202290->f18.f.b1 && D_00202290->x14 != 0) return;
    if (D_0020228C != 0) {
        cleanup();
        return;
    }
    if (D_00202288 == 0) D_00202288 = func_001ABB20();
    if (D_00202288 == 0) return;
    if (!D_00202288->fA8.f.b1) {
        c = D_00202288->h9E == 2 && D_00202288->h9C >= 800;
        k = D_00202288->h9C;
        if (c) func_001256E0(buf1, D_001FD9D0, k);
        else func_001256E0(buf1, D_001FD9F0, k);
        func_00125CE8(buf2, buf1);
        if (D_004B4B78) {
            s = func_0015ABD0(func_00159D10(buf1));
            D_004B4B78[0] = func_0015A300(s);
            func_0015AB80(s);
        }
        D_004B4B80[0] = func_001288C0(D_00202290, D_004B4B78[0]);
        D_004B4B84[0] = 0;
        D_004B4B7C[0] = 0;
        D_004B4B74[0] = func_0014DB00(buf2, 0x102, D_00270F40);
        D_004B4B7C[0] = func_0014DA70(D_004B4B74[0]);
        func_0014DAC0(D_004B4B74[0], 0);
        D_00202288->fA8.f.b1 = 1;
    }
    switch (func_0014DAF0(D_004B4B74[0])) {
    case 0:
        break;
    case 5:
        n = D_004B4B78[0] - D_004B4B7C[0];
        n = (n > 0x80000) ? 0x80000 : n;
        q = (s32)n >> 4;
        r = n - q * 16;
        func_0010BCA0(0);
        func_001789E0(*D_004B4B80[0] + D_004B4B7C[0], D_00270F40, q);
        if (r > 0) func_00123A88(*D_004B4B80[0] + D_004B4B7C[0] + q * 16, D_00270F40 + q * 16, r);
        D_004B4B7C[0] += n;
        func_0014DAE0(D_004B4B74[0]);
        break;
    case 3:
    case 6:
        if (D_004B4B70[0] != 0) break;
        p = *D_004B4B80[0];
        if (D_004B4B88[0] == 0) {
            if (func_0014DA90(D_004B4B74[0], p, p, D_004B4B78[0])) D_004B4B88[0] = 1;
        }
        if (D_004B4B88[0] != 0 && func_0014DA80(D_004B4B74[0], 8) != 0) break;
        D_004B4B88[0] = 0;
        D_004B4B84[0] = func_0016F950(D_002022A0, D_004B4B80[0]);
        b = D_00202288;
        b->x90 = func_0016FF80(*D_004B4B84[0]);
        func_001ABCC0(D_00202288, D_004B4B84[0]);
        D_004B4B80[0] = 0;
        D_004B4B70[0] = 1;
        cleanup();
        break;
    case 1:
    case 2:
    case 4:
        D_00222A54[0].f = 3;
        break;
    }
}
