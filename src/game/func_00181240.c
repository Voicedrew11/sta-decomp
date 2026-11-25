#include "common.h"
typedef struct { u8 b[0x60]; } Buf;
typedef struct { u128 q[4]; } D40;
extern D40 D_001F25F0;
extern u8 D_001FB980[];
void func_00101438(Buf *, s32, s32, s32, s32, s32, s32, s32);
void func_0010BCA0(s32);
void func_00101620(Buf *, void *);
void func_00101120(s32, s32);

void func_00181240(void) {
    Buf a;
    Buf b;
    D40 d;
    func_00101438(&a, 0x3020, 1, 0x14, 0, 0, 0x80, 0x40);
    func_0010BCA0(0);
    func_00101620(&a, D_001FB980);
    func_00101120(0, 0);
    d = D_001F25F0;
    func_00101438(&b, 0x3032, 1, 0, 0, 0, 8, 2);
    func_0010BCA0(0);
    func_00101620(&b, &d);
    func_00101120(0, 0);
}
