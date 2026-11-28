#include "m2c.h"
typedef struct Node { s32 id; s32 size; u32 lo:8; u32 off:24; u16 pad; u16 count; } Node;

Node *Node_FindById_2_0014DCD0(Node *n, s32 id) {
    u32 j;
    Node *c;
    Node *r;
    u32 i;
    u16 cnt;
    c = (Node *)((s8 *)n + n->off);
    r = c;
    if (n->id == id) return n;
    if (n->id == id) return n;
    cnt = n->count;
    for (i = 0; i < cnt; i++) {
        if (r->id == id) return r;
        r = (Node *)((s8 *)r + r->size);
    }
    for (j = 0; j < n->count; j++) {
        r = Node_FindById_2_0014DCD0(c, id);
        if (r != NULL) return r;
        c = (Node *)((s8 *)c + c->size);
    }
    return NULL;
}
