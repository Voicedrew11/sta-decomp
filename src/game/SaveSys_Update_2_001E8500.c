#include "common.h"
extern s32 D_002023D8;
extern u32 D_002023DC;
s32 Mc_Update_4_001D6D00(void);
void SaveSys_StepCheckSpace_0_001E7C10(s32);
void SaveSys_StepScan_1_001E7880(s32);
void SaveSys_StepSave_2_001E64E0(s32);
void SaveSys_StepLoad_2_001E72A0(s32);
void SaveSys_StepCheckCard_0_001E7FA0(s32);
void SaveSys_StepUnformat_1_001E7DF0(s32);
s32 SaveSys_Update_2_001E8500(void) {
    s32 r;
    if (D_002023D8 < 0) {
        D_002023D8 = 0;
        D_002023DC = 1;
    }
    r = Mc_Update_4_001D6D00();
    if (0 < r) {
        return 0;
    }
    switch (D_002023DC) {
    case 0: break;
    case 1: SaveSys_StepCheckSpace_0_001E7C10(r); break;
    case 2: SaveSys_StepScan_1_001E7880(r); break;
    case 5: SaveSys_StepSave_2_001E64E0(r); break;
    case 6: SaveSys_StepLoad_2_001E72A0(r); break;
    case 3: SaveSys_StepCheckCard_0_001E7FA0(r); break;
    case 4: SaveSys_StepUnformat_1_001E7DF0(r); break;
    }
    return 0;
}
