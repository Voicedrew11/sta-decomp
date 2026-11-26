#include "m2c.h"
M2C_UNK sceVu0InterVector(f32, s8 *, M2C_UNK *, M2C_UNK *); /* extern */
M2C_UNK sceVu0CopyVector(s8 *, M2C_UNK *);             /* extern */
M2C_UNK func_00157630();                            /* extern */
M2C_UNK func_001580E0(M2C_UNK *);                   /* extern */
extern s32 D_002F19B0[];
extern s8 D_002F19C0[];
extern s8 D_002F19CC[];
extern s32 D_002F19D8[];
extern s32 D_002F19DC[];
extern s16 D_002F1A48[];
extern M2C_UNK D_002F1A60[];
extern M2C_UNK D_002F1A80[];
extern s8 D_002F1AA0[];
extern M2C_UNK D_002F1AB0[];
extern M2C_UNK D_002F1AC0[];
extern f32 D_002F1AD0[];
extern f32 D_002F1AD4[];
extern u8 D_002F2078[];

void func_00159680(void) {
    s32 sp1C;
    s32 sp18;
    f32 temp_f1;

    if (((u64) ((s64) D_002F2078[0] << 0x38) >> 0x3F) != 0) {
        func_00154700(D_002F19B0[0], -1);
        if (D_002F2078[0] & 1) {
            func_00158900(D_002F19C0);
        }
        func_00156AF0();
        func_00157320(0);
        func_00155900();
        if ((D_002F1AD0[0] += 0.033333335f) > D_002F1AD4[0]) {
            D_002F1AD4[0] = 0.0f;
        }
        if (D_002F1AD4[0] == 0.0f) {
            sceVu0CopyVector(D_002F1AA0, D_002F1AB0);
        } else {
            sceVu0InterVector(1.0f - (D_002F1AD0[0] / D_002F1AD4[0]), D_002F1AA0, D_002F1AC0, D_002F1AB0);
        }
        func_00154700(D_002F19B0[0], 0);
        D_002F19DC[0] = 0;
        D_002F1A48[0] = 2;
        D_002F19D8[0] = 0;
        if (((u64) ((s64) D_002F2078[0] << 0x3C) >> 0x3F) != 0) {
            func_00158EE0(D_002F1AA0);
        }
        func_00156F60();
        func_00155900();
        return;
    }
    func_00154700(D_002F19B0[0], -1);
    if (D_002F2078[0] & 1) {
        func_00158900(D_002F19C0);
    }
    if (((u64) ((s64) D_002F2078[0] << 0x3E) >> 0x3F) != 0) {
        func_00158900(D_002F19CC);
    }
    if (((u64) ((s64) D_002F2078[0] << 0x3D) >> 0x3F) != 0) {
        func_00159160(&sp1C, &sp18);
        if (D_002F1A48[0] != 1) {
            func_00158BF0(sp1C, sp18);
        }
    }
    func_00157320(0);
    func_00155900();
    func_00154700(D_002F19B0[0], 0);
    if (((u64) ((s64) D_002F2078[0] << 0x3B) >> 0x3F) != 0) {
        func_001580E0(D_002F1A60);
    }
    if (((u64) ((s64) D_002F2078[0] << 0x3A) >> 0x3F) != 0) {
        func_001580E0(D_002F1A80);
    }
    if (D_002F1A48[0] != 0) {
        D_002F1A48[0] -= 1;
    }
    if (((u64) ((s64) D_002F2078[0] << 0x39) >> 0x3F) != 0) {
        func_00157630();
    }
    func_00156CE0();
    if (((u64) ((s64) D_002F2078[0] << 0x3C) >> 0x3F) != 0) {
        func_00158EE0(D_002F1AA0);
    }
    func_00156F60();
    func_00155900();
}
