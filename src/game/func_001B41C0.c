#include "m2c.h"
typedef struct { u8 pad[0x1C]; u8 bit; u8 pad2[0xF]; } E;           /* 0x2C */
typedef struct { s8 *p; u8 b0:1; u8 b1:1; } Slot;                   /* 8 */
typedef struct {
    u8 pad0[0x78]; u16 n; u8 pad7A[0x12]; s16 i8C; s16 i8E;
    u8 pad90[0xC0]; E *elems; s32 *tbl; u8 pad158[0x38]; Slot *slots;
    u8 pad194[0x44]; u8 f0:1;
} O;
extern O **D_002022BC;
void func_00167640(s8 *, s32);

void func_001B41C0(O *o) {
    E *e;
    s32 m1;
    s32 m2;
    s32 i;
    Slot *s;
    s32 off1;
    s32 off2;
    s32 idx;
    O *p;
    s32 *t;
    s16 k;

    m2 = 0;
    m1 = 0;
    if (o != NULL && o->f0) {
        t = o->tbl;
        k = o->i8C;
        if (o->i8E != -2) {
            k = o->i8E;
        }
        idx = k;
        if (idx != -1) {
            m1 = t[idx];
        }
        if (D_002022BC != NULL && (p = *D_002022BC) != NULL && p != o && p->i8C != -1) {
            m2 = p->tbl[p->i8C + 0x20];
        }
        i = 0;
        if (0 < o->n) {
            off1 = 0;
            off2 = 0;
            do {
            e = (E *)((s8 *)o->elems + off1);
            s = (Slot *)((s8 *)o->slots + off2);
            if (s->p != NULL && !s->b1) {
                func_00167640(s->p, 0);
                if (e->bit < 0x20) {
                    if (idx == -1) {
                        if (!(m2 & (1 << e->bit))) {
                        } else {
                            goto on;
                        }
                    } else if (!(m1 & (1 << e->bit))) {
                    } else {
                        goto on;
                    }
                } else if (idx != -1) {
on:
                    func_00167640(s->p, 1);
                }
            }
            i++;
            off1 += 0x2C;
            off2 += 8;
            } while (i < o->n);
        }
    }
}
