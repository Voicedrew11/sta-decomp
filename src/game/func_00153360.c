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
s32 func_00128830(s8 *);
void func_001285C0(s8 *, C *, s32);
void FlushCache(s32);
void func_001789E0(s8 *, s8 *, s32);
void func_00123A88(s8 *, s8 *, s32);

void func_00153360(C *c, C *a1, C *a2) {
    u32 esz;
    s32 off;
    s8 *h;
    s32 sz;
    u32 n;
    s32 v;
    s32 k;
    s8 *b;

    switch (c->type) {
    case 1:
        esz = c->esz;
        h = c->heap;
        off = (s8 *)a1 - c->base;
        n = c->size / esz;
        if (n == c->cnt) {
            n *= 2;
            sz = n * esz;
            v = func_00128830(h);
            if (v < sz) {
                sz = v;
                if (v < (s32)(c->size + c->esz)) {
                    goto skip;
                }
            }
            func_001285C0(h, c, sz);
        }
skip:
        k = c->cnt - off / (s32)esz;
        if (k != 0) {
            b = c->base;
            if (!(((s32)b | esz) & 0xF)) {
                sz = esz * k;
                if (sz > 0x1400) {
                    FlushCache(0);
                    func_001789E0(c->base + off + esz, c->base + off, sz / 16);
                } else {
                    func_00123A88(b + off + esz, b + off, sz);
                }
            } else {
                func_00123A88(b + off + esz, b + off, k * esz);
            }
        }
        func_00123A88(c->base + off, (s8 *)a2, esz);
        c->cnt++;
        break;
    case 2:
        a2->type = 2;
        a2->next = a1->next;
        a2->prev = a1;
        if (a1->next == c) {
            c->prev = a2;
        } else {
            a1->next->prev = a2;
        }
        a1->next = a2;
        c->cnt++;
        break;
    }
}
