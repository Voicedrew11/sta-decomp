#include "common.h"
typedef struct { s32 status; void *entry; void *stack; s32 stackSize; void *gpReg; s32 initPriority; s32 currentPriority; u32 attr; u32 option; s32 waitType; s32 waitId; s32 wakeupCount; } TP;
s32 CreateThread(TP *);
s32 StartThread(s32, void *);
s32 func_001D8960(s32, s32, s32, s32, s32);
s32 printf(const char *, ...);
s32 sceSifCheckStatRpc(void *);
void func_001D8BE0(void);
extern char D_001FE6C0[];
extern s32 D_004B9EF0[];
/* .bss, from the top down (CodeWarrior writes it in reverse) */
u8 D_004B7EF0[0x2000];
extern s32 D_00201E38;
extern s32 D_00202300;
extern s32 _gp;
static inline s32 st(void) {
    TP tp;
    s32 id;
    tp.entry = func_001D8BE0;
    tp.initPriority = 0x30;
    tp.stack = D_004B7EF0;
    tp.stackSize = 0x2000;
    tp.gpReg = &_gp;
    id = CreateThread(&tp);
    if (id >= 0) {
        D_00201E38 = id;
        StartThread(id, 0);
        return 1;
    }
    return 0;
}
s32 func_001D8210(void) {
    s32 r, t;
    s32 n;
    if (D_00202300 == 0) {
        if (st() != 0) {
            n = 10000000; goto check; loop: if (n < 0) { printf(D_001FE6C0); r = -1; goto out; } n--; check: t = sceSifCheckStatRpc(D_004B9EF0); r = 1; if (t == r) goto loop; out:
            if (r >= 0) func_001D8960(0, 1, 0, 4, 0x20000);
            D_00202300 = 1;
        }
        return 1;
    }
    return 0;
}

