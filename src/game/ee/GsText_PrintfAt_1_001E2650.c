#include "common.h"
void vsnprintf(char *, s32, const char *, void *);
void Sjis_ToWide_2_001E5C60(s32, s32, char *, s32);
void GsText_DrawString_2_001E2748(f32 *, s32);
typedef struct { char pad[0x134]; s32 x134; } G;
extern G *D_00201E5C;
extern f32 *D_00201E60;
void GsText_PrintfAt_1_001E2650(f32 *a, const char *fmt, ...) {
    char buf[0x200];
    vsnprintf(buf, 0x1FF, fmt, (char *)__builtin_next_arg(fmt) - 0x30);
    buf[0x1FF] = 0;
    Sjis_ToWide_2_001E5C60(D_00201E5C->x134, 0x100, buf, -1);
    *D_00201E60 = *a;
    GsText_DrawString_2_001E2748(a, D_00201E5C->x134);
}
