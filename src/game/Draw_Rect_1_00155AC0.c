#include "m2c.h"
typedef struct { s32 x, y, z, w; } V4;
typedef struct {
    V4 xy[4];
    s32 prim;
    s32 pad[3];
    V4 uv[3];
    s32 col[4];
} Pkt;
void Draw_Prim_1_00155DB0(Pkt *);

void Draw_Rect_1_00155AC0(s32 a0, s32 a1, s32 a2, s32 a3, s32 col) {
    Pkt p;
    s32 x0, y0, x1, y1;
    p.prim = 0x46;
    p.col[0] = col;
    p.xy[0].z = 0;
    p.xy[0].w = 0x10;
    p.col[1] = col;
    p.xy[1].z = 0;
    p.xy[1].w = 0x10;
    p.col[2] = col;
    p.xy[2].z = 0;
    p.xy[2].w = 0x10;
    p.col[3] = col;
    p.xy[3].z = 0;
    p.xy[3].w = 0x10;
    x0 = a0 * 16 + 0x6C00;
    y0 = a1 * 16 + 0x7200;
    x1 = a2 * 16 + 0x6C00;
    y1 = a3 * 16 + 0x7200;
    p.xy[0].x = x0;
    p.xy[0].y = y0;
    p.xy[1].x = x1;
    p.xy[1].y = y0;
    p.xy[2].x = x0;
    p.xy[2].y = y1;
    Draw_Prim_1_00155DB0(&p);
    p.xy[0].x = x1;
    p.xy[0].y = y0;
    p.xy[1].x = x1;
    p.xy[1].y = y1;
    p.xy[2].x = x0;
    p.xy[2].y = y1;
    Draw_Prim_1_00155DB0(&p);
}
