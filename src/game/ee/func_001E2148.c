#include "common.h"
typedef struct { s32 x0; s32 p4[3]; s32 x10; s32 x14; s32 p18[6]; f32 x30; f32 x34; s32 p38[2]; f32 x40; f32 x44; s32 x48; s32 x4C; s32 x50; s32 x54; s32 x58; s32 x5C; f32 x60; } T;
typedef struct { s32 p[6]; s32 x18; s32 x1C; s32 x20; s32 x24; } U;
extern const f32 D_00201B80;
extern U *D_00201E5C;
extern T *D_00201E60;

void func_001E2148(void) {
D_00201E60->x5C = 0; D_00201E60->x48 = -1; D_00201E60->x4C = -1; D_00201E60->x10 = 0; D_00201E60->x14 = 0; D_00201E60->x30 = 1.0f; D_00201E60->x34 = 1.0f; D_00201E60->x40 = D_00201B80; D_00201E60->x44 = D_00201B80; D_00201E60->x58 = D_00201E60->x54 = D_00201E60->x50 = 0; D_00201E60->x60 = 3.0f; D_00201E60->x0 = 0; D_00201E5C->x1C = D_00201E5C->x18; D_00201E5C->x24 = 0;
}
