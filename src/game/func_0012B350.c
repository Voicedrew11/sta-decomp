#include "common.h"
typedef struct { u8 pad[0x1D8]; u8 f; } Inner;
extern Inner **D_00201E80[2];
#define C (D_00201E80[2])
#define D (D_00201E80[3])
static inline s32 IS(Inner **p) { if (p != NULL) return ((*p)->f & 1) != 0; else return 0; }
typedef struct { u8 a:3; u8 b:3; u8 c:2; } BF;
extern BF D_00222A54[];
extern u32 D_00201E94;
extern s32 D_00201E98;
extern s32 D_00222A2C[];
extern s32 D_00222734[];
extern s32 D_00222730[];
extern s8 D_00222AF0[];
extern s8 D_00222B20[];
void func_0012B120(void);
s32 func_00154AC0(void);
void func_001E8500(void);
s32 func_001787A0(void);
void func_00155370(void);
void func_00128210(void *);
void func_00128460(void *, s32);
void func_00169780(void);
void func_00169790(void);
void func_00178760(void);
void func_001769C0(void);
void func_0015FC10(void);
void func_001296C0(void);
void func_001552A0(void);
void func_0012A520(f32);
void func_001C9830(void);
void func_001B4100(Inner *);
void func_0012A070(void);
s32 func_001170C8(s32);
void func_001DF9A0(void);
void func_0012AA30(void);

s32 func_0012B350(void) {
    s32 t;

    t = 0;
    func_0012B120();
    while (!D_00201E98 != 0) {
        D_00222A2C[0] = func_00154AC0();
        func_001E8500();
        D_00222734[0] = func_001787A0() - t;
        D_00222A54[0].b = 0;
        func_00155370();
        func_00128210(D_00222AF0);
        func_00128210(D_00222B20);
        func_00169780();
        D_00222730[0] = func_001787A0() - t;
        func_00178760();
        t = func_001787A0();
        func_001769C0();
        func_0015FC10();
        func_001296C0();
        func_001552A0();
        func_0012A520(0.033333335f);
        func_001C9830();
        if (IS(C)) func_001B4100(*C);
        if (IS(D)) func_001B4100(*D);
        func_00128460(D_00222AF0, -1);
        func_00128460(D_00222B20, -1);
        func_00169790();
        func_0012A070();
        if (D_00201E94 % 15 == 0 && func_001170C8(1) == 0) {
            func_001DF9A0();
        }
        D_00201E94++;
    }
    func_0012AA30();
    return 0;
}
