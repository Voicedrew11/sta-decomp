#include "actor.h"
typedef struct { u8 pad0[0x94]; u8 b94; } R;
typedef struct { u8 pad0[0x94]; Flags8 f94; } R2;
typedef struct {
    u8 pad0[0x390];
    R *x390;
    u8 pad394[0x3C0 - 0x394];
    s8 *x3C0;
    s8 *x3C4;
} P;
s32 func_001DB4D0(void);
s32 func_001DAF80(void);
s32 func_001DAA50(void);
void func_0012E730(s32);
s32 func_0012E640(s32, s32);
s32 func_0012ED60(s32, s32);
s32 func_0012EA00(s32, s32);
u8 func_001A9470(void);
void func_001DA8F0(s32, s16);
s32 func_001E1D20(void);
s32 func_001D9710(void);
s32 func_001D8FA0(void);
void func_001313C0(u8);
extern Actor *D_002022E4;
extern Flags8 D_0022EC40[];
extern Flags8 D_0022EC41[];
extern Flags8 D_0022EC42[];
extern Flags8 D_0022EC43[];
extern s32 D_0022EC44[];
extern s16 D_0022EC48[];
extern s16 D_0022EC4A[];
extern u8 D_0022EC20[];
extern s32 D_0022F054[];
extern s32 D_0022F064[];
extern s32 D_0022F074[];
extern s32 D_0022F084[];
extern s32 D_00222B54[];
extern s8 D_0022EBC9[];
extern s8 D_0022EBCB[];
extern u8 D_0022EBD9[];
extern s8 D_00201ED5;
extern s8 D_00201ED6;
extern s8 D_00201ED7;
#define SCAN() { \
    s32 j; \
    for (j = 0; j < 4; j++) { \
        if (!(D_0022EC40[j].f.b0 != 0) == 0) { \
            D_0022EC48[0] = 1; \
            break; \
        } \
    } }
#define FAIL(F) { \
    D_0022EC48[0] = 0; \
    F[0].f.b0 = 0; \
    F[0].f.b2 = 0; \
    SCAN(); \
    return -1; \
}
#define DONE(F) \
    D_0022EC4A[0] = 0; \
    D_0022EC48[0] = 0; \
    F[0].f.b1 = 0; \
    F[0].f.b0 = 0; \
    F[0].f.b2 = 0; \
    SCAN();
#define CHAIN(b) (*(s32 *)*(s8 **)(*(s8 **)*(s8 **)*(s8 **)(b) + 0x10))
static inline s32 init(void) {
    if (func_001DB4D0()) return 0;
    if (func_001DAF80()) return 0;
    if (func_001DAA50()) return 0;
    D_0022F084[0] = 0;
    return 1;
}
static inline s8 *pick(void) {
    P *p = (P *)(D_002022E4->unk518 + 0x180);
    return (p->x390->b94 & 1) == 0 ? p->x3C0 : p->x3C4;
}

s32 func_0012C7C0(void) {
    s32 i;
    s32 r;
    s8 *pk;
    s8 *q;
    s8 *d;
    s32 v;
    if (D_0022EC48[0] == 0) return 1;
    if (D_0022EC44[0] != 0) {
        if (init()) {
            D_0022EC44[0] = 0;
            D_0022EC4A[0] = 0;
        } else {
            return 0;
        }
    }
    if (D_0022EC4A[0] == 0 && (D_0022EC43[0].b & 1)) {
        if (!D_0022EC43[0].f.b2) {
            func_0012E730(3);
            D_0022EC43[0].f.b2 = 1;
            return 0;
        }
        pk = pick();
        if (pk == NULL || **(s32 **)(pk + 0x84) == 0) {
            D_0022EC43[0].f.b0 = 0;
            return -1;
        }
        if (D_0022F074[0] == 0) FAIL(D_0022EC43);
        if (func_0012E640(CHAIN(*(s8 **)(pk + 0x84)) + D_0022F074[0], 3) == -1) FAIL(D_0022EC43);
        D_0022EC4A[0] = 1;
        D_0022EC43[0].f.b1 = 1;
        return 0;
    }
    if (D_0022EC4A[0] != 0 && D_0022EC43[0].f.b1) {
        pk = pick();
        q = (s8 *)(CHAIN(*(s8 **)(pk + 0x84)) + D_0022F074[0] + 0x10);
        if (q == NULL) FAIL(D_0022EC43);
        d = q + *(s32 *)q;
        if (d == NULL) FAIL(D_0022EC43);
        r = func_0012ED60((s32)d, 3);
        if (r == 1) {
            DONE(D_0022EC43);
            D_00201ED7 = 1;
            v = func_001A9470() * 2;
            if (v > 0x7F) v = 0x7F;
            func_001DA8F0(D_0022EBCB[0], v);
        } else {
            return -(r == -1);
        }
    }
    if (D_0022EC4A[0] == 0 && (D_0022EC41[0].b & 1)) {
        if (!func_001E1D20()) return -1;
        if (!D_0022EC41[0].f.b2) {
            func_0012E730(1);
            D_0022EC41[0].f.b2 = 1;
            return 0;
        }
        if (func_0012E640(D_00222B54[0] + D_0022F054[0], 1) == -1) FAIL(D_0022EC41);
        D_0022EC4A[0] = 1;
        D_0022EC41[0].f.b1 = 1;
        return 0;
    }
    if (D_0022EC4A[0] != 0 && D_0022EC41[0].f.b1) {
        if (!func_001E1D20()) return -1;
        q = (s8 *)(D_00222B54[0] + D_0022F054[0] + 0x10);
        if (q == NULL) FAIL(D_0022EC41);
        d = q + *(s32 *)q;
        if (d == NULL) FAIL(D_0022EC41);
        r = func_0012ED60((s32)d, 1);
        if (r == 1) {
            DONE(D_0022EC41);
            D_00201ED5 = 1;
            v = func_001A9470() * 2;
            if (v > 0x7F) v = 0x7F;
            func_001DA8F0(D_0022EBC9[0], v);
        } else {
            return -(r == -1);
        }
    }
    if (D_0022EC4A[0] == 0 && (D_0022EC42[0].b & 1)) {
        if (!func_001E1D20()) return -1;
        if (D_0022EC20[0] != 0) return 0;
        if (!func_001D9710()) return 0;
        if (func_001D8FA0()) return 0;
        D_0022EC20[0] = 0;
        if (func_0012E640(D_00222B54[0] + D_0022F064[0], 2) == -1) FAIL(D_0022EC42);
        D_0022EC4A[0] = 1;
        D_0022EC42[0].f.b1 = 1;
        return 0;
    }
    if (D_0022EC4A[0] != 0 && D_0022EC42[0].f.b1) {
        if (!func_001E1D20()) return -1;
        q = (s8 *)(D_00222B54[0] + D_0022F064[0] + 0x10);
        if (q == NULL) FAIL(D_0022EC42);
        d = q + *(s32 *)q;
        if (d == NULL) FAIL(D_0022EC42);
        r = func_0012EA00((s32)d, 2);
        if (r == 1) {
            DONE(D_0022EC42);
            D_00201ED6 = 1;
            func_001313C0(D_0022EBD9[0]);
        } else if (r == -1) {
            FAIL(D_0022EC42);
        } else {
            return 0;
        }
    }
    return 1;
}
