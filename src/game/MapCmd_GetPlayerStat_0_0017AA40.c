#include "m2c.h"
extern u16 D_00317238[];
s32 *Script_GetArgPtr_2_00165130(char *, s32);

void MapCmd_GetPlayerStat_0_0017AA40(char *a0) {
    s32 *p = Script_GetArgPtr_2_00165130(a0, 1);
    s32 v = *(s32 *)(a0 + 8);
    if (v < 12) {
        switch (v) {
        case 0: *p = D_00317238[0] & 0x10; break;
        case 1: *p = D_00317238[0] & 0x40; break;
        case 2: *p = D_00317238[0] & 0x80; break;
        case 3: *p = D_00317238[0] & 0x20; break;
        case 4: *p = D_00317238[0] & 0x1000; break;
        case 5: *p = D_00317238[0] & 0x4000; break;
        case 6: *p = D_00317238[0] & 0x8000; break;
        case 7: *p = D_00317238[0] & 0x2000; break;
        case 8: *p = D_00317238[0] & 0x400; break;
        case 9: *p = D_00317238[0] & 0x800; break;
        case 10: *p = D_00317238[0] & 0x100; break;
        case 11: *p = D_00317238[0] & 0x200; break;
        }
    }
}
