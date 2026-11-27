#include "common.h"

typedef struct { char pad[0x10]; char sub[0x4D0]; } E;
typedef struct { E e[64]; } B;
extern B D_003174F0[2];
void Lightning_Init_0_00164BB0(void *p);
void Lightning_ResetPoints_0_00164940(void);

void Lightning_InitAll_1_001643B0(void)
{
    s32 j, i;
    for (j = 0; j < 2; j++) {
        for (i = 0; i < 64; i++)
            Lightning_Init_0_00164BB0(D_003174F0[j].e[i].sub);
    }
    Lightning_ResetPoints_0_00164940();
}
