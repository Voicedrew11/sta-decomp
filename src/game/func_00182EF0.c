#include "m2c.h"
#include "common.h"
typedef struct { f32 m[4]; f32 x; f32 y; } S_func_00182EF0;
typedef struct { u8 r; u8 g; u8 b; u8 a; } Col_func_00182EF0;
typedef struct { u8 pad[0x6C]; s8 *p; } O_func_00183090;
typedef struct 
{
  s32 a;
  s8 *b;
} S_func_001832D0 __attribute__((aligned(16)));
typedef struct { s32 first; s32 x; u8 b0:1; u8 b1:1; u8 b2:1; } O_func_001833E0;
typedef struct { s32 a; s8 *p; s32 b[2]; f32 f[8]; } Ent;
typedef struct { u8 b[0x100]; } Buf_func_001833E0;
typedef struct { u8 r, g, b, a; } Col_func_00183650;
typedef struct { s32 a; void *b; } Buf_func_00183650;
typedef struct { u8 b[256]; } Buf_func_00183750;
typedef struct { u8 a:1; u8 b:1; u8 c:1; } BF;
typedef struct { u8 b[256]; } Buf_func_00183970;
typedef struct {
    s32 x0;
    s32 x4;
    Flags8 f8;
} Res;
typedef struct { u8 b[256]; } Buf_func_00183DC0;
typedef struct { s32 idx; u8 pad[0x28]; f32 x, z; u8 pad2[0xC]; } Obj;
typedef struct { u32 n; Obj *e; } L;
typedef struct { u8 pad[0x14]; L *l; } R;
typedef struct { f32 x, z; } V2;
extern S_func_00182EF0 D_001F2770[] __attribute__((aligned(16)));
extern f32 D_002020A4;
extern f32 D_002020A0;
extern u8 D_0048D141[];
extern u8 D_0048D142[];
extern u8 D_0048D143[];
extern s8 D_0048D170[];
extern u8 D_001FC9C0[];
extern u8 D_001FC9D8[];
extern O_func_001833E0 *D_0048D110[];
extern Col_func_00183650 D_002020A8;
extern s32 D_0048D0E0[];
extern s32 D_0048D0E4[];
extern M2C_UNK D_001FC9F0[];
extern M2C_UNK D_001FCA08[];
extern s32 D_00201CDC;
extern s32 D_00201CE0;
extern s32 D_00201CE4;
extern s32 D_00201CE8;
extern s8 *D_002020AC;
extern s32 D_0048D0F0[];
extern s32 D_0048D0F4[];
extern s32 D_0048D0F8[];
extern s32 D_0048D0FC[];
extern s32 D_0048D100[];
extern s32 D_0048D104[];
extern s32 D_0048D108[];
extern s32 D_0048D10C[];
extern M2C_UNK D_001FCA10[];
extern M2C_UNK D_001FCA20[];
extern s8 D_001FCA30[];
extern s8 D_001FCA48[];
extern M2C_UNK D_001FCA60[];
extern M2C_UNK D_001FCA78[];
void func_00182EF0(s32 x0, s32 y0, s32 x1, s32 y1, f32 u0, f32 u1, f32 alpha);
void func_00183090(f32 *arg0, s32 arg1, s32 arg2, s32 arg3);
void func_001832D0(s8 *arg0, s32 arg1, s32 arg2);
void func_001833E0(s32 arg0, s32 arg1);
void func_00183650(s8 *arg0);
void func_00183750(s32 arg0);
void func_00183970(s32 arg0);
void func_00183B90(s32 id);
void func_00183DC0(s32 arg0);
s32 func_00183FF0(void);
void func_00184040(s32 a0, f32 ang);
f32 sinf(f32);
s8* func_00189020(s32);
void func_00181680(s32, s8 *, s8 *, void *, S_func_00182EF0 *, s32);
void func_00182080(f32, s32, f32 *, s8 *, s32 *, s32);
void func_00187B20(s32);
void func_00182C10(s8*, void *);
void sprintf(void *, void *, s32);
O_func_001833E0* func_001E1570(void *, s32);
void func_00177570(s8 *);
s8* func_00177AF0(s32, s32);
s32 func_00177F80(void *);
R* func_00189050(s32);
f32 atanf(f32);
f32 cosf(f32);
void func_001829B0(Obj *, u8 *, void *, s32);
void func_00184280(void);
f32 sqrtf(f32);

/* func_00182EF0 */
void func_00182EF0(s32 x0, s32 y0, s32 x1, s32 y1, f32 u0, f32 u1, f32 alpha) {
    S_func_00182EF0 t __attribute__((aligned(16)));
    Col_func_00182EF0 col;
    s8 *o;

    t = D_001F2770[0];
    o = *(s8 **)(func_00189020(0) + 0x84);
    col.r = 0x80;
    col.g = 0x80;
    col.b = 0x80;
    D_002020A4 += 0.1f;
    col.a = alpha / 2.0f;
    t.x = (f32)x0 + 6.0f * sinf(D_002020A4);
    t.y = (f32)y0;
    func_00181680(*(s32 *)(o + 4), o + 0x10, o + 0x20, &col, &t, 0);
    t.x = (f32)x1 - 6.0f * sinf(D_002020A4);
    t.y = (f32)y1;
    func_00181680(*(s32 *)(o + 4), o + 0x10, o + 0x20, &col, &t, 1);
}

/* func_00183090 */
#define func_00189020 func_00189020__as_func_00183090
O_func_00183090 *func_00189020__as_func_00183090(s32);

void func_00183090(f32 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 col;
    f32 c[4];
    f32 b[4];
    f32 a[4];
    f32 h, step, d;
    O_func_00183090 *s0;
    s32 n;

    s0 = func_00189020(0);
    col = 0x80404040;
    if (arg2 != 0) {
        d = arg0[3] - arg0[1];
        h = 1.0f / (f32)(arg2 - (arg1 - 1)); h *= d;
        if (arg1 == arg2) {
            D_002020A0 = 0.0f;
        } else {
            step = h;
            if (h < 10.0f) {
                h = 10.0f;
                step = (d - 10.0f) / (f32)(arg2 - arg1);
            }
            if (arg2 < arg3 + arg1) {
                D_002020A0 = step * (f32)(arg2 - arg1);
            } else {
                if (arg3 < 0) arg3 = 0;
                D_002020A0 = (f32)arg3 * step;
            }
        }
        b[0] = arg0[0];
        b[1] = D_002020A0 + arg0[1];
        b[2] = arg0[2];
        b[3] = 4.0f + (D_002020A0 + arg0[1]);
        c[0] = arg0[0];
        c[1] = 4.0f + (D_002020A0 + arg0[1]);
        c[2] = arg0[2];
        c[3] = h + (D_002020A0 + arg0[1]);
        a[0] = arg0[0];
        a[1] = h + (D_002020A0 + arg0[1]);
        a[2] = arg0[2];
        a[3] = h + (4.0f + (D_002020A0 + arg0[1]));
        func_00187B20(0);
        n = M2C_FIELD(s0->p, s32 *, 4);
        func_00182080(0.0f, n, b, s0->p + 0x20, &col, 0);
        func_00182080(0.0f, n, c, s0->p + 0x50, &col, 0);
        func_00182080(0.0f, n, a, s0->p + 0x80, &col, 0);
    }
}
#undef func_00189020

/* func_001832D0 */
/* .bss, from the top down (CodeWarrior writes it in reverse) */
u8 D_0048D140[0x30];
#define func_00182C10 func_00182C10__as_func_001832D0
void func_00182C10__as_func_001832D0(s8 *, S_func_001832D0 *);

void func_001832D0(s8 *arg0, s32 arg1, s32 arg2)
{
  S_func_001832D0 s = {0};
  s8 *t1;
  u8 *a3;
  u8 *a1;
  t1 = D_0048D170 + (arg1 * 0x30);
  *((s32 *) t1) = arg2;
  s.a = 1;
  a3 = D_0048D140 + (arg1 * 4);
  s.b = t1;
  *((f32 *) (((s8 *) arg0) + 0x34)) = 1.0f;
  *((f32 *) (((s8 *) arg0) + 0x38)) = 1.0f;
  *a3 = 0xFF;
  D_0048D141[arg1 * 4] = 0xFF;
  D_0048D142[arg1 * 4] = 0xFF;
  a1 = D_0048D143 + (arg1 * 4);
  if ((*a1) > 0xD0)
  {
    *a1 = 0xFF;
  }
  else
  {
    *a1 += 0x20;
  }
  *((f32 *) (((s8 *) arg0) + 0x3C)) = *((f32 *) (D_0048D140 + (arg1 * 4)));
  if ((*((s32 *) (((s8 *) t1) + 4))) != 0)
  {
    func_00182C10(arg0, &s);
  }
  else
  {
    *((s32 *) (D_0048D140 + (arg1 * 4))) = 0;
  }
}
#undef func_00182C10

/* func_001833E0 */
s32 D_001F2740[0xc] = { -0x1 };
#define D_0048D170 D_0048D170__as_func_001833E0
extern Ent D_0048D170__as_func_001833E0[];
static inline O_func_001833E0 **getp(s32 i) { return &D_0048D110[i]; }

void func_001833E0(s32 arg0, s32 arg1) {
    Ent *e; O_func_001833E0 *o; s32 x; s32 *cur; O_func_001833E0 **pp;
    e = &D_0048D170[arg1];
    if (arg0 <= 0) {
        pp = getp(arg1);
        if (*pp != NULL && (*pp)->b2) {
            if (e->p != NULL) {
                func_00177570(e->p);
                e->p = NULL;
                D_001F2740[arg1] = -1;
                *pp = NULL;
            }
        }
        return;
    }
    cur = &D_001F2740[arg1];
    if (arg0 != *cur) {
        pp = getp(arg1);
        o = *pp;
        if (o != NULL && o->b1) return;
        *cur = arg0;
        if (o != NULL && o->b2) {
            if (e->p != NULL) {
                func_00177570(e->p);
                e->p = NULL;
            }
        }
        {
            Buf_func_001833E0 s = {0};
            sprintf(&s, D_001FC9C0, *cur);
            *pp = func_001E1570(&s, arg1);
        }
        e->f[0] = 4.0f;
        e->f[1] = 4.0f;
        e->f[2] = 50.0f;
        e->f[3] = 50.0f;
        e->f[4] = 0.0f;
        e->f[5] = 0.0f;
        e->f[6] = 64.0f;
        e->f[7] = 64.0f;
    }
    pp = getp(arg1);
    o = *pp;
    if (o != NULL && !o->b1 && !o->b2 && o->b0) {
        u8 buf2[16];
        sprintf(buf2, D_001FC9D8, *cur);
        if ((x = (*pp)->first) != 0) {
            e->p = func_00177AF0(func_00177F80(buf2), x);
            (*(O_func_001833E0 **)((s8 *)D_0048D110 + arg1 * 4))->b2 = 1;
        }
    }
}
#undef D_0048D170

/* func_00183650 */
#define func_00182C10 func_00182C10__as_func_00183650
void func_00182C10__as_func_00183650(s8 *, Buf_func_00183650 *);

void func_00183650(s8 *arg0) {
    Buf_func_00183650 s __attribute__((aligned(16))) = {0};
    if (D_0048D0E4[0] != 0) {
        if (D_002020A8.a > 0xD0) {
            D_002020A8.a = 0xFF;
        } else {
            D_002020A8.a += 0x20;
        }
        s.a = 1;
        s.b = D_0048D0E0;
        *(s32 *)(arg0 + 0x34) = 0x3F800000;
        *(s32 *)(arg0 + 0x38) = 0x3F800000;
        D_002020A8.r = 0xFF;
        D_002020A8.g = 0xFF;
        D_002020A8.b = 0xFF;
        arg0[0x3C] = D_002020A8.r;
        arg0[0x3D] = D_002020A8.g;
        arg0[0x3E] = D_002020A8.b;
        arg0[0x3F] = (D_002020A8.a * (u8)arg0[0x3F]) / 128;
        func_00182C10(arg0, &s);
        return;
    }
    *(u32 *)&D_002020A8 = 0;
}
#undef func_00182C10

/* func_00183750 */
#define sprintf sprintf__as_func_00183750
void sprintf__as_func_00183750(u8 *, M2C_UNK *, s32);
#define func_001E1570 func_001E1570__as_func_00183750
s8 *func_001E1570__as_func_00183750(u8 *, M2C_UNK);
#define D_002020A8 D_002020A8__as_func_00183750
extern s32 D_002020A8__as_func_00183750;
#define D_0048D0E4 D_0048D0E4__as_func_00183750
extern s8 *D_0048D0E4__as_func_00183750[];
#define func_00177F80 func_00177F80__as_func_00183750
s32 func_00177F80__as_func_00183750(u8 *);
#define func_00177AF0 func_00177AF0__as_func_00183750
s32 func_00177AF0__as_func_00183750(s32, s32);

void func_00183750(s32 arg0) {
    s32 temp_s0;
    u8 temp_a0;

    if (arg0 <= 0) {
        if ((D_002020AC != NULL) && (((u64) ((s64) M2C_FIELD(D_002020AC, u8 *, 8) << 0x3D) >> 0x3F) != 0) && (D_0048D0E4[0] != NULL)) {
            func_00177570(D_0048D0E4[0]);
            D_0048D0E4[0] = NULL;
            D_00201CE8 = -1;
        }
        return;
    }
    if (D_00201CE8 != arg0) {
        if (D_002020AC != NULL && (((u64) ((s64) M2C_FIELD(D_002020AC, u8 *, 8) << 0x3E) >> 0x3F) != 0)) {
            return;
        }
        if ((D_002020AC != NULL) && (((u64) ((s64) M2C_FIELD(D_002020AC, u8 *, 8) << 0x3D) >> 0x3F) != 0) && (D_0048D0E4[0] != NULL)) {
            func_00177570(D_0048D0E4[0]);
            D_0048D0E4[0] = NULL;
        }
        D_00201CE8 = arg0;
        D_00201CE0 = -1;
        D_00201CDC = -1;
        D_00201CE4 = -1;
        {
            Buf_func_00183750 s = {0};
        sprintf(s.b, D_001FC9F0, D_00201CE8);
            D_002020AC = func_001E1570(s.b, 0xA);
            D_0048D0F0[0] = 0;
            D_0048D0F4[0] = 0;
            D_002020A8 = 0;
            D_0048D0F8[0] = 0x43800000;
            D_0048D0FC[0] = 0x43800000;
            D_0048D100[0] = 0;
            D_0048D104[0] = 0;
            D_0048D108[0] = 0x43800000;
            D_0048D10C[0] = 0x43800000;
        }
    }
    {
        u8 name[16];
    if (D_002020AC != NULL) {
            temp_a0 = M2C_FIELD(D_002020AC, u8 *, 8);
            if ((((u64) ((s64) temp_a0 << 0x3E) >> 0x3F) == 0) && (((u64) ((s64) temp_a0 << 0x3D) >> 0x3F) == 0) && (temp_a0 & 1)) {
                sprintf(name, D_001FCA08, D_00201CE8);
                temp_s0 = M2C_FIELD(D_002020AC, s32 *, 0);
                if (temp_s0 != 0) {
                    D_0048D0E4[0] = (s8 *)func_00177AF0(func_00177F80(name), temp_s0);
                    ((BF *)(D_002020AC + 8))->c = 1;
                }
            }
        }
    }
}
#undef sprintf
#undef func_001E1570
#undef func_00177F80
#undef func_00177AF0
#undef D_002020A8
#undef D_0048D0E4

/* func_00183970 */
#define sprintf sprintf__as_func_00183970
void sprintf__as_func_00183970(u8 *, M2C_UNK *, s32);
#define func_001E1570 func_001E1570__as_func_00183970
s8 *func_001E1570__as_func_00183970(u8 *, M2C_UNK);
#define D_002020A8 D_002020A8__as_func_00183970
extern s32 D_002020A8__as_func_00183970;
#define D_0048D0E4 D_0048D0E4__as_func_00183970
extern s8 *D_0048D0E4__as_func_00183970[];
#define func_00177F80 func_00177F80__as_func_00183970
s32 func_00177F80__as_func_00183970(u8 *);
#define func_00177AF0 func_00177AF0__as_func_00183970
s32 func_00177AF0__as_func_00183970(s32, s32);

void func_00183970(s32 arg0) {
    s32 temp_s0;
    u8 temp_a0;

    if (arg0 <= 0) {
        if ((D_002020AC != NULL) && (((u64) ((s64) M2C_FIELD(D_002020AC, u8 *, 8) << 0x3D) >> 0x3F) != 0) && (D_0048D0E4[0] != NULL)) {
            func_00177570(D_0048D0E4[0]);
            D_0048D0E4[0] = NULL;
            D_00201CE4 = -1;
        }
        return;
    }
    if (D_00201CE4 != arg0) {
        if (D_002020AC != NULL && (((u64) ((s64) M2C_FIELD(D_002020AC, u8 *, 8) << 0x3E) >> 0x3F) != 0)) {
            return;
        }
        if ((D_002020AC != NULL) && (((u64) ((s64) M2C_FIELD(D_002020AC, u8 *, 8) << 0x3D) >> 0x3F) != 0) && (D_0048D0E4[0] != NULL)) {
            func_00177570(D_0048D0E4[0]);
            D_0048D0E4[0] = NULL;
        }
        D_00201CE4 = arg0;
        D_00201CE0 = -1;
        D_00201CDC = -1;
        D_00201CE8 = -1;
        {
            Buf_func_00183970 s = {0};
        sprintf(s.b, D_001FCA10, D_00201CE4);
            D_002020AC = func_001E1570(s.b, 0xA);
            D_0048D0F0[0] = 0;
            D_0048D0F4[0] = 0;
            D_002020A8 = 0;
            D_0048D0F8[0] = 0x43000000;
            D_0048D0FC[0] = 0x43000000;
            D_0048D100[0] = 0;
            D_0048D104[0] = 0;
            D_0048D108[0] = 0x43000000;
            D_0048D10C[0] = 0x43000000;
        }
    }
    {
        u8 name[16];
    if (D_002020AC != NULL) {
            temp_a0 = M2C_FIELD(D_002020AC, u8 *, 8);
            if ((((u64) ((s64) temp_a0 << 0x3E) >> 0x3F) == 0) && (((u64) ((s64) temp_a0 << 0x3D) >> 0x3F) == 0) && (temp_a0 & 1)) {
                sprintf(name, D_001FCA20, D_00201CE4);
                temp_s0 = M2C_FIELD(D_002020AC, s32 *, 0);
                if (temp_s0 != 0) {
                    D_0048D0E4[0] = (s8 *)func_00177AF0(func_00177F80(name), temp_s0);
                    ((BF *)(D_002020AC + 8))->c = 1;
                }
            }
        }
    }
}
#undef sprintf
#undef func_001E1570
#undef func_00177F80
#undef func_00177AF0
#undef D_002020A8
#undef D_0048D0E4

/* func_00183B90 */
#define D_002020AC D_002020AC__as_func_00183B90
extern Res *D_002020AC__as_func_00183B90;
#define D_002020A8 D_002020A8__as_func_00183B90
extern s32 D_002020A8__as_func_00183B90;
#define D_0048D0F0 D_0048D0F0__as_func_00183B90
extern f32 D_0048D0F0__as_func_00183B90[];
#define D_0048D0F4 D_0048D0F4__as_func_00183B90
extern f32 D_0048D0F4__as_func_00183B90[];
#define D_0048D0F8 D_0048D0F8__as_func_00183B90
extern f32 D_0048D0F8__as_func_00183B90[];
#define D_0048D0FC D_0048D0FC__as_func_00183B90
extern f32 D_0048D0FC__as_func_00183B90[];
#define D_0048D100 D_0048D100__as_func_00183B90
extern f32 D_0048D100__as_func_00183B90[];
#define D_0048D104 D_0048D104__as_func_00183B90
extern f32 D_0048D104__as_func_00183B90[];
#define D_0048D108 D_0048D108__as_func_00183B90
extern f32 D_0048D108__as_func_00183B90[];
#define D_0048D10C D_0048D10C__as_func_00183B90
extern f32 D_0048D10C__as_func_00183B90[];
#define func_00177570 func_00177570__as_func_00183B90
void func_00177570__as_func_00183B90(s32);
#define func_001E1570 func_001E1570__as_func_00183B90
Res *func_001E1570__as_func_00183B90(void *, s32);
#define func_00177AF0 func_00177AF0__as_func_00183B90
s32 func_00177AF0__as_func_00183B90(s32, s32);

void func_00183B90(s32 id) {


    s32 r;
    if (id == -1 || id == 0) {
        if (D_002020AC && D_002020AC->f8.f.b2 && D_0048D0E4[0]) {
            func_00177570(D_0048D0E4[0]);
            D_0048D0E4[0] = 0;
            D_00201CE0 = -1;
        }
        return;
    }
    if (D_00201CE0 != id) {
        if (D_002020AC && D_002020AC->f8.f.b1) return;
        if (D_002020AC && D_002020AC->f8.f.b2 && D_0048D0E4[0]) {
            func_00177570(D_0048D0E4[0]);
            D_0048D0E4[0] = 0;
        }
        D_00201CE0 = id;
        D_00201CE4 = -1;
        D_00201CDC = -1;
        D_00201CE8 = -1;
        {
        s8 buf[0x100] = {0};
        sprintf(buf, D_001FCA30, D_00201CE0);
        D_002020AC = func_001E1570(buf, 10);
        D_0048D0F0[0] = 0.0f;
        D_0048D0F4[0] = 0.0f;
        D_002020A8 = 0;
        D_0048D0F8[0] = 128.0f;
        D_0048D0FC[0] = 128.0f;
        D_0048D100[0] = 0.0f;
        D_0048D104[0] = 0.0f;
        D_0048D108[0] = 128.0f;
        D_0048D10C[0] = 128.0f;
        }
    }
    if (D_002020AC && !D_002020AC->f8.f.b1 && !D_002020AC->f8.f.b2 && D_002020AC->f8.f.b0) {
        s8 name[16];
        sprintf(name, D_001FCA48, D_00201CE0);
        r = D_002020AC->x0;
        if (r) {
            D_0048D0E4[0] = func_00177AF0(func_00177F80(name), r);
            D_002020AC->f8.f.b2 = 1;
        }
    }
}
#undef func_00177570
#undef func_001E1570
#undef func_00177AF0
#undef D_002020AC
#undef D_002020A8
#undef D_0048D0F0
#undef D_0048D0F4
#undef D_0048D0F8
#undef D_0048D0FC
#undef D_0048D100
#undef D_0048D104
#undef D_0048D108
#undef D_0048D10C

/* func_00183DC0 */
#define sprintf sprintf__as_func_00183DC0
void sprintf__as_func_00183DC0(u8 *, M2C_UNK *, s32);
#define func_001E1570 func_001E1570__as_func_00183DC0
s8 *func_001E1570__as_func_00183DC0(u8 *, M2C_UNK);
#define D_002020A8 D_002020A8__as_func_00183DC0
extern s32 D_002020A8__as_func_00183DC0;
#define D_0048D0E4 D_0048D0E4__as_func_00183DC0
extern s8 *D_0048D0E4__as_func_00183DC0[];
#define func_00177F80 func_00177F80__as_func_00183DC0
s32 func_00177F80__as_func_00183DC0(u8 *);
#define func_00177AF0 func_00177AF0__as_func_00183DC0
s32 func_00177AF0__as_func_00183DC0(s32, s32);

void func_00183DC0(s32 arg0) {
    s32 temp_s0;
    u8 temp_a0;

    if (arg0 == -1 || arg0 == 0) {
        if ((D_002020AC != NULL) && (((u64) ((s64) M2C_FIELD(D_002020AC, u8 *, 8) << 0x3D) >> 0x3F) != 0) && (D_0048D0E4[0] != NULL)) {
            func_00177570(D_0048D0E4[0]);
            D_0048D0E4[0] = NULL;
            D_00201CDC = -1;
        }
        return;
    }
    if (D_00201CDC != arg0) {
        if (D_002020AC != NULL && (((u64) ((s64) M2C_FIELD(D_002020AC, u8 *, 8) << 0x3E) >> 0x3F) != 0)) {
            return;
        }
        if ((D_002020AC != NULL) && (((u64) ((s64) M2C_FIELD(D_002020AC, u8 *, 8) << 0x3D) >> 0x3F) != 0) && (D_0048D0E4[0] != NULL)) {
            func_00177570(D_0048D0E4[0]);
            D_0048D0E4[0] = NULL;
        }
        D_00201CDC = arg0;
        D_00201CE4 = -1;
        D_00201CE0 = -1;
        D_00201CE8 = -1;
        {
            Buf_func_00183DC0 s = {0};
        sprintf(s.b, D_001FCA60, D_00201CDC);
            D_002020AC = func_001E1570(s.b, 0xA);
            D_0048D0F0[0] = 0;
            D_0048D0F4[0] = 0;
            D_002020A8 = 0;
            D_0048D0F8[0] = 0x43000000;
            D_0048D0FC[0] = 0x43000000;
            D_0048D100[0] = 0;
            D_0048D104[0] = 0;
            D_0048D108[0] = 0x43000000;
            D_0048D10C[0] = 0x43000000;
        }
    }
    {
        u8 name[16];
    if (D_002020AC != NULL) {
            temp_a0 = M2C_FIELD(D_002020AC, u8 *, 8);
            if ((((u64) ((s64) temp_a0 << 0x3E) >> 0x3F) == 0) && (((u64) ((s64) temp_a0 << 0x3D) >> 0x3F) == 0) && (temp_a0 & 1)) {
                sprintf(name, D_001FCA78, D_00201CDC);
                temp_s0 = M2C_FIELD(D_002020AC, s32 *, 0);
                if (temp_s0 != 0) {
                    D_0048D0E4[0] = (s8 *)func_00177AF0(func_00177F80(name), temp_s0);
                    ((BF *)(D_002020AC + 8))->c = 1;
                }
            }
        }
    }
}
#undef sprintf
#undef func_001E1570
#undef func_00177F80
#undef func_00177AF0
#undef D_002020A8
#undef D_0048D0E4

/* func_00183FF0 */
#define D_002020AC D_002020AC__as_func_00183FF0
extern Res *D_002020AC__as_func_00183FF0;
s32 func_00183FF0(void) {
    if (D_002020AC == NULL) return 0;
    goto test;
one:
    return 1;
test:
    if (D_002020AC->f8.f.b1) goto one;
    D_00201CDC = -1; D_00201CE0 = -1; D_00201CE4 = -1; D_00201CE8 = -1;
    return 0;
}
#undef D_002020AC

/* func_00184040 */
#define func_00189020 func_00189020__as_func_00184040
u8 *func_00189020__as_func_00184040(s32);

void func_00184040(s32 a0, f32 ang) {
    u32 i;
    L *l;
    u8 *t;
    Obj o;

    l = func_00189050(2)->l;
    t = func_00189020(2);
    func_00187B20(0);
    for (i = 0; i < l->n; i++) {
        o = l->e[i];
        {
        V2 c = {0};
        f32 d, dx, dz, a, r;
        f32 ox, oz;
        f32 fx, fz;
        c.x = 735.0f;
        c.z = 129.0f;
        fx = o.x; fz = o.z; ox = fx - 735.0f; oz = fz - 129.0f;
        d = sqrtf(ox * ox + oz * oz);
        dx = fx - c.x;
        dz = fz - c.z;
        if (dx == 0.0f) {
            a = 0.0f;
        } else {
            a = atanf(dx / dz);
        }
        if (dz < 0.0f) {
            a += 3.141592f;
        }
        r = a + ang;
        o.x = 735.0f + d * sinf(r);
        o.z = 129.0f + d * cosf(r);
        }
        func_001829B0(&o, t + (l->e[i].idx << 3), func_00184280, a0);
    }
}
#undef func_00189020
