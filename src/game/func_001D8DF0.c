#include "common.h"
extern u16 D_0020230C;

void func_001D8DF0(void) {
    if (D_0020230C != 0) {
        func_001D85D0(5, 1, 0x40000);
        D_0020230C = 0;
    }
}
