#include "m2c.h"

s32 func_0014F0C0(f32 *a, f32 *b, f32 *box, f32 r) {
    if (a[0] + r < box[0] && b[0] + r < box[0]) {
        return 0;
    }
    if (a[1] + r < box[1] && b[1] + r < box[1]) {
        return 0;
    }
    if (a[2] + r < box[2] && b[2] + r < box[2]) {
        return 0;
    }
    if (!(a[0] - r <= box[4]) && !(b[0] - r <= box[4])) {
        return 0;
    }
    if (!(a[1] - r <= box[5]) && !(b[1] - r <= box[5])) {
        return 0;
    }
    if (!(a[2] - r <= box[6]) && !(b[2] - r <= box[6])) {
        return 0;
    }
    return 1;
}
