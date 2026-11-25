#include "actor.h"
typedef struct { u8 a : 5; u8 m : 2; u8 b7 : 1; } M;
typedef struct { u8 c[2]; } B2;
typedef struct {
    u8 pad0[0x3A2];
    M x3A2;
    u8 pad3A3[0xD];
    s32 x3B0;
    u8 pad3B4[0xA];
    u8 x3BE;
    u8 pad3BF[0x11];
    f32 x3D0;
    u8 pad3D4;
    u8 x3D5;
    u8 pad3D6[0x4A];
    s8 x420;
    s8 x421;
    u16 x422;
    u8 pad424[0x2C];
    s32 x450;
} P;
extern s32 D_002022E0;
extern B2 D_00201E28;
extern u64 D_002F1420[];
extern Flags8 D_00222A54[];
void func_001545D0(void);
void func_001543E0(s32, s64);
void func_001544C0(void);
u8 func_001A94A0(void);
void func_001BBCC0(void);
void func_001BC610(s32, s32, s32, s32, u32, s32, s32);
s32 func_00120570(s32);
s32 func_001CE200(s32);
void func_001BC7A0(s8, s8, u16);
static inline P *cur(void) {
    if (D_002022E4 == 0) return 0;
    if (D_002022E4->unk518 == 0) return 0;
    return (P *)(D_002022E4->unk518 + 0x180);
}

void func_001BCB60(void) {
    P *p;
    P *q;
    u32 c;
    u8 n;
    u8 k;
    s32 i;
    B2 t;

    p = cur();
    if (p == 0) return;
    func_001545D0();
    func_001543E0(0x40, D_002F1420[0]);
    func_001543E0(0x41, D_002F1420[0]);
    func_001544C0();
    D_002022E0 = (func_001A94A0() == 2) ? 0x2C : 0;
    func_001BBCC0();
    if (p->x3A2.m == 1) {
        q = cur();
        if (q != 0 && (q->x3D5 == 3 || q->x3D5 == 4) && D_00222A54[0].f.b2) {
            func_001545D0();
            func_001543E0(0x42, 0x48);
            func_001544C0();
            func_001BC610(-8, -8, 8, 8, -0x8000, 1, q->x450);
        }
    } else if (p->x3A2.m == 2) {
        q = cur();
        if (q != 0) {
            c = (u32)(128.0f * (-1.0f * (q->x3D0 / -0.17453293f))) << 24;
            func_001545D0();
            func_001543E0(0x42, 0x44);
            func_001544C0();
            func_001BC610(-0x140, -0xE0, 0x140, 0xE0, c, 1, q->x3B0);
        }
    }
    i = p->x3BE;
    if (i != 0) {
        n = i;
        if (n > 12) {
            k = (f32)(func_00120570(n - 15) * 96) / 3.0f;
        } else {
            k = (f32)(n * 96) / 12.0f;
        }
        func_001545D0();
        func_001543E0(0x42, 0x48);
        func_001544C0();
        func_001BC610(-0x140, -224.0f + (f32)D_002022E0, 0x140, 224.0f - (f32)D_002022E0, (k << 24) | 0x80, 1, 0);
    }
    i = func_001CE200(2);
    if (i != 0) {
        t = D_00201E28;
        c = t.c[i - 1] << 24;
        func_001545D0();
        func_001543E0(0x42, 0x44);
        func_001544C0();
        func_001BC610(-0x140, -224.0f + (f32)D_002022E0, 0x140, 224.0f - (f32)D_002022E0, c, 1, 0);
    }
    func_001BC7A0(p->x420, p->x421, p->x422);
}
