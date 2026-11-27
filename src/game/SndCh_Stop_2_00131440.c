#include "common.h"
typedef struct { u8 pad[0xE]; s8 xE; u8 rest[0x71]; } E;
extern E D_0022CBC0[];
s32 SndCh_Stop_2_00131440(s32 arg0) {
    E *e;
    if (!(0 > arg0) && arg0 < 0x3F) e = &D_0022CBC0[arg0]; else e = NULL;
    if (e != NULL) {
        e->xE = 1;
        return 0;
    }
    return -1;
}
