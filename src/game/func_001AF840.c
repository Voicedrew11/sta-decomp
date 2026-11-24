#include "m2c.h"
void func_00128580(s32, s32);
void func_0014DAB0(s32);
void func_001AF4A0(s8 *);
extern s32 D_00202288;
extern s32 D_0020228C;
extern s32 D_00202290;
extern s16 D_004AC5A0[];
extern s16 D_004AC5A2[];
extern s16 D_004AC5A4[];
extern s16 D_004AC5A6[];
extern s8 D_004AC630[];
extern s8 D_004AC970[];
extern s8 D_004AE370[];
extern s32 D_004B4B70[];
extern s32 D_004B4B74[];
extern s32 D_004B4B80[];
extern s32 D_004B4B88[];

void func_001AF840(void) {
    s32 i;
    if (D_004B4B80[0] != 0) {
        func_00128580(D_00202290, D_004B4B80[0]);
    }
    if (D_004B4B74[0] != 0) {
        func_0014DAB0(D_004B4B74[0]);
        D_004B4B74[0] = 0;
    }
    D_004B4B80[0] = 0;
    D_004B4B74[0] = 0;
    D_00202288 = 0;
    D_004B4B70[0] = 0;
    D_0020228C = 0;
    D_004B4B88[0] = 0;
    for (i = 0; i < 0x40; i++) {
        func_001AF4A0(D_004AE370 + i * 0xD0);
        func_001AF4A0(D_004AE370 + i * 0xD0 + 0x3400);
    }
    for (i = 0; i < 0x10; i++) {
        func_001AF4A0(D_004AC970 + i * 0xD0);
        func_001AF4A0(D_004AC970 + i * 0xD0 + 0xD00);
    }
    for (i = 0; i < 4; i++) {
        func_001AF4A0(D_004AC630 + i * 0xD0);
    }
    D_004AC5A0[0] = 0;
    D_004AC5A2[0] = 0;
    D_004AC5A4[0] = 0;
    D_004AC5A6[0] = 0;
}
