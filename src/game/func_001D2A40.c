#include "m2c.h"
typedef struct { u8 p:2; u8 v:1; } B;

s32 func_001D2A40(u16 *arg0) {
    s32 r = *arg0 != 0;
    if (r) {
        r = !((B *)(*(s8 **)((s8 *)arg0 + 0x4B0) + 0x2AD))->v;
    }
    return r;
}
