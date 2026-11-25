#include "m2c.h"
typedef union { u128 q; u32 w[4]; } V;
typedef union { u32 w; u8 b[4]; } C;
typedef void (*Fn)(void);
void func_0018A310(s32);
f32 func_00187770(f32, f32, f32);
void func_001875C0(s32, s32, u32, f32, f32, f32);
void func_0017F5C0(void);
void func_0019CCF0(f32, s32);
void func_00185390(f32, s32, s32, s32);
void func_00182080(s32, f32, V *, V *, C *, s32);
void func_0019C9B0(u8 *, f32);
s32 func_001958A0(void);
s32 func_001957E0(s32, s32);
extern Fn D_001F28D0[];
extern V D_001F3120[];
extern V D_001F3130[];
extern f32 D_00201D70;
extern f32 D_00201D74;
extern s32 *D_00201D68;
extern s32 D_002021E4;
extern s32 D_002021E8;
extern s32 D_002021F8;
extern s32 D_00202200;
extern s32 D_004A3290[];
static inline s32 get(s32 id) {
    s32 t = func_001958A0();
    if (id == 0) {
        return 0;
    }
    if (id == -1) {
        return 0;
    }
    if (t == 0) {
        return 0;
    }
    return func_001957E0(t, id);
}

void func_0019C6D0(u8 *arg0) {
    C c;
    C col;
    V a;
    V b;
    s32 id;
    s32 k;
    f32 f;

    D_001F28D0[0]();
    func_0018A310(0xC);
    if (arg0[8] == 0x15) {
        D_00201D70 = func_00187770(D_00201D70, -0.02f, 3.5f);
        id = D_00201D68[D_004A3290[0]];
        if (id > 0) {
            c.w = 0x80808080;
            func_001875C0(get(id), 2, *(u32 *)&c, 622.0f, 17.0f, 1.1f);
        }
    } else {
        D_00201D70 = func_00187770(D_00201D70, -2.99f, 3.5f);
    }
    if (!(D_00201D70 <= -2.89f)) {
        func_0017F5C0();
        D_002021E4 = 0;
        f = -D_00201D70 / 1.5f;
        k = D_00201D68[D_004A3290[0]];
        if (D_002021F8 <= 0) {
            k = -1;
        }
        func_0019CCF0(f, k);
        func_00185390(-f, 1, D_002021F8 - 1, D_004A3290[0]);
    }
    a = D_001F3120[0];
    b = D_001F3130[0];
    if (D_002021E8 == 1) {
        D_00201D74 = D_00201D74 - (D_00201D74 - 10.0f) / 4.0f;
        D_00202200 = D_00202200 - (D_00202200 - 64.0f) / 4.0f;
    } else {
        D_00201D74 = D_00201D74 - (D_00201D74 + 300.0f) / 4.0f;
        D_00202200 = D_00202200 - D_00202200 / 4.0f;
    }
    col.w = 0;
    col.b[3] = D_00202200;
    func_00182080(0, 0.0f, &a, &b, &col, 0);
    func_0019C9B0(arg0, D_00201D74);
}
