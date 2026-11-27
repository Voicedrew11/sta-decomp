#include "common.h"
typedef struct { u8 pad[0x23]; u8 on; u8 pad2[0xC]; } E_func_0015C0C0;
typedef struct {
    f32 f[6];
    u8 pad[0xB0 - 0x18];
    E_func_0015C0C0 e[2][32];
    u8 padCB0[4];
    u16 n[2];
} S;
typedef struct { u8 b[4]; u16 h; u8 c; } C;
typedef struct { u8 b[0x600]; } E_func_0015C6D0;
typedef struct { Vec a; f32 x10; f32 x14; f32 x18; u8 b1C; u8 b1D; u8 b1E; u8 b1F; u16 h20; u8 b22; u8 used; u8 pad[0xC]; } Ent;
typedef struct { u8 pad[0xB0]; Ent ents[2][32]; } W;
typedef struct {
    Vec v;
    f32 x10, x14, x18;
    u8 x1C, x1D, x1E, x1F;
    u16 x20;
    u8 x22, x23;
    u8 pad[0xC];
} __attribute__((aligned(16))) S30;
typedef struct {
    u8 pad[0x20];
    S30 a;
    S30 b;
    S30 c;
    u8 pad2[0xCC0 - 0xB0];
} Big;
extern S D_0030C420[];
extern Vec D_0030C3E0[];
extern C D_0030C48C[];
extern u16 D_0030D0D4[];
extern Vec D_003139A0;
extern u8 D_0030C420__as_func_0015C620[];
extern E_func_0015C6D0 D_0030C420__as_func_0015C6D0[];
extern W D_0030C420__as_func_0015C730;
extern Big D_0030C420__as_func_0015C8D0;
void func_0015C0C0(void *arg0);
void func_0015C620(void *arg0);
void func_0015C6D0(s32 i);
s32 func_0015C730(s32 idx, Vec *v, u8 c0, u8 c1, u8 c2, u8 c3, u16 h, u8 c4, f32 f0, f32 f1, f32 f2, f32 f3);
void func_0015C8D0(void);
void sceVu0CopyMatrix(Vec *, void *);
f32 func_0015BDE0(E_func_0015C0C0 *);
void func_00159340(u8, u8, u8, u8, u16, u8);
void sceVu0AddVector(void *, void *, void *);
void* memset(void*, s32, u32);
void sceVu0CopyVector(void *, void *);
void sceVu0CopyVector__as_func_0015C730(Vec *, Vec *);
void memset__as_func_0015C8D0(void *, s32, s32);

/* func_0015C0C0 */
/* func_0015C0C0 */
void func_0015C0C0(void *arg0) {
    s32 i;
    s32 j;
    s32 cnt;
    f32 sum;
    f32 inv;

    cnt = 0;
    sum = 0.0f;
    D_0030C420[0].f[0] = 0.0f;
    D_0030C420[0].f[1] = 0.0f;
    D_0030C420[0].f[2] = 0.0f;
    D_0030C420[0].f[3] = 0.0f;
    D_0030C420[0].f[4] = 0.0f;
    D_0030C420[0].f[5] = 0.0f;
    sceVu0CopyMatrix(D_0030C3E0, arg0);
    for (i = 0; i < 2; i++) {
        if (D_0030C420[0].n[i]) {
            for (j = 0; j < 32; j++) {
                if (D_0030C420[0].e[i][j].on) {
                    sum += func_0015BDE0(&D_0030C420[0].e[i][j]);
                    cnt++;
                }
            }
        }
    }
    if (cnt) {
        inv = 1.0f / sum;
        D_0030C48C[0].b[0] = D_0030C420[0].f[0] * inv;
        D_0030C48C[0].b[1] = D_0030C420[0].f[1] * inv;
        D_0030C48C[0].b[2] = D_0030C420[0].f[2] * inv;
        D_0030C48C[0].b[3] = D_0030C420[0].f[3] * inv;
        D_0030C48C[0].h = D_0030C420[0].f[4] * inv;
        D_0030C48C[0].c = D_0030C420[0].f[5] * inv;
    } else {
        inv = 1.0f;
        D_0030C48C[0].b[0] = D_0030C420[0].f[0] * inv;
        D_0030C48C[0].b[1] = D_0030C420[0].f[1] * inv;
        D_0030C48C[0].b[2] = D_0030C420[0].f[2] * inv;
        D_0030C48C[0].b[3] = D_0030C420[0].f[3] * inv;
        D_0030C48C[0].h = D_0030C420[0].f[4] * inv;
        D_0030C48C[0].c = D_0030C420[0].f[5] * inv;
    }
    func_00159340(D_0030C48C[0].b[0], D_0030C48C[0].b[1], D_0030C48C[0].b[2], D_0030C48C[0].b[3], D_0030C48C[0].h, D_0030C48C[0].c);
}

/* func_0015C620 */
#define D_0030C420 D_0030C420__as_func_0015C620
void func_0015C620(void *arg0) {
    s32 i;
    s32 j;
    u8 *p;
    u8 *q;
    u8 *r;
    i = 0;
    p = D_0030C420;
    q = D_0030C420;
    do {
        j = 0;
        if (*(u16 *)(p + 0xCB4) != 0) {
            r = q;
            do {
                if (r[0xD3] != 0) {
                    sceVu0AddVector(r + 0xB0, r + 0xB0, arg0);
                }
                j++;
                r += 0x30;
            } while (j < 0x20);
        }
        i++;
        p += 2;
        q += 0x600;
    } while (i < 2);
}
#undef D_0030C420

/* func_0015C6D0 */
#define D_0030C420 D_0030C420__as_func_0015C6D0

void func_0015C6D0(s32 i)
{
    memset(D_0030C420[i].b + 0xB0, 0, 0x600);
    D_0030D0D4[i] = 0;
}
#undef D_0030C420

/* func_0015C730 */
#define D_0030C420 D_0030C420__as_func_0015C730
#define sceVu0CopyVector sceVu0CopyVector__as_func_0015C730

s32 func_0015C730(s32 idx, Vec *v, u8 c0, u8 c1, u8 c2, u8 c3, u16 h, u8 c4, f32 f0, f32 f1, f32 f2, f32 f3) {
    s32 i;
    s32 id;
    Ent *e;

    for (i = 0; i < 32; i++) {
        if (D_0030C420.ents[idx & 1][i].used == 0) {
            id = i + (idx & 1) * 32;
            goto found;
        }
    }
    id = -1;
found:
    if (id == -1) {
        return id;
    }
    e = &D_0030C420.ents[(u32)id >> 5][id & 31];
    sceVu0CopyVector(&e->a, v);
    e->a.w = f0;
    e->x10 = f2;
    e->x14 = f3;
    e->x18 = f1;
    e->used = 1;
    e->b1C = c0;
    e->b1D = c1;
    e->b1E = c2;
    e->b1F = c3;
    e->h20 = h;
    e->b22 = c4;
    D_0030D0D4[idx]++;
    return id;
}
#undef sceVu0CopyVector
#undef D_0030C420

/* func_0015C8D0 */
#define D_0030C420 D_0030C420__as_func_0015C8D0
#define memset memset__as_func_0015C8D0

void func_0015C8D0(void) {
    memset(&D_0030C420, 0, 0xCC0);
    sceVu0CopyVector(&D_0030C420.c.v, &D_003139A0);
    D_0030C420.c.v.w = 40000.0f;
    D_0030C420.c.x18 = 100.0f;
    D_0030C420.c.x10 = 1.0f;
    D_0030C420.c.x14 = 0.1f;
    D_0030C420.c.x23 = 1;
    D_0030C420.c.x1C = 0x18;
    D_0030C420.c.x1D = 8;
    D_0030C420.c.x1E = 8;
    D_0030C420.c.x1F = 8;
    D_0030C420.c.x20 = 0x40;
    D_0030C420.c.x22 = 0x78;
    D_0030C420.a = D_0030C420.c;
    D_0030C420.b = D_0030C420.c;
}
#undef memset
#undef D_0030C420
