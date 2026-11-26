/* libdev.a: sceDevVif0Reset (SAB: SDK 2.5 member, not in kfiv-decomp; the name is the
   SDK's libdev function the code fits, derived) */
#include <libdev_internal.h>

void sceDevVif0Reset(void)
{
    LIBDEV_REG32(VIF0_FBRST) = 1;
    LIBDEV_REG32(VIF0_ERR) = 6;
}
