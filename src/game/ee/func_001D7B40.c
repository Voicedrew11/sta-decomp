#include "common.h"

typedef struct {
    char pad[0x6C];
    s32 f;
    char rest[0x150];
} E;
extern E D_004B6A00[];

s32 func_001D7B40(s32 i, s32 j)
{
    return D_004B6A00[i * 4 + j].f;
}
