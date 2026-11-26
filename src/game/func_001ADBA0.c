#include "obj3d.h"
typedef struct { u8 pad[0x80]; Vec s; } Ent;
void sceVu0CopyVector(Vec *, Vec *);
void sceVu0MulVector(Vec *, Vec *, Vec *);
extern Ent *D_002022B0;
void func_001ADBA0(Obj3D *n, Vec *out) {
    Ent *tbl = D_002022B0;
    out->x = out->y = out->z = 1.0f;
    out->w = 0.0f;
    if (n != NULL && n->x9C != -1) {
        if (n->xA9.f.b1) {
            sceVu0CopyVector(out, &n->x60);
            return;
        }
        sceVu0CopyVector(out, &tbl[n->x9C].s);
        sceVu0MulVector(out, out, &n->x60);
    }
}

