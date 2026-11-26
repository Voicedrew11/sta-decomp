#include "common.h"
typedef struct { u8 trycount; u8 spindlctrl; u8 datapattern; u8 pad; } RMode;
s32 printf(const char *, ...);
s32 sceCdDiskReady(s32);
s32 sceCdStRead(u32, u32 *, u32, u32 *);
s32 sceCdStSeek(u32);
s32 sceCdStStart(u32, RMode *);
s32 sceCdStStop(void);
s32 sceRead(s32, void *, s32);
extern char D_00201870[];
extern char D_00201898[];
extern char D_002018B0[];
extern char D_002018D0[];
extern char D_002018E8[];
extern char D_00201900[];

s32 func_001E8710(s32 *a0, void *buf, s32 size, u32 lsn) {
    u32 err;
    RMode mode;
    s32 r;

    if (a0[0] != 0) {
        do {
            r = sceCdStRead(size >> 11, buf, 1, &err);
            if (err != 0) {
                printf(D_00201870, r, err);
                if (err == 1) {
                    printf(D_00201898);
                    while (!sceCdStStop() != 0) {
                    }
                    mode.trycount = 0;
                    mode.spindlctrl = 0;
                    mode.datapattern = 0;
                    while (!sceCdStStart(lsn, &mode) != 0) {
                    }
                } else {
                    printf(D_002018B0);
                    sceCdDiskReady(0);
                    printf(D_002018D0, lsn);
                    while (!sceCdStSeek(lsn) != 0) {
                    }
                    printf(D_002018E8);
                }
            }
        } while (err != 0);
        r <<= 11;
    } else {
        do {
            r = sceRead(a0[12], buf, size);
            if (r < 0) {
                printf(D_00201900, r);
            }
        } while (r < 0);
    }
    return r;
}

