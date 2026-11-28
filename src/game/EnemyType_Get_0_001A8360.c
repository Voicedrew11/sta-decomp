#include "common.h"
extern u8 *D_00202284;
void* EnemyType_Get_0_001A8360(s32 i);
s32 EnemyType_LoadTable_0_001A83A0(void *p);
void Arc_LoadFile_2_00159DD0(s32 id, void *p, s32 **a, s32 *b);

/* EnemyType_Get_0_001A8360 */
void *EnemyType_Get_0_001A8360(s32 i) { if (i < 0 || i > 0xFF) return NULL; if (!D_00202284) return NULL; return (u8 *)(i * 64) + (s32)D_00202284 + 16; }

/* EnemyType_LoadTable_0_001A83A0 */
#define D_00202284 D_00202284__as_EnemyType_LoadTable_0_001A83A0
extern s32 D_00202284__as_EnemyType_LoadTable_0_001A83A0;

s32 EnemyType_LoadTable_0_001A83A0(void *p)
{
    s32 b;
    s32 *a;
    Arc_LoadFile_2_00159DD0(0x3F114AF, p, &a, &b);
    D_00202284 = *a;
    return 0;
}
#undef D_00202284
