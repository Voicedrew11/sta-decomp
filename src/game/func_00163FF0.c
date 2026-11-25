#include "m2c.h"
typedef union { u128 q; u64 d[2]; u32 w[4]; } Q;
typedef struct {
    s32 x0;
    s32 id;
    f32 c[4];
    u8 pad18[0x50 - 0x18];
    u64 d50;
    u8 pad58[0x4C0 - 0x58];
    u64 d4C0;
    u8 pad4C8[0x4E0 - 0x4C8];
} Entry;
typedef struct { u8 pad[0x10]; u8 s[0x4D0]; } Raw;
typedef union { struct { u32 n[4]; Entry e[2][64]; } a; Raw r[2][64]; } Tbl;
extern Tbl D_003174F0;
extern s32 D_00201F2C;
extern Entry *D_00201F94;
extern s32 D_00201F98;
extern s32 D_00201F9C;
extern s32 func_00164A60(u32, u8 *, s32);
extern Q *func_00154A80(s32);
extern void func_00164440(Entry *, u8 *, u8 *, u8 *, s32);
static inline Entry *find(s32 id) {
    u32 i;
    for (i = 0; i < D_003174F0.a.n[D_00201F2C]; i++) {
        if (D_003174F0.a.e[D_00201F2C][i].id == id) return &D_003174F0.a.e[D_00201F2C][i];
    }
    return 0;
}

s32 func_00163FF0(u32 a0, u8 *a1, s32 a2) {
    s32 id;
    Entry *e;
    Q *p;
    id = func_00164A60(a0, a1, a2);
    e = find(id);
    if (e) {
        if (D_00201F94 != e) {
            Q q;
            p = func_00154A80(1);
            q.q = 0;
            q.w[0] = 0x50000000;
            q.w[1] = (u32)((u8 *)e + 0x20);
            *p = q;
            D_00201F9C++;
        }
    } else {
        Q q;
        union { u32 w; u8 b[4]; } col;
        Raw *r;
        col.w = a0;
        r = &D_003174F0.r[D_00201F2C][D_003174F0.a.n[D_00201F2C]];
        e = (Entry *)r->s;
        ((Entry *)r->s)->d50 = ((u64)D_00201F98 << 32) | ((u64)1 << 48);
        ((Entry *)r->s)->d4C0 = (s64)D_00201F98 | (0x10004000 | ((u64)5 << 32));

        e->c[0] = col.b[0] / 9.0f;
        e->c[1] = col.b[1] / 9.0f;
        e->c[2] = col.b[2] / 9.0f;
        e->c[3] = col.b[3] / 9.0f;
        func_00164440(e, (u8 *)e + 0xA0, a1 + 0x10, a1 + 0x50, a2);
        D_003174F0.a.n[D_00201F2C]++;
        e->id = id;
        p = func_00154A80(1);
        q.q = 0;
        q.w[0] = 0x50000000;
        q.w[1] = (u32)((u8 *)e + 0x20);
        *p = q;
        D_00201F9C++;
    }
    D_00201F94 = e;
    return 1;
}
