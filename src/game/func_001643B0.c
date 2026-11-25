#include "common.h"

typedef struct { char pad[0x10]; char sub[0x4D0]; } E;
typedef struct { E e[64]; } B;
extern B D_003174F0[2];
void func_00164BB0(void *p);
void func_00164940(void);

void func_001643B0(void)
{
    s32 j, i;
    for (j = 0; j < 2; j++) {
        for (i = 0; i < 64; i++)
            func_00164BB0(D_003174F0[j].e[i].sub);
    }
    func_00164940();
}
