#include "common.h"
void sceVu0AddVector(u8 *, u8 *, s32);
typedef struct { u8 d[0x40]; } E;
extern s32 D_0030A2D0[];
void Light_OffsetAll_0_0015B110(s32 arg0) {
    s32 j;
    s32 i;
    u8 *h;
    u8 *b;
    E *e;
    j = 0;
    h = (u8 *)D_0030A2D0;
    b = (u8 *)D_0030A2D0;
    do {
        i = 0;
        if (*(u16 *)(h + 0x2104) != 0) {
            e = (E *)b;
            do {
                if (e[4].d[0x38] & 1) {
                    sceVu0AddVector(e[4].d, e[4].d, arg0);
                }
                i++;
                e++;
            } while (i < 0x40);
        }
        j++;
        h += 2;
        b += 0x1000;
    } while (j < 2);
}

