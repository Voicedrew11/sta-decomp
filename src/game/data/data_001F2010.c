#include "common.h"

/* data_001F2010: the game's data at 0x001F2010..., one object per label. */
#pragma explicit_zero_data on

void func_0014DC00(void);
void func_0014DC10(void);
void func_0014DC50(void);
void func_0014DC70(void);

s32 D_001F2010[0x4] = { (s32)func_0014DC70, (s32)func_0014DC50, (s32)func_0014DC10, (s32)func_0014DC00 };
