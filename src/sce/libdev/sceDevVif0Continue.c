/* libdev.a: sceDevVif0Continue (STA: SDK 2.5 member, not in kfiv-decomp; the name is the
   SDK's libdev function the code fits, derived) */
#include <libdev_internal.h>

int sceDevVif0GetStat(void);

int sceDevVif0Continue(void)
{
    if (sceDevVif0GetStat() != 1) {
        return 0;
    }
    LIBDEV_REG32(VIF0_FBRST) = 8;
    return 1;
}
