#include "m2c.h"
typedef struct Node { s32 id; s32 size; u32 lo:8; u32 off:24; u16 pad; u16 count; s32 x10, x14, x18; } Node;
extern s32 D_00201CA8;
extern s32 D_00201CAC;
extern s8 D_001FB8D0[];
extern Node *Node_FindById_2_0014DCD0(Node *, s32);
s32 Sfx_Create_2_00169F40(s32 *, s32, s32, s32, s32, s32, u16);
void sprintf(s8 *, s8 *, s32);

s32 Sfx_SpawnFromStam_2_00169BD0(s32 id, s32 *a1, s32 a2, s32 a3, s32 a4, s32 a5) {
    Node *h;
    Node *p;
    u32 i;
    s8 buf[256];
    h = Node_FindById_2_0014DCD0((Node *)*a1, D_00201CA8);
    if (id == 0) return 0;
    if (h == NULL) return 0;
    p = (Node *)((s8 *)h + h->off);
    for (i = 0; i < h->count; i++) {
        if (p->id == D_00201CAC && p->x18 == id) {
            return Sfx_Create_2_00169F40(a1, (s32)p - *a1, a2, a3, a4, a5, id);
        }
        p = (Node *)((s8 *)p + p->size);
    }
    sprintf(buf, D_001FB8D0, id);
    return 0;
}
