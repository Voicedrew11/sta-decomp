#include "common.h"
void func_0018A330(s32);                         /* extern */
s64 func_001C99C0();                                /* extern */
extern s32 D_00201EA0;
extern u8 D_00222A53[];

s32 func_0012C110(s32 arg0) {
    if ((((u64) ((s64) (*D_00222A53) << 0x3B) >> 0x3F) != 0) && (((s64) (func_001C99C0() << 0x30) >> 0x30) <= 0) && (arg0 != 0x28)) {
        return 0;
    }
    if (D_00201EA0 != 0) {
        return 0;
    }
    func_0018A330(arg0 & 0xFF);
    return 1;
}
