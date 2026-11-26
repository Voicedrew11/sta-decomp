/* libdev.a: sceDevVif0Pause (STA: SDK 2.5 member, not in kfiv-decomp; the name is the
   SDK's libdev function the code fits, derived) */
#include <libdev_internal.h>

int sceDevVif0GetStat(void);

int sceDevVif0Pause(int mode)
{
    int s = sceDevVif0GetStat();

    if (s == 0) {
        return 0;
    }
    if (s == 1) {
        return 0;
    }
    if (mode == 0) {
        LIBDEV_REG32(VIF0_FBRST) = 2;
    } else if (mode == 1) {
        LIBDEV_REG32(VIF0_FBRST) = 4;
    }
    return 1;
}
