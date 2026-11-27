#include "m2c.h"
#include "common.h"
typedef union { u128 q; f32 f[4]; } Q;
typedef struct { s32 idx; u8 pad4[0x28]; f32 f2C; f32 f30; u8 pad34[0xC]; } Item_func_0017EDC0;
typedef struct { u32 n; Item_func_0017EDC0 *items; } List_func_0017EDC0;
typedef struct { u8 pad[0x10]; List_func_0017EDC0 *list; } Res_func_0017EDC0;
typedef struct { s32 idx; u8 pad4[0x28]; f32 f2C; u8 pad30[0x10]; } Item_func_0017F0D0;
typedef struct { u32 n; Item_func_0017F0D0 *items; } List_func_0017F0D0;
typedef struct { u8 pad[0x10]; List_func_0017F0D0 *list; } Res_func_0017F0D0;
typedef struct { char p0[0x28]; f32 x28; char p2c[0x14]; f32 x40; char p44[4]; u8 b48; char p49[3]; } E_func_0017F3D0;
typedef struct { u8 b0:1; u8 b1:1; u8 st:4; u8 b6:2; } BF;
typedef struct { u8 pad[0x28]; f32 b8; u8 pad2[0x14]; f32 d0; f32 d4; BF bf; u8 pad3[3]; } E_func_0017F470;
typedef struct Node { s32 key; s32 x4; struct Node *val; } Node;
typedef struct Obj_func_0017F650 { s32 x0; s32 x4; s32 x8; s32 xC; s32 x10; f32 x14; Node *x18; } Obj_func_0017F650;
typedef struct Desc Desc;
typedef struct { u8 b0 : 1; u8 b1 : 1; u8 b2 : 4; u8 b6 : 2; } B;
typedef struct { char p[0x48]; B b; char q[3]; } E_func_0017F7C0;
typedef struct { char b[0x4C]; } E_func_0017F840;
typedef struct { f32 v[8]; } M8;
typedef struct { M8 a; M8 b; f32 c; u8 pad[0x4C - 0x44]; } E_func_0017F890;
typedef union { u32 w; u8 b[4]; } C4;
typedef struct { s32 idx; s32 id; u8 pad8[0x24]; f32 f2C; f32 f30; u8 pad34[8]; C4 c; } Item_func_0017F990;
typedef struct { u32 n; Item_func_0017F990 *items; } List_func_0017F990;
typedef struct { f32 t; s32 id; } Key;
typedef struct { s32 x0; s32 id; } Obj_func_0017F990;
typedef struct { s32 res; s32 lst; s32 item; Key *keys; s32 n; f32 t; Obj_func_0017F990 *obj; void (*fn)(); } Anim;
typedef struct { s32 pad[3]; s32 f0C; s32 f10[7]; s32 pad2[1]; } St;
typedef struct { f32 m[4]; f32 x; f32 y; } S;
typedef struct { u8 r; u8 g; u8 b; u8 a; } Col;
typedef struct { u8 pad[0x6C]; s8 *p; } O;
extern Q D_001F25E0[];
extern f32 D_0020205C;
extern s32 D_00486980[];
extern f32 D_00486984[];
extern f32 D_00486988[];
extern Q D_001F25D0[];
extern f32 D_00202058;
extern E_func_0017F3D0 D_00486990[];
extern s8 D_00222AF0[];
extern s32 D_0020203C;
extern s32 D_00202048;
extern s32 D_0020204C;
extern s32 D_00202040;
extern s32 D_00202044;
extern s32 D_00201CC8;
extern s32 D_00201CCC;
extern S D_001F25B0[] __attribute__((aligned(16)));
extern f32 D_00202054;
extern f32 D_00202050;
void func_0017EDC0(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);
void func_0017F0D0(s32 a0, s32 a1, s32 a2, s32 a3);
s32 func_0017F3D0(s32 i);
s32 func_0017F470(s32 arg0, s32 arg1, f32 val);
void func_0017F5C0(void);
void func_0017F650(Obj_func_0017F650 *o, Desc *d);
void func_0017F7C0(s32 i, s32 on, s32 f);
void func_0017F840(s32 i, E_func_0017F840 **out);
void func_0017F890(s32 arg0, M8 *a1, M8 *a2);
void func_0017F990(Anim *s);
void func_0017FF70(s32 arg0);
s32 func_00180110(void);
s32 func_001801F0(s32 arg0);
void func_001803B0(s32 arg0, s32 arg1);
void func_001803C0(s32 arg0, s32 arg1);
void func_001803D0(s32 arg0, s32 arg1);
void func_001803E0(s8 *o, s32 unused, u32 id, s32 up);
void func_001805D0(f32 *arg0, s32 arg1, s32 arg2, s32 arg3);
Res_func_0017EDC0* func_00189050(s32);
s32 func_00189020(s32);
f32 sinf(f32);
void func_00187B20(s32);
void func_001829B0(Item_func_0017EDC0 *, s32, void (*)(), s32);
f32 fabsf(f32);
void func_00180CA0(void);
void func_00155900(void);
void func_00154AF0(void);
void func_00176A40(void);
void func_00155370(void);
void func_001552A0(void);
void func_00154B70(void);
void func_00153D80(void);
s32 func_001A9480(void);
void func_001D7FD0(void);
void DisableIntc(s32);
s32* func_001288C0(s8 *, u32);
void func_001ED5D0(s32, s32, s32, s32);
void func_001ED0C0(s32, s32, s32, void (*)(void), s32, s32, s32, s32);
void func_00180F10(void);
void EnableIntc(s32);
void func_00128580(s8 *, s32 *);
void func_001D7EC0(void);
void func_001558F0(void);
void func_00176A60(void);
void func_00154700(s32, s32);
void func_001545D0(void);
void func_001543E0(s32, s64);
void func_001544C0(void);
s32 func_001E82A0(s32);
s32 func_001E6110(void);
void func_001E5E80(St *);
s32 func_001E5F30(s32, s32);
void func_001E6080(s32 *);
s32 func_001E8290(void);
void func_00181680(s32, s8 *, s8 *, void *, S *, s32);
void func_00182080(f32, s32, f32 *, s8 *, s32 *, s32);

/* func_0017EDC0 */

void func_0017EDC0(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    Item_func_0017EDC0 it;
    Q v;
    s32 base;
    u32 i;
    List_func_0017EDC0 *l;
    f32 t;
    f32 d;

    l = func_00189050(5)->list;
    base = func_00189020(5);
    if (a0) {
        t = 1.0f;
    } else {
        D_00486980[0] = 0;
        t = 0.0f;
        D_00486988[0] = 0.0f;
        D_00486984[0] = 0.0f;
    }
    d = 0.25f * (t - D_0020205C);
    D_00486980[0] += 5;
    D_00486980[0] %= 180;
    D_00486984[0] = 10.0f * sinf(3.1415927f * D_00486980[0] / 180.0f);
    D_00486988[0] = -10.0f * sinf(3.1415927f * D_00486980[0] / 180.0f);
    func_00187B20(0);
    for (i = 0; i < l->n; i++) {
        it = l->items[i];
        it.f2C -= 80.0f * (1.0f - D_0020205C);
        it.f30 = 166.0f;
        func_001829B0(&it, base + l->items[i].idx * 8, func_001803E0, a1);
    }
    v = D_001F25E0[0];
    v.f[0] -= 80.0f * (1.0f - D_0020205C);
    v.f[2] -= 80.0f * (1.0f - D_0020205C);
    func_001805D0(&v, a2, a3, a4);
    D_0020205C += d;
    if (D_0020205C > 1.0f) {
        D_0020205C = 1.0f;
    }
    if (D_0020205C < 0.0f) {
        D_0020205C = 0.0f;
    }
}

/* func_0017F0D0 */

void func_0017F0D0(s32 a0, s32 a1, s32 a2, s32 a3) {
    Item_func_0017F0D0 it;
    Q v;
    s32 base;
    u32 i;
    List_func_0017F0D0 *l;
    f32 t;
    f32 d;

    l = func_00189050(5)->list;
    base = func_00189020(5);
    if (a0) {
        t = 1.0f;
    } else {
        D_00486980[0] = 0;
        t = 0.0f;
        D_00486988[0] = 0.0f;
        D_00486984[0] = 0.0f;
    }
    d = 0.25f * (t - D_00202058);
    D_00486980[0] += 5;
    D_00486980[0] %= 180;
    D_00486984[0] = 10.0f * sinf(3.1415927f * D_00486980[0] / 180.0f);
    D_00486988[0] = -10.0f * sinf(3.1415927f * D_00486980[0] / 180.0f);
    func_00187B20(0);
    for (i = 0; i < l->n; i++) {
        it = l->items[i];
        it.f2C -= 80.0f * (1.0f - D_00202058);
        func_001829B0(&it, base + l->items[i].idx * 8, func_001803E0, 1);
    }
    v = D_001F25D0[0];
    v.f[0] -= 80.0f * (1.0f - D_00202058);
    v.f[2] -= 80.0f * (1.0f - D_00202058);
    func_001805D0(&v, a1, a2, a3);
    D_00202058 += d;
    if (D_00202058 > 1.0f) {
        D_00202058 = 1.0f;
    }
    if (D_00202058 < 0.0f) {
        D_00202058 = 0.0f;
    }
}

/* func_0017F3D0 */
s32 func_0017F3D0(s32 i) {
    s32 r = fabsf(D_00486990[i].x40 - D_00486990[i].x28) < 0.01f;
    if (r) { E_func_0017F3D0 *e = &D_00486990[i]; r = (e->b48 & 1) != 0; }
    return r;
}

/* func_0017F470 */
#define D_00486990 D_00486990__as_func_0017F470
extern E_func_0017F470 D_00486990__as_func_0017F470[];

s32 func_0017F470(s32 arg0, s32 arg1, f32 val) {
    s32 i = arg0 % 24;
    BF *p = &D_00486990[i].bf;
    if (p->st == 0) {
        D_00486990[i].d0 = val;
        D_00486990[i].d4 = 0.25f * (val - D_00486990[i].b8);
        p->b1 |= arg1 & 1;
        return 1;
    } else if (p->st == 3) {
        D_00486990[i].d0 = val;
        D_00486990[i].d4 = 0.25f * (val - D_00486990[i].b8);
        p->b1 |= arg1 & 1;
        return 0;
    }
    return 0;
}
#undef D_00486990

/* func_0017F5C0 */

void func_0017F5C0(void) {
    s32 (*temp_2)(s32);
    s32 var_17;
    u8 *var_16;

    var_17 = 0;
    var_16 = D_00486990;
    do {
        if (M2C_FIELD(var_16, u8 *, 0x48) & 1) {
            temp_2 = M2C_FIELD(var_16, s32 (**)(s32), 0x34);
            if (temp_2 != NULL) {
                temp_2(var_17);
            } else {
                func_00180810(var_17);
            }
            func_0017F650(var_16, var_16 + 0x20);
        }
        var_17 += 1;
        var_16 += 0x4C;
    } while (var_17 < 0x18);
}

/* func_0017F650 */
struct Desc {
    s32 *list;
    s32 n;
    f32 x8;
    Node *(*get)(s32);
    s32 (*f10)(s32);
    s32 x14;
    void (*f18)(s32, Obj_func_0017F650 *, Desc *);
};

void func_0017F650(Obj_func_0017F650 *o, Desc *d) {
    Node *old;
    s32 i;
    s32 key;
    s32 off;
    Node n;
    Node *np;
    Node **pv;

    if (o == NULL || d == NULL) {
        return;
    }
    old = o->x18;
    i = 0;
    if (i < d->n) {
        off = 0;
        pv = &n.val;
        np = &n;
        do {
            if (d->get != NULL) {
                if (d->list == NULL) {
                    goto next;
                }
                key = *(s32 *)((s8 *)d->list + off);
                *pv = d->get(key);
                n.key = key;
                if (*pv == NULL) {
                    goto next;
                }
                o->x18 = np;
            } else {
                *pv = old;
                o->x18 = np;
            }
            if (d->f10 != NULL) {
                if (d->list == NULL) {
                    goto next;
                }
                o->x8 = d->f10(*(s32 *)((s8 *)d->list + off));
            }
            if (d->f18 != NULL) {
                d->f18(i, o, d);
            } else {
                o->x14 = d->x8 - (f32)i;
            }
            func_0017F990(o);
        next:
            i++;
            off += 4;
        } while (i < d->n);
    }
}

/* func_0017F7C0 */
#define D_00486990 D_00486990__as_func_0017F7C0
extern E_func_0017F7C0 D_00486990__as_func_0017F7C0[24];
void func_0017F7C0(s32 i, s32 on, s32 f) {
    B *b;
    i %= 24;
    b = &D_00486990[i].b;
    b->b0 = on & 1;
    if (f) b->b2 = 3;
}
#undef D_00486990

/* func_0017F840 */

void func_0017F840(s32 i, E_func_0017F840 **out)
{
    i %= 24;
    if (out)
        *out = &D_00486990[i];
}

/* func_0017F890 */
#define D_00486990 D_00486990__as_func_0017F890
extern E_func_0017F890 D_00486990__as_func_0017F890[];

void func_0017F890(s32 arg0, M8 *a1, M8 *a2) {
    arg0 %= 24;
    if (a1 != NULL) {
        D_00486990[arg0].a = *a1;
    }
    if (a2 != NULL) {
        D_00486990[arg0].b = *a2;
        D_00486990[arg0].c = a2->v[2];
    }
}
#undef D_00486990

/* func_0017F990 */
#define func_00189050 func_00189050__as_func_0017F990
List_func_0017F990 **func_00189050__as_func_0017F990(s32);
#define func_001829B0 func_001829B0__as_func_0017F990
void func_001829B0__as_func_0017F990(Item_func_0017F990 *, s32, void (*)(), Obj_func_0017F990 *);
static inline f32 mu(u32 x, f32 k) { f32 f = x; return f * k; }

void func_0017F990(Anim *s) {
    Item_func_0017F990 it;
    C4 c;
    List_func_0017F990 *l;
    s32 base;
    f32 t;
    s32 n;
    Key *keys;
    s32 i;
    s32 hi;
    s32 lo;
    f32 f;
    Item_func_0017F990 *pB;
    Item_func_0017F990 *pA;
    Obj_func_0017F990 *o;

    if (s == 0) return;
    l = func_00189050(s->res)[s->lst];
    base = func_00189020(s->res);
    keys = s->keys;
    t = s->t;
    n = s->n;
    if (l == 0 || base == 0 || keys == 0 || n == 0) return;
    if (t < keys[0].t) return;
    if (keys[n - 1].t < t) return;
    for (i = 0; i < n - 1; i++) {
        if (keys[i].t <= t && t <= keys[i + 1].t) {
            lo = i;
            hi = i + 1;
            break;
        }
    }
    f = (t - keys[lo].t) / (keys[hi].t - keys[lo].t);
    lo = keys[lo].id;
    hi = keys[hi].id;
    pA = 0;
    pB = 0;
    for (i = 0; i < l->n; i++) {
        if (hi == l->items[i].id) pB = &l->items[i];
        if (lo == l->items[i].id) pA = &l->items[i];
    }
    if (pB == 0 || pA == 0) return;
    o = s->obj;
    o->id = f < 0.5f ? lo : (lo = hi);
    it = l->items[s->item];
    it.f2C = pB->f2C * f + pA->f2C * (1.0f - f);
    it.f30 = pB->f30 * f + pA->f30 * (1.0f - f);
    c.b[0] = mu(pB->c.b[0], f) + mu(pA->c.b[0], (1.0f - f));
    c.b[1] = mu(pB->c.b[1], f) + mu(pA->c.b[1], (1.0f - f));
    c.b[2] = mu(pB->c.b[2], f) + mu(pA->c.b[2], (1.0f - f));
    c.b[3] = mu(pB->c.b[3], f) + mu(pA->c.b[3], (1.0f - f));
    if (c.b[0] == 0x7F) c.b[0] = 0x80;
    if (c.b[1] == 0x7F) c.b[1] = 0x80;
    if (c.b[2] == 0x7F) c.b[2] = 0x80;
    if (c.b[3] == 0x7F) c.b[3] = 0x80;
    it.c = c;
    if (s->fn == 0) {
        func_001829B0(&it, base + it.idx * 8, func_00180CA0, s->obj);
    } else {
        func_001829B0(&it, base + it.idx * 8, s->fn, s->obj);
    }
}
#undef func_00189050
#undef func_001829B0

/* func_0017FF70 */
void func_0017FF70(s32 arg0) {
    s32 *blk;
    s32 vol;

    func_00155900();
    func_00154AF0();
    func_00176A40();
    func_00155370();
    func_001552A0();
    func_00154B70();
    func_00153D80();
    func_00154AF0();
    func_00155370();
    func_001552A0();
    vol = (func_001A9480() & 0xFF) * 2;
    if (vol > 0x7F) {
        vol = 0x7F;
    }
    func_001D7FD0();
    DisableIntc(9);
    blk = func_001288C0(D_00222AF0, 0xA00000);
    func_001ED5D0(0, 0, 0, 0x1E);
    func_001ED0C0(arg0, *blk, 0xA00000, func_00180F10, vol * 129, 2, 0, 0);
    EnableIntc(9);
    func_00128580(D_00222AF0, blk);
    func_001D7EC0();
    func_001558F0();
    func_00154B70();
    func_00176A60();
    func_00154700(5, -2);
    func_001545D0();
    func_001543E0(0x40, 0x027F0000 | ((s64)0x01BF0000 << 32));
    func_001543E0(0x41, 0x027F0000 | ((s64)0x01BF0000 << 32));
    func_001543E0(0x49, 0);
    func_001544C0();
}

/* func_00180110 */
s32 func_00180110(void) {
    s32 r = 0;
    func_001E82A0(0);
    switch (func_001E6110()) {
    case 1: r &= ~0xF; break;
    case 0: r |= 3; break;
    case 2: r |= 1; break;
    }
    func_001E82A0(1);
    switch (func_001E6110()) {
    case 1: r &= ~0xF0; break;
    case 0: r |= 0x30; break;
    case 2: r |= 0x10; break;
    }
    return r;
}

/* func_001801F0 */
s32 func_001801F0(s32 arg0) {
    s32 s;
    St st = {0};
    s32 r;

    r = -1;
    switch (D_0020203C) {
    case 0:
        if (func_001E82A0(arg0) != 0) {
            D_0020203C++;
        } else {
            r = 0;
            break;
        }
    case 1:
        if (func_001E5F30(0, 0) == 0) {
            r = 0;
            D_0020203C++;
        } else {
            D_0020203C = 0;
        }
        break;
    case 2:
        if (arg0 != func_001E8290()) {
            D_0020203C = 0;
            break;
        }
        func_001E6080(&s);
        if (s == 2) {
            r = 0;
        } else if (s == 0) {
            func_001E5E80(&st);
            if (st.f10[0] != 0 || st.f10[1] != 0 || st.f10[2] != 0 || st.f10[3] != 0 || st.f10[4] != 0 ||
                st.f10[5] != 0 || st.f10[6] != 0) {
                r = 2;
            } else {
                r = 1;
            }
            if (st.f0C == 1) {
                r |= 4;
            }
            D_0020203C = 0;
} else {
            D_0020203C = 0;
            r = 0x40000000;
        }
        break;
    default:
        D_0020203C = 0;
        break;
    }
    return r;
}

/* func_001803B0 */
void func_001803B0(s32 arg0, s32 arg1) {
    D_00202048 = arg0;
    D_0020204C = arg1;
}

/* func_001803C0 */
void func_001803C0(s32 arg0, s32 arg1) {
    D_00202040 = arg0;
    D_00202044 = arg1;
}

/* func_001803D0 */
void func_001803D0(s32 arg0, s32 arg1) {
    D_00201CC8 = arg0;
    D_00201CCC = arg1;
}

/* func_001803E0 */

void func_001803E0(s8 *o, s32 unused, u32 id, s32 up) {
    S t __attribute__((aligned(16)));
    Col col;
    s8 *p;

    t = D_001F25B0[0];
    col.b = 0x80;
    col.g = 0x80;
    col.r = 0x80;
    col.a = 0x40;
    if (id < 200) {
        t.x = *(f32 *)(o + 0x30);
        t.y = *(f32 *)(o + 0x34);
        func_00181680(*(s32 *)(o + 0x28), o, o + 0x10, o + 0x2C, &t, id);
        return;
    }
    if (up) {
        D_00202054 += 4.0f;
        if (!(D_00202054 <= 64.0f)) {
            D_00202054 = 64.0f;
        }
    } else {
        D_00202054 -= 4.0f;
        if (D_00202054 < 0.0f) {
            D_00202054 = 0.0f;
        }
    }
    col.a = D_00202054;
    switch (id) {
    case 200:
        p = *(s8 **)(func_00189020(0) + 0x8C) + 0x30;
        t.x = *(f32 *)(o + 0x38);
        t.y = *(f32 *)(o + 0x3C) + D_00486988[0];
        func_00181680(*(s32 *)(p + 4), p + 0x10, p + 0x20, &col, &t, 1);
        break;
    case 201:
        p = *(s8 **)(func_00189020(0) + 0x8C);
        t.x = *(f32 *)(o + 0x38);
        t.y = *(f32 *)(o + 0x3C) + D_00486984[0];
        func_00181680(*(s32 *)(p + 4), p + 0x10, p + 0x20, &col, &t, 1);
        break;
    }
}

/* func_001805D0 */
#define func_00189020 func_00189020__as_func_001805D0
O *func_00189020__as_func_001805D0(s32);

void func_001805D0(f32 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 col;
    f32 c[4];
    f32 b[4];
    f32 a[4];
    f32 inv, h, step, d;
    O *s0;
    s32 n;

    s0 = func_00189020(0);
    col = 0x80404040;
    inv = 1.0f / (f32)(arg2 - (arg1 - 1));
    d = arg0[3] - arg0[1];
    h = inv * d;
    if (arg1 == arg2) {
        D_00202050 = 0.0f;
    } else {
        step = h;
        if (h < 10.0f) {
            step = inv * (d - 10.0f);
            h = 10.0f;
        }
        if (arg2 < arg3 + arg1) {
            D_00202050 = step * (f32)(arg2 - arg1);
        } else {
            if (arg3 < 0) arg3 = 0;
            D_00202050 = (f32)arg3 * step;
        }
    }
    b[0] = arg0[0];
    b[1] = (f32)(s32)D_00202050 + arg0[1];
    b[2] = arg0[2];
    b[3] = 4.0f + ((f32)(s32)D_00202050 + arg0[1]);
    c[0] = arg0[0];
    c[1] = 4.0f + ((f32)(s32)D_00202050 + arg0[1]);
    c[2] = arg0[2];
    c[3] = (f32)(s32)h + ((f32)(s32)D_00202050 + arg0[1]);
    a[0] = arg0[0];
    a[1] = (f32)(s32)h + ((f32)(s32)D_00202050 + arg0[1]);
    a[2] = arg0[2];
    a[3] = (f32)(s32)h + (4.0f + ((f32)(s32)D_00202050 + arg0[1]));
    func_00187B20(0);
    n = M2C_FIELD(s0->p, s32 *, 4);
    func_00182080(0.0f, n, b, s0->p + 0x20, &col, 0);
    func_00182080(0.0f, n, c, s0->p + 0x50, &col, 0);
    func_00182080(0.0f, n, a, s0->p + 0x80, &col, 0);
}
#undef func_00189020
