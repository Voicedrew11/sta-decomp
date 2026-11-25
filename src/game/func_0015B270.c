#include "common.h"
typedef union { u128 q; u64 d[2]; u32 w[4]; } Q;
extern u8 D_0030A2D0[];
extern s32 D_00201F2C;
Q *func_00154A80(s32);
void func_00154A70(void);
void func_00102A60(void *, void *);
void func_001545D0(void);
extern u64 func_0011F650(f32);
void func_001543E0(s32, u64);
void func_00154420(void);

void func_0015B270(void) {
    Vec c;
    Q q;
    Q *p;
    u64 r;
    u64 g;
    u64 b;
    q.q = 0;
    p = func_00154A80(1);
    q.w[0] = 0x30000001;
    q.w[1] = (u32)(D_0030A2D0 + D_00201F2C * 32);
    q.w[3] = 0x6C010059;
    p->q = q.q;
    func_00154A70();
    func_00102A60(&c, D_0030A2D0 + D_00201F2C * 32 + 0x10);
    func_001545D0();
    r = func_0011F650(255.0f * c.x);
    g = func_0011F650(255.0f * c.y);
    r |= g << 8;
    b = func_0011F650(255.0f * c.z);
    func_001543E0(0x3D, (b << 16) | r);
    func_00154420();
}
