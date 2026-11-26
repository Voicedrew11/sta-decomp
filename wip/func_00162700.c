/* near-miss: only diff is in the shared calc() inline: orig leaves 2 extra nops before 'div zero,a1,a0' at the start of the 'rate < fp' path (ours fills right after the bc1f delay slot) and keeps (f32)period in $f1 (ours $f2). Everything else matches modulo that 8-byte shift. Same issue as near_func_001629E0.c. */
#include "m2c.h"

typedef union {
    u128 q[3];
    struct {
        u8 pad[0x20];
        f32 f20;
    } s;
} Sub;

typedef struct {
    u16 f0;
    u8 pad2[5];
    u8 f7;
    u8 pad8[0x20];
    u16 f28;
} Dat;

typedef struct {
    u8 pad0[4];
    f32 f4;
    u8 pad8[5];
    s8 fD;
    u8 padE[0x42];
    Sub sub;
} Ch;

typedef struct {
    u8 pad0[0x174];
    f32 f174;
    u8 pad178[0xC];
    f32 f184;
    u8 pad188[0x88];
    Dat *dat[24];
    Ch ch[1];
} Mgr;

void func_00162CE0(Sub *, Dat *, f32);
s32 func_00162F30(void *, u16, Mgr *, Dat *, Sub *, Ch *, s32);

static inline u16 calc(s32 frame, s32 period, f32 rate, s32 flag, s32 cur) {
    u16 r;
    f32 fp;

    if (rate == 0.0f) {
        return 0;
    }
    if (!flag) {
        if (rate <= (f32)cur) {
            return 0;
        }
        if (period < frame) {
            return 0;
        }
    }
    if (0.0f < rate && rate <= 1.0f && cur == 0) {
        return 1;
    }
    fp = period;
    return rate < fp ? frame % period >= (s32)(fp / rate) * (s32)((f32)cur - rate * (f32)(frame / period)) : (frame % period < (s32)rate % period ? (s32)(1.0f + rate / fp) : (s32)(rate / fp));
}

void func_00162700(Mgr *m, s32 k, f32 t) {
    Ch *ch;
    Dat *d;
    Sub *s;
    Sub tmp;
    s32 n;
    s32 r;

    ch = &m->ch[k];
    d = m->dat[k];
    if (d->f28 != 0) {
        tmp = ch->sub;
        s = &tmp;
        func_00162CE0(&tmp, d, m->f174);
    } else {
        s = &ch->sub;
    }
    n = calc((s32)(30.0f * m->f174), d->f0, s->s.f20 * m->f184, d->f7 & 1, (s32)ch->f4);
    ch->f4 += (f32)n;
    r = func_00162F30(0, n, m, d, s, ch, k);
    if (r) {
        ch->f4 -= (f32)r;
    }
    if (m->ch[k].fD != 0) { func_00162700(m, m->ch[k].fD, t); }
}

