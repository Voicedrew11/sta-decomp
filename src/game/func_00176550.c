#include "m2c.h"
extern s32 D_00438A10[];
extern s32 D_00438A14[];
extern s32 D_00438A18[];
extern volatile u16 D_00438A1C[];
void func_00176710(u64, u64);
typedef struct { u64 pad:14; u64 lv:6; u64 ty:6; u64 rest:38; } A0;
typedef struct { u16 lo:4; u16 ty:6; u16 hi:6; } C;
typedef struct { u8 lv:6; u8 hi:2; } B;

void func_00176550(s8 *arg0, s32 arg1, s8 *arg2) {
    M2C_FIELD(arg0, u64 *, 0) = M2C_FIELD(arg2, u64 *, 0x40);
    M2C_FIELD(arg0, u64 *, 8) = M2C_FIELD(arg2, u64 *, 0x48);
    func_00176710(M2C_FIELD(arg0, u64 *, 0), M2C_FIELD(arg0, u64 *, 8));
    if (M2C_FIELD(arg2, s32 *, 0x24) == 0) {
        D_00438A18[0] = 0;
    }
    M2C_FIELD(arg0, s16 *, 0x2A) = D_00438A10[0];
    M2C_FIELD(arg0, s16 *, 0x2C) = D_00438A14[0];
    M2C_FIELD(arg0, s16 *, 0x2E) = D_00438A18[0];
    M2C_FIELD(arg2, s8 **, 0x38) = arg0;
    ((B *)(arg2 + 0x2E))->lv = D_00438A1C[0] >> 6;
    if (((B *)(arg2 + 0x2E))->lv <= 0) {
        ((B *)(arg2 + 0x2E))->lv = 1;
    }
    if (((A0 *)arg0)->ty == 0x13 || ((A0 *)arg0)->ty == 0x14) {
        if (((B *)(arg2 + 0x2E))->lv < 2) {
            ((B *)(arg2 + 0x2E))->lv = 2;
        }
    }
    ((A0 *)arg0)->lv = D_00438A1C[0] >> 6;
    if (((A0 *)arg0)->lv == 0) {
        ((A0 *)arg0)->lv = 1;
    }
    if (((C *)(arg0 + 2))->ty == 0x13 || ((C *)(arg0 + 2))->ty == 0x14) {
        if (((A0 *)arg0)->lv < 2) {
            ((A0 *)arg0)->lv = 2;
        }
    }
}
