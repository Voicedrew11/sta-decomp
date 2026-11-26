#include "m2c.h"
typedef struct { s32 state; s32 buttons; u8 next; u8 pad[5]; u8 pad_e; } Menu;
typedef struct { u8 b0:1; } BF;
void func_00131600(s32, u8);
void func_0017F7C0(s32, s32, s32);
s32 func_0017F470(s32, s32, f32);
void func_0012F6E0(s32);
void func_0012C260(void);
void func_001C9BA0(void);
void func_001CAEF0(s16);
void func_0019DCF0(void);
void memset(void *, s32, s32);
extern s32 *D_00201D68;
extern s32 D_002021E0;
extern s32 D_002021E8;
extern s32 D_002021EC;
extern s32 D_002021F0;
extern s32 D_002021F4;
extern s32 D_002021F8;
extern s32 D_004A3290[];
extern s32 D_004A3294[];
extern f32 D_004A3298[];
extern BF D_004A329C[];
extern u8 D_004A32A0[];

void func_0019DA70(Menu *m) {
    s32 sel = D_004A3290[0];
    s32 v;

    if (m->state != 0x16) {
        return;
    }
    if (m->buttons & 0x10) {
        sel--;
    } else if (m->buttons & 0x40) {
        sel++;
    } else if (m->buttons & 0x2000) {
        if (D_002021F8 > 0) {
            v = D_00201D68[sel];
            if (v == 2 || v == 0x50) {
                func_001C9BA0();
                D_004A3298[0] = 15.0f;
                D_002021E0 = 0;
                D_004A329C[0].b0 = 0;
                D_004A3294[0] = 2;
                D_002021E8 = 1;
                memset(D_004A32A0, 0, 0x10);
                if (D_00201D68[D_004A3290[0]] == 0x50) {
                    D_002021EC = 0x14;
                    D_002021F0 = 0x14;
                } else {
                    D_002021EC = 5;
                    D_002021F0 = 5;
                }
            } else {
                func_001CAEF0(v);
                func_0019DCF0();
                m->next = 0x12;
                m->buttons = 0;
                m->state = 0x1A;
                func_0017F7C0(1, 0, 0);
                func_0012F6E0(1);
                func_0012C260();
            }
            func_00131600(0x67, m->pad_e);
        }
    } else if (m->buttons & 0x4000) {
        func_00131600(0x69, m->pad_e);
        m->next = 0x14;
        m->buttons = 0;
        m->state = 0x1A;
        func_0017F7C0(1, 0, 0);
        return;
    }
    if (sel < 0) {
        if (D_002021F8 > 0) {
            sel = D_002021F8 - 1;
        } else {
            sel = 0;
        }
    }
    if (sel >= D_002021F8) {
        sel = 0;
    }
    if (func_0017F470(1, 0, D_004A3290[0]) != 0) {
        if (D_004A3290[0] != sel) {
            func_00131600(0x66, m->pad_e);
        }
        D_004A3290[0] = sel;
        D_002021F4 = 0;
    }
}
