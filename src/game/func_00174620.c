#include "m2c.h"
M2C_UNK func_001536F0(s32, s8 *);                 /* extern */
M2C_UNK func_001746A0();                            /* static */

s32 func_00174620(s32 *arg0, s32 arg1) {
    if (arg1 == 0) {
        return 0;
    }
    if (arg0 == NULL) {
        return 0;
    }
    *arg0 = arg1;
    func_001536F0(arg1, (s8 *)arg0 + 4);
    func_001536F0(arg1, (s8 *)arg0 + 0x34);
    func_001746A0();
    return 1;
}
