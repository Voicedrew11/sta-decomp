#include "common.h"
#include "game/data.h"
#include "game/ee.h"
typedef struct { u64 : 48; u64 b48 : 1; u64 b49 : 1; u64 b50 : 1; u64 : 13; char pad[0x128]; s16 x130; void *x134; } S;
typedef struct { s32 x0; char pad[0x6C]; s32 x70; s32 x74; f32 x78; f32 x7C; } T;
extern S *D_00201E5C;
extern T *D_00201E60;
void *GsText_Alloc_0_001E1E08(s32, s32);
void GsText_SetPriority_0_001E2A08(s16);
void *memset(void *, s32, u32);

void GsText_Init_1_001E2018(s32 arg0, u8 arg1, u16 arg2) {
    D_00201E58 = arg0;
    D_00201E5C = GsText_Alloc_0_001E1E08(0x138, 0);
    D_00201E60 = GsText_Alloc_0_001E1E08(0x90, 0);
    memset(D_00201E5C, 0, 0x138);
    memset(D_00201E60, 0, 0x90);
    if (arg2 != 0) {
        D_00201E5C->x130 = arg2;
        D_00201E5C->x134 = GsText_Alloc_0_001E1E08(arg2 * 2, 0);
    }
    D_00201E5C->b48 = arg1;
    D_00201E5C->b50 = 0;
    D_00201E60->x0 = 0;
    D_00201E60->x70 = 0;
    D_00201E60->x74 = 0;
    D_00201E60->x78 = 640.0f;
    D_00201E60->x7C = 448.0f;
    GsText_SetPriority_0_001E2A08(0x23);
    GsText_SetFlag_0_001E1EA8(1);
}
