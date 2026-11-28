#include "common.h"
typedef struct { unsigned int : 1; unsigned int f : 1; } B_Bestiary_IsSeen_2_001A9EC0;
typedef struct { unsigned char : 1; unsigned char f : 1; } B_Bestiary_SetSeen_1_001A9F10;
typedef struct { unsigned char : 0; unsigned char f : 1; } B_Bestiary_SetKilled_1_001A9FA0;
extern u8 *D_00201DC8;
s32 Bestiary_IsSeen_2_001A9EC0(s16 i);
void Bestiary_SetSeen_1_001A9F10(s16 i);
s32 Bestiary_IsKilled_1_001A9F60(s16 i);
void Bestiary_SetKilled_1_001A9FA0(s16 i);

/* Bestiary_IsSeen_2_001A9EC0 */
s32 Bestiary_IsSeen_2_001A9EC0(s16 i)
{
    if (0 > i || i > 0x80)
        return 0;
    return ((B_Bestiary_IsSeen_2_001A9EC0 *)&D_00201DC8[i])->f;
}

/* Bestiary_SetSeen_1_001A9F10 */
void Bestiary_SetSeen_1_001A9F10(s16 i)
{
    if (0 > i || i > 0x80)
        return;
    ((B_Bestiary_SetSeen_1_001A9F10 *)&D_00201DC8[i])->f = 1;
}

/* Bestiary_IsKilled_1_001A9F60 */
s32 Bestiary_IsKilled_1_001A9F60(s16 i)
{
    if (0 > i || i > 0x80)
        return 0;
    return D_00201DC8[i] & 1;
}

/* Bestiary_SetKilled_1_001A9FA0 */
void Bestiary_SetKilled_1_001A9FA0(s16 i)
{
    if (0 > i || i > 0x80)
        return;
    ((B_Bestiary_SetKilled_1_001A9FA0 *)&D_00201DC8[i])->f = 1;
}
