#include "common.h"
typedef struct { u8 pad[0x30]; u32 x30[8]; s32 x50[8]; } P;
P *PlayerData_Get_2_001C9BA0(void);
u32 PlayerData_GetStatusTimer_0_001CE200(s32 x) {
    P *p = PlayerData_Get_2_001C9BA0();
    if (x < 0 || x >= 7) return 0;
    if (p->x50[x] == 0 && p->x30[x] != 0) return p->x30[x] >> 24;
    return 0;
}
