#include "common.h"
extern s32 D_004BAC3C[];
extern s32 D_004BAC48[];
extern u8 D_004BAC4C[];
extern Flags8 D_004BAC4D[];
void Task_Init_1_001E03C0();

s32 Task_Step_1_001E0020(u8 *p) {
    s32 s;
    if (!(D_004BAC4C[0] & 1)) {
        if (p == NULL) {
            while ((s = D_004BAC3C[0]) == 1 || s == 4) {
                if (D_004BAC48[0] != -1) D_004BAC4D[0].f.b1 = 1;
                Task_Init_1_001E03C0();
            }
            D_004BAC4D[0].f.b1 = 0;
        } else {
            while ((s = *p) == 1 || s == 4) {
                if (D_004BAC48[0] != -1) D_004BAC4D[0].f.b1 = 1;
                Task_Init_1_001E03C0();
            }
            D_004BAC4D[0].f.b1 = 0;
        }
        return 0;
    }
    return 0;
}
