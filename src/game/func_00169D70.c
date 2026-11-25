#include "m2c.h"
typedef struct Node { s32 id; s32 size; u32 lo:8; u32 off:24; u16 pad; u16 count; } Node;
typedef struct { u8 pad[0x22]; s16 x22; } Obj;
typedef struct { Obj *obj; } Blk;
extern const s8 D_001FB8F0[];
extern s8 D_001FB8F1[];
extern s8 D_001FB8F2[];
extern s8 D_001FB8F3[];
extern s32 D_00201CB8;
extern u8 D_0042D7E0[];
extern Node *func_0014DCD0(Node *, s32);
extern Blk *func_00170000(u8 *, s32 *, Node *);

s32 func_00169D70(s32 *a0, Blk **a1, u32 n) {
    Node *h;
    s32 cnt;
    Node *p;
    u32 i;
    Blk *b;
    h = func_0014DCD0((Node *)*a0, D_00201CB8);
    for (i = 0; i < n; i++) {
        a1[i] = 0;
    }
    if (h == NULL) return 0;
    cnt = 0;
    p = (Node *)((s8 *)h + h->off);
    for (i = 0; i < h->count; i++) {
        if (p->id == (D_001FB8F0[0] | (((const s8 *)D_001FB8F0)[1] << 8) | (((const s8 *)D_001FB8F0)[2] << 16) | (((const s8 *)D_001FB8F0)[3] << 24))) {
            b = func_00170000(D_0042D7E0, a0, p);
            b->obj->x22++;
            *a1++ = b;
            cnt++;
        }
        p = (Node *)((s8 *)p + p->size);
    }
    return cnt;
}
