#include "m2c.h"
#include "common.h"
typedef union {
    u32 w;
    struct { u8 r, g, b, a; } c;
} Col;
typedef struct {
    s32 id;
    s32 off;
} Ent1952B0;
typedef struct {
    s32 x0;
    u32 n;
    u8 pad8[8];
    Ent1952B0 e[1];
} Pack1952B0;
typedef struct {
    u8 pad0[8];
    u8 x8;
} Obj1952B0;
typedef struct { u128 q[2]; } Q2;
typedef struct { s32 p; s32 n; f32 f; void *fn; s32 a; s32 b; void *cb; } Arg;
typedef struct { s32 id; s32 o1; s32 o2; } Ent_func_00195460;
typedef struct { s32 x0; u32 n; s32 x8; s32 xC; Ent_func_00195460 e[1]; } Tbl_func_00195460;
typedef struct { s32 x0; s32 x4; u8 x8; u8 pad9[5]; u8 xE; } Ev;
typedef struct { s32 id; char p[0x2C]; } E_func_00195770;
typedef struct { char p0[4]; u32 n; char p8[8]; E_func_00195770 e[1]; } T_func_00195770;
typedef struct { s32 id; s32 o1; s32 o2; } Ent_func_001957E0;
typedef struct { s32 x0; u32 n; s32 x8; s32 xC; Ent_func_001957E0 e[1]; } Tbl_func_001957E0;
typedef struct { s32 id; s32 o1; s32 o2; } Ent_func_00195840;
typedef struct { s32 x0; u32 n; s32 x8; s32 xC; Ent_func_00195840 e[1]; } Tbl_func_00195840;
typedef struct { s32 id; s32 x4; s32 off; } Ent_func_00195900;
typedef struct { s32 x0; u32 n; s32 x8; s32 xC; Ent_func_00195900 e[1]; } Hdr;
typedef struct { s32 id; s32 o1; s32 o2; } Ent_func_00195970;
typedef struct { s32 x0; u32 n; s32 x8; s32 xC; Ent_func_00195970 e[1]; } Tbl_func_00195970;
typedef struct { s16 v; s16 id; } E_func_001959E0;
typedef struct { s32 id; s32 o1; s32 o2; } Ent_func_00195A30;
typedef struct { s32 x0; u32 n; s32 x8; s32 xC; Ent_func_00195A30 e[1]; } Tbl_func_00195A30;
typedef struct { s32 id; s32 o1; s32 o2; } Ent_func_00195AA0;
typedef struct { s32 x0; u32 n; s32 x8; s32 xC; Ent_func_00195AA0 e[1]; } Tbl_func_00195AA0;
typedef struct { s32 id; s32 off; } E_func_00195B10;
typedef struct { char p0[4]; u32 n; char p8[8]; E_func_00195B10 e[1]; } T_func_00195B10;
typedef struct { s16 n; s8 v[14]; } E_func_00195B80;
extern f32 D_00201D30;
extern s32 D_00202154;
extern Pack1952B0 **D_00202180;
extern u8 D_001FD270[];
extern u8 D_001FD288[];
extern Q2 D_001F2E40;
extern s32 D_001F2E60[];
extern s8 D_001FD268[];
extern s8 *D_00201D28;
extern s8 *D_00201D2C;
extern u8 D_00201D20[4];
extern Tbl_func_00195460 *D_0020215C;
extern u32 D_002022B8;
extern T_func_00195770 **D_00202168;
extern s32 *D_00202160;
extern s32 *D_00202164;
extern E_func_001959E0 **D_0020216C;
extern E_func_00195B80 *D_0020217C;
extern s16 *D_00202174;
extern s8 D_001FD290[];
extern s8 D_001FD2A0[];
extern s8 D_001FD2B0[];
extern s8 D_001FD2C0[];
extern s8 D_001FD2D0[];
extern s8 D_001FD2E0[];
extern s8 D_001FD2F0[];
extern s8 D_001FD310[];
extern s8 * volatile D_00202158;
extern s32 *D_00202170;
extern s32 *D_00202178;
extern f32 *D_00201D24;
void func_001952B0(Obj1952B0 *o);
void func_00195410(s32 arg0);
s32 func_00195420(s32 i);
void func_00195460(Ev *arg0);
E_func_00195770* func_00195770(s32 id);
s8* func_001957E0(Tbl_func_001957E0 *t, s32 id);
s8* func_00195840(Tbl_func_00195840 *t, s32 id);
s32 func_001958A0(void);
s32 func_001958C0(void);
s32 func_001958E0(void);
s32* func_00195900(s32 id);
s8* func_00195970(s32 id);
s32 func_001959E0(s32 id);
s8* func_00195A30(s32 id);
s8* func_00195AA0(s32 id);
void* func_00195B10(s32 id);
s8 func_00195B80(s32 i, s32 *p);
s16 func_00195BE0(s32 i);
void func_00195C00(s8 *arg0);
void func_00195D80(s32 i, f32 *a1, f32 *a2);
void func_0018A310(s32);
void func_0017F5C0(void);
void func_00185390(f32, s32, s32, s32);
void func_001875C0(f32, s32, f32, f32, u32, u32);
f32 func_00187770(f32, f32, f32);
void func_0017F890(s32, Q2 *, Arg *);
void func_0017F7C0(s32, s32, s32);
s32 func_0017F470(f32, s32, s32);
void func_00131600(s32, u8);
s8* func_00159D10(s8 *);
void func_00159DD0(s8 *, s8 *, void *, void *);
void func_0017F840(s32, s32 *);

/* func_001952B0 */
static inline s8 *find(s32 id) {
    u32 i;
    Ent1952B0 *e;
    Pack1952B0 *p;
    p = *D_00202180;
    if (p == NULL) {
        return NULL;
    }
    for (e = p->e, i = 0; i < p->n; i++, e++) {
        if (e->id == id) {
            return (s8 *)p + e->off;
        }
    }
    return NULL;
}

void func_001952B0(Obj1952B0 *o) {
    Col col;

    func_0018A310(4);
    if (o->x8 == 0x18) {
        D_00201D30 = func_00187770(D_00201D30, -0.02f, 3.5f);
    } else {
        D_00201D30 = func_00187770(D_00201D30, -2.99f, 3.5f);
    }
    if (!(D_00201D30 <= -2.99f)) {
        col.w = 0x80FFFFFF;
        if (D_00202154 >= 0) {
            func_001875C0(622.0f, (s32)find(D_00202154 + 0x1E), 17.0f, 1.0f, 2, *(u32 *)&col);
        }
        func_0017F5C0();
    }
    func_00185390(D_00201D30, 1, 3, D_00202154);
}

/* func_00195410 */
void func_00195410(s32 arg0) {
    func_00195460((void *) arg0);
}

/* func_00195420 */
#pragma explicit_zero_data on
const u8 D_001FD278[0x9] = "CREATURE\000";
s32 D_001F2E70[0x4] = { (s32)D_001FD270, (s32)D_001FD278, (s32)D_001FD288 };
s32 func_00195420(s32 i)
{
    if (i < 0 || i > 3)
        return 0;
    return D_001F2E70[i];
}

/* func_00195460 */
#define func_00195420 func_00195420__as_func_00195460
void func_00195420__as_func_00195460(void);
#define func_00195D80 func_00195D80__as_func_00195460
void func_00195D80__as_func_00195460(void);
static inline Tbl_func_00195460 *get_func_00195460(void) {
    if (D_0020215C != NULL) {
        return (Tbl_func_00195460 *)D_0020215C->x0;
    }
    return 0;
}
static inline s8 *find1_func_00195460(Tbl_func_00195460 *t, s32 id) {
    Ent_func_00195460 *e;
    u32 i;
    if (t == 0) {
        return D_001FD268;
    }
    e = t->e;
    for (i = 0; i < t->n; i++, e++) {
        if (e->id == id) {
            return (s8 *)t + e->o1;
        }
    }
    return D_001FD268;
}
static inline s8 *find2_func_00195460(Tbl_func_00195460 *t, s32 id) {
    Ent_func_00195460 *e;
    u32 i;
    if (t == 0) {
        return D_001FD268;
    }
    e = t->e;
    for (i = 0; i < t->n; i++, e++) {
        if (e->id == id) {
            return (s8 *)t + e->o2;
        }
    }
    return D_001FD268;
}

void func_00195460(Ev *arg0) {
    Q2 q;
    Arg a;
    s32 n;
    s32 k;
    Tbl_func_00195460 *t;
    u32 id;

    if (arg0->x0 == 0x19) {
        id = D_002022B8 / 10;
        t = get_func_00195460();
        if (t != 0) {
            D_00201D28 = find1_func_00195460(t, id);
            D_00201D2C = find2_func_00195460(t, id);
            D_00202154 = 0;
            q = D_001F2E40;
            a.p = (s32)D_001F2E60;
            a.n = 3;
            a.fn = func_00195420;
            a.f = -3.0f;
            a.cb = func_00195D80;
            a.a = 0;
            a.b = 0;
            func_0017F890(3, &q, &a);
            func_0017F7C0(3, 1, 1);
            func_0017F470(D_00202154, 3, 1);
        }
    }
    if (arg0->x0 == 0x16) {
        n = D_00202154;
        k = n;
        if (arg0->x4 & 0x2000) {
            func_0017F7C0(3, 0, 1);
            arg0->x4 &= ~0x2000;
            arg0->x8 = D_00201D20[n];
            arg0->x4 = 0;
            arg0->x0 = 0x1F;
            func_00131600(0x69, arg0->xE);
        } else if (arg0->x4 & 0x4000) {
            func_0017F7C0(3, 0, 1);
            arg0->x8 = 0x14;
            arg0->x4 = 0;
            arg0->x0 = 0x1F;
            func_00131600(0x69, arg0->xE);
        } else {
            if (arg0->x4 & 0x10) {
                k = n - 1;
            } else if (arg0->x4 & 0x40) {
                k = n + 1;
            }
            k = (k + 3) % 3;
            if (func_0017F470(n, 3, 0)) {
                if (k != D_00202154) {
                    func_00131600(0x66, arg0->xE);
                }
                D_00202154 = k;
            }
        }
    }
}
#undef func_00195420
#undef func_00195D80

/* func_00195770 */
E_func_00195770 *func_00195770(s32 id)
{
    T_func_00195770 *t;
    E_func_00195770 *e;
    u32 i;
    if (!D_00202168)
        return NULL;
    t = *D_00202168;
    e = t->e;
    for (i = 0; i < t->n; i++, e++) {
        if (e->id == id)
            return e;
    }
    return NULL;
}

/* func_001957E0 */
s8 *func_001957E0(Tbl_func_001957E0 *t, s32 id) {
    Ent_func_001957E0 *e;
    u32 i;
    if (t == 0) {
        return D_001FD268;
    }
    e = t->e;
    for (i = 0; i < t->n; i++, e++) {
        if (e->id == id) {
            return (s8 *)t + e->o2;
        }
    }
    return D_001FD268;
}

/* func_00195840 */
#define D_0020215C D_0020215C__as_func_00195840
extern Tbl_func_00195840 *D_0020215C__as_func_00195840;
s8 *func_00195840(Tbl_func_00195840 *t, s32 id) {
    Ent_func_00195840 *e;
    u32 i;
    if (t == 0) {
        return D_001FD268;
    }
    e = t->e;
    for (i = 0; i < t->n; i++, e++) {
        if (e->id == id) {
            return (s8 *)t + e->o1;
        }
    }
    return D_001FD268;
}
#undef D_0020215C

/* func_001958A0 */
s32 func_001958A0(void) {
    if (D_00202160 != NULL) {
        return *D_00202160;
    }
    return 0;
}

/* func_001958C0 */
s32 func_001958C0(void) {
    if (D_00202164 != NULL) {
        return *D_00202164;
    }
    return 0;
}

/* func_001958E0 */
#define D_0020215C D_0020215C__as_func_001958E0
extern s32 *D_0020215C__as_func_001958E0;

s32 func_001958E0(void) {
    if (D_0020215C != NULL) {
        return *D_0020215C;
    }
    return 0;
}
#undef D_0020215C

/* func_00195900 */
#define D_001FD268 D_001FD268__as_func_00195900
extern s32 D_001FD268__as_func_00195900[];
static inline s32 get_func_00195900(void) {
    if (D_00202164 != NULL) {
        return *D_00202164;
    }
    return 0;
}
s32 *func_00195900(s32 id) {
    Hdr *h = (Hdr *)get_func_00195900();
    Ent_func_00195900 *e;
    u32 i;
    if (h == NULL) return D_001FD268;
    e = h->e;
    for (i = 0; i < h->n; i++, e++) {
        if (e->id == id) return (s32 *)((u8 *)h + e->off);
    }
    return D_001FD268;
}
#undef D_001FD268

/* func_00195970 */
#define D_00202164 D_00202164__as_func_00195970
extern Tbl_func_00195970 **D_00202164__as_func_00195970;
static inline Tbl_func_00195970 *get_func_00195970(void) {
    if (D_00202164 != NULL) {
        return *D_00202164;
    }
    return 0;
}
static inline s8 *find1_func_00195970(Tbl_func_00195970 *t, s32 id) {
    Ent_func_00195970 *e;
    u32 i;
    if (t == 0) {
        return D_001FD268;
    }
    e = t->e;
    for (i = 0; i < t->n; i++, e++) {
        if (e->id == id) {
            return (s8 *)t + e->o1;
        }
    }
    return D_001FD268;
}
s8 *func_00195970(s32 id) {
    return find1_func_00195970(get_func_00195970(), id);
}
#undef D_00202164

/* func_001959E0 */
s32 func_001959E0(s32 id) { s32 i; E_func_001959E0 *base = *D_0020216C; E_func_001959E0 *e = base; for (i = 0; i < 24; i++, e++) { if (id == e->id) return base[i].v; } return -1; }

/* func_00195A30 */
#define D_0020215C D_0020215C__as_func_00195A30
extern Tbl_func_00195A30 *D_0020215C__as_func_00195A30;
static inline Tbl_func_00195A30 *get_func_00195A30(void) {
    if (D_0020215C != NULL) {
        return (Tbl_func_00195A30 *)D_0020215C->x0;
    }
    return 0;
}
static inline s8 *find2_func_00195A30(Tbl_func_00195A30 *t, s32 id) {
    Ent_func_00195A30 *e;
    u32 i;
    if (t == 0) {
        return D_001FD268;
    }
    e = t->e;
    for (i = 0; i < t->n; i++, e++) {
        if (e->id == id) {
            return (s8 *)t + e->o2;
        }
    }
    return D_001FD268;
}
s8 *func_00195A30(s32 id) {
    return find2_func_00195A30(get_func_00195A30(), id);
}
#undef D_0020215C

/* func_00195AA0 */
#define D_0020215C D_0020215C__as_func_00195AA0
extern Tbl_func_00195AA0 *D_0020215C__as_func_00195AA0;
static inline Tbl_func_00195AA0 *get_func_00195AA0(void) {
    if (D_0020215C != NULL) {
        return (Tbl_func_00195AA0 *)D_0020215C->x0;
    }
    return 0;
}
static inline s8 *find1_func_00195AA0(Tbl_func_00195AA0 *t, s32 id) {
    Ent_func_00195AA0 *e;
    u32 i;
    if (t == 0) {
        return D_001FD268;
    }
    e = t->e;
    for (i = 0; i < t->n; i++, e++) {
        if (e->id == id) {
            return (s8 *)t + e->o1;
        }
    }
    return D_001FD268;
}
s8 *func_00195AA0(s32 id) {
    return find1_func_00195AA0(get_func_00195AA0(), id);
}
#undef D_0020215C

/* func_00195B10 */
#define D_00202180 D_00202180__as_func_00195B10
extern T_func_00195B10 **D_00202180__as_func_00195B10;

void *func_00195B10(s32 id)
{
    u32 i;
    E_func_00195B10 *e;
    T_func_00195B10 *t = *D_00202180;
    if (!t)
        return NULL;
    e = t->e;
    for (i = 0; i < t->n; i++, e++) {
        if (e->id == id)
            return (u8 *)t + e->off;
    }
    return NULL;
}
#undef D_00202180

/* func_00195B80 */
s8 func_00195B80(s32 i, s32 *p) {
    s32 k = *p;
    if (k < 0) k = D_0020217C[i].n - 1;
    if (k > D_0020217C[i].n - 1) k = 0;
    *p = k;
    return D_0020217C[i].v[k];
}

/* func_00195BE0 */
s16 func_00195BE0(s32 i)
{
    return D_00202174[i];
}

/* func_00195C00 */
#define D_0020215C D_0020215C__as_func_00195C00
extern s8 *D_0020215C__as_func_00195C00;
#define D_00202160 D_00202160__as_func_00195C00
extern s8 *D_00202160__as_func_00195C00;
#define D_00202164 D_00202164__as_func_00195C00
extern s8 *D_00202164__as_func_00195C00;
#define D_00202168 D_00202168__as_func_00195C00
extern s8 *D_00202168__as_func_00195C00;
#define D_0020216C D_0020216C__as_func_00195C00
extern s8 *D_0020216C__as_func_00195C00;
#define D_00202174 D_00202174__as_func_00195C00
extern s32 D_00202174__as_func_00195C00;
#define D_0020217C D_0020217C__as_func_00195C00
extern s32 D_0020217C__as_func_00195C00;
#define D_00202180 D_00202180__as_func_00195C00
extern s8 *D_00202180__as_func_00195C00;

void func_00195C00(s8 *arg0) {
    u32 sp1C;

    D_00202158 = arg0;
    if (D_0020215C == NULL) {
        func_00159DD0(func_00159D10(D_001FD290), D_00202158, &D_0020215C, &sp1C);
    }
    if (D_00202164 == NULL) {
        func_00159DD0(func_00159D10(D_001FD2A0), D_00202158, &D_00202164, &sp1C);
    }
    if (D_00202160 == NULL) {
        func_00159DD0(func_00159D10(D_001FD2B0), D_00202158, &D_00202160, &sp1C);
    }
    if (D_00202180 == NULL) {
        func_00159DD0(func_00159D10(D_001FD2C0), D_00202158, &D_00202180, &sp1C);
    }
    if (D_00202168 == NULL) {
        func_00159DD0(func_00159D10(D_001FD2D0), D_00202158, &D_00202168, &sp1C);
    }
    if (D_0020216C == NULL) {
        func_00159DD0(func_00159D10(D_001FD2E0), D_00202158, &D_0020216C, &sp1C);
    }
    if (D_00202170 == NULL) {
        func_00159DD0(func_00159D10(D_001FD2F0), D_00202158, &D_00202170, &sp1C);
        D_00202174 = *D_00202170;
    }
    if (D_00202178 == NULL) {
        func_00159DD0(func_00159D10(D_001FD310), D_00202158, &D_00202178, &sp1C);
        D_0020217C = *D_00202178;
    }
}
#undef D_0020215C
#undef D_00202160
#undef D_00202164
#undef D_00202168
#undef D_0020216C
#undef D_00202174
#undef D_0020217C
#undef D_00202180

/* func_00195D80 */
void func_00195D80(s32 i, f32 *a1, f32 *a2) { s32 sp; f32 f; func_0017F840(3, &sp);  if (i >= D_00202154 - 3 && i <= D_00202154 + 3) { f = a2[2] - (f32)i; D_00201D24[i] = f; a1[5] = f; return; } D_00201D24[i] = -5.0f; a1[5] = -5.0f; }
