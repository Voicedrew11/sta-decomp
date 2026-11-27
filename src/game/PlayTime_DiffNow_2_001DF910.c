#include "common.h"

typedef struct { s32 a, b; } Pair;
extern Pair D_00202380, D_002023A0;
void PlayTime_Diff_2_001DF790(Pair a, Pair b);

void PlayTime_DiffNow_2_001DF910(void)
{
    PlayTime_Diff_2_001DF790(D_00202380, D_002023A0);
}
