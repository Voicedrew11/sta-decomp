/* libdev.a: sceDevVif0PutFifo (SAB: SDK 2.5 member, not in kfiv-decomp; the name is the
   SDK's libdev function the code fits, derived) */
#include <libdev_internal.h>

typedef unsigned int u128 __attribute__((mode(TI)));

/* Feeds n quadwords to VIF0's FIFO until VIF0 signals a stall; returns how
   many went. */
int sceDevVif0PutFifo(void *src, int qwc)
{
    u128 *addr = src;
    int n = qwc;
    int i = 0;

    while (n--) {
        if (LIBDEV_REG32(VIF0_STAT) & 0x10000000) {
            return i;
        }
        *(volatile u128 *)VIF0_FIFO = *addr++;
        i++;
    }
    return i;
}
