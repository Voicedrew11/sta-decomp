#include "m2c.h"
typedef struct { u8 pad[0x10]; s32 *base; u16 n14; u16 n16; u8 pad18[0x28]; } Q;
typedef struct { Q **q; u16 x4; u16 n6; } O;
typedef struct { u16 a; u16 b; u16 n; u16 c; u16 d; } E;
typedef void (*CB)(O *, s32, u8, u8 *, f32, u8 *, u8);

void func_001717A0(O *o, s32 idx, f32 t0, f32 t1, CB cb) {
    u8 *tbl;
    u8 *fp;
    s32 i;
    u8 *p;
    u32 cnt;
    u32 a;
    u32 b;
    u8 *end;
    u32 j;
    E *e;
    s32 base;
    Q *q;
    f32 s;
    f32 en;

    q = *o->q;
    base = *q->base;
    tbl = (u8 *)((s32)q + 0x40 + q->n14 * 16);
    b = idx;
    fp = tbl + q->n16 * 8;
    if (q->n16 != 0) {
        tbl += (b & 0xFFFF) * 8;
        fp += *(u16 *)(tbl + 4) * 4;
        for (i = 0; i < o->n6; i++) {
            e = (E *)(base + ((s32 *)fp)[i + o->x4]);
            a = e->a;
            b = e->b;
            cnt = e->n;
            p = (u8 *)e + 0x10;
            if (a != 0) {
                p += e->c;
            }
            if (b != 0) {
                p += e->d;
            }
            if (cnt != 0) {
                end = p + cnt * 16;
                for (j = 0; j < cnt; j++, p += 16) {
                    s = 0.00041666668f * ((s32 *)p)[0];
                    en = 0.00041666668f * ((s32 *)p)[1];
                    if (!(t0 <= t1) && !(t0 <= s) && t1 <= en) {
                        cb(o, idx, i, p, t0, end, t1 <= s);
                    }
                }
            }
        }
    }
}

