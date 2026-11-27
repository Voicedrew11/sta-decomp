#include "m2c.h"
typedef struct { f32 x, y, z; } V3;
typedef struct { s16 x, y, z; } S3;
typedef struct { u8 pad[6]; u16 bits; } H;

void Mdl_DecodeVerts_0_0016B600(V3 *out, u32 n, s32 mode, H *h, u16 *idx, void *tbl) {
    u32 i;
    u16 bits = h->bits;
    s32 j;
    V3 *v;
    u32 k;
    S3 *s;

    for (i = 0; i < n; i++) {
        k = bits;
        switch (k & 3) {
        case 0:
            out->x = 0.0f;
            out->y = 0.0f;
            out->z = 0.0f;
            break;
        case 1:
            out->x = 1.0f;
            out->y = 1.0f;
            out->z = 1.0f;
            break;
        case 3:
            j = *idx++;
            if (mode == 2) {
                v = &((V3 *)tbl)[j]; out->x = v->x; out->y = v->y; out->z = v->z;
            } else if (mode == 3) {
                s = &((S3 *)tbl)[j];
                out->x = 0.00024414062f * s->x;
                out->y = 0.00024414062f * s->y;
                out->z = 0.00024414062f * s->z;
            }
            break;
        }
        bits = (s32)k >> 2;
        out++;
    }
}
