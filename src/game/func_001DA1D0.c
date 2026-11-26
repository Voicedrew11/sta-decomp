#include "common.h"

typedef struct { s32 x0; s32 x4; s32 x8; u16 xC; u16 xE; } B;
typedef struct { s8 x0; s8 x1; s8 x2; s8 x3; } C;
extern struct { char pad[0x200]; B b[8]; C c[64]; } D_004BA500;
extern s32 D_004BA4F8[];
extern s16 D_004BA300[];
extern s32 D_00202320;
extern s32 D_00202324;
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } R;
void memset(void *, s32, s32);
s32 func_001D8350(s32 a, s32 b, s32 c, s32 d, s32 e, void *m);
void func_001DA340(s32 *, s32 *, s32, s32, s32);

void func_001DA1D0(s32 n0, R *r0)
{
    R *r;
    s32 n;
    s32 cnt;
    C *c;
    C *cb;
    s16 *p;
    r = r0;
    n = n0;
    if (n0 > 0) {
        cb = D_004BA500.c - 0xA0;
        do {
            cnt = 0;
            memset(D_004BA300, 0, 0x1FC);
            p = D_004BA300;
            while (cnt < 63 && n > 0) {
                c = cb + 0xA0;
                if (c->x2 == 1) {
                    func_001DA340(&D_00202320, &D_00202324, r->x0, -r->x4, 0x7FF);
                    cnt++;
                    p[0] = D_00202320;
                    p[63] = D_00202324;
                    p[126] = ((u16)c->x0 << 8) | D_004BA500.b[c->x1].xC;
                    p[189] = r->xC;
                    D_004BA4F8[0] = cnt;
                    p++;
                }
                r++;
                cb++;
                n--;
            }
            if (cnt > 0)
                func_001D8350(4, 0, 0x1FC, 0, 0x411C00, D_004BA300);
        } while (n > 0);
    }
}
