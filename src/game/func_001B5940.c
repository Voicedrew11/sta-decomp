#include "common.h"

typedef struct { f32 v[4]; s32 x10; u8 b14; char p15[3]; s32 x18; } Out;
extern s32 D_00201E88, D_00201E8C;
extern s32 D_002022B8;
s32 func_001B0660(Out *o);
void func_001B5640(s32 h);
void func_001B03E0(void);
void func_0015C6D0(s32 i);
void func_0015B890(s32 i);
void func_0012F920(void);
void func_001E1CC0(void);

void func_001B5940(void)
{
    Out t;
    func_001B0660(&t);
    if (t.x18)
        func_001B5640(t.x18);
    func_001B03E0();
    if (D_00201E88) {
        func_0015C6D0(0);
        func_0015B890(0);
        func_001B5640(D_00201E88);
        D_00201E88 = 0;
    }
    if (D_00201E8C) {
        func_0015C6D0(1);
        func_0015B890(1);
        func_001B5640(D_00201E8C);
        D_00201E8C = 0;
    }
    func_0012F920();
    D_002022B8 = 0;
    func_001E1CC0();
}
