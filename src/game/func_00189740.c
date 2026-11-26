#include "common.h"
typedef struct { s32 n; u8 *p; } Hdr;
typedef struct { s32 n; u8 *p; } Ent;
typedef struct { Hdr *x[16]; Ent e[64]; u8 **a; s32 pad; u32 n; } Tbl;
extern s32 *D_002020DC;
void func_00159DD0(s32, s32 *, u8 ***, s32 *);

static inline u8 *hdr2(Tbl *t, u32 j, u8 *p) { u8 *q; t->x[j] = (Hdr *)p; q = p + 0x10; t->x[j]->p = q; return q + t->x[j]->n * 0x40; }
void func_00189740(Tbl *t, u64 key) {
    s32 b;
    u8 **a;
    u32 i;
    u32 n;
    u8 *p; u32 j; u32 m;
    b = 0;
    a = 0;
    func_00159DD0((s32)key, D_002020DC, &a, &b);
    p = *a;
    n = *(u32 *)p;
    p += 0x10;
    for (i = 0; i < n; i++) {
        t->e[i].n = *(s32 *)p;
        t->e[i].p = p + 0x10;
        p += t->e[i].n * 0x30 + 0x10;
    }
    m = *(u32 *)p;
    p += 0x10;
    for (j = 0; j < m; j++) {
p = hdr2(t, j, p);
    }
    t->n = m;
    t->a = a;
}
