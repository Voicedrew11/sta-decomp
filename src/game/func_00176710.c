#include "m2c.h"
typedef struct {
    u64 TBP0:14; u64 TBW:6; u64 PSM:6; u64 TW:4; u64 TH:4; u64 TCC:1; u64 TFX:2;
    u64 CBP:14; u64 CPSM:4; u64 CSM:1; u64 CSA:5; u64 CLD:3;
} Tex0;
typedef struct {
    u64 LCM:1; u64 pad01:1; u64 MXL:3; u64 MMAG:1; u64 MMIN:3; u64 MTBA:1; u64 pad10:9; u64 L:2; u64 pad21:11; u64 K:12; u64 pad44:20;
} Tex1;
typedef struct { Tex0 t0; Tex1 t1; } TexRegs;
typedef struct { u32 a10; u32 a14; u32 a18; u16 a1C; u16 a1E; u16 a20; u16 a22; s32 a24; } TexInfo;
extern TexInfo D_00438A10;

void func_00176710(Tex0 t0, Tex1 t1) {
    u32 s;
    u32 n;

    D_00438A10.a1E = t0.TH;
    D_00438A10.a1E = 1 << D_00438A10.a1E;
    D_00438A10.a1C = 1 << t0.TW;
    switch (t0.PSM) {
    case 0:
    case 0x30:
        D_00438A10.a24 = 32;
        break;
    case 1:
    case 0x31:
        D_00438A10.a24 = 24;
        break;
    case 2:
    case 0xA:
    case 0x32:
    case 0x3A:
        D_00438A10.a24 = 16;
        break;
    case 0x13:
        D_00438A10.a24 = 8;
        break;
    case 0x1B:
    case 0x14:
        D_00438A10.a24 = 4;
        break;
    case 0x24:
    case 0x2C:
        break;
    }
    D_00438A10.a14 = (D_00438A10.a24 * (D_00438A10.a1C * D_00438A10.a1E) / 8 + 15) / 16;
    s = D_00438A10.a14;
    D_00438A10.a10 = s;
    if (t1.MXL != 0) {
        n = t1.MXL;
        while (n--) {
            s >>= 2;
            D_00438A10.a10 += s;
        }
    }
    if (D_00438A10.a24 == 4) {
        if (t0.CPSM == 0) {
            D_00438A10.a18 = 4;
        } else {
            D_00438A10.a18 = 2;
        }
        D_00438A10.a20 = 8;
        D_00438A10.a22 = 2;
    } else if (D_00438A10.a24 == 8) {
        if (t0.CPSM == 0) {
            D_00438A10.a18 = 0x40;
        } else {
            D_00438A10.a18 = 0x20;
        }
        D_00438A10.a20 = 16;
        D_00438A10.a22 = 16;
    } else {
        D_00438A10.a18 = 0;
        D_00438A10.a20 = 0;
        D_00438A10.a22 = 0;
    }
}
