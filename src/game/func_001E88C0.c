#include "common.h"
typedef struct { u8 trycount; u8 spindlctrl; u8 datapattern; u8 pad; } RMode;
s32 printf(const char *, ...);
s32 sprintf(char *, const char *, ...);
char *index(const char *, s32);
s32 strcmp(const char *, const char *);
s32 strlen(const char *);
char *strcpy(char *, const char *);
s32 toupper(s32);
void strncpy(char *, const char *, s32);
s32 sceOpen(char *, s32);
s32 sceSifFreeSysMemory(s32);
s32 sceCdSearchFile(void *, char *);
s32 sceCdDiskReady(s32);
s32 sceCdStInit(u32, u32, u32);
s32 sceCdStStart(u32, RMode *);
s32 sceCdStStop(void);
s32 sceClose(s32);
s32 sceLseek(s32, s32, s32);
s32 sceSifAllocIopHeap(s32);
extern char D_00201920[];
extern char D_00201940[];
extern char D_00201950[];
extern char D_00201958[];
extern char D_00201960[];
extern char D_00201968[];
extern char D_00201970[];
extern char D_00201978[];
#pragma explicit_zero_data on
const char D_00201980[0x20] = "SifAllocIopHeap Error\012\000\000\000\000\000\000\000\000\000\000";
const char D_002019A0[0x20] = "sceCdStInit Error \012\000\000\000\000\000\000\000\000\000\000\000\000\000";
const char D_002019C0[0x30] = "Cannot open '%s'(sceCdSearchFile)\012\000\000\000\000\000\000\000\000\000\000\000\000\000\000";
const char D_002019F0[0x20] = "Cannot open '%s'(sceOpen)\012\000\000\000\000\000\000";
const char D_00201A10[0x20] = "sceLseek() fails (%s): %d\012\000\000\000\000\000\000";
const char D_00201A30[0x17] = "sceLseek() fails (%s)\012\000";

s32 func_001E88C0(s32 *a0, char *name) {
    RMode mode;
    char path[0x10C];
    char dev[0x40];
    char *colon;
    s32 len;
    s32 i;
    s32 n;

    colon = index(name, ':');
    len = colon - name;
    if (colon != NULL) {
        strncpy(dev, name, len);
        dev[len] = 0;
        if (strcmp(dev, D_00201950) == 0) {
            n = strlen(colon + 1);
            a0[0] = 1;
            for (i = 0; i < n; i++) {
                char *p = colon + i + 1;
                if (*p == '/') *p = 0x5C;
                *p = toupper(*p);
            }
            sprintf(path, D_00201968, colon + 1, index(name, ';') ? D_00201958 : D_00201960);
        } else {
            a0[0] = 0;
            sprintf(path, D_00201970, dev, colon + 1);
        }
    } else {
        strcpy(dev, D_00201978);
        a0[0] = 0;
        sprintf(path, D_00201970, dev, name);
    }
    if (a0[0] != 0) {
        sceCdDiskReady(0);
        a0[11] = sceSifAllocIopHeap(0x28010);
        if (a0[11] == 0) {
            printf(D_00201980);
            return 0;
        }
        if (sceCdStInit(0x50, 5, (a0[11] + 0xF) & ~0xF) != 1) {
            printf(D_002019A0);
            if (sceSifFreeSysMemory(a0[11]) < 0) {
                printf(D_00201920, D_00201940, 0xF1A);
            }
            return 0;
        }
        if (sceCdSearchFile(&a0[2], path) == 0) {
            printf(D_002019C0, path);
            while (!sceCdStStop() != 0) {
            }
            if (sceSifFreeSysMemory(a0[11]) < 0) {
                printf(D_00201920, D_00201940, 0xF22);
            }
            return 0;
        }
        a0[1] = a0[3];
        mode.trycount = 0;
        mode.spindlctrl = 0;
        mode.datapattern = 0;
        while (!sceCdStStart(a0[2], &mode) != 0) {
        }
    } else {
        a0[12] = sceOpen(path, 1);
        if (a0[12] < 0) {
            printf(D_002019F0, path);
            return 0;
        }
        a0[1] = sceLseek(a0[12], 0, 2);
        if (a0[1] < 0) {
            printf(D_00201A10, path, a0[1]);
            sceClose(a0[12]);
            return 0;
        }
        if (sceLseek(a0[12], 0, 0) < 0) {
            printf(D_00201A30, path);
            sceClose(a0[12]);
            return 0;
        }
    }
    return 1;
}

