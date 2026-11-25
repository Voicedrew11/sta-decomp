#include "m2c.h"
s32 func_00169BB0(s32);
s32 func_00169B50(s32, s32, s32, s32);
s32 func_00169BD0(s32, s32, void *, s32, s32, s32);
void func_00169D70(s32, void *, s32);
typedef struct { u8 pad[0x10]; s32 x10; } M;
typedef struct { M *m; } MP;
typedef struct { u8 pad[0x2C]; u32 pad2:14; u32 id:10; } Def;
typedef struct { u8 pad[0x160]; u8 b0:1; u8 b1:1; u8 pad2[3]; s32 x164; u8 pad3[0x8]; } Ent;
typedef struct { u8 pad[0xC]; u8 c0:6; u8 c6:1; u8 pad2[0x2E0 - 0xD]; u16 id; u8 pad3[0x3E]; } T0;
typedef struct { u8 pad[0x120]; u16 a:2; u16 m:8; u16 pad1:6; u16 pad2; s32 x124[8]; } Q;
typedef struct {
    u8 pad[4];
    MP *mp;
    u8 pad8[0x74];
    s32 n;
    u8 pad80[0x4B0 - 0x80];
    u8 *t;
    Def *defs[(0x518 - 0x4B4) / 4];
    Q *q;
    Ent *ents;
    u8 pad520[0x60];
    u8 buf[1];
} O;
static inline s32 load(O *o, u16 id, volatile s32 *flag) {
    s32 r;
    r = 0;
    if (id) {
        if (func_00169BB0(id)) {
            r = func_00169B50(id, 1, 0, 0);
            *flag = 1;
        } else {
            r = func_00169BD0(id, o->mp->m->x10, o->buf, 1, 0, 0);
            *flag = 0;
        }
    }
    return r;
}

void func_001A71B0(O *o) {
    s32 i;
    Ent *e;
    volatile s32 flag;
    s32 id;
    Q *q;
    u16 id1;

    func_00169D70(o->mp->m->x10, o->buf, 8);
    for (i = 0; i < o->n; i++) {
        Def *d = o->defs[i];
        e = &o->ents[i];
        if (d->id) {
            e->x164 = load(o, d->id, &flag);
            e->b1 = flag;
        }
    }
    if (((T0 *)o->t)->c6) {
        q = o->q;
        q->m = 0;
        for (i = 0; i < 8; i++) {
            id = ((T0 *)(o->t + i * 0x40))->id;
            if (id) {
                s32 r = 0;
                if (id) {
                    if (func_00169BB0(id)) {
                        r = func_00169B50(id, 1, 0, 0);
                        flag = 1;
                    } else {
                        r = func_00169BD0(id, o->mp->m->x10, o->buf, 1, 0, 0);
                        flag = 0;
                    }
                }
                q->x124[i] = r;
                q->m |= (u16)(flag << i);
            }
        }
    }
}
