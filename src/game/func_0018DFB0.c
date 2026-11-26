#include "m2c.h"
typedef struct {
    s32 x0;
    s32 x4;
    u8 x8;
    u8 pad9;
    u8 xA;
    u8 xB;
} Obj;
void func_0018B150(s32 *, s32, s32, void (*)(), s32, f32);
void func_0018B320(s32 *);
s32 func_001E6110(void);
void func_0018E120(s32, void *);
void func_0018E0B0();
extern s32 D_004A1020[];
extern s32 D_004A1054[];
extern s32 D_004A1058[];
extern s32 D_004A1068[];
extern s32 D_004A106C[];
static inline s32 start(Obj *o, s32 r) {
    if (r == 1) {
        func_0018B150(D_004A1020, 0x79, 2, func_0018E0B0, 0, 1.0f);
        func_0018B320(D_004A1020);
        o->xA = 1;
        o->xB = 1;
        D_004A1054[0] = 0;
        D_004A1058[0] = 0;
        return 1;
    }
    return 0;
}

void func_0018DFB0(Obj *o) {
    s32 r;

    func_0018E120(0, D_004A1068);
    func_0018E120(1, D_004A106C);
    r = func_001E6110();
    func_0018E120(0, D_004A1068);
    func_0018E120(1, D_004A106C);
    if (!start(o, r) && (o->x4 & 0x2000)) {
        o->xA = 2;
    }
}
