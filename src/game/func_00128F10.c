#include "m2c.h"
s32 func_00122C88(s32, s32);
void func_001A83A0(s8 *);
void func_00128E80(s32 *);
void func_00178D20(void);
void func_00178C00(s32, u32);
void func_00128A60(s8 *, s8 *, s32, s32);
void func_001AFFA0(s8 *);
void func_001AFCA0(s8 *);
void func_00195C00(s8 *);
extern s32 D_00201C00;
extern s32 D_00201E80;
extern s32 D_00201F90;
extern s8 D_00222700[];
extern s8 *D_00222B50[];
extern s32 D_00222B70[];
extern s32 D_00222B74[];
extern s32 D_00222B78[];
extern s32 D_00222B7C[];
extern s32 D_00222B80[];
extern s32 D_00222B84[];
extern s32 D_00222B88[];

void func_00128F10(void) {
    D_00201C00 = D_00201F90 - 0x40000;
    if (D_00201C00 > 0x06000000) {
        D_00201C00 = 0x06000000;
    }
    D_00201E80 = func_00122C88(0x80, D_00201C00);
    func_00178D20();
    func_00178C00(D_00201E80, (u32)D_00201C00);
    D_00222B78[0] = 0x400000;
    D_00222B88[0] = 0x180000;
    D_00222B74[0] = 0x140000;
    D_00222B80[0] = 0x40000;
    D_00222B84[0] = 0x2C0000;
    D_00222B7C[0] = 0xF00000;
    D_00222B70[0] = 0x100000;
    func_00128E80(D_00222B70);
    func_00128A60(D_00222700, D_00222B50[0], D_00222B70[0], 0x80);
    func_001AFFA0(D_00222700);
    func_001AFCA0(D_00222700);
    func_00195C00(D_00222700);
    func_001A83A0(D_00222700);
}
