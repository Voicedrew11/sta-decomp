#include "m2c.h"
typedef struct { s16 x, y; } V;
typedef struct { u8 pad[0x140]; V pos[2][8][11]; V vel[2][8][11]; } W;
extern W D_002F19B0;
u32 func_0015ED20(void);

void func_00157FE0(u8 a0) {
    u8 j;
    u8 i;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 11; j++) {
            D_002F19B0.vel[a0][i][j].x = 0;
            D_002F19B0.vel[a0][i][j].y = 0;
            if (i == 0 || i == 7 || j == 0 || j == 10) {
                D_002F19B0.pos[a0][i][j].x = 0;
                D_002F19B0.pos[a0][i][j].y = 0;
            } else {
                D_002F19B0.pos[a0][i][j].x = (func_0015ED20() & 0x3FF) - 0x200;
                D_002F19B0.pos[a0][i][j].y = (func_0015ED20() & 0x3FF) - 0x200;
            }
        }
    }
}
