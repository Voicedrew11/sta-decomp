#include "common.h"
void func_001545D0();                            /* extern */
void func_00176AE0();                            /* extern */
extern u16 D_00201F04;
extern u16 D_00201F08;
extern u8 D_00201F0C;

void func_00132930(s32 arg0) {
    if (D_00201F0C != 0) {
        func_00131970((s32) D_00201F04, (s32) D_00201F08, (void *) arg0);
        func_001545D0();
        func_001543E0(0x1A, 1);
        func_001543E0(0x42, 0xAA);
        func_001543E0(0x43, 0x48);
        func_001543E0(0x47, 0x50000);
        func_001543E0(0x48, 0x50000);
        func_001543E0(1, 0x80000);
        func_00154420();
        func_00176AE0();
        D_00201F0C = 0;
    }
}
