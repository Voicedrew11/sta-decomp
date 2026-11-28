#include "m2c.h"
#include "common.h"
#include "game/core.h"
typedef struct Node_Pool_Compact_2_00128210 {
    s32 dst;
    s32 src;
    u32 size;
    struct Node_Pool_Compact_2_00128210 *next;
    s32 pad10;
    u8 state:2;
    u8 rest:6;
} Node_Pool_Compact_2_00128210;
typedef struct {
    s32 pad[4];
    s32 nfree;
    s32 nused;
    u8 b0:1;
    u8 b1:1;
    u8 b2:1;
    u8 b3:1;
    u8 b4:1;
    u8 b5:3;
    Node_Pool_Compact_2_00128210 *head;
    Node_Pool_Compact_2_00128210 *tail;
    Node_Pool_Compact_2_00128210 *dead;
    Node_Pool_Compact_2_00128210 *sent;
} Pool_Pool_Compact_2_00128210;
typedef struct Node_Pool_PlanCompact_1_00128460 { s32 a; s32 b; s32 size; struct Node_Pool_PlanCompact_1_00128460 *next; s32 pad; u8 st:2; u8 rest:6; } Node_Pool_PlanCompact_1_00128460;
typedef struct { u8 pad[0x14]; s32 count; u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 rest:3; u8 pad2[3]; Node_Pool_PlanCompact_1_00128460 *head; } Obj;
typedef struct { char pad[8]; s32 n; char p2[8]; unsigned char f : 2; } B;
typedef struct { char pad[8]; u32 n; char p2[8]; s32 count; } A;
typedef struct Blk_Pool_Realloc_2_001285C0 {
    s32 a;
    s32 b;
    u32 size;
    struct Blk_Pool_Realloc_2_001285C0 *next;
    s32 x10;
    union { s32 w; struct { u32 st : 2; } f; } x14;
} Blk_Pool_Realloc_2_001285C0;
typedef struct Heap {
    s32 x0;
    s32 x4;
    s32 size;
    s32 xC;
    s32 x10;
    s32 x14;
    u8 flags;
    Blk_Pool_Realloc_2_001285C0 *list;
    Blk_Pool_Realloc_2_001285C0 *last;
    s32 x24;
    struct Heap *parent;
} Heap;
typedef struct Blk_Pool_Alloc_3_001288C0 { s32 addr; s32 cur; u32 size; struct Blk_Pool_Alloc_3_001288C0 *next; s32 pad; u8 bf:2; } Blk_Pool_Alloc_3_001288C0;
typedef struct { s32 p0; s32 p4; s32 free; s32 pC; s32 count; s32 p14; u8 flags; Blk_Pool_Alloc_3_001288C0 *head; Blk_Pool_Alloc_3_001288C0 *tail; s32 p24; Blk_Pool_Alloc_3_001288C0 *fb; } Pool_Pool_Alloc_3_001288C0;
typedef struct E {
    struct E *x0;
    struct E *x4;
    struct E *x8;
    struct E *xC;
    u8 pad10[4];
    u8 b0:2;
    u8 b2:6;
    u8 pad15[0x1B];
} E;
typedef struct {
    E *x0;
    E *x4;
    E *x8;
    s32 xC;
    s32 x10;
    s32 x14;
    u8 b0:1;
    u8 b1:1;
    u8 b2:1;
    u8 b3:1;
    u8 b4:1;
    u8 b5:3;
    s32 x1C;
    s32 x20;
    E *x24;
    E *x28;
} S;
s32 Pool_Compact_2_00128210(Pool_Pool_Compact_2_00128210 *p);
void Pool_PlanCompact_1_00128460(Obj *o, u32 limit);
void Pool_Free_2_00128580(A *a, B *b);
s32 Pool_Realloc_2_001285C0(Heap *h, Blk_Pool_Realloc_2_001285C0 *b, u32 n);
s32 Pool_GetBlockUsable_1_00128830(void *arg0);
Blk_Pool_Alloc_3_001288C0* Pool_Alloc_3_001288C0(Pool_Pool_Alloc_3_001288C0 *p, s32 sz);
void Pool_Init_2_00128A60(S *a0, E *a1, E *a2, u32 a3);
void FlushCache(s32, s32, u32);
void Dma_SprCopy_1_001789E0(s32, s32, u32);
void memcpy(s32, s32, u32);
void memset(s32, s32, s32);

/* Pool_Compact_2_00128210 */
s32 Pool_Compact_2_00128210(Pool_Pool_Compact_2_00128210 *p) {
    u32 flag;
    Node_Pool_Compact_2_00128210 *n;
    Node_Pool_Compact_2_00128210 *next;
    Node_Pool_Compact_2_00128210 *prev;
    s32 dst, src;
    u32 size;
    flag = p->b2;
    if (p->b3) return 0;
    if (p->nused == 0) {
        p->b1 = 0;
        return 1;
    }
    prev = NULL;
    for (n = p->head; n != NULL; n = next) {
        next = n->next;
        if (n->state == 2) {
            if (prev == NULL) p->head = next;
            else prev->next = next;
            if (n == p->tail) p->tail = prev;
            n->next = p->dead;
            p->dead = n;
        } else {
            dst = n->dst;
            src = n->src;
            if (src != dst) {
                size = n->size;
                if (size >= 0x1400 && dst - src > 0) {
                    FlushCache(0, dst, size);
                    Dma_SprCopy_1_001789E0(n->src, n->dst, n->size >> 4);
                } else {
                    memcpy(src, dst, size);
                }
                n->dst = n->src;
            }
            prev = n;
        }
    }
    p->b1 = 0;
    p->b2 = 0;
    if (flag) {
        {
            Node_Pool_Compact_2_00128210 *mn, *m;
            m = p->dead;
            if (m != p->sent) {
                do {
                    mn = m->next;
                p->sent->dst -= m->size;
                p->sent->size += m->size;
                m->dst = 0;
                m->src = 0;
                m->size = 0;
                m->state = 0;
                m->next = p->sent->next;
                p->sent->next = m;
                p->nfree++;
                p->nused--;
                    m = mn;
                } while (mn != p->sent);
            }
        }
        p->dead = p->sent;
    }
    p->b4 = 0;
    return flag;
}

/* Pool_PlanCompact_1_00128460 */
void Pool_PlanCompact_1_00128460(Obj *o, u32 limit) {
    s32 acc = 0;
    u32 sum = 0;
    Node_Pool_PlanCompact_1_00128460 *n;
    Node_Pool_PlanCompact_1_00128460 *next;

    if (o->b3 == 0) {
        o->b4 = 0;
        if (o->count == 0) {
            o->b1 = 1;
            return;
        }
        for (n = o->head; n != NULL; n = next) {
            next = n->next;
            if (n->st) {
                acc += n->size;
                n->st = 2;
                continue;
            }
            if (acc == 0) continue;
            n->b = n->a - acc;
            sum += n->size;
            if (!(sum < limit)) break;
        }
        if (n == NULL) {
            o->b2 = 1;
        }
        o->b1 = 1;
        o->b4 = 1;
    }
}

/* Pool_Free_2_00128580 */
void Pool_Free_2_00128580(A *a, B *b) { a->n = b->n + a->n; b->f = 1; a->count++; }

/* Pool_Realloc_2_001285C0 */
#define Pool_Alloc_3_001288C0 Pool_Alloc_3_001288C0__as_Pool_Realloc_2_001285C0
Blk_Pool_Realloc_2_001285C0 *Pool_Alloc_3_001288C0__as_Pool_Realloc_2_001285C0(Heap *, u32);
#define FlushCache FlushCache__as_Pool_Realloc_2_001285C0
void FlushCache__as_Pool_Realloc_2_001285C0(s32);
#define Dma_SprCopy_1_001789E0 Dma_SprCopy_1_001789E0__as_Pool_Realloc_2_001285C0
void Dma_SprCopy_1_001789E0__as_Pool_Realloc_2_001285C0(s32, s32, s32);
#define memcpy memcpy__as_Pool_Realloc_2_001285C0
void memcpy__as_Pool_Realloc_2_001285C0(s32, s32, s32);
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

s32 Pool_Realloc_2_001285C0(Heap *h, Blk_Pool_Realloc_2_001285C0 *b, u32 n) {
    Blk_Pool_Realloc_2_001285C0 *c;
    Blk_Pool_Realloc_2_001285C0 *prev;
    Blk_Pool_Realloc_2_001285C0 *p;
    u32 sz;
    s32 t;

    if (avail(h) <= n) return 0;
    if (n == b->size) return 1;
    c = Pool_Alloc_3_001288C0(h, n);
    sz = b->size;
    if (c->size < sz) sz = c->size;
    if ((s32)sz >= 0x1400) {
        FlushCache(0);
        Dma_SprCopy_1_001789E0(c->a, b->a, (s32)sz / 16);
    } else {
        memcpy(c->a, b->a, sz);
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
#undef Pool_Alloc_3_001288C0
#undef FlushCache
#undef Dma_SprCopy_1_001789E0
#undef memcpy

/* Pool_GetBlockUsable_1_00128830 */
s32 Pool_GetBlockUsable_1_00128830(void *arg0) {
    s32 var_2;

    if (M2C_FIELD(arg0, u8 *, 0x18) & 1) {
        if ((M2C_FIELD(arg0, s32 *, 0x10) == 1) && (M2C_FIELD(arg0, s32 *, 0x14) == 0)) {
            return 0;
        }
        var_2 = M2C_FIELD(arg0, s32 *, 8) - 0x3F;
        goto block_10;
    }
    if (M2C_FIELD(arg0, s32 *, 0x10) == 1) {
        return 0;
    }
    var_2 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x28), s32 *, 8) - 0x3F;
block_10:
    if (var_2 < 0) {
        var_2 = 0;
    }
    return var_2;
}

/* Pool_Alloc_3_001288C0 */
#define FlushCache FlushCache__as_Pool_Alloc_3_001288C0
void FlushCache__as_Pool_Alloc_3_001288C0(s32);
#define Pool_PlanCompact_1_00128460 Pool_PlanCompact_1_00128460__as_Pool_Alloc_3_001288C0
void Pool_PlanCompact_1_00128460__as_Pool_Alloc_3_001288C0(Pool_Pool_Alloc_3_001288C0 *, s32);
#define Pool_Compact_2_00128210 Pool_Compact_2_00128210__as_Pool_Alloc_3_001288C0
void Pool_Compact_2_00128210__as_Pool_Alloc_3_001288C0(Pool_Pool_Alloc_3_001288C0 *);

Blk_Pool_Alloc_3_001288C0 *Pool_Alloc_3_001288C0(Pool_Pool_Alloc_3_001288C0 *p, s32 sz) {
    Blk_Pool_Alloc_3_001288C0 *b;
    sz = (sz + 0x3F) & ~0x3F;
    if (p->free < sz) {
        return NULL;
    }
    if (p->fb->size < (u32)sz || p->count < 2) {
        if (p->flags & 1) {
            Pool_PlanCompact_1_00128460(p, -1);
            Pool_Compact_2_00128210(p);
        } else {
            return NULL;
        }
    }
    b = p->fb->next;
    p->free -= sz;
    p->count--;
    b->addr = p->fb->addr;
    p->fb->next = b->next;
    p->fb->size -= sz;
    p->fb->addr += sz;
    if (p->head == NULL) {
        p->head = b;
    }
    if (p->tail != NULL) {
        p->tail->next = b;
    }
    p->tail = b;
    if ((u32)sz >= 0x1400) {
        FlushCache(0);
        Dma_SprInit_1_00178D20();
        Dma_SprClear_1_00178C00(b->addr, sz);
    } else {
        memset(b->addr, 0, sz);
    }
    b->cur = b->addr;
    b->size = sz;
    b->bf = 0;
    b->next = NULL;
    return b;
}
#undef FlushCache
#undef Pool_PlanCompact_1_00128460
#undef Pool_Compact_2_00128210

/* Pool_Init_2_00128A60 */
void Pool_Init_2_00128A60(S *a0, E *a1, E *a2, u32 a3) {
    s32 i;
    a0->x0 = a1;
    a0->x4 = a2;
    a0->x8 = a2 - a3;
    a0->xC = a3;
    a0->x10 = a3;
    a0->x14 = 0;
    a0->x1C = 0;
    a0->x20 = 0;
    a0->b1 = 0;
    a0->b2 = 0;
    a0->b0 = 0;
    a0->b3 = 0;
    a0->b4 = 0;
    a0->x28 = a1;
    for (i = 0; i < (s32)a3; i++) {
        a1->x0 = 0;
        a1->x4 = 0;
        a1->x8 = 0;
        a1->b0 = 0;
        a1->xC = a1 + 1;
        a1 += 1;
    }
    a0->x28->x0 = a0->x0 + a3;
    a0->x28->x4 = a0->x28->x0;
    a0->x28->x8 = a0->x8;
    a1[-1].xC = 0;
    a0->x24 = a0->x28;
}
