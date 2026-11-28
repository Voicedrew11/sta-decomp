#include "common.h"
typedef struct { u8 pad[0x30]; u32 x30[8]; s32 x50[8]; } P;
typedef struct { char pad[0x30]; s32 a[8]; s32 b[7]; } T_PlayerData_ClearStatus_0_001CE270;
typedef struct { u32 t:24; u32 h:8; } T_PlayerData_TickStatus_0_001CE2D0;
typedef struct { s8 pad[0x30]; T_PlayerData_TickStatus_0_001CE2D0 t[7]; s8 pad2[0x50 - 0x4C]; s32 c[7]; } B;
u32 PlayerData_GetStatusTimer_0_001CE200(s32 x);
void PlayerData_ClearStatus_0_001CE270(s32 i);
void PlayerData_TickStatus_0_001CE2D0(void);
P* PlayerData_Get_2_001C9BA0(void);

/* PlayerData_GetStatusTimer_0_001CE200 */
u32 PlayerData_GetStatusTimer_0_001CE200(s32 x) {
    P *p = PlayerData_Get_2_001C9BA0();
    if (x < 0 || x >= 7) return 0;
    if (p->x50[x] == 0 && p->x30[x] != 0) return p->x30[x] >> 24;
    return 0;
}

/* PlayerData_ClearStatus_0_001CE270 */
#define PlayerData_Get_2_001C9BA0 PlayerData_Get_2_001C9BA0__as_PlayerData_ClearStatus_0_001CE270
T_PlayerData_ClearStatus_0_001CE270 *PlayerData_Get_2_001C9BA0__as_PlayerData_ClearStatus_0_001CE270(void);

void PlayerData_ClearStatus_0_001CE270(s32 i)
{
    T_PlayerData_ClearStatus_0_001CE270 *t = PlayerData_Get_2_001C9BA0();
    if (i < 0 || i >= 7)
        return;
    t->b[i] = 150;
    t->a[i] = 0;
}
#undef PlayerData_Get_2_001C9BA0

/* PlayerData_TickStatus_0_001CE2D0 */
#define PlayerData_Get_2_001C9BA0 PlayerData_Get_2_001C9BA0__as_PlayerData_TickStatus_0_001CE2D0
B *PlayerData_Get_2_001C9BA0__as_PlayerData_TickStatus_0_001CE2D0(void);
void PlayerData_TickStatus_0_001CE2D0(void) {
    B *b = PlayerData_Get_2_001C9BA0();
    T_PlayerData_TickStatus_0_001CE2D0 *t;
    s32 *c;
    u32 i;
    s32 *p;
    u32 j;
    u32 n;
    u32 w;
    c = b->c;
    t = b->t;
    i = 0;
    p = c;
    do {
        if (*p != 0) *p = *p - 1;
        i++;
        p++;
    } while (i < 7);
    j = 0;
    do {
        n = t->t; w = *(u32 *)t >> 24;
        if (n != 0) {
            n--;
            *(u32 *)t = n | (w << 24);
            if (n == 0) {
                *c = 150;
                *(u32 *)t = 0;
            }
        }
        j++;
        t++;
        c++;
    } while (j < 7);
}
#undef PlayerData_Get_2_001C9BA0
