#include "common.h"

typedef struct { u64 a; u64 b; char p10[0x18]; u8 kind; } Obj;
extern s32 D_004830E8[], D_004830EC[], D_004830F4[];
extern u64 D_00202010;
void func_001545D0(void);
void func_001543E0(s32 a, u64 b);
void func_00154420(void);
void func_00176440(void);

void func_00176B10(Obj *o)
{
    if (!o)
        return;
    if ((o->kind & 7) == 3) {
        D_004830E8[0]++;
        D_004830EC[0]++;
        func_001545D0();
        func_001543E0(0x14, o->b);
        func_001543E0(6, o->a);
        func_00154420();
        D_00202010 = 0;
        D_004830F4[0] = 1;
    } else {
        D_004830F4[0] = 2;
        func_00176440();
    }
}
