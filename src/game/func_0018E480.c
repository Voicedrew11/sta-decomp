#include "common.h"
typedef struct { s32 x0; s32 x4; u8 pad[0x38]; } E;
typedef struct { u32 n; E *arr; } L;
typedef struct { s32 x0; L *x4; L *x8; L *xC; } R;
typedef struct { u8 r, g, b, a; } Col;
extern s32 D_004A10D4[];
extern s32 D_004A10D0[];
extern s32 D_004A10E0[];
extern s32 D_004A10E4[];
extern s32 D_004A10E8[];
extern f32 D_00201D1C;
extern s32 D_00202130;
void func_0018A310(s32);
void func_0017F5C0(void);
void func_0017F0D0(s32, s32, s32, s32);
R *func_00189050(s32);
s8 *func_00189020(s32);
void func_00182C10(E *, s8 *);
s8 *func_00195B10(s32);
void func_001875C0(f32, f32, f32, s8 *, s32, u32);
void func_00185390(s32, s32, s32, f32);
void func_00187B20(s32);

void func_0018E480(void) {
    if (D_004A10D4[0]) {
        D_00201D1C += 0.25f * (-1.0f - D_00201D1C);
    } else {
        D_00201D1C += 0.25f * -D_00201D1C;
    }
    if (!(D_00201D1C <= 0.0f)) {
        D_00201D1C = 0.0f;
    }
    func_0018A310(4);
    if (D_004A10D4[0] == 1 || D_004A10D4[0] == 2 || D_004A10D4[0] == 3) {
        func_0018A310(8);
    }
    func_0017F5C0();
    switch (D_004A10D4[0]) {
    case 0:
        func_0017F0D0(0, 1, 3, D_004A10E0[0]);
        func_0017F0D0(0, 1, 3, D_004A10E4[0]);
        func_0017F0D0(0, 1, 2, D_004A10E8[0]);
        if (D_004A10D4[0] != 5) {
            Col col;
            *(u32 *)&col = 0x80FFFFFF;
            func_001875C0(622.0f, 17.0f, 1.0f, func_00195B10(D_004A10D0[0] + 0x28), 2, *(u32 *)&col);
        }
        break;
    case 1: {
        u32 i;
        L *l;
        s8 *q;
        func_0017F0D0(1, 1, 3, D_004A10E0[0]);
        l = func_00189050(5)->x4;
        q = func_00189020(5);
        for (i = 0; i < l->n; i++) {
            if (l->arr) {
                E *e = &l->arr[i];
                if (e->x4 == 0x1005) {
                    func_00182C10(e, q + e->x0 * 8);
                }
            }
        }
        if (D_004A10D4[0] != 5) {
            Col col;
            *(u32 *)&col = 0x80FFFFFF;
            func_001875C0(622.0f, 17.0f, 1.0f, func_00195B10(D_004A10E0[0] + 0x32), 2, *(u32 *)&col);
        }
        break;
    }
    case 2: {
        u32 i;
        L *l;
        s8 *q;
        func_0017F0D0(1, 1, 3, D_004A10E4[0]);
        l = func_00189050(5)->xC;
        q = func_00189020(5);
        for (i = 0; i < l->n; i++) {
            if (l->arr) {
                E *e = &l->arr[i];
                if (e->x4 == 0x1068) {
                    func_00182C10(e, q + e->x0 * 8);
                }
            }
        }
        if (D_004A10D4[0] != 5) {
            Col col;
            *(u32 *)&col = 0x80FFFFFF;
            func_001875C0(622.0f, 17.0f, 1.0f, func_00195B10(D_004A10E4[0] + 0x3C), 2, *(u32 *)&col);
        }
        break;
    }
    case 3: {
        u32 i;
        L *l;
        s8 *q;
        func_0017F0D0(1, 1, 2, D_004A10E8[0]);
        l = func_00189050(5)->x8;
        q = func_00189020(5);
        for (i = 0; i < l->n; i++) {
            if (l->arr) {
                E *e = &l->arr[i];
                if (e->x4 == 0x1068) {
                    func_00182C10(e, q + e->x0 * 8);
                }
            }
        }
        if (D_004A10D4[0] != 5) {
            Col col;
            *(u32 *)&col = 0x80FFFFFF;
            func_001875C0(622.0f, 17.0f, 1.0f, func_00195B10(D_004A10E8[0] + 0x46), 2, *(u32 *)&col);
        }
        break;
    }
    case 5:
        func_0017F0D0(0, 1, 3, D_004A10E0[0]);
        func_0017F0D0(0, 1, 3, D_004A10E4[0]);
        func_0017F0D0(0, 1, 2, D_004A10E8[0]);
        break;
    }
    func_00185390(1, 4 - D_00202130, D_004A10D0[0], D_00201D1C);
    func_00187B20(0);
}
