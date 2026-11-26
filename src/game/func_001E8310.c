#include "common.h"
s32 strcmp(const char *, const char *);
s32 strlen(const char *);
s32 strncmp(const char *, const char *, s32);
extern char D_00201760[];
extern char D_00201788[];
extern char D_00201798[];
extern char D_002017B8[];
extern char D_00201840[];
typedef struct { u8 p0[0x10]; s32 x10; u8 p14[0xC]; u8 name[0x20]; } E;
typedef struct { s32 x0[8]; s32 n; u8 p24[0x1C]; E e[14]; u8 pad[0x40]; } S;
extern S D_004BC380[];

void func_001E8310(s32 idx, s32 *pa, s32 *pb) {
    s32 n;
    s32 i;
    s32 a;
    s32 b;
    s32 len;
    s32 z;
    s32 c;
    i = 2;
    a = 0;
    n = D_004BC380[idx].n;
    b = 0;
    for (; i < n; i++) {
        z = D_004BC380[idx].e[i].x10 == 0;
        if (strcmp((char *)D_004BC380[idx].e[i].name, D_00201760) == 0) a |= 1;
        if (strcmp((char *)D_004BC380[idx].e[i].name, D_00201840) == 0) { if (z) b |= 2; else a |= 2; }
        if (strcmp((char *)D_004BC380[idx].e[i].name, D_00201788) == 0) { if (z) b |= 4; else a |= 4; }
        if (strcmp((char *)D_004BC380[idx].e[i].name, D_00201798) == 0) { if (z) b |= 8; else a |= 8; }
        len = strlen(D_002017B8);
        if (strncmp((char *)D_004BC380[idx].e[i].name, D_002017B8, len) == 0) {
            c = D_004BC380[idx].e[i].name[len] - '0';
            if (z) b |= 1 << (c + 4); else a |= 1 << (c + 4);
        }
    }
    if (pa != NULL) *pa = a;
    if (pb != NULL) *pb = b;
}
