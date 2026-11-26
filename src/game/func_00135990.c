#include "common.h"
typedef struct { u16 x0; u16 x2; u16 x4; u16 x6; u16 x8; u8 pada[0xA]; u16 x14; } Prm;
typedef struct { u8 pad[0x24]; s32 x24; u8 pad28[0x18]; } Hit;
extern s32 D_00201E80;
#define C (((s32 **)&D_00201E80)[2])
#define D (((s32 **)&D_00201E80)[3])
f32 sqrtf(f32);
Prm *func_0013DE60(s8 *);
void func_0013EA80(s8 *, s32);
void func_00141A50(s8 *, f32 *, f32 *, f32 *, f32 *, f32 *);
Vec *func_00145730(void);
Vec *func_00140460(s8 *);
void sceVu0SubVector(Vec *, Vec *, Vec *);
void sceVu0CopyVector(Vec *, Vec *);
f32 sceVu0InnerProduct(Vec *, Vec *);
void func_001403D0(s8 *, Vec *);
s32 func_001C9A20(void);
s32 func_001C9A80(void);
s32 func_00145620(void);
s32 func_0013E660(s8 *);
s32 func_0013E610(s8 *);
f32 cosf(f32);
void memset(void *, s32, s32);
void func_0013D320(s32, Hit *, Vec *, s32, s32);
void func_00145760(s8 *);
void func_00145720(s8 *);
static inline f32 u2f(u32 x) { return x; }
static inline f32 mu(u32 x, f32 k) { f32 f = x; return f * k; }

u8 func_00135990(s8 *a, f32 *pl, f32 *pc, f32 *py) {
    f32 v12C;
    f32 v128;
    f32 v124;
    f32 v120;
    f32 v11C;
    Vec d;
    Vec m;
    Hit h;
    Vec seg[2];
    u8 r;
    Prm *p;
    f32 full;
    f32 len;
    f32 cs;
    f32 dy;

    r = 0;
    p = func_0013DE60(a);
    func_0013EA80(a, 1);
    func_00141A50(a, &v12C, &v128, &v124, &v120, &v11C);
    sceVu0SubVector(&d, func_00145730(), func_00140460(a));
    full = sqrtf(sceVu0InnerProduct(&d, &d));
    dy = d.y;
    dy = dy < 0.0f ? -dy : dy;
    *(s32 *)&d.y = 0;
    len = sqrtf(sceVu0InnerProduct(&d, &d));
    if (len > 0.0f) {
        d.x /= len;
        d.y /= len;
        d.z /= len;
    }
    func_001403D0(a, &m);
    cs = sceVu0InnerProduct(&d, &m);
    if (full < mu(p->x14, v11C)) r = 1;
    if (r == 0) {
        if (func_001C9A20() || func_001C9A80() || func_00145620()) {
            if (full < mu(p->x8, v128)) r = 1;
        }
    }
    if (r == 0 && func_0013E660(a)) {
        if (len < mu(p->x0, v12C) && dy < u2f(p->x4) && !(cs <= cosf(3.1415927f * u2f(p->x2) / 180.0f))) {
            sceVu0CopyVector(&seg[0], func_00140460(a));
            seg[0].y -= 100.0f;
            seg[0].w = 1.0f;
            sceVu0CopyVector(&seg[1], func_00145730());
            seg[1].y -= 100.0f;
            seg[1].w = 1.0f;
            memset(&h, 0, 0x40);
            if (C) func_0013D320(*C, &h, seg, 6, 7);
            if (h.x24 == 0 && D) func_0013D320(*D, &h, seg, 6, 7);
            if (h.x24 == 0) r = 1;
        }
    }
    if (pl) *pl = len;
    if (pc) *pc = cs;
    if (py) *py = dy;
    if (func_0013E610(a)) r = 0;
    func_00145760(a + 0x680);
    func_00145720(a + 0x690);
    return r;
}
