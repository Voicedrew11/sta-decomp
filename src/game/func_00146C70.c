#include "m2c.h"
typedef struct { u8 pad0[0xA]; u16 w; u16 pad; u16 h; } Dim;
typedef struct {
    u16 f0;
    u8 pad2[0x7A];
    s32 n;
    u8 pad80[0x430];
    Dim *dim;
    u8 *ent[1];
    u8 pad4B8[0x64];
    u8 *tbl;
} Obj;
typedef struct { u8 pad0[0x2D]; u8 b0 : 1; u8 b1 : 1; u8 b2 : 1; u8 b3 : 1; u8 b4 : 1; u8 b5 : 1; u8 b6 : 1; u8 b7 : 1; } E;
typedef struct { u8 pad[0xC]; f32 d; u8 pad2[0x20]; s32 flag; u8 pad3[0xC]; } Hit;
void func_001502A0(void *, s32, s32);
s32 func_0013EE40(void *);
void func_00140470(void *, void *);
s32 func_0014EC00(void *, void *, f32, f32);
s32 func_0013BA70(s32, void *, u8 *, u8 *);
void func_00151B20(void *, void *, u8 *);
void sceVu0CopyVector(void *, void *);
static inline f32 u2f(u32 x) { return x; }
s32 func_00146C70(s32 a0, s32 a1, Obj *a2, s32 *a3, f32 *t0) {
    s32 bi, i;
    u8 *rec;
    u8 *e;
    u8 buf0[0x20];
    Hit best;
    u8 buf1[0x10];
    Hit cur;
    f32 d;
    func_001502A0(buf0, a0, a1);
    d = 5.0f;
    bi = -1;
    if (func_0013EE40(a2) != 0) return 0;
    func_00140470(a2, buf1);
    if (func_0014EC00(buf0, buf1, u2f(a2->dim->w), u2f(a2->dim->h)) == 0) {
        *a3 = 0;
        return 0;
    }
    for (i = 0; i < a2->n; i++) {
        rec = a2->tbl + i * 0x170;
        e = ((u8 **)a2)[i + 0x4B4 / 4];
        if (((E *)e)->b5) {
            if (a2->f0 != 0 && (e[0x2C] & 7) == 1) continue;
            if ((e[0x2C] & 7) == 2 && a2->f0 != 0) continue;
            if (func_0013BA70(0, a2, rec, e) != 0) {
                func_00151B20(&cur, buf0, rec);
                if (cur.flag != 0 && cur.d < d) {
                    d = cur.d;
                    bi = i;
                    best = cur;
                }
            }
        }
    }
    if (bi != -1) {
        *a3 = bi;
        if (t0 != 0) {
            sceVu0CopyVector(t0, &best);
            t0[3] = 1.0f;
        }
        return 1;
    }
    *a3 = 0;
    return 0;
}
