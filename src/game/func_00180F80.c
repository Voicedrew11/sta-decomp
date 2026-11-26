#include "m2c.h"
typedef union { u128 q; u64 d[2]; u32 w[4]; f32 f[4]; } Q;
typedef struct { s32 x0; u8 b[4]; } Ent;
typedef struct { s16 x, y; } Pt;
extern s32 D_00202060;
extern s32 D_00202064;
extern Ent *D_00202068;
extern s32 D_00201F3C;
extern Ent D_004880B0[];
extern s8 D_004870B0[];
extern Pt D_004884B0[];
void func_001545D0(void);
void func_001543E0(s32, u64);
void func_00154420(void);
void *func_00154A80(s32);
void func_00154A70(void);
void func_001549D0(void);
void func_00181310(s16, s16, s8, u8 *, u64 **);
static inline s32 cl(s32 n) { if (!(n < 0x20)) return 0x20; return n; }

void func_00180F80(void) {
    s32 n;
    s32 i;
    s32 base;
    s32 end;
    s32 cnt;
    Q q;
    u64 *p;
    base = 0;
    cnt = 0;
    D_00202068 = D_004880B0;
    n = D_00202060;
    while (n != 0) {
        n = cl(n);
        func_001545D0();
        func_001543E0(0x3F, -1);
        func_001543E0(7, ((u64)0x20060645 << 32) | 0x9D407020);
        func_001543E0(0x15, 0x60);
        func_001543E0(0x43, 0x44);
        func_001543E0(0x48, 0x31001);
        func_001543E0(9, 5);
        func_00154420();
        end = n * 5;
        p = func_00154A80(end + 3);
        q.q = 0;
        q.w[0] = (end + 2) | 0x10000000;
        q.w[3] = ((end + 1) << 16) | 0x6C00C000;
        *(Q *)p = q;
        p += 2;
        *p = (s64)n | (((u64)0x51AF4000 << 32) | 0x8000);
        p++;
        *p = 0x41343;
        p++;
        end = n + base;
        for (i = base; i < end; i++) {
            if (D_00202068->x0 < cnt) {
                D_00202068++;
            }
            cnt++;
            func_00181310(D_004884B0[i].x, D_004884B0[i].y, D_004870B0[i], D_00202068->b, &p);
        }
        q.q = 0;
        q.w[3] = D_00201F3C | 0x15000000;
        *(Q *)p = q;
        p += 2;
        func_00154A70();
        base += n;
        D_00202060 -= n;
        n = D_00202060;
    }
    func_001549D0();
    D_004880B0[0].b[0] = 0x80;
    D_004880B0[0].b[1] = 0x80;
    D_00202064 = 0;
    D_004880B0[0].x0 = 0x7FFFFFFF;
    D_00202060 = 0;
    D_004880B0[0].b[2] = 0x80;
    D_004880B0[0].b[3] = 0x80;
}
