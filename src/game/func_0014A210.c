/* ang < 0.0f | a */
#include "actor.h"
#include "common.h"
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
static inline f32 DEG(f32 a) { return a ? 0.01745f * a : 0.0f; }
typedef struct {
    Vec p;
    u8 pad10[0x40];
    f32 x50;
    f32 x54;
    u8 pad58[8];
    f32 x60;
    f32 x64;
    f32 x68;
    u8 pad6C[0x24];
    s8 *x90;
    u8 pad94[0x2C];
    Mtx xC0;
} O;
extern s8 D_001F2160[];
extern Mtx D_001F2170;
u16 func_0015ED20(void);
f32 cosf(f32);
f32 sinf(f32);
void sceVu0AddVector(void *, void *, Vec *);
void sceVu0SubVector(Vec *, s8 *, s8 *);
void func_00146570(Actor *, Vec *);
void func_00145F40(Actor *, f32 *, f32 *);
void sceVu0RotMatrixY(Mtx *, Mtx *, f32);
inline s32 has(void) {
    return D_002022E4 != NULL && D_002022E4->unk518 != NULL;
}

void func_0014A210(O *o) {
    f32 h;
    f32 ang;
    f32 r;
    f32 yr;
    f32 a;
    s8 *b;
    Vec t;
    Vec w;
    Vec d;

    h = o->x60;
    ang = o->x64;
    r = o->x50;
    yr = o->x54;
    a = 6.2831855f * (1.5259022e-05f * (f32)(u32)func_0015ED20());
    r *= 1.5259022e-05f * (f32)(u32)func_0015ED20();
    d.x = r * cosf(a);
    d.z = r * sinf(a);
    d.y = yr * (1.0f - 2.0f * (1.5259022e-05f * (f32)(u32)func_0015ED20()));
    d.w = 0.0f;
    sceVu0AddVector(o, o, &d);
    b = o->x90;
    sceVu0SubVector(&t, has() ? D_002022E4->unk518 + 0x1C0 : D_001F2160, b + 0x30);
    sceVu0AddVector(o, o, &t);
    o->p.w = 1.0f;
    o->p.y += h;
    func_00146570(D_002022E4, &w);
    o->p.x += w.x * o->x68;
    o->p.z += w.z * o->x68;
    if (ang < 0.0f) {
        func_00145F40(D_002022E4, &ang, NULL);
        sceVu0RotMatrixY(&o->xC0, &D_001F2170, WRAP(ang));
    } else {
        sceVu0RotMatrixY(&o->xC0, &D_001F2170, WRAP(DEG(ang)));
    }
}
