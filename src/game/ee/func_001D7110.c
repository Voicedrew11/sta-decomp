#include "common.h"
typedef struct { u8 b[0x24]; } PadData;
typedef struct { u8 p0[0x100]; PadData d; u8 p124[0x58]; u8 x17C; } PadRec;
s32 scePadRead(s32 port, s32 slot, u8 *rdata);

s32 func_001D7110(PadRec *s, s32 port, s32 slot) {
    PadData r;
    s32 id;
    id = s->x17C;
    if (scePadRead(port, slot, (u8 *)&r) == 0) return 0;
    if (r.b[0] == 0) {
        s->x17C = r.b[1] >> 4;
        if (id != 0 && s->x17C != id) return -1;
        s->d = r;
        *(u16 *)&s->d.b[2] = ~*(u16 *)&s->d.b[2];
    }
    return 1;
}
