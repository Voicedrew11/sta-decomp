#include "m2c.h"
void func_001028F8(f32 (*)[4], s32);
void func_001027B0(f32 *, f32 (*)[4], s32);

s32 func_0014F8C0(s32 arg0, s32 arg1, f32 *box, s32 arg3) {
    f32 m[4][4];
    f32 a[4];
    f32 b[4];

    func_001028F8(m, arg3);
    func_001027B0(a, m, arg0);
    func_001027B0(b, m, arg1);
    if (a[0] < box[0] && b[0] < box[0]) {
        return 0;
    }
    if (a[1] < box[1] && b[1] < box[1]) {
        return 0;
    }
    if (a[2] < box[2] && b[2] < box[2]) {
        return 0;
    }
    if (!(a[0] <= box[4]) && !(b[0] <= box[4])) {
        return 0;
    }
    if (!(a[1] <= box[5]) && !(b[1] <= box[5])) {
        return 0;
    }
    if (!(a[2] <= box[6]) && !(b[2] <= box[6])) {
        return 0;
    }
    return 1;
}
