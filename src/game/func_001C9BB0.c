#include "common.h"
void memcpy(s32, s32, s32);           /* extern */
extern s32 D_00201E20;

void func_001C9BB0(s32 arg0) {
    memcpy(D_00201E20, arg0, 0x10A0);
    func_001CEDC0(3);
    func_001CEA50(0);
}
