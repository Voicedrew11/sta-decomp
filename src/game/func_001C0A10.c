#include "actor.h"
#include "obj3d.h"
#include "m2c.h"
#include "common.h"
typedef struct { s32 type; s32 a; s32 b; s32 c; f32 x, y, z, w; f32 h; f32 p; f32 r; s32 f; } Msg;
typedef struct {
    u8 pad[0x39C];
    u32 lo:13;
    u32 b13:1;
    u32 f14:4;
    u32 f18:4;
    u32 hi:10;
    u8 pad3A0[0x414 - 0x3A0];
    Obj3D *x414;
} S_func_001C0A10;
typedef struct { u8 pad[0x30]; s32 x30; } P_func_001C0A10;
typedef struct { u8 pad[0x94]; Flags8 f94; } R_func_001C0E60;
typedef struct {
    u8 pad[0x390];
    R_func_001C0E60 *x390;
    u8 pad394[0x39C - 0x394];
    u8 x39C;
    u8 pad39D;
    u16 lo : 6;
    u16 f39E : 6;
    u16 hi : 4;
    u8 pad3A0[2];
    Flags8 f3A2;
    u8 pad3A3[0x3D5 - 0x3A3];
    u8 x3D5;
    Flags8 f3D6;
} S_func_001C0E60;
typedef struct { u8 pad[0x30]; s32 x30; } Ev;
typedef struct { f32 a[4]; f32 b[4]; } Ray;
typedef struct { s32 w[9]; s32 hit; s32 pad; u8 *tri; s32 w2[4]; } Res;
typedef struct { u8 pad[0x18]; s8 *m18; u8 pad1C[0x382]; u16 lo:6; u16 f6:6; u16 b12:1; u16 f13:3; u8 m3A0[0x1F]; u8 m3BF; } P_func_001C1140;
typedef struct { f32 m[4][4]; } MtxF;
typedef struct { u8 pad[0xC]; u8 t:4; u8 r:4; u8 padD[3]; f32 x, y, z; } Tri;
typedef struct { Vec p; u8 pad10[0x14]; s32 x24; u8 pad28[4]; Tri *x2C; u8 pad30[0x10]; } Hit;
typedef struct { u8 pad[0x18]; Vec *o; u8 pad1C[0x39E - 0x1C]; u16 a:6; u16 b:6; u16 c:1; u16 d:3; f32 f3A0; f32 f3A4; } P_func_001C13B0;
typedef struct { u8 b0:1; u8 b1:1; u8 rest:6; } BFa;
typedef struct { u8 pad:3; u8 b3:1; u8 rest:4; } BFb;
typedef struct { s8 pad[0x94]; u8 b94; } S390_func_001C1900;
typedef struct { s8 pad[0xA8]; BFa a8; } SV;
typedef struct { s8 pad[0x390]; S390_func_001C1900 *p390; s8 pad2[0x39C-0x394]; u8 b39C; s8 pad3[0x3C0-0x39D]; SV *p3C0; SV *p3C4; } SS_func_001C1900;
typedef struct { u8 pad[0x94]; u8 x94; } S390_func_001C1A00;
typedef struct { u8 pad[0x20]; f32 x20; f32 x24; } O18;
typedef struct {
    u8 pad0[0x18];
    O18 *x18;
    u8 pad1C[0x390 - 0x1C];
    S390_func_001C1A00 *x390;
    s8 x394;
    u8 pad395[0x39C - 0x395];
    u8 x39C;
    u8 pad39D[3];
    u8 x3A0;
    Flags8 f3A1;
    u8 pad3A2[0x3CD - 0x3A2];
    s8 x3CD;
    u8 pad3CE[2];
    f32 x3D0;
    u8 x3D4;
    u8 x3D5;
    u8 pad3D6[0xA];
    u16 x3E0[8];
} P_func_001C1A00;
typedef struct { u8 pad[0x54]; s16 x54; s16 x56; } T;
typedef struct { u8 pad[3]; u8 x3; } U;
typedef struct { u8 pad[0x2C]; f32 x2C; u32 x30; u32 x34; } K;
typedef struct { u8 b0:4; u8 f:3; u8 b7:1; } F30;
typedef struct { u16 h[6]; u8 padC[4]; u8 y[0x20]; F30 f30; u8 pad31[0xF]; } X_func_001C1A00;
typedef struct { u8 pad[0x30]; u32 x30; u32 x34; } Pad;
typedef struct { u8 pad[3]; u8 x3; } R_func_001C2190;
typedef struct {
    u8 pad[0x39C]; u8 m39C; u8 pad2[0x3D5 - 0x39D]; u8 m3D5; u8 pad3[0x3E0 - 0x3D6]; u16 h[8];
} S_func_001C2190;
typedef struct { u8 lo:4; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; } BF;
typedef struct {
    u8 pad0[0x396]; s8 x396; u8 pad1; s16 x398;
    u8 pad2[0x3CC - 0x39A]; s8 x3cc; u8 pad3[8]; u8 x3d5; BF f; u8 pad4[9]; u16 x3e0[8];
} Sub;
typedef struct { u8 pad[0x180]; Sub s; } Obj2;
typedef struct { u8 pad[0x516]; s8 x516; } Hd;
typedef struct { u8 pad[0x518]; s8 *x518; } Obj;
typedef struct { u8 pad[0x20]; f32 x20, x24, x28, x2c; } Arg;
typedef struct { u8 pad[0x20]; f32 rot; } R_func_001C27C0;
typedef struct { u8 pad[0x48]; s32 slow; } Q_func_001C27C0;
typedef struct {
    u8 pad0[0x18]; R_func_001C27C0 *r;
    u8 pad1[0x390 - 0x1C]; Q_func_001C27C0 *q;
    u8 pad2[0x3A0 - 0x394]; u8 flg;
    u8 pad3[0x42C - 0x3A1]; f32 dt;
} A;
typedef struct { u8 pad[0x18]; f32 x, y; u8 pad2[0x34 - 0x20]; s32 btn; } In_func_001C27C0;
typedef struct { u8 pad[0x50]; Vec v50; u8 p60[0x380 - 0x60]; f32 f380; f32 f384; f32 f388; u32 u38C; u8 p390[0x3A1 - 0x390];
    Flags8 f3A1; Flags8 f3A2; u8 p3A3[0x3BF - 0x3A3]; u8 u3BF; u8 p3C0[0x454 - 0x3C0]; f32 f454; } P_func_001C2A50;
typedef struct { u8 pad[0x20]; f32 x20; f32 x24; } Q_func_001C2DB0;
typedef struct { u8 pad[0x48]; s32 x48; } R_func_001C2DB0;
typedef struct { u8 lo4:4; u8 b4:1; u8 b5:3; } B39D_func_001C2DB0;
typedef union { struct { u16 a:7; u16 f:6; u16 c:3; } h; struct { u8 lo; Flags8 hi; } b; } U3A0;
typedef struct {
    u8 pad[0x18];
    Q_func_001C2DB0 *x18;
    u8 pad1C[0x50 - 0x1C];
    Vec v50;
    u8 pad60[0x390 - 0x60];
    R_func_001C2DB0 *x390;
    u8 pad394[0x39D - 0x394];
    B39D_func_001C2DB0 f39D;
    u8 pad39E[2];
    U3A0 f3A0;
    u8 pad3A2[0x3CD - 0x3A2];
    s8 x3CD;
    u8 pad3CE[0x428 - 0x3CE];
    f32 f428;
    f32 f42C;
} P_func_001C2DB0;
typedef struct { s8 pad[0x20]; f32 f20; f32 f24; s8 pad2[0x38]; Vec v60; s8 pad3[0x10]; Vec v80; } P18;
typedef struct { s8 pad[0x48]; s32 x48; } P390;
typedef struct { u8 n:4; u8 b4:1; u8 r:3; } B39D_func_001C34F0;
typedef struct { u16 pad:7; u16 cnt:6; u16 r:3; } B3A0;
typedef struct {
    s8 pad[0x18]; P18 *p18; s8 pad1[0x50 - 0x1C]; Vec v50;
    s8 pad2[0x390 - 0x60]; P390 *p390; s8 pad3[0x39D - 0x394]; B39D_func_001C34F0 b39D; s8 pad4[2]; B3A0 h3A0; s8 pad5[2]; f32 f3A4;
} SS_func_001C34F0;
typedef struct { u8 pad0[0x24]; f32 x24; u8 pad28[0x38]; Vec v60; u8 pad70[0x10]; Vec v80; } Q_func_001C39D0;
typedef struct { u8 pad0[0x48]; s32 x48; } R_func_001C39D0;
typedef struct {
    u8 pad0[0x18];
    Q_func_001C39D0 *x18;
    u8 pad1C[0x40 - 0x1C];
    Vec v40;
    Vec v50;
    u8 pad60[0x390 - 0x60];
    R_func_001C39D0 *x390;
    u8 pad394[0x3A0 - 0x394];
    u16 lo:7; u16 f:6; u16 hi:3;
    u8 pad3A2[2];
    f32 x3A4;
} P_func_001C39D0;
typedef struct { f32 x0, x4, x8, xC, x10, x14, x18, x1C; } In_func_001C39D0;
typedef struct { u8 pad0[0x24]; f32 x24; u8 pad28[0x38]; Vec v60; u8 pad70[0x10]; Vec v80; } Q_func_001C3EF0;
typedef struct { u8 pad0[0x48]; s32 x48; } R_func_001C3EF0;
typedef struct { u8 pad0[0xC]; u8 c0 : 4; u8 c4 : 4; u8 d0 : 3; u8 d3 : 5; } X_func_001C3EF0;
typedef struct {
    u8 pad0[0x18];
    Q_func_001C3EF0 *x18;
    u8 pad1C[0x40 - 0x1C];
    Vec v40;
    Vec v50;
    u8 pad60[0x154 - 0x60];
    s32 x154;
    u8 pad158[4];
    X_func_001C3EF0 *x15C;
    u8 pad160[0x390 - 0x160];
    R_func_001C3EF0 *x390;
    u8 pad394[0x39E - 0x394];
    u16 lo : 6; u16 cnt : 6; u16 b12 : 1; u16 hi3 : 3;
    u16 lo7 : 7; u16 f : 6; u16 hi : 3;
    u8 pad3A2[2];
    f32 x3A4;
} P_func_001C3EF0;
typedef struct { f32 x0, x4, x8, xC, x10, x14, x18, x1C; } In_func_001C3EF0;
extern s32 D_002022EC;
extern s32 **D_002022BC;
extern s32 D_00201EB0;
extern s32 D_00201E80;
extern s8 D_004B4CF0[];
extern f32 D_004B4D00[];
extern f32 D_004B4D04[];
extern f32 D_004B4D08[];
extern f32 D_004B4D0C[];
extern MtxF D_001F2170;
extern u8 D_00222A54[];
extern Vec D_003139A0;
extern Vec D_001F2140;
extern f32 D_002022E8;
void func_001C0A10(Actor *a, P_func_001C0A10 *p);
void func_001C0E60(Actor *a, Ev *e);
inline s8* get(void);
s32 func_001C1140(void);
s32 func_001C13B0(void);
void func_001C1900(s8 *arg0, s8 *arg1);
void func_001C1A00(Actor *a0, K *a1);
void func_001C2190(Actor *a, Pad *pad);
void func_001C23E0(Obj *arg0, Arg *arg1);
f32 func_001C2640(s8 *arg0);
void func_001C27C0(s8 *arg0, In_func_001C27C0 *in);
void func_001C2A50(Actor *a);
void func_001C2DB0(Actor *a, f32 *in);
void func_001C34F0(s8 *arg0, f32 *a);
void func_001C39D0(Actor *a, In_func_001C39D0 *in, f32 dt);
void func_001C3EF0(Actor *a, In_func_001C3EF0 *in, f32 dt);
void func_001C0860(Obj3D *, Obj3D *, s32, s32, f32);
s32 func_001A9D50(s32, u16);
void func_001A9E10(s32, u16, u8);
void func_001AF4A0(Obj3D *);
void func_001AF3F0(Obj3D *);
void memset(void *, s32, s32);
s32 func_00179F80(Msg *);
void func_001CBCD0(s32);
void func_0012C110(s32);
s32 func_001D1CB0(s32);
void func_001C0020(Actor *);
s32 func_001CCD90(s32);
void func_001CAEF0(s32);
s32 func_001C0550(Actor *);
void func_00179F10(void);
void func_001B90F0(void);
void sceVu0CopyVector(void *, void *);
void sceVu0Normalize(void *, void *);
void sceVu0ScaleVector(void *, void *, f32);
void sceVu0AddVector(void *, void *, void *);
void func_001502A0(Ray *, f32 *, f32 *, f32);
void func_001B2160(s32, Res *, Ray *, s32, s32);
void sceVu0RotMatrixX(void *, void *, f32);
void sceVu0RotMatrixY(void *, void *, f32);
void sceVu0SubVector(Vec *, Vec *, Vec *);
s32 func_001B3240(s8 *, Hit *, Vec *, s32, s32);
f32 sceVu0InnerProduct(Vec *, Vec *);
f32 sqrtf(f32);
s32 func_001D1D50(u8);
s32 func_001D1DA0(u8);
s32 func_0012C400(s32);
u8 func_001A9450(void);
T* func_001AFC40(s16);
s16 func_001CBC20(s16);
void func_001C6590(s32);
U* func_001D1E10(void);
void func_001CA930(void);
void func_001CBA80(s16, u8);
void func_001CA6F0(void);
s32 func_001D1E00(u8);
s32 func_001D1DD0(u8);
s8* func_00169B50(s16, s32, s32, s32);
void sceVu0CopyMatrix(Mtx *, Mtx *);
void func_001677C0(s8 *, Mtx *);
void func_00167600(s8 *, Actor *);
void func_001CEBF0(X_func_001C1A00 *, u8 *, s8);
s32 func_001CC250(s32);
void func_001672B0(s8 *, X_func_001C1A00 *);
void func_001CA860(void);
void func_001C69A0(s32);
void func_001CA940(void);
void func_001CA870(void);
void func_001CA880(s32);
void func_001C6D40(u8);
f32 fabsf(f32);
f32 sinf(f32);
s32 func_001A9440(void);
void func_001CA4A0(u8, u8);
s32 func_00120570(s32);
f32 func_0015DF90(f32, f32, f32);
void func_001CA2C0(void);
void sceVu0OuterProduct(Vec *, Vec *, Vec *);

/* func_001C0A10 */
void func_001C0A10(Actor *a, P_func_001C0A10 *p) {
    S_func_001C0A10 *s = (S_func_001C0A10 *)(a->unk518 + 0x180);
    Obj3D *o = s->x414;
    u8 n;
    f32 q;
    s32 *id;
    u16 k;
    Msg msg;

    if (o == NULL) return;
    if (o->xA8.f.b1) goto ret;
    if (o->xA8.f.b0) goto go;
ret:
    return;
go:
    n = s->f18;
    if (n != 0) {
        if (s->b13) {
            q = 1.0f - n / 15.0f;
            func_001C0860(o, o, 0, 0, q * q);
        } else {
            q = n / 15.0f;
            func_001C0860(o, o, D_002022EC, 1, q * (2.0f - q));
        }
        s->f18 = s->f18 + 1;
        if (s->f18 < 15) return;
        if (o->x9E == 2 && o->xA9.f.b2) {
            if (!s->b13) {
                id = *(s32 **)o->x8C;
                func_001A9E10(*id, o->xAC, func_001A9D50(*id, o->xAC) | 2);
            }
            func_001AF4A0(o);
        } else if (!s->b13) {
            if (o->x9E == 0 && (k = o->xAA) != 0 && D_002022BC != NULL && *D_002022BC != NULL) {
                memset(&msg, 0, 0x30);
                                msg.type = 5;
msg.a = k;
                msg.b = **D_002022BC;
                func_00179F80(&msg);
            }
            func_001AF3F0(o);
        }
        s->f18 = 0;
        s->f14 = 0;
        s->x414 = NULL;
        return;
    }
    D_002022EC++;
    if (s->f14 < 15) {
        s->f14 = s->f14 + 1;
        D_002022EC = 0;
    }
    q = s->f14 / 15.0f;
    func_001C0860(o, o, D_002022EC, 0, q * (2.0f - q));
    if (p->x30 & 0x2000) {
        func_001CBCD0(o->x9C);
        s->b13 = 0;
        s->f18 = 1;
        s->f14 = 0;
    } else if (p->x30 & 0x4000) {
        s->b13 = 1;
        s->f18 = 1;
        s->f14 = 0;
    }
}

/* func_001C0E60 */
#define func_001C1140 func_001C1140__as_func_001C0E60
void func_001C1140__as_func_001C0E60(void);
static inline S_func_001C0E60 *get_func_001C0E60(void) {
    S_func_001C0E60 *r;
    s8 *base;
    s32 v;
    if (D_002022E4 == NULL) {
        r = NULL;
    } else if ((base = D_002022E4->unk518) == NULL) {
        r = NULL;
    } else {
        r = (S_func_001C0E60 *)(base + 0x180);
    }
    return r;
}
static inline s32 fa(void) {
    S_func_001C0E60 *r;
    s8 *base;
    s32 v;
    if (D_002022E4 == NULL) {
        r = NULL;
    } else if ((base = D_002022E4->unk518) == NULL) {
        r = NULL;
    } else {
        r = (S_func_001C0E60 *)(base + 0x180);
    }
    if (r == NULL) v = 0; else v = r->f3D6.f.b0;
    return v;
}
static inline s32 fb(void) {
    S_func_001C0E60 *r;
    s8 *base;
    s32 v;
    if (D_002022E4 == NULL) {
        r = NULL;
    } else if ((base = D_002022E4->unk518) == NULL) {
        r = NULL;
    } else {
        r = (S_func_001C0E60 *)(base + 0x180);
    }
    if (r == NULL) v = 0; else v = r->f3D6.f.b1;
    return v;
}

void func_001C0E60(Actor *a, Ev *e) {
    s32 fl = e->x30;
    S_func_001C0E60 *s = (S_func_001C0E60 *)(a->unk518 + 0x180);
    S_func_001C0E60 *p;
    if (fl & 1) {
        func_0012C110(0x13);
        return;
    }
    if (s->f39E && (fl & 0x4000)) {
        s->f39E = 0;
        return;
    }
    if (s->x3D5 == 8) return;
    if (!fa() && !fb()) {
        if ((fl & 0x4000) && D_00201EB0 != 1) {
            func_0012C110(0x14);
            return;
        }
        if (fl & 0x1000) {
            if (!s->f3D6.f.b3) {
                if (func_001D1CB0(s->x39C)) {
                    s->x390->f94.f.b0 = 0;
                    s->f3D6.f.b3 = 0;
                } else {
                    s->f3D6.f.b3 = 1;
                }
            }
            return;
        }
    }
    if (fl & 0x8000) {
        func_001C0020(a);
        return;
    }
    if (fl & 8) {
        func_001CAEF0(func_001CCD90(9));
        return;
    }
    if (s->f3A2.f.b0 && (fl & 0x2000)) {
        if (!func_001C0550(a)) {
            func_00179F10();
            func_001B90F0();
            p = get_func_001C0E60();
            if (p && !p->f39E) {
                if (!func_001C13B0()) func_001C1140();
            }
        }
    }
}
#undef func_001C1140

/* func_001C1140 */
#define sceVu0CopyVector sceVu0CopyVector__as_func_001C1140
void sceVu0CopyVector__as_func_001C1140(f32 *, s8 *);
#define sceVu0Normalize sceVu0Normalize__as_func_001C1140
void sceVu0Normalize__as_func_001C1140(f32 *, f32 *);
#define sceVu0ScaleVector sceVu0ScaleVector__as_func_001C1140
void sceVu0ScaleVector__as_func_001C1140(f32 *, f32 *, f32);
#define sceVu0AddVector sceVu0AddVector__as_func_001C1140
void sceVu0AddVector__as_func_001C1140(f32 *, f32 *, s8 *);
inline s8 *get(void) {
    if (D_002022E4 == NULL) {
        return NULL;
    }
    if (D_002022E4->unk518 == NULL) {
        return NULL;
    }
    return D_002022E4->unk518 + 0x180;
}

s32 func_001C1140(void) {
    Res res;
    Ray ray;
    f32 a[4];
    f32 b[4];
    s32 i;
    P_func_001C1140 *p;
    s32 **q;
    s32 t;

    p = (P_func_001C1140 *)get();
    if (p->m3BF != 0xC && p->m3BF != 0xD) {
        return 0;
    }
    sceVu0CopyVector(a, p->m18 + 0x80);
    a[1] = 0.0f;
    sceVu0Normalize(a, a);
    sceVu0ScaleVector(a, a, -125.0f);
    sceVu0CopyVector(b, (s8 *)a);
    a[1] -= 10.0f;
    b[1] += 300.0f;
    sceVu0AddVector(a, a, p->m18 + 0x90);
    sceVu0AddVector(b, b, p->m18 + 0x90);
    func_001502A0(&ray, a, b, 50.0f);
    for (i = 0, q = (s32 **)(&D_00201E80 + 2); i < 2; i++, q++) {
        if (*q != 0 && **q != 0) {
            memset(&res, 0, 0x40);
            func_001B2160(**q, &res, &ray, 2, -2);
            if (res.hit != 0) {
                t = res.tri[0xC] & 0xF;
                if (t == 0xC || t == 0xD) {
                    D_004B4D00[0] = *(f32 *)(res.tri + 0x10);
                    D_004B4D04[0] = *(f32 *)(res.tri + 0x14);
                    D_004B4D08[0] = *(f32 *)(res.tri + 0x18);
                    D_004B4D0C[0] = 1.0f;
                    sceVu0CopyVector((f32 *)D_004B4CF0, (s8 *)&res);
                    p->f6 = 1;
                    p->b12 = 1;
                    p->f13 = 0;
                    return 1;
                }
            }
        }
    }
    return 0;
}
#undef sceVu0CopyVector
#undef sceVu0Normalize
#undef sceVu0ScaleVector
#undef sceVu0AddVector

/* func_001C13B0 */
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
#define D_004B4D00 D_004B4D00__as_func_001C13B0
extern Vec D_004B4D00__as_func_001C13B0;
#define D_004B4CF0 D_004B4CF0__as_func_001C13B0
extern Vec D_004B4CF0__as_func_001C13B0;
#define sceVu0RotMatrixX sceVu0RotMatrixX__as_func_001C13B0
void sceVu0RotMatrixX__as_func_001C13B0(MtxF *, MtxF *, f32);
#define sceVu0RotMatrixY sceVu0RotMatrixY__as_func_001C13B0
void sceVu0RotMatrixY__as_func_001C13B0(MtxF *, MtxF *, f32);
#define sceVu0CopyVector sceVu0CopyVector__as_func_001C13B0
void sceVu0CopyVector__as_func_001C13B0(Vec *, Vec *);
#define sceVu0ScaleVector sceVu0ScaleVector__as_func_001C13B0
void sceVu0ScaleVector__as_func_001C13B0(Vec *, Vec *, f32);
#define sceVu0AddVector sceVu0AddVector__as_func_001C13B0
void sceVu0AddVector__as_func_001C13B0(Vec *, Vec *, Vec *);
#define sceVu0Normalize sceVu0Normalize__as_func_001C13B0
void sceVu0Normalize__as_func_001C13B0(Vec *, Vec *);
static inline P_func_001C13B0 *cur_func_001C13B0(void) {
    if (D_002022E4 == 0) return 0;
    if (D_002022E4->unk518 == 0) return 0;
    return (P_func_001C13B0 *)(D_002022E4->unk518 + 0x180);
}

s32 func_001C13B0(void) {
    s8 ***q;
    P_func_001C13B0 *p;
    s32 i;
    Tri *t;
    Hit hit;
    Vec V[2];
    MtxF m;
    Vec d;

    p = cur_func_001C13B0();
    sceVu0RotMatrixX(&m, &D_001F2170, WRAP(p->f3A4 + WRAP(p->o[3].x)));
    sceVu0RotMatrixY(&m, &m, WRAP(WRAP(3.1415927f + p->o[3].y)));
    sceVu0CopyVector(&V[1], (Vec *)m.m[2]);
    sceVu0ScaleVector(&V[1], &V[1], 650.0f);
    sceVu0AddVector(&V[1], &V[1], p->o);
    sceVu0CopyVector(&V[0], p->o);
    memset(&hit, 0, 0x40);
    for (i = 0, q = (s8 ***)(&D_00201E80 + 2); i < 2; i++, q++) {
        if (*q != 0 && **q != 0) {
            func_001B3240(**q, &hit, &V[0], 2, 0);
        }
    }
    if (hit.x24 == 0) return 0;
    if (hit.x2C->t == 12 || hit.x2C->t == 13) {
        V[1].x = hit.x2C->x;
        V[1].y = hit.x2C->y;
        V[1].z = hit.x2C->z;
        V[1].w = 1.0f;
        sceVu0CopyVector(&V[0], &p->o[8]);
        V[0].y = 0.0f;
        sceVu0Normalize(&V[0], &V[0]);
        if (sceVu0InnerProduct(&V[1], &V[0]) > 0.8f) {
            if (hit.p.y < p->o->y + 234.99998f) {
                sceVu0SubVector(&d, &hit.p, p->o);
                if (!(sqrtf(sceVu0InnerProduct(&d, &d)) <= 200.0f)) return 0;
                hit.p.y = p->o->y - 20.0f;
            }
            p->b = 1;
            p->c = 0;
            p->d = 0;
            sceVu0CopyVector(&D_004B4D00, &V[1]);
            sceVu0CopyVector(&D_004B4CF0, &hit.p);
            return 1;
        }
    }
    return 0;
}
#undef sceVu0RotMatrixX
#undef sceVu0RotMatrixY
#undef sceVu0CopyVector
#undef sceVu0ScaleVector
#undef sceVu0AddVector
#undef sceVu0Normalize
#undef D_004B4D00
#undef D_004B4CF0

/* func_001C1900 */
#define func_001C1A00 func_001C1A00__as_func_001C1900
void func_001C1A00__as_func_001C1900(s8 *, s8 *);
#define func_001C2190 func_001C2190__as_func_001C1900
void func_001C2190__as_func_001C1900(s8 *, s8 *);
#define func_001C23E0 func_001C23E0__as_func_001C1900
void func_001C23E0__as_func_001C1900(s8 *, s8 *);

void func_001C1900(s8 *arg0, s8 *arg1) {
    s8 *t;
    SS_func_001C1900 *s;
    SV *v;

    t = M2C_FIELD(arg0, s8 **, 0x518);
    s = (SS_func_001C1900 *)(t + 0x180);
    if (M2C_FIELD(t, BFb *, 0x556).b3 == 0) {
        if (s->p390->b94 & 1) {
            v = s->p3C4;
        } else {
            v = s->p3C0;
        }
        if (v->a8.b1) goto ret; if (v->a8.b0) goto go; ret: return; go: {
            if (func_0012C400(3) != 0) {
                if (func_001D1D50(s->b39C) != 0) {
                    if (func_001D1DA0(s->b39C) != 0) {
                        func_001C2190(arg0, arg1);
                    } else {
                        func_001C1A00(arg0, arg1);
                    }
                } else {
                    func_001C23E0(arg0, arg1);
                }
            }
        }
    }
}
#undef func_001C1A00
#undef func_001C2190
#undef func_001C23E0

/* func_001C1A00 */
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
#define D_001F2170 D_001F2170__as_func_001C1A00
extern Mtx D_001F2170__as_func_001C1A00;
#define sceVu0RotMatrixX sceVu0RotMatrixX__as_func_001C1A00
void sceVu0RotMatrixX__as_func_001C1A00(Mtx *, Mtx *, f32);
#define sceVu0RotMatrixY sceVu0RotMatrixY__as_func_001C1A00
void sceVu0RotMatrixY__as_func_001C1A00(Mtx *, Mtx *, f32);
#define sceVu0CopyVector sceVu0CopyVector__as_func_001C1A00
void sceVu0CopyVector__as_func_001C1A00(Vec *, void *);
static inline P_func_001C1A00 *cur_func_001C1A00(void) {
    if (D_002022E4 == 0) return 0;
    if (D_002022E4->unk518 == 0) return 0;
    return (P_func_001C1A00 *)(D_002022E4->unk518 + 0x180);
}

void func_001C1A00(Actor *a0, K *a1) {
    P_func_001C1A00 *s3;
    u32 m1;
    T *t;
    s16 r;
    u32 m2;
    s16 idx;
    s32 v;
    s32 k;
    s8 *o;
    P_func_001C1A00 *c;
    X_func_001C1A00 x;
    Mtx m;

    s3 = (P_func_001C1A00 *)(a0->unk518 + 0x180);
    if (func_001A9450() < 2) m1 = 4; else m1 = 0x800;
    if (func_001A9450() < 2) m2 = 4; else m2 = 0x800;
    if (s3->f3A1.f.b7) {
        if (s3->x3D5 == 3) func_001C6590(6);
        return;
    }
    t = func_001AFC40(func_001CCD90(s3->x390->x94 & 1));
    idx = t->x54;
    r = func_001CBC20(idx);
    if (s3->x3D5 == 0) {
        if (func_001D1E10()->x3 > 0 || r > 0) {
            if (a1->x30 & m1) {
                func_001C6590(1);
                s3->x3D4 = 10;
                func_001CA930();
            }
        }
    } else if (s3->x3D5 == 3) {
    if (func_001D1E10()->x3 <= 0) {
        if (r <= 0) {
            func_001C6590(6);
        } else {
            func_001C6590(5);
            s3->x3D4 = 10;
            v = s3->x394;
            v = (v < r) ? v : r;
            func_001D1E10()->x3 = v;
            func_001CBA80(idx, func_001D1E10()->x3);
            func_001CA6F0();
        }
        return;
    }
    if (func_001D1E00(s3->x39C) && s3->x3D0 <= 0.17f) m2 = 0;
    if ((a1->x30 & m2) || (func_001D1DD0(s3->x39C) && (a1->x34 & m2))) {
        k = t->x56;
        if (k != 0) {
        o = func_00169B50(k, 0, 1, 0);
        if (o != 0) {
            sceVu0CopyMatrix(&m, &D_001F2170);
            sceVu0RotMatrixX(&m, &m, WRAP(-WRAP(s3->x18->x20)));
            sceVu0RotMatrixY(&m, &m, WRAP(WRAP(s3->x18->x24)));
            sceVu0CopyVector(&m.m[3], s3->x18);
            m.m[3].w = 1.0f;
            func_001677C0(o, &m);
            func_00167600(o, a0);
            c = cur_func_001C1A00();
            if (c != 0) {
                memset(&x, 0, 0x40);
                func_001CEBF0(&x, x.y, c->x3CD);
                x.f30.f = func_001CC250(func_001CCD90(c->x390->x94 & 1));
            }
            if (s3->x39C == 11) {
                x.h[0] >>= 2;
                x.h[1] >>= 2;
                x.h[2] >>= 2;
                x.h[3] >>= 2;
                x.h[4] >>= 2;
                x.h[5] >>= 2;
            }
            func_001672B0(o, &x);
        }
        }
        func_001C6590(4);
        s3->x3D4 = 10;
        func_001D1E10()->x3--;
        c = cur_func_001C1A00();
        if (c != 0) {
            c->x3E0[0] = 0xFFFF; c->x3E0[1] = 0xFFFF; c->x3E0[2] = 0xFFFF; c->x3E0[3] = 0xFFFF;
            c->x3E0[4] = 0xFFFF; c->x3E0[5] = 0xFFFF; c->x3E0[6] = 0xFFFF; c->x3E0[7] = 0xFFFF;
        }
        func_001CA860();
    } else {
    if (func_001A9450() < 2) {
        if (!(a1->x2C <= 0.5f)) s3->x3D4--; else s3->x3D4 = 10;
    } else {
        s3->x3D4 = 10;
        if (a1->x30 & 0x400) s3->x3D4 = 0;
    }
    if (s3->x3D4 <= 0) func_001C6590(6);
    }
    }
}
#undef sceVu0RotMatrixX
#undef sceVu0RotMatrixY
#undef sceVu0CopyVector
#undef D_001F2170

/* func_001C2190 */
#define func_001CBC20 func_001CBC20__as_func_001C2190
s32 func_001CBC20__as_func_001C2190(s32);
#define func_001D1E10 func_001D1E10__as_func_001C2190
R_func_001C2190 *func_001D1E10__as_func_001C2190(void);
static inline s8 *get_func_001C2190(void) {
    if (D_002022E4 == NULL) {
        return NULL;
    }
    if (D_002022E4->unk518 == NULL) {
        return NULL;
    }
    return D_002022E4->unk518 + 0x180;
}

void func_001C2190(Actor *a, Pad *pad) {
    S_func_001C2190 *s;
    u32 mask;
    S_func_001C2190 *t;

    s = (S_func_001C2190 *)(a->unk518 + 0x180);
    mask = (func_001A9450() < 2) ? 4 : 0x800;
    if (s->m39C == 9) {
        if (func_001CBC20(0x12) <= 0) {
            if (s->m3D5 == 3) {
                func_001C69A0(5);
            }
            return;
        }
    } else {
        if (func_001CBC20(0x13) <= 0) {
            if (s->m3D5 == 3) {
                func_001C69A0(5);
            }
            return;
        }
    }
    if (s->m3D5 == 0) {
        if (pad->x30 & mask) {
            func_001C69A0(1);
            func_001D1E10()->x3 = 1;
            func_001CA940();
        }
    } else if (s->m3D5 == 1) {
        if (!(pad->x34 & mask)) {
            func_001C69A0(2);
            func_001D1E10()->x3 = 0;
        }
    } else if (s->m3D5 == 3) {
        if (!(pad->x34 & mask)) {
            func_001C69A0(4);
            func_001D1E10()->x3 = 0;
            if (s->m39C == 9) {
                func_001CBA80(0x12, 1);
            } else {
                func_001CBA80(0x13, 1);
            }
            t = (S_func_001C2190 *)get_func_001C2190();
            if (t != NULL) {
                t->h[0] = 0xFFFF;
                t->h[1] = 0xFFFF;
                t->h[2] = 0xFFFF;
                t->h[3] = 0xFFFF;
                t->h[4] = 0xFFFF;
                t->h[5] = 0xFFFF;
                t->h[6] = 0xFFFF;
                t->h[7] = 0xFFFF;
            }
            func_001CA870();
        } else if (func_001A9450() >= 2 && (pad->x30 & 0x400)) {
            func_001C69A0(5);
            func_001D1E10()->x3 = 0;
        }
    }
}
#undef func_001CBC20
#undef func_001D1E10

/* func_001C23E0 */
#define D_002022E4 D_002022E4__as_func_001C23E0
extern Obj *D_002022E4__as_func_001C23E0;
static inline Sub *getsub(void) {
    Obj *o = D_002022E4;
    if (o == NULL) return NULL;
    if (o->x518 == NULL) return NULL;
    return (Sub *)(o->x518 + 0x180);
}

void func_001C23E0(Obj *arg0, Arg *arg1) {
    s8 *h = arg0->x518;
    Sub *s = (Sub *)(h + 0x180);
    u8 k = 0;
    f32 f;
    if (((Hd *)h)->x516 > 0 && s->x3d5 == 0) {
        f = arg1->x28;
        if (!(f <= 0.5f)) {
            k = 1;
            if (!(arg1->x20 <= f)) k = 2;
            if (!(arg1->x24 <= f)) k = 4;
        } else {
            f = arg1->x2c;
            if (!(f <= 0.5f)) {
                k = 3;
                if (!(arg1->x20 <= f)) k = 2;
                if (!(arg1->x24 <= f)) k = 4;
            } else {
                if (!(arg1->x20 <= 0.5f)) k = 2;
                if (!(arg1->x24 <= 0.5f)) k = 4;
            }
        }
        if ((u8)k == 0) {
            s->x3cc = k;
            s->f.b6 = 0;
            s->f.b4 = 0;
            return;
        }
        if (s->f.b4 == 0 && (u8)k != s->x3cc) {
            s->x3cc = k;
            s->f.b6 = 0;
        } else {
            s->x3cc = k;
            s->f.b6 = 1;
            s->f.b4 = 0;
        }
        if (s->f.b6 == 0) {
            Sub *p = getsub();
            if (p != NULL) {
                p->x3e0[0] = 0xFFFF; p->x3e0[1] = 0xFFFF; p->x3e0[2] = 0xFFFF; p->x3e0[3] = 0xFFFF;
                p->x3e0[4] = 0xFFFF; p->x3e0[5] = 0xFFFF; p->x3e0[6] = 0xFFFF; p->x3e0[7] = 0xFFFF;
            }
            func_001CA880(k);
            s->x398 = 0;
            s->x396--;
            func_001C6D40(k);
        }
    }
}
#undef D_002022E4

/* func_001C2640 */
/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x10, 0x14, 0x18, 0x1c, 0x20, 0x24], gap at: 0x8. */

f32 func_001C2640(s8 *arg0) {
    f32 var_f20;
    s32 temp_v0;
    s32 temp_v0_2;
    s8 *temp_v1;
    s8 *p;

    temp_v1 = M2C_FIELD(arg0, s8 **, 0x518);
    p = temp_v1 + 0x180;
    var_f20 = 1.0f;
    if ((((u64) ((s64) M2C_FIELD(temp_v1, u8 *, 0x521) << 0x38) >> 0x3F) != 0) && (func_001CD450(0x10, NULL, 0, 1) == 0)) {
        var_f20 = 0.5f;
    }
    if ((M2C_FIELD(p, u8 *, 0x3BF) == 7) && !(var_f20 <= 0.5f)) {
        var_f20 = 0.5f;
    }
    if (!(D_00222A54[0] & 1)) {
        temp_v0 = func_001CDEC0();
        if (temp_v0 >= 2) {
            if (!(var_f20 <= 0.33333334f)) {
                var_f20 = 0.33333334f;
            }
        } else if ((temp_v0 == 1) && !(var_f20 <= 0.6666667f)) {
            var_f20 = 0.6666667f;
        }
    }
    temp_v0_2 = func_001CE200(3);
    if (temp_v0_2 >= 2) {
        if (!(var_f20 <= 0.33333334f)) {
            var_f20 = 0.33333334f;
        }
    } else if ((temp_v0_2 == 1) && !(var_f20 <= 0.6666667f)) {
        var_f20 = 0.6666667f;
    }
    return var_f20;
}

/* func_001C27C0 */
#define func_001A9450 func_001A9450__as_func_001C27C0
s32 func_001A9450__as_func_001C27C0(void);
static inline f32 spd(A *a) {
    f32 k;
    if (a->q->slow != 0) k = 0.5f; else k = 1.0f;
    return 0.06981317f * k;
}

void func_001C27C0(s8 *arg0, In_func_001C27C0 *in) {
    f32 mag;
    f32 acc;
    A *a;
    s32 on;
    f32 sign;

    on = 0;
    a = (A *)(M2C_FIELD(arg0, s32 *, 0x518) + 0x180);
    acc = 0.0f;
    mag = 1.0f;
    if ((func_001A9450() & 0xFF) >= 2) {
        if (in->btn & 4) {
            mag = 0.64000005f;
            on = 1;
        }
    } else if (in->y > acc && in->x > acc) {
        f32 t;
        mag = in->y * in->y;
        t = in->x * in->x;
        on = 1;
        mag = (t < mag) ? mag : t;
    }
    if (on != 0) {
        if (!(a->flg & 1)) {
            sign = 1.0f;
            if (a->r->rot > 0.0f) sign = -1.0f;
            acc += mag * sign * spd(a);
            a->r->rot += acc * a->dt;
            if (a->r->rot * sign > 0.0f) a->r->rot = 0.0f;
        }
    } else {
        if (in->y > 0.1f) acc -= 0.4f * spd(a);
        if (in->x > 0.1f) acc += 0.4f * spd(a);
        a->r->rot += acc * a->dt;
    }
}
#undef func_001A9450

/* func_001C2A50 */
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
#define sceVu0CopyVector sceVu0CopyVector__as_func_001C2A50
void sceVu0CopyVector__as_func_001C2A50(Vec *, Vec *);

void func_001C2A50(Actor *a) {
    P_func_001C2A50 *p;
    Vec v;
    f32 x;
    p = (P_func_001C2A50 *)(a->unk518 + 0x180);
    sceVu0CopyVector(&v, &p->v50);
    v.y = 0.0f;
    x = sqrtf(sceVu0InnerProduct(&v, &v));
    p->f454 = p->f380;
    if (x <= 100.0f && fabsf(p->f380) < 0.2f) {
        p->f384 = 0.0f;
        p->f388 = 0.0f;
        p->f380 = 0.0f;
        p->u38C = 0;
        p->f3A2.f.b2 = 0;
        return;
    }
    p->f384 *= 0.5f;
    p->f388 *= 0.5f;
    if (p->f3A1.f.b5) {
        x = WRAP(0.3f * p->u38C);
    } else {
        x = WRAP(0.2f * p->u38C);
    }
    p->f388 += 0.5f * sinf(x);
    p->f384 += p->f388;
    p->u38C++;
    p->f380 = func_001A9440() ? p->f384 : 0.0f;
    if (!(p->f384 <= 1.5f)) {
        if (!p->f3A2.f.b2) {
            func_001CA4A0(p->f3A1.f.b7 ? 0x10 : p->u3BF, p->f3A1.f.b5);
        }
        p->f3A2.f.b2 = 1;
    } else {
        p->f3A2.f.b2 = 0;
    }
}
#undef sceVu0CopyVector

/* func_001C2DB0 */
#define sceVu0ScaleVector sceVu0ScaleVector__as_func_001C2DB0
void sceVu0ScaleVector__as_func_001C2DB0(Vec *, Vec *, f32);
#define sceVu0AddVector sceVu0AddVector__as_func_001C2DB0
void sceVu0AddVector__as_func_001C2DB0(Vec *, Vec *, Vec *);
#define sceVu0CopyVector sceVu0CopyVector__as_func_001C2DB0
void sceVu0CopyVector__as_func_001C2DB0(Vec *, Vec *);
#define func_001C2640 func_001C2640__as_func_001C2DB0
f32 func_001C2640__as_func_001C2DB0(Actor *);

void func_001C2DB0(Actor *a, f32 *in) {
    Vec v90;
    Vec v80;
    Vec v70;
    Vec v60;
    P_func_001C2DB0 *p;
    s32 n;
    f32 d;
    f32 y;
    f32 sc;
    f32 yaw;
    f32 pitch;
    f32 t;
    f32 u;
    Q_func_001C2DB0 *q;

    yaw = 0.0f;
    p = (P_func_001C2DB0 *)(a->unk518 + 0x180);
    pitch = 0.0f;
    if (!(in[2] <= 0.2f) || !(in[3] <= 0.2f)) {
        n = 0;
        if (!(in[2] < 1.0f) && p->x3CD == 0) n -= 2;
        else if (!(in[2] <= 0.2f)) n -= 1;
        if (!(in[3] < 1.0f) && p->x3CD == 0) n += 2;
        else if (!(in[3] <= 0.2f)) n += 1;
        switch (func_00120570(n)) {
        case 0:
            in[3] = 0.0f;
            in[2] = 0.0f;
            break;
        case 1:
            sceVu0ScaleVector(&v90, (Vec *)((u8 *)p->x18 + 0x80), n > 0 ? 60.000004f : -75.0f);
            sceVu0AddVector(&p->v50, &v90, &p->v50);
            break;
        case 2:
            sceVu0ScaleVector(&v80, (Vec *)((u8 *)p->x18 + 0x80), n > 0 ? 100.0f : -250.0f);
            sceVu0AddVector(&p->v50, &v80, &p->v50);
            p->f3A0.b.hi.f.b5 = 1;
            break;
        }
    }
    if (!(in[5] <= 0.2f) || !(in[4] <= 0.2f)) {
        n = 0;
        if (!(in[5] <= 0.4f) && p->x3CD == 0) n -= 2;
        else if (!(in[5] <= 0.2f)) n -= 1;
        if (!(in[4] <= 0.4f) && p->x3CD == 0) n += 2;
        else if (!(in[4] <= 0.2f)) n += 1;
        sc = n >= 0 ? 1.0f : -1.0f;
        switch (func_00120570(n)) {
        case 0:
            in[4] = 0.0f;
            in[5] = 0.0f;
            break;
        case 1:
            sceVu0ScaleVector(&v70, (Vec *)((u8 *)p->x18 + 0x60), sc * (0.6f * (100.0f * (p->x390->x48 ? 0.5f : 1.0f))));
            sceVu0AddVector(&p->v50, &v70, &p->v50);
            break;
        case 2:
            sceVu0ScaleVector(&v60, (Vec *)((u8 *)p->x18 + 0x60), sc * (100.0f * (p->x390->x48 ? 0.5f : 1.0f)));
            sceVu0AddVector(&p->v50, &v60, &p->v50);
            p->f3A0.b.hi.f.b5 = 1;
            break;
        }
    }
    if (!(in[0] <= 0.2f) && in[1] <= 0.2f) {
        yaw += in[0] * (0.0488692187f * (p->x390->x48 ? 0.5f : 1.0f));
    }
    if (!(in[1] <= 0.2f) && in[0] <= 0.2f) {
        yaw -= in[1] * (0.0488692187f * (p->x390->x48 ? 0.5f : 1.0f));
    }
    sc = func_001C2640(a);
    y = p->v50.y;
    p->v50.y = 0.0f;
    d = sqrtf(sceVu0InnerProduct(&p->v50, &p->v50));
    if (d < 40.0f) sceVu0CopyVector(&p->v50, &D_003139A0);
    p->f428 = func_0015DF90(p->f428, p->f3A0.b.hi.f.b5 ? 0.8f * sc : 0.5f * sc, 0.2f);
    u = 600.0f * (p->x390->x48 ? 0.5f : 1.0f);
    t = p->f428 * u;
    if (!(d <= t)) {
        sceVu0ScaleVector(&p->v50, &p->v50, t / d);
    }
    if (in[2] <= 0.05f && in[3] <= 0.05f && in[5] <= 0.05f && in[4] <= 0.05f) {
        sceVu0ScaleVector(&p->v50, &p->v50, 0.64000005f);
    }
    p->v50.y = y;
    sc = (p->x3CD == 0) ? sc : 0.5f * sc;
    p->f42C = func_0015DF90(p->f42C, sc, 0.2f);
    q = p->x18;
    q->x20 += pitch * p->f42C;
    q = p->x18;
    q->x24 += yaw * p->f42C;
    func_001C2A50(a);
    p->f39D.b4 = 1;
    p->f3A0.h.f = 0;
    p->f39D.lo4 = 0;
}
#undef sceVu0ScaleVector
#undef sceVu0AddVector
#undef sceVu0CopyVector
#undef func_001C2640

/* func_001C34F0 */
#define sceVu0ScaleVector sceVu0ScaleVector__as_func_001C34F0
void sceVu0ScaleVector__as_func_001C34F0(Vec *, Vec *, f32);
#define sceVu0AddVector sceVu0AddVector__as_func_001C34F0
void sceVu0AddVector__as_func_001C34F0(Vec *, Vec *, Vec *);
static inline f32 mu(f32 a, f32 b) { return a * b; }

void func_001C34F0(s8 *arg0, f32 *a) {
    Vec t0;
    Vec t1;
    Vec t2;
    Vec t3;
    SS_func_001C34F0 *s;
    f32 k;
    f32 sv;
    f32 len;
    f32 f;
    f32 r;

    s = (SS_func_001C34F0 *)(*(s8 **)(arg0 + 0x518) + 0x180);
    if (s->h3A0.cnt < 0x3F) {
        s->h3A0.cnt++;
    }
    if (s->h3A0.cnt == 10) {
        func_001CA2C0();
    }
    if (s->h3A0.cnt < 4) {
        if (a[2] > 0.0f) {
            sceVu0ScaleVector(&t0, &s->p18->v80, 0.2f * (250.0f * -a[2]));
            sceVu0AddVector(&s->v50, &t0, &s->v50);
        }
        if (a[3] > 0.0f) {
            sceVu0ScaleVector(&t1, &s->p18->v80, 0.2f * (100.0f * a[3]));
            sceVu0AddVector(&s->v50, &t1, &s->v50);
        }
        if (a[5] > 0.0f) {
            k = s->p390->x48 ? 0.5f : 1.0f;
            sceVu0ScaleVector(&t2, &s->p18->v60, 0.2f * (-a[5] * (100.0f * k)));
            sceVu0AddVector(&s->v50, &t2, &s->v50);
        }
        if (a[4] > 0.0f) {
            k = s->p390->x48 ? 0.5f : 1.0f;
            sceVu0ScaleVector(&t3, &s->p18->v60, 0.2f * (a[4] * (100.0f * k)));
            sceVu0AddVector(&s->v50, &t3, &s->v50);
        }
    }
    if (a[0] > 0.0f) {
        k = s->p390->x48 ? 0.5f : 1.0f;
        s->p18->f24 = s->p18->f24 + 0.3f * (a[0] * (0.0488692187f * k));
    }
    if (a[1] > 0.0f) {
        k = s->p390->x48 ? 0.5f : 1.0f;
        s->p18->f24 = s->p18->f24 - 0.3f * (a[1] * (0.0488692187f * k));
    }
    sv = s->v50.y;
    s->v50.y = 0.0f;
    sceVu0ScaleVector(&s->v50, &s->v50, 0.640000045f);
    len = sceVu0InnerProduct(&s->v50, &s->v50);
    s->v50.y = sv;
    len = sqrtf(len);
    if (fabsf(s->p18->f20) < 0.0872664675f) {
        if (s->b39D.n > 3) {
            f = len / 1000.0f;
            f = f > 1.0f ? 1.0f : f;
            r = s->v50.y > 0.0f ? 0.05f : 0.01f;
            s->f3A4 = s->f3A4 + mu((-0.7853982f - s->f3A4) * r, f);
            s->b39D.n = 5;
        }
        s->b39D.n++;
    } else {
        s->f3A4 *= 0.8f;
        s->b39D.n = 0;
    }
    s->b39D.b4 = 0;
}
#undef sceVu0ScaleVector
#undef sceVu0AddVector

/* func_001C39D0 */
#define sceVu0CopyVector sceVu0CopyVector__as_func_001C39D0
void sceVu0CopyVector__as_func_001C39D0(Vec *, Vec *);
#define sceVu0AddVector sceVu0AddVector__as_func_001C39D0
void sceVu0AddVector__as_func_001C39D0(Vec *, void *, Vec *);
#define sceVu0ScaleVector sceVu0ScaleVector__as_func_001C39D0
void sceVu0ScaleVector__as_func_001C39D0(Vec *, Vec *, f32);

void func_001C39D0(Actor *a, In_func_001C39D0 *in, f32 dt) {
    P_func_001C39D0 *p;
    Vec t0;
    Vec t1;
    Vec t2;
    Vec t3;
    Vec t4;
    Vec t5;
    Vec t6;
    Vec t7;
    f32 m;

    p = (P_func_001C39D0 *)(a->unk518 + 0x180);
    sceVu0ScaleVector(&t0, &p->v50, -dt);
    sceVu0AddVector(&p->v40, &t0, &p->v40);
    p->v50.y = p->v50.y - 3920.0f * dt;
    sceVu0ScaleVector(&p->v50, &p->v50, 0.9f);
    if (sqrtf(sceVu0InnerProduct(&p->v50, &p->v50)) < 50.0f) {
        sceVu0CopyVector(&p->v50, &D_003139A0);
    }
    sceVu0ScaleVector(&t1, &p->v50, dt);
    sceVu0AddVector(&p->v40, &t1, &p->v40);
    if (in->x8 > 0.0f) {
        sceVu0ScaleVector(&t2, &p->x18->v80, 250.0f * -in->x8);
        sceVu0AddVector(&p->v50, &t2, &p->v50);
    }
    if (in->xC > 0.0f) {
        sceVu0ScaleVector(&t3, &p->x18->v80, 100.0f * in->xC);
        sceVu0AddVector(&p->v50, &t3, &p->v50);
    }
    if (in->x0 > 0.0f) {
        p->x18->x24 += in->x0 * (0.048869219f * (p->x390->x48 ? 0.5f : 1.0f));
    }
    if (in->x4 > 0.0f) {
        p->x18->x24 -= in->x4 * (0.048869219f * (p->x390->x48 ? 0.5f : 1.0f));
    }
    if (in->x14 > 0.0f) {
        if (in->x14 > 0.4f) {
            sceVu0ScaleVector(&t4, &p->x18->v60, -1.0f * (100.0f * (p->x390->x48 ? 0.5f : 1.0f)));
            sceVu0AddVector(&p->v50, &t4, &p->v50);
        } else {
            sceVu0ScaleVector(&t5, &p->x18->v60, -0.5f * (100.0f * (p->x390->x48 ? 0.5f : 1.0f)));
            sceVu0AddVector(&p->v50, &t5, &p->v50);
        }
    }
    if (in->x10 > 0.0f) {
        if (in->x10 > 0.4f) {
            sceVu0ScaleVector(&t6, &p->x18->v60, 100.0f * (p->x390->x48 ? 0.5f : 1.0f));
            sceVu0AddVector(&p->v50, &t6, &p->v50);
        } else {
            sceVu0ScaleVector(&t7, &p->x18->v60, 0.5f * (100.0f * (p->x390->x48 ? 0.5f : 1.0f)));
            sceVu0AddVector(&p->v50, &t7, &p->v50);
        }
    }
    p->x3A4 *= 0.5f;
    if (in->x1C > 0.0f && in->x18 > 0.0f) {
        m = in->x18 < in->x1C ? in->x18 : in->x1C;
        p->v50.y += 200.0f * m;
    }
    if (in->x14 > 0.0f && in->x10 > 0.0f) {
        m = in->x10 < in->x14 ? in->x10 : in->x14;
        p->v50.y += -200.0f * m;
    }
    p->f = 0;
}
#undef sceVu0CopyVector
#undef sceVu0AddVector
#undef sceVu0ScaleVector

/* func_001C3EF0 */
#define D_004B4D00 D_004B4D00__as_func_001C3EF0
extern Vec D_004B4D00__as_func_001C3EF0;
#define sceVu0CopyVector sceVu0CopyVector__as_func_001C3EF0
void sceVu0CopyVector__as_func_001C3EF0(Vec *, Vec *);
#define sceVu0AddVector sceVu0AddVector__as_func_001C3EF0
void sceVu0AddVector__as_func_001C3EF0(Vec *, Vec *, Vec *);
#define sceVu0ScaleVector sceVu0ScaleVector__as_func_001C3EF0
void sceVu0ScaleVector__as_func_001C3EF0(Vec *, Vec *, f32);
#define sceVu0Normalize sceVu0Normalize__as_func_001C3EF0
void sceVu0Normalize__as_func_001C3EF0(Vec *, Vec *);
#define func_001CA4A0 func_001CA4A0__as_func_001C3EF0
s32 func_001CA4A0__as_func_001C3EF0(u32, s32);

void func_001C3EF0(Actor *a, In_func_001C3EF0 *in, f32 dt) {
    Vec c;
    Vec n;
    Vec t0;
    Vec t1;
    Vec t2;
    Vec t3;
    Vec t4;
    Vec t5;
    Vec t6;
    Vec t7;
    Vec t8;
    Vec t9;
    Vec t10;
    Vec t11;
    P_func_001C3EF0 *p;
    s32 k;

    p = (P_func_001C3EF0 *)(a->unk518 + 0x180);
    if (p->cnt < 0x3F) {
        p->cnt++;
    }
    if (!(p->cnt < 15)) {
        sceVu0ScaleVector(&t0, &p->v50, -dt);
        sceVu0AddVector(&p->v40, &t0, &p->v40);
        p->v50.y = p->v50.y - 3920.0f * dt;
        sceVu0ScaleVector(&p->v50, &p->v50, 0.5f);
        sceVu0ScaleVector(&t1, &p->v50, dt);
        sceVu0AddVector(&p->v40, &t1, &p->v40);
    }
    if (p->b12) {
        if (p->cnt < 10) {
            sceVu0ScaleVector(&t2, &D_004B4D00, 120.0f);
            sceVu0AddVector(&p->v50, &t2, &p->v50);
            sceVu0ScaleVector(&t3, &D_001F2140, 150.0f);
            sceVu0AddVector(&p->v50, &t3, &p->v50);
        } else if (p->cnt < 0x30) {
            sceVu0ScaleVector(&t4, &D_004B4D00, -200.0f);
            sceVu0AddVector(&p->v50, &t4, &p->v50);
            sceVu0ScaleVector(&t5, &D_001F2140, 100.0f);
            sceVu0AddVector(&p->v50, &t5, &p->v50);
        } else {
            sceVu0ScaleVector(&t6, &D_004B4D00, -50.0f);
            sceVu0AddVector(&p->v50, &t6, &p->v50);
            if (p->cnt > 0x3C) {
                p->b12 = 0;
            }
        }
        sceVu0CopyVector(&n, &p->x18->v80);
        *(s32 *)&n.y = 0;
        sceVu0Normalize(&n, &n);
        sceVu0OuterProduct(&c, &D_004B4D00, &n);
        if (sceVu0InnerProduct(&D_004B4D00, &n) < -0.9f) {
            p->x18->x24 += 2.0f * (0.048869219f * (p->x390->x48 ? 0.5f : 1.0f));
        } else {
            if (c.y < -0.05f) {
                p->x18->x24 -= 2.5f * (c.y * (0.048869219f * (p->x390->x48 ? 0.5f : 1.0f)));
            }
            if (c.y > 0.05f) {
                p->x18->x24 -= 2.5f * (c.y * (0.048869219f * (p->x390->x48 ? 0.5f : 1.0f)));
            }
        }
    } else {
        sceVu0OuterProduct(&c, &D_004B4D00, &p->x18->v80);
        if (c.y > 0.05f) {
            p->x18->x24 -= 2.0f * (c.y * (0.048869219f * (p->x390->x48 ? 0.5f : 1.0f)));
        }
        if (c.y < -0.05f) {
            p->x18->x24 -= 2.0f * (c.y * (0.048869219f * (p->x390->x48 ? 0.5f : 1.0f)));
        }
        if (!(p->cnt < 15)) {
            sceVu0ScaleVector(&t7, &D_004B4D00, -400.0f);
            sceVu0AddVector(&p->v50, &t7, &p->v50);
            if (in->x8 > 0.0f) {
                p->v50.y = p->v50.y + 300.0f * -in->x8;
            }
            if (in->xC > 0.0f) {
                p->v50.y = p->v50.y + 300.0f * in->xC;
            }
            if (in->x14 > 0.4f) {
                sceVu0ScaleVector(&t8, &p->x18->v60, -0.5f * (100.0f * (p->x390->x48 ? 0.5f : 1.0f)));
                sceVu0AddVector(&p->v50, &t8, &p->v50);
            }
            if (in->x10 > 0.4f) {
                sceVu0ScaleVector(&t9, &p->x18->v60, 0.5f * (100.0f * (p->x390->x48 ? 0.5f : 1.0f)));
                sceVu0AddVector(&p->v50, &t9, &p->v50);
            }
            if (in->x0 > 0.4f) {
                sceVu0ScaleVector(&t10, &p->x18->v60, -0.5f * (100.0f * (p->x390->x48 ? 0.5f : 1.0f)));
                sceVu0AddVector(&p->v50, &t10, &p->v50);
            }
            if (in->x4 > 0.4f) {
                sceVu0ScaleVector(&t11, &p->x18->v60, 0.5f * (100.0f * (p->x390->x48 ? 0.5f : 1.0f)));
                sceVu0AddVector(&p->v50, &t11, &p->v50);
            }
        }
    }
    if (p->x154 != 0 && p->x15C->d0 == 1) {
        k = p->x15C->c0;
        if (k == 12 || k == 13) {
            D_002022E8 = D_002022E8 + fabsf(p->v50.y);
            if (D_002022E8 > 10000.0f) {
                D_002022E8 -= 10000.0f;
                if (fabsf(p->v50.y) > 100.0f) {
                    func_001CA4A0(k, 1);
                }
            }
        }
    }
    p->f = 0;
}
#undef sceVu0CopyVector
#undef sceVu0AddVector
#undef sceVu0ScaleVector
#undef sceVu0Normalize
#undef func_001CA4A0
#undef D_004B4D00
