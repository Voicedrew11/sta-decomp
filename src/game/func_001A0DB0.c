#include "m2c.h"
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; } F;
typedef struct { u8 pad[7]; u8 lv; u8 pad8[0x88]; } E;
typedef struct { u8 pad[5]; u8 kind; } K;
void func_0018B320(s32 *);
void func_0018B150(f32, s32 *, s32, s32, void (*)(), s32);
void func_0019F890();
void func_001A13F0();
void func_00131600(s32, s32);
E *func_001AFC90(void);
K *func_001A97D0(s16);
u8 *func_001CC3F0(s16);
s16 func_001CBA30(void);
extern s32 D_004A32E0[];
extern s32 D_004A32E4[];
extern s32 D_004A32E8[];
extern void (*D_004A32EC[])();
extern s32 D_004A32F0[];
extern u16 D_004A3310[];
extern s16 D_004A3312[];
extern s32 D_004A3318[];
extern s32 D_004A331C[];
extern s32 D_004A3328[];
extern F D_004A332C[];

void func_001A0DB0(s8 *a0) {
    s32 id;
    E *t;
    s16 m;
    s16 r;

    if (D_004A332C[0].b4) {
        D_004A32E0[0] = 0;
        D_004A32E4[0] = 3;
        D_004A32EC[0] = func_0019F890;
        D_004A32F0[0] = 0x3F800000;
        D_004A32E8[0] = 0;
        func_0018B320(D_004A32E0);
        a0[0xA] = 1;
        D_004A332C[0].b4 = 0;
        D_004A3328[0] = 0x41200000;
        return;
    }
    if (*(s32 *)(a0 + 4) & 0x2000) {
        id = D_004A3310[0];
        t = func_001AFC90();
        if (func_001A97D0(id)->kind == 2) {
            m = 5;
        } else if (*func_001CC3F0(id) <= 0) {
            m = 1;
        } else {
            m = t[id].lv;
        }
        r = func_001CBA30();
        if (r + D_004A3312[0] * m > 99) {
            func_0018B150(1.0f, D_004A32E0, 0xA5, 2, func_001A13F0, 0);
            func_0018B320(D_004A32E0);
            a0[0xA] = 1;
            a0[0xB] = 1;
            func_00131600(0x6B, *(u8 *)(a0 + 0xE));
            return;
        }
        D_004A3318[0] = D_004A331C[0];
        D_004A332C[0].b2 = 1;
        func_00131600(0x67, *(u8 *)(a0 + 0xE));
        return;
    }
    if (*(s32 *)(a0 + 4) & 0x4000) {
        D_004A332C[0].b2 = 1;
        func_00131600(0x68, *(u8 *)(a0 + 0xE));
    }
}
