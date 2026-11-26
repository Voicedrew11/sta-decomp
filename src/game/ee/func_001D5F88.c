#include "common.h"
typedef struct { s32 type[8]; s32 free[8]; s32 format[8]; s32 res[8]; s32 port; s32 slot; s32 x88; s32 step; s32 x90; s32 x94; s32 err; s32 retry; s32 name; s32 xa4; u32 size; s32 xac; s32 xb0; u8 *buf; } T;
extern T D_004B63B8;
extern s32 D_004B63B4[];
extern s32 D_004B6474[];
extern u8 D_004B6478[];
s32 func_001D3BF0(s32, s32, s32 *, s32 *, s32 *, s32);
s32 func_001D3CE0(s32 n);
void func_001D3DA8(s32);
void *func_00123A88(void *, void *, s32);
void memset(void *, s32, s32);
s32 sceMcOpen(s32, s32, s32, s32);
s32 sceMcRead(s32, void *, s32);
s32 sceMcClose(s32);
s32 sceMcSync(s32, s32 *, s32 *);

s32 func_001D5F88(void) {
    s32 step = D_004B63B8.step;
    s32 j = D_004B63B8.slot;
    s32 i = D_004B63B8.port;
    s32 r;
    s32 e;
    switch (step) {
    case 0:
        D_004B6474[0] = 0;
        D_004B63B4[0] = 0;
        D_004B63B8.step++;
        D_004B63B8.retry = 0;
    case 1:
        D_004B63B8.x90 = func_001D3BF0(i, j, &D_004B63B8.type[i * 4 + j], &D_004B63B8.free[i * 4 + j], &D_004B63B8.format[i * 4 + j], D_004B63B8.x90);
        if (D_004B63B8.x90 > 0) break;
        e = func_001D3CE0(D_004B63B8.x90);
        D_004B63B8.err = e;
        if (e != 0) {
            D_004B63B8.x88 = 0;
            return -10;
        }
        if (D_004B63B8.type[i * 4 + j] != 2) {
            D_004B63B8.step = 100;
            break;
        }
        D_004B63B8.step++;
        break;
    case 2:
        if (sceMcOpen(i, j, D_004B63B8.name, 1) != 0) {
            if (D_004B63B8.retry == 2) {
                D_004B63B8.step = 100;
                break;
            }
            D_004B63B8.retry++;
            break;
        }
        D_004B63B8.step++;
        break;
    case 3:
        if (sceMcSync(1, 0, &r) == 0) break;
        if (r < 0) {
            if (D_004B63B8.retry == 2) {
                func_001D3DA8(r);
                if (D_004B63B8.err == 100) D_004B63B8.err = 0x47;
                D_004B63B8.step = 100;
                D_004B63B8.x90 = -1;
                D_004B63B8.x88 = 0;
                return r;
            }
            D_004B63B8.retry++;
            D_004B63B8.step--;
            break;
        }
        D_004B6474[0] = r;
        D_004B63B8.step++;
        break;
    case 4:
        memset(D_004B6478, 0, 0x400);
        D_004B63B8.retry = 0;
        D_004B63B8.step++;
        break;
    case 5:
        if (sceMcRead(D_004B6474[0], D_004B6478, 0x400) != 0) {
            if (D_004B63B8.retry == 2) {
                D_004B63B8.step = 100;
                break;
            }
            D_004B63B8.retry++;
            break;
        }
        D_004B63B8.step++;
        break;
    case 6:
        if (sceMcSync(1, 0, &r) == 0) break;
        if (r < 0) {
            if (D_004B63B8.retry == 2) {
                D_004B63B8.x90 = r;
                D_004B63B8.step = 100;
                break;
            }
            D_004B63B8.retry++;
            D_004B63B8.step--;
            break;
        }
        D_004B63B8.retry = 0;
        if (D_004B63B8.size < D_004B63B4[0] + r) {
            r = D_004B63B8.size - D_004B63B4[0];
            func_00123A88(D_004B63B8.buf + D_004B63B4[0], D_004B6478, r);
            D_004B63B8.step--;
            break;
        }
        func_00123A88(D_004B63B8.buf + D_004B63B4[0], D_004B6478, r);
        D_004B63B4[0] += r;
        D_004B63B8.step++;
        break;
    case 7:
        D_004B63B8.retry = 0;
        D_004B63B8.step++;
        break;
    case 8:
        if (sceMcClose(D_004B6474[0]) != 0) {
            if (D_004B63B8.retry == 2) {
                D_004B63B8.x88 = 0;
                D_004B63B8.err = 0x47;
                return -1;
            }
            D_004B63B8.retry++;
            break;
        }
        D_004B63B8.step++;
        break;
    case 9:
        if (sceMcSync(1, 0, &r) == 0) break;
        D_004B63B8.x88 = 0;
        if (r < 0) {
            if (D_004B63B8.retry == 2) {
                D_004B63B8.err = 0x47;
                return r;
            }
            D_004B63B8.retry++;
            D_004B63B8.step--;
            break;
        }
        D_004B63B8.err = 0x48;
        return 1;
    case 100:
        if (D_004B6474[0] < 0) {
            D_004B63B8.err = 0x47;
            D_004B63B8.x88 = 0;
            return D_004B63B8.x90;
        }
        D_004B63B8.retry = 0;
        D_004B63B8.step++;
        break;
    case 101:
        if (sceMcClose(D_004B6474[0]) != 0) {
            if (D_004B63B8.retry == 2) {
                D_004B63B8.x88 = 0;
                D_004B63B8.err = 0x47;
            }
            D_004B63B8.retry++;
            break;
        }
        D_004B63B8.step++;
        break;
    case 102:
        if (sceMcSync(1, 0, &r) == 0) break;
        D_004B63B8.err = 0x47;
        D_004B63B8.x88 = 0;
        return -100;
    }
    return 0;
}
