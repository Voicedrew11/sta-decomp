/* near-miss 12/170: case-1 call args: orig loads ch (lb a0) first and off before addr[arg1], addu a1,addr,off */
#include "m2c.h"
void FlushCache(s32);
void memcpy(s32 *, s8 *, u32);
void func_001789E0(s32 *, s8 *, u32);
s32 func_001DAC70();
s32 func_001DB020(s8, s32 *, u32);
typedef struct { s8 ch[0x20]; s32 addr[4]; } Tb;
extern Tb D_0022EBC0;
typedef struct { u32 off; s32 state; u32 n; u32 left; s32 buf[1]; } Ld;
extern Ld D_0022F080;

s32 func_0012F0F0(s8 *arg0, u32 arg1) {
    s32 r;
    s32 ret;
    u32 n;
    s8 *p;

    ret = -1;
    switch (D_0022F080.state) {
    case 0:
        if (arg1 >= 4 || D_0022EBC0.ch[arg1] == -1) {
            break;
        }
        D_0022F080.left = *(u32 *)(arg0 + 4);
        D_0022F080.state = 1;
        D_0022F080.off = 0;
        D_0022F080.n = 0;
    case 1:
        p = (s8 *)((s32)arg0 + 0x10) + ((*(s32 *)(arg0 + 0xC) + 0xF) & ~0xF) + D_0022F080.off;
        n = D_0022F080.left;
        if (n > 0x40000) {
            n = 0x40000;
        }
        D_0022F080.n = n;
        func_001DAC70(D_0022EBC0.ch[arg1], D_0022EBC0.addr[arg1] + D_0022F080.off, n);
        if (D_0022F080.n > 0x1000) {
            FlushCache(0);
            func_001789E0(D_0022F080.buf, p, ((D_0022F080.n + 0xF) & ~0xF) >> 4);
        } else {
            memcpy(D_0022F080.buf, p, D_0022F080.n);
        }
        FlushCache(0);
        ret = 0;
        D_0022F080.state = 2;
        break;
    case 2:
        r = func_001DB020(D_0022EBC0.ch[arg1], D_0022F080.buf, D_0022F080.n);
        if (r == 1) {
            D_0022F080.state = 3;
            goto three;
        }
        if (r == 0) {
            ret = 0;
            break;
        }
        D_0022F080.state = 0;
        break;
    case 3:
    three:
        D_0022F080.left = D_0022F080.left - (n = D_0022F080.n);
        D_0022F080.off += n;
        if (D_0022F080.left != 0) {
            ret = 0;
            D_0022F080.state = 1;
        } else {
            D_0022F080.state = 0;
            ret = 1;
            func_001DAC70(D_0022EBC0.ch[arg1], D_0022EBC0.addr[arg1]);
        }
        break;
    default:
        D_0022F080.state = 0;
        break;
    }
    FlushCache(0);
    return ret;
}
