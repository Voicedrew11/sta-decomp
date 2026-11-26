/* libc.a member vsnprintf.o (SAB: not in kfiv-decomp; newlib's vsnprintf
 * and _vsnprintf_r, a string FILE handed to vfprintf) */
#include <stdio.h>
#include <reent.h>
#include <libc_internal.h>

#define __SWR 0x0008
#define __SSTR 0x0200

int vsnprintf(char *str, unsigned int size, const char *fmt, char *ap)
{
    int ret;
    Fil f;

    f.flags = __SWR | __SSTR;
    f.bf.base = f.p = (unsigned char *)str;
    f.bf.size = f.w = (size > 0 ? size - 1 : 0);
    f.data = _impure_ptr;
    ret = vfprintf(&f, fmt, ap);
    if (size > 0)
        *f.p = 0;
    return ret;
}

int _vsnprintf_r(Reent *ptr, char *str, unsigned int size, const char *fmt, char *ap)
{
    int ret;
    Fil f;

    f.flags = __SWR | __SSTR;
    f.bf.base = f.p = (unsigned char *)str;
    f.bf.size = f.w = (size > 0 ? size - 1 : 0);
    f.data = ptr;
    ret = vfprintf(&f, fmt, ap);
    if (size > 0)
        *f.p = 0;
    return ret;
}
