#include "m2c.h"
typedef struct { s16 x, y; } V;
typedef struct { u8 pad[0x140]; V pos[2][8][11]; V vel[2][8][11]; } W;
extern W D_002F19B0;
extern f32 D_002F2070[];
void func_00123A88(V (*)[11], V (*)[11], s32);
void func_00157FE0(s32);

void func_00157D50(f32 dt) {
    u8 l;
    u8 j;
    u8 i;
    s16 ax;
    s16 ay;

    for (l = 0; l < 2; l++) {
        for (i = 1; i < 7; i++) {
            for (j = 1; j < 10; j++) {
                ax = 0;
                ay = 0;
                ax += D_002F19B0.pos[l][i - 1][j].x;
                ay += D_002F19B0.pos[l][i - 1][j].y;
                ax += D_002F19B0.pos[l][i + 1][j].x;
                ay += D_002F19B0.pos[l][i + 1][j].y;
                ax += D_002F19B0.pos[l][i][j - 1].x;
                ay += D_002F19B0.pos[l][i][j - 1].y;
                ax += D_002F19B0.pos[l][i][j + 1].x;
                ay += D_002F19B0.pos[l][i][j + 1].y;
                ax -= (s16)(D_002F19B0.pos[l][i][j].x * 4);
                ay -= (s16)(D_002F19B0.pos[l][i][j].y * 4);
                D_002F19B0.vel[l][i][j].x += ax;
                D_002F19B0.vel[l][i][j].y += ay;
            }
        }
        for (i = 1; i < 7; i++) {
            for (j = 1; j < 10; j++) {
                D_002F19B0.pos[l][i][j].x += (s16)(0.005f * D_002F19B0.vel[l][i][j].x);
                D_002F19B0.pos[l][i][j].y += (s16)(0.005f * D_002F19B0.vel[l][i][j].y);
            }
        }
    }
    D_002F2070[0] += dt / 100.0f;
    if (D_002F2070[0] > 1.0f) {
        D_002F2070[0] -= 1.0f;
        func_00123A88(D_002F19B0.pos[0], D_002F19B0.pos[1], 0x160);
        func_00123A88(D_002F19B0.vel[0], D_002F19B0.vel[1], 0x160);
        func_00157FE0(1);
    }
}
