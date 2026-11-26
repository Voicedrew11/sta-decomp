#include "common.h"
typedef struct { s32 id; } O;
typedef struct { char pad[0x1D8]; u8 b0:1; } O2;
extern O **D_00201E88;
extern O **D_00201E8C;
static inline s32 act(O **p) { return p ? (((O2 *)*p)->b0 != 0) : 0; }
s16 func_001B0BC0(s32 id, s32 base) {
    s32 r = -1;
    if (act(D_00201E88) && (*D_00201E88)->id == id) r = 0;
    if (act(D_00201E8C) && (*D_00201E8C)->id == id) r = 1;
    if (r == -1) return r;
    return base + r * 64;
}
