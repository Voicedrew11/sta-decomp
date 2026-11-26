#include "m2c.h"
typedef struct { u64 pmode; u64 smode2; u64 dispfb; u64 display; u64 bgcolor; } DispEnv;
typedef struct { u64 r[16]; } DrawEnv1;
typedef struct {
    u64 testa; u64 testaaddr;
    u64 prim; u64 primaddr;
    u64 rgbaq; u64 rgbaqaddr;
    u64 xyz2a; u64 xyz2aaddr;
    u64 xyz2b; u64 xyz2baddr;
    u64 testb; u64 testbaddr;
} Clear;
typedef struct { DispEnv disp[2]; u64 giftag0[2]; DrawEnv1 draw0; Clear clear0; u64 giftag1[2]; DrawEnv1 draw1; Clear clear1; } DBuff;
extern s8 D_00222AF0[];
extern s32 *D_00202150;
extern s32 *D_0020214C;
extern s32 D_00202148;
extern s32 D_00202144;
extern s8 D_001FD250[];
void func_00155900(void);
void func_00154AF0(void);
void func_00155370(void);
void func_001552A0(void);
void func_00154B70(void);
void func_00153D80(void);
s32 func_00101088(s32);
void func_00100200(s32, s32, s32, s32);
void func_00159DD0(s32, s8 *, void *, s32 *);
s32 func_001E3AF8(s32);
s32 *func_001288C0(s8 *, s32);
void func_001E3B48(s32, s32);
void func_001E3DB8(s32);
void func_00100D90(DBuff *, s32, s32, s32, s32, s32, s32);
void func_0010BCA0(s32);
s32 func_00130590(s8 *, s32, s32);
void func_00101028(DBuff *, s32);
void func_00101120(s32, s32);
s32 func_001E3CA0(void);
void func_001304B0(s32);
void func_001017A0(DrawEnv1 *, s32, s32, s16);
void func_001304C0(void);
void func_00130440(void);
void func_00128580(s8 *, s32 *);
void func_001558F0(void);
void func_00154700(s32, s32);
void func_001545D0(void);
void func_001543E0(s32, u64);
void func_001544C0(void);

void func_00194FC0(void) {
    DBuff db;
    s32 x;
    s32 fr;
    s32 i;

    func_00155900();
    func_00154AF0();
    func_00155370();
    func_001552A0();
    func_00154B70();
    func_00153D80();
    func_00154AF0();
    func_00155370();
    func_001552A0();
    func_00101088(0);
    func_00100200(0, 1, 2, 1);
    x = 0;
    func_00159DD0(0xC6EE908E, D_00222AF0, &D_00202150, &x);
    D_00202148 = *D_00202150;
    D_0020214C = func_001288C0(D_00222AF0, func_001E3AF8(D_00202148));
    D_00202144 = *D_0020214C;
    func_001E3B48(D_00202148, D_00202144);
    func_001E3DB8(2);
    func_00100D90(&db, 0, 0x280, 0xE0, 3, 0x3A, 1);
    db.clear1.rgbaq = db.clear0.rgbaq = ((u64)0x80 << 24) | ((u64)0x3F800000 << 32);
    func_0010BCA0(0);
    func_00130590(D_001FD250, 0, 0);
    fr = func_00101088(0);
loop:
        func_0010BCA0(0);
        func_00101028(&db, fr);
        func_00101120(0, 0);
    if (func_001E3CA0() == 0) goto flip;
            i = 0;
            func_001304B0(-0x100);
            for (; i < 0x80; i++) {
                func_001017A0(fr ? &db.draw0 : &db.draw1, 0x800, 0x800, fr);
                fr = !(fr != 0);
                func_001304C0();
                func_00101088(0);
                func_0010BCA0(0);
                func_00101028(&db, fr);
                func_00101120(0, 0);
            }
    goto done;
flip:
        func_001017A0(fr ? &db.draw0 : &db.draw1, 0x800, 0x800, fr);
        fr = !(fr != 0);
        func_001304C0();
        func_00101088(0);
    goto loop;
done:
    func_00130440();
    func_00128580(D_00222AF0, D_0020214C);
    func_00128580(D_00222AF0, D_00202150);
    func_001558F0();
    func_00154B70();
    func_00154700(5, -2);
    func_001545D0();
    func_001543E0(0x40, 0x27F0000 | ((u64)0x1BF0000 << 32));
    func_001543E0(0x41, 0x27F0000 | ((u64)0x1BF0000 << 32));
    func_001543E0(0x49, 0);
    func_001544C0();
}
