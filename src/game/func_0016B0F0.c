#include "m2c.h"
typedef struct { u16 prev; u16 next; u16 sib; } N;
typedef struct { u8 pad[0x114]; u8 b0:1; u8 b1:1; u8 b2:1; u8 pad115[0xB]; } O;
extern u16 D_00201C9C;
extern u16 D_00201CA0;
extern u16 D_00201CA4;
extern O *D_00201FC0;
extern N *D_00201FD4;
extern u16 D_00201FD8;

u16 func_0016B0F0(u16 a0, s32 which) {
    u16 *h;
    u16 id;

    h = which ? &D_00201CA4 : &D_00201C9C;
    if (D_00201FD8 == 0) return 0xFFFF;
    id = D_00201CA0;
    D_00201CA0 = D_00201FD4[id].next;
    if (D_00201CA0 != 0xFFFF) {
        D_00201FD4[D_00201CA0].prev = 0xFFFF;
    }
    D_00201FD4[id].prev = 0xFFFF;
    D_00201FD4[id].next = *h;
    if (*h != 0xFFFF) {
        D_00201FD4[*h].prev = id;
    }
    *h = id;
    D_00201FD8--;
    D_00201FD4[id].sib = a0;
    D_00201FC0[id].b0 = 1;
    return id;
}
