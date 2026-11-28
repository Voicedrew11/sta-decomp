#include "common.h"
void Color_Double_0_001878A0(u8 *c);
void Color_Pulse_1_00187960(u8 *p, f32 f);
void Color_PulseB_1_00187A20(u8 *c, f32 t);
f32 fabsf(f32);
f32 sinf(f32);

/* Color_Double_0_001878A0 */
void Color_Double_0_001878A0(u8 *c) {
    s32 v;
    v = (c[0] * 256) / 128;
    c[0] = v < 0 ? 0 : (v > 0xFF ? 0xFF : v);
    v = (c[1] * 256) / 128;
    c[1] = v < 0 ? 0 : (v > 0xFF ? 0xFF : v);
    v = (c[2] * 256) / 128;
    c[2] = v < 0 ? 0 : (v > 0xFF ? 0xFF : v);
}

/* Color_Pulse_1_00187960 */
void Color_Pulse_1_00187960(u8 *p, f32 f) {
    s32 v = 96.0f + fabsf(128.0f * sinf(0.05f * f));
    p[0] = p[0] * v / 128;
    p[1] = p[1] * v / 128;
    p[2] = p[2] * v / 128;
}

/* Color_PulseB_1_00187A20 */
void Color_PulseB_1_00187A20(u8 *c, f32 t)
{
    s32 k = fabsf(128.0f * sinf(0.05f * t));
    c[3] = c[3] * k / 128;
}
