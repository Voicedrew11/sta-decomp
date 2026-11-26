#include "m2c.h"
typedef struct { u8 pad[0x1D8]; u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; } R;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; } B8;
typedef struct {
    u16 v0;
    u8 pad2[0x4A6];
    R **r;
    u8 pad4ac[0x5A0 - 0x4AC];
    u8 f5a0;
    B8 f5a1;
} P;
typedef struct { f32 x, y, z, w; } V;
extern B8 D_00222A50[];
extern P **D_004A4570[];
void func_001548F0(s32);
void func_001329D0(s32, s32, s32);
void func_00155900(void);
void func_001A7030(P *, s32, s32);
s32 func_0013E2B0(P *);
void func_001A5DE0(P *);
u32 func_001C9C00(s32);
void func_00132930(V *);
void func_0016B280(void);
static inline void setb6(P *p, s32 v) { p->f5a1.b6 = v; }

void func_001A6770(void) {
    V v;
    s32 i;
    P ***pp;
    if (!D_00222A50[0].b6) {
        func_001548F0(4);
        func_001329D0(0x15E, 0x100, 0x100);
        func_00155900();
    }
    i = 0;
    pp = D_004A4570;
    for (; i < 0x81; i++, pp++) {
        P **q = *pp;
        if (q != NULL) {
            P *p = *q;
            if (p != NULL && p->v0 != 0) {
                func_001A7030(p, 0, 0);
                setb6(p, 0);
                if (!p->f5a1.b5) {
                    R **rr = p->r;
                    R *r;
                    if (rr == NULL || (r = *rr) == NULL || !r->b3) {
                        u8 f = p->f5a0;
                        if ((f & 1) && ((u64)((s64)f << 0x3D) >> 0x3F) && func_0013E2B0(p) != 0) {
                            func_001A5DE0(p);
                        }
                    }
                }
            }
        }
    }
    if (!D_00222A50[0].b6) {
        func_001548F0(4);
        v.w = (f32)func_001C9C00(0) / 255.0f;
        func_00132930(&v);
        func_00155900();
    }
    func_0016B280();
}
