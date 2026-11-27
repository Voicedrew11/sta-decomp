#include "common.h"

typedef struct { char pad[0x1C0]; } E;
extern E D_004B6A00[];

E *Pad_GetRecord_1_001D7B68(s32 i, s32 j)
{
    return &D_004B6A00[i * 4 + j];
}
