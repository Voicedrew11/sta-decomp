/* libc.a member rand.o.  STA: this newlib's 64-bit generator: the state is
 * the unsigned long long at 0xA8 of the reentrancy record (newlib's
 * _new._reent._rand_next), stepped by Knuth's MMIX multiplier. */
#include <stdlib.h>
#include <string.h>
#include <reent.h>

#define RAND_NEXT(r) (*(unsigned long long *)((char *)(r) + 0xA8))

void srand(unsigned int seed)
{
    RAND_NEXT(_impure_ptr) = seed;
}

int rand(void)
{
    Reent *r = _impure_ptr;

    RAND_NEXT(r) = RAND_NEXT(r) * 6364136223846793005LL + 1;
    return (int)((RAND_NEXT(r) >> 32) & 0x7fffffff);
}
