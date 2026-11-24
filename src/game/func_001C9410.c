#include "m2c.h"
void func_00102A60(s8 *, s8 *);
extern s8 *D_002022E4;

void func_001C9410(f32 *arg0) {
    s8 *p;
    if (D_002022E4 == NULL) {
        p = 0;
    } else {
        p = *(s8 **)(D_002022E4 + 0x518);
        if (p == 0) {
            p = 0;
        } else {
            p = p + 0x180;
        }
    }
    if (p) {
        func_00102A60((s8 *)arg0, p + 0x40);
    }
    arg0[1] += 220.0f;
}
