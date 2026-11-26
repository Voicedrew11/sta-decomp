/* libdev.a: sceDevVu0GetCtx (SAB: SDK 2.5 member, not in kfiv-decomp; the name is the
   SDK's libdev function the code fits, derived) */
#include <libdev_internal.h>

int sceDevVu0IsRunning(void);

/* not volatile: the return value is set ahead of the reads */
#define CFC2(dst, vi) __asm__("cfc2.ni %0, $" #vi : "=r"(dst))

/* Copies VU0's integer and control registers into the caller's record:
   VI16..VI18 and VI20..VI22 as words at 0x200, VI0..VI15 as halfwords at
   0x218.  Fails while VU0 runs. */
int sceDevVu0GetCtx(void *cnd)
{
    char *c = cnd;
    int v;

    if (sceDevVu0IsRunning()) {
        return 0;
    }
    CFC2(v, vi16); *(int *)(c + 0x200) = v;
    CFC2(v, vi17); *(int *)(c + 0x204) = v;
    CFC2(v, vi18); *(int *)(c + 0x208) = v;
    CFC2(v, vi20); *(int *)(c + 0x20C) = v;
    CFC2(v, vi21); *(int *)(c + 0x210) = v;
    CFC2(v, vi22); *(int *)(c + 0x214) = v;
    CFC2(v, vi0); *(short *)(c + 0x218) = v;
    CFC2(v, vi1); *(short *)(c + 0x21A) = v;
    CFC2(v, vi2); *(short *)(c + 0x21C) = v;
    CFC2(v, vi3); *(short *)(c + 0x21E) = v;
    CFC2(v, vi4); *(short *)(c + 0x220) = v;
    CFC2(v, vi5); *(short *)(c + 0x222) = v;
    CFC2(v, vi6); *(short *)(c + 0x224) = v;
    CFC2(v, vi7); *(short *)(c + 0x226) = v;
    CFC2(v, vi8); *(short *)(c + 0x228) = v;
    CFC2(v, vi9); *(short *)(c + 0x22A) = v;
    CFC2(v, vi10); *(short *)(c + 0x22C) = v;
    CFC2(v, vi11); *(short *)(c + 0x22E) = v;
    CFC2(v, vi12); *(short *)(c + 0x230) = v;
    CFC2(v, vi13); *(short *)(c + 0x232) = v;
    CFC2(v, vi14); *(short *)(c + 0x234) = v;
    CFC2(v, vi15); *(short *)(c + 0x236) = v;
    return 1;
}
