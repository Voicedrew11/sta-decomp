/* libc.a member mlock.o.  SAB: this game's libc locks malloc per thread
 * (kfiv-decomp's newlib stub does nothing): a recursive lock on the
 * semaphore libkernl's _InitSys creates (initsys.c's __malloc_sema). */
#include <reent.h>

int GetThreadId(void);
int WaitSema(int sema);
int SignalSema(int sema);
extern int __malloc_sema;

static int lock_owner = -1; /* derived name */
static int lock_count = 0;  /* derived name */

void __malloc_lock(Reent *ptr)
{
    int id = GetThreadId();

    if (lock_owner == id) {
        lock_count++;
        return;
    }
    WaitSema(__malloc_sema);
    lock_owner = id;
    lock_count++;
}

void __malloc_unlock(Reent *ptr)
{
    if (--lock_count == 0) {
        lock_owner = -1;
        SignalSema(__malloc_sema);
    }
}
