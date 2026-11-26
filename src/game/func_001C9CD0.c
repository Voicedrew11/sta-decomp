#include "m2c.h"
extern s8 *D_002022E4;
extern s32 D_00201E20;
extern s32 D_00202278;
extern char D_001FDC08[], D_001FDC10[], D_001FDC18[], D_001FDC20[], D_001FDC28[];
extern u8 D_004B4BE0[];
void func_001A7E60(void);
void func_001C5750(void);
void func_001C5150(void);
void func_001BEFA0(void);
void func_001BE7B0(void);
void func_001C55A0(void);
void func_00159DD0(s32, s32, void *, s32 *);
s32 func_00177F80(void *);
s32 func_00177AF0(s32, s32);
void memset(void *, s32, s32);

void func_001C9CD0(s8 *a) {
    s8 *o;
    s32 tmp;
    o = *(s8 **)(a + 0x518) + 0x180;
    D_002022E4 = a;
    func_001A7E60();
    *(void **)(a + 0x538) = func_001C5750;
    *(void **)(a + 0x53C) = func_001C5150;
    *(void **)(a + 0x540) = func_001BEFA0;
    *(void **)(a + 0x544) = func_001BE7B0;
    *(void **)(a + 0x548) = func_001C55A0;
    *(s16 *)(a + 0x4AE) = -1;
    *(s32 *)(*(s8 **)(o + 0x18) + 0x4F0) = 0;
    *(s32 *)(*(s8 **)(o + 0x18) + 0x510) = D_00201E20;
    *(s16 *)(*(s8 **)(o + 0x18) + 0x538) = -1;
    *(s16 *)(*(s8 **)(o + 0x18) + 0x53A) = -1;
    *(u8 *)(o + 0x39C) = 0;
    func_00159DD0(0x374169A, D_00202278, o + 0x3A8, &tmp);
    *(s32 *)(o + 0x3B0) = func_00177AF0(func_00177F80(D_001FDC08), *(s32 *)(o + 0x3A8));
    *(s32 *)(o + 0x3B4) = func_00177AF0(func_00177F80(D_001FDC10), *(s32 *)(o + 0x3A8));
    *(s32 *)(o + 0x448) = func_00177AF0(func_00177F80(D_001FDC18), *(s32 *)(o + 0x3A8));
    *(s32 *)(o + 0x44C) = func_00177AF0(func_00177F80(D_001FDC20), *(s32 *)(o + 0x3A8));
    *(s32 *)(o + 0x450) = func_00177AF0(func_00177F80(D_001FDC28), *(s32 *)(o + 0x3A8));
    memset(D_004B4BE0, 0, 0x58);
}
