#include "common.h"
typedef struct Ch { s32 x0; s32 x4; u32 type : 8; u32 off : 24; u16 xC; u16 xE; } Ch;
extern const s8 D_001FE890[];
void func_0012C7A0(s32, s32);
void func_0012C7B0(s32, s32);

void func_001E1810(Ch *a0, s32 a1) {
    u32 i;
    u32 j;
    Ch *c;
    Ch *d;
    switch (a0->x0) {
    case 0x4D415453:
    c = (Ch *)((u8 *)a0 + a0->off);
    for (i = 0; i < a0->xE; i++) {
        if (c->x0 == (D_001FE890[0] | (((const s8 *)D_001FE890)[1] << 8) | (((const s8 *)D_001FE890)[2] << 16) | (((const s8 *)D_001FE890)[3] << 24))) {
            d = (Ch *)((u8 *)c + c->off);
            for (j = 0; j < c->xE; j++) {
                switch (d->x0) {
                case 0x61444E53:
                    func_0012C7B0((u8 *)d - (u8 *)a1, 0);
                    break;
                case 0x62444E53:
                    func_0012C7A0((u8 *)d - (u8 *)a1, 0);
                    break;
                }
                d = (Ch *)((u8 *)d + d->x4);
            }
        }
        c = (Ch *)((u8 *)c + c->x4);
    }
    }
}
