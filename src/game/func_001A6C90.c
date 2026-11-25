#include "common.h"
typedef struct { char pad[0x5A1]; unsigned char : 4; unsigned char f : 1; } BF_5A1_4_1;
typedef struct { char pad[0x5A0]; unsigned char : 2; unsigned char f : 1; } BF_5A0_2_1;
void sceVu0AddVector(u8 *, u8 *, u8 *);        /* extern */
void sceVu0CopyVector(u8 *, u8 *);               /* extern */

void func_001A6C90(u8 *arg0) {
    u8 *temp_17;
    u8 **temp_2;
    u8 *temp_16;

    if (arg0 != NULL) {
        if (!(M2C_FIELD(arg0, u8 *, 0x5A0) & 1)) {
            ((BF_5A1_4_1 *)arg0)->f = 1;
            return;
        }
        ((BF_5A1_4_1 *)arg0)->f = 0;
        ((BF_5A0_2_1 *)arg0)->f = 1;
        temp_2 = M2C_FIELD(arg0, u8 ***, 0x4A8);
        if (temp_2 != NULL) {
            temp_17 = *temp_2;
            temp_16 = M2C_FIELD(arg0, u8 **, 0x518);
            func_001B59E0(M2C_FIELD(temp_17, s32 *, 0x13C) + (M2C_FIELD(arg0, u16 *, 0x4AC) * 0x54), temp_16, temp_16 + 0x20, temp_16 + 0x50);
            sceVu0AddVector(temp_16, temp_16, temp_17 + 0x10);
            sceVu0CopyVector(temp_16 + 0x10, temp_16);
            sceVu0CopyVector(temp_16 + 0x30, temp_16 + 0x20);
        }
        func_001A6DC0(arg0);
        if (M2C_FIELD(arg0, u16 *, 0) != 0) {
            func_00136700(arg0);
            func_001A7030(arg0, 1, 0);
        }
    }
}
