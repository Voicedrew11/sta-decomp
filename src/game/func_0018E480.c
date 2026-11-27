#include "common.h"
#include "m2c.h"
#include "actor.h"
typedef struct { s32 x0; s32 x4; u8 pad[0x38]; } E_func_0018E480;
typedef struct { u32 n; E_func_0018E480 *arr; } L;
typedef struct { s32 x0; L *x4; L *x8; L *xC; } R;
typedef struct { u8 r, g, b, a; } Col_func_0018E480;
typedef union { u128 q; f32 f[4]; } Q;
typedef struct { s32 idx; u8 pad[0x3C]; } Item;
typedef struct { u32 n; Item *items; } List;
typedef struct { s32 pad; List *list; } Res;
typedef struct { u8 b0:1; u8 b1:1; u8 r:6; } F_func_0018EAE0;
typedef struct { u8 b0:1; u8 r:7; } G;
typedef struct { s32 x0; s32 x4; s8 x8; u8 p9[3]; s8 xC; u8 pD[7]; G x14; } O_func_0018EAE0;
typedef struct {
    s32 x0;
    s32 x4;
    u8 x8;
    u8 pad9;
    u8 xA;
    u8 xB;
    u8 padC[2];
    u8 xE;
} Obj18EC40;
typedef struct { s32 x0; s32 x4; u8 x8; u8 pad9; u8 xA; u8 padB[3]; u8 xE; } Obj;
typedef union { u128 q[2]; s32 w[8]; f32 f[8]; void *p[8]; } Q2_func_0018F940;
typedef struct { s32 *p; s32 n; f32 f; void *fn; void *a; s32 b; void *cb; } Arg_func_0018F940;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 r:2; } F_func_0018F940;
typedef struct { s32 x0; s32 x4; s8 x8; u8 p9; s8 xA; u8 pB; s8 xC; u8 xD; u8 xE; } O_func_0018F940;
typedef struct { u8 pad0[0x10]; s32 x10; u8 pad14[0x14]; f32 x28; } Info;
typedef union { u128 q[2]; s32 w[8]; f32 f[8]; void *p[8]; } Q2_func_0018FFE0;
typedef struct { s32 *p; s32 n; f32 f; void *fn; s32 a; s32 b; void *cb; } Arg_func_0018FFE0;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 r:2; } F_func_0018FFE0;
typedef struct { s32 x0; s32 x4; s8 x8; u8 p9; s8 xA; u8 pB; s8 xC; } O_func_0018FFE0;
typedef union { u128 q[2]; s32 w[8]; void *p[8]; } Q2_func_00190340;
typedef struct { s32 *p; s32 n; f32 f; void *fn; s32 a; s32 b; void *cb; } Arg_func_00190340;
typedef union { u128 q[2]; s32 w[8]; void *p[8]; f32 f[8]; } Q2_func_00190490;
typedef struct { void *p; s32 n; f32 f; void *fn; void *cb; s32 a; s32 b; } Arg_func_00190490;
typedef struct { f32 m[4]; f32 x; f32 y; } S_func_001907D0;
typedef union { u32 w; u8 b[4]; } Col_func_001907D0;
typedef union {
    u32 w;
    struct { u8 r, g, b, a; } c;
} Col_func_00190A50;
typedef struct {
    u64 a, b;
    f32 x, y;
} S_func_00190A50;
typedef struct {
    f32 v0[4];
    f32 v10[4];
    u8 pad20[8];
    s32 x28;
    Col_func_00190A50 x2C;
    f32 x30, x34, x38, x3C;
} A_func_00190A50;
typedef struct {
    s32 x0;
    s32 x4;
    u8 pad8[8];
    f32 v10[4];
    f32 v20[4];
} E_func_00190A50;
typedef struct {
    u8 pad0[0x84];
    E_func_00190A50 *x84;
    u8 pad88[0xC];
    E_func_00190A50 *x94;
} P;
typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
} B;
typedef union {
    u32 w;
    struct { u8 r, g, b, a; } c;
} Col_func_00190DC0;
typedef struct {
    u64 a, b;
    f32 x, y;
} S191110;
typedef struct {
    f32 v0[4];
    f32 v10[4];
    u8 pad20[8];
    s32 x28;
    Col_func_00190DC0 x2C;
    f32 x30, x34, x38, x3C;
} A191110_func_00190DC0;
typedef struct {
    s32 x0;
    s32 x4;
    u8 pad8[8];
    f32 v10[4];
    f32 v20[4];
} E191110;
typedef struct {
    u8 pad0[0x84];
    E191110 *x84;
    u8 pad88[0xC];
    E191110 *x94;
} P191110;
typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
} B191110;
typedef union {
    u32 w;
    struct { u8 r, g, b, a; } c;
} Col_func_00191110;
typedef struct {
    f32 v0[4];
    f32 v10[4];
    u8 pad20[8];
    s32 x28;
    Col_func_00191110 x2C;
    f32 x30, x34, x38, x3C;
} A191110_func_00191110;
typedef union {
    u32 w;
    f32 f;
    struct { u8 r, g, b, a; } c;
} Col_func_00191420;
typedef struct {
    u64 a, b;
    f32 x, y;
} S_func_00191420;
typedef struct {
    f32 v0[4];
    f32 v10[4];
    u8 pad20[8];
    s32 x28;
    Col_func_00191420 x2C;
    f32 x30, x34, x38, x3C;
} A_func_00191420;
typedef union {
    u32 w;
    struct { u8 r, g, b, a; } c;
} Col_func_00191580;
typedef struct {
    Vec v0;
    Vec v10;
    u8 pad20[8];
    s32 x28;
    Col_func_00191580 x2C;
    f32 x30, x34, x38, x3C;
} A191110_func_00191580;
extern s32 D_004A10D4[];
extern s32 D_004A10D0[];
extern s32 D_004A10E0[];
extern s32 D_004A10E4[];
extern s32 D_004A10E8[];
extern f32 D_00201D1C;
extern s32 D_00202130;
extern Q D_001F2D80[];
extern Q D_001F2D90[];
extern s32 D_0020212C;
extern u8 D_0020212F;
extern f32 D_004A10D8[];
extern F_func_0018EAE0 D_004A10DC[];
extern u8 D_004A1075[];
extern s32 D_00202128;
extern s32 D_004A10C0[];
extern s32 D_004A10C4[];
extern s32 D_004A10C8[];
extern u8 D_004A1073[];
extern u8 D_004A1077[];
extern u8 D_004A1070[];
extern u8 D_004A1072[];
extern u8 D_004A1078[];
extern u8 D_004A1071[];
extern u8 D_004A1074[];
extern Q2_func_0018F940 D_001F2D10;
extern s32 D_001F2D00[];
extern f32 D_001F2AC0[];
extern s32 D_004A1080[];
extern s32 D_004A1084[];
extern s32 D_004A1088[];
extern s32 D_004A108C[];
extern f32 D_004A10B0[];
extern Q2_func_0018FFE0 D_001F2CE0;
extern s32 D_001F2CD0[];
extern f32 D_001F2A90[];
extern Q2_func_00190340 D_001F2D60;
extern f32 D_001F2B00[];
extern s32 D_00201D10;
extern s32 D_00201D18;
extern Q2_func_00190490 D_001F2D40;
extern s32 D_001F2D30[];
extern f32 D_001F2B20[];
extern s32 D_00201D08;
extern s32 D_00201CF8[2];
extern s32 D_001F2B70[];
extern s32 D_001F2B60[];
extern u8 D_001FCE08[];
extern u8 D_001FCE18[];
extern u8 D_001FCE30[];
extern u8 D_001FCE50[];
extern S_func_001907D0 D_001F2CB0[] __attribute__((aligned(16)));
extern s32 D_001F2BB0[];
extern s8 D_001FCFE8[][13];
extern s32 D_00201D00[2];
extern s32 D_001F2B90[];
extern S_func_00190A50 D_001F2C90 __attribute__((aligned(16)));
extern s32 D_001F2B80[];
extern S191110 D_001F2C70 __attribute__((aligned(16)));
extern s32 D_001F2B50[];
extern S191110 D_001F2C50 __attribute__((aligned(16)));
extern S_func_00191420 D_001F2C30 __attribute__((aligned(16)));
extern S191110 D_001F2C10 __attribute__((aligned(16)));
extern s8 D_001FD118[];
extern s8 D_001FD120[];
void func_0018E480(void);
void func_0018E980(u8 *arg0);
void func_0018EAE0(O_func_0018EAE0 *arg0);
void func_0018EC40(Obj18EC40 *o);
void func_0018EDA0(Obj *o);
void func_0018F0D0(Obj *o);
void func_0018F490(Obj *o);
void func_0018F940(O_func_0018F940 *a0);
void func_0018FFE0(O_func_0018FFE0 *p);
void func_00190340(void);
void func_00190490(void);
s32 func_001905E0(s32 x);
s32 func_00190630(s32 x);
s32 func_00190680(s32 x);
s32 func_001906D0(s32 x);
s32 func_00190720(s32 x);
s32 func_00190770(s32 x);
void func_001907D0(s8 *o, s32 unused, u32 id, s8 *p);
void func_00190A50(A_func_00190A50 *o, s32 unused, u32 kind, B *b);
void func_00190DC0(A191110_func_00190DC0 *o, s32 unused, u32 kind, B191110 *b);
void func_00191110(A191110_func_00191110 *o, s32 unused, u32 kind, B191110 *b);
void func_00191420(A_func_00191420 *o, s32 unused, u32 kind, B *b);
void func_00191580(A191110_func_00191580 *o, u32 kind, s32 alpha);
void func_0018A310(s32);
void func_0017F5C0(void);
void func_0017F0D0(s32, s32, s32, s32);
R* func_00189050(s32);
s8* func_00189020(s32);
void func_00182C10(E_func_0018E480 *, s8 *);
s8* func_00195B10(s32);
void func_001875C0(f32, f32, f32, s8 *, s32, u32);
void func_00185390(s32, s32, s32, f32);
void func_00187B20(s32);
void func_001829B0(Item *, s32, void *, s32);
void func_00182080(s32, f32, Q *, Q *, void *, s32);
void func_00181420(void);
void func_001DCF80(void);
s8 func_00189EA0(void);
void func_0017F7C0(s32, s32, s32);
s32 func_0017F470(s32 arg0, s32 arg1, f32 val);
void func_00131600(s32, u8);
void func_0012C320(void);
void func_0012C720(s32);
void func_0012C6B0(void);
s32 func_0017F3D0(s32);
s32 func_0012C1B0(void);
void func_0012C730(s32);
void func_0012DA60(s32);
void func_0017F890(s32, void *, void *);
void func_0017F840(s32, Info **);
void func_0018B320(s32 *);
void func_0012C6C0(s32);
void func_001304B0(s32);
void func_0018B150(f32, s32 *, s32, s32, void (*)(), s32);
f32 sinf(f32);
void func_00130440(void);
void func_00191820(void);
void func_00191C40(void);
u32 strlen(s32);
void func_00181680(s32, void *, void *, void *, void *, s32);
void func_001874F0(f32, f32, f32, s32, s32, s32, u32);
void func_001545D0(void);
void func_001543E0(s32, s64);
void func_001544C0(void);
void sprintf(s8 *, s8 *, ...);

/* func_0018E480 */
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
            Col_func_0018E480 col;
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
                E_func_0018E480 *e = &l->arr[i];
                if (e->x4 == 0x1005) {
                    func_00182C10(e, q + e->x0 * 8);
                }
            }
        }
        if (D_004A10D4[0] != 5) {
            Col_func_0018E480 col;
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
                E_func_0018E480 *e = &l->arr[i];
                if (e->x4 == 0x1068) {
                    func_00182C10(e, q + e->x0 * 8);
                }
            }
        }
        if (D_004A10D4[0] != 5) {
            Col_func_0018E480 col;
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
                E_func_0018E480 *e = &l->arr[i];
                if (e->x4 == 0x1068) {
                    func_00182C10(e, q + e->x0 * 8);
                }
            }
        }
        if (D_004A10D4[0] != 5) {
            Col_func_0018E480 col;
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

/* func_0018E980 */
#define func_00189050 func_00189050__as_func_0018E980
Res *func_00189050__as_func_0018E980(s32);
#define func_00189020 func_00189020__as_func_0018E980
s32 func_00189020__as_func_0018E980(s32);

void func_0018E980(u8 *arg0) {
    Q a;
    Q b;
    u32 i;
    List *l;
    s32 base;

    a = D_001F2D80[0];
    b = D_001F2D90[0];
    if (D_00202130 != 0) {
        l = func_00189050(3)->list;
        base = func_00189020(3);
        for (i = 0; i < l->n; i++) {
            func_001829B0(&l->items[i], base + l->items[i].idx * 8, func_001DCF80, 0);
        }
        func_00187B20(0);
        if (arg0[8] == 6) {
            if (D_0020212F < 0xC) {
                D_0020212F = 0;
            } else {
                D_0020212F -= 0xC;
            }
        } else {
            D_0020212F += 0xC;
            if (D_0020212F > 0x60) {
                D_0020212F = 0x60;
            }
        }
        func_00182080(0, 0.0f, &a, &b, &D_0020212C, 0);
        func_00181420();
    }
}
#undef func_00189050
#undef func_00189020

/* func_0018EAE0 */
#define func_0018FFE0 func_0018FFE0__as_func_0018EAE0
void func_0018FFE0__as_func_0018EAE0(O_func_0018EAE0 *);
#define func_0018F940 func_0018F940__as_func_0018EAE0
void func_0018F940__as_func_0018EAE0(O_func_0018EAE0 *);
#define func_0018F490 func_0018F490__as_func_0018EAE0
void func_0018F490__as_func_0018EAE0(O_func_0018EAE0 *);
#define func_0018F0D0 func_0018F0D0__as_func_0018EAE0
void func_0018F0D0__as_func_0018EAE0(O_func_0018EAE0 *);
#define func_0018EDA0 func_0018EDA0__as_func_0018EAE0
void func_0018EDA0__as_func_0018EAE0(O_func_0018EAE0 *);
#define func_0018EC40 func_0018EC40__as_func_0018EAE0
void func_0018EC40__as_func_0018EAE0(O_func_0018EAE0 *);

void func_0018EAE0(O_func_0018EAE0 *arg0) {
    func_0018FFE0(arg0);
    if (arg0->x0 == 0x16) {
        switch (D_004A10D4[0]) {
        case 0:
            if (D_00202130 != 0) {
                arg0->xC = 4;
            } else {
                arg0->xC = 0;
            }
            func_0018F940(arg0);
            break;
        case 1:
            arg0->xC = 1;
            func_0018F490(arg0);
            break;
        case 2:
            arg0->xC = 2;
            func_0018F0D0(arg0);
            break;
        case 3:
            arg0->xC = 3;
            func_0018EDA0(arg0);
            break;
        case 4:
            func_0018EC40(arg0);
            break;
        case 5:
            if (!(D_004A10D8[0] <= 12.0f)) {
                if (D_004A10DC[0].b1) {
                    arg0->x14.b0 = 1;
                } else {
                    arg0->x8 = func_00189EA0();
                    arg0->x4 = 0;
                    arg0->x0 = 0x1A;
                }
                func_0017F7C0(0xD, 0, 0);
            }
            break;
        }
    }
}
#undef func_0018FFE0
#undef func_0018F940
#undef func_0018F490
#undef func_0018F0D0
#undef func_0018EDA0
#undef func_0018EC40

/* func_0018EC40 */
#define D_004A10DC D_004A10DC__as_func_0018EC40
extern Flags8 D_004A10DC__as_func_0018EC40[];

void func_0018EC40(Obj18EC40 *o) {
    s32 fl;
    s32 v;
    func_0017F470(0xD, 0, D_004A10D0[0]);
    if (D_004A10D8[0] <= 10.0f) return;
    fl = o->x4;
    if (fl & 0x2000) {
        func_0012C320();
        func_00131600(0x69, o->xE);
        o->xA = 2;
        o->xB = 0;
        D_004A10D4[0] = 5;
        D_004A10D8[0] = 0;
        D_004A10DC[0].f.b1 = 1;
        if (D_004A10DC[0].f.b4) {
            v = D_004A1075[0] * 2;
            if (v > 0x7F) v = 0x7F;
            func_0012C720(v);
            func_0012C6B0();
        } else {
            func_0012C720(0x7F);
        }
    } else if (fl & 0x4000) {
        func_00131600(0x68, o->xE);
        o->xA = 2;
        o->xB = 0;
        D_00202128 = 2;
        D_004A10D4[0] = 0;
    }
    func_0017F470(0xD, 0, D_004A10D0[0]);
}
#undef D_004A10DC

/* func_0018EDA0 */
void func_0018EDA0(Obj *o) {
    s32 cur;
    u32 old;
    s32 b;

    cur = D_004A10E8[0];
    old = cur;
    func_0017F470(0xD, 0, D_004A10D0[0]);
    if (D_004A10D8[0] > 20.0f) {
        func_0017F7C0(0xB, 1, 0);
        func_0017F7C0(0xC, 1, 0);
    } else {
        return;
    }
    if (func_0017F3D0(0xB)) {
        b = o->x4;
        switch (D_004A10E8[0]) {
        case 0:
            if (b & 0x20) {
                D_004A1073[0] = !D_004A1073[0];
                func_00131600(0x6A, o->xE);
            }
            if (o->x4 & 0x80) {
                D_004A1073[0] = !D_004A1073[0];
                func_00131600(0x6A, o->xE);
            }
            break;
        case 1:
            if (b & 0x20) {
                if (D_004A1077[0] < 5) {
                    D_004A1077[0]++;
                } else {
                    D_004A1077[0] = 0;
                }
                func_00131600(0x6A, o->xE);
            }
            if (o->x4 & 0x80) {
                if (D_004A1077[0] > 0) {
                    D_004A1077[0]--;
                } else {
                    D_004A1077[0] = 5;
                }
                func_00131600(0x6A, o->xE);
            }
            break;
        }
    }
    if (o->x4 & 0x4000) {
        if (func_0017F470(0xB, 1, -4.0f) && func_0017F470(0xC, 1, 0.0f)) {
            func_00131600(0x68, o->xE);
            D_004A10D4[0] = 0;
            D_00202128 = 2;
            return;
        }
    }
    b = o->x4;
    if (b & 0x10) {
        D_004A10C0[0] = 0;
        cur--;
        D_004A10C8[0] = 0;
        D_004A10C4[0] = 0;
        o->x4 &= ~0x10;
    } else if (b & 0x40) {
        D_004A10C0[0] = 0;
        cur++;
        D_004A10C8[0] = 0;
        D_004A10C4[0] = 0;
        o->x4 &= ~0x40;
    }
    if (!func_0017F470(0xB, 0, D_004A10E8[0])) {
        D_004A10E8[0] = old;
        return;
    }
    if (D_004A10E8[0] != cur) {
        func_00131600(0x66, o->xE);
    }
    D_004A10E8[0] = (cur + 2) % 2;
    func_0017F470(0xC, 0, D_004A10E8[0]);
}

/* func_0018F0D0 */
void func_0018F0D0(Obj *o) {
    s32 cur;
    u32 old;
    s32 b;

    cur = D_004A10E4[0];
    old = cur;
    func_0017F470(0xD, 0, D_004A10D0[0]);
    if (D_004A10D8[0] > 20.0f) {
        func_0017F7C0(0xB, 1, 0);
        func_0017F7C0(0xC, 1, 0);
    } else {
        return;
    }
    if (func_0017F3D0(0xB)) {
        switch (D_004A10E4[0]) {
        case 0:
            if (o->x4 & 0x20) {
                D_004A1078[0] = !D_004A1078[0];
                func_00131600(0x6A, o->xE);
            }
            if (o->x4 & 0x80) {
                D_004A1078[0] = !D_004A1078[0];
                func_00131600(0x6A, o->xE);
            }
            break;
        case 1:
            if (o->x4 & 0x20) {
                if (D_004A1072[0] < 2) {
                    D_004A1072[0]++;
                } else {
                    D_004A1072[0] = 0;
                }
                func_00131600(0x6A, o->xE);
            }
            if (o->x4 & 0x80) {
                if (D_004A1072[0] > 0) {
                    D_004A1072[0]--;
                } else {
                    D_004A1072[0] = 2;
                }
                func_00131600(0x6A, o->xE);
            }
            break;
        case 2:
            if ((o->x4 & 0x20) && D_004A1070[0] < 0x40) {
                func_00131600(0x6A, o->xE);
                D_004A1070[0]++;
            }
            if ((o->x4 & 0x80) && D_004A1070[0] > 0) {
                func_00131600(0x6A, o->xE);
                D_004A1070[0]--;
            }
            break;
        }
    }
    if (o->x4 & 0x4000) {
        if (func_0017F470(0xB, 1, -4.0f) && func_0017F470(0xC, 1, 1.0f)) {
            func_00131600(0x68, o->xE);
            D_004A10D4[0] = 0;
            D_00202128 = 2;
            return;
        }
    }
    b = o->x4;
    if (b & 0x10) {
        D_004A10C0[0] = 0;
        cur--;
        D_004A10C8[0] = 0;
        D_004A10C4[0] = 0;
        o->x4 &= ~0x10;
    } else if (b & 0x40) {
        D_004A10C0[0] = 0;
        cur++;
        D_004A10C8[0] = 0;
        D_004A10C4[0] = 0;
        o->x4 &= ~0x40;
    }
    if (!func_0017F470(0xB, 0, D_004A10E4[0])) {
        D_004A10E4[0] = old;
        return;
    }
    if (D_004A10E4[0] != cur) {
        func_00131600(0x66, o->xE);
    }
    D_004A10E4[0] = (cur + 3) % 3;
    func_0017F470(0xC, 0, D_004A10E4[0]);
}

/* func_0018F490 */
#define D_004A10DC D_004A10DC__as_func_0018F490
extern Flags8 D_004A10DC__as_func_0018F490[];

void func_0018F490(Obj *o) {
    s32 cur;
    u32 old;
    s32 b;
    s32 v;

    cur = D_004A10E0[0];
    old = cur;
    func_0017F470(0xD, 0, D_004A10D0[0]);
    if (D_004A10D8[0] <= 20.0f) {
        return;
    }
    if (D_004A10DC[0].f.b5) {
        if (func_0012C1B0()) {
            func_0017F7C0(0xB, 1, 0);
            func_0017F470(0xB, 0, D_004A10E0[0]);
            return;
        }
        D_004A10DC[0].f.b5 = 0;
    }
    if (func_0017F3D0(0xB)) {
        switch (D_004A10E0[0]) {
        case 0:
            if (o->x4 & 0x20) {
                D_004A1071[0]++;
                func_00131600(0x6A, o->xE);
            }
            if (o->x4 & 0x80) {
                if (D_004A1071[0] > 0) {
                    D_004A1071[0]--;
                } else {
                    D_004A1071[0] = 2;
                }
                func_00131600(0x6A, o->xE);
            }
            D_004A1071[0] = D_004A1071[0] % 3u;
            switch (D_004A1071[0]) {
            case 0:
                func_0012DA60(0);
                break;
            case 1:
                func_0012DA60(1);
                break;
            case 2:
                func_0012DA60(2);
                break;
            }
            break;
        case 1:
            if ((o->x4 & 0x20) && D_004A1074[0] < 0x40) {
                func_00131600(0x6A, o->xE);
                D_004A1074[0]++;
            }
            if ((o->x4 & 0x80) && D_004A1074[0] > 0) {
                func_00131600(0x6A, o->xE);
                D_004A1074[0]--;
            }
            v = D_004A1074[0] * 2;
            if (v > 0x7F) {
                v = 0x7F;
            }
            func_0012C730(v);
            break;
        case 2:
            if ((o->x4 & 0x20) && D_004A1075[0] < 0x40) {
                func_00131600(0x6A, o->xE);
                D_004A1075[0]++;
            }
            if ((o->x4 & 0x80) && D_004A1075[0] > 0) {
                func_00131600(0x6A, o->xE);
                D_004A1075[0]--;
            }
            v = D_004A1075[0] * 2;
            if (v > 0x7F) {
                v = 0x7F;
            }
            func_0012C720(v);
            break;
        }
    }
    if (o->x4 & 0x4000) {
        if (func_0017F470(0xB, 1, -4.0f)) {
            func_00131600(0x68, o->xE);
            D_004A10D4[0] = 0;
            D_00202128 = 2;
            return;
        }
    }
    b = o->x4;
    if (b & 0x10) {
        D_004A10C0[0] = 0;
        cur--;
        D_004A10C8[0] = 0;
        D_004A10C4[0] = 0;
        o->x4 &= ~0x10;
    } else if (b & 0x40) {
        D_004A10C0[0] = 0;
        cur++;
        D_004A10C8[0] = 0;
        D_004A10C4[0] = 0;
        o->x4 &= ~0x40;
    }
    if (!func_0017F470(0xB, 0, D_004A10E0[0])) {
        D_004A10E0[0] = old;
        return;
    }
    if (cur != D_004A10E0[0]) {
        func_00131600(0x66, o->xE);
    }
    D_004A10E0[0] = (cur + 3) % 3;
}
#undef D_004A10DC

/* func_0018F940 */
#define func_0017F890 func_0017F890__as_func_0018F940
void func_0017F890__as_func_0018F940(s32, Q2_func_0018F940 *, Arg_func_0018F940 *);
#define func_0017F470 func_0017F470__as_func_0018F940
s32 func_0017F470__as_func_0018F940(f32, s32, s32);
#define func_00190720 func_00190720__as_func_0018F940
void func_00190720__as_func_0018F940(void);
#define func_00190630 func_00190630__as_func_0018F940
void func_00190630__as_func_0018F940(void);
/* .bss, from the top down (CodeWarrior writes it in reverse) */
f32 D_004A1090[0x8];
#define D_004A10DC D_004A10DC__as_func_0018F940
extern F_func_0018F940 D_004A10DC__as_func_0018F940[];
static inline void fill(void) {
    Info *p;
    s32 i;
    s32 n;
    func_0017F840(13, &p);
    n = p->x10;
    for (i = 0; i < n; i++) {
        D_004A10B0[i] = p->x28 - i;
    }
}

void func_0018F940(O_func_0018F940 *a0) {
    s32 cur;
    s32 nxt;
    s32 flags;
    s32 v;
    Q2_func_0018F940 q;
    Arg_func_0018F940 a;

    D_004A1088[0] = 0;
    D_004A1080[0] = 0x2B;
    D_004A1084[0] = 3;
    D_004A1090[0] = 1.0f;
    D_004A108C[0] = 0;
    cur = D_004A10D0[0];
    nxt = cur;
    if (!D_004A10DC[0].b3) {
        flags = a0->x4;
        if (flags & 0x2000) {
            func_00131600(0x67, a0->xE);
            switch (D_004A10D0[0]) {
            case 0:
                D_004A10D4[0] = 1;
                D_004A10E0[0] = 0;
                q = D_001F2D10;
                a.p = D_001F2D00;
                a.n = 3;
                a.fn = func_00190720;
                a.a = func_00190630;
                a.b = 0;
                a.cb = 0;
                a.f = D_001F2AC0[0];
                func_0017F890(11, &q, &a);
                func_0017F470(0.0f, 11, 0);
                func_0017F7C0(11, 0, 0);
                D_004A10DC[0].b4 = 1;
                D_004A10DC[0].b5 = 1;
                v = D_004A1075[0] * 2;
                if (v > 0x7F) v = 0x7F;
                func_0012C6C0(0x7F);
                func_0012C720(v);
                break;
            case 1:
                D_004A10D4[0] = 2;
                D_004A10E4[0] = 0;
                func_00190490();
                break;
            case 2:
                D_004A10D4[0] = 3;
                D_004A10E8[0] = 0;
                func_00190340();
                break;
            case 3:
                D_004A10D4[0] = 4;
                func_0018B320(D_004A1080);
                a0->xA = 1;
                break;
            }
            D_004A10D8[0] = 0.0f;
            if (D_00202128 == 0) fill();
            D_00202128 = 1;
            return;
        } else if (flags & 0x4000) {
            func_00131600(0x69, a0->xE);
            D_004A10D8[0] = 0.0f;
            D_004A10D4[0] = 5;
            if (D_00202128 == 0) fill();
            D_00202128 = 3;
            func_0017F7C0(13, 0, 1);
            func_001304B0(-0x666);
            if (D_004A10DC[0].b4) {
                v = D_004A1075[0] * 2;
                if (v > 0x7F) v = 0x7F;
                func_0012C720(v);
                func_0012C6B0();
            } else {
                func_0012C720(0x7F);
            }
            return;
        } else if (flags & 0x10) {
            if (D_00202128 == 0) {
                nxt = cur - 1;
                a0->x4 = flags & ~0x10;
            }
        } else if (flags & 0x40) {
            if (D_00202128 == 0) {
                nxt = cur + 1;
                a0->x4 = flags & ~0x40;
            }
        }
    }
    if (!func_0017F470(*(volatile s32 *)D_004A10D0, 13, 0)) {
        D_004A10D0[0] = cur;
        return;
    }
    if (nxt != D_004A10D0[0]) func_00131600(0x66, a0->xE);
    v = 4 - D_00202130;
    D_004A10D0[0] = (nxt + v) % v;
}
#undef func_0017F890
#undef func_0017F470
#undef func_00190720
#undef func_00190630
#undef D_004A10DC

/* func_0018FFE0 */
#define func_0017F890 func_0017F890__as_func_0018FFE0
void func_0017F890__as_func_0018FFE0(s32, Q2_func_0018FFE0 *, Arg_func_0018FFE0 *);
#define func_0017F470 func_0017F470__as_func_0018FFE0
void func_0017F470__as_func_0018FFE0(f32, s32, s32);
#define func_00190770 func_00190770__as_func_0018FFE0
void func_00190770__as_func_0018FFE0(void);
#define D_004A10C4 D_004A10C4__as_func_0018FFE0
extern f32 D_004A10C4__as_func_0018FFE0[];
#define D_004A10C8 D_004A10C8__as_func_0018FFE0
extern f32 D_004A10C8__as_func_0018FFE0[];
#define D_004A10DC D_004A10DC__as_func_0018FFE0
extern F_func_0018FFE0 D_004A10DC__as_func_0018FFE0[];

void func_0018FFE0(O_func_0018FFE0 *p) {
    Q2_func_0018FFE0 q;
    Arg_func_0018FFE0 a;

    switch (p->x0) {
    case 0x19:
        D_004A10D8[0] = 0.0f;
        D_004A10D4[0] = 0;
        D_004A10D0[0] = 1;
        D_004A10C0[0] = 0;
        D_004A10C8[0] = 0.0f;
        D_004A10C4[0] = 0.0f;
        D_004A10DC[0].b2 = 0;
        D_004A10DC[0].b1 = 0;
        D_004A10DC[0].b4 = 0;
        D_004A10DC[0].b5 = 1;
        D_00202128 = 0;
        q = D_001F2CE0;
        q.f[5] = D_001F2A90[0];
        a.p = D_001F2CD0;
        a.n = 4 - D_00202130;
        a.fn = func_00190770;
        a.f = D_001F2A90[0];
        a.a = 0;
        a.b = 0;
        a.cb = func_00191820;
        func_0017F890(13, &q, &a);
        func_0017F470(0.0f, 13, 0);
        func_0017F7C0(13, 0, 1);
        if (D_00202130) {
            func_0018B150(1.0f, D_004A1080, 0x2C, 2, func_00191C40, 0);
            func_0018B320(D_004A1080);
            D_004A10DC[0].b3 = 1;
            p->xA = 1;
        }
        if (D_00202130) {
            p->xC = 4;
        } else {
            p->xC = 0;
        }
        break;
    case 0x1B:
        break;
    case 0:
        func_0017F7C0(13, 1, 1);
        break;
    case 0x16:
        break;
    case 0x1A:
        break;
    case 0x1C:
        break;
    case 0x1E:
        func_00130440();
        break;
    }
    D_004A10D8[0] += 1.0f;
    D_004A10C0[0] += 5;
    D_004A10C0[0] %= 180;
    D_004A10C4[0] = 10.0f * sinf(3.1415927f * D_004A10C0[0] / 180.0f);
    D_004A10C8[0] = -10.0f * sinf(3.1415927f * D_004A10C0[0] / 180.0f);
}
#undef func_0017F890
#undef func_0017F470
#undef func_00190770
#undef D_004A10C4
#undef D_004A10C8
#undef D_004A10DC

/* func_00190340 */
#define func_0017F890 func_0017F890__as_func_00190340
void func_0017F890__as_func_00190340(s32, Q2_func_00190340 *, Arg_func_00190340 *);
#define func_0017F470 func_0017F470__as_func_00190340
void func_0017F470__as_func_00190340(f32, s32, s32);
#define func_00190680 func_00190680__as_func_00190340
void func_00190680__as_func_00190340(void);
#define func_001907D0 func_001907D0__as_func_00190340
void func_001907D0__as_func_00190340(void);

void func_00190340(void) {
    Q2_func_00190340 q;
    Arg_func_00190340 a;

    q = D_001F2D60;
    a.p = &D_00201D10;
    a.n = 2;
    a.fn = func_00190680;
    a.f = D_001F2AC0[0];
    a.a = 0;
    a.b = 0;
    a.cb = 0;
    func_0017F890(11, &q, &a);
    func_0017F470(0.0f, 11, 0);
    func_0017F7C0(11, 0, 0);
    q.w[5] = 0;
    q.p[7] = func_001907D0;
    q.w[2] = 8;
    q.p[3] = D_001F2B00;
    q.w[4] = 4;
    a.p = &D_00201D18;
    a.n = 1;
    a.fn = 0;
    a.f = D_001F2B00[0];
    a.a = 0;
    func_0017F890(12, &q, &a);
    func_0017F470(1.0f, 12, 0);
    func_0017F7C0(12, 0, 0);
}
#undef func_0017F890
#undef func_0017F470
#undef func_00190680
#undef func_001907D0

/* func_00190490 */
#define func_0017F890 func_0017F890__as_func_00190490
void func_0017F890__as_func_00190490(s32, Q2_func_00190490 *, Arg_func_00190490 *);
#define func_0017F470 func_0017F470__as_func_00190490
void func_0017F470__as_func_00190490(f32, s32, s32);
#define func_001906D0 func_001906D0__as_func_00190490
void func_001906D0__as_func_00190490(void);
#define func_001905E0 func_001905E0__as_func_00190490
void func_001905E0__as_func_00190490(void);

void func_00190490(void) {
    Q2_func_00190490 q;
    Arg_func_00190490 a;

    q = D_001F2D40;
    a.p = D_001F2D30;
    a.n = 3;
    a.fn = func_001906D0;
    a.f = D_001F2AC0[0];
    a.cb = func_001905E0;
    a.a = 0;
    a.b = 0;
    func_0017F890(11, &q, &a);
    func_0017F470(0.0f, 11, 0);
    func_0017F7C0(11, 0, 0);
    q.w[2] = 8;
    q.f[5] = 1.0f;
    q.p[3] = D_001F2B20;
    q.w[4] = 4;
    a.p = &D_00201D08;
    a.n = 1;
    a.fn = 0;
    a.f = D_001F2B20[0];
    a.cb = 0;
    func_0017F890(12, &q, &a);
    func_0017F470(1.0f, 12, 0);
    func_0017F7C0(12, 0, 0);
}
#undef func_0017F890
#undef func_0017F470
#undef func_001906D0
#undef func_001905E0

/* func_001905E0 */
s32 func_001905E0(s32 x)
{
    switch (x) {
    case 0:
    case 1:
        return 4;
    case 2:
        return 0;
    }
    return 0;
}

/* func_00190630 */
s32 func_00190630(s32 x)
{
    switch (x) {
    case 0:
        return 0;
    case 1:
    case 2:
        return 8;
    }
    return 0;
}

/* func_00190680 */
s32 func_00190680(s32 x)
{
    switch (x) {
    case 0:
    case 1:
        return D_00201CF8[x];
    }
    return 0;
}

/* func_001906D0 */
s32 func_001906D0(s32 x)
{
    switch (x) {
    case 0:
    case 1:
    case 2:
        return D_001F2B70[x];
    }
    return 0;
}

/* func_00190720 */
s32 func_00190720(s32 x)
{
    switch (x) {
    case 0:
    case 1:
    case 2:
        return D_001F2B60[x];
    }
    return 0;
}

/* func_00190770 */
#pragma explicit_zero_data on
s32 D_001F2B40[0x4] = { (s32)D_001FCE08, (s32)D_001FCE18, (s32)D_001FCE30, (s32)D_001FCE50 };

s32 func_00190770(s32 x)
{
    switch (x) {
    case 0:
    case 1:
    case 2:
    case 3:
        return D_001F2B40[x];
    }
    return 0;
}

/* func_001907D0 */
#define func_00181680 func_00181680__as_func_001907D0
void func_00181680__as_func_001907D0(s32, s8 *, s8 *, void *, S_func_001907D0 *, s32);
#define func_001875C0 func_001875C0__as_func_001907D0
void func_001875C0__as_func_001907D0(f32, f32, f32, s32, s32, u32);

void func_001907D0(s8 *o, s32 unused, u32 id, s8 *p) {
    S_func_001907D0 t __attribute__((aligned(16)));
    Col_func_001907D0 col;
    s32 k;
    s32 dx;
    s32 *str;
    f32 sc;
    s32 on;

    on = *(s32 *)(p + 8);
    t = D_001F2CB0[0];
    if (on != 0) {
        if (id < 200) {
            t.x = *(f32 *)(o + 0x30);
            t.y = *(f32 *)(o + 0x34);
            func_00181680(*(s32 *)(o + 0x28), o, o + 0x10, o + 0x2C, &t, 0);
        } else if (id == 301) {
            if (D_004A1077[0] == 0 || D_004A1077[0] == 1) {
                t.x = *(f32 *)(o + 0x30);
                t.y = *(f32 *)(o + 0x34);
                func_00181680(*(s32 *)(o + 0x28), o, o + 0x10, o + 0x2C, &t, 0);
            }
        } else if (id == 300) {
            if ((u32)(D_004A1077[0] - 2) <= 2 || D_004A1077[0] == 5) {
                t.x = *(f32 *)(o + 0x30);
                t.y = *(f32 *)(o + 0x34);
                func_00181680(*(s32 *)(o + 0x28), o, o + 0x10, o + 0x2C, &t, 0);
            }
        } else {
            k = D_001FCFE8[D_004A1077[0]][id];
            dx = -2;
            if (k == 16) {
                sc = 0.95f;
            } else {
                sc = 1.0f;
            }
            col.w = 0x80808080;
            col.b[3] = *(u8 *)(o + 0x2F) * 2;
            *(f32 *)(o + 0x3C) += 1.0f;
            str = &D_001F2BB0[k];
            if (strlen(*str) > 8) {
                if (k == 1) {
                    dx = -3;
                }
                if (k == 4 || k == 5) {
                    dx = -7;
                }
                func_001874F0(*(f32 *)(o + 0x38), *(f32 *)(o + 0x3C), sc, dx, *str, 1, col.w);
            } else {
                func_001875C0(*(f32 *)(o + 0x38), *(f32 *)(o + 0x3C), 1.0f, *str, 1, col.w);
            }
        }
    }
}
#undef func_00181680
#undef func_001875C0

/* func_00190A50 */
#define func_00181680 func_00181680__as_func_00190A50
void func_00181680__as_func_00190A50(s32, f32 *, f32 *, Col_func_00190A50 *, S_func_00190A50 *, s32);
#define func_00189020 func_00189020__as_func_00190A50
P *func_00189020__as_func_00190A50(s32);
#define func_001875C0 func_001875C0__as_func_00190A50
void func_001875C0__as_func_00190A50(f32, s32, f32, f32, u32, u32);
#define D_004A10C4 D_004A10C4__as_func_00190A50
extern f32 D_004A10C4__as_func_00190A50[];
#define D_004A10C8 D_004A10C8__as_func_00190A50
extern f32 D_004A10C8__as_func_00190A50[];

void func_00190A50(A_func_00190A50 *o, s32 unused, u32 kind, B *b) {
    Col_func_00190A50 col;
    S_func_00190A50 s __attribute__((aligned(16)));
    s32 h;
    s32 r;
    E_func_00190A50 *e;

    h = b->x8;
    s = D_001F2C90;
    col.c.r = col.c.g = col.c.b = 0x80;
    col.c.a = 0x40;
    if (h != 0) {
        if (kind < 0xC8) {
            s.x = o->x30;
            s.y = o->x34;
            col = o->x2C;
            func_00181680(o->x28, o->v0, o->v10, &col, &s, 0);
            return;
        }
        r = func_0017F3D0(0xB);
        switch (kind) {
        case 0xC8:
            if (b->x4 == 0xFA4) {
                e = func_00189020(0)->x94;
                s.x = o->x38;
                s.y = o->x3C;
                func_00181680(e->x4, e->v10, e->v20, &o->x2C, &s, 0);
            }
            break;
        case 0xC9:
            col.w = 0x80808080;
            col.c.a = o->x2C.c.a * 2;
            func_001875C0(o->x38, h, o->x3C, 0.83333331f, 0, col.w);
            break;
        case 0xCA:
            col.w = 0x80808080;
            col.c.a = o->x2C.c.a * 2;
            if (b->x0 == 0) {
                func_001875C0(o->x38, D_00201D00[!D_004A1073[0]], o->x3C, 0.83333331f, 1, col.w);
            } else if (b->x0 == 1) {
                func_001875C0(o->x38, D_001F2B90[D_004A1077[0]], o->x3C, 0.83333331f, 1, col.w);
            }
            break;
        case 0xCB:
            if (r != 0 && b->x4 == 0xFA4) {
                e = &func_00189020(0)->x84[1];
                s.x = o->x38 + D_004A10C8[0];
                s.y = o->x3C;
                func_00181680(e->x4, e->v10, e->v20, &col, &s, 1);
            }
            break;
        case 0xCC:
            if (r != 0 && b->x4 == 0xFA4) {
                e = func_00189020(0)->x84;
                s.x = o->x38 + D_004A10C4[0];
                s.y = o->x3C;
                func_00181680(e->x4, e->v10, e->v20, &col, &s, 1);
            }
            break;
        case 0x190:
            s.x = o->x30;
            s.y = o->x34;
            func_00181680(o->x28, o->v0, o->v10, &o->x2C, &s, 0);
            break;
        }
    }
}
#undef func_00181680
#undef func_00189020
#undef func_001875C0
#undef D_004A10C4
#undef D_004A10C8

/* func_00190DC0 */
#define func_00181680 func_00181680__as_func_00190DC0
void func_00181680__as_func_00190DC0(s32, f32 *, f32 *, Col_func_00190DC0 *, S191110 *, s32);
#define func_00189020 func_00189020__as_func_00190DC0
P191110 *func_00189020__as_func_00190DC0(s32);
#define func_001875C0 func_001875C0__as_func_00190DC0
void func_001875C0__as_func_00190DC0(f32, s32, f32, f32, u32, u32);
#define func_00191580 func_00191580__as_func_00190DC0
void func_00191580__as_func_00190DC0(A191110_func_00190DC0 *, u32, s32);
#define D_004A10C4 D_004A10C4__as_func_00190DC0
extern f32 D_004A10C4__as_func_00190DC0[];
#define D_004A10C8 D_004A10C8__as_func_00190DC0
extern f32 D_004A10C8__as_func_00190DC0[];

void func_00190DC0(A191110_func_00190DC0 *o, s32 unused, u32 kind, B191110 *b) {
    Col_func_00190DC0 col;
    S191110 s __attribute__((aligned(16)));
    s32 h;
    s32 alpha;
    s32 r;
    E191110 *e;

    h = b->x8;
    s = D_001F2C70;
    alpha = 0x40;
    col.c.r = col.c.g = col.c.b = 0x80;
    col.c.a = alpha;
    if (h != 0) {
        if (kind < 0xC8) {
            s.x = o->x30;
            s.y = o->x34;
            func_00181680(o->x28, o->v0, o->v10, &o->x2C, &s, 0);
            return;
        }
        if (b->x0 == 2) {
            alpha = D_004A1070[0];
        }
        r = func_0017F3D0(0xB);
        switch (kind) {
        case 0xC8:
            if (b->x4 == 0xFA4) {
                e = func_00189020(0)->x94;
                s.x = o->x38;
                s.y = o->x3C;
                func_00181680(e->x4, e->v10, e->v20, &o->x2C, &s, 0);
            }
            break;
        case 0xC9:
            col.w = 0x80808080;
            col.c.a = o->x2C.c.a * 2;
            func_001875C0(o->x38, h, o->x3C, 0.83333331f, 0, col.w);
            break;
        case 0xCA:
            col.w = 0x80808080;
            col.c.a = o->x2C.c.a * 2;
            if (b->x0 == 0) {
                func_001875C0(o->x38, D_00201D00[!D_004A1078[0]], o->x3C, 0.83333331f, 1, col.w);
            } else if (b->x0 == 1) {
                func_001875C0(o->x38, D_001F2B80[D_004A1072[0]], o->x3C, 0.83333331f, 1, col.w);
            }
            break;
        case 0xCB:
            if (r != 0 && b->x4 == 0xFA4) {
                e = &func_00189020(0)->x84[1];
                s.x = o->x38 + D_004A10C8[0];
                s.y = o->x3C;
                func_00181680(e->x4, e->v10, e->v20, &col, &s, 1);
            }
            break;
        case 0xCC:
            if (r != 0 && b->x4 == 0xFA4) {
                e = func_00189020(0)->x84;
                s.x = o->x38 + D_004A10C4[0];
                s.y = o->x3C;
                func_00181680(e->x4, e->v10, e->v20, &col, &s, 1);
            }
            break;
        }
        func_00191580(o, kind, alpha);
    }
}
#undef func_00181680
#undef func_00189020
#undef func_001875C0
#undef func_00191580
#undef D_004A10C4
#undef D_004A10C8

/* func_00191110 */
#define func_00181680 func_00181680__as_func_00191110
void func_00181680__as_func_00191110(s32, f32 *, f32 *, Col_func_00191110 *, S191110 *, s32);
#define func_00189020 func_00189020__as_func_00191110
P191110 *func_00189020__as_func_00191110(s32);
#define func_001875C0 func_001875C0__as_func_00191110
void func_001875C0__as_func_00191110(f32, s32, f32, f32, u32, u32);
#define func_00191580 func_00191580__as_func_00191110
void func_00191580__as_func_00191110(A191110_func_00191110 *, u32, s32);
#define D_004A10C4 D_004A10C4__as_func_00191110
extern f32 D_004A10C4__as_func_00191110[];
#define D_004A10C8 D_004A10C8__as_func_00191110
extern f32 D_004A10C8__as_func_00191110[];

void func_00191110(A191110_func_00191110 *o, s32 unused, u32 kind, B191110 *b) {
    Col_func_00191110 col;
    S191110 s __attribute__((aligned(16)));
    s32 h;
    s32 alpha;
    s32 r;
    E191110 *e;

    h = b->x8;
    s = D_001F2C50;
    alpha = 0x40;
    col.c.r = col.c.g = col.c.b = 0x80;
    col.c.a = alpha;
    if (h != 0) {
        if (kind < 0xC8) {
            s.x = o->x30;
            s.y = o->x34;
            func_00181680(o->x28, o->v0, o->v10, &o->x2C, &s, 0);
            return;
        }
        if (b->x0 == 1) {
            alpha = D_004A1074[0];
        }
        if (b->x0 == 2) {
            alpha = D_004A1075[0];
        }
        r = func_0017F3D0(0xB);
        switch (kind) {
        case 0xC8:
            if (b->x4 == 0xFA4) {
                e = func_00189020(0)->x94;
                s.x = o->x38;
                s.y = o->x3C;
                func_00181680(e->x4, e->v10, e->v20, &o->x2C, &s, 0);
            }
            break;
        case 0xC9:
            col.w = 0x80808080;
            col.c.a = o->x2C.c.a * 2;
            func_001875C0(o->x38, h, o->x3C, 0.83333331f, 0, col.w);
            break;
        case 0xCA:
            col.w = 0x80808080;
            col.c.a = o->x2C.c.a * 2;
            func_001875C0(o->x38, D_001F2B50[D_004A1071[0]], o->x3C, 0.83333331f, 1, col.w);
            break;
        case 0xCB:
            if (r != 0 && b->x4 == 0xFA4) {
                e = &func_00189020(0)->x84[1];
                s.x = o->x38 + D_004A10C8[0];
                s.y = o->x3C;
                func_00181680(e->x4, e->v10, e->v20, &col, &s, 1);
            }
            break;
        case 0xCC:
            if (r != 0 && b->x4 == 0xFA4) {
                e = func_00189020(0)->x84;
                s.x = o->x38 + D_004A10C4[0];
                s.y = o->x3C;
                func_00181680(e->x4, e->v10, e->v20, &col, &s, 1);
            }
            break;
        }
        func_00191580(o, kind, alpha);
    }
}
#undef func_00181680
#undef func_00189020
#undef func_001875C0
#undef func_00191580
#undef D_004A10C4
#undef D_004A10C8

/* func_00191420 */
#define func_00181680 func_00181680__as_func_00191420
void func_00181680__as_func_00191420(s32, f32 *, f32 *, Col_func_00191420 *, S_func_00191420 *, u32);
#define func_001875C0 func_001875C0__as_func_00191420
void func_001875C0__as_func_00191420(f32, s32, f32, f32, u32, u32);

void func_00191420(A_func_00191420 *o, s32 unused, u32 kind, B *b) {
    S_func_00191420 s __attribute__((aligned(16)));
    Col_func_00191420 col;
    s32 h;

    h = b->x8;
    s = D_001F2C30;
    if (h == 0) return;
    if (kind < 200) {
        s.x = o->x30;
        s.y = o->x34;
        col = o->x2C;
        if (D_004A10D4[0] != 0 && b->x4 == 0xFA2) {
            col.c.r = col.c.g = col.c.b = 0x40;
        }
        func_00181680(o->x28, o->v0, o->v10, &col, &s, kind);
        return;
    }
    switch (kind) {
    case 200:
        col.w = 0x80808080;
        col.c.a = o->x2C.c.a * 2;
        o->x3C += 4.0f;
        if (strlen(h) < 16) {
            o->x3C += 9.0f;
        }
        func_001875C0(o->x38, h, o->x3C, 0.83333331f, 0, col.w);
        break;
    }
}
#undef func_00181680
#undef func_001875C0

/* func_00191580 */
#define func_00181680 func_00181680__as_func_00191580
void func_00181680__as_func_00191580(s32, Vec *, Vec *, Col_func_00191580 *, S191110 *, s32);
#define func_001874F0 func_001874F0__as_func_00191580
void func_001874F0__as_func_00191580(f32, f32, f32, s32, s8 *, s32, u32);

void func_00191580(A191110_func_00191580 *o, u32 kind, s32 alpha) {
    Col_func_00191580 col;
    S191110 s __attribute__((aligned(16)));
    Vec v10;
    Vec v0;
    s8 buf[0x400];
    f32 f;

    s = D_001F2C10;
    switch (kind) {
    case 0xCD:
        col.c.b = 0x40;
        col.c.r = 0x40;
        col.c.a = 0x40;
        f = 0.015625f * alpha;
        col.c.g = 0x60;
        func_00187B20(0);
        func_00181420();
        func_001545D0();
        func_001543E0(0x42, 0x48);
        func_001544C0();
        s.x = o->x30;
        s.y = o->x34;
        v10 = o->v10;
        v0 = o->v0;
        o->v10.z = o->v10.z * f;
        o->v0.z = v0.x + f * (v0.z - v0.x);
        func_00181680(o->x28, &o->v0, &o->v10, &col, &s, 0);
        o->v10 = v10;
        o->v0 = v0;
        func_00187B20(0);
        func_00181420();
        func_001545D0();
        func_001543E0(0x42, 0x44);
        func_001544C0();
        break;
    case 0xCE:
        s.x = o->x30;
        s.y = o->x34;
        func_00181680(o->x28, &o->v0, &o->v10, &o->x2C, &s, 0);
        break;
    case 0xCF:
        col.c.r = 0x80 - alpha;
        col.c.g = alpha + 0x80;
        col.c.b = alpha + 0x80;
        col.c.a = o->x2C.c.a * 2;
        if (alpha < 0x40) {
            sprintf(buf, D_001FD118);
        } else {
            sprintf(buf, D_001FD120);
        }
        func_001874F0(o->x38, o->x3C, 0.83333331f, -1, buf, 0, col.w);
        func_00187B20(0);
        break;
    }
}
#undef func_00181680
#undef func_001874F0
