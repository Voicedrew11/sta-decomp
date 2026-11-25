#include "m2c.h"
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
void func_0018A310(s32);
void func_0017F5C0(void);
void func_00185390(f32, s32, s32, s32);
void func_001875C0(f32, s32, f32, f32, u32, u32);
f32 func_00187770(f32, f32, f32);
extern f32 D_00201D30;
extern s32 D_00202154;
extern Pack1952B0 **D_00202180;
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
