#include "common.h"
typedef struct { s32 type[8]; s32 free[8]; s32 format[8]; s32 res[8]; s32 port; s32 slot; s32 x88; s32 step; s32 x90; s32 x94; s32 err; s32 retry; s32 name; s32 xa4; u32 size; s32 xac; s32 xb0; u8 *buf; } T;
typedef struct { u8 p[0x10]; u32 x10; } DE;
extern T D_004B63B8;
extern s32 D_004B63A4[];
extern s32 D_004B63A8[];
extern s32 D_004B63AC[];
extern s32 D_004B63B0[];
extern s32 D_004B6474[];
extern u8 D_004B6478[];
extern DE D_004B68C0[];
extern s32 D_004B68D0[];
s32 func_001D3BF0(s32, s32, s32 *, s32 *, s32 *, s32);
s32 func_001D3CE0(s32 n);
void func_001D3DA8(s32);
s32 func_0010FAD0(s8 *, s32);
void strcpy(s8 *, s32);
s32 sceLseek(s32, s32, s32);
s32 sceRead(s32, void *, s32);
void sceClose(s32);
s32 sceMcGetDir(s32, s32, s32, s32, s32, DE *);
s32 sceMcOpen(s32, s32, s32, s32);
s32 sceMcWrite(s32, void *, s32);
s32 sceMcClose(s32);
s32 sceMcSync(s32, s32 *, s32 *);

s32 func_001D58C0(void) {
    s32 step = D_004B63B8.step;
    s32 j = D_004B63B8.slot;
    s32 i = D_004B63B8.port;
    s8 buf[0x40];
    s32 r;
    s32 e;
    s32 n;
    s32 fd;
    s32 w;
    s32 k;
    switch (step) {
    case 0:
        D_004B6474[0] = 0;
        D_004B63AC[0] = 0;
        D_004B63B0[0] = 0;
        D_004B63B8.step++;
        D_004B63B8.retry = 0;
        break;
    case 1:
        D_004B63B8.x90 = func_001D3BF0(i, j, &D_004B63B8.type[i * 4 + j], &D_004B63B8.free[i * 4 + j], &D_004B63B8.format[i * 4 + j], D_004B63B8.x90);
        if (D_004B63B8.x90 > 0) break;
        e = func_001D3CE0(D_004B63B8.x90);
        D_004B63B8.err = e;
        if (e != 0) {
            D_004B63B8.x88 = 0;
            return -10;
        }
        D_004B63B8.step++;
        break;
    case 2:
        if (D_004B63B8.type[i * 4 + j] != 2) {
            D_004B63B8.x88 = 0;
            D_004B63B8.err = 0x3D;
            return -4;
        }
        D_004B63B8.step++;
        break;
    case 3:
        if (sceMcGetDir(i, j, D_004B63B8.name, 0, 1, D_004B68C0) != 0) {
            if (D_004B63B8.retry == 2) {
                D_004B63B8.x88 = 0;
                D_004B63B8.err = 100;
                return -1;
            }
            D_004B63B8.retry++;
            break;
        }
        D_004B63B8.step++;
        break;
    case 4:
        if (sceMcSync(1, 0, &r) == 0) break;
        if (r < 0) {
            if (D_004B63B8.retry == 2) {
                if (r == -2) {
                    D_004B63B8.err = 3;
                } else if (r == -4) {
                    D_004B68D0[0] = 0;
                    D_004B63B8.step++;
                    break;
                } else {
                    D_004B63B8.err = 100;
                }
                return r;
            }
            D_004B63B8.retry++;
            D_004B63B8.step--;
            break;
        }
        if (r == 0) D_004B68D0[0] = 0;
        D_004B63B8.step++;
        break;
    case 5:
        n = (D_004B68C0[0].x10 + 0x3FF) / 1024 + D_004B63B8.free[i * 4 + j];
        if (D_004B68C0[0].x10 == 0 && n < 3) {
            D_004B63B8.x88 = 0;
            D_004B63B8.err = 0x1F;
            return -6;
        }
        strcpy(buf, D_004B63B8.xa4);
        fd = func_0010FAD0(buf, 1);
        D_004B63A4[0] = fd;
        if (fd < 0) {
            D_004B63B8.x88 = 0;
            D_004B63B8.err = 0x3D;
            return fd;
        }
        if (D_004B63B8.xac != 0) {
            D_004B63AC[0] = D_004B63B8.xac;
        } else {
            D_004B63AC[0] = sceLseek(fd, 0, 2);
            sceLseek(D_004B63A4[0], 0, 0);
        }
        k = D_004B68C0[0].x10 != 0 ? 0 : 2;
        if (n - k < (D_004B63AC[0] + 0x3FF) / 1024) {
            D_004B63B8.err = 0x3D;
            D_004B63B8.x88 = 0;
            return -0x65;
        }
        D_004B63B8.step = 8;
        D_004B63B8.retry = 0;
        break;
    case 8:
        if (sceMcOpen(i, j, D_004B63B8.name, D_004B68D0[0] == 0 ? 0x203 : 3) != 0) {
            if (D_004B63B8.retry == 2) {
                D_004B63B8.x88 = 0;
                D_004B63B8.err = 0x3D;
                return -0xB;
            }
            D_004B63B8.retry++;
            break;
        }
        D_004B63B8.step++;
        break;
    case 9:
        if (sceMcSync(1, 0, &r) == 0) break;
        if (r < 0) {
            if (D_004B63B8.retry == 2) {
                func_001D3DA8(r);
                if (D_004B63B8.err == 100) D_004B63B8.err = 0x3D;
                D_004B63B8.step = 100;
                D_004B63B8.x90 = -1;
                break;
            }
            D_004B63B8.retry++;
            D_004B63B8.step--;
            break;
        }
        D_004B6474[0] = r;
        D_004B63B8.step++;
        break;
    case 10:
        if ((D_004B63A8[0] = sceRead(D_004B63A4[0], D_004B6478, 0x400)) <= 0) {
            D_004B63B8.step = 13;
            break;
        }
        D_004B63B8.retry = 0;
        D_004B63B8.step++;
        break;
    case 11:
        w = sceMcWrite(D_004B6474[0], D_004B6478, D_004B63A8[0]);
        if (w != 0) {
            if (D_004B63B8.retry == 2) {
                D_004B63B8.x90 = -1;
                D_004B63B8.step = 100;
                break;
            }
            D_004B63B8.retry++;
            break;
        }
        D_004B63B8.step++;
        break;
    case 12:
        if (sceMcSync(1, 0, &r) == 0) break;
        if (r < 0) {
            if (D_004B63B8.retry != 2 && r != -8) {
                D_004B63B8.retry++;
                D_004B63B8.step--;
                break;
            }
            D_004B63B8.x90 = -1;
            D_004B63B8.step = 100;
            break;
        }
        D_004B63B8.retry = 0;
        D_004B63B0[0] += D_004B63A8[0];
        if (D_004B63B0[0] < D_004B63AC[0]) {
            D_004B63B8.step -= 2;
            break;
        }
        D_004B63B8.step++;
        break;
    case 13:
        sceClose(D_004B63A4[0]);
        D_004B63B8.step++;
        break;
    case 14:
        w = sceMcClose(D_004B6474[0]);
        if (w != 0) {
            if (D_004B63B8.retry == 2) {
                D_004B63B8.x90 = -1;
                D_004B63B8.step = 100;
                break;
            }
            D_004B63B8.retry++;
            break;
        }
        D_004B63B8.step++;
        break;
    case 15:
        if (sceMcSync(1, 0, &r) == 0) break;
        if (r < 0) {
            if (D_004B63B8.retry == 2) {
                D_004B63B8.x88 = 0;
                D_004B63B8.err = 0x3D;
                return r;
            }
            D_004B63B8.retry++;
            D_004B63B8.step--;
            break;
        }
        D_004B63B8.err = 0x3E;
        D_004B63B8.x88 = 0;
        return 1;
    case 100:
        if (D_004B63A4[0] != 0) sceClose(D_004B63A4[0]);
        if (D_004B6474[0] < 0) {
            D_004B63B8.err = 0x3D;
            D_004B63B8.x88 = 0;
            return -999;
        }
        D_004B63B8.retry = 0;
        break;
    case 101:
        if (sceMcClose(D_004B6474[0]) != 0) {
            if (D_004B63B8.retry == 2) {
                D_004B63B8.x88 = 0;
                D_004B63B8.err = 0x3D;
                return -999;
            }
            D_004B63B8.retry++;
            break;
        }
        D_004B63B8.step++;
        break;
    case 102:
        if (sceMcSync(1, 0, &r) == 0) break;
        D_004B63B8.err = 0x3D;
        D_004B63B8.x88 = 0;
        return -999;
    }
    return 0;
}
