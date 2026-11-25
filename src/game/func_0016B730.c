#include "m2c.h"
typedef struct { f32 x, y, z, w; } Vec;
typedef struct { s16 x, y, z; } SV;
extern s32 D_00201FF4;
void func_00102A60(Vec *, Vec *);

void func_0016B730(Vec *out, s32 mode, u16 *hdr, u16 *idx, void *data, f32 scale) {
    u32 i;
    Vec *o;
    s32 m;
    u16 bits = hdr[3];
    if (D_00201FF4 != bits) {
        D_00201FF4 = bits;
    }
    for (i = 0, o = out; i < 7; i++, o++) {
        m = bits;
        switch (m & 3) {
        case 0:
            o->x = 0.0f;
            o->y = 0.0f;
            o->z = 0.0f;
            o->w = 1.0f;
            break;
        case 1:
            o->x = 1.0f;
            o->y = 1.0f;
            o->z = 1.0f;
            o->w = 1.0f;
            break;
        case 2:
            func_00102A60(o, &out[i - 1]);
            break;
        case 3: {
            s32 k = *idx++;
            if (mode == 2) {
                Vec *v = (Vec *)((u8 *)data + k * 12);
                o->x = v->x;
                o->y = v->y;
                o->z = v->z;
            } else if (i < 3) {
                SV *v = (SV *)data + k;
                o->x = scale * v->x;
                o->y = scale * v->y;
                o->z = scale * v->z;
            } else {
                SV *v = (SV *)data + k;
                o->x = (1.0f / 4096.0f) * v->x;
                o->y = (1.0f / 4096.0f) * v->y;
                o->z = (1.0f / 4096.0f) * v->z;
            }
            break;
        }
        }
        bits = m >> 2;
    }
}
