#include "m2c.h"
typedef struct { s32 x[4]; } H;
typedef struct { s32 h[3]; s32 size; s8 data[1]; } B;
typedef struct { u8 b0:3; u8 r:5; } Bits;
typedef struct {
    u8 p0[0x10]; s32 **x10; u8 p14[8]; s16 prev; s16 next; s16 x20; u8 p22[2]; s32 x24; Bits x28; u8 p29[7];
} Node;
typedef struct { u64 key; u8 p8[0x30]; Node *x38; s32 x3C; u8 p40[0x10]; } Ent;
typedef struct { s32 x0; s32 x4; u32 n; u8 pC[4]; Ent e[1]; } Tbl;
extern s8 D_001FB908[];
extern s8 D_001FB909[];
extern s8 D_001FB90A[];
extern s8 D_001FB90B[];
extern s8 D_001FB910[];
extern s8 D_001FB911[];
extern s8 D_001FB912[];
extern s8 D_001FB913[];
extern s32 D_00201CB4;
extern Node D_004800C0[];
extern s16 D_004800DC[];
extern s16 D_004800DE[];
extern s16 D_004830C8[];
extern s16 D_004830CA[];
extern s16 D_004830CC[];
extern s16 D_004830CE[];
H *func_0014DCD0(s32 *, s32);
Node *func_00175850(s32);
void func_00176550(Node *, Tbl *, Ent *);
static inline s32 getsz(s32 *s) {
    H *v;
    B *b;
    if (*s == (D_001FB908[0] | (D_001FB909[0] << 8) | (D_001FB90A[0] << 16) | (D_001FB90B[0] << 24))) {
        return 0;
    }
    v = func_0014DCD0(s, D_00201CB4);
    if (v != NULL) {
        b = (B *)(v + 1); return ((s32)b->data + ((b->size + 0xF) & ~0xF)) - (s32)s;
    }
    return -1;
}

static inline void link(s16 idx) {
    s16 h;
    D_004830CE[0]++;
    h = D_004830CC[0];
    if (h == -1) {
        D_004830CC[0] = idx;
        D_004800DC[idx * 24] = idx;
        D_004800DE[idx * 24] = idx;
    } else {
        D_004800DC[idx * 24] = h;
        D_004800DE[idx * 24] = D_004800DE[h * 24];
        D_004800DE[D_004800DC[idx * 24] * 24] = idx;
        D_004800DC[D_004800DE[idx * 24] * 24] = idx;
        D_004830CC[0] = idx;
    }
}
static inline Node *unlink(s16 idx) {
    s16 *pv;
    Node *n;
    n = &D_004800C0[idx];
    D_004830CA[0]--;
    pv = &D_004800DC[idx * 24];
    if (idx == *pv) {
        D_004830C8[0] = -1;
    } else {
        D_004800DE[*pv * 24] = D_004800DE[idx * 24];
        D_004800DC[D_004800DE[idx * 24] * 24] = *pv;
        if (*(volatile s16 *)D_004830C8 == idx) D_004830C8[0] = *pv;
    }
    return n;
}
Node *func_00177BB0(u64 key, s32 **r, s32 off) {
    Ent *e;
    Tbl *t;
    u32 i;
    Node *nd;
    s32 idx;
    s32 n;
    union { u64 d; struct { s32 w; u8 c[4]; } s; } k;

    if (off == -1) off = getsz(*r);
    if (off == -1) return 0;
    t = (Tbl *)((s8 *)*r + off);
    e = t->e;
    for (i = 0; i < t->n; i++) {
        if (key == e[i].key) break;
    }
    k.d = key;
    if (k.s.w == (D_001FB910[0] | (D_001FB911[0] << 8) | (D_001FB912[0] << 16) | (D_001FB913[0] << 24)) && k.s.c[0] == 'X') {
        n = (k.s.c[1] - '0') * 100 + (k.s.c[2] - '0') * 10;
        n += k.s.c[3] - '0';
        nd = func_00175850(n);
    } else {
    e = &e[i];
    if (i != t->n) {
    if (e->x3C) {
        e->x3C++;
        nd = e->x38;
    } else {
    idx = D_004830C8[0];
    nd = unlink(idx);
    link(idx);
    nd->x10 = r;
    nd->x24 = off;
    nd->x20 = i;
    nd->x28.b0 = 1;
    func_00176550(nd, t, e);
    e->x3C++;
    }
    } else return 0;
    }
    return nd;
}


