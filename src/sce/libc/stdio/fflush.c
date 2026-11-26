/* libc.a member fflush.o */
#include <reent.h>
#include <libc_internal.h>
#include <stdio.h>

#define __SLBF 0x0001
#define __SNBF 0x0002
#define __SWR 0x0008
#define __SERR 0x0040
#define EOF (-1)

int fflush(Fil *fp)
{
    register unsigned char *p;
    register int n, t;

    if (fp == 0) {
        return _fwalk(_impure_ptr, fflush);
    }
    /* newlib's CHECK_INIT(fp), a do-while-zero macro wrapper */
    do {
        if (fp->data == 0)
            fp->data = _impure_ptr;
        if (fp->data->sdidinit == 0)
            __sinit(fp->data);
    } while (0);
    /* SAB: this newlib's version: one test, a while loop */
    t = fp->flags;
    if ((t & __SWR) == 0 || (p = fp->bf.base) == 0)
        return 0;
    n = fp->p - p; /* write this much */
    fp->p = p;
    fp->w = t & (__SLBF | __SNBF) ? 0 : fp->bf.size;
    while (n > 0) {
        t = (*fp->write)(fp->cookie, (char *)p, n);
        if (t <= 0) {
            fp->flags |= __SERR;
            return EOF;
        }
        p += t;
        n -= t;
    }
    return 0;
}
