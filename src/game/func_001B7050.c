#include "common.h"
extern char D_001FDA80[];
extern s32 D_002022B4;
extern s32 D_002022C4;
void func_001B7050(s32 n, char *name, s32 *size);
s32** func_001B70E0(s32 n);
s32 sprintf(char *buf, const char *fmt, ...);
char* strcpy(char *dst, const char *src);
s32 func_00159D10(char *name);
s32 func_0015ABD0(s32 a);
s32 func_0015A300(s32 h);
void func_0015AB80(s32 h);
s32** func_001288C0(s32, s32);
void memset(void *, s32, s32);

/* func_001B7050 */
void func_001B7050(s32 n, char *name, s32 *size)
{
    char buf[0x100];
    s32 h;
    sprintf(buf, D_001FDA80, n);
    if (name)
        strcpy(name, buf);
    if (size) {
        h = func_0015ABD0(func_00159D10(buf));
        *size = func_0015A300(h);
        func_0015AB80(h);
    }
}

/* func_001B70E0 */
static inline void ld(s32 n, s32 *size)
{
    char buf[0x100];
    s32 h;
    sprintf(buf, D_001FDA80, n);
    if (size) {
        h = func_0015ABD0(func_00159D10(buf));
        *size = func_0015A300(h);
        func_0015AB80(h);
    }
}
s32 **func_001B70E0(s32 n) {
    s32 size;
    s32 **r;
    s32 *p;
    ld(n, &size);
    D_002022B4 = n;
    r = func_001288C0(D_002022C4, 0x1E0);
    p = *r;
    memset(p, 0, 0x1E0);
    p[9] = (s32)func_001288C0(D_002022C4, size);
    p[0] = n;
    return r;
}
