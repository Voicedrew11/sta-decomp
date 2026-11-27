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
void sceVu0MulMatrix(void *, void *, void *);
void sceVu0AddVector(void *, void *, void *);
void Mtx_Compose_2_00173FD0(void *, Vec *, Vec *, Vec *);
extern Ent *D_002022B0;

void ItemObj_GetMatrix_0_001ADC60(Node *n, Mtx *out) {
    Ent *tbl = D_002022B0;
    if (n != NULL && n->idx != -1) {
        if (((u64)((s64)n->fA9 << 0x3E) >> 0x3F) != 0) {
            Mtx_Compose_2_00173FD0(out, &n->v40, &n->v50, &n->v60);
        } else {
            Mtx tmp;
            Ent *e = &tbl[n->idx];
            Mtx_Compose_2_00173FD0(&tmp, &e->a, &e->b, &e->c);
            Mtx_Compose_2_00173FD0(out, &n->v40, &n->v50, &n->v60);
            sceVu0MulMatrix(out, out, &tmp);
        }
        sceVu0AddVector(&out->m[3], &out->m[3], &n->v70);
    }
}
