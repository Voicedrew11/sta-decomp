#include "m2c.h"
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 pad; s16 h; u16 vol; } St;
extern St D_00201EE0;
extern u8 D_0022EBD9[];
extern u8 D_001FABB8[];
extern u8 D_001FABC0[];
void FlushCache(s32);
s32 func_00116EA0(void *, void *);
s32 sceCdGetError(void);
void memset(void *, s32, s32);
void sprintf(void *, void *, s32);
void func_001D7FD0(void);
s32 func_001D8C50(void);
void func_001D8CA0(s32, u16, u16);
s32 func_001D8CC0(s32, s32);
void func_001D8CE0(s32, s32, s32);
void func_001D8D20(s32, void *, s32);
void func_001D8DF0(void);
void func_001D8E30(void);

s32 func_00130590(s32 arg0, s32 arg1, s32 arg2) {
    s32 i = 0;
    s32 info[12];
    u8 name[0x100];
    if (D_00201EE0.b1) return -1;
    func_001D7FD0();
    func_001D8E30();
    D_00201EE0.vol = (D_0022EBD9[0] * 0x3FFF) / 127;
    func_001D8CA0(1, D_00201EE0.vol, D_00201EE0.vol);
    if (arg2) D_00201EE0.b2 = 1; else D_00201EE0.b2 = 0;
    if (arg1 == 0) {
        sprintf(name, D_001FABB8, arg0);
        while (func_00116EA0(info, name) == 0) {
            s32 r = sceCdGetError();
            i++;
            if (r == 0) {
                if (i > 10) {
                    func_001D8DF0();
                    return -1;
                }
                memset(info, 0, 0x24);
                break;
            }
        }
        FlushCache(0);
        func_001D8CE0(1, info[0], 0x10000);
        D_00201EE0.b0 = 1;
    } else {
        sprintf(name, D_001FABC0, arg0);
        func_001D8D20(1, name, 0x10000);
        while (func_001D8C50() == 0) {}
        if (func_001D8CC0(1, D_00201EE0.b2 != 0) == 0) {
            func_001D8DF0();
            return -1;
        }
        D_00201EE0.b0 = 0;
    }
    D_00201EE0.h = 0;
    D_00201EE0.b1 = 1;
    return 0;
}
