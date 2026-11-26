#include "common.h"
typedef union { u128 q; u32 w[4]; } Q;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; u8 c0:1; u8 c1:7; } F;
typedef struct { u8 pad[0x28]; u8 t:3; u8 r:5; } Tex;
typedef struct {
    u8 pad[0x18]; s16 x, y, z; u8 pad1E[6];
    u32 g0:1; u32 g1:1; u32 g2:1; u32 g3:1; u32 A:2; u32 B:2; u32 C:2; u32 D:2; u32 fix:8; u32 rest:12;
    u64 x28; u64 x30; Tex *x38;
} A2;
typedef struct { u8 pad[0x24]; u8 g0:4; u8 g4:1; u8 g5:3; } A1;
typedef struct { u8 pad[0x10]; s32 x10; u8 pad14[0x18]; s32 x2C; u8 pad30[0xC]; u8 g0:4; u8 g4:1; u8 g5:3; } A0;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; } BF;
extern BF D_00222A50[];
extern BF D_00222A51[];
extern A2 D_00222790[];
extern s8 D_001FB8F8[];
extern s32 D_00201FF0;
extern Q *func_00154A80(s32);
extern void func_00154A70(void);
extern void func_001543E0(s32, u64);
extern void func_00154420(void);
extern void func_001545D0(void);
extern Tex *func_00177AF0(u64, s32);
extern Tex *func_00177B20(u64);
extern void func_00176B10(Tex *);
extern s32 func_00163FF0(u32, s32, Vec *);

void func_0016F440(A0 *a0, A1 *a1, A2 *a2, s32 a3, F *f) {
    Q tag1;
    Vec p;
    Q tag2;
    union { u64 d; u32 w[2]; u8 b[8]; } n;
    union { u32 w; u8 b[4]; } m;
    Q *q;

    if (D_00222A51[0].b6) {
        a2 = D_00222790;
    }
    if (f->b7) {
        f->b2 = 1;
        f->b3 = 0;
        f->b6 = 0;
    }
    if (!D_00222A50[0].b2) {
        q = func_00154A80(1);
        tag1.q = 0;
        tag1.w[1] = (u32)((s8 *)a2 + a3);
        tag1.w[0] = 0x30000002;
        tag1.w[3] = 0x6D040054;
        q->q = tag1.q;
        func_00154A70();
    } else {
        q = func_00154A80(1);
        tag2.q = 0;
        tag2.w[1] = (u32)((s8 *)a2 + a3);
        tag2.w[0] = 0x30000001;
        tag2.w[3] = 0x6D020054;
        q->q = tag2.q;
        func_00154A70();
    }
    f->b1 = 0;
    f->b0 = a2->g1;
    if (f->b7) {
        func_001545D0();
        func_001543E0(0x42, 0x44);
        func_00154420();
    } else {
        f->b2 = a2->g2;
        if (f->b2) {
            func_001545D0();
            func_001543E0(0x42, (u64)a2->A | ((u64)a2->B << 2) | ((u64)a2->C << 4) | ((u64)a2->D << 6) | ((u64)a2->fix << 32));
            func_00154420();
        }
    }
    if (f->b6) {
        func_001545D0();
        func_001543E0(0x42, 0x44);
        func_00154420();
    }
    if (a1->g4) {
        f->b5 = 0;
        if (a2->x28 != (u64)-1) {
            if (a2->x38 == 0) {
                if (a0->x2C) {
                    a2->x38 = func_00177AF0(a2->x28, a0->x2C);
                }
                if (a2->x38 == 0 && a0->g4) {
                    a2->x38 = func_00177AF0(a2->x28, a0->x10);
                }
                if (a2->x38 == 0) {
                    a2->x38 = func_00177B20(a2->x28);
                }
            }
            if (a2->x38) {
                func_00176B10(a2->x38);
                if (a2->x38->t == 3) {
                    a2->x38 = 0;
                }
                f->b1 = 1;
            }
        }
        if (!f->c0) {
            if (a2->x30 != (u64)-1) {
                n.d = a2->x30;
                if (n.w[0] == (D_001FB8F8[0] | (D_001FB8F8[1] << 8) | (D_001FB8F8[2] << 16) | (D_001FB8F8[3] << 24))) {
                    p.x = 0.000244140625f * a2->x;
                    p.y = 0.000244140625f * a2->y;
                    p.z = 0.000244140625f * a2->z;
                    p.w = 0.0f;
                    m.b[3] = n.b[4] - '0';
                    m.b[2] = n.b[5] - '0';
                    m.b[1] = n.b[6] - '0';
                    m.b[0] = n.b[7] - '0';
                    if (func_00163FF0(m.w, D_00201FF0, &p)) {
                        f->b5 = 1;
                    }
                }
            }
        }
    }
    if (f->b3 != a2->g3) {
        f->b3 = a2->g3;
        func_001545D0();
        func_001543E0(0x49, f->b3);
        func_00154420();
    }
}
