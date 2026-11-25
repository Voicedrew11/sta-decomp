#include "m2c.h"
typedef struct { f32 v[4]; } Vec;
typedef struct { Vec m[4]; } Mtx;
typedef struct { u8 pad[0x10]; s32 x10; u8 pad14[0x4C]; Vec a; Vec b; Vec c; } Ent;
typedef struct {
    Mtx m;
    Vec v40, v50, v60, v70;
    u8 pad80[0x1C];
    s16 idx;
    u8 pad9E[0xB];
    u8 fA9;
    u8 padAA[0x26];
} Node;
void func_001027E0(void *, void *, void *);
void func_001029D0(void *, void *, void *);
void func_00173FD0(void *, Vec *, Vec *, Vec *);
extern Ent *D_002022B0;

void func_001ADC60(Node *n, Mtx *out) {
    Ent *tbl = D_002022B0;
    if (n != NULL && n->idx != -1) {
        if (((u64)((s64)n->fA9 << 0x3E) >> 0x3F) != 0) {
            func_00173FD0(out, &n->v40, &n->v50, &n->v60);
        } else {
            Mtx tmp;
            Ent *e = &tbl[n->idx];
            func_00173FD0(&tmp, &e->a, &e->b, &e->c);
            func_00173FD0(out, &n->v40, &n->v50, &n->v60);
            func_001027E0(out, out, &tmp);
        }
        func_001029D0(&out->m[3], &out->m[3], &n->v70);
    }
}
