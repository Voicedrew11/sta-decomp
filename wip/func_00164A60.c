#include "common.h"
/* NEAR: 36/81 words differ. Shape is right (s32 i vs 40u gives the target's 8x unroll + remainder loop,
 * `p += 1` gives the in-place pointer IV, `h = R; h = h ^ q[i];` matches the q tail). Remaining diff:
 * register naming / xor operand order inside the unrolled main body and remainder ordering. */
u32 func_00164A60(u32 h, u32 *p, u32 *q) {
    s32 i;
    for (i = 0; i < 40u; i++) {
        h = ((h >> 24) | (h << 8)) ^ *p;
        p += 1;
    }
    for (i = 0; i < 4; i++) {
        h = ((h >> 24) | (h << 8));
        h = h ^ q[i];
    }
    return h;
}
