#include "m2c.h"
typedef struct { u8 p:3; u8 v:1; } B;
void func_00154700(M2C_UNK, M2C_UNK);
void func_00155900();
void func_0017FF70(M2C_UNK *);
extern M2C_UNK D_001FD870[];

void func_001A3C10(s8 *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0) == 0) {
        func_00155900();
        func_0017FF70(D_001FD870);
        func_00154700(5, 0);
        ((B *)(arg0 + 0x14))->v = 1;
    }
}
