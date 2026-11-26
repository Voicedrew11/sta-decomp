#include "m2c.h"
typedef struct { u8 b0, b1, b2, b3, b4, b5, b6, b7; } Slot;
typedef struct { u8 pad0[0x2E]; u8 x2E; u8 x2F; u8 pad30[0x5C00 - 0x30]; Slot slot[0x400]; } W;
typedef struct { u8 x0[0x20]; u8 x20[0x20]; u8 x40[0x20]; u8 x60[0x120]; u8 x180[0x40]; } Rec;
typedef struct { u8 pad0[0xE]; u8 xE; u8 xF; u8 pad10[0xA0 - 0x10]; u32 xA0[0x40]; } Sv;
extern W *D_00201DC0;
extern Rec *D_00201DC4;
Sv *func_001C9BA0(void);
void memset(void *, s32, s32);
void func_001A95A0(s16, u8);
static inline Slot *slot(s16 id) {
    Slot *s;
    if (0 > id || id >= 0x400) {
        s = NULL;
    } else {
        s = &D_00201DC0->slot[id];
    }
    return s;
}

void func_001AA760(void) {
    Sv *sv;
    s32 i;
    sv = func_001C9BA0();
    for (i = 0; i < 0x2A; i++) {
        memset(D_00201DC4[i].x0, 0, 0x20);
        memset(D_00201DC4[i].x20, 0, 0x20);
        memset(D_00201DC4[i].x40, 0, 8);
        memset(D_00201DC4[i].x60, 0, 0x120);
        memset(D_00201DC4[i].x180, 0, 0x40);
    }
    memset(&D_00201DC4[0x2A], 0, 0x20);
    D_00201DC0->x2E = 1;
    D_00201DC0->x2F = 10;
    for (i = 0x1F; i <= 0x31; i++) {
        memset(&sv->xA0[i], 0, 4);
        memset(slot(i), 0, 8);
    }
    for (i = 3; i <= 0xB; i++) {
        if ((u32)(i - 4) > 1) {
            func_001A95A0(i, 10);
        }
    }
    func_001A95A0(0x14, 5);
    func_001A95A0(0x15, 0x14);
    func_001A95A0(0x16, 5);
    func_001A95A0(0x17, 0x1E);
    for (i = 0x3D; i <= 0x45; i++) {
        if (i == 0x42 || i == 0x43) {
            func_001A95A0(i, 0x28);
        } else {
            func_001A95A0(i, 5);
        }
    }
    func_001A95A0(0x6A, 1);
    func_001A95A0(0x7B, 1);
    func_001A95A0(0xE0, 1);
    func_001A95A0(0xED, 1);
    func_001A95A0(0xF5, 1);
    func_001A95A0(0x133, 1);
    func_001A95A0(0x148, 1);
    func_001A95A0(0x151, 1);
    func_001A95A0(0x1A1, 1);
    func_001A95A0(0x1FA, 1);
    func_001A95A0(0x25B, 1);
    func_001A95A0(0x25D, 1);
    func_001A95A0(0x2D6, 1);
    func_001A95A0(0x2DF, 1);
    func_001A95A0(0x2FF, 1);
    func_001A95A0(0x300, 1);
    func_001A95A0(0x323, 1);
    func_001A95A0(0x32F, 1);
    func_001A95A0(0x331, 1);
    func_001A95A0(0x33F, 1);
    func_001A95A0(0x347, 1);
    func_001A95A0(0x355, 1);
    func_001A95A0(0x369, 1);
    func_001A95A0(0x392, 1);
    func_001A95A0(0x397, 1);
    func_001A95A0(0x39C, 1);
    func_001A95A0(0x3A9, 1);
    func_001A95A0(0x3C6, 1);
    func_001A95A0(0x3CC, 1);
    sv->xE = 1;
    sv->xF = 10;
}
