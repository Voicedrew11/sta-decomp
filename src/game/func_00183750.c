#include "m2c.h"
typedef struct { u8 b[256]; } Buf;
typedef struct { u8 a:1; u8 b:1; u8 c:1; } BF;
void sprintf(u8 *, M2C_UNK *, s32);        /* extern */
s8 *func_001E1570(u8 *, M2C_UNK);                 /* extern */
extern M2C_UNK D_001FC9F0[];
extern M2C_UNK D_001FCA08[];
extern s32 D_00201CDC;
extern s32 D_00201CE0;
extern s32 D_00201CE4;
extern s32 D_00201CE8;
extern s32 D_002020A8;
extern s8 *D_002020AC;
extern s8 *D_0048D0E4[];
extern s32 D_0048D0F0[];
extern s32 D_0048D0F4[];
extern s32 D_0048D0F8[];
extern s32 D_0048D0FC[];
extern s32 D_0048D100[];
extern s32 D_0048D104[];
extern s32 D_0048D108[];
extern s32 D_0048D10C[];
void func_00177570(s8 *);
s32 func_00177F80(u8 *);
s32 func_00177AF0(s32, s32);

void func_00183750(s32 arg0) {
    s32 temp_s0;
    u8 temp_a0;

    if (arg0 <= 0) {
        if ((D_002020AC != NULL) && (((u64) ((s64) M2C_FIELD(D_002020AC, u8 *, 8) << 0x3D) >> 0x3F) != 0) && (D_0048D0E4[0] != NULL)) {
            func_00177570(D_0048D0E4[0]);
            D_0048D0E4[0] = NULL;
            D_00201CE8 = -1;
        }
        return;
    }
    if (D_00201CE8 != arg0) {
        if (D_002020AC != NULL && (((u64) ((s64) M2C_FIELD(D_002020AC, u8 *, 8) << 0x3E) >> 0x3F) != 0)) {
            return;
        }
        if ((D_002020AC != NULL) && (((u64) ((s64) M2C_FIELD(D_002020AC, u8 *, 8) << 0x3D) >> 0x3F) != 0) && (D_0048D0E4[0] != NULL)) {
            func_00177570(D_0048D0E4[0]);
            D_0048D0E4[0] = NULL;
        }
        D_00201CE8 = arg0;
        D_00201CE0 = -1;
        D_00201CDC = -1;
        D_00201CE4 = -1;
        {
            Buf s = {0};
        sprintf(s.b, D_001FC9F0, D_00201CE8);
            D_002020AC = func_001E1570(s.b, 0xA);
            D_0048D0F0[0] = 0;
            D_0048D0F4[0] = 0;
            D_002020A8 = 0;
            D_0048D0F8[0] = 0x43800000;
            D_0048D0FC[0] = 0x43800000;
            D_0048D100[0] = 0;
            D_0048D104[0] = 0;
            D_0048D108[0] = 0x43800000;
            D_0048D10C[0] = 0x43800000;
        }
    }
    {
        u8 name[16];
    if (D_002020AC != NULL) {
            temp_a0 = M2C_FIELD(D_002020AC, u8 *, 8);
            if ((((u64) ((s64) temp_a0 << 0x3E) >> 0x3F) == 0) && (((u64) ((s64) temp_a0 << 0x3D) >> 0x3F) == 0) && (temp_a0 & 1)) {
                sprintf(name, D_001FCA08, D_00201CE8);
                temp_s0 = M2C_FIELD(D_002020AC, s32 *, 0);
                if (temp_s0 != 0) {
                    D_0048D0E4[0] = (s8 *)func_00177AF0(func_00177F80(name), temp_s0);
                    ((BF *)(D_002020AC + 8))->c = 1;
                }
            }
        }
    }
}
