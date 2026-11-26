#include "m2c.h"
typedef union { u32 w; u8 b[4]; } C;
typedef struct { u8 pad[6]; u8 x6; u8 pad7[0x89]; } E;
typedef struct { u8 x0; u8 x1; u8 x2; u8 x3; u8 x4; u8 x5; } Q;
void func_001875C0(s8 *, s32, u32, f32, f32, f32);
f32 func_0018B110(void);
s8 *func_00195B10(s32);
s8 *func_0019D510(u16);
void sprintf(s8 *, s8 *, ...);
void strcpy(s8 *, s8 *);
E *func_001AFC90(void);
Q *func_001A97D0(s16);
Q *func_001CC3F0(s16);
void func_00182EF0(s32, s32, s32, s32, f32, f32, f32);
extern u16 D_004A3310[];
extern s16 D_004A3312[];
extern s8 D_001FD6A0[];
extern s8 D_001FD6A8[];

void func_0019FA00(void) {
    C c;
    s8 buf[0x100];
    s32 id;
    E *e;
    s16 v;

    c.w = 0x80808080;
    c.b[3] = (s32)func_0018B110();
    func_001875C0(func_0019D510(D_004A3310[0]), 1, *(u32 *)&c, 330.0f, 140.0f, 1.1f);
    sprintf(buf, func_00195B10(0x96));
    func_001875C0(buf, 0, *(u32 *)&c, 250.0f, 170.0f, 1.0f);
    sprintf(buf, D_001FD6A0, (s16)func_001A97D0(D_004A3310[0])->x2);
    func_001875C0(buf, 0, *(u32 *)&c, 330.0f, 170.0f, 1.0f);
    sprintf(buf, func_00195B10(0x98));
    func_001875C0(buf, 0, *(u32 *)&c, 250.0f, 200.0f, 1.0f);
    sprintf(buf, D_001FD6A0, func_001CC3F0(D_004A3310[0])->x2);
    func_001875C0(buf, 0, *(u32 *)&c, 330.0f, 200.0f, 1.0f);
    sprintf(buf, func_00195B10(0x97));
    func_001875C0(buf, 0, *(u32 *)&c, 220.0f, 230.0f, 1.0f);
    sprintf(buf, D_001FD6A0, D_004A3312[0]);
    func_001875C0(buf, 0, *(u32 *)&c, 300.0f, 230.0f, 1.0f);
    id = D_004A3310[0];
    e = func_001AFC90();
    if (func_001A97D0(id)->x5 == 2) {
        v = 5;
    } else {
        v = e[id].x6;
    }
    sprintf(buf, D_001FD6A8, D_004A3312[0] * v);
    func_001875C0(buf, 0, *(u32 *)&c, 355.0f, 230.0f, 1.0f);
    func_00182EF0(0xB4, 0xE6, 0x1B8, 0xE6, 0.0f, 0.0f, func_0018B110());
    strcpy(buf, func_00195B10(0x9B));
    func_001875C0(buf, 1, *(u32 *)&c, 320.0f, 260.0f, 1.0f);
}
