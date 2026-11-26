#include "common.h"
void sceVu0AddVector(void *, void *, void *);
extern u8 D_0030C420[];
void func_0015C620(void *arg0) {
    s32 i;
    s32 j;
    u8 *p;
    u8 *q;
    u8 *r;
    i = 0;
    p = D_0030C420;
    q = D_0030C420;
    do {
        j = 0;
        if (*(u16 *)(p + 0xCB4) != 0) {
            r = q;
            do {
                if (r[0xD3] != 0) {
                    sceVu0AddVector(r + 0xB0, r + 0xB0, arg0);
                }
                j++;
                r += 0x30;
            } while (j < 0x20);
        }
        i++;
        p += 2;
        q += 0x600;
    } while (i < 2);
}

