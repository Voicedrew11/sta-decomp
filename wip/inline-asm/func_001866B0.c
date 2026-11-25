#include "m2c.h"
static inline u32 get(u16 *p, s32 i) { return p ? p[i] : 0; }
static inline u32 mk(u32 lo, u32 hi) { return (u16)lo | ((u16)hi << 16); }

u32 func_001866B0(s32 a0, u16 *a1, u16 *a2, u16 *a3, u16 *t0) {
    u32 t;
    u16 lo, hi;
    asm("addi %0, %1, -3001" : "=r"(t) : "r"(a0));
    switch (t) {
    case 0:
        return mk(get(a1, 0), get(a3, 0));
    case 1:
        return mk(get(a1, 1), get(a3, 1));
    case 2:
        return mk(get(a1, 2), get(a3, 2));
    case 3:
        return mk(get(a1, 3), get(a3, 3));
    case 4:
        return mk(get(a1, 4), get(a3, 4));
    case 5:
        return mk(get(a1, 5), get(a3, 5));
    case 6:
        return mk(get(a1, 6), get(a3, 6));
    case 7:
        return mk(get(a1, 7), get(a3, 7));
    case 10:
        return mk(get(a2, 0), get(t0, 0));
    case 11:
        return mk(get(a2, 1), get(t0, 1));
    case 12:
        return mk(get(a2, 2), get(t0, 2));
    case 13:
        return mk(get(a2, 3), get(t0, 3));
    case 14:
        return mk(get(a2, 4), get(t0, 4));
    case 15:
        return mk(get(a2, 5), get(t0, 5));
    case 8: case 9:
    default:
        return 0;
    }
}
