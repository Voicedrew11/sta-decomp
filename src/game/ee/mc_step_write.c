#include "common.h"
#include "game/data.h"
#include "game/ee.h"
typedef struct { u8 pad[0x10]; u32 fsize; } Tbl;
extern Tbl D_004B68C0[];
extern u32 D_004B639C[];
extern s32 D_004B63A0[];
s32 Mc_StepGetInfo_3_001D3BF0(s32, s32, s32 *, s32 *, s32 *, s32);
s32 sceMcClose(s32);
s32 sceMcGetDir(s32, s32, s32, s32, s32, Tbl *);
s32 sceMcOpen(s32, s32, s32, s32);
s32 sceMcSync(s32, s32 *, s32 *);
s32 sceMcWrite(s32, s32, s32);
s32 Mc_StepWrite_4_001D5280(void) {
    s32 i = D_004B63B8.port;
    s32 j = D_004B63B8.slot;
    s32 r;
    s32 n;
    s32 k;
    switch (D_004B63B8.step) {
    case 0:
        D_004B6474[0] = 0;
        D_004B639C[0] = 0;
        D_004B63B8.step++;
        break;
    case 1:
        { s32 e; s32 e2;
        e = Mc_StepGetInfo_3_001D3BF0(i, j, &D_004B63B8.type[i * 4 + j], &D_004B63B8.free[i * 4 + j], &D_004B63B8.format[i * 4 + j], D_004B63B8.x90);
        D_004B63B8.x90 = e;
        if (e > 0) break;
        e2 = Mc_GetInfoStatus_2_001D3CE0(e);
        D_004B63B8.err = e2;
        if (e2 != 0) {
            if (e2 == 100) D_004B63B8.err = 0x3D;
            D_004B63B8.cmd = 0;
            return -10;
        }
        D_004B63B8.step++;
        break; }
    case 2:
        if (D_004B63B8.type[i * 4 + j] != 2) {
            D_004B63B8.cmd = 0;
            D_004B63B8.err = 0x3D;
            return -4;
        }
        D_004B63B8.retry = 0;
        D_004B63B8.step++;
        break;
    case 3:
        if (sceMcGetDir(i, j, D_004B63B8.name, 0, 1, D_004B68C0) != 0) {
            if (D_004B63B8.retry == 2) {
                D_004B63B8.cmd = 0;
                D_004B63B8.err = 100;
                return -1;
            }
            D_004B63B8.retry++;
        } else {
            D_004B63B8.step++;
        }
        break;
    case 4:
        if (sceMcSync(1, 0, &r) == 0) break;
        if (r < 0) {
            if (D_004B63B8.retry == 2) {
                if (r == -2) D_004B63B8.err = 3;
                else if (r == -4) { D_004B68D0[0] = 0; D_004B63B8.step++; break; }
                else D_004B63B8.err = 100;
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
        n = ((D_004B68C0[0].fsize + 0x3FF) >> 10) + D_004B63B8.free[i * 4 + j];
        if (D_004B68C0[0].fsize == 0 && n < 3) {
            D_004B63B8.cmd = 0;
            D_004B63B8.err = 0x1F;
            return -6;
        }
        k = 2;
        if (D_004B68C0[0].fsize != 0) k = 0;
        if ((u32)(n - k) < (D_004B63B8.size + 0x3FF) >> 10) {
            D_004B63B8.cmd = 0;
            D_004B63B8.err = 0x3D;
            return -0x65;
        }
        D_004B63B8.retry = 0;
        D_004B63B8.step = 8;
        break;
    case 8:
        if (sceMcOpen(i, j, D_004B63B8.name, D_004B68D0[0] == 0 ? 0x203 : 3) != 0) {
            if (D_004B63B8.retry == 2) {
                D_004B63B8.cmd = 0;
                D_004B63B8.err = 0x3D;
                return -11;
            }
            D_004B63B8.retry++;
        } else {
            D_004B63B8.step++;
        }
        break;
    case 9:
        if (sceMcSync(1, 0, &r) == 0) break;
        if (r < 0) {
            if (D_004B63B8.retry == 2) {
                Mc_SetErrorStatus_4_001D3DA8(r);
                if (D_004B63B8.err == 100) D_004B63B8.err = 0x3D;
                D_004B63B8.step = 100;
                D_004B63B8.x90 = -1;
            } else {
                D_004B63B8.retry++;
                D_004B63B8.step--;
            }
            break;
        }
        D_004B6474[0] = r;
        D_004B63B8.step++;
        break;
    case 10:
        D_004B63A0[0] = D_004B63B8.size - D_004B639C[0];
        if (D_004B63A0[0] > 0x400) D_004B63A0[0] = 0x400;
        D_004B63B8.retry = 0;
        D_004B63B8.step++;
        break;
    case 11:
        if (sceMcWrite(D_004B6474[0], D_004B63B8.xB8 + D_004B639C[0], D_004B63A0[0]) != 0) {
            if (D_004B63B8.retry == 2) {
                D_004B63B8.x90 = -1;
                D_004B63B8.step = 100;
            } else {
                D_004B63B8.retry++;
            }
        } else {
            D_004B63B8.step++;
        }
        break;
    case 12:
        if (sceMcSync(1, 0, &r) == 0) break;
        if (r < 0) {
            if (D_004B63B8.retry == 2 || r == -8) {
                D_004B63B8.x90 = -1;
                D_004B63B8.step = 100;
            } else {
                D_004B63B8.retry++;
                D_004B63B8.step--;
            }
            break;
        }
        D_004B63B8.retry = 0;
        D_004B639C[0] += r;
        if (D_004B639C[0] >= D_004B63B8.size) D_004B63B8.step++;
        else D_004B63B8.step = 10;
        break;
    case 13:
        if (sceMcClose(D_004B6474[0]) != 0) {
            if (D_004B63B8.retry == 2) {
                D_004B63B8.x90 = -1;
                D_004B63B8.step = 100;
            } else {
                D_004B63B8.retry++;
            }
        } else {
            D_004B63B8.step++;
        }
        break;
    case 14:
        if (sceMcSync(1, 0, &r) == 0) break;
        D_004B63B8.cmd = 0;
        if (r < 0) {
            if (D_004B63B8.retry == 2) {
                D_004B63B8.err = 0x3D;
                return r;
            }
            D_004B63B8.retry++;
            D_004B63B8.step--;
            break;
        }
        D_004B63B8.err = 0x3E;
        return 1;
    case 100:
        if (D_004B6474[0] >= 0) {
            D_004B63B8.retry = 0;
            D_004B63B8.step++;
            break;
        }
        D_004B63B8.err = 0x3D;
        D_004B63B8.cmd = 0;
        return -999;
    case 101:
        if (sceMcClose(D_004B6474[0]) != 0) {
            if (D_004B63B8.retry == 2) {
                D_004B63B8.cmd = 0;
                D_004B63B8.err = 0x3D;
                return -999;
            }
            D_004B63B8.retry++;
        } else {
            D_004B63B8.step++;
        }
        break;
    case 102:
        if (sceMcSync(1, 0, &r) == 0) break;
        D_004B63B8.err = 0x3D;
        D_004B63B8.cmd = 0;
        return -999;
    }
    return 0;
}
