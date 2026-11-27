#include "m2c.h"
typedef struct { s32 state; s32 buttons; u8 next; u8 pad[5]; u8 pad_e; } Menu;
typedef struct { u8 pad[0x10]; s32 count; u8 pad2[0x14]; f32 base; } Info;
void func_00131600(s32, u8);
void func_00189ED0(s32);
void func_0018E470(s32);
void func_0017F840(s32, Info **);
void func_0017F7C0(s32, s32, s32);
s32 func_0017F470(s32, s32, f32);
void func_0012F6E0(s32);
void func_0012C260(void);
extern s32 D_00202204;
extern s32 D_00202208;
/* .bss, from the top down (CodeWarrior writes it in reverse) */
f32 D_004A32B0[0x6];
extern s32 D_004A32C8[];
extern s32 D_004A32CC[];

void func_0019E400(Menu *m) {
    Info *info;
    s32 i;
    s32 n;
    s32 sel = D_004A32C8[0];

    if (m->buttons & 0x2000) {
        func_00131600(0x69, m->pad_e);
        switch (D_004A32C8[0]) {
        case 0:
            m->next = 0x15;
            break;
        case 1:
            m->next = 0x16;
            break;
        case 2:
            m->next = 0x18;
            break;
        case 3:
            m->next = 9;
            func_00189ED0(0x14);
            func_0018E470(0);
            break;
        case 4:
            m->next = 0xD;
            func_00189ED0(0x14);
            func_0018E470(0);
            break;
        }
        D_004A32CC[0] = 0;
        if (D_00202208 == 0) {
            func_0017F840(0, &info);
            n = info->count;
            for (i = 0; i < n; i++) {
                D_004A32B0[i] = info->base - (f32)i;
            }
        }
        D_00202208 = 1;
        m->buttons = 0;
        m->state = 0x1A;
        func_0017F7C0(0, 0, 0);
        D_00202204 = 0;
        return;
    }
    if (m->buttons & 0x4000) {
        m->next = 0x12;
        m->buttons = 0;
        m->state = 0x1A;
        func_0017F7C0(0, 0, 0);
        D_00202204 = 0;
        D_00202208 = 3;
        func_00131600(0x65, m->pad_e);
        func_0012F6E0(1);
        func_0012C260();
        return;
    }
    if (m->buttons & 0x10) {
        sel = D_004A32C8[0] - 1;
    } else if (m->buttons & 0x40) {
        sel = D_004A32C8[0] + 1;
    }
    if (func_0017F470(0, 0, D_004A32C8[0]) != 0) {
        if (D_004A32C8[0] != sel) {
            func_00131600(0x66, m->pad_e);
        }
        D_00202208 = 0;
        D_004A32C8[0] = (sel + 5) % 5;
    }
}
