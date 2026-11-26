#include "common.h"
extern s32 D_001FD268[];
extern s32 *D_00202164;
typedef struct { s32 id; s32 x4; s32 off; } Ent;
typedef struct { s32 x0; u32 n; s32 x8; s32 xC; Ent e[1]; } Hdr;
static inline s32 get(void) {
    if (D_00202164 != NULL) {
        return *D_00202164;
    }
    return 0;
}
s32 *func_00195900(s32 id) {
    Hdr *h = (Hdr *)get();
    Ent *e;
    u32 i;
    if (h == NULL) return D_001FD268;
    e = h->e;
    for (i = 0; i < h->n; i++, e++) {
        if (e->id == id) return (s32 *)((u8 *)h + e->off);
    }
    return D_001FD268;
}

