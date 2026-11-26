#include "m2c.h"
typedef struct Blk {
    s32 a;
    s32 b;
    u32 size;
    struct Blk *next;
    s32 x10;
    union { s32 w; struct { u32 st : 2; } f; } x14;
} Blk;
typedef struct Heap {
    s32 x0;
    s32 x4;
    s32 size;
    s32 xC;
    s32 x10;
    s32 x14;
    u8 flags;
    Blk *list;
    Blk *last;
    s32 x24;
    struct Heap *parent;
} Heap;
Blk *func_001288C0(Heap *, u32);
void FlushCache(s32);
void func_001789E0(s32, s32, s32);
void func_00123A88(s32, s32, s32);
static inline s32 avail(Heap *h) {
    s32 v;
    if (h->flags & 1) {
        if (h->x10 == 1 && h->x14 == 0) return 0;
        v = h->size - 0x3F;
    } else {
        if (h->x10 == 1) return 0;
        v = h->parent->size - 0x3F;
    }
    if (v < 0) v = 0;
    return v;
}

s32 func_001285C0(Heap *h, Blk *b, u32 n) {
    Blk *c;
    Blk *prev;
    Blk *p;
    u32 sz;
    s32 t;

    if (avail(h) <= n) return 0;
    if (n == b->size) return 1;
    c = func_001288C0(h, n);
    sz = b->size;
    if (c->size < sz) sz = c->size;
    if ((s32)sz >= 0x1400) {
        FlushCache(0);
        func_001789E0(c->a, b->a, (s32)sz / 16);
    } else {
        func_00123A88(c->a, b->a, sz);
    }
    t = b->a; b->a = c->a; c->a = t;
    t = b->b; b->b = c->b; c->b = t;
    t = b->x14.w; b->x14.w = c->x14.w; c->x14.w = t;
    t = b->size; b->size = c->size; c->size = t;
    prev = NULL;
    for (p = h->list; p != NULL; p = p->next) {
        if (p->next == c) { prev = p; break; }
    }
    if (b == h->list) {
        h->list = c;
    } else {
        for (p = h->list; p != NULL; p = p->next) {
            if (p->next == b) { p->next = c; break; }
        }
    }
    c->next = b->next;
    if (c->next == c) c->next = b;
    if (prev != b) prev->next = b;
    b->next = NULL;
    h->last = b;
    h->size += c->size;
    c->x14.f.st = 1;
    h->x14++;
    return 1;
}
