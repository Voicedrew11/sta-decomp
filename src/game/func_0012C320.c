#include "common.h"

typedef struct { s8 b0; char p1[0xD]; s8 bE; char rest[0x71]; } E;
extern E D_0022CBC0[63];
void func_001313A0(void);
void func_0012F880(void);

void func_0012C320(void)
{
    s32 i;
    func_001313A0();
    func_0012F880();
    for (i = 0; i < 63; i++) {
        if (D_0022CBC0[i].b0)
            D_0022CBC0[i].bE = 1;
    }
}
