/* libdev.a: sceDevVif0PutErr (STA: SDK 2.5 member, not in kfiv-decomp; the name is the
   SDK's libdev function the code fits, derived) */
#include <libdev_internal.h>

unsigned int sceDevVif0PutErr(unsigned int me0, unsigned int me1, unsigned int mii)
{
    unsigned int v = me0 | me1 << 1 | mii << 2;

    LIBDEV_REG32(VIF0_ERR) = v;
    return v;
}
