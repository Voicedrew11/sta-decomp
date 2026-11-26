#include "m2c.h"
f32 fabsf(f32);

f32 func_00187770(f32 cur, f32 tgt, f32 spd) {
    f32 d = tgt - cur;
    f32 s;
    if (fabsf(d) > 0.6f) {
        s = 1.0f / spd;
        if (d > 0.0f) {
            cur += s;
        } else {
            cur -= s;
        }
        if (d > 0.0f) {
            if (tgt - cur > 0.0f) {
                cur = cur;
            } else {
                cur = tgt;
            }
        } else {
            if (tgt - cur < 0.0f) {
                cur = cur;
            } else {
                cur = tgt;
            }
        }
    } else {
        cur += d / spd;
        if (fabsf(tgt - cur) < 0.003f) {
            cur = tgt;
        }
    }
    return cur;
}
