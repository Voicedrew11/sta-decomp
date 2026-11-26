#include "common.h"
typedef struct { s32 src; s32 dst; s32 size; s32 attr; } Dma;
void FlushCache(s32);
s32 sceSifDmaStat(s32);
s32 sceSifSetDma(Dma *, s32);

static inline void dma(s32 src, s32 dst, s32 size) {
    Dma d;
    s32 id;
    d.src = src;
    d.dst = dst;
    d.size = size;
    d.attr = 0;
    FlushCache(0);
    id = sceSifSetDma(&d, 1);
    while (sceSifDmaStat(id) >= 0) {}
}

s32 func_001EB540(s32 p1, s32 n1, s32 p2, s32 n2, s32 s1, s32 l1, s32 s2, s32 l2) {
    s32 e;
    if (n1 + n2 < l1 + l2) {
        e = (l1 + l2) - (n1 + n2);
        if (e >= l2) {
            l1 -= e - l2;
            l2 = 0;
        } else {
            l2 -= e;
        }
    }
    if (l1 >= n1) {
        if (n1 > 0) dma(s1, p1, n1);
        if (l1 - n1 > 0) dma(s1 + n1, p2, l1 - n1);
        if (l2 > 0) dma(s2, p2 + l1 - n1, l2);
    } else if (l2 >= n1 - l1) {
        if (l1 > 0) dma(s1, p1, l1);
        if (n1 - l1 > 0) dma(s2, p1 + l1, n1 - l1);
        if (l2 - (n1 - l1) > 0) dma(s2 + n1 - l1, p2, l2 - (n1 - l1));
    } else {
        if (l1 > 0) dma(s1, p1, l1);
        if (l2 > 0) dma(s2, p1 + l1, l2);
    }
    return l1 + l2;
}
