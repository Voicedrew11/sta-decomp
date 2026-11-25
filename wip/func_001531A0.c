#include "common.h"
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
void func_00123A88(void *, void *, s32);
void func_0010BCA0(s32);
void func_001789E0(void *, void *, s32);
void func_00128580(s32, Node *);
static inline void rm1(s32 qq, u8 *a1) {
    Pool *q = (Pool *)qq;
    s32 total;
    s32 sz;
    s32 off;
    s32 n;
    u8 *base;
    n = q->count;
    base = q->base;
    sz = q->size;
    off = a1 - base;
    n = n - off / sz - 1;
    if (n != 0) {
        if ((((s32)base | sz) & 0xF) == 0) {
            total = sz * n;
            if (total > 0x1400) {
                func_0010BCA0(0);
                func_001789E0(q->base + off, q->base + off + sz, total / 16);
            } else {
                func_00123A88(base + off, base + off + sz, total);
            }
        } else {
            func_00123A88(base + off, base + off + sz, n * sz);
        }
    }
    q->count--;
}
static inline void rm2(s32 qq, Node *a1) {
    Pool *q = (Pool *)qq;
    if (q->head == a1) q->head = a1->next;
    a1->next->prev = a1->prev;
    a1->prev->next = a1->next;
    func_00128580(q->x1C, a1);
    q->count--;
}
void func_001531A0(Pool *p, u8 *a1) {
    switch (p->state) {
    case 1:
        rm1((s32)p, a1);
        break;
    case 2:
        rm2((s32)p, (Node *)a1);
        break;
    }
}
