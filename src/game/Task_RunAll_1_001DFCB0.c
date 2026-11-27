#include "common.h"
extern void (*volatile D_004BAC28[])(u8 *);
extern u8 *volatile D_004BAC30[];
extern volatile s32 D_004BAC34[];
extern volatile u32 D_004BAC38[];
extern volatile s32 D_004BAC3C[];
extern s32 D_002023A8;
s32 Task_Step_1_001E0020(u8 *);
static inline void clr(u8 *p) {
    void (*f)(u8 *);
    p[0] = 0;
    p[1] = 0;
    *(s32 *)(p + 0x18) = -1;
    f = D_004BAC28[0];
    if (f != NULL) f(p);
}
static inline void mk(u8 *a) {
    u32 i;
    u8 *p;
    if (a == NULL) {
        for (i = 0; i < D_004BAC38[0]; i++) {
            p = D_004BAC30[0] + D_004BAC34[0] * i;
            if (p[1] == 2) p[1] = 3;
        }
    } else if (a[1] == 2) {
        a[1] = 3;
    }
}
s32 Task_RunAll_1_001DFCB0(u8 *a) {
    u32 i;
    s32 st;
    if (a == NULL) {
        if (D_002023A8 != 0) {
            st = D_004BAC3C[0];
            if (st == 1 || st == 4) {
                mk(NULL);
                if (Task_Step_1_001E0020(NULL) != 0) return 1;
            }
        }
        D_004BAC3C[0] = 0;
        for (i = 0; i < D_004BAC38[0]; i++) clr(D_004BAC30[0] + D_004BAC34[0] * i);
    } else {
        if (a[0] == 1 || a[0] == 4) {
            mk(a);
            if (Task_Step_1_001E0020(a) != 0) return 1;
        }
        clr(a);
    }
    return 0;
}
