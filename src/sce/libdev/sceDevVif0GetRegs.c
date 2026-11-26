/* libdev.a: sceDevVif0GetRegs (STA: SDK 2.5 member, not in kfiv-decomp; the name is the
   SDK's libdev function the code fits, derived) */
#include <libdev_internal.h>

int sceDevVif0GetStat(void);

/* Copies VIF0's row and column registers, MASK, CODE, STAT, ITOP, ITOPS,
   MARK, NUM, ERR, CYCLE and MODE into the caller's record.  Fails while VIF0
   transfers. */
int sceDevVif0GetRegs(void *cnd)
{
    char *c = cnd;
    unsigned int cycle = LIBDEV_VIF_REG32(VIF0_STAT, VIF_CYCLE);

    if ((unsigned int)sceDevVif0GetStat() >= 2) {
        return 0;
    }
    *(int *)(c + 0x00) = LIBDEV_VIF_REG32(VIF0_STAT, VIF_ROW + 0x00);
    *(int *)(c + 0x04) = LIBDEV_VIF_REG32(VIF0_STAT, VIF_ROW + 0x10);
    *(int *)(c + 0x08) = LIBDEV_VIF_REG32(VIF0_STAT, VIF_ROW + 0x20);
    *(int *)(c + 0x0C) = LIBDEV_VIF_REG32(VIF0_STAT, VIF_ROW + 0x30);
    *(int *)(c + 0x10) = LIBDEV_VIF_REG32(VIF0_STAT, VIF_COL + 0x00);
    *(int *)(c + 0x14) = LIBDEV_VIF_REG32(VIF0_STAT, VIF_COL + 0x10);
    *(int *)(c + 0x18) = LIBDEV_VIF_REG32(VIF0_STAT, VIF_COL + 0x20);
    *(int *)(c + 0x1C) = LIBDEV_VIF_REG32(VIF0_STAT, VIF_COL + 0x30);
    *(int *)(c + 0x20) = LIBDEV_VIF_REG32(VIF0_STAT, VIF_MASK);
    *(int *)(c + 0x24) = LIBDEV_VIF_REG32(VIF0_STAT, VIF_CODE);
    *(int *)(c + 0x28) = LIBDEV_REG32(VIF0_STAT);
    *(short *)(c + 0x2C) = LIBDEV_VIF_REG32(VIF0_STAT, VIF_ITOP);
    *(short *)(c + 0x2E) = LIBDEV_VIF_REG32(VIF0_STAT, VIF_ITOPS);
    *(short *)(c + 0x30) = LIBDEV_VIF_REG32(VIF0_STAT, VIF_MARK);
    *(short *)(c + 0x32) = LIBDEV_VIF_REG32(VIF0_STAT, VIF_NUM);
    *(char *)(c + 0x34) = LIBDEV_REG32(VIF0_ERR);
    *(char *)(c + 0x35) = cycle;
    *(char *)(c + 0x36) = cycle >> 8;
    *(char *)(c + 0x37) = LIBDEV_VIF_REG32(VIF0_STAT, VIF_MODE);
    return 1;
}
