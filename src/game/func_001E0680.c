#include "common.h"
typedef struct { u8 a; u8 b; u8 pad2[6]; s32 x8; u16 xC; u8 padE[10]; s32 x18; } Ent;
typedef s32 (*Fn)(Ent *);
extern Fn D_004BAC28[];
extern Fn D_004BAC2C[];
extern u8 *D_004BAC30[];
extern s32 D_004BAC34[];
extern u32 D_004BAC38[];
void func_001E0AB0(Ent *);

static inline s32 cb(Ent *e) {
    Fn f = D_004BAC2C[0];
    return f ? f(e) : 0;
}

static inline void get3(Ent **pe, u32 i) {
    *pe = (Ent *)(D_004BAC30[0] + D_004BAC34[0] * i);
}

static inline Ent *get(u32 i) {
    return (Ent *)(D_004BAC30[0] + D_004BAC34[0] * i);
}

void func_001E0680(void) {
    u32 i;
    Ent *p;
    u32 k;
    Ent *q;
    Ent *e;
    s32 j;
    s32 foundv;
    s32 minv;
    u32 found;
    u32 mi;

    minv = foundv = 0x10000;
    mi = found = -1;
    {
        for (j = 0; j < D_004BAC38[0]; j++) {
            get3(&e, j);
            if (e->a == 1 || e->a == 4) {
                if (found != -1) return;
                foundv = e->xC;
                found = j;
            } else if (e->b == 2 && e->xC < minv) {
                minv = e->xC;
                mi = j;
            }
        }
    }
    if (mi != -1 && minv < foundv) {
        if (found == -1) {
            e = get(mi);
            e->a = 1;
            func_001E0AB0(e);
        } else {
            e = get(found);
            if (e->b == 2) e->b = 3;
        }
    } else if (found != -1) {
        e = get(found);
        if (cb(e) == 0 && e->b == 2) func_001E0AB0(e);
    }
    for (i = 0; i < D_004BAC38[0]; i++) {
        q = get(i);
        if (q->b == 1) {
            if (q->a == 1 || q->a == 4) {
                if (cb(q) == 0) {
                    q->a = 0;
                    q->b = 0;
                    q->x18 = -1;
                    if (D_004BAC28[0]) D_004BAC28[0](q);
                }
            } else {
                q->a = 0;
                q->b = 0;
                q->x18 = -1;
                if (D_004BAC28[0]) D_004BAC28[0](q);
            }
        }
    }
    for (k = 0; k < D_004BAC38[0]; k++) {
        p = get(k);
        if (p->b == 3) {
            if (p->a == 1) {
                if (cb(p) == 0) {
                    p->a = 2;
                    p->b = 0;
                }
            } else if (p->a == 4) {
                if (cb(p) == 0) p->a = 5;
            } else {
                p->b = 0;
            }
        }
    }
    for (k = 0; k < D_004BAC38[0]; k++) {
        p = get(k);
        if (p->b == 4) {
            if (p->a == 6) {
                if (D_004BAC28[0]) D_004BAC28[0](p);
                p->a = 3;
                p->b = 0;
                p->x8 = 0;
            } else {
                p->b = 0;
            }
        }
    }
}
