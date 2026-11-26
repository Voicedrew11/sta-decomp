#include "actor.h"
typedef struct { u8 pad[0x94]; Flags8 f94; } R;
typedef struct {
    u8 pad[0x390];
    R *x390;
    u8 pad394[0x39C - 0x394];
    u8 x39C;
    u8 pad39D;
    u16 lo : 6;
    u16 f39E : 6;
    u16 hi : 4;
    u8 pad3A0[2];
    Flags8 f3A2;
    u8 pad3A3[0x3D5 - 0x3A3];
    u8 x3D5;
    Flags8 f3D6;
} S;
typedef struct { u8 pad[0x30]; s32 x30; } Ev;
extern s32 D_00201EB0;
void func_0012C110(s32);
s32 func_001D1CB0(s32);
void func_001C0020(Actor *);
s32 func_001CCD90(s32);
void func_001CAEF0(s32);
s32 func_001C0550(Actor *);
void func_00179F10(void);
void func_001B90F0(void);
s32 func_001C13B0(void);
void func_001C1140(void);
static inline S *get(void) {
    S *r;
    s8 *base;
    s32 v;
    if (D_002022E4 == NULL) {
        r = NULL;
    } else if ((base = D_002022E4->unk518) == NULL) {
        r = NULL;
    } else {
        r = (S *)(base + 0x180);
    }
    return r;
}
static inline s32 fa(void) {
    S *r;
    s8 *base;
    s32 v;
    if (D_002022E4 == NULL) {
        r = NULL;
    } else if ((base = D_002022E4->unk518) == NULL) {
        r = NULL;
    } else {
        r = (S *)(base + 0x180);
    }
    if (r == NULL) v = 0; else v = r->f3D6.f.b0;
    return v;
}
static inline s32 fb(void) {
    S *r;
    s8 *base;
    s32 v;
    if (D_002022E4 == NULL) {
        r = NULL;
    } else if ((base = D_002022E4->unk518) == NULL) {
        r = NULL;
    } else {
        r = (S *)(base + 0x180);
    }
    if (r == NULL) v = 0; else v = r->f3D6.f.b1;
    return v;
}

void func_001C0E60(Actor *a, Ev *e) {
    s32 fl = e->x30;
    S *s = (S *)(a->unk518 + 0x180);
    S *p;
    if (fl & 1) {
        func_0012C110(0x13);
        return;
    }
    if (s->f39E && (fl & 0x4000)) {
        s->f39E = 0;
        return;
    }
    if (s->x3D5 == 8) return;
    if (!fa() && !fb()) {
        if ((fl & 0x4000) && D_00201EB0 != 1) {
            func_0012C110(0x14);
            return;
        }
        if (fl & 0x1000) {
            if (!s->f3D6.f.b3) {
                if (func_001D1CB0(s->x39C)) {
                    s->x390->f94.f.b0 = 0;
                    s->f3D6.f.b3 = 0;
                } else {
                    s->f3D6.f.b3 = 1;
                }
            }
            return;
        }
    }
    if (fl & 0x8000) {
        func_001C0020(a);
        return;
    }
    if (fl & 8) {
        func_001CAEF0(func_001CCD90(9));
        return;
    }
    if (s->f3A2.f.b0 && (fl & 0x2000)) {
        if (!func_001C0550(a)) {
            func_00179F10();
            func_001B90F0();
            p = get();
            if (p && !p->f39E) {
                if (!func_001C13B0()) func_001C1140();
            }
        }
    }
}
