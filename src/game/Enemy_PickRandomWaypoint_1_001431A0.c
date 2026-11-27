#include "m2c.h"
u8 Enemy_FindNearestWaypoint_1_00143610(void);
u32 Rand_Next_3_0015ED20(void);
typedef struct { u8 pad[0x10]; u8 tbl[1][0x100]; } T;

u8 Enemy_PickRandomWaypoint_1_001431A0(T *arg0) {
    u8 buf[16];
    u8 r;
    u8 n;
    u8 i;
    u8 j;
    u8 c;


    r = Enemy_FindNearestWaypoint_1_00143610();
    if (r != 0xFF) {
        buf[0] = r;
        i = 0;

        n = 1;
        for (; i < 0xFF; i++) {
            c = arg0->tbl[r][i];
            if (c != 0xFF) {
                for (j = 0; j < n; j++) {
                    if (buf[j] == c) {
                        break;
                    }
                }
                if (j == n) {
                buf[n++] = c;
            }
            }
        }
        r = buf[(u8)(Rand_Next_3_0015ED20() % n)];
    }
    return r;
}
