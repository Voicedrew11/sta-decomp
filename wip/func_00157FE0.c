

#include "m2c.h"
typedef struct { s16 x, y; } P;
typedef struct { P a[11]; } R;
typedef struct { u8 x[0x160]; } R2;
extern u8 D_002F19B0[];
u32 func_0015ED20(void);

void func_00157FE0(u8 a0) {
    u8 j;
    u8 i;
    u8 *r;
    P *p;

    r = D_002F19B0 + a0 * 0x160;
    for (i = 0; i < 8; i++) {
        for (j = 0, p = (P *)r; j < 11; j++) {
            p[0x100].x = 0;
            p[0x100].y = 0;
            if (i == 0 || i == 7 || j == 0 || j == 10) {
                p[0x50].x = 0;
                p[0x50].y = 0;
            } else {
                p[0x50].x = (func_0015ED20() & 0x3FF) - 0x200;
                p[0x50].y = (func_0015ED20() & 0x3FF) - 0x200;
            }
            p++;
        }
        r += 0x2C;
    }
}
