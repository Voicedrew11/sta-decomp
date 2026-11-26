/* NEAR 12 of 129 (was 103, len-3): node lookup in a static inline with early return (gives the b+nop), (u32)idx in the 2nd tbl index stops idx*48 CSE, ae not a local (arg1->e twice). Left: o (arg1->o) in a1 instead of a0 and the 0x2AAAAAAB magic in a0 instead of a1 (+ ddu a1,a1,a3 operand order); decl perms (720) no effect. */
#include "actor.h"
typedef struct { u8 pad[0x18]; u16 n18; u16 n1A; u8 pad1C[0x14]; } E30;
typedef struct { u8 pad[4]; u16 x4; u16 x6; u8 pad8[0xA]; Flags8 x12; u8 pad13; u16 x14; u8 v[6]; u8 pad1C[0x24]; } N40;
typedef struct { u8 pad[0x50]; u8 x50; u8 pad51[0x2F]; } E80;
typedef struct { s32 o0; u8 pad4[0x134]; E30 *tbl; u8 pad13C[0x34]; N40 *nodes; u8 pad174[0xC]; E80 *e80; } Obj;
typedef struct { u8 pad[0x30]; Obj *o; E30 *cur; E80 *e; } Arg;
void memset(void *, s32, s32);
s32 func_001AB500(s32, s16 *);
void func_001B8350(s32, s32, s32);
s8 *func_001B19A0(s32);
void func_00179F80(s32 *);

static inline N40 *node(Obj *o, s32 idx) {
    N40 *n = &o->nodes[o->tbl[idx].n18];
    if ((o->e80[idx].x50 & 3) && n->x12.f.b3) {
        return &o->nodes[n->x6];
    }
    return n;
}

s32 func_001B85B0(s32 arg0, Arg *arg1) {
    s32 o0;
    s32 idx;
    N40 *n;
    Obj *o;
    E30 *cur;
    E80 *ae;
    Obj *t;
    E30 *e;
    s16 b[8];
    s32 m[12];

    cur = arg1->cur;
    if (cur != NULL) {
        if (arg1->e != NULL) {
            o = arg1->o;
            o0 = o->o0;
            idx = cur - o->tbl;
            n = node(o, idx);
            if (n->x4 != 2) {
                return 0;
            }
            if (arg1->e->x50 & 3) {
                return 0;
            }
            memset(b, 0, 0x10);
            b[1] = n->v[0];
            b[2] = n->v[1];
            b[3] = n->v[2];
            b[5] = n->v[3];
            b[6] = n->v[4];
            b[7] = n->v[5];
            if (func_001AB500(arg0, b) >= n->x14) {
                func_001B8350(o0, idx, 0);
                t = (Obj *)func_001B19A0(o0);
                if (t != NULL) {
                    e = &t->tbl[(u32)idx];
                    if (e->n1A % 100) {
                        memset(m, 0, 0x30);
                        m[0] = 8;
                        m[1] = e->n1A % 100;
                        m[2] = o0;
                        m[3] = idx;
                        func_00179F80(m);
                    }
                }
                return 1;
            }
        }
    }
    return 0;
}




