#include "m2c.h"
typedef struct { s32 state; s32 x4; u8 x8; u8 x9; u8 pad[4]; u8 xE; u8 xF; } P;
s8 *func_001C9BA0(void);
void func_0012F6E0(s32);
void func_0012C260(void);
void func_00180F50(f32);
void func_0012F640(void);
void func_0012C2C0(void);
void func_0012C210(void);
void func_00131600(s32, u8);
void func_00193850(s32);
void func_00189ED0(s32);
extern s32 D_002021C0;
extern s32 D_002021D8;
extern s32 D_002021DC;
extern s32 D_004A3320[];

void func_0019B590(P *p) {
    s8 *b;

    b = func_001C9BA0();
    if (p->state == 0x19) {
        func_0012F6E0(1);
        func_0012C260();
    }
    if (p->state == 0) {
        func_00180F50(90.0f);
        D_002021D8 = *(s16 *)(b + 4);
        D_002021DC = *(s16 *)(b + 6);
    }
    D_002021C0 = 0;
    if (p->state == 0x16) {
        D_002021C0 = 1;
        if (p->xF) {
            func_0012F640();
            func_0012F6E0(0);
            func_0012C2C0();
            func_0012C210();
        }
        switch (p->xF) {
        case 0x1F:
            p->x8 = p->xF;
            p->xF = 0;
            D_002021C0 = 0;
            p->x4 = 0;
            p->state = 0x1F;
            func_00131600(0x2BD, p->xE);
            break;
        case 0x28:
            p->x8 = p->xF;
            p->xF = 0;
            D_002021C0 = 0;
            p->x4 = 0;
            p->state = 0x1F;
            break;
        case 0xA:
            p->x8 = p->xF;
            p->xF = 0;
            D_002021C0 = 0;
            func_00193850(0);
            func_00189ED0(0x12);
            p->x4 = 0;
            p->state = 0x1F;
            func_00131600(0x2BC, p->xE);
            break;
        case 0x14:
            p->x8 = p->xF;
            p->xF = 0;
            D_002021C0 = 0;
            p->x4 = 0;
            p->state = 0x1F;
            func_00131600(0x64, p->xE);
            break;
        case 0x80:
            p->xF = 0;
            D_002021C0 = 0;
            p->x9 = 0;
            D_004A3320[0] = 5;
            p->x8 = 0x22;
            func_00189ED0(0x12);
            p->x4 = 0;
            p->state = 0x1F;
            func_00131600(0x2BD, p->xE);
            break;
        case 0x81:
            p->xF = 0;
            D_002021C0 = 0;
            p->x9 = 0;
            D_004A3320[0] = 6;
            p->x8 = 0x22;
            func_00189ED0(0x12);
            p->x4 = 0;
            p->state = 0x1F;
            func_00131600(0x2BD, p->xE);
            break;
        case 0x29:
            p->xF = 0;
            D_002021C0 = 0;
            p->x9 = 0;
            p->x8 = 0x29;
            func_00189ED0(1);
            p->x4 = 0;
            p->state = 0x1A;
            break;
        case 0x13:
            p->xF = 0;
            D_002021C0 = 0;
            p->x9 = 0;
            p->x8 = 0x13;
            p->x4 = 0;
            p->state = 0x1F;
            break;
        case 0x11:
            p->xF = 0;
            D_002021C0 = 0;
            p->x9 = 0;
            p->x8 = 0x11;
            p->x4 = 0;
            p->state = 0x1F;
            break;
        case 0x25:
            p->xF = 0;
            D_002021C0 = 0;
            p->x9 = 0;
            p->x8 = 0x25;
            p->x4 = 0;
            p->state = 0x1F;
            break;
        case 0x24:
            p->xF = 0;
            D_002021C0 = 0;
            p->x9 = 0;
            p->x8 = 0x24;
            p->x4 = 0;
            p->state = 0x1F;
            break;
        }
    }
}
