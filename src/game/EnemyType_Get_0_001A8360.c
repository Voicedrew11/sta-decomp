#include "common.h"
extern u8 *D_00202284;
void *EnemyType_Get_0_001A8360(s32 i) { if (i < 0 || i > 0xFF) return NULL; if (!D_00202284) return NULL; return (u8 *)(i * 64) + (s32)D_00202284 + 16; }
