#include "m2c.h"
#include "actor.h"
#include "common.h"
typedef struct { u8 pad[0xC]; u16 xC; u8 pad2[2]; s32 x10; } H_func_0012E6B0;
typedef struct {
    s8 on; s8 idx; s8 x2; s8 x3;
    u8 p4[0x7C];
} Snd;
typedef struct { u8 b0:1; u8 b1:7; } F;
typedef struct { s32 pad[3]; F f; u8 p[3]; } S_func_0012E810;
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; s8 data[1]; } H_func_0012E810;
typedef struct { s32 a; s32 b; s32 c8; s32 c; } H_func_0012E8F0;
typedef struct { s32 st; s32 p4; s32 p8; Flags8 fC; u8 pD[3]; } S_func_0012E8F0;
typedef struct { s32 a; s32 b; s32 c8; s32 c; } H_func_0012EA00;
typedef struct { s32 st; s32 pad[3]; } S_func_0012EA00;
typedef struct { s32 x0; s32 x4; s32 x8; u16 xC; u16 xE; } B;
extern M2C_UNK D_0022F040[];
extern Snd D_0022CBC0[];
extern s8 D_0022EBC8[];
extern s8 D_0022EBC0[];
extern s32 D_00222BC0[];
extern s8 D_00222BC1[];
extern s8 D_00222BC4[];
extern s8 D_00222BC5[];
extern u8 D_0022EBD9[];
extern u8 D_0022F090[];
s32 func_0012E640(s8 *arg0, s32 arg1);
s32 func_0012E6B0(H_func_0012E6B0 *a);
void func_0012E730(s32 arg0);
s32 func_0012E810(H_func_0012E810 *arg0, s32 arg1);
s32 func_0012E8F0(H_func_0012E8F0 *a0, s32 idx);
s32 func_0012EA00(H_func_0012EA00 *a0, u32 idx);
s32 func_0012ED60(u8 *, u32);
void func_001D9EE0(s32);
void func_001DA920(s8);
void func_001DACB0(s8);
void FlushCache(s32);
s32 func_001D8FC0(void *, void *, void *, s32, s8, s8, B *);
void func_001789E0(void *, s32, s32);
s32 func_001D98D0(s32, void *, s32, s32, u16, u16);
s32 func_001D9820(u16, u16);
s32 func_001D8FB0(void);

/* func_0012E640 */
s32 func_0012E640(s8 *arg0, s32 arg1) {
    s8 *temp_v1;

    temp_v1 = arg0 + 0x10;
    if ((s32) M2C_FIELD(arg0, u16 *, 0xC) < 4) {
        return -1;
    }
    if (M2C_FIELD(temp_v1, s32 *, 4) == 0) {
        return -1;
    }
    func_0012E8F0(temp_v1, arg1);
    D_0022F040[arg1 * 4] = 0;
    return 0;
}

/* func_0012E6B0 */
#define func_0012E8F0 func_0012E8F0__as_func_0012E6B0
s32 func_0012E8F0__as_func_0012E6B0(u8 *, s32);
#define D_0022F040 D_0022F040__as_func_0012E6B0
extern s32 D_0022F040__as_func_0012E6B0[];
s32 func_0012E6B0(H_func_0012E6B0 *a) {
    u8 *p = (u8 *)&a->x10;
    if (a->xC != 4) return -1;
    func_0012E8F0(p, 0);
    p += *(s32 *)p;
    D_0022F040[0] = 0;
    while (func_0012ED60(p, 0) == 0) {}
    return 0;
}
#undef func_0012E8F0
#undef D_0022F040

/* func_0012E730 */
void func_0012E730(s32 arg0) {
    s32 n;
    Snd *s;
    s8 *p;

    n = 0x3F;
    s = D_0022CBC0;
    while (n--) {
        if (s->on != 0 && s->x2 == arg0) {
            s->on = 0;
        }
        s++;
    }
    func_001D9EE0(arg0);
    p = &D_0022EBC8[arg0];
    if (*p != -1) {
        func_001DA920(*p);
    }
    *p = -1;
    p = &D_0022EBC0[arg0];
    if (*p != -1) {
        func_001DACB0(*p);
    }
    *p = -1;
}

/* func_0012E810 */
#define D_0022F040 D_0022F040__as_func_0012E810
extern S_func_0012E810 D_0022F040__as_func_0012E810[];

s32 func_0012E810(H_func_0012E810 *arg0, s32 arg1) {
    s32 i;
    s32 n;
    s32 v;
    F *f;
    s32 *d;

    d = (s32 *)((s32)arg0->data + ((arg0->xC + 0xF) & ~0xF));
    f = &D_0022F040[arg1].f;
    if (!f->b0) {
        return 0;
    }
    if (arg0->x4 == 0) {
        return -1;
    }
    n = *d++;
    i = 0;
    if (0 < n) {
        do {
            v = *d;
            if (!(v < 0x2800)) {
                return -1;
            }
            D_00222BC0[v] = -1;
            i++;
            d += 2;
        } while (i < n);
    }
    f->b0 = 0;
    return 0;
}
#undef D_0022F040

/* func_0012E8F0 */
#define D_0022F040 D_0022F040__as_func_0012E8F0
extern S_func_0012E8F0 D_0022F040__as_func_0012E8F0[];

s32 func_0012E8F0(H_func_0012E8F0 *a0, s32 idx) {
    s32 i;
    s32 *p;
    s32 *end;
    s32 n;
    s32 k;

    p = (s32 *)((u8 *)((s32)a0 + 0x10) + ((a0->c + 15) & ~15));
    end = (s32 *)((u8 *)p + a0->b);
    if (a0->b == 0) return -1;
    n = *p++;
    for (i = 0; i < n; i++) {
        if (!(p < end)) return -1;
        k = p[0];
        if (!(p + 1 < end)) return -1;
        if (k >= 0x2800) return -1;
        D_00222BC0[k] = p[1];
        p += 2;
    }
    FlushCache(0);
    D_0022F040[idx].fC.f.b0 = 1;
    return 0;
}
#undef D_0022F040

/* func_0012EA00 */
#define D_0022F040 D_0022F040__as_func_0012EA00
extern S_func_0012EA00 D_0022F040__as_func_0012EA00[];
#define D_00222BC0 D_00222BC0__as_func_0012EA00
extern s8 D_00222BC0__as_func_0012EA00[];
#define DATA(h) ((u8 *)((s32)(h) + 0x10) + (((h)->c + 15) & ~15))

s32 func_0012EA00(H_func_0012EA00 *a0, u32 idx) {
    H_func_0012EA00 *s3;
    H_func_0012EA00 *s2;
    s32 ret;
    S_func_0012EA00 *s0;
    s32 x0, x1, x2;
    B b;
    u16 v;

    s0 = &D_0022F040[idx];
    s3 = (H_func_0012EA00 *)((u8 *)a0 + a0->a);
    s2 = (H_func_0012EA00 *)((u8 *)s3 + s3->a);
    x0 = a0->b;
    x1 = s3->b;
    x2 = s2->b;
    if (x0 == 0 || x1 == 0 || x2 == 0) return -1;
    ret = -1;
    switch (s0->st) {
    case 0:
        if (func_001D8FC0(DATA(s2), DATA(a0), DATA(s3), x1, D_00222BC0[0], D_00222BC1[0], &b) == 0) {
            s0->st = 0;
            break;
        }
        func_001789E0(D_0022F090, b.x0, ((b.x8 + 15) & ~15) >> 4);
        if (func_001D98D0(0, D_0022F090, b.x8, b.x4, b.xC, b.xE) == 0) {
            s0->st = 0;
            break;
        }
        s0->st = 1;
        ret = 0;
        break;
    case 1:
        v = D_0022EBD9[0] * 129;
        if (func_001D9820(v, v) == 0) {
            s0->st = 0;
            break;
        }
        s0->st = 2;
        ret = 0;
        break;
    case 2:
        if (func_001D8FB0() == 7) {
            s0->st = 3;
        } else {
            ret = 0;
            break;
        }
    case 3:
        if (func_001D8FC0(DATA(s2), DATA(a0), DATA(s3), x1, D_00222BC4[0], D_00222BC5[0], &b) == 0) {
            s0->st = 0;
            break;
        }
        func_001789E0(D_0022F090, b.x0, ((b.x8 + 15) & ~15) >> 4);
        if (func_001D98D0(1, D_0022F090, b.x8, b.x4, b.xC, b.xE) == 0) {
            s0->st = 0;
            break;
        }
        s0->st = 4;
        ret = 0;
        break;
    case 4:
        v = D_0022EBD9[0] * 129;
        func_001D9820(v, v);
        s0->st = 5;
        ret = 0;
        break;
    case 5:
        if (func_001D8FB0() == 7) {
            s0->st = 6;
        } else {
            ret = 0;
            break;
        }
    case 6:
        s0->st = 0;
        ret = 1;
        break;
    default:
        s0->st = 0;
        break;
    }
    return ret;
}
#undef D_0022F040
#undef D_00222BC0
