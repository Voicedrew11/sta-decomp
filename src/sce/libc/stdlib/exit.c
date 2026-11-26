/* libc.a member exit.o (SAB: not in kfiv-decomp; newlib's exit) */
#include <reent.h>
#include <libc_internal.h>

void _exit(int code);

void exit(int code)
{
    register struct _atexit *p;
    register int n;

    for (p = _impure_ptr->atexit; p; p = p->next)
        for (n = p->ind; --n >= 0;)
            (*p->fns[n])();
    if (_impure_ptr->cleanup)
        (*(void (*)(Reent *))_impure_ptr->cleanup)(_impure_ptr);
    _exit(code);
}
