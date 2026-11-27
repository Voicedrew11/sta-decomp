#include "m2c.h"
typedef struct { u8 pad[0xA]; u16 a; u8 pad2[0x24]; u16 v[6]; u8 pad3[0x90-0x3C]; } S;
S *Item_GetTable_1_001AFC90(void);

s32 Equip_CheckAmmo_0_001CC250(s32 arg0) {
    S *base;
    u16 m;
    s32 r;
    s16 i;

    base = Item_GetTable_1_001AFC90();
    m = 0;
    i = arg0;
    r = 0;
    if (i < 0 && i >= 0x400) {
        return 1;
    }
    if (base[i].a != 2) {
        return 0;
    }
    if (base[i].v[0] > 0) {
        m = base[i].v[0];
        r = 0;
    }
    if (m < base[i].v[1]) { m = base[i].v[1]; r = 1; }
    if (m < base[i].v[2]) { m = base[i].v[2]; r = 2; }
    if (m < base[i].v[3]) { m = base[i].v[3]; r = 3; }
    if (m < base[i].v[4]) { m = base[i].v[4]; r = 4; }
    if (base[i].v[5] > m) { r = 5; }
    return r;
}
