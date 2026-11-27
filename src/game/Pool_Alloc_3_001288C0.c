#include "m2c.h"
typedef struct Blk { s32 addr; s32 cur; u32 size; struct Blk *next; s32 pad; u8 bf:2; } Blk;
typedef struct { s32 p0; s32 p4; s32 free; s32 pC; s32 count; s32 p14; u8 flags; Blk *head; Blk *tail; s32 p24; Blk *fb; } Pool;
void FlushCache(s32);
void Dma_SprInit_1_00178D20(void);
void Dma_SprClear_1_00178C00(s32, u32);
void memset(s32, s32, s32);
void Pool_PlanCompact_1_00128460(Pool *, s32);
void Pool_Compact_2_00128210(Pool *);

Blk *Pool_Alloc_3_001288C0(Pool *p, s32 sz) {
    Blk *b;
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
