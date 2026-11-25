#include "m2c.h"
void func_00155900(void);
void func_00154AF0(void);
void func_00176A40(void);
void func_00155370(void);
void func_001552A0(void);
void func_00154B70(void);
void func_00153D80(void);
s32 func_001A9480(void);
void func_001D7FD0(void);
void func_0010C500(s32);
s32 *func_001288C0(s8 *, u32);
void func_001ED5D0(s32, s32, s32, s32);
void func_001ED0C0(s32, s32, s32, void (*)(void), s32, s32, s32, s32);
void func_00180F10(void);
void func_0010C568(s32);
void func_00128580(s8 *, s32 *);
void func_001D7EC0(void);
void func_001558F0(void);
void func_00176A60(void);
void func_00154700(s32, s32);
void func_001545D0(void);
void func_001543E0(s32, s64);
void func_001544C0(void);
extern s8 D_00222AF0[];

void func_0017FF70(s32 arg0) {
    s32 *blk;
    s32 vol;

    func_00155900();
    func_00154AF0();
    func_00176A40();
    func_00155370();
    func_001552A0();
    func_00154B70();
    func_00153D80();
    func_00154AF0();
    func_00155370();
    func_001552A0();
    vol = (func_001A9480() & 0xFF) * 2;
    if (vol > 0x7F) {
        vol = 0x7F;
    }
    func_001D7FD0();
    func_0010C500(9);
    blk = func_001288C0(D_00222AF0, 0xA00000);
    func_001ED5D0(0, 0, 0, 0x1E);
    func_001ED0C0(arg0, *blk, 0xA00000, func_00180F10, vol * 129, 2, 0, 0);
    func_0010C568(9);
    func_00128580(D_00222AF0, blk);
    func_001D7EC0();
    func_001558F0();
    func_00154B70();
    func_00176A60();
    func_00154700(5, -2);
    func_001545D0();
    func_001543E0(0x40, 0x027F0000 | ((s64)0x01BF0000 << 32));
    func_001543E0(0x41, 0x027F0000 | ((s64)0x01BF0000 << 32));
    func_001543E0(0x49, 0);
    func_001544C0();
}
