#include "m2c.h"
typedef struct Node { s32 id; s32 next; u32 lo:8; u32 child:24; u16 pC; u16 cnt; s32 p10[3]; s32 size; } Node;
typedef struct { s32 off; s32 p4; s32 p8; s8 c; s8 d; s8 pad[0x72]; } Ent;
extern s32 D_00201CAC;
extern s32 D_00201CB0;

typedef struct { s32 a, b, c, size; } Hdr;
static inline s32 hend(Hdr *h) { return (s32)h + 0x10 + ((h->size + 0xF) & ~0xF); }
s8 func_0016A9D0(s8 *base, Node *n, s8 idx, Ent *tbl) {
    Node *c = (Node *)((s8 *)n + n->child);
    s32 i;
    s8 cur;

    if (n->id != D_00201CAC && n->id != D_00201CB0) {
        return idx;
    }
    if (n->cnt != 0) {
        tbl[idx].c = idx + 1;
    }
    tbl[idx].off = hend((Hdr *)((s8 *)n + 0x10)) - (s32)base;
    idx++;
    for (i = 0; i < n->cnt; i++) {
        cur = idx;
        idx = func_0016A9D0(base, c, idx, tbl);
        if (i != n->cnt - 1) {
            c = (Node *)((s8 *)c + c->next);
            if (c->id != D_00201CB0) {
                return idx;
            }
            tbl[cur].d = idx;
        }
    }
    return idx;
}

