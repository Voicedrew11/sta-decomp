#include "m2c.h"
typedef struct { u16 prev; u16 next; u16 sib; } N;
typedef struct { u8 pad[0x114]; u8 b0:1; u8 b1:1; u8 b2:1; u8 pad115[0xB]; } O;
extern u16 D_00201C9C;
extern u16 D_00201CA0;
extern u16 D_00201CA4;
extern O *D_00201FC0;
extern N *D_00201FD4;
extern u16 D_00201FD8;

void Sfx_ListInsert_0_0016AF40(u16 a0, u16 id, s32 which) {
    u16 *h;
    u16 k;

    h = which ? &D_00201CA4 : &D_00201C9C;
    if (D_00201FD4[id].prev != 0xFFFF) {
        D_00201FD4[D_00201FD4[id].prev].next = D_00201FD4[id].next;
    }
    if (D_00201FD4[id].next != 0xFFFF) {
        D_00201FD4[D_00201FD4[id].next].prev = D_00201FD4[id].prev;
    }
    if (D_00201FD4[id].prev == 0xFFFF) {
        *h = D_00201FD4[id].next;
    }
    if (D_00201CA0 != 0xFFFF) {
        D_00201FD4[D_00201CA0].prev = id;
    }
    D_00201FD4[id].next = D_00201CA0;
    D_00201FD4[id].prev = 0xFFFF;
    D_00201CA0 = id;
    D_00201FD8++;
    for (k = a0; k != 0xFFFF; k = D_00201FD4[k].sib) {
        if (id == D_00201FD4[k].sib) {
            D_00201FD4[k].sib = D_00201FD4[id].sib;
            break;
        }
    }
    D_00201FD4[id].sib = 0xFFFF;
    D_00201FC0[id].b0 = 0;
    D_00201FC0[id].b2 = 0;
}
