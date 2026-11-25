#include "actor.h"
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; } Bits;
typedef struct {
    u8 pad[0x40];
    u16 x40;
    u16 x42;
    u8 x44;
    u8 x45;
    u8 x46;
    u8 x47;
    u8 x48;
    u8 x49;
    u8 pad4A[0xC];
    u8 x56;
    u8 x57;
    u8 pad58[0x38];
} E;
typedef struct {
    u16 h[6];
    u8 padC[4];
    s32 w[6];
    u8 pad28[9];
    Bits f31;
    u8 pad32[0xE];
} D;
typedef struct { u8 pad[6]; s16 x6; } Q;
typedef struct {
    u8 pad[0x18];
    f32 *p18;
    u8 pad1C[0x374 - 0x1C];
    f32 x374;
    s8 *x378;
    u8 pad37C[0x14];
    Q *x390;
    u8 pad394[3];
    s8 x397;
    u8 pad398[2];
    s16 x39A;
    u8 pad39C[6];
    Bits f3A2;
    u8 pad3A3[0x46A - 0x3A3];
    u16 x46A;
    u8 pad46C[4];
    u16 x470[6];
} P;
E *func_001AFC90(void);
s32 func_001CCD90(s32);
s8 *func_00169B50(s32, s32, s32, s32);
void func_001CC450(u16);
void func_00102A70(Mtx *, Mtx *);
void func_00102C20(Mtx *, Mtx *, f32);
void func_00102CC8(Mtx *, Mtx *, f32);
void func_00102A60(void *, void *);
void func_001677C0(s8 *, Mtx *);
void func_00167600(s8 *, Actor *);
void func_00123C40(void *, s32, s32);
void func_001672B0(s8 *, D *);
extern Mtx D_001F2170;
static inline f32 u2f(u32 x) { return x; }

void func_001C0020(Actor *a) {
    D d;
    Mtx m;
    P *p;
    E *tbl;
    s32 i;
    s32 j;
    u16 *c;

    p = (P *)(a->unk518 + 0x180);
    tbl = func_001AFC90();
    j = i = (s16)func_001CCD90(6);
    if (i != -1 && p->x397 > 0) {
    c = &tbl[j].x42;
    if (*c <= p->x390->x6 && p->x374 <= 0.0f) {
    p->x378 = func_00169B50(tbl[j].x40, 0, 0, 0);
    if (p->x378 != NULL) {
    func_001CC450(p->x46A);
    p->x390->x6 -= *c;
    p->x397--;
    p->x39A = 0;
    p->x374 = u2f(tbl[i].x56);
    func_00102A70(&m, &D_001F2170);
    func_00102C20(&m, &m, WRAP(-WRAP(p->p18[8])));
    func_00102CC8(&m, &m, WRAP(WRAP(p->p18[9])));
    func_00102A60(&m.m[3], p->p18);
    m.m[3].w = 1.0f;
    func_001677C0(p->x378, &m);
    func_00167600(p->x378, a);
    func_00123C40(&d, 0, 0x40);
    d.h[0] = p->x470[0] / tbl[i].x57;
    d.h[1] = p->x470[1] / tbl[i].x57;
    d.h[2] = p->x470[2] / tbl[i].x57;
    d.h[3] = p->x470[3] / tbl[i].x57;
    d.h[4] = p->x470[4] / tbl[i].x57;
    d.h[5] = p->x470[5] / tbl[i].x57;
    d.w[0] = tbl[i].x44;
    d.w[1] = tbl[i].x45;
    d.w[2] = tbl[i].x46;
    d.w[3] = tbl[i].x48;
    d.w[4] = tbl[i].x47;
    d.w[5] = tbl[i].x49;
    d.f31.b1 = 1;
    func_001672B0(p->x378, &d);
    p->f3A2.b3 = 1;
    }
    }
    }
}
