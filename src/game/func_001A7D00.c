#include "common.h"

extern char D_001FD970[];
s32 sprintf(char *buf, const char *fmt, ...);
char *strcpy(char *dst, const char *src);
s32 func_00159D10(char *name);
s32 func_0015ABD0(s32 a);
s32 func_0015A300(s32 h);
void func_0015AB80(s32 h);

void func_001A7D00(s32 n, char *name, s32 *size)
{
    char buf[0x100];
    s32 h;
    sprintf(buf, D_001FD970, n);
    if (name)
        strcpy(name, buf);
    if (size) {
        h = func_0015ABD0(func_00159D10(buf));
        *size = func_0015A300(h);
        func_0015AB80(h);
    }
}
