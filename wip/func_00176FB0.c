#include "m2c.h"
typedef struct { u8 pad[0x22]; s16 x22; } Owner;
typedef struct {
    s16 prev, next, fnext, fprev;
    u16 off, size;
    Owner *owner;
} Blk;
extern Blk D_0047F0C0[];
extern s16 D_004830D8[];
extern s16 D_004830DA[];
extern s16 D_004830DC[];
extern s16 D_004830DE[];
void func_00177380(s32);

s32 func_00176FB0(u16 a0) {
    s16 i;
    Owner *o;
    s16 n;
    Owner *on;
    s32 p;
    s16 h;

    i = a0;
    o = D_0047F0C0[i].owner;
    D_004830DE[0]--;
    if (i == D_0047F0C0[i].fnext) {
        D_004830DC[0] = -1;
    } else {
        D_0047F0C0[D_0047F0C0[i].fnext].fprev = D_0047F0C0[i].fprev;
        D_0047F0C0[D_0047F0C0[i].fprev].fnext = D_0047F0C0[i].fnext;
        if (D_004830DC[0] == i) D_004830DC[0] = D_0047F0C0[i].fnext;
    }
    n = D_0047F0C0[i].next;
    on = D_0047F0C0[n].owner;
    if ((on != NULL || n == 0) && (D_0047F0C0[D_0047F0C0[i].prev].owner != NULL || i == D_0047F0C0[i].prev)) {
        D_004830DA[0]++;
        h = D_004830D8[0];
        if (h == -1) {
            D_004830D8[0] = a0;
            D_0047F0C0[i].fnext = a0;
            D_0047F0C0[i].fprev = a0;
        } else {
            D_0047F0C0[i].fnext = h;
            D_0047F0C0[i].fprev = D_0047F0C0[h].fprev;
            D_0047F0C0[D_0047F0C0[i].fnext].fprev = a0;
            D_0047F0C0[D_0047F0C0[i].fprev].fnext = a0;
            D_004830D8[0] = a0;
        }
        D_0047F0C0[i].owner = NULL;
        i = a0;
    } else if (on == NULL && n != 0 && D_0047F0C0[D_0047F0C0[i].prev].owner == NULL && i != D_0047F0C0[i].prev) {
        p = D_0047F0C0[i].prev;
        D_0047F0C0[p].off -= D_0047F0C0[i].size;
        D_0047F0C0[D_0047F0C0[i].prev].size += D_0047F0C0[i].size;
        D_0047F0C0[D_0047F0C0[i].prev].off -= D_0047F0C0[n].size;
        D_0047F0C0[D_0047F0C0[i].prev].size += D_0047F0C0[n].size;
        i = D_0047F0C0[i].prev;
        func_00177380(n);
        func_00177380(a0);
    } else if (on == NULL && n != 0) {
        D_0047F0C0[n].size += D_0047F0C0[i].size;
        i = D_0047F0C0[i].next;
        func_00177380(a0);
    } else if (D_0047F0C0[D_0047F0C0[i].prev].owner == NULL && i != D_0047F0C0[i].prev) {
        p = D_0047F0C0[i].prev;
        D_0047F0C0[p].off -= D_0047F0C0[i].size;
        D_0047F0C0[D_0047F0C0[i].prev].size += D_0047F0C0[i].size;
        i = D_0047F0C0[i].prev;
        func_00177380(a0);
    }
    o->x22 = -1;
    return i;
}
