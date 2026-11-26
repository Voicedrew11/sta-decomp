#include "m2c.h"
typedef struct { s16 n0; s16 p2; s16 n4; s16 p6; s32 pad8; s32 used; } L;
extern L D_0047F0C0[];
extern s16 D_004830D0[];
extern s16 D_004830D2[];
extern s16 D_004830D4[];
extern s16 D_004830D6[];
extern s16 D_004830D8[];
extern s16 D_004830DA[];

void func_00177380(s16 i) {

    if (D_0047F0C0[i].used == 0) {
        D_004830DA[0]--;
        if (i == D_0047F0C0[i].n4) {
            D_004830D8[0] = -1;
        } else {
            D_0047F0C0[D_0047F0C0[i].n4].p6 = D_0047F0C0[i].p6;
            D_0047F0C0[D_0047F0C0[i].p6].n4 = D_0047F0C0[i].n4;
            if (D_004830D8[0] == i) D_004830D8[0] = D_0047F0C0[i].n4;
        }
    }
    D_004830D6[0]--;
    if (i == D_0047F0C0[i].n0) {
        D_004830D4[0] = -1;
    } else {
        D_0047F0C0[D_0047F0C0[i].n0].p2 = D_0047F0C0[i].p2;
        D_0047F0C0[D_0047F0C0[i].p2].n0 = D_0047F0C0[i].n0;
        if (D_004830D4[0] == i) D_004830D4[0] = D_0047F0C0[i].n0;
    }
    D_004830D2[0]++;
    if (D_004830D0[0] == -1) {
        D_004830D0[0] = i;
        D_0047F0C0[i].n0 = i;
        D_0047F0C0[i].p2 = i;
    } else {
        D_0047F0C0[i].n0 = D_004830D0[0];
        D_0047F0C0[i].p2 = D_0047F0C0[D_004830D0[0]].p2;
        D_0047F0C0[D_0047F0C0[i].n0].p2 = i;
        D_0047F0C0[D_0047F0C0[i].p2].n0 = i;
        D_004830D0[0] = i;
    }
    D_0047F0C0[i].used = 0;
}
