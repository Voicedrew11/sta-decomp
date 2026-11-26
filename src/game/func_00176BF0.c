#include "m2c.h"
typedef struct { u8 pad[0x28]; u8 type; } Owner;
typedef struct {
    s16 prev, next, fnext, fprev;
    u16 off, size;
    Owner *owner;
} Blk;
extern Blk D_0047F0C0[];
extern volatile s16 D_004830D0[];
#define D_004830D0 D_004830D0[0]
extern s16 D_004830D2[];
#define D_004830D2 D_004830D2[0]
extern s16 D_004830D4[];
#define D_004830D4 D_004830D4[0]
extern s16 D_004830D6[];
#define D_004830D6 D_004830D6[0]
extern s16 D_004830D8[];
#define D_004830D8 D_004830D8[0]
extern s16 D_004830DC[];
#define D_004830DC D_004830DC[0]
extern s16 D_004830DE[];
#define D_004830DE D_004830DE[0]
s32 func_00176FB0(s16);

u16 func_00176BF0(Owner *arg0, u16 arg1) {
    u16 size;
    s32 b;
    s16 first;
    s16 t;
    s16 s;
    s32 n;
    s16 h;

    size = (arg1 + 0x1F) & ~0x1F;
    b = D_004830D8;
    first = b;
    if (first != -1) {
        do {
            if (!(D_0047F0C0[b].size < size)) goto found;
            b = D_0047F0C0[b].fnext;
        } while (b != first);
    }
    b = D_004830DC;
    if (b != -1) {
        do {
            s = b;
            b = D_0047F0C0[b].fprev;
            if ((D_0047F0C0[b].owner->type & 7) != 3) {
                t = func_00176FB0(b);
                b = D_0047F0C0[s].fprev;
                if (size < D_0047F0C0[t].size) {
                    b = t;
                    goto found;
                }
            }
            if (D_004830DC == -1) break;
        } while (b != D_004830DC || (D_0047F0C0[b].owner->type & 7) != 3);
    }
found:
    n = D_004830D0;
    D_004830D2--;
    if (n == D_0047F0C0[n].prev) {
        D_004830D0 = -1;
    } else {
        D_0047F0C0[D_0047F0C0[n].prev].next = D_0047F0C0[n].next;
        D_0047F0C0[D_0047F0C0[n].next].prev = D_0047F0C0[n].prev;
        if (D_004830D0 == n) D_004830D0 = D_0047F0C0[n].prev;
    }
    D_004830D6++;
    h = D_004830D4;
    if (h == -1) {
        D_004830D4 = n;
        D_0047F0C0[n].prev = n;
        D_0047F0C0[n].next = n;
    } else {
        D_0047F0C0[n].prev = b;
        D_0047F0C0[n].next = D_0047F0C0[b].next;
        D_0047F0C0[D_0047F0C0[n].prev].next = n;
        D_0047F0C0[D_0047F0C0[n].next].prev = n;
        if (h == b) D_004830D4 = n;
    }
    D_0047F0C0[n].off = D_0047F0C0[b].off;
    D_0047F0C0[n].size = size;
    D_0047F0C0[b].off += size;
    D_0047F0C0[b].size -= size;
    D_004830DE++;
    h = D_004830DC;
    if (h == -1) {
        D_004830DC = n;
        D_0047F0C0[n].fnext = n;
        D_0047F0C0[n].fprev = n;
    } else {
        D_0047F0C0[n].fnext = h;
        D_0047F0C0[n].fprev = D_0047F0C0[h].fprev;
        D_0047F0C0[D_0047F0C0[n].fnext].fprev = n;
        D_0047F0C0[D_0047F0C0[n].fprev].fnext = n;
        D_004830DC = n;
    }
    D_0047F0C0[n].owner = arg0;
    return n;
}
