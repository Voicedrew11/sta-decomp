/* libc.a member malign.o (STA: not in kfiv-decomp): memalign, under the
 * per-thread malloc lock like this libc's malloc and free */
#include <reent.h>
#include <libc_internal.h>

void __malloc_lock(Reent *ptr);
void __malloc_unlock(Reent *ptr);
void *_memalign_r(Reent *ptr, unsigned int align, unsigned int nbytes);

void *memalign(unsigned int align, unsigned int nbytes)
{
    void *p;

    __malloc_lock(_impure_ptr);
    p = _memalign_r(_impure_ptr, align, nbytes);
    __malloc_unlock(_impure_ptr);
    return p;
}
