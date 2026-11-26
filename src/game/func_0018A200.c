#include "m2c.h"
extern s32 D_00201CF0;
extern s32 D_004A0B20[];
extern s32 D_004A0B24[];
extern u8 D_004A0B2A[];
extern u8 D_004A0B2B[];
extern void (*D_001F27D0[])(void *);
void func_0018E460(void);
void func_0018AAD0(void *);
void func_0018A420(void *);
void func_001304C0(void);
void func_0018E450(void);

void func_0018A200(void) {
    func_0018E460();
    func_0018AAD0(D_004A0B20);
    switch (D_004A0B20[0]) {
    case 0:
        D_004A0B24[0] = 0;
        break;
    case 31:
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
    case 30:
        break;
    }
    if (D_004A0B2B[0] == 0) {
        D_001F27D0[D_00201CF0](D_004A0B20);
    }
    if (D_004A0B2A[0] != 0) {
        D_001F27D0[0](D_004A0B20);
    }
    D_004A0B24[0] = 0;
    func_0018A420(D_004A0B20);
    func_001304C0();
    func_0018E450();
}
