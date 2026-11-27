#include "common.h"
typedef struct { u64 x0; } A;
extern A *D_00201E5C;
void func_001E24A0(void);
void func_001E3688(void);

s32 func_001E2430(void) {
    s32 *p = (s32 *)D_00201E5C;
    if (*p == 0) return 0;
    if (--*p != 0) return 0;
    func_001E24A0();
    if ((D_00201E5C->x0 & 0x1000000000000ULL) && *(u16 *)((u8 *)D_00201E5C + 4) != 0) func_001E3688();
    return *(u16 *)((u8 *)D_00201E5C + 4);
}
