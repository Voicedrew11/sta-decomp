#include "m2c.h"
#include "common.h"
typedef struct { u128 q[2]; } Q2;
typedef struct { s32 p; s32 n; f32 f; void *fn; s32 a; s32 b; void *cb; } Arg;
typedef struct { u8 b0 : 1; } F;
typedef struct { s32 state; s32 buttons; u8 next; u8 pad[5]; u8 pad_e; } Menu;
typedef struct { u8 b0:1; } BF;
typedef struct { u8 pad[0xA]; u16 xA; u8 pc[0x1D]; u8 x29; u8 p2a[0x66]; } E_func_0019DCF0;
typedef struct { u8 pad[2]; u8 x2; u8 x3; } C;
typedef struct { char p0[0xA]; u16 h; char pc[0x1D]; u8 b; char rest[0x66]; } E_func_0019DE30;
extern Q2 D_001F30C0;
extern s32 *D_00201D68;
extern s32 D_002021E8;
extern s32 D_002021F4;
extern s32 D_002021F8;
extern s32 D_004A3290[];
extern s32 D_004A3294[];
extern f32 D_004A3298[];
extern F D_004A329C[];
extern s32 D_002021E0;
extern s32 D_002021EC;
extern s32 D_002021F0;
extern s32 D_002021FC;
extern u16 D_004A32A0[];
extern f32 *D_00201D6C;
void func_0019D290(s32 *arg0);
void* func_0019D4A0(s32 id);
void* func_0019D510(s32 id);
void func_0019D580(Menu *m);
void func_0019DA70(Menu *m);
void func_0019DCF0(void);
s32 func_0019DE30(s32 i);
void func_0019DE90(s32 i, s8 *a1, s8 *a2);
void func_0017F890(s32, Q2 *, Arg *);
void func_0017F7C0(s32, s32, s32);
void func_0017F470(f32, s32, s32);
void func_00183DC0(s32);
void* func_001958A0(void);
void* func_001957E0(void *h, s32 id);
void* func_00195840(void *h, s32 id);
void func_00131600(s32, u8);
void func_001C9BA0(void);
void func_001CB980(void *);
void memset(void *, s32, s32);
void func_001CEDC0(s32);
void func_001CEA50(s32);
void func_001CBED0(s16, s32, s32);
void func_0012F6E0(s32);
void func_0012C260(void);
void func_001CAEF0(s16);
E_func_0019DCF0* func_001AFC90(void);
s32 func_00195BE0(s32);
C* func_001CC3F0(s16);
void func_0017F840(s32, s32 *);

/* func_0019D290 */
#define func_0019D580 func_0019D580__as_func_0019D290
void func_0019D580__as_func_0019D290(s32 *);
#define func_0019DA70 func_0019DA70__as_func_0019D290
void func_0019DA70__as_func_0019D290(s32 *);
#define func_0019D510 func_0019D510__as_func_0019D290
void func_0019D510__as_func_0019D290(void);
#define func_0019DE90 func_0019DE90__as_func_0019D290
void func_0019DE90__as_func_0019D290(void);

void func_0019D290(s32 *arg0) {
    Q2 q;
    Arg a;

    if (*arg0 == 0x19) {
        D_004A3290[0] = 0;
        func_0019DCF0();
        q = D_001F30C0;
        a.fn = func_0019D510;
        a.f = -3.0f;
        a.cb = func_0019DE90;
        a.a = 0;
        a.b = 0;
        a.p = (s32)D_00201D68;
        a.n = D_002021F8;
        func_0017F890(1, &q, &a);
        func_0017F7C0(1, 1, 1);
        D_002021F4 = 2;
        func_0017F470(D_004A3290[0], 1, 1);
    }
    func_00183DC0(D_00201D68[D_004A3290[0]]);
    if (D_004A329C[0].b0) {
        switch (D_002021E8) {
        case 0:
            func_0019DA70(arg0);
            break;
        case 1:
            func_0019D580(arg0);
            break;
        }
    }
    if (!D_004A329C[0].b0) {
        D_004A3298[0] -= 1.0f;
        if (D_004A3298[0] < 0.0f) {
            D_004A329C[0].b0 = 1;
            switch (D_004A3294[0]) {
            case 1:
                D_002021E8 = 0;
                D_004A3298[0] = 15.0f;
                D_004A329C[0].b0 = 0;
                break;
            case 2:
                D_002021E8 = 1;
                break;
            }
            D_004A3294[0] = -1;
            return;
        }
        D_004A329C[0].b0 = 0;
        return;
    }
}
#undef func_0019D580
#undef func_0019DA70
#undef func_0019D510
#undef func_0019DE90

/* func_0019D4A0 */
void *func_0019D4A0(s32 id)
{
    void *h = func_001958A0();
    if (!id)
        return NULL;
    if (id == -1)
        return NULL;
    if (h)
        return func_001957E0(h, id);
    return NULL;
}

/* func_0019D510 */
void *func_0019D510(s32 id)
{
    void *h = func_001958A0();
    if (!id)
        return NULL;
    if (id == -1)
        return NULL;
    if (h)
        return func_00195840(h, id);
    return NULL;
}

/* func_0019D580 */
#define D_004A329C D_004A329C__as_func_0019D580
extern BF D_004A329C__as_func_0019D580[];

void func_0019D580(Menu *m) {
    s32 n;

    func_001C9BA0();
    if (m->buttons & 0x10) {
        D_002021E0--;
        D_002021FC = 0;
        if (D_002021E0 < 0) {
            D_002021E0 = 0;
        } else {
            func_00131600(0x66, m->pad_e);
        }
    } else if (m->buttons & 0x40) {
        D_002021E0++;
        D_002021FC = 0;
        if (D_002021E0 > 7) {
            D_002021E0 = 7;
        } else {
            func_00131600(0x66, m->pad_e);
        }
    } else if (m->buttons & 0x20) {
        if (D_002021EC > 0) {
            switch (D_002021E0) {
            case 0: D_004A32A0[0]++; break;
            case 1: D_004A32A0[1]++; break;
            case 2: D_004A32A0[2]++; break;
            case 3: D_004A32A0[3]++; break;
            case 4: D_004A32A0[4]++; break;
            case 5: D_004A32A0[5]++; break;
            case 6: D_004A32A0[6]++; break;
            case 7: D_004A32A0[7]++; break;
            }
            D_002021EC--;
            func_00131600(0x6A, m->pad_e);
        }
    } else if (m->buttons & 0x80) {
        n = D_002021EC;
        if (n < D_002021F0) {
            switch (D_002021E0) {
            case 0: if (D_004A32A0[0] > 0) { D_004A32A0[0]--; D_002021EC = n + 1; func_00131600(0x6A, m->pad_e); } break;
            case 1: if (D_004A32A0[1] > 0) { D_004A32A0[1]--; D_002021EC = n + 1; func_00131600(0x6A, m->pad_e); } break;
            case 2: if (D_004A32A0[2] > 0) { D_004A32A0[2]--; D_002021EC = n + 1; func_00131600(0x6A, m->pad_e); } break;
            case 3: if (D_004A32A0[3] > 0) { D_004A32A0[3]--; D_002021EC = n + 1; func_00131600(0x6A, m->pad_e); } break;
            case 4: if (D_004A32A0[4] > 0) { D_004A32A0[4]--; D_002021EC = n + 1; func_00131600(0x6A, m->pad_e); } break;
            case 5: if (D_004A32A0[5] > 0) { D_004A32A0[5]--; D_002021EC = n + 1; func_00131600(0x6A, m->pad_e); } break;
            case 6: if (D_004A32A0[6] > 0) { D_004A32A0[6]--; D_002021EC = n + 1; func_00131600(0x6A, m->pad_e); } break;
            case 7: if (D_004A32A0[7] > 0) { D_004A32A0[7]--; D_002021EC = n + 1; func_00131600(0x6A, m->pad_e); } break;
            }
        }
    } else if (m->buttons & 0x2000) {
        if (D_002021EC == 0) {
            func_001CB980(D_004A32A0);
            memset(D_004A32A0, 0, 0x10);
            func_001CEDC0(3);
            func_001CEA50(1);
            D_004A3298[0] = 15.0f;
            D_004A329C[0].b0 = 0;
            D_004A3294[0] = 1;
            func_001CBED0(D_00201D68[D_004A3290[0]], -1, -1);
            func_0019DCF0();
            func_00131600(0x67, m->pad_e);
        } else {
            func_00131600(0x68, m->pad_e);
        }
    } else if (m->buttons & 0x4000) {
        D_002021E8 = 0;
        func_00131600(0x68, m->pad_e);
    }
    m->buttons = 0;
}
#undef D_004A329C

/* func_0019DA70 */
#define func_0017F470 func_0017F470__as_func_0019DA70
s32 func_0017F470__as_func_0019DA70(s32, s32, f32);
#define D_004A329C D_004A329C__as_func_0019DA70
extern BF D_004A329C__as_func_0019DA70[];
#define D_004A32A0 D_004A32A0__as_func_0019DA70
extern u8 D_004A32A0__as_func_0019DA70[];

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
#undef func_0017F470
#undef D_004A329C
#undef D_004A32A0

/* func_0019DCF0 */
static inline s32 is5(s32 id) {
    E_func_0019DCF0 *e = &func_001AFC90()[id];
    if (e->xA == 0 && e->x29 == 5) return 1;
    return 0;
}

void func_0019DCF0(void) {
    s32 i;
    E_func_0019DCF0 *t;
    C *c;
    t = func_001AFC90();
    D_002021F8 = 0;
    memset(D_00201D68, -1, 0x1000);
    for (i = 0; i < 0x400; i++) {
        c = func_001CC3F0(func_00195BE0(i));
        if (c->x2 > 0 || (is5(func_00195BE0(i)) && c->x3 > 0)) {
            if (t[func_00195BE0(i)].xA == 0) {
                D_00201D68[D_002021F8] = func_00195BE0(i);
                D_002021F8++;
            }
        }
    }
}

/* func_0019DE30 */
#define func_001AFC90 func_001AFC90__as_func_0019DE30
E_func_0019DE30 *func_001AFC90__as_func_0019DE30(s32 i);

s32 func_0019DE30(s32 i)
{
    E_func_0019DE30 *e = func_001AFC90(i);
    E_func_0019DE30 *p = &e[i];
    if (p->h == 0 && p->b == 5)
        return 1;
    return 0;
}
#undef func_001AFC90

/* func_0019DE90 */
void func_0019DE90(s32 i, s8 *a1, s8 *a2) {
    s32 t;
    f32 f;
    func_0017F840(1, &t);
    switch (D_002021F4) {
    case 0:
        *(f32 *)(a1 + 0x14) = *(f32 *)(a2 + 8) - (f32)i;
        break;
    case 2:
        if (i >= D_004A3290[0] - 3 && i <= D_004A3290[0] + 3) {
            f = *(f32 *)(a2 + 8) - (f32)i;
            D_00201D6C[i] = f;
            *(f32 *)(a1 + 0x14) = f;
        } else {
            D_00201D6C[i] = -5.0f;
            *(f32 *)(a1 + 0x14) = -5.0f;
        }
        break;
    }
}
