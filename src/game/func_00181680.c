#include "common.h"
typedef union { u128 q; u32 w[4]; } Q;
typedef struct { f32 x, y; } P2;
extern s32 D_00201CD4;
extern s32 D_00201CD8;
extern s32 D_0020206C;
extern Q D_0048C4B0[][9];
void func_00181420(void);
static inline void rot(P2 *p, f32 *m) {
    P2 t;
    t.x = p->x * m[0] + p->y * m[1];
    t.y = p->x * m[2] + p->y * m[3];
    *p = t;
}

void func_00181680(s32 id, f32 *r, f32 *uv, u8 *col, f32 *m, s32 mode) {
    P2 p0, p1, p2, p3;
    Q q;
    Q *p;
    if (col[3] < 2) return;
    switch (mode) {
    default:
        p0.x = r[0]; p0.y = r[1];
        p1.x = r[0]; p1.y = r[3];
        p2.x = r[2]; p2.y = r[1];
        p3.x = r[2]; p3.y = r[3];
        break;
    case 1:
        p0.x = r[2]; p0.y = r[1];
        p1.x = r[2]; p1.y = r[3];
        p2.x = r[0]; p2.y = r[1];
        p3.x = r[0]; p3.y = r[3];
        break;
    case 2:
        p0.x = r[0]; p0.y = r[3];
        p1.x = r[0]; p1.y = r[1];
        p2.x = r[2]; p2.y = r[3];
        p3.x = r[2]; p3.y = r[1];
        break;
    case 3:
        p0.x = r[2]; p0.y = r[3];
        p1.x = r[2]; p1.y = r[1];
        p2.x = r[0]; p2.y = r[3];
        p3.x = r[0]; p3.y = r[1];
        break;
    }
    rot(&p0, m);
    rot(&p1, m);
    rot(&p2, m);
    rot(&p3, m);
    p0.x += m[4]; p0.y += m[5];
    p1.x += m[4]; p1.y += m[5];
    p2.x += m[4]; p2.y += m[5];
    p3.x += m[4]; p3.y += m[5];
    if (D_00201CD4 != id || D_0020206C >= 16) {
        func_00181420();
        D_00201CD4 = id;
    }
    p = D_0048C4B0[D_0020206C];
    q.w[0] = (((col[3] * D_00201CD8) / 128) << 24) | (col[2] << 16) | (col[1] << 8) | col[0];
    q.w[1] = 0; q.w[2] = 1; q.w[3] = 0;
    p[0] = q;
    q.w[0] = (u32)(16.0f * uv[0]) + 8;
    q.w[1] = (u32)(16.0f * uv[1]) + 8;
    q.w[2] = 0; q.w[3] = 0;
    p[1] = q;
    q.w[0] = (u32)(16.0f * p0.x) + 0x6C00;
    q.w[1] = (u32)(16.0f * p0.y) + 0x7200;
    q.w[2] = 0x10; q.w[3] = -1;
    p[2] = q;
    q.w[0] = (u32)(16.0f * uv[0]) + 8;
    q.w[1] = (u32)(16.0f * (uv[1] + uv[3])) - 8;
    q.w[2] = 0; q.w[3] = 0;
    p[3] = q;
    q.w[0] = (u32)(16.0f * p1.x) + 0x6C00;
    q.w[1] = (u32)(16.0f * p1.y) + 0x7200;
    q.w[2] = 0x10; q.w[3] = -1;
    p[4] = q;
    q.w[0] = (u32)(16.0f * (uv[2] + uv[0])) - 8;
    q.w[1] = (u32)(16.0f * uv[1]) + 8;
    q.w[2] = 0; q.w[3] = 0;
    p[5] = q;
    q.w[0] = (u32)(16.0f * p2.x) + 0x6C00;
    q.w[1] = (u32)(16.0f * p2.y) + 0x7200;
    q.w[2] = 0x10; q.w[3] = 0;
    p[6] = q;
    q.w[0] = (u32)(16.0f * (uv[2] + uv[0])) - 8;
    q.w[1] = (u32)(16.0f * (uv[3] + uv[1])) - 8;
    q.w[2] = 0; q.w[3] = 0;
    p[7] = q;
    q.w[0] = (u32)(16.0f * p3.x) + 0x6C00;
    q.w[1] = (u32)(16.0f * p3.y) + 0x7200;
    q.w[2] = 0x10; q.w[3] = 0;
    p[8] = q;
    D_0020206C++;
}
