#include "common.h"

extern struct { unsigned char : 1; unsigned char f : 1; } D_00201EE0;
void func_001D8C80(s32 a);
void func_001D8C60(s32 a);
void func_001D8DF0(void);
void func_001D7EC0(void);

void func_00130440(void)
{
    if (D_00201EE0.f) {
        int v = 0;
        func_001D8C80(1);
        func_001D8C60(1);
        func_001D8DF0();
        func_001D7EC0();
        D_00201EE0.f = v;
    }
}
