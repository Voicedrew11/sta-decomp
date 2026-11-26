/* libc.a member malloc.o (SAB: not in kfiv-decomp).  This libc's malloc and
 * free take the per-thread malloc lock (mlock.c) around the reentrant
 * calls. */
#include <reent.h>
#include <libc_internal.h>

void __malloc_lock(Reent *ptr);
void __malloc_unlock(Reent *ptr);
void *_malloc_r(Reent *ptr, unsigned int size);
void _free_r(Reent *ptr, void *p);

void *malloc(unsigned int nbytes)
{
    void *p;

    __malloc_lock(_impure_ptr);
    p = _malloc_r(_impure_ptr, nbytes);
    __malloc_unlock(_impure_ptr);
    return p;
}

void free(void *aptr)
{
    __malloc_lock(_impure_ptr);
    _free_r(_impure_ptr, aptr);
    __malloc_unlock(_impure_ptr);
}
