/* libgraph.a member graph003.o */
#include <eekernel.h>
#include <stdio.h>
#include <stdlib.h>
#include <sifdev.h>
#include <libgraph.h>

typedef long long s_long128;

/* STA: SDK 2.5's sceGsSetDefDispEnv adds the display offsets the kernel
 * keeps for the modes other than NTSC and PAL (syscall 0x80), on boot ROMs
 * dated after 2001-06-08 (rom0:ROMVER). */
static int _sceGsNewRom(void) /* derived name */
{
    char buf[256];
    char *p;
    unsigned int i;
    int fd;

    fd = sceOpen("rom0:ROMVER", 1);
    if (fd < 0) {
        return -1;
    }
    i = 0;
    p = buf;
    for (; i < 0x100; i++) {
        sceRead(fd, p, 1);
        if (*p++ == 0) {
            break;
        }
    }
    sceClose(fd);
    return atoi(&buf[i - 9]) > 20010608;
}

int _GetGsDxDyOffset(int mode, int *dx, int *dy, int *dw, int *dh); /* derived name */

/* the kernel call, a syscall stub in the member */
__asm__(".section .text\n"
        "    .set noat\n"
        "    .set noreorder\n"
        "    .align 3\n"
        "    .type _GetGsDxDyOffset, @function\n"
        "_GetGsDxDyOffset:\n"
        "    addiu $3, $0, 0x80\n"
        "    syscall\n"
        "    jr $31\n"
        "    nop\n"
        "    .size _GetGsDxDyOffset, . - _GetGsDxDyOffset\n"
        "    .set reorder\n"
        "    .set at\n");

/* the message sceGsSetDefDispEnv prints for an unknown mode (named for the
   inline asm below) */
static const char defDispEnvMsg[] = "sceGsDefDispEnv:Not support displaymode for 0x%x!!\n";

/* TODO(STA): TEMPORARY inline asm, to be removed: sceGsSetDefDispEnv is retail's
 * instructions until the C below matches.  The C is kept (under #if 0) for
 * the next attempt; delete the asm and the #if 0 once it compiles to the
 * same bytes.  tools/asm2inline.py generated the block. */
#if 0
void sceGsSetDefDispEnv(sceGsDispEnv *disp, short psm, short w, short h, short dx, short dy)
{
    sceGsGParam *gp = sceGsGetGParam();
    int off[4];

    if ((unsigned short)(gp->omode - 2) >= 2 && _sceGsNewRom()) {
        _GetGsDxDyOffset(gp->omode, &off[0], &off[1], &off[2], &off[3]);
    } else {
        off[3] = 0;
        off[2] = 0;
        off[1] = 0;
        off[0] = 0;
    }
    disp->pmode = 0x66;
    if (gp->inter != 0) {
        if (gp->ffmd != 0) {
            disp->smode2 = 3;
        } else {
            disp->smode2 = 1;
        }
    } else {
        disp->smode2 = 2;
    }
    disp->dispfb = ((s_long128)(psm & 0xF) << 15) | ((s_long128)(((w + 0x3F) >> 6) & 0x3F) << 9);

    if (gp->omode == 2) {
        if (gp->inter == 1) {
            int q = (w + 0x9FF) / w;
            s_long128 ddy = (s_long128)((dy + off[1] + 0x32) & 0xFFF) << 12;
            s_long128 x0 = (s_long128)off[0] + 0x27C;
            s_long128 magh = (s_long128)(q - 1) << 23;
            s_long128 ddx = ((s_long128)(dx * q) + x0) & 0xFFF;
            s_long128 dw = (s_long128)(q * w - 1) << 32;
            s_long128 display;

            if (gp->ffmd) {
                display = magh | dw | (ddx | (s_long128)(h * 2 - 1) << 44) | ddy;
            } else {
                display = magh | dw | (ddx | (s_long128)(h - 1) << 44) | ddy;
            }
            disp->display = display;
        } else {
            int q = (w + 0x9FF) / w;
            s_long128 ddy = (s_long128)((dy + off[1] + 0x19) & 0xFFF) << 12;
            s_long128 x0 = (s_long128)off[0] + 0x27C;
            s_long128 magh = (s_long128)(q - 1) << 23;
            s_long128 ddx = ((s_long128)(dx * q) + x0) & 0xFFF;
            s_long128 dw = (s_long128)(q * w - 1) << 32;

            disp->display = magh | dw | (ddx | (s_long128)(h - 1) << 44) | ddy;
        }
    } else if (gp->omode == 3) {
        if (gp->inter == 1) {
            int q = (w + 0x9FF) / w;
            s_long128 ddy = (s_long128)((dy + off[1] + 0x48) & 0xFFF) << 12;
            s_long128 x0 = (s_long128)off[0] + 0x290;
            s_long128 magh = (s_long128)(q - 1) << 23;
            s_long128 ddx = ((s_long128)(dx * q) + x0) & 0xFFF;
            s_long128 dw = (s_long128)(q * w - 1) << 32;
            s_long128 display;

            if (gp->ffmd) {
                display = magh | dw | (ddx | (s_long128)(h * 2 - 1) << 44) | ddy;
            } else {
                display = magh | dw | (ddx | (s_long128)(h - 1) << 44) | ddy;
            }
            disp->display = display;
        } else {
            int q = (w + 0x9FF) / w;
            s_long128 ddy = (s_long128)((dy + off[1] + 0x24) & 0xFFF) << 12;
            s_long128 x0 = (s_long128)off[0] + 0x290;
            s_long128 magh = (s_long128)(q - 1) << 23;
            s_long128 ddx = ((s_long128)(dx * q) + x0) & 0xFFF;
            s_long128 dw = (s_long128)(q * w - 1) << 32;

            disp->display = magh | dw | (ddx | (s_long128)(h - 1) << 44) | ddy;
        }
    } else if (gp->omode == 0x50) {
        /* STA: SDK 2.5's 480p mode, twice the horizontal clock */
        disp->display = (s_long128)(h - 1) << 44 | (s_long128)(w * 2 - 1) << 32 |
                        ((((s_long128)((0x2D0 - w) / 2 * 2) + off[0] + ((s_long128)(dx * 2) + 0xE8)) &
                          0xFFF) |
                         0x800000) |
                        (s_long128)((dy + off[1] + 0x23) & 0xFFF) << 12;
    } else {
        scePrintf("sceGsDefDispEnv:Not support displaymode for 0x%x!!\n", gp->omode);
    }
    disp->bgcolor = 0;
}
#endif
__asm__(".section .text\n"
        "    .set noat\n"
        "    .set noreorder\n"
        "    .align 3\n"
        "    .globl sceGsSetDefDispEnv\n"
        "    .type sceGsSetDefDispEnv, @function\n"
        "sceGsSetDefDispEnv:\n"
        "    addiu      $29, $29, -0x90\n"
        "    sll        $5, $5, 16\n"
        "    sd         $22, 0x70($29)\n"
        "    sll        $6, $6, 16\n"
        "    sd         $21, 0x60($29)\n"
        "    sll        $7, $7, 16\n"
        "    sd         $20, 0x50($29)\n"
        "    sll        $8, $8, 16\n"
        "    sd         $19, 0x40($29)\n"
        "    sll        $9, $9, 16\n"
        "    sd         $18, 0x30($29)\n"
        "    sra        $22, $5, 16\n"
        "    sd         $16, 0x10($29)\n"
        "    sra        $18, $7, 16\n"
        "    sd         $17, 0x20($29)\n"
        "    sra        $16, $6, 16\n"
        "    sd         $31, 0x80($29)\n"
        "    sra        $21, $8, 16\n"
        "    sra        $20, $9, 16\n"
        "    jal        sceGsGetGParam\n"
        "    daddu     $19, $4, $0\n"
        "    daddu      $17, $2, $0\n"
        "    lhu        $4, 0x2($17)\n"
        "    addiu      $2, $4, -0x2\n"
        "    sltiu      $2, $2, 0x2\n"
        "    bnel       $2, $0, .L00100558\n"
        "    sw        $0, 0xC($29)\n"
        "    jal        _sceGsNewRom\n"
        "    nop\n"
        "    beqz       $2, .L00100550\n"
        "    daddu     $5, $29, $0\n"
        "    lh         $4, 0x2($17)\n"
        "    ori        $6, $29, 0x4\n"
        "    ori        $7, $29, 0x8\n"
        "    jal        _GetGsDxDyOffset\n"
        "    ori       $8, $29, 0xC\n"
        "    b          .L00100564\n"
        "    lhu       $4, 0x2($17)\n"
        ".L00100550:\n"
        "    lhu        $4, 0x2($17)\n"
        "    sw         $0, 0xC($29)\n"
        ".L00100558:\n"
        "    sw         $0, 0x8($29)\n"
        "    sw         $0, 0x4($29)\n"
        "    sw         $0, 0x0($29)\n"
        ".L00100564:\n"
        "    addiu      $3, $0, 0x66\n"
        "    lhu        $6, 0x0($17)\n"
        "    sd         $3, 0x0($19)\n"
        "    lh         $2, 0x0($17)\n"
        "    beqz       $2, .L0010058C\n"
        "    addiu     $2, $0, 0x2\n"
        "    lh         $2, 0x4($17)\n"
        "    bnez       $2, .L0010058C\n"
        "    addiu     $2, $0, 0x3\n"
        "    addiu      $2, $0, 0x1\n"
        ".L0010058C:\n"
        "    sd         $2, 0x8($19)\n"
        "    addiu      $2, $16, 0x3F\n"
        "    andi       $3, $22, 0xF\n"
        "    sra        $2, $2, 6\n"
        "    sll        $4, $4, 16\n"
        "    andi       $2, $2, 0x3F\n"
        "    dsll       $3, $3, 15\n"
        "    dsll       $2, $2, 9\n"
        "    sra        $5, $4, 16\n"
        "    or         $3, $3, $2\n"
        "    addiu      $4, $0, 0x2\n"
        "    bne        $5, $4, .L00100668\n"
        "    sd        $3, 0x10($19)\n"
        "    sll        $2, $6, 16\n"
        "    addiu      $3, $0, 0x1\n"
        "    sra        $2, $2, 16\n"
        "    bne        $2, $3, .L0010063C\n"
        "    addiu     $2, $16, 0x9FF\n"
        "    addiu      $3, $16, 0x9FF\n"
        "    beql       $16, $0, .L001005E0\n"
        "    break     0, 7\n"
        ".L001005E0:\n"
        "    div        $0, $3, $16\n"
        "    lw         $2, 0x4($29)\n"
        "    lw         $5, 0x0($29)\n"
        "    addu       $2, $20, $2\n"
        "    lh         $6, 0x4($17)\n"
        "    addiu      $2, $2, 0x32\n"
        "    daddiu     $5, $5, 0x27C\n"
        "    andi       $2, $2, 0xFFF\n"
        "    dsll       $7, $2, 12\n"
        "    mflo       $3\n"
        "    mult       $4, $3, $16\n"
        "    mult1      $2, $21, $3\n"
        "    addiu      $3, $3, -0x1\n"
        "    dsll       $10, $3, 23\n"
        "    addiu      $4, $4, -0x1\n"
        "    dsll32     $3, $4, 0\n"
        "    daddu      $5, $2, $5\n"
        "    beqz       $6, .L001006F0\n"
        "    andi      $5, $5, 0xFFF\n"
        "    sll        $2, $18, 1\n"
        "    or         $3, $10, $3\n"
        "    b          .L001006F8\n"
        "    addiu     $2, $2, -0x1\n"
        ".L0010063C:\n"
        "    beql       $16, $0, .L00100644\n"
        "    break     0, 7\n"
        ".L00100644:\n"
        "    div        $0, $2, $16\n"
        "    addiu      $7, $18, -0x1\n"
        "    lw         $5, 0x0($29)\n"
        "    dsll32     $7, $7, 12\n"
        "    lw         $3, 0x4($29)\n"
        "    daddiu     $5, $5, 0x27C\n"
        "    addu       $3, $20, $3\n"
        "    b          .L00100738\n"
        "    addiu     $3, $3, 0x19\n"
        ".L00100668:\n"
        "    addiu      $2, $0, 0x3\n"
        "    bne        $5, $2, .L0010077C\n"
        "    addiu     $2, $0, 0x50\n"
        "    sll        $2, $6, 16\n"
        "    addiu      $3, $0, 0x1\n"
        "    sra        $2, $2, 16\n"
        "    bne        $2, $3, .L00100710\n"
        "    addiu     $2, $16, 0x9FF\n"
        "    addiu      $3, $16, 0x9FF\n"
        "    beql       $16, $0, .L00100694\n"
        "    break     0, 7\n"
        ".L00100694:\n"
        "    div        $0, $3, $16\n"
        "    lw         $2, 0x4($29)\n"
        "    lw         $5, 0x0($29)\n"
        "    addu       $2, $20, $2\n"
        "    lh         $6, 0x4($17)\n"
        "    addiu      $2, $2, 0x48\n"
        "    daddiu     $5, $5, 0x290\n"
        "    andi       $2, $2, 0xFFF\n"
        "    dsll       $7, $2, 12\n"
        "    mflo       $3\n"
        "    mult       $4, $3, $16\n"
        "    mult1      $2, $21, $3\n"
        "    addiu      $3, $3, -0x1\n"
        "    dsll       $10, $3, 23\n"
        "    addiu      $4, $4, -0x1\n"
        "    dsll32     $3, $4, 0\n"
        "    daddu      $5, $2, $5\n"
        "    beqz       $6, .L001006F0\n"
        "    andi      $5, $5, 0xFFF\n"
        "    sll        $2, $18, 1\n"
        "    or         $3, $10, $3\n"
        "    b          .L001006F8\n"
        "    addiu     $2, $2, -0x1\n"
        ".L001006F0:\n"
        "    addiu      $2, $18, -0x1\n"
        "    or         $3, $10, $3\n"
        ".L001006F8:\n"
        "    dsll32     $2, $2, 12\n"
        "    or         $2, $5, $2\n"
        "    or         $3, $3, $2\n"
        "    or         $2, $3, $7\n"
        "    b          .L00100800\n"
        "    sd        $2, 0x18($19)\n"
        ".L00100710:\n"
        "    beql       $16, $0, .L00100718\n"
        "    break     0, 7\n"
        ".L00100718:\n"
        "    div        $0, $2, $16\n"
        "    addiu      $7, $18, -0x1\n"
        "    lw         $5, 0x0($29)\n"
        "    dsll32     $7, $7, 12\n"
        "    lw         $3, 0x4($29)\n"
        "    daddiu     $5, $5, 0x290\n"
        "    addu       $3, $20, $3\n"
        "    addiu      $3, $3, 0x24\n"
        ".L00100738:\n"
        "    andi       $3, $3, 0xFFF\n"
        "    dsll       $3, $3, 12\n"
        "    mflo       $2\n"
        "    mult       $6, $21, $2\n"
        "    mult1      $4, $2, $16\n"
        "    addiu      $2, $2, -0x1\n"
        "    daddu      $5, $6, $5\n"
        "    dsll       $2, $2, 23\n"
        "    andi       $5, $5, 0xFFF\n"
        "    addiu      $4, $4, -0x1\n"
        "    or         $5, $5, $7\n"
        "    dsll32     $4, $4, 0\n"
        "    or         $2, $2, $4\n"
        "    or         $2, $2, $5\n"
        "    or         $2, $2, $3\n"
        "    b          .L00100800\n"
        "    sd        $2, 0x18($19)\n"
        ".L0010077C:\n"
        "    bne        $5, $2, .L001007F8\n"
        "    lui       $4, %hi(defDispEnvMsg)\n"
        "    addiu      $2, $0, 0x2D0\n"
        "    lw         $5, 0x0($29)\n"
        "    subu       $2, $2, $16\n"
        "    sll        $6, $21, 1\n"
        "    srl        $3, $2, 31\n"
        "    lw         $4, 0x4($29)\n"
        "    addu       $2, $2, $3\n"
        "    daddiu     $7, $6, 0xE8\n"
        "    sra        $2, $2, 1\n"
        "    sll        $6, $16, 1\n"
        "    sll        $2, $2, 1\n"
        "    addu       $4, $20, $4\n"
        "    daddu      $5, $2, $5\n"
        "    addiu      $3, $18, -0x1\n"
        "    daddu      $5, $5, $7\n"
        "    addiu      $6, $6, -0x1\n"
        "    dsll32     $3, $3, 12\n"
        "    dsll32     $6, $6, 0\n"
        "    andi       $5, $5, 0xFFF\n"
        "    addiu      $4, $4, 0x23\n"
        "    lui        $2, (0x800000 >> 16)\n"
        "    or         $3, $3, $6\n"
        "    or         $5, $5, $2\n"
        "    andi       $4, $4, 0xFFF\n"
        "    or         $3, $3, $5\n"
        "    dsll       $4, $4, 12\n"
        "    or         $3, $3, $4\n"
        "    b          .L00100800\n"
        "    sd        $3, 0x18($19)\n"
        ".L001007F8:\n"
        "    jal        scePrintf\n"
        "    addiu     $4, $4, %lo(defDispEnvMsg)\n"
        ".L00100800:\n"
        "    sd         $0, 0x20($19)\n"
        "    ld         $31, 0x80($29)\n"
        "    ld         $22, 0x70($29)\n"
        "    ld         $21, 0x60($29)\n"
        "    ld         $20, 0x50($29)\n"
        "    ld         $19, 0x40($29)\n"
        "    ld         $18, 0x30($29)\n"
        "    ld         $17, 0x20($29)\n"
        "    ld         $16, 0x10($29)\n"
        "    jr         $31\n"
        "    addiu     $29, $29, 0x90\n"
        "    .size sceGsSetDefDispEnv, . - sceGsSetDefDispEnv\n"
        "    .set reorder\n"
        "    .set at\n");
