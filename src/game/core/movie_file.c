#include "common.h"
#include "game/core.h"
typedef CdRMode RMode;
s32 printf(const char *, ...);
s32 sceCdDiskReady(s32);
s32 sceCdStRead(u32, u32 *, u32, u32 *);
s32 sceCdStSeek(u32);
s32 sceCdStStart(u32, RMode *);
s32 sceCdStStop(void);
s32 sceRead(s32, void *, s32);
#pragma explicit_zero_data on
const char D_00201870[0x28] = "sceCdStRead Error count=%d err=%d\012\000\000\000\000\000\000";
const char D_00201898[0x18] __attribute__((aligned(8))) = "sceCdStStop\012\000\000\000\000\000\000\000\000\000\000\000\000";
const char D_002018B0[0x20] = "sceCdDiskReady...\012\000\000\000\000\000\000\000\000\000\000\000\000\000\000";
const char D_002018D0[0x17] = "sceCdStSeek... lsn=%d\012\000";
const char D_002018E8[0x18] __attribute__((aligned(8))) = "retry...\012\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000";
const char D_00201900[0x15] = "read error retry %d\012\000";

s32 MovieFile_Read_3_001E8710(s32 *a0, void *buf, s32 size, u32 lsn) {
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

