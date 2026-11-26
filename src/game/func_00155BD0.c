#include "m2c.h"
typedef struct { s32 x, y, z, w; } V4;
typedef struct {
    V4 xy[4];
    s32 prim;
    s32 pad[3];
    V4 uv[3];
    s32 col[4];
} Pkt;
typedef struct {
    s32 x0, x4, x8, xC, x10, x14, x18, x1C, x20, x24, x28, x2C, x30, x34, x38, x3C, x40;
    s32 col;
    s32 x48;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
} Src;
void func_00155DB0(Pkt *);

void func_00155BD0(Src *s) {
    Pkt p;

    p.prim = (u64)6 | ((u64)s->b0 << 3) | ((u64)s->b1 << 4) | ((u64)0 << 5) | ((u64)s->b2 << 6) | ((u64)0 << 7) | ((u64)1 << 8);
    p.col[0] = s->col;
    p.xy[0].z = 0;
    p.xy[0].w = 0x10;
    p.col[1] = s->col;
    p.xy[1].z = 0;
    p.xy[1].w = 0x10;
    p.col[2] = s->col;
    p.xy[2].z = 0;
    p.xy[2].w = 0x10;
    p.col[3] = s->col;
    p.xy[3].z = 0;
    p.xy[3].w = 0x10;
    p.xy[0].x = s->x0;
    p.xy[0].y = s->x4;
    p.xy[1].x = s->x10;
    p.xy[1].y = s->x4;
    p.xy[2].x = s->x0;
    p.xy[2].y = s->x14;
    if (s->b1) {
        p.uv[0].x = s->x20;
        p.uv[0].y = s->x24;
        p.uv[1].x = s->x30;
        p.uv[1].y = s->x24;
        p.uv[2].x = s->x20;
        p.uv[2].y = s->x34;
    }
    func_00155DB0(&p);
    p.xy[0].x = s->x10;
    p.xy[0].y = s->x4;
    p.xy[1].x = s->x10;
    p.xy[1].y = s->x14;
    p.xy[2].x = s->x0;
    p.xy[2].y = s->x14;
    if (s->b1) {
        p.uv[0].x = s->x30;
        p.uv[0].y = s->x24;
        p.uv[1].x = s->x30;
        p.uv[1].y = s->x34;
        p.uv[2].x = s->x20;
        p.uv[2].y = s->x34;
    }
    func_00155DB0(&p);
}
