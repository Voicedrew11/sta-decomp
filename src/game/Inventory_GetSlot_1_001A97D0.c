#include "common.h"
typedef struct { char b[8]; } E;
typedef struct { char pad[0x5C00]; E e[0x400]; } S;
extern S *D_00201DC0;
E *Inventory_GetSlot_1_001A97D0(s16 i) { if (0 > i || i >= 0x400) return NULL; return &D_00201DC0->e[i]; }
