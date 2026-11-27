#include "m2c.h"
typedef struct C {
    s8 *base;
    s32 p4;
    s32 size;
    u8 padC[0xC];
    u32 type:8;
    u32 cnt:24;
    s8 *heap;
    struct C *next;
    struct C *prev;
    s32 p28;
    u32 esz;
} C;
s32 Pool_GetBlockUsable_1_00128830(s8 *);
void Pool_Realloc_2_001285C0(s8 *, C *, s32);
void memcpy(s8 *, s8 *, s32);
void Pool_GrowArray_1_00153360(C *, C *, s8 *);

void Pool_ArrayAppend_0_001535B0(C *c, s8 *a1) {
    u32 esz;
    s8 *h;
    s32 sz;
    u32 n;
    s32 v;

    switch (c->type) {
    case 1:
        esz = c->esz;
        h = c->heap;
        n = c->size / esz;
        if (n == c->cnt) {
            n *= 2;
            sz = n * esz;
            v = Pool_GetBlockUsable_1_00128830(h);
            if (v < sz) {
                sz = v;
                if (v < (s32)(c->size + c->esz)) {
                    goto skip;
                }
            }
            Pool_Realloc_2_001285C0(h, c, sz);
        }
skip:
        memcpy(c->base + c->cnt * c->esz, a1, c->esz);
        c->cnt++;
        break;
    case 2:
        Pool_GrowArray_1_00153360(c, c, a1);
        break;
    }
}
