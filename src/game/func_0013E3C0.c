#include "common.h"
f32 func_0013E3C0(void *arg0) {
    f32 var_f0;

    var_f0 = M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0x518), void **, 0x198), f32 *, 4) - M2C_FIELD(arg0, f32 *, 0x5DC);
    if (var_f0 < 0.0f) {
        var_f0 = 0.0f;
    }
    return var_f0;
}
