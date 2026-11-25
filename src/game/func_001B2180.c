#include "actor.h"
typedef struct { f32 x, y, z, w; } Vec;
typedef union { u128 q[2]; Vec v[2]; } Q2;
typedef struct { u8 pad0[0x24]; s32 x24; u8 pad28[8]; void *x30; void *x34; void *x38; } H;
typedef struct { u8 pad0[0x40]; s32 **x40; u8 pad44[0xC]; u8 x50; u8 pad51; Flags8 x52; u8 pad53[0x2D]; } E;
typedef struct { u8 pad0[0x18]; u16 x18; u8 pad1A[0x16]; } S;
typedef struct { u8 pad0[0x1E]; Flags8 x1E; u8 pad1F[0x21]; } T;
typedef struct {
    u8 pad0[0x6E];
    u16 x6E;
    u8 pad70[0xC8];
    S *x138;
    u8 pad13C[0x34];
    T *x170;
    u8 pad174[4];
    s32 ***x178;
    u8 pad17C[4];
    E *x180;
    u8 pad184[0x54];
    u8 x1D8;
} O;
extern Flags8 D_00222A52[];
s32 func_0014FA30(H *, s32 *, Q2 *, void *, O *, s32);
void func_00102A60(Vec *, H *);

s32 func_001B2180(O *o, H *h, Q2 *src, void *a3, s32 flags) {
    Q2 buf;
    s32 i;
    E *e;
    S *s;
    T *t;
    u8 f;

    if (o == NULL) return 0;
    if (h == NULL) return 0;
    if (src == NULL) return 0;
    if (a3 == NULL) return 0;
    if (flags == 0) return 0;
    if (!(o->x1D8 & 1)) return 0;
    buf = *src;
    f = flags;
    if (f & 1) {
        if (func_0014FA30(h, **o->x178, &buf, a3, o, 0)) {
            func_00102A60(&buf.v[1], h);
            h->x30 = o;
            if (f & 4) return 1;
        }
    }
    if (!(f & 2)) return h->x24;
    if (D_00222A52[0].f.b4) return h->x24;
    for (i = 0; i < o->x6E; i++) {
        e = &o->x180[i];
        s = &o->x138[i];
        t = &o->x170[s->x18];
        if (e->x50 & 3) continue;
        if (e->x52.f.b4) continue;
        if (!e->x52.f.b3) continue;
        if (func_0014FA30(h, *e->x40, &buf, a3, 0, t->x1E.f.b3)) {
            func_00102A60(&buf.v[1], h);
            h->x30 = o;
            h->x38 = e;
            h->x34 = s;
            if (f & 4) return 1;
        }
    }
    return h->x24;
}
