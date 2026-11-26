#include "m2c.h"
typedef struct { u8 pad[0x2C]; u16 a[8]; u8 pad2[0x4A-0x3C]; u16 b[6]; } E;
extern u8 *func_001AFC90(void);
extern s32 func_001AFBD0(s32);
void memset(void *, s32, s32);

void func_0019A370(u16 *a0, u16 *a1, void *a2, void *a3, s32 t0) {
    u8 *e = func_001AFC90() + t0 * 0x90;
    memset(a1, 0, 0x10);
    memset(a0, 0, 0x10);
    memset(a3, 0, 0x10);
    memset(a2, 0, 0x10);
    if (t0 >= 0) {
        switch (func_001AFBD0(t0)) {
        case 1:
            a0[0] = *(u16 *)(e + 0x2C); a0[1] = *(u16 *)(e + 0x2E);
            a0[2] = *(u16 *)(e + 0x30); a0[3] = *(u16 *)(e + 0x32);
            a0[4] = *(u16 *)(e + 0x34); a0[5] = *(u16 *)(e + 0x36);
            a0[6] = *(u16 *)(e + 0x38); a0[7] = *(u16 *)(e + 0x3A);
            a1[0] = *(u16 *)(e + 0x4A); a1[1] = *(u16 *)(e + 0x4C);
            a1[2] = *(u16 *)(e + 0x4E); a1[3] = *(u16 *)(e + 0x50);
            a1[4] = *(u16 *)(e + 0x52); a1[5] = *(u16 *)(e + 0x54);
            break;
        case 2:
            a1[0] = *(u16 *)(e + 0x30); a1[1] = *(u16 *)(e + 0x32);
            a1[2] = *(u16 *)(e + 0x34); a1[3] = *(u16 *)(e + 0x36);
            a1[4] = *(u16 *)(e + 0x38); a1[5] = *(u16 *)(e + 0x3A);
            break;
        }
    }
}
