/* libdev.a: sceDevVu0PutCtx (SAB: SDK 2.5 member, not in kfiv-decomp; the name is the
   SDK's libdev function the code fits, derived) */
#include <libdev_internal.h>

int sceDevVu0IsRunning(void);

#define LQC2(vf, off, base) __asm__ __volatile__("lqc2 $" #vf ", " #off "(%0)" : : "r"(base))

/* Loads VU0's 32 float registers and its integer and control registers from
   the record sceDevVu0GetCtx fills.  Fails while VU0 runs. */
int sceDevVu0PutCtx(void *cnd)
{
    void *p = cnd;
    int v;

    if (sceDevVu0IsRunning()) {
        return 0;
    }
    LQC2(vf0, 0x0, p);
    LQC2(vf1, 0x10, p);
    LQC2(vf2, 0x20, p);
    LQC2(vf3, 0x30, p);
    LQC2(vf4, 0x40, p);
    LQC2(vf5, 0x50, p);
    LQC2(vf6, 0x60, p);
    LQC2(vf7, 0x70, p);
    LQC2(vf8, 0x80, p);
    LQC2(vf9, 0x90, p);
    LQC2(vf10, 0xA0, p);
    LQC2(vf11, 0xB0, p);
    LQC2(vf12, 0xC0, p);
    LQC2(vf13, 0xD0, p);
    LQC2(vf14, 0xE0, p);
    LQC2(vf15, 0xF0, p);
    LQC2(vf16, 0x100, p);
    LQC2(vf17, 0x110, p);
    LQC2(vf18, 0x120, p);
    LQC2(vf19, 0x130, p);
    LQC2(vf20, 0x140, p);
    LQC2(vf21, 0x150, p);
    LQC2(vf22, 0x160, p);
    LQC2(vf23, 0x170, p);
    LQC2(vf24, 0x180, p);
    LQC2(vf25, 0x190, p);
    LQC2(vf26, 0x1A0, p);
    LQC2(vf27, 0x1B0, p);
    LQC2(vf28, 0x1C0, p);
    LQC2(vf29, 0x1D0, p);
    LQC2(vf30, 0x1E0, p);
    LQC2(vf31, 0x1F0, p);
    v = *(int *)((char *)cnd + 0x200);
    LIBDEV_CTC2(v, vi16);
    v = *(int *)((char *)cnd + 0x204);
    LIBDEV_CTC2(v, vi17);
    v = *(int *)((char *)cnd + 0x208);
    LIBDEV_CTC2(v, vi18);
    v = *(int *)((char *)cnd + 0x20C);
    LIBDEV_CTC2(v, vi20);
    v = *(int *)((char *)cnd + 0x210);
    LIBDEV_CTC2(v, vi21);
    v = *(int *)((char *)cnd + 0x214);
    LIBDEV_CTC2(v, vi22);
    v = *(unsigned short *)((char *)cnd + 0x218);
    LIBDEV_CTC2(v, vi0);
    v = *(unsigned short *)((char *)cnd + 0x21A);
    LIBDEV_CTC2(v, vi1);
    v = *(unsigned short *)((char *)cnd + 0x21C);
    LIBDEV_CTC2(v, vi2);
    v = *(unsigned short *)((char *)cnd + 0x21E);
    LIBDEV_CTC2(v, vi3);
    v = *(unsigned short *)((char *)cnd + 0x220);
    LIBDEV_CTC2(v, vi4);
    v = *(unsigned short *)((char *)cnd + 0x222);
    LIBDEV_CTC2(v, vi5);
    v = *(unsigned short *)((char *)cnd + 0x224);
    LIBDEV_CTC2(v, vi6);
    v = *(unsigned short *)((char *)cnd + 0x226);
    LIBDEV_CTC2(v, vi7);
    v = *(unsigned short *)((char *)cnd + 0x228);
    LIBDEV_CTC2(v, vi8);
    v = *(unsigned short *)((char *)cnd + 0x22A);
    LIBDEV_CTC2(v, vi9);
    v = *(unsigned short *)((char *)cnd + 0x22C);
    LIBDEV_CTC2(v, vi10);
    v = *(unsigned short *)((char *)cnd + 0x22E);
    LIBDEV_CTC2(v, vi11);
    v = *(unsigned short *)((char *)cnd + 0x230);
    LIBDEV_CTC2(v, vi12);
    v = *(unsigned short *)((char *)cnd + 0x232);
    LIBDEV_CTC2(v, vi13);
    v = *(unsigned short *)((char *)cnd + 0x234);
    LIBDEV_CTC2(v, vi14);
    v = *(unsigned short *)((char *)cnd + 0x236);
    LIBDEV_CTC2(v, vi15);
    return 1;
}
