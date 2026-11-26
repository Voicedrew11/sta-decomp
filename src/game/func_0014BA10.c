#include "m2c.h"
typedef struct { u8 b0 : 1; u8 b1 : 1; } BF;
typedef struct {
    f32 v0[4];
    f32 v10[4];
    u8 pad20[0x30];
    f32 v50[4];
    f32 x60;
    f32 x64;
    f32 x68;
    u8 pad6C[0x1C];
    f32 x88;
    u8 pad8C[0x2C];
    f32 xB8;
    f32 xBC;
    u8 padC0[0x54];
    BF x114;
} Obj;
extern f32 D_001F2160[];
extern s32 **D_002022BC;
s8 *func_001A5460(s32 *);
u32 func_0013E110(s8 *);
void sceVu0AddVector(f32 *, f32 *, f32 *);
void sceVu0SubVector(f32 *, f32 *, f32 *);
f32 func_00146940(Obj *, f32 *);
void func_00141510(s8 *, u8, s32, s32);
f32 sceVu0InnerProduct(f32 *, f32 *);
void sceVu0Normalize(f32 *, f32 *);
void sceVu0ScaleVector(f32 *, f32 *, f32);
f32 sqrtf(f32);
#define POS(p) ((p) ? (f32 *)(*(s32 *)((p) + 0x518) + 0x90) : D_001F2160)
static inline s8 *find(u16 id) {
    s32 it;
    s8 *p;
    it = 0;
    for (p = func_001A5460(&it); p != NULL; p = func_001A5460(&it)) {
        if (*(u16 *)p != 0 && (u16)func_0013E110(p) == id) return p;
    }
    return NULL;
}
static inline s32 ok(void) {
    return D_002022BC != NULL && *D_002022BC != NULL;
}

void func_0014BA10(Obj *a0) {
    f32 c[4];
    f32 b[4];
    f32 a[4];
    s8 *p;
    s32 id;
    f32 x60 = a0->x60;
    f32 x68 = a0->x68;
    f32 bc;
    f32 len;

    id = (u16)(u32)a0->xB8;
    if (id != 0) {
        p = find(id);
    } else {
        p = NULL;
    }
    if (p != NULL) {
        sceVu0AddVector(c, POS(p), a0->v50);
        c[3] = 1.0f;
        if (func_00146940(a0, c) < x68) {
            func_00141510(p, ok() ? **D_002022BC : 0, 3, 0);
            a0->x88 = (f32)(u32)(a0->x114.b1 = 0);
        }
        bc = a0->xBC;
        sceVu0SubVector(b, c, (f32 *)a0);
        len = sqrtf(sceVu0InnerProduct(a0->v10, a0->v10));
        sceVu0Normalize(a, b);
        sceVu0ScaleVector(a, a, -1.0f * bc);
        sceVu0AddVector(a0->v10, a0->v10, a);
        sceVu0Normalize(a0->v10, a0->v10);
        sceVu0ScaleVector(a0->v10, a0->v10, len);
        a0->xBC -= x60;
    }
}
