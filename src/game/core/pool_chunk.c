#include "common.h"
#include "m2c.h"
typedef struct Node {
    u8 pad[0x20];
    struct Node *next;
    struct Node *prev;
} Node;
typedef struct {
    u8 *base;
    u8 pad4[0x14];
    u32 state : 8;
    u32 count : 24;
    s32 x1C;
    s32 pad20;
    Node *head;
    s32 pad28;
    s32 size;
} Pool;
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
typedef struct { char pad[0x18]; u32 a : 8; u32 b : 24; s32 x1c; void *p20; void *p24; } Obj;
void Pool_FreeChunk_0_001531A0(Pool *p, u8 *a1);
void Pool_GrowArray_1_00153360(C *c, C *a1, C *a2);
void Pool_ArrayAppend_0_001535B0(C *c, s8 *a1);
void Pool_MarkDead_0_001536F0(s32 x, Obj *o);
void memcpy(void *, void *, s32);
void FlushCache(s32);
void Dma_SprCopy_1_001789E0(void *, void *, s32);
void Pool_Free_2_00128580(s32, Node *);
s32 Pool_GetBlockUsable_1_00128830(s8 *);
void Pool_Realloc_2_001285C0(s8 *, C *, s32);

/* Pool_FreeChunk_0_001531A0 */
static inline void rm1(s32 qq, u8 *a1) {
    Pool *q = (Pool *)qq;
    s32 total;
    s32 sz;
    s32 off;
    s32 n;
    u8 *base;
    sz = q->size;
    base = q->base;
    n = q->count;
    off = a1 - base;
    n = n - off / sz - 1;
    if (n != 0) {
        if ((((s32)base | sz) & 0xF) == 0) {
            total = sz * n;
            if (total > 0x1400) {
                FlushCache(0);
                Dma_SprCopy_1_001789E0(q->base + off, q->base + off + sz, total / 16);
            } else {
                memcpy(base + off, base + off + sz, total);
            }
        } else {
            memcpy(base + off, base + off + sz, n * sz);
        }
    }
    q->count--;
}
static inline void rm2(s32 qq, Node *a1) {
    Pool *q = (Pool *)qq;
    if (q->head == a1) q->head = a1->next;
    a1->next->prev = a1->prev;
    a1->prev->next = a1->next;
    Pool_Free_2_00128580(q->x1C, a1);
    q->count--;
}
void Pool_FreeChunk_0_001531A0(Pool *p, u8 *a1) {
    switch (p->state) {
    case 1:
        rm1((s32)p, a1);
        break;
    case 2:
        rm2((s32)p, (Node *)a1);
        break;
    }
}

/* Pool_GrowArray_1_00153360 */
#define Dma_SprCopy_1_001789E0 Dma_SprCopy_1_001789E0__as_Pool_GrowArray_1_00153360
void Dma_SprCopy_1_001789E0__as_Pool_GrowArray_1_00153360(s8 *, s8 *, s32);
#define memcpy memcpy__as_Pool_GrowArray_1_00153360
void memcpy__as_Pool_GrowArray_1_00153360(s8 *, s8 *, s32);

void Pool_GrowArray_1_00153360(C *c, C *a1, C *a2) {
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
        k = c->cnt - off / (s32)esz;
        if (k != 0) {
            b = c->base;
            if (!(((s32)b | esz) & 0xF)) {
                sz = esz * k;
                if (sz > 0x1400) {
                    FlushCache(0);
                    Dma_SprCopy_1_001789E0(c->base + off + esz, c->base + off, sz / 16);
                } else {
                    memcpy(b + off + esz, b + off, sz);
                }
            } else {
                memcpy(b + off + esz, b + off, k * esz);
            }
        }
        memcpy(c->base + off, (s8 *)a2, esz);
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
#undef Dma_SprCopy_1_001789E0
#undef memcpy

/* Pool_ArrayAppend_0_001535B0 */
#define memcpy memcpy__as_Pool_ArrayAppend_0_001535B0
void memcpy__as_Pool_ArrayAppend_0_001535B0(s8 *, s8 *, s32);
#define Pool_GrowArray_1_00153360 Pool_GrowArray_1_00153360__as_Pool_ArrayAppend_0_001535B0
void Pool_GrowArray_1_00153360__as_Pool_ArrayAppend_0_001535B0(C *, C *, s8 *);

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
#undef memcpy
#undef Pool_GrowArray_1_00153360

/* Pool_MarkDead_0_001536F0 */
void Pool_MarkDead_0_001536F0(s32 x, Obj *o)
{
    o->a = 2;
    o->b = 0;
    o->p20 = o;
    o->p24 = o;
    o->x1c = x;
}
