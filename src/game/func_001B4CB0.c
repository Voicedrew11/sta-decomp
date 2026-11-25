#include "m2c.h"
typedef struct O { s8 pad0[0x10]; f32 pos[3]; s32 x1C; s32 x20; s8 pad24[0x154]; struct O ***x178; s8 pad17C[0x5C]; u8 x1D8; } O;
void func_00102A60(f32 *, f32 *);
void func_00102A18(f32, f32 *, f32 *);
void func_001A5CD0(f32 *);
void func_001AC4A0(f32 *);
void func_00167850(f32 *);
void func_00159460(f32 *);
void func_0015B110(f32 *);
void func_0015C620(f32 *);
void func_0015D5A0(f32 *);
void func_0012F7E0(f32 *);
extern s32 D_00201E80;
extern s32 D_002022C0;
extern f32 D_003139A0[];
extern f32 D_004B4BD0[];
static inline f32 diff(f32 *a, f32 *b) {
    f32 d;
    if ((d = a[0] - b[0]) != 0.0f) return d;
    if ((d = a[1] - b[1]) != 0.0f) return d;
    d = a[2] - b[2];
    return d != 0.0f ? d : 0.0f;
}

void func_001B4CB0(void) {
    f32 v[4];
    s32 side;
    O **pp;
    O *o;

    side = !(&D_00201E80)[1];
    if (D_002022C0 != 0) {
        func_00102A60(v, D_004B4BD0);
        o = *((O ***)(&D_00201E80 + 2))[side];
        if (diff(o->pos, D_003139A0) != 0.0f) {
            func_00102A60(o->pos, D_003139A0);
            o->x1C = 0;
            o->x20 = 2;
            if (o->x1D8 & 1) {
                func_00102A60((f32 *)((s8 *)**o->x178 + 0x30), o->pos);
            }
        }
        func_00102A18(-1.0f, v, v);
        pp = ((O ***)(&D_00201E80 + 2))[!side];
        if (pp != 0) {
            o = *pp;
            if (diff(o->pos, v) != 0.0f) {
                func_00102A60(o->pos, v);
                o->x1C = 0;
                o->x20 = 2;
                if (o->x1D8 & 1) {
                    func_00102A60((f32 *)((s8 *)**o->x178 + 0x30), o->pos);
                }
            }
        }
        func_001A5CD0(v);
        func_001AC4A0(v);
        func_00167850(v);
        func_00159460(v);
        func_0015B110(v);
        func_0015C620(v);
        func_0015D5A0(v);
        func_0012F7E0(v);
        D_002022C0 = -1;
    }
}
