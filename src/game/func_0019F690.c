#include "m2c.h"
typedef struct { u8 b[256]; } Buf;
typedef union { s32 w; u8 b[4]; } Col;
typedef struct { u8 pad[2]; u8 x2; } Ent;
f32 func_0018B110(void);
s8 *func_0019D510(s32);
void func_001875C0(s8 *, s32, s32, f32, f32, f32);
s8 *func_00195B10(s32);
void func_001256E0(s8 *, s8 *, ...);
void func_00125CE8(s8 *, s8 *);
Ent *func_001CC3F0(s32);
void func_00182EF0(s32, s32, s32, s32, f32, f32, f32);
extern s8 D_001FD6A0[];
extern s16 D_004A3310[];
extern s16 D_004A3312[];

void func_0019F690(void) {
    Buf buf = {0};
    Col col;

    col.w = 0x80808080;
    col.b[3] = (s32)func_0018B110();
    func_001875C0(func_0019D510((u16)D_004A3310[0]), 1, col.w, 320.0f, 160.0f, 1.1f);
    func_001256E0((s8 *)&buf, func_00195B10(0x98));
    func_001875C0((s8 *)&buf, 0, col.w, 250.0f, 190.0f, 1.0f);
    func_001256E0((s8 *)&buf, D_001FD6A0, func_001CC3F0(D_004A3310[0])->x2);
    func_001875C0((s8 *)&buf, 0, col.w, 330.0f, 190.0f, 1.0f);
    func_001256E0((s8 *)&buf, func_00195B10(0x9A));
    func_001875C0((s8 *)&buf, 0, col.w, 250.0f, 220.0f, 1.0f);
    func_001256E0((s8 *)&buf, D_001FD6A0, D_004A3312[0]);
    func_001875C0((s8 *)&buf, 0, col.w, 330.0f, 220.0f, 1.0f);
    func_00182EF0(200, 220, 400, 220, 0.0f, 0.0f, func_0018B110());
    func_00125CE8((s8 *)&buf, func_00195B10(0x9B));
    func_001875C0((s8 *)&buf, 1, col.w, 320.0f, 250.0f, 1.0f);
}
