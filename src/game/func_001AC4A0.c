#include "m2c.h"
typedef struct { f32 v[4]; } Vec;
typedef struct { Vec m[4]; } Mtx;
typedef struct { u8 pad[0x60]; Vec a; Vec b; Vec c; } Ent;
typedef struct {
    Mtx m;          /* 0x00 */
    Vec v40, v50, v60, v70; /* 0x40..0x7F */
    u8 pad80[0x1C];
    s16 idx;        /* 0x9C */
    u8 pad9E[0xB];
    u8 fA9;
    u8 padAA[0x26];
} Node;
void func_001027E0(void *, void *, void *);
void func_001029D0(void *, void *, void *);
void func_00173FD0(void *, Vec *, Vec *, Vec *);
extern Ent *D_002022B0;
extern Node D_004AC970[];
extern Node D_004AE370[];
static inline void upd(Node *n, void *m) {
    if (n->idx != -1) {
        func_001029D0(&n->v70, &n->v70, m);
        {
        Ent *tbl = D_002022B0;
        if (n != NULL && n->idx != -1) {
            if (((u64)((s64)n->fA9 << 0x3E) >> 0x3F) != 0) {
                func_00173FD0(n, &n->v40, &n->v50, &n->v60);
            } else {
                Mtx tmp;
                Ent *e = &tbl[n->idx];
                func_00173FD0(&tmp, &e->a, &e->b, &e->c);
                func_00173FD0(n, &n->v40, &n->v50, &n->v60);
                func_001027E0(n, n, &tmp);
            }
            func_001029D0(&n->m.m[3], &n->m.m[3], &n->v70);
        }
        }
    }
}

void func_001AC4A0(void *arg0) {
    s32 i;
    Node *n;

    n = D_004AE370;
    for (i = 0; i < 0x40; i++) {
        upd(n, arg0);
        upd(n + 0x40, arg0);
        n++;
    }
    {
    Node *m = D_004AC970;
    for (i = 0; i < 0x10; i++) {
        upd(m, arg0);
        upd(m + 0x10, arg0);
        m++;
    }
    }
}
