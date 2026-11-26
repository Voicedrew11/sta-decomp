/* libdev.a: sceDevVif0GetStat (STA: SDK 2.5 member, not in kfiv-decomp; the name is the
   SDK's libdev function the code fits, derived) */
#include <libdev_internal.h>

/* 0 idle, 1 stopped, 2 waiting, 3 transferring to VU0, 4 decoding */
int sceDevVif0GetStat(void)
{
    unsigned int v = LIBDEV_REG32(VIF0_STAT);

    if (!(v & 3)) {
        return 0;
    }
    if (v & 0x700) {
        return 1;
    }
    if (v & 0xC) {
        return 2;
    }
    return (v & 0x3000) ? 3 : 4;
}
