#include "common.h"
void Color_Double_0_001878A0(u8 *c) {
    s32 v;
    v = (c[0] * 256) / 128;
    c[0] = v < 0 ? 0 : (v > 0xFF ? 0xFF : v);
    v = (c[1] * 256) / 128;
    c[1] = v < 0 ? 0 : (v > 0xFF ? 0xFF : v);
    v = (c[2] * 256) / 128;
    c[2] = v < 0 ? 0 : (v > 0xFF ? 0xFF : v);
}
