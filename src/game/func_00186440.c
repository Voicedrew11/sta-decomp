#include "m2c.h"
typedef struct { s32 idx; s32 x4; u8 pad[0x24]; f32 x2C; f32 x30; u8 pad34[0xC]; } Elem;
typedef struct { u32 n; Elem *e; } List;
typedef struct { u8 pad[0x10]; List *list; } Ctx;
typedef struct { f32 x, y; } V2;
Ctx *func_00189050(s32);
s32 func_00189020(s32);
f32 atanf(f32);
f32 sinf(f32);
f32 cosf(f32);
float sqrtf(float);
s32 func_001866B0(s32, s32, s32, s32, s32);
void func_00186990();
void func_001829B0(Elem *, s32, void (*)(), s32);
static inline f32 d2d(f32 x, f32 y, f32 cx, f32 cy) { f32 u = x - cx; f32 v = y - cy; return sqrtf(u * u + v * v); }

void func_00186440(s32 a0, s32 a1, s32 a2, s32 a3, f32 f) {
    Elem el;
    u32 i;
    List *list;
    s32 base;
    f32 dist;
    f32 dx;
    f32 dy;
    f32 ang;
    f32 px;
    f32 py;

    list = func_00189050(0)->list;
    base = func_00189020(0);
    for (i = 0; i < list->n; i++) {
        el = list->e[i];
        {
        V2 c = {0};
        c.x = -70.0f;
        c.y = 276.0f;
        px = el.x2C;
        py = el.x30;
        dist = d2d(px, py, -70.0f, 276.0f);
        dx = px - c.x;
        dy = py - c.y;
        if (dx == 0.0f) {
            ang = 0.0f;
        } else {
            ang = atanf(dx / dy);
        }
        if (dy < 0.0f) {
            ang += 3.141592f;
        }
        dy = ang + f;
        el.x2C = -70.0f + dist * sinf(dy);
        el.x30 = 276.0f + dist * cosf(dy);
        }
        func_001829B0(&el, base + list->e[i].idx * 8, func_00186990, func_001866B0(el.x4, a0, a1, a2, a3));
    }
}
