#include "m2c.h"
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; } F;
typedef struct { u8 pad[4]; u8 max; } K;
typedef struct { u8 pad[2]; u8 n; } C;
void func_0018B320(s32 *);
void func_0018B150(f32, s32 *, s32, s32, void (*)(), s32);
void func_0019F690();
void func_001A13F0();
void func_00131600(s32, s32);
K *func_001A97D0(s16);
C *func_001CC3F0(s16);
extern s32 D_004A32E0[];
extern s32 D_004A32E4[];
extern s32 D_004A32E8[];
extern void (*D_004A32EC[])();
extern s32 D_004A32F0[];
extern s16 D_004A3310[];
extern s16 D_004A3312[];
extern s32 D_004A3318[];
extern s32 D_004A331C[];
extern s32 D_004A3328[];
extern F D_004A332C[];

void func_001A0B00(s8 *a0) {
    s16 n; s32 m; u8 c;

    if (D_004A332C[0].b4) {
        D_004A32E0[0] = 0;
        D_004A32E4[0] = 3;
        D_004A32EC[0] = func_0019F690;
        D_004A32F0[0] = 0x3F800000;
        D_004A32E8[0] = 0;
        func_0018B320(D_004A32E0);
        a0[0xA] = 1;
        D_004A332C[0].b4 = 0;
        D_004A3328[0] = 0x41200000;
        return;
    }
    if (*(s32 *)(a0 + 4) & 0x80) {
        D_004A3312[0]--;
        if (D_004A3312[0] <= 0) {
            D_004A3312[0] = 1;
            return;
        }
        func_00131600(0x6A, *(u8 *)(a0 + 0xE));
        return;
    }
    if (*(s32 *)(a0 + 4) & 0x20) {
        D_004A3312[0]++;
        m = D_004A3312[0];
        if (func_001CC3F0(D_004A3310[0])->n < m) {
            D_004A3312[0] = func_001CC3F0(D_004A3310[0])->n;
            return;
        }
        func_00131600(0x6A, *(u8 *)(a0 + 0xE));
        return;
    }
    if (*(s32 *)(a0 + 4) & 0x2000) {
        n = D_004A3312[0];
        c = func_001A97D0(D_004A3310[0])->max;
        if ((s16)n + c > 99) {
            func_0018B150(1.0f, D_004A32E0, 0xA1, 2, func_001A13F0, 0);
            func_0018B320(D_004A32E0);
            a0[0xA] = 1;
            a0[0xB] = 1;
            func_00131600(0x6B, *(u8 *)(a0 + 0xE));
            return;
        }
        if (n) {
            D_004A3318[0] = D_004A331C[0];
            D_004A332C[0].b2 = 1;
            func_00131600(0x67, *(u8 *)(a0 + 0xE));
            return;
        }
        func_00131600(0x68, *(u8 *)(a0 + 0xE));
        return;
    }
    if (*(s32 *)(a0 + 4) & 0x4000) {
        D_004A332C[0].b2 = 1;
        func_00131600(0x68, *(u8 *)(a0 + 0xE));
    }
}
