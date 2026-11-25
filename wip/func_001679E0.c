#include "actor.h"
typedef struct { u16 prev; u16 next; u16 x4; } Lnk;
typedef struct { Vec v; u8 pad[0x110]; } Ent;
extern Lnk *D_00201FD4;
extern Ent *D_00201FC0;
extern u16 D_00201CA4;
extern Mtx D_002229D0;
void func_00146600(Actor *, Mtx *);
void func_001028F8(Mtx *, Mtx *);
void func_001027E0(Mtx *, Mtx *, Mtx *);
void func_00102A60(Vec *, Vec *);
void func_001027B0(Vec *, Mtx *, Vec *);
static inline void swp(u16 a, u16 b) {
    if (D_00201FD4[a].prev != 0xFFFF) D_00201FD4[D_00201FD4[a].prev].next = b;
    D_00201FD4[b].prev = D_00201FD4[a].prev;
    if (D_00201FD4[b].next != 0xFFFF) D_00201FD4[D_00201FD4[b].next].prev = a;
    D_00201FD4[a].next = D_00201FD4[b].next;
    D_00201FD4[a].prev = b;
    D_00201FD4[b].next = a;
}
void func_001679E0(u16 id) {
    u16 cur;
    s32 swapped;
    u16 c;
    u16 n;
    Mtx m;
    Mtx m2;
    Vec a;
    Vec b;
    if (id == 0xFFFF) return;
    func_00146600(D_002022E4, &m);
    func_001028F8(&m, &m);
    func_001027E0(&m2, &D_002229D0, &m);
    cur = D_00201CA4;
    do {
        swapped = 0;
        while ((n = D_00201FD4[cur].next) != 0xFFFF) {
            c = cur;
            func_00102A60(&a, &D_00201FC0[c].v);
            func_00102A60(&b, &D_00201FC0[n].v);
            func_001027B0(&a, &m2, &a);
            func_001027B0(&b, &m2, &b);
            if (b.z / b.w < a.z / a.w) {
                if (D_00201FD4[c].prev == 0xFFFF) D_00201CA4 = n;
                swp(c, n);
                swapped = 1;
            } else {
                cur = n;
            }
        }
    } while (swapped);
}
