#include "m2c.h"
#include "game/core.h"
typedef ResNode Node;

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
