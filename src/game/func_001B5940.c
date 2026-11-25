#include "m2c.h"
typedef struct { s32 pad[6]; s32 x18; s32 pad1C; } Info;
void func_001B0660(Info *);
void func_001B5640(s32);
void func_001B03E0(void);
void func_0015C6D0(s32);
void func_0015B890(s32);
void func_0012F920(void);
void func_001E1CC0(void);
extern s32 D_00201E80;
extern s32 D_002022B8;

void func_001B5940(void) {
    Info info;

    func_001B0660(&info);
    if (info.x18 != 0) {
        func_001B5640(info.x18);
    }
    func_001B03E0();
    if ((&D_00201E80)[2] != 0) {
        func_0015C6D0(0);
        func_0015B890(0);
        func_001B5640((&D_00201E80)[2]);
        (&D_00201E80)[2] = 0;
    }
    if ((&D_00201E80)[3] != 0) {
        func_0015C6D0(1);
        func_0015B890(1);
        func_001B5640((&D_00201E80)[3]);
        (&D_00201E80)[3] = 0;
    }
    func_0012F920();
    D_002022B8 = 0;
    func_001E1CC0();
}
