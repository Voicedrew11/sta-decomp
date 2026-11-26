#include "actor.h"
typedef struct { u8 pad[0x20]; f32 x20; } O18;
typedef struct {
    u8 pad[0x18];
    O18 *x18;
    u8 pad1C[0x50 - 0x1C];
    Vec x50;
    u8 pad60[0x374 - 0x60];
    f32 f374;
    u8 pad378[0x37C - 0x378];
    f32 f37C;
    u8 pad380[0x394 - 0x380];
    s8 x394;
    s8 x395;
    u8 pad396[0x39C - 0x396];
    u32 b39C:8;
    u32 b8:6;
    u32 m:4;
    u32 n:4;
    u32 o:6;
    u32 r:4;
    Flags8 f3A0;
    Flags8 f3A1;
    union { u8 b; struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:2; u8 b7:1; } f; } f3A2;
    u8 pad3A3[0x3AD - 0x3A3];
    u8 x3AD;
    u8 x3AE;
    u8 x3AF;
    u8 pad3B0[0x3BE - 0x3B0];
    u8 x3BE;
    u8 pad3BF[0x3CC - 0x3BF];
    s8 x3CC;
    s8 x3CD;
    s8 x3CE;
    s8 x3CF;
    f32 f3D0;
    u8 x3D4;
    u8 x3D5;
    Flags8 f3D6;
    u8 pad3D7[0x3F0 - 0x3D7];
    Vec x3F0;
    u8 x400[0x41E - 0x400];
    u16 x41E;
    s8 x420;
    s8 x421;
    u16 x422;
    u8 pad424[0x430 - 0x424];
    f32 f430;
    f32 f434;
    f32 f438;
    f32 f43C;
    f32 f440;
    f32 f444;
} S;
extern Flags8 D_00222A53[];
extern Flags8 D_00222A52[];
extern s8 D_00222A11[];
extern Vec D_003139A0;
typedef struct { u8 pad[0x78]; s32 x78; u8 p7c[0x518-0x7C]; s8 *unk518; } AH;
#define Actor AH
void sceVu0CopyVector(Vec *, Vec *);
void sceVu0AddVector(Vec *, Vec *, Vec *);
void memset(void *, s32, s32);
void func_001C7020(u16, f32, s32, f32, f32);
f32 func_0015DF90(f32, f32, f32);
void func_0012C110(s32);
s32 func_001BFB70(Actor *);
f32 func_0011DA18(f32);
s32 func_0012C020(void);
void func_001CE2D0(void);
void func_001CDF80(void);
void func_001CEBA0(void);
void func_001CD6C0(void);
s32 func_001CD980(s8 *, s8 *);
void func_001C9FF0(void);
void func_001CEDC0(s32);
void func_001CEA50(s32);
void func_001C4760(Actor *, u8 *);
void func_001C89E0(u8 *, f32);
void func_001C3EF0(Actor *, u8 *, f32);
void func_001C39D0(Actor *, u8 *, f32);
void func_001C34F0(Actor *, u8 *);
void func_001C2DB0(Actor *, u8 *);
void func_001C27C0(Actor *, u8 *);
void func_001C1900(Actor *, u8 *);
void func_001C0A10(Actor *, u8 *);
void func_001C0E60(Actor *, u8 *);
void func_001BF940(Actor *);
s8 *func_001715B0(s32);
s32 func_001BD350(s32);
void func_001CE4B0(S *);
void func_001CE370(S *);
s32 func_001D1E00(u8);
s32 func_001D1D50(u8);
void func_0019A840(void);
static inline f32 u2f(u32 x) { return x; }
static inline void reset(void) {
    S *p;
    s8 *base;
    if (D_002022E4 == NULL) {
        p = NULL;
    } else if ((base = D_002022E4->unk518) == NULL) {
        p = NULL;
    } else {
        p = (S *)(base + 0x180);
    }
    if (p != NULL) {
        func_001C7020(0, 0.0f, 0, 0.0f, 1.0f);
        p->x3CC = 0;
        p->x3CD = 0;
        p->x3CE = 0;
        p->x3CF = 0;
        p->x3D5 = 0;
        p->x3D4 = 0;
        p->f3D6.f.b5 = 0;
    }
}
static inline S *cur(void) {
    if (D_002022E4 == 0) return 0;
    if (D_002022E4->unk518 == 0) return 0;
    return (S *)(D_002022E4->unk518 + 0x180);
}
static inline s32 mode(void) {
    S *p = cur();
    if (p == 0) return 0;
    return p->m;
}
static inline s32 flag1(void) {
    S *p = cur();
    if (p == 0) return 0;
    return p->f3D6.f.b1;
}

void func_001BEFA0(AH *a0, f32 dt) {
    S *q;
    S *s;
    s32 o394;
    s8 *t;
    s32 i;
    s32 o395;
    u8 buf[0x38];
    s32 v;

    s = (S *)(a0->unk518 + 0x180);
    o394 = s->x394;
    o395 = s->x395;
    s->f3A1.f.b5 = 0;
    s->f3A2.f.b3 = 0;
    s->x3AD = 0;
    s->x3AE = 0;
    if (D_00222A53[0].f.b4 && s->f3A2.f.b4) {
        q = (S *)(a0->unk518 + 0x180);
        sceVu0CopyVector(&q->x50, &D_003139A0);
        q->x50.y -= 3920.0f * dt;
        reset();
        q->x18->x20 = func_0015DF90(q->x18->x20, 1.5707964f, (u2f(q->x41E) / 90.0f) * (u2f(q->x41E) / 90.0f));
        if (q->x41E > 0x2D) {
            func_0012C110(0x28);
        } else {
            q->x41E++;
        }
        return;
    }
    func_001BFB70(a0);
    q = cur();
    if (q != 0) {
        if (q->f444 <= 0.0f) {
            q->f430 = q->f434 = 0.0f;
        } else {
            q->f430 = q->f438 * func_0011DA18(q->f444);
            q->f434 = q->f43C * func_0011DA18(q->f444);
            q->f438 = q->f438 * q->f440;
            q->f43C = q->f43C * q->f440;
            q->f444 -= 1.0f;
        }
    }
    if (!func_0012C020() && !mode()) {
        func_001CE2D0();
        func_001CDF80();
        func_001CEBA0();
        func_001CD6C0();
    }
    s->x420 = -1;
    s->x421 = -1;
    if (func_001CD980(&s->x420, &s->x421)) {
        s->x422++;
    } else {
        s->x422 = 0;
    }
    func_001C9FF0();
    func_001CEDC0(3);
    func_001CEA50(0);
    memset(buf, 0, 0x38);
    if (!func_0012C020()) {
        if (!D_00222A52[0].f.b2 || D_00222A11[0] != 0) {
            func_001C4760(a0, buf);
        }
    }
    if (s->x3AF < 0x2D) {
        memset(buf, 0, 0x38);
        s->x3AF++;
    }
    if (s->f3A2.f.b1) {
        func_001C89E0(s->x400, s->f37C);
    }
    if (!func_0012C020() && !mode()) {
        if (s->o) {
            func_001C3EF0(a0, buf, dt);
        } else if (s->f3A0.f.b0) {
            func_001C39D0(a0, buf, dt);
        } else if (!s->f3A2.f.b0) {
            func_001C34F0(a0, buf);
        } else {
            func_001C2DB0(a0, buf);
        }
        func_001C27C0(a0, buf);
        func_001C1900(a0, buf);
    } else {
        sceVu0CopyVector(&s->x50, &D_003139A0);
        s->x50.y -= 3920.0f * dt;
    }
    if (s->x18->x20 < -1.0471976f) {
        s->x18->x20 = -1.0471976f;
    }
    if (!(s->x18->x20 <= 0.6108653f)) {
        s->x18->x20 = 0.6108653f;
    }
    if (s->m || s->n) {
        func_001C0A10(a0, buf);
    } else {
        func_001C0E60(a0, buf);
    }
    func_001BF940(a0);
    if (a0 != 0 && (((Flags8 *)a0)[0x5A0].b & 1) && ((Flags8 *)a0)[0x5A0].f.b2) {
        t = func_001715B0(*(s32 *)(a0->unk518 + 0xB0));
        for (i = 0; i < a0->x78; i++) {
            ((Flags8 *)(t + (i + 1) * 0x140))[0x1F8].f.b3 = !func_001BD350(i);
        }
    }
    if (!func_0012C020() && !mode()) {
        if (s->x3CF != 1) {
            func_001CE4B0(s);
        }
        func_001CE370(s);
        if (!(s->f374 <= 0.0f)) {
            s->f374 -= 1.0f;
        }
    }
    if (s->x3D4 && func_001D1E00(s->b39C) && !flag1()) {
        s->f3D0 = s->f3D0 + 0.1f * (0.17453294f - s->f3D0);
    } else {
        s->f3D0 = s->f3D0 + 0.1f * -s->f3D0;
    }
    if (!func_0012C020() && !mode()) {
        sceVu0AddVector(&s->x50, &s->x50, &s->x3F0);
    }
    sceVu0CopyVector(&s->x3F0, &D_003139A0);
    if (s->x3BE) {
        s->x3BE--;
    }
    s->f3A1.f.b6 = 0;
    if (func_001D1D50(s->b39C)) {
        v = func_001D1E00(s->b39C) ? 2 : 1;
    } else {
        v = 0;
    }
    s->f3A2.f.b5 = v;
    if (o394 != s->x394 || o395 != s->x395) {
        func_0019A840();
    }
}
