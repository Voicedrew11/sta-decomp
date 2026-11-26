#include "m2c.h"
void strcpy(void *, s32);
u32 strlen(void *);
void func_00187A90(void *, void *, u64);
extern u16 D_00317238[];
extern u8 D_004A0B50[];
extern s32 D_004A0F54[];
extern f32 D_004A0F58[];
extern u8 D_004A0F5C[];
extern s32 D_004A0F60[];
extern s32 D_004A0F64[];
typedef struct { u8 a:3; u8 b:5; } BF;
extern BF D_004A0F68[];
extern s16 D_004A0F6C[];
extern s32 D_004A0F80[];
extern s32 D_004A0F84[];

s32 func_0018AEB0(s32 arg0, s32 arg1) {
    switch (D_004A0F54[0]) {
    case 0:
        strcpy(D_004A0B50, arg0);
        func_00187A90(D_004A0F60, D_004A0B50, strlen(D_004A0B50));
        D_004A0F84[0] = 0x3F800000;
        D_004A0F60[0] = 0x43A00000;
        D_004A0F64[0] = 0x43A00000;
        D_004A0F80[0] = 0x3FA66666;
        D_004A0F6C[0] = 2;
        D_004A0F68[0].a = 1;
        if (arg1 > 0) {
            D_004A0F54[0] = 3;
            D_004A0F58[0] = (f32) arg1;
        } else if (arg1 == -1) {
            D_004A0F54[0] = 5;
            D_004A0F58[0] = 60.0f;
        } else {
            D_004A0F54[0] = 2;
            D_004A0F58[0] = 60.0f;
        }
        return 0;
    case 3:
        if (D_004A0F58[0] < 0.0f) {
            D_004A0F54[0] = 0;
            return 3;
        }
        break;
    case 5:
        if ((D_00317238[0] & 0x2000) && (D_004A0F5C[0] & 1)) {
            return 3;
        }
        break;
    case 2:
        if ((D_00317238[0] & 0x2000) && (D_004A0F5C[0] & 1)) {
            D_004A0F54[0] = 3;
            D_004A0F58[0] = 8.0f;
        }
        break;
    case 4:
        D_004A0F54[0] = 0;
        return 0;
    }
    return 1;
}
