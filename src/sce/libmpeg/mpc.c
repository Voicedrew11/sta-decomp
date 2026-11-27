#define LIBMPEG25 /* STA: SDK 2.5 */
/* libmpeg.a(mpc.o): motion compensation, the macroblock and slice decoder,
 * the IPU command and bit reader layer, the picture-level header parsers and
 * the output path.  The member's .text is 16-aligned by _copyRefImage's
 * `.align 4` before _maxval.
 *
 * STA: SDK 2.5: every function past the copy kernels takes the decoder record
 * (MpegSys), which holds SDK 2.2's globals; converted from kfiv-decomp's
 * SDK 2.2 member and fixed function by function against the ROM. */
#include <libmpeg.h>
#include <libmpeg_internal.h>
#include <eeregs.h>
#include <eekernel.h>
#include <stdio.h>

/* STA: SDK 2.5 helpers defined at the end of the member */
void _sendRefTags(MpegSys *p);
void _ipuToSpr(int addr, int size);

int _motionComp0(MpegSys *p, int mba, int inc, int mb_type, int motion_type, int PMV[2][2][2],
                 int mv_field_sel[2][2], int *dmvector)
{
    int col = mba % p->widthMB;
    int row = mba / p->widthMB;
    int x = col * 16;
    int y = row * 16;
    int intra = mb_type & 1;

    if (intra) {
        while (((*(volatile unsigned int *)D9_CHCR) >> 8) & 1) {}
        p->mbcont.rec[p->mbcont.cur].busy = 0;
    } else {
        if ((unsigned int)(motion_type - 1) >= 3) {
            _Error1(p, "Invalid modion type -- ignored(%d)", motion_type);
            p->isError = 1;
            return 0;
        }
        _getAllRefs(p, x, y, mb_type, motion_type, PMV, mv_field_sel, dmvector);
        while (((*(volatile unsigned int *)D9_CHCR) >> 8) & 1) {}
        _sendRefTags(p);
        p->mbcont.rec[p->mbcont.cur].busy = 1;
    }
    if (inc == 1 && (mb_type & 2)) {
        p->mbcont.rec[p->mbcont.cur].coded = inc;
    } else {
        p->mbcont.rec[p->mbcont.cur].coded = 0;
    }
    p->mbcont.rec[p->mbcont.cur].intra = intra;
    if (p->picture_structure == 3) {
        int *f = p->curFrame;
        p->mbcont.rec[p->mbcont.cur].dst = (void *)(f[0] + (col * f[4] + row) * 0x180);
    } else {
        int *f = p->picture_structure == 2 ? p->curBot : p->curTop;
        p->mbcont.rec[p->mbcont.cur].dst = (void *)(f[0] + (col * f[4] + row) * 0x180);
    }
    return 1;
}

void _getAllRefs(MpegSys *p, int x, int y, int mbflags, int motion_type, int PMV[2][2][2],
                 int mv_field_sel[2][2], int *dmvector)
{
    int DMV[4];
    int *fields[2][2];
    int fld = 1;
    int avg = 0;

    p->mbcont.rec[p->mbcont.cur].count = 0;
    if ((mbflags & 8) || p->picture_coding_type == 2) {
        if (p->picture_structure == 3) {
            if (motion_type == 2 || (mbflags & 8) == 0) {
                _getRef0(p, p->forwFrame, 0, 0, 0, 16, x, y, PMV[0][0][0], PMV[0][0][1], 0, 0);
            } else if (motion_type == 1) {
                _getRef0(p, p->forwFrame, mv_field_sel[0][0], 0, 0, 8, x, y, PMV[0][0][0],
                         PMV[0][0][1] >> 1, fld, 0);
                _getRef0(p, p->forwFrame, mv_field_sel[1][0], 1, 0, 8, x, y, PMV[1][0][0],
                         PMV[1][0][1] >> 1, fld, 0);
            } else if (motion_type == 3) {
                _dualPrimeVector(p, DMV, dmvector, PMV[0][0][0], PMV[0][0][1] >> 1);
                _getRef0(p, p->forwFrame, 0, 0, 0, 8, x, y, PMV[0][0][0], PMV[0][0][1] >> 1, fld, 0);
                _getRef0(p, p->forwFrame, 1, 0, 0, 8, x, y, DMV[0], DMV[1], fld, 1);
                _getRef0(p, p->forwFrame, 1, 1, 0, 8, x, y, PMV[0][0][0], PMV[0][0][1] >> 1, fld, 0);
                _getRef0(p, p->forwFrame, 0, 1, 0, 8, x, y, DMV[2], DMV[3], fld, 1);
            } else {
                _Error1(p, "(a) invalid motion_type(%d)-0", motion_type);
            }
        } else {
            int bot;

            fields[0][0] = p->forwTop;
            fields[0][1] = p->forwBot;
            fields[1][0] = p->backTop;
            fields[1][1] = p->backBot;
            bot = p->picture_structure == 2;
            if (p->picture_coding_type == 2 && p->isSecondField != 0 && bot != mv_field_sel[0][0]) {
                fld = 1;
            } else {
                fld = 0;
            }
            if (motion_type == 1 || (mbflags & 8) == 0) {
                _getRef0(p, fields[fld][mv_field_sel[0][0]], 0, 0, 0, 16, x, y, PMV[0][0][0],
                         PMV[0][0][1], 0, 0);
            } else if (motion_type == 2) {
                _getRef0(p, fields[fld][mv_field_sel[0][0]], 0, 0, 0, 8, x, y, PMV[0][0][0],
                         PMV[0][0][1], 0, 0);
                fld = 0;
                if (p->picture_coding_type == motion_type && p->isSecondField != 0 &&
                    bot != mv_field_sel[1][0]) {
                    fld = 1;
                }
                _getRef0(p, fields[fld][mv_field_sel[1][0]], 0, 0, 8, 8, x, y, PMV[1][0][0],
                         PMV[1][0][1], 0, 0);
            } else if (motion_type == 3) {
                fld = 0;
                if (p->isSecondField != 0) {
                    fld = 1;
                }
                _dualPrimeVector(p, DMV, dmvector, PMV[0][0][0], PMV[0][0][1]);
                _getRef0(p, fields[0][bot], 0, 0, 0, 16, x, y, PMV[0][0][0], PMV[0][0][1], 0, 0);
                _getRef0(p, fields[fld][bot ? 0 : 1], 0, 0, 0, 16, x, y, DMV[0], DMV[1], 0, 1);
            } else {
                _Error1(p, "(b) invalid motion_type(%d)-1", motion_type);
            }
        }
        avg = 1;
    }
    if (mbflags & 4) {
        if (p->picture_structure == 3) {
            /* The backward frame's own field flag: fld may hold the field
               parity here. */
            int bfld = 1;

            if (motion_type == 2) {
                _getRef0(p, p->backFrame, 0, 0, 0, 16, x, y, PMV[0][1][0], PMV[0][1][1], 0, avg);
            } else {
                _getRef0(p, p->backFrame, mv_field_sel[0][1], 0, 0, 8, x, y, PMV[0][1][0],
                         PMV[0][1][1] >> 1, bfld, avg);
                _getRef0(p, p->backFrame, mv_field_sel[1][1], 1, 0, 8, x, y, PMV[1][1][0],
                         PMV[1][1][1] >> 1, bfld, avg);
            }
        } else if (motion_type == 1) {
            _getRef0(p, mv_field_sel[0][1] ? p->backBot : p->backTop, 0, 0, 0, 16, x, y, PMV[0][1][0],
                     PMV[0][1][1], 0, avg);
        } else if (motion_type == 2) {
            _getRef0(p, mv_field_sel[0][1] ? p->backBot : p->backTop, 0, 0, 0, 8, x, y, PMV[0][1][0],
                     PMV[0][1][1], 0, avg);
            _getRef0(p, mv_field_sel[1][1] ? p->backBot : p->backTop, 0, 0, 8, 8, x, y, PMV[1][1][0],
                     PMV[1][1][1], 0, avg);
        } else {
            _Error1(p, "(c) invalid motion_type(%d)-2", motion_type);
        }
    }
}

/* the prediction buffer the IPU reads the two reference blocks out of */
/* the eight luma (_rix_*) and the eight chroma (_ri0_*) prediction copy
 * routines, picked by the half-pel bits of the vector and by whether this
 * reference is averaged; _doMC calls them with the descriptor */
void _rix_000();
void _rix_001();
void _rix_010();
void _rix_011();
void _rix_100();
void _rix_101();
void _rix_110();
void _rix_111();
void _ri0_000();
void _ri0_001();
void _ri0_010();
void _ri0_011();
void _ri0_100();
void _ri0_101();
void _ri0_110();
void _ri0_111();

static void (*lumaCopy[8])() = {_rix_000, _rix_001, _rix_010, _rix_011,
                                _rix_100, _rix_101, _rix_110, _rix_111}; /* derived name */

static void (*chromaCopy[8])() = {_ri0_000, _ri0_001, _ri0_010, _ri0_011,
                                  _ri0_100, _ri0_101, _ri0_110, _ri0_111}; /* derived name */

/* Append one reference block to the current macroblock record: its luma and
 * chroma copy descriptors, then the two source addresses and the two copy
 * routines in the record's srcAddr, lumaFn and chromaFn arrays.
 * fld is 1 when the reference is read field-organised out of a frame buffer,
 * which doubles every vertical step and halves every vertical extent. The
 * chroma half reuses the luma half's position, fraction and half-pel
 * variables. */
void _getRef0(MpegSys *p, int *img, int lineOff, int predIdx, int yoff, int h, int x, int y, int mvx, int mvy,
              int fld, int avg)
{
    int dst = p->refBlockp;
    int lumaCmd, chromaCmd;
    int cmvx, cmvy, cpx, cpy, cyoff, ch;
    int base, idx, lrow, lrow2, cbase, crow, crow2;
    int ix, rx, ry, px, py, fy, blk, t, xh, yh;
    int n = p->mbcont.rec[p->mbcont.cur].count;
    MCRefDesc *luma = &p->mbcont.rec[p->mbcont.cur].luma[n];
    MCRefDesc *chroma = &p->mbcont.rec[p->mbcont.cur].chroma[n];

    ix = mvx >> 1;
    rx = ix + x;
    if (fld) {
        ry = (mvy >> 1) * 2 + lineOff + yoff + y;
    } else {
        ry = (mvy >> 1) + lineOff + yoff + y;
    }
    px = rx >> 4;
    py = ry >> 4;
    blk = px * img[0x10 / 4] + py;
    fy = ry - py * 16;
    xh = mvx & 1;
    yh = mvy & 1;
    luma->xoff = rx - px * 16;
    luma->dst = (void *)(dst + (predIdx + yoff) * 32);
    if (yh) {
        if (fy + (h << fld) >= 16) {
            t = (16 >> fld) - (fy >> fld) - 1;
            luma->rows0 = t;
            luma->rows1 = h - t;
        } else {
            luma->rows0 = h;
            luma->rows1 = 0;
        }
    } else {
        if (fy + (h << fld) >= 17) {
            t = (16 >> fld) - (fy >> fld);
            luma->rows0 = t;
            luma->rows1 = h - t;
        } else {
            luma->rows0 = h;
            luma->rows1 = 0;
        }
    }
    base = p->mbcont.rec[p->mbcont.cur].refBuf + n * 0x600;
    lrow = fy * 16;
    luma->src0 = (void *)(base + lrow);
    lrow2 = lrow + 0x300;
    luma->src1 = (void *)(base + lrow2);
    luma->stride = 16 << fld;
    lumaCmd = (avg << 2) | (xh << 1) | yh;

    cmvx = mvx / 2;
    cmvy = mvy / 2;
    rx = (cmvx >> 1) + (x >> 1);
    cyoff = yoff >> 1;
    ch = h >> 1;
    if (fld) {
        ry = (cmvy >> 1) * 2 + lineOff + cyoff + (y >> 1);
    } else {
        ry = (cmvy >> 1) + lineOff + cyoff + (y >> 1);
    }
    cpx = rx >> 3;
    cpy = ry >> 3;
    fy = ry - cpy * 8;
    xh = cmvx & 1;
    yh = cmvy & 1;
    chroma->xoff = rx - cpx * 8;
    chroma->dst = (void *)(dst + 0x200 + (predIdx + cyoff) * 16);
    if (yh) {
        if (fy + (ch << fld) >= 8) {
            t = (8 >> fld) - (fy >> fld) - 1;
            chroma->rows0 = t;
            chroma->rows1 = ch - t;
        } else {
            chroma->rows0 = ch;
            chroma->rows1 = 0;
        }
    } else {
        if (fy + (ch << fld) >= 9) {
            t = (8 >> fld) - (fy >> fld);
            chroma->rows0 = t;
            chroma->rows1 = ch - t;
        } else {
            chroma->rows0 = ch;
            chroma->rows1 = 0;
        }
    }
    cbase = ((cpx - px) * 2 + (cpy - py)) * 0x180 + base;
    crow = fy * 8 + 0x100;
    crow2 = fy * 8 + 0x400;
    chroma->src0 = (void *)(cbase + crow);
    chroma->src1 = (void *)(cbase + crow2);
    chroma->stride = 8 << fld;
    chromaCmd = (avg << 2) | (xh << 1) | yh;

    idx = p->mbcont.cur;
    p->mbcont.rec[idx].srcAddr[0][n] = (void *)(img[0] + blk * 0x180);
    p->mbcont.rec[idx].srcAddr[1][n] = (void *)(img[0] + (blk + img[0x10 / 4]) * 0x180);
    p->mbcont.rec[idx].lumaFn[n] = lumaCopy[lumaCmd];
    p->mbcont.rec[idx].chromaFn[n] = chromaCopy[chromaCmd];
    p->mbcont.rec[idx].count += 1;
}

/* Finish record a0: run each reference's luma and chroma copy routines into
 * the prediction buffer, then copy the intra block, the prediction (skipped
 * macroblock) or the prediction plus the residual to the destination. */
void _doMC(MpegSys *p, int idx)
{
    int i;

    if (p->mbcont.rec[idx].busy != 0) {
        for (i = 0; i < p->mbcont.rec[idx].count; i++) {
            p->mbcont.rec[idx].lumaFn[i](&p->mbcont.rec[idx].luma[i]);
            p->mbcont.rec[idx].chromaFn[i](&p->mbcont.rec[idx].chroma[i]);
        }
    }
    if (p->mbcont.rec[idx].intra != 0 && p->mbcont.rec[idx].skip != 0) {
        _Error(p, "intra && skip MB");
    }
    if (p->mbcont.rec[idx].intra != 0) {
        _copyRefImage(p->mbcont.rec[idx].dst, (void *)p->mbcont.rec[idx].ipuBuf);
    } else if (p->mbcont.rec[idx].skip != 0) {
        _copyRefImage(p->mbcont.rec[idx].dst, (void *)p->refBlockp);
    } else {
        _copyAddRefImage(p->mbcont.rec[idx].dst, (void *)p->refBlockp, (void *)p->mbcont.rec[idx].ipuBuf);
    }
}

__asm__(".section .text\n"
        "    .set noat\n"
        "    .set noreorder\n"
        "    .global _rix_000\n"
        "    .type _rix_000, @function\n"
        "    .align 3\n"
        "_rix_000:\n"
        "    lw    $5, 0x14($4)\n"
        "    lw    $6, 0x18($4)\n"
        "    lw    $7, 0x8($4)\n"
        "    lw    $14, 0x0($4)\n"
        "    lw    $13, 0x4($4)\n"
        "    lw    $12, 0x10($4)\n"
        "    sll   $11, $12, 1\n"
        "    addiu $15, $0, -0x1\n"
        "    mtsab $13, 0x0\n"
        "1:\n"
        "    lq    $8, 0x0($5)\n"
        "    addi  $7, $7, -0x1\n"
        "    lq    $9, 0x0($6)\n"
        "    addu  $5, $5, $12\n"
        "    qfsrv $10, $9, $8\n"
        "    pextlb $8, $0, $10\n"
        "    pextub $9, $0, $10\n"
        "    sq    $8, 0x0($14)\n"
        "    addu  $6, $6, $12\n"
        "    sq    $9, 0x10($14)\n"
        "    bgtz  $7, 1b\n"
        "    addu  $14, $14, $11\n"
        "    addiu $5, $5, 0x80\n"
        "    addiu $6, $6, 0x80\n"
        "    lw    $7, 0xC($4)\n"
        "    and   $10, $15, $7\n"
        "    bnez  $10, 1b\n"
        "    daddu $15, $0, $0\n"
        "    jr    $31\n"
        "    nop\n"
        "    .size _rix_000, . - _rix_000\n"
        "    nop\n"
        "    .set reorder\n"
        "    .set at\n");

__asm__(".section .text\n"
        "    .set noat\n"
        "    .set noreorder\n"
        ".global _ri0_000\n"
        ".type _ri0_000, @function\n"
        "    .align 3\n"
        "_ri0_000:\n"
        "    lw $5, 0x14($4)\n"
        "    lw $6, 0x18($4)\n"
        "    lw $14, 0x0($4)\n"
        "    lw $13, 0x4($4)\n"
        "    lw $12, 0x10($4)\n"
        "    sll $11, $12, 1\n"
        "    mtsab $13, 0x0\n"
        "    addiu $24, $0, -0x1\n"
        ".L_ri0_00000250350:\n"
        "    lw $7, 0x8($4)\n"
        "    addiu $15, $0, -0x1\n"
        ".L_ri0_00000250358:\n"
        "    ld $8, 0x0($5)\n"
        "    ld $9, 0x0($6)\n"
        "    pcpyld $8, $9, $8\n"
        "    qfsrv $9, $8, $8\n"
        "    pextlb $8, $0, $9\n"
        "    sq $8, 0x0($14)\n"
        "    addi $7, $7, -0x1\n"
        "    addu $5, $5, $12\n"
        "    addu $14, $14, $11\n"
        "    bgtz $7, .L_ri0_00000250358\n"
        "    addu $6, $6, $12\n"
        "    addiu $5, $5, 0x140\n"
        "    addiu $6, $6, 0x140\n"
        "    lw $7, 0xC($4)\n"
        "    and $10, $15, $7\n"
        "    bnez $10, .L_ri0_00000250358\n"
        "    daddu $15, $0, $0\n"
        "    lw $5, 0x14($4)\n"
        "    lw $6, 0x18($4)\n"
        "    lw $14, 0x0($4)\n"
        "    addiu $5, $5, 0x40\n"
        "    addiu $6, $6, 0x40\n"
        "    addiu $14, $14, 0x80\n"
        "    bnez $24, .L_ri0_00000250350\n"
        "    daddu $24, $0, $0\n"
        "    jr $31\n"
        "    nop\n"
        ".size _ri0_000, . - _ri0_000\n"
        "    nop\n"
        "    .set reorder\n"
        "    .set at\n");

__asm__(".section .text\n"
        "    .set noat\n"
        "    .set noreorder\n"
        ".global _rix_001\n"
        ".type _rix_001, @function\n"
        "    .align 3\n"
        "_rix_001:\n"
        "    pnor $25, $0, $0\n"
        "    psrlh $25, $25, 15\n"
        "    lw $5, 0x14($4)\n"
        "    lw $6, 0x18($4)\n"
        "    lw $7, 0x8($4)\n"
        "    lw $14, 0x0($4)\n"
        "    lw $13, 0x4($4)\n"
        "    lw $24, 0x10($4)\n"
        "    lq $8, 0x0($5)\n"
        "    sll $12, $24, 1\n"
        "    lq $9, 0x0($6)\n"
        "    mtsab $13, 0x0\n"
        "    qfsrv $10, $9, $8\n"
        "    pextlb $8, $0, $10\n"
        "    addiu $11, $0, -0x1\n"
        "    beqz $7, .L_rix_0010025045C\n"
        "    pextub $9, $0, $10\n"
        ".L_rix_0010025040C:\n"
        "    addu $5, $5, $24\n"
        "    addu $6, $6, $24\n"
        "    lq $10, 0x0($5)\n"
        "    lq $15, 0x0($6)\n"
        "    qfsrv $2, $15, $10\n"
        "    pextlb $10, $0, $2\n"
        "    addi $7, $7, -0x1\n"
        "    pextub $15, $0, $2\n"
        "    paddh $2, $8, $10\n"
        "    paddh $3, $9, $15\n"
        "    por $8, $10, $0\n"
        "    por $9, $15, $0\n"
        "    paddh $2, $2, $25\n"
        "    paddh $3, $3, $25\n"
        "    psrlh $2, $2, 1\n"
        "    psrlh $3, $3, 1\n"
        "    sq $2, 0x0($14)\n"
        "    sq $3, 0x10($14)\n"
        "    bgtz $7, .L_rix_0010025040C\n"
        "    addu $14, $14, $12\n"
        ".L_rix_0010025045C:\n"
        "    addiu $5, $5, 0x80\n"
        "    addiu $6, $6, 0x80\n"
        "    lw $7, 0xC($4)\n"
        "    and $10, $11, $7\n"
        "    bnez $10, .L_rix_0010025040C\n"
        "    daddu $11, $0, $0\n"
        "    jr $31\n"
        "    nop\n"
        ".size _rix_001, . - _rix_001\n"
        "    nop\n"
        "    .set reorder\n"
        "    .set at\n");

__asm__(".section .text\n"
        "    .set noat\n"
        "    .set noreorder\n"
        ".global _ri0_001\n"
        ".type _ri0_001, @function\n"
        "    .align 3\n"
        "_ri0_001:\n"
        "    pnor $25, $0, $0\n"
        "    psrlh $25, $25, 15\n"
        "    lw $5, 0x14($4)\n"
        "    lw $6, 0x18($4)\n"
        "    lw $14, 0x0($4)\n"
        "    lw $13, 0x4($4)\n"
        "    lw $12, 0x10($4)\n"
        "    addiu $11, $0, 0x1\n"
        "    sll $24, $12, 1\n"
        "    mtsab $13, 0x0\n"
        ".L_ri0_001002504A8:\n"
        "    lw $7, 0x8($4)\n"
        "    ld $8, 0x0($5)\n"
        "    ld $9, 0x0($6)\n"
        "    pcpyld $8, $9, $8\n"
        "    qfsrv $8, $8, $8\n"
        "    ori $11, $11, 0x8000\n"
        "    beqz $7, .L_ri0_00100250504\n"
        "    pextlb $15, $0, $8\n"
        ".L_ri0_001002504C8:\n"
        "    addu $5, $5, $12\n"
        "    addu $6, $6, $12\n"
        "    ld $8, 0x0($5)\n"
        "    ld $9, 0x0($6)\n"
        "    pcpyld $8, $9, $8\n"
        "    qfsrv $8, $8, $8\n"
        "    pextlb $10, $0, $8\n"
        "    addi $7, $7, -0x1\n"
        "    paddh $9, $10, $15\n"
        "    por $15, $10, $0\n"
        "    paddh $10, $9, $25\n"
        "    psrlh $10, $10, 1\n"
        "    sq $10, 0x0($14)\n"
        "    bgtz $7, .L_ri0_001002504C8\n"
        "    addu $14, $14, $24\n"
        ".L_ri0_00100250504:\n"
        "    psrah $10, $11, 15\n"
        "    addiu $5, $5, 0x140\n"
        "    lw $7, 0xC($4)\n"
        "    addiu $6, $6, 0x140\n"
        "    and $10, $10, $7\n"
        "    bnez $10, .L_ri0_001002504C8\n"
        "    andi $11, $11, 0x7FFF\n"
        "    lw $5, 0x14($4)\n"
        "    lw $6, 0x18($4)\n"
        "    lw $14, 0x0($4)\n"
        "    addiu $5, $5, 0x40\n"
        "    addiu $6, $6, 0x40\n"
        "    addiu $14, $14, 0x80\n"
        "    andi $10, $11, 0x1\n"
        "    bnez $10, .L_ri0_001002504A8\n"
        "    andi $11, $11, 0xFFFE\n"
        "    jr $31\n"
        "    nop\n"
        ".size _ri0_001, . - _ri0_001\n"
        "    nop\n"
        "    .set reorder\n"
        "    .set at\n");

__asm__(".section .text\n"
        "    .set noat\n"
        "    .set noreorder\n"
        ".global _rix_010\n"
        ".type _rix_010, @function\n"
        "    .align 3\n"
        "_rix_010:\n"
        "    pnor $25, $0, $0\n"
        "    psrlh $25, $25, 15\n"
        "    lw $5, 0x14($4)\n"
        "    lw $6, 0x18($4)\n"
        "    lw $7, 0x8($4)\n"
        "    lw $14, 0x0($4)\n"
        "    lw $13, 0x4($4)\n"
        "    addiu $24, $0, 0x1\n"
        "    lw $9, 0x10($4)\n"
        "    sll $8, $9, 1\n"
        "    addiu $11, $0, -0x1\n"
        ".L_rix_0100025057C:\n"
        "    lq $10, 0x0($5)\n"
        "    lq $15, 0x0($6)\n"
        "    mtsab $13, 0x0\n"
        "    qfsrv $2, $15, $10\n"
        "    qfsrv $3, $10, $15\n"
        "    pextlb $10, $0, $2\n"
        "    addi $7, $7, -0x1\n"
        "    pextub $15, $0, $2\n"
        "    mtsab $24, 0x0\n"
        "    qfsrv $3, $3, $2\n"
        "    pextlb $2, $0, $3\n"
        "    pextub $3, $0, $3\n"
        "    paddh $10, $10, $2\n"
        "    paddh $15, $15, $3\n"
        "    paddh $2, $10, $25\n"
        "    paddh $3, $15, $25\n"
        "    psrlh $2, $2, 1\n"
        "    psrlh $3, $3, 1\n"
        "    sq $2, 0x0($14)\n"
        "    sq $3, 0x10($14)\n"
        "    addu $5, $5, $9\n"
        "    addu $6, $6, $9\n"
        "    bgtz $7, .L_rix_0100025057C\n"
        "    addu $14, $14, $8\n"
        "    addiu $5, $5, 0x80\n"
        "    addiu $6, $6, 0x80\n"
        "    lw $7, 0xC($4)\n"
        "    and $12, $11, $7\n"
        "    bnez $12, .L_rix_0100025057C\n"
        "    daddu $11, $0, $0\n"
        "    jr $31\n"
        "    nop\n"
        ".size _rix_010, . - _rix_010\n"
        "    nop\n"
        "    .set reorder\n"
        "    .set at\n");

__asm__(".section .text\n"
        "    .set noat\n"
        "    .set noreorder\n"
        ".global _ri0_010\n"
        ".type _ri0_010, @function\n"
        "    .align 3\n"
        "_ri0_010:\n"
        "    pnor $25, $0, $0\n"
        "    psrlh $25, $25, 15\n"
        "    lw $5, 0x14($4)\n"
        "    lw $6, 0x18($4)\n"
        "    lw $14, 0x0($4)\n"
        "    lw $13, 0x4($4)\n"
        "    addiu $24, $0, 0x1\n"
        "    addiu $12, $0, -0x1\n"
        "    lw $3, 0x10($4)\n"
        "    sll $2, $3, 1\n"
        ".L_ri0_01000250628:\n"
        "    lw $7, 0x8($4)\n"
        "    addiu $11, $0, -0x1\n"
        ".L_ri0_01000250630:\n"
        "    ld $8, 0x0($5)\n"
        "    ld $9, 0x0($6)\n"
        "    pcpyld $8, $9, $8\n"
        "    mtsab $13, 0x0\n"
        "    qfsrv $8, $8, $8\n"
        "    pextlb $9, $0, $8\n"
        "    addi $7, $7, -0x1\n"
        "    addu $5, $5, $3\n"
        "    addu $6, $6, $3\n"
        "    mtsab $24, 0x0\n"
        "    qfsrv $10, $0, $8\n"
        "    pextlb $8, $0, $10\n"
        "    paddh $10, $9, $8\n"
        "    paddh $10, $10, $25\n"
        "    psrlh $10, $10, 1\n"
        "    sq $10, 0x0($14)\n"
        "    bgtz $7, .L_ri0_01000250630\n"
        "    addu $14, $14, $2\n"
        "    addiu $5, $5, 0x140\n"
        "    addiu $6, $6, 0x140\n"
        "    lw $7, 0xC($4)\n"
        "    and $10, $11, $7\n"
        "    bnez $10, .L_ri0_01000250630\n"
        "    daddu $11, $0, $0\n"
        "    lw $5, 0x14($4)\n"
        "    lw $6, 0x18($4)\n"
        "    lw $14, 0x0($4)\n"
        "    addiu $5, $5, 0x40\n"
        "    addiu $6, $6, 0x40\n"
        "    addiu $14, $14, 0x80\n"
        "    bnez $12, .L_ri0_01000250628\n"
        "    daddu $12, $0, $0\n"
        "    jr $31\n"
        "    nop\n"
        ".size _ri0_010, . - _ri0_010\n"
        "    .set reorder\n"
        "    .set at\n");

__asm__(".section .text\n"
        "    .set noat\n"
        "    .set noreorder\n"
        ".global _rix_011\n"
        ".type _rix_011, @function\n"
        "    .align 3\n"
        "_rix_011:\n"
        "    pnor $25, $0, $0\n"
        "    psrlh $25, $25, 15\n"
        "    psllh $25, $25, 1\n"
        "    lw $5, 0x14($4)\n"
        "    lw $6, 0x18($4)\n"
        "    lw $7, 0x8($4)\n"
        "    lw $14, 0x0($4)\n"
        "    lw $13, 0x4($4)\n"
        "    lw $12, 0x10($4)\n"
        "    addiu $24, $0, 0x1\n"
        "    lq $8, 0x0($5)\n"
        "    lq $9, 0x0($6)\n"
        "    mtsab $13, 0x0\n"
        "    qfsrv $10, $9, $8\n"
        "    qfsrv $15, $8, $9\n"
        "    pextlb $8, $0, $10\n"
        "    pextub $9, $0, $10\n"
        "    addiu $11, $0, -0x1\n"
        "    mtsab $24, 0x0\n"
        "    qfsrv $15, $15, $10\n"
        "    pextlb $10, $0, $15\n"
        "    pextub $15, $0, $15\n"
        "    paddh $8, $8, $10\n"
        "    beqz $7, .L_rix_01100250790\n"
        "    paddh $9, $9, $15\n"
        ".L_rix_0110025071C:\n"
        "    addu $5, $5, $12\n"
        "    addu $6, $6, $12\n"
        "    lq $10, 0x0($5)\n"
        "    lq $15, 0x0($6)\n"
        "    mtsab $13, 0x0\n"
        "    qfsrv $2, $15, $10\n"
        "    qfsrv $3, $10, $15\n"
        "    pextlb $10, $0, $2\n"
        "    addi $7, $7, -0x1\n"
        "    pextub $15, $0, $2\n"
        "    mtsab $24, 0x0\n"
        "    qfsrv $3, $3, $2\n"
        "    pextlb $2, $0, $3\n"
        "    pextub $3, $0, $3\n"
        "    paddh $10, $10, $2\n"
        "    paddh $15, $15, $3\n"
        "    paddh $2, $8, $10\n"
        "    paddh $3, $9, $15\n"
        "    por $8, $10, $0\n"
        "    por $9, $15, $0\n"
        "    paddh $2, $2, $25\n"
        "    paddh $3, $3, $25\n"
        "    psrlh $2, $2, 2\n"
        "    psrlh $3, $3, 2\n"
        "    sq $2, 0x0($14)\n"
        "    sll $10, $12, 1\n"
        "    sq $3, 0x10($14)\n"
        "    bgtz $7, .L_rix_0110025071C\n"
        "    addu $14, $14, $10\n"
        ".L_rix_01100250790:\n"
        "    addiu $5, $5, 0x80\n"
        "    addiu $6, $6, 0x80\n"
        "    lw $7, 0xC($4)\n"
        "    and $10, $11, $7\n"
        "    bnez $10, .L_rix_0110025071C\n"
        "    daddu $11, $0, $0\n"
        "    jr $31\n"
        "    nop\n"
        ".size _rix_011, . - _rix_011\n"
        "    .set reorder\n"
        "    .set at\n");

__asm__(".section .text\n"
        "    .set noat\n"
        "    .set noreorder\n"
        ".global _ri0_011\n"
        ".type _ri0_011, @function\n"
        "    .align 3\n"
        "_ri0_011:\n"
        "    pnor $25, $0, $0\n"
        "    psrlh $25, $25, 15\n"
        "    psllh $25, $25, 1\n"
        "    lw $5, 0x14($4)\n"
        "    lw $6, 0x18($4)\n"
        "    lw $14, 0x0($4)\n"
        "    lw $13, 0x4($4)\n"
        "    lw $12, 0x10($4)\n"
        "    addiu $24, $0, 0x1\n"
        "    addiu $11, $0, 0x1\n"
        ".L_ri0_011002507D8:\n"
        "    lw $7, 0x8($4)\n"
        "    ld $8, 0x0($5)\n"
        "    ld $9, 0x0($6)\n"
        "    pcpyld $8, $9, $8\n"
        "    mtsab $13, 0x0\n"
        "    qfsrv $8, $8, $8\n"
        "    pextlb $9, $0, $8\n"
        "    addu $5, $5, $12\n"
        "    ori $11, $11, 0x8000\n"
        "    mtsab $24, 0x0\n"
        "    qfsrv $10, $0, $8\n"
        "    pextlb $8, $0, $10\n"
        "    beqz $7, .L_ri0_01100250864\n"
        "    paddh $15, $9, $8\n"
        ".L_ri0_01100250810:\n"
        "    addu $6, $6, $12\n"
        "    ld $8, 0x0($5)\n"
        "    ld $9, 0x0($6)\n"
        "    pcpyld $8, $9, $8\n"
        "    mtsab $13, 0x0\n"
        "    qfsrv $8, $8, $8\n"
        "    pextlb $9, $0, $8\n"
        "    addi $7, $7, -0x1\n"
        "    addu $5, $5, $12\n"
        "    mtsab $24, 0x0\n"
        "    qfsrv $10, $0, $8\n"
        "    pextlb $8, $0, $10\n"
        "    paddh $10, $9, $8\n"
        "    paddh $9, $10, $15\n"
        "    por $15, $10, $0\n"
        "    paddh $10, $9, $25\n"
        "    sll $8, $12, 1\n"
        "    psrlh $10, $10, 2\n"
        "    sq $10, 0x0($14)\n"
        "    bgtz $7, .L_ri0_01100250810\n"
        "    addu $14, $14, $8\n"
        ".L_ri0_01100250864:\n"
        "    psrah $10, $11, 15\n"
        "    addiu $5, $5, 0x140\n"
        "    lw $7, 0xC($4)\n"
        "    addiu $6, $6, 0x140\n"
        "    and $10, $10, $7\n"
        "    bnez $10, .L_ri0_01100250810\n"
        "    andi $11, $11, 0x7FFF\n"
        "    lw $5, 0x14($4)\n"
        "    lw $6, 0x18($4)\n"
        "    lw $14, 0x0($4)\n"
        "    addiu $5, $5, 0x40\n"
        "    addiu $6, $6, 0x40\n"
        "    addiu $14, $14, 0x80\n"
        "    andi $10, $11, 0x1\n"
        "    bnez $10, .L_ri0_011002507D8\n"
        "    andi $11, $11, 0xFFFE\n"
        "    jr $31\n"
        "    nop\n"
        ".size _ri0_011, . - _ri0_011\n"
        "    nop\n"
        "    .set reorder\n"
        "    .set at\n");

__asm__(".section .text\n"
        "    .set noat\n"
        "    .set noreorder\n"
        ".global _rix_100\n"
        ".type _rix_100, @function\n"
        "    .align 3\n"
        "_rix_100:\n"
        "    lw $5, 0x14($4)\n"
        "    lw $6, 0x18($4)\n"
        "    lw $7, 0x8($4)\n"
        "    lw $14, 0x0($4)\n"
        "    lw $13, 0x4($4)\n"
        "    lw $9, 0x10($4)\n"
        "    sll $8, $9, 1\n"
        "    addiu $11, $0, -0x1\n"
        "    mtsab $13, 0x0\n"
        ".L_rix_100_row:\n"
        "    lq $10, 0x0($5)\n"
        "    lq $15, 0x0($6)\n"
        "    qfsrv $2, $15, $10\n"
        "    pextlb $10, $0, $2\n"
        "    pextub $15, $0, $2\n"
        "    lq $2, 0x0($14)\n"
        "    lq $3, 0x10($14)\n"
        "    paddh $2, $2, $10\n"
        "    paddh $3, $3, $15\n"
        "    pnor $25, $0, $0\n"
        "    psrlh $25, $25, 15\n"
        "    paddh $10, $2, $25\n"
        "    psrlh $2, $10, 1\n"
        "    paddh $10, $3, $25\n"
        "    psrlh $3, $10, 1\n"
        "    sq $2, 0x0($14)\n"
        "    sq $3, 0x10($14)\n"
        "    addi $7, $7, -0x1\n"
        "    addu $5, $5, $9\n"
        "    addu $14, $14, $8\n"
        "    bgtz $7, .L_rix_100_row\n"
        "    addu $6, $6, $9\n"
        "    addiu $5, $5, 0x80\n"
        "    addiu $6, $6, 0x80\n"
        "    lw $7, 0xC($4)\n"
        "    and $12, $11, $7\n"
        "    bnez $12, .L_rix_100_row\n"
        "    daddu $11, $0, $0\n"
        "    jr $31\n"
        "    nop\n"
        ".size _rix_100, . - _rix_100\n"
        "    nop\n"
        "    .set reorder\n"
        "    .set at\n");

__asm__(".section .text\n"
        "    .set noat\n"
        "    .set noreorder\n"
        ".global _ri0_100\n"
        ".type _ri0_100, @function\n"
        "    .align 3\n"
        "_ri0_100:\n"
        "    lw $5, 0x14($4)\n"
        "    lw $6, 0x18($4)\n"
        "    lw $14, 0x0($4)\n"
        "    lw $13, 0x4($4)\n"
        "    addiu $12, $0, -0x1\n"
        "    lw $3, 0x10($4)\n"
        "    sll $2, $3, 1\n"
        "    mtsab $13, 0x0\n"
        ".L_ri0_10000250978:\n"
        "    lw $7, 0x8($4)\n"
        "    addiu $11, $0, -0x1\n"
        ".L_ri0_10000250980:\n"
        "    ld $8, 0x0($5)\n"
        "    ld $9, 0x0($6)\n"
        "    pcpyld $8, $9, $8\n"
        "    qfsrv $8, $8, $8\n"
        "    pextlb $9, $0, $8\n"
        "    addi $7, $7, -0x1\n"
        "    addu $5, $5, $3\n"
        "    addu $6, $6, $3\n"
        "    lq $8, 0x0($14)\n"
        "    paddh $10, $9, $8\n"
        "    pcgth $9, $10, $0\n"
        "    psrlh $9, $9, 15\n"
        "    paddh $10, $10, $9\n"
        "    psrlh $10, $10, 1\n"
        "    sq $10, 0x0($14)\n"
        "    bgtz $7, .L_ri0_10000250980\n"
        "    addu $14, $14, $2\n"
        "    addiu $5, $5, 0x140\n"
        "    addiu $6, $6, 0x140\n"
        "    lw $7, 0xC($4)\n"
        "    and $10, $11, $7\n"
        "    bnez $10, .L_ri0_10000250980\n"
        "    daddu $11, $0, $0\n"
        "    lw $5, 0x14($4)\n"
        "    lw $6, 0x18($4)\n"
        "    lw $14, 0x0($4)\n"
        "    addiu $5, $5, 0x40\n"
        "    addiu $6, $6, 0x40\n"
        "    addiu $14, $14, 0x80\n"
        "    bnez $12, .L_ri0_10000250978\n"
        "    daddu $12, $0, $0\n"
        "    jr $31\n"
        "    nop\n"
        ".size _ri0_100, . - _ri0_100\n"
        "    nop\n"
        "    .set reorder\n"
        "    .set at\n");

__asm__(".section .text\n"
        "    .set noat\n"
        "    .set noreorder\n"
        ".global _rix_101\n"
        ".type _rix_101, @function\n"
        "    .align 3\n"
        "_rix_101:\n"
        "    pnor $25, $0, $0\n"
        "    psrlh $25, $25, 15\n"
        "    lw $5, 0x14($4)\n"
        "    lw $6, 0x18($4)\n"
        "    lw $7, 0x8($4)\n"
        "    lw $14, 0x0($4)\n"
        "    lw $13, 0x4($4)\n"
        "    lw $12, 0x10($4)\n"
        "    lq $8, 0x0($5)\n"
        "    lq $9, 0x0($6)\n"
        "    mtsab $13, 0x0\n"
        "    qfsrv $10, $9, $8\n"
        "    sll $24, $12, 1\n"
        "    pextlb $8, $0, $10\n"
        "    addiu $11, $0, -0x1\n"
        "    beqz $7, .L_rix_10100250ACC\n"
        "    pextub $9, $0, $10\n"
        ".L_rix_10100250A4C:\n"
        "    addu $5, $5, $12\n"
        "    addu $6, $6, $12\n"
        "    lq $10, 0x0($5)\n"
        "    lq $15, 0x0($6)\n"
        "    qfsrv $2, $15, $10\n"
        "    pextlb $10, $0, $2\n"
        "    addi $7, $7, -0x1\n"
        "    pextub $15, $0, $2\n"
        "    paddh $2, $8, $10\n"
        "    paddh $3, $9, $15\n"
        "    por $8, $10, $0\n"
        "    por $9, $15, $0\n"
        "    paddh $2, $2, $25\n"
        "    paddh $3, $3, $25\n"
        "    psrlh $2, $2, 1\n"
        "    psrlh $3, $3, 1\n"
        "    lq $10, 0x0($14)\n"
        "    lq $15, 0x10($14)\n"
        "    paddh $2, $2, $10\n"
        "    paddh $3, $3, $15\n"
        "    paddh $10, $2, $25\n"
        "    psrlh $2, $10, 1\n"
        "    pcgth $10, $3, $0\n"
        "    psrlh $10, $10, 15\n"
        "    paddh $10, $3, $10\n"
        "    psrlh $3, $10, 1\n"
        "    sq $2, 0x0($14)\n"
        "    sq $3, 0x10($14)\n"
        "    bgtz $7, .L_rix_10100250A4C\n"
        "    addu $14, $14, $24\n"
        ".L_rix_10100250ACC:\n"
        "    addiu $5, $5, 0x80\n"
        "    addiu $6, $6, 0x80\n"
        "    lw $7, 0xC($4)\n"
        "    and $10, $11, $7\n"
        "    bnez $10, .L_rix_10100250A4C\n"
        "    daddu $11, $0, $0\n"
        "    jr $31\n"
        "    nop\n"
        ".size _rix_101, . - _rix_101\n"
        "    nop\n"
        "    .set reorder\n"
        "    .set at\n");

__asm__(".section .text\n"
        "    .set noat\n"
        "    .set noreorder\n"
        ".global _ri0_101\n"
        ".type _ri0_101, @function\n"
        "    .align 3\n"
        "_ri0_101:\n"
        "    pnor $25, $0, $0\n"
        "    psrlh $25, $25, 15\n"
        "    lw $5, 0x14($4)\n"
        "    lw $6, 0x18($4)\n"
        "    lw $14, 0x0($4)\n"
        "    lw $13, 0x4($4)\n"
        "    lw $12, 0x10($4)\n"
        "    addiu $11, $0, 0x1\n"
        "    sll $24, $12, 1\n"
        "    mtsab $13, 0x0\n"
        ".L_ri0_10100250B18:\n"
        "    lw $7, 0x8($4)\n"
        "    ld $8, 0x0($5)\n"
        "    ld $9, 0x0($6)\n"
        "    pcpyld $8, $9, $8\n"
        "    qfsrv $8, $8, $8\n"
        "    ori $11, $11, 0x8000\n"
        "    beqz $7, .L_ri0_10100250B8C\n"
        "    pextlb $15, $0, $8\n"
        ".L_ri0_10100250B38:\n"
        "    addu $5, $5, $12\n"
        "    addu $6, $6, $12\n"
        "    ld $8, 0x0($5)\n"
        "    ld $9, 0x0($6)\n"
        "    pcpyld $8, $9, $8\n"
        "    qfsrv $8, $8, $8\n"
        "    pextlb $10, $0, $8\n"
        "    addi $7, $7, -0x1\n"
        "    paddh $9, $10, $15\n"
        "    por $15, $10, $0\n"
        "    paddh $10, $9, $25\n"
        "    psrlh $10, $10, 1\n"
        "    lq $8, 0x0($14)\n"
        "    paddh $10, $10, $8\n"
        "    pcgth $9, $10, $0\n"
        "    psrlh $9, $9, 15\n"
        "    paddh $10, $10, $9\n"
        "    psrlh $10, $10, 1\n"
        "    sq $10, 0x0($14)\n"
        "    bgtz $7, .L_ri0_10100250B38\n"
        "    addu $14, $14, $24\n"
        ".L_ri0_10100250B8C:\n"
        "    psrah $10, $11, 15\n"
        "    addiu $5, $5, 0x140\n"
        "    lw $7, 0xC($4)\n"
        "    addiu $6, $6, 0x140\n"
        "    and $10, $10, $7\n"
        "    bnez $10, .L_ri0_10100250B38\n"
        "    andi $11, $11, 0x7FFF\n"
        "    lw $5, 0x14($4)\n"
        "    lw $6, 0x18($4)\n"
        "    lw $14, 0x0($4)\n"
        "    addiu $5, $5, 0x40\n"
        "    addiu $6, $6, 0x40\n"
        "    addiu $14, $14, 0x80\n"
        "    andi $10, $11, 0x1\n"
        "    bnez $10, .L_ri0_10100250B18\n"
        "    andi $11, $11, 0xFFFE\n"
        "    jr $31\n"
        "    nop\n"
        ".size _ri0_101, . - _ri0_101\n"
        "    nop\n"
        "    .set reorder\n"
        "    .set at\n");

__asm__(".section .text\n"
        "    .set noat\n"
        "    .set noreorder\n"
        ".global _rix_110\n"
        ".type _rix_110, @function\n"
        "    .align 3\n"
        "_rix_110:\n"
        "    pnor $25, $0, $0\n"
        "    psrlh $25, $25, 15\n"
        "    lw $5, 0x14($4)\n"
        "    lw $6, 0x18($4)\n"
        "    lw $7, 0x8($4)\n"
        "    lw $14, 0x0($4)\n"
        "    lw $13, 0x4($4)\n"
        "    addiu $24, $0, 0x1\n"
        "    lw $9, 0x10($4)\n"
        "    sll $8, $9, 1\n"
        "    addiu $11, $0, -0x1\n"
        ".L_rix_11000250C04:\n"
        "    lq $10, 0x0($5)\n"
        "    lq $15, 0x0($6)\n"
        "    mtsab $13, 0x0\n"
        "    qfsrv $2, $15, $10\n"
        "    qfsrv $3, $10, $15\n"
        "    pextlb $10, $0, $2\n"
        "    addi $7, $7, -0x1\n"
        "    pextub $15, $0, $2\n"
        "    mtsab $24, 0x0\n"
        "    qfsrv $3, $3, $2\n"
        "    pextlb $2, $0, $3\n"
        "    pextub $3, $0, $3\n"
        "    paddh $10, $10, $2\n"
        "    paddh $15, $15, $3\n"
        "    paddh $2, $10, $25\n"
        "    paddh $3, $15, $25\n"
        "    psrlh $2, $2, 1\n"
        "    psrlh $3, $3, 1\n"
        "    lq $10, 0x0($14)\n"
        "    lq $15, 0x10($14)\n"
        "    paddh $2, $2, $10\n"
        "    paddh $3, $3, $15\n"
        "    paddh $10, $2, $25\n"
        "    psrlh $2, $10, 1\n"
        "    pcgth $10, $3, $0\n"
        "    psrlh $10, $10, 15\n"
        "    paddh $10, $3, $10\n"
        "    psrlh $3, $10, 1\n"
        "    sq $2, 0x0($14)\n"
        "    sq $3, 0x10($14)\n"
        "    addu $5, $5, $9\n"
        "    addu $6, $6, $9\n"
        "    bgtz $7, .L_rix_11000250C04\n"
        "    addu $14, $14, $8\n"
        "    addiu $5, $5, 0x80\n"
        "    addiu $6, $6, 0x80\n"
        "    lw $7, 0xC($4)\n"
        "    and $12, $11, $7\n"
        "    bnez $12, .L_rix_11000250C04\n"
        "    daddu $11, $0, $0\n"
        "    jr $31\n"
        "    nop\n"
        ".size _rix_110, . - _rix_110\n"
        "    nop\n"
        "    .set reorder\n"
        "    .set at\n");

__asm__(".section .text\n"
        "    .set noat\n"
        "    .set noreorder\n"
        ".global _ri0_110\n"
        ".type _ri0_110, @function\n"
        "    .align 3\n"
        "_ri0_110:\n"
        "    pnor $25, $0, $0\n"
        "    psrlh $25, $25, 15\n"
        "    lw $5, 0x14($4)\n"
        "    lw $6, 0x18($4)\n"
        "    lw $14, 0x0($4)\n"
        "    lw $13, 0x4($4)\n"
        "    addiu $24, $0, 0x1\n"
        "    addiu $12, $0, -0x1\n"
        "    lw $3, 0x10($4)\n"
        "    sll $2, $3, 1\n"
        ".L_ri0_11000250CE0:\n"
        "    lw $7, 0x8($4)\n"
        "    addiu $11, $0, -0x1\n"
        ".L_ri0_11000250CE8:\n"
        "    ld $8, 0x0($5)\n"
        "    ld $9, 0x0($6)\n"
        "    pcpyld $8, $9, $8\n"
        "    mtsab $13, 0x0\n"
        "    qfsrv $8, $8, $8\n"
        "    pextlb $9, $0, $8\n"
        "    addi $7, $7, -0x1\n"
        "    addu $5, $5, $3\n"
        "    addu $6, $6, $3\n"
        "    mtsab $24, 0x0\n"
        "    qfsrv $10, $0, $8\n"
        "    pextlb $8, $0, $10\n"
        "    paddh $10, $9, $8\n"
        "    paddh $10, $10, $25\n"
        "    psrlh $10, $10, 1\n"
        "    lq $8, 0x0($14)\n"
        "    paddh $10, $10, $8\n"
        "    pcgth $9, $10, $0\n"
        "    psrlh $9, $9, 15\n"
        "    paddh $10, $10, $9\n"
        "    psrlh $10, $10, 1\n"
        "    sq $10, 0x0($14)\n"
        "    bgtz $7, .L_ri0_11000250CE8\n"
        "    addu $14, $14, $2\n"
        "    addiu $5, $5, 0x140\n"
        "    addiu $6, $6, 0x140\n"
        "    lw $7, 0xC($4)\n"
        "    and $10, $11, $7\n"
        "    bnez $10, .L_ri0_11000250CE8\n"
        "    daddu $11, $0, $0\n"
        "    lw $5, 0x14($4)\n"
        "    lw $6, 0x18($4)\n"
        "    lw $14, 0x0($4)\n"
        "    addiu $5, $5, 0x40\n"
        "    addiu $6, $6, 0x40\n"
        "    addiu $14, $14, 0x80\n"
        "    bnez $12, .L_ri0_11000250CE0\n"
        "    daddu $12, $0, $0\n"
        "    jr $31\n"
        "    nop\n"
        ".size _ri0_110, . - _ri0_110\n"
        "    .set reorder\n"
        "    .set at\n");

__asm__(".section .text\n"
        "    .set noat\n"
        "    .set noreorder\n"
        ".global _rix_111\n"
        ".type _rix_111, @function\n"
        "    .align 3\n"
        "_rix_111:\n"
        "    pnor $25, $0, $0\n"
        "    psrlh $25, $25, 15\n"
        "    psllh $25, $25, 1\n"
        "    lw $5, 0x14($4)\n"
        "    lw $6, 0x18($4)\n"
        "    lw $7, 0x8($4)\n"
        "    lw $14, 0x0($4)\n"
        "    lw $13, 0x4($4)\n"
        "    lw $24, 0x10($4)\n"
        "    addiu $12, $0, 0x1\n"
        "    lq $8, 0x0($5)\n"
        "    lq $9, 0x0($6)\n"
        "    mtsab $13, 0x0\n"
        "    qfsrv $10, $9, $8\n"
        "    qfsrv $15, $8, $9\n"
        "    pextlb $8, $0, $10\n"
        "    pextub $9, $0, $10\n"
        "    addiu $11, $0, -0x1\n"
        "    mtsab $12, 0x0\n"
        "    qfsrv $15, $15, $10\n"
        "    pextlb $10, $0, $15\n"
        "    pextub $15, $0, $15\n"
        "    paddh $8, $8, $10\n"
        "    beqz $7, .L_rix_11100250E90\n"
        "    paddh $9, $9, $15\n"
        ".L_rix_11100250DEC:\n"
        "    addu $5, $5, $24\n"
        "    addu $6, $6, $24\n"
        "    lq $10, 0x0($5)\n"
        "    lq $15, 0x0($6)\n"
        "    mtsab $13, 0x0\n"
        "    qfsrv $2, $15, $10\n"
        "    qfsrv $3, $10, $15\n"
        "    pextlb $10, $0, $2\n"
        "    addi $7, $7, -0x1\n"
        "    pextub $15, $0, $2\n"
        "    mtsab $12, 0x0\n"
        "    qfsrv $3, $3, $2\n"
        "    pextlb $2, $0, $3\n"
        "    pextub $3, $0, $3\n"
        "    paddh $10, $10, $2\n"
        "    paddh $15, $15, $3\n"
        "    paddh $2, $8, $10\n"
        "    paddh $3, $9, $15\n"
        "    por $8, $10, $0\n"
        "    por $9, $15, $0\n"
        "    paddh $2, $2, $25\n"
        "    paddh $3, $3, $25\n"
        "    psrlh $2, $2, 2\n"
        "    psrlh $3, $3, 2\n"
        "    lq $10, 0x0($14)\n"
        "    lq $15, 0x10($14)\n"
        "    paddh $2, $2, $10\n"
        "    paddh $3, $3, $15\n"
        "    pnor $25, $0, $0\n"
        "    psrlh $25, $25, 15\n"
        "    paddh $10, $2, $25\n"
        "    psrlh $2, $10, 1\n"
        "    paddh $10, $3, $25\n"
        "    psrlh $3, $10, 1\n"
        "    sq $2, 0x0($14)\n"
        "    sll $10, $24, 1\n"
        "    sq $3, 0x10($14)\n"
        "    bgtz $7, .L_rix_11100250DEC\n"
        "    addu $14, $14, $10\n"
        ".L_rix_11100250E90:\n"
        "    addiu $5, $5, 0x80\n"
        "    addiu $6, $6, 0x80\n"
        "    lw $7, 0xC($4)\n"
        "    and $10, $11, $7\n"
        "    bnez $10, .L_rix_11100250DEC\n"
        "    daddu $11, $0, $0\n"
        "    jr $31\n"
        "    nop\n"
        ".size _rix_111, . - _rix_111\n"
        "    .set reorder\n"
        "    .set at\n");

__asm__(".section .text\n"
        "    .set noat\n"
        "    .set noreorder\n"
        ".global _ri0_111\n"
        ".type _ri0_111, @function\n"
        "    .align 3\n"
        "_ri0_111:\n"
        "    pnor $25, $0, $0\n"
        "    psrlh $25, $25, 15\n"
        "    psllh $25, $25, 1\n"
        "    lw $5, 0x14($4)\n"
        "    lw $6, 0x18($4)\n"
        "    lw $14, 0x0($4)\n"
        "    lw $13, 0x4($4)\n"
        "    lw $12, 0x10($4)\n"
        "    addiu $24, $0, 0x1\n"
        "    addiu $11, $0, 0x1\n"
        ".L_ri0_11100250ED8:\n"
        "    lw $7, 0x8($4)\n"
        "    ld $8, 0x0($5)\n"
        "    ld $9, 0x0($6)\n"
        "    pcpyld $8, $9, $8\n"
        "    mtsab $13, 0x0\n"
        "    qfsrv $8, $8, $8\n"
        "    pextlb $9, $0, $8\n"
        "    addu $5, $5, $12\n"
        "    ori $11, $11, 0x8000\n"
        "    mtsab $24, 0x0\n"
        "    qfsrv $10, $0, $8\n"
        "    pextlb $8, $0, $10\n"
        "    beqz $7, .L_ri0_11100250F7C\n"
        "    paddh $15, $9, $8\n"
        ".L_ri0_11100250F10:\n"
        "    addu $6, $6, $12\n"
        "    ld $8, 0x0($5)\n"
        "    ld $9, 0x0($6)\n"
        "    pcpyld $8, $9, $8\n"
        "    mtsab $13, 0x0\n"
        "    qfsrv $8, $8, $8\n"
        "    pextlb $9, $0, $8\n"
        "    addi $7, $7, -0x1\n"
        "    addu $5, $5, $12\n"
        "    mtsab $24, 0x0\n"
        "    qfsrv $10, $0, $8\n"
        "    pextlb $8, $0, $10\n"
        "    paddh $10, $9, $8\n"
        "    paddh $9, $10, $15\n"
        "    por $15, $10, $0\n"
        "    paddh $10, $9, $25\n"
        "    psrlh $10, $10, 2\n"
        "    lq $8, 0x0($14)\n"
        "    paddh $10, $10, $8\n"
        "    pcgth $9, $10, $0\n"
        "    psrlh $9, $9, 15\n"
        "    paddh $10, $10, $9\n"
        "    sll $8, $12, 1\n"
        "    psrlh $10, $10, 1\n"
        "    sq $10, 0x0($14)\n"
        "    bgtz $7, .L_ri0_11100250F10\n"
        "    addu $14, $14, $8\n"
        ".L_ri0_11100250F7C:\n"
        "    psrah $10, $11, 15\n"
        "    addiu $5, $5, 0x140\n"
        "    lw $7, 0xC($4)\n"
        "    addiu $6, $6, 0x140\n"
        "    and $10, $10, $7\n"
        "    bnez $10, .L_ri0_11100250F10\n"
        "    andi $11, $11, 0x7FFF\n"
        "    lw $5, 0x14($4)\n"
        "    lw $6, 0x18($4)\n"
        "    lw $14, 0x0($4)\n"
        "    addiu $5, $5, 0x40\n"
        "    addiu $6, $6, 0x40\n"
        "    addiu $14, $14, 0x80\n"
        "    andi $10, $11, 0x1\n"
        "    bnez $10, .L_ri0_11100250ED8\n"
        "    andi $11, $11, 0xFFFE\n"
        "    jr $31\n"
        "    nop\n"
        ".size _ri0_111, . - _ri0_111\n"
        "    nop\n"
        "    .set reorder\n"
        "    .set at\n");

void _copyAddRefImage(void *dst, void *ref, void *diff)
{
    __asm__ __volatile__(".set noreorder\n"
                         "addiu $12, $0, 0x18\n"
                         "lui $10, %%hi(_maxval)\n"
                         "addiu $10, $10, %%lo(_maxval)\n"
                         "lq $11, 0x0($10)\n"
                         "1:\n"
                         "lq $8, 0x0($5)\n"
                         "addi $12, $12, -0x1\n"
                         "lq $13, 0x0($6)\n"
                         "addiu $4, $4, 0x10\n"
                         "lq $9, 0x10($5)\n"
                         "paddh $8, $8, $13\n"
                         "lq $2, 0x10($6)\n"
                         "pminh $8, $8, $11\n"
                         "paddh $9, $9, $2\n"
                         "pmaxh $8, $8, $0\n"
                         "pminh $9, $9, $11\n"
                         "addiu $5, $5, 0x20\n"
                         "pmaxh $9, $9, $0\n"
                         "addiu $6, $6, 0x20\n"
                         "ppacb $10, $9, $8\n"
                         "bnez $12, 1b\n"
                         "sq $10, -0x10($4)\n"
                         ".set reorder\n" ::
                             : "$2", "$8", "$9", "$10", "$11", "$12", "$13", "memory");
}

/* The saturating pack _copyAddRefImage does without the add: 24 rounds of two
 * quadwords of signed halfword samples clamped into 0..255 and packed down to
 * bytes. Whole-function assembly under the MMI exception, and the 16 byte
 * clamp mask its sibling reads as _maxval lives in this function's own
 * text, aligned to a quadword, with the two pad instructions the alignment
 * leaves behind. */
/* STA: top-level asm, so _copyRefImage and the _maxval words each carry the
   symbol sizes the ROM's split gives them */
__asm__(".section .text\n"
        "    .set noat\n"
        "    .set noreorder\n"
        "    .align 3\n"
        "    .globl _copyRefImage\n"
        "    .type _copyRefImage, @function\n"
        "_copyRefImage:\n"
        "addiu $12, $0, 0x18\n"
        "lui $10, %hi(_maxval)\n"
        "addiu $10, $10, %lo(_maxval)\n"
        "lq $11, 0x0($10)\n"
        "1:\n"
        "lq $8, 0x0($5)\n"
        "addi $12, $12, -0x1\n"
        "pminh $8, $8, $11\n"
        "lq $9, 0x10($5)\n"
        "pmaxh $8, $8, $0\n"
        "pminh $9, $9, $11\n"
        "addiu $5, $5, 0x20\n"
        "pmaxh $9, $9, $0\n"
        "addiu $4, $4, 0x10\n"
        "ppacb $10, $9, $8\n"
        "bnez $12, 1b\n"
        "sq $10, -0x10($4)\n"
                         "    .size _copyRefImage, 0x40\n"
        "    .align 4\n"
        "    .type _maxval, @function\n"
        "_maxval:\n"
        "    .word 0x00FF00FF\n"
        "    .word 0x00FF00FF\n"
        "    .word 0x00FF00FF\n"
        "    .word 0x00FF00FF\n"
        "    jr $31\n"
        "    nop\n"
        "    .size _maxval, . - _maxval\n"
        "    .set reorder\n"
        "    .set at\n");

void _ipuSetMPEG1(int on)
{
    int *reg = (int *)IPU_CTRL;
    *reg = (*reg & 0xFF7FFFFF) | (on << 23);
}

int _waitBdecOut(MpegSys *p)
{
    int a[8];
    int b[8];
    int ret = 1;
    int bp;
    long long top;
    int intr;

    _waitIpuIdle(p);
    while (*D3_QWC != 0 && (*IPU_CTRL & 0x4000) == 0) {
        if (*D4_QWC == 0 && (*D4_CHCR & 0x100) == 0) {
            a[0] = 1;
            _dispatchMpegCallback(p->mp, a);
        }
    }
    bp = *IPU_BP;
    top = *(long long *)IPU_TOP;
    p->top32 = top;
    if (top < 0) {
        p->top32len = (bp & 0x1F) != 0 ? 32 - (bp & 0x1F) : 0;
    } else {
        p->top32len = 32;
    }
    if ((*IPU_CTRL & 0x4000) != 0) {
        _Error(p, "Error code detected(BDEC)");
        b[0] = 2;
        _dispatchMpegCallback(p->mp, b);
        *(int *)IPU_CTRL = 0x40000000;
        b[0] = 3;
        _dispatchMpegCallback(p->mp, b);
        intr = DIntr();
        *D_ENABLEW = *D_ENABLER | 0x10000;
        *D3_CHCR = 0;
        *D_ENABLEW = *D_ENABLER & 0xFFFEFFFF;
        if (intr) {
            EIntr();
        }
        ret = 0;
        *D3_QWC = 0;
    }
    return ret;
}

int _dmVector(MpegSys *p)
{
    return _ipuVdec(p, 3);
}

void _dualPrimeVector(MpegSys *p, int *DMV, int *dmvector, int mvx, int mvy)
{
    int vec;
    int ps;

    if (p->picture_structure == 3) {
        if (p->top_field_first != 0) {
            DMV[0] = ((mvx + (mvx > 0)) >> 1) + dmvector[0];
            DMV[1] = ((mvy + (mvy > 0)) >> 1) + dmvector[1] - 1;
            DMV[2] = ((3 * mvx + (mvx > 0)) >> 1) + dmvector[0];
            DMV[3] = ((3 * mvy + (mvy > 0)) >> 1) + dmvector[1] + 1;
        } else {
            DMV[0] = ((3 * mvx + (mvx > 0)) >> 1) + dmvector[0];
            DMV[1] = ((3 * mvy + (mvy > 0)) >> 1) + dmvector[1] - 1;
            DMV[2] = ((mvx + (mvx > 0)) >> 1) + dmvector[0];
            DMV[3] = ((mvy + (mvy > 0)) >> 1) + dmvector[1] + 1;
        }
    } else {
        DMV[0] = ((mvx + (mvx > 0)) >> 1) + dmvector[0];
        vec = ((mvy + (mvy > 0)) >> 1) + dmvector[1];
        DMV[1] = vec;
        if (p->picture_structure == 1) {
            DMV[1] = vec - 1;
        } else {
            DMV[1] = vec + 1;
        }
    }
}

int _mbAddressIncrement(MpegSys *p)
{
    int cont;
    int sum;
    unsigned int v;

    sum = 0;
    do {
        v = _ipuVdec(p, 0);
        switch (v) {
        case 0x22:
            cont = 1;
            break;
        case 0x23:
            cont = 1;
            sum += 0x21;
            break;
        case 0: {
            int r = _peepBit(p, 0xB);
            if ((p->isMpeg2 != 0) && (r == 0xF)) {
                _flushBuf(p, 0xB);
                cont = 1;
            } else {
                _Error1(p, "Invalid macroblock_address_increment code(0x%08x)", v);
                p->isError = 1;
                return 1;
            }
        } break;
        default:
            sum += v;
            cont = 0;
            break;
        }
    } while (cont);
    return sum;
}

int _pictureData0(MpegSys *p)
{
    int n = p->widthMB * p->heightMB;
    int r;

    p->mbcont.cur = 0;
    p->mbcont.aux = 0;
    if (p->picture_structure != 3) {
        n = n >> 1;
    }
    do {
        r = _slice0(p, n);
    } while (r == 1 || r == 3);
    _waitIpuIdle(p);
    if (_waitBdecOut(p) == 0) {
        r = 2;
    }
    while (((*(volatile unsigned int *)D9_CHCR) >> 8) & 1) {}
    if (r == 0) {
        _doMC(p, p->mbcont.cur == 0);
    }
    if (r == 1 || r == 2) {
        _Error(p, "= Skip to the next picture =");
    }
    return r == 0;
}

int _sliceA0(MpegSys *p, int total, int *mba, int *inc, int PMV[2][2][2])
{
    int id;
    int m;
    int n;

    p->isError = 0;
    _nextStartCode(p);
    id = _peepBit(p, 0x20);
    if ((unsigned int)(id - 0x101) >= 0xAF) {
        _Error1(p, "slice_start_code(0x%08x) out of range", id);
        return 2;
    }
    _flushBuf(p, 0x20);
    m = _sliceB(p);
    n = _mbAddressIncrement(p);
    *inc = n;
    if (p->isError != 0) {
        _Error(p, "_sliceA0(): error happens");
        return 1;
    }
    *mba = ((((m << 7) + (id & 0xFF)) - 1) * p->widthMB + n) - 1;
    *inc = 1;
    p->sp_dcr = 1;
    PMV[1][0][1] = 0;
    PMV[1][0][0] = 0;
    PMV[0][0][1] = 0;
    PMV[0][0][0] = 0;
    PMV[1][1][1] = 0;
    PMV[1][1][0] = 0;
    PMV[0][1][1] = 0;
    PMV[0][1][0] = 0;
    return 0;
}

int _slice0(MpegSys *p, int total)
{
    int PMV[2][2][2];
    int mv_field_sel[2][2];
    int dmvector[4];
    int mba;
    int n;
    int mb_type;
    int motion_type;
    int dct_type;
    int r;

    mba = 0;
    n = 0;
    r = _sliceA0(p, total, &mba, &n, PMV);
    if (r != 0) {
        return r;
    }
    p->isError = 0;
    for (;;) {
        if (mba >= total) {
            return 0;
        }
        p->mbcont.rec[p->mbcont.cur].skip = 0;
        if (_waitBdecOut(p) == 0) {
            return 2;
        }
        if (n == 0) {
            if (_peepBit(p, 0x17) == 0 || p->isError != 0) {
                p->isError = 0;
                return 3;
            }
            n = _mbAddressIncrement(p);
            if (p->isError != 0) {
                p->isError = 0;
                return 1;
            }
        }
        if (mba >= total) {
            _Error(p, "Too many macroblocks in picture");
            return 2;
        }
        if (n == 1) {
            if (_decMB0(p, &mb_type, &motion_type, &dct_type, PMV, mv_field_sel, dmvector) == 0) {
                p->isError = 0;
                return 1;
            }
        } else {
            if (_skipMB0(p, PMV, &motion_type, mv_field_sel, &mb_type) == 0) {
                p->isError = 0;
                return 2;
            }
        }
        if (_motionComp0(p, mba, n, mb_type, motion_type, PMV, mv_field_sel, dmvector) == 0) {
            p->isError = 0;
            return 2;
        }
        if (mba != 0) {
            _doMC(p, p->mbcont.cur ^ 1);
        }
        mba = mba + 1;
        p->mbcont.cur = p->mbcont.cur ^ 1;
        n = n - 1;
    }
}

int _skipMB0(MpegSys *p, int PMV[2][2][2], int *motion_type, int mv_field_sel[2][2], int *mb_type)
{
    int ret = 1;
    MCRecord *pq;

    pq = &p->mbcont.rec[p->mbcont.cur];
    pq->skip = 1;
    p->sp_dcr = 1;
    if (p->picture_coding_type == 2) {
        PMV[0][0][0] = PMV[0][0][1] = PMV[1][0][0] = PMV[1][0][1] = 0;
    }
    if (p->picture_structure == 3) {
        motion_type[0] = 2;
    } else {
        motion_type[0] = 1;
        mv_field_sel[0][0] = mv_field_sel[0][1] = p->picture_structure == 2;
    }
    if (p->picture_coding_type == 1) {
        _Error(p, "skiped macroblock in I picure is not allowed");
        ret = 0;
    }
    mb_type[0] = mb_type[0] & ~1;
    return ret;
}

/* Decode one macroblock's header: the macroblock type, the motion and DCT
 * types, the quantiser scale and the motion vectors, then either start the
 * IPU block decode (the fromIPU channel writing into the current record) or
 * mark the record skipped, and reset the motion vector predictors. PMV is the
 * [r][s][t] predictor array _motionVectors takes. */
int _decMB0(MpegSys *p, int *mb_type, int *motion_type, int *dct_type, int PMV[2][2][2], int mv_field_sel[2][2],
            int *dmvector)
{
    int mv_count;
    int mv_format;
    int dmv;
    int mvscale;
    MCRecord *pq;
    int cmd;
    int cmd2;

    *IPU_CTRL = (*IPU_CTRL & 0xF8FFFFFF) | (p->picture_coding_type << 24);
    mb_type[0] = _ipuVdec(p, 1);
    if (mb_type[0] == 0) {
        _Error(p, "Invalid macroblock_type code: 0");
        p->isError = 1;
        return 0;
    }
    if (mb_type[0] & 0xC) {
        if (p->picture_structure == 3 && p->frame_pred_frame_dct != 0) {
            motion_type[0] = 2;
        } else {
            motion_type[0] = _nextBit(p, 2);
        }
    } else if ((mb_type[0] & 1) && p->concealment_motion_vectors != 0) {
        motion_type[0] = p->picture_structure == 3 ? 2 : 1;
    }
    if (p->picture_structure == 3) {
        mv_count = motion_type[0] == 1 ? 2 : 1;
        mv_format = motion_type[0] == 2;
    } else {
        mv_count = motion_type[0] == 2 ? 2 : 1;
        mv_format = 0;
    }
    dmv = motion_type[0] == 3;
    mvscale = 0;
    if (mv_format == 0) {
        mvscale = p->picture_structure == 3;
    }
    dct_type[0] = p->picture_structure == 3 && p->frame_pred_frame_dct == 0 && (mb_type[0] & 3) != 0
                      ? _nextBit(p, 1)
                      : 0;
    if (mb_type[0] & 0x10) {
        p->qscqsc = _nextBit(p, 5);
    }
    if ((mb_type[0] & 8) || ((mb_type[0] & 1) && p->concealment_motion_vectors != 0)) {
        if (p->isMpeg2) {
            _motionVectors(p, PMV, dmvector, mv_field_sel, 0, mv_count, mv_format, p->f_code[0][0] - 1,
                           p->f_code[0][1] - 1, dmv, mvscale);
        } else {
            _motionVector(p, PMV[0][0], dmvector, p->forward_f_code - 1, p->forward_f_code - 1, 0, 0,
                          p->full_pel_forward_vector);
        }
    }
    if (p->isError) {
        return 0;
    }
    if (mb_type[0] & 4) {
        if (p->isMpeg2) {
            _motionVectors(p, PMV, dmvector, mv_field_sel, 1, mv_count, mv_format, p->f_code[1][0] - 1,
                           p->f_code[1][1] - 1, 0, mvscale);
        } else {
            _motionVector(p, PMV[0][1], dmvector, p->backward_f_code - 1, p->backward_f_code - 1, 0, 0,
                          p->full_pel_backward_vector);
        }
    }
    if (p->isError) {
        return 0;
    }
    if ((mb_type[0] & 1) && p->concealment_motion_vectors != 0) {
        _flushBuf(p, 1);
    }
    if (mb_type[0] & 3) {
        _ipuToSpr(p->mbcont.rec[p->mbcont.cur].ipuBuf, 0x300);
        _waitIpuIdle(p);
        cmd = ((mb_type[0] & 1) << 27) | (p->qscqsc << 16);
        cmd2 = (p->sp_dcr << 26) | 0x20000000;
        _sendIpuCommand(p, cmd | cmd2 | (dct_type[0] << 25));
    } else {
        p->mbcont.rec[p->mbcont.cur].skip = 1;
    }
    p->sp_dcr = 0;
    if (p->isError) {
        return 0;
    }
    if ((mb_type[0] & 1) == 0) {
        p->sp_dcr = 1;
    }
    if ((mb_type[0] & 1) && p->concealment_motion_vectors == 0) {
        PMV[0][0][0] = PMV[0][0][1] = PMV[1][0][0] = PMV[1][0][1] = 0;
        PMV[0][1][0] = PMV[0][1][1] = PMV[1][1][0] = PMV[1][1][1] = 0;
    }
    if (p->picture_coding_type == 2 && (mb_type[0] & 9) == 0) {
        PMV[0][0][0] = PMV[0][0][1] = PMV[1][0][0] = PMV[1][0][1] = 0;
        if (p->picture_structure == 3) {
            motion_type[0] = 2;
        } else {
            motion_type[0] = 1;
            mv_field_sel[0][0] = p->picture_structure == 2;
        }
    }
    return 1;
}

void _decode_motion_vector(int *pred, int r_size, int motion_code, int motion_r, int full_pel)
{
    int lim = 16 << r_size;
    int vec = full_pel ? (*pred >> 1) : *pred;

    if (motion_code > 0) {
        vec += ((motion_code - 1) << r_size) + motion_r + 1;
        if (vec >= lim) {
            vec -= lim + lim;
        }
    } else if (motion_code < 0) {
        vec -= ((-motion_code - 1) << r_size) + motion_r + 1;
        if (vec < -lim) {
            vec += lim + lim;
        }
    }
    *pred = full_pel ? vec * 2 : vec;
}

void _motionVectors(MpegSys *p, int PMV[2][2][2], int *dmvector, int mv_field_sel[2][2], int s, int mv_count,
                    int mv_format, int h_r_size, int v_r_size, int dmv, int mvscale)
{
    if (mv_count == 1) {
        if (mv_format == 0 && dmv == 0) {
            mv_field_sel[1][s] = mv_field_sel[0][s] = _nextBit(p, 1);
        }
        _motionVector(p, PMV[0][s], dmvector, h_r_size, v_r_size, dmv, mvscale, 0);
        PMV[1][s][0] = PMV[0][s][0];
        PMV[1][s][1] = PMV[0][s][1];
    } else {
        mv_field_sel[0][s] = _nextBit(p, 1);
        _motionVector(p, PMV[0][s], dmvector, h_r_size, v_r_size, dmv, mvscale, 0);
        mv_field_sel[1][s] = _nextBit(p, 1);
        _motionVector(p, PMV[1][s], dmvector, h_r_size, v_r_size, dmv, mvscale, 0);
    }
}

void _motionVector(MpegSys *p, int *PMV, int *dmvector, int h_r_size, int v_r_size, int dmv, int mvscale,
                   int full_pel)
{
    int motion_code;
    int motion_r;

    motion_code = _ipuVdec(p, 2);
    if (h_r_size != 0 && motion_code != 0) {
        motion_r = _nextBit(p, h_r_size);
    } else {
        motion_r = 0;
    }
    _decode_motion_vector(&PMV[0], h_r_size, motion_code, motion_r, full_pel);
    if (dmv != 0) {
        dmvector[0] = _dmVector(p);
    }
    motion_code = _ipuVdec(p, 2);
    if (v_r_size != 0 && motion_code != 0) {
        motion_r = _nextBit(p, v_r_size);
    } else {
        motion_r = 0;
    }
    if (mvscale != 0) {
        PMV[1] = PMV[1] >> 1;
    }
    _decode_motion_vector(&PMV[1], v_r_size, motion_code, motion_r, full_pel);
    if (mvscale != 0) {
        PMV[1] = PMV[1] * 2;
    }
    if (dmv != 0) {
        dmvector[1] = _dmVector(p);
    }
}

/* whether the top of the bit buffer is stale after each IPU command, by the
 * command's opcode (cmd >> 28) */
static int top32Dirty[10] = {1, 1, 0, 0, 0, 1, 1, 1, 1, 1}; /* derived name */

void _sendIpuCommand(MpegSys *p, unsigned int cmd)
{
    *IPU_CMD = cmd;
    p->isTop32dirty = top32Dirty[cmd >> 28];
}

void _waitIpuIdle(MpegSys *p)
{
    int n = 0;

    /* the IPU control register the hardware clears when the decode retires */
    while ((*IPU_CTRL & 0x80004000) == 0x80000000) {
        if (n++ >= 5001) {
            _dispatchMpegCbNodata(p->mp);
            n = 0;
        }
    }
}

long long _waitIpuIdle64(MpegSys *p)
{
    long long v;
    int n = 0;

    /* the 64 bit IPU command register: the top bit stays set while the
     * command is running, and 0x4000 of the control register at 0x10002010
     * is the error the decoder gives up on */
    while ((v = *(volatile long long *)IPU_CMD) < 0 && (*IPU_CTRL & 0x4000) == 0) {
        if (n++ >= 5001) {
            _dispatchMpegCbNodata(p->mp);
            n = 0;
        }
    }
    return v;
}

int _ipuVdec(MpegSys *p, int tbl)
{
    long long v;
    int cmd;
    int bp;
    long long top;
    int m = 0;
    int n = 0;

    while ((*IPU_CTRL & 0x80004000) == 0x80000000) {
        if (n++ >= 5001) {
            _dispatchMpegCbNodata(p->mp);
            n = 0;
        }
    }
    cmd = (tbl << 26) | 0x30000000;
    *IPU_CMD = cmd;
    p->isTop32dirty = top32Dirty[cmd >> 28];
    while ((v = *(volatile long long *)IPU_CMD) < 0) {
        if (m++ >= 5001) {
            _dispatchMpegCbNodata(p->mp);
            m = 0;
        }
    }
    bp = *IPU_BP;
    /* the IPU TOP register is read once, after the command above has retired,
     * so this read is not qualified: only the two busy-waits above need the
     * qualifier */
    top = *(long long *)IPU_TOP;
    p->top32 = top;
    if (top < 0) {
        p->top32len = (-(bp & 0x1F)) & 0x1F;
    } else {
        p->top32len = 32;
    }
    p->isError = ((int)v == 0);
    return (short)v;
}

int _peepBit(MpegSys *p, int bits)
{
    if (p->isTop32dirty != 0 || p->top32len < bits) {
        int n = 0;

        while ((*IPU_CTRL & 0x80004000) == 0x80000000) {
            if (n++ >= 5001) {
                _dispatchMpegCbNodata(p->mp);
                n = 0;
            }
        }
        *IPU_CMD = 0x40000000;
        p->isTop32dirty = top32Dirty[4];
        p->top32 = _waitIpuIdle64(p);
        p->top32len = 32;
    }
    return (unsigned int)p->top32 >> (32 - bits);
}

void _flushBuf(MpegSys *p, int bits)
{
    int n = 0;
    int cmd;

    while ((*IPU_CTRL & 0x80004000) == 0x80000000) {
        if (n++ >= 5001) {
            _dispatchMpegCbNodata(p->mp);
            n = 0;
        }
    }
    cmd = bits | 0x40000000;
    *IPU_CMD = cmd;
    p->isTop32dirty = top32Dirty[(unsigned int)cmd >> 28];
    p->top32 = _waitIpuIdle64(p);
    p->top32len = 32;
}

unsigned int _nextBit(MpegSys *p, int bits)
{
    int n = 0;
    int cmd;
    unsigned int r;

    while ((*IPU_CTRL & 0x80004000) == 0x80000000) {
        if (n++ >= 5001) {
            _dispatchMpegCbNodata(p->mp);
            n = 0;
        }
    }
    if (p->isTop32dirty != 0 || p->top32len < bits) {
        *IPU_CMD = 0x40000000;
        p->isTop32dirty = top32Dirty[4];
        p->top32 = _waitIpuIdle64(p);
    }
    r = (unsigned int)p->top32 >> (32 - bits);
    cmd = bits | 0x40000000;
    p->top32len = 32;
    *IPU_CMD = cmd;
    p->isTop32dirty = top32Dirty[(unsigned int)cmd >> 28];
    p->top32 = _waitIpuIdle64(p);
    return r;
}

void _nextStartCode(MpegSys *p)
{
    int v;
    _waitIpuIdle(p);
    v = (-(*IPU_BP & 7)) & 7;
    if (v)
        _flushBuf(p, v);
    while (_peepBit(p, 0x18) != 1) {
        _flushBuf(p, 8);
    }
}

int _sliceB(MpegSys *p)
{
    p->qscqsc = _nextBit(p, 5);
    if (_nextBit(p, 1) != 0) {
        _nextBit(p, 1); /* STA: SDK 2.5 drops intra_slice */
        _flushBuf(p, 7);
        _extrainfo(p);
    }
    return 0;
}

int _nextHeader(MpegSys *p)
{
    int buf[8];
    unsigned int code;

    for (;;) {
        _nextStartCode(p);
        code = _nextBit(p, 32);
        switch (code) {
        case 0x1B3:
            _sequenceHeader(p);
            break;
        case 0x1B8:
            _groupOfPicturesHeader(p);
            break;
        case 0x100:
            _pictureHeader(p);
            buf[0] = 5;
            *(long long *)&buf[2] = -1;
            *(long long *)&buf[4] = -1;
            _dispatchMpegCallback(p->mp, buf);
            p->headerPts = *(long long *)&buf[2];
            p->headerDts = *(long long *)&buf[4];
            return p->picture_coding_type;
        case 0x1B7:
            return 0;
        }
    }
}

void _pictureHeader(MpegSys *p)
{
    int tr;

    tr = _nextBit(p, 10);
    p->picture_coding_type = _nextBit(p, 3);
    _nextBit(p, 16); /* vbv_delay */
    if (p->picture_coding_type == 2 || p->picture_coding_type == 3) {
        p->full_pel_forward_vector = _nextBit(p, 1);
        p->forward_f_code = _nextBit(p, 3);
    }
    if (p->picture_coding_type == 3) {
        p->full_pel_backward_vector = _nextBit(p, 1);
        p->backward_f_code = _nextBit(p, 3);
    }
    _extrainfo(p);
    _extensionAndUserData(p);
    _updateTempTackData(p, tr);
}

/* the extension dispatch table, one entry per extension id, entry 0 is the
 * unknown-extension handler every id past the last known one falls back to */

void _extensionAndUserData(MpegSys *p)
{
    /* STA: SDK 2.5's handler table is a local, copied from .rodata */
    void (*extHandler[11])(MpegSys *) = {_unknown_extension,
        _sequenceExtension,
        _sequenceDisplayExtension,
        _quantMatrixExtension,
        _copyrightExtension,
        _sequenceScalableExtension,
        _unknown_extension,
        _pictureDisplayExtension,
        _pictureCodingExtension,
        _pictureSpatialScalableExtension,
        _pictureTemporalScalableExtension};
    int code;

    _nextStartCode(p);
    while ((code = _peepBit(p, 32)) == 0x1B5 || code == 0x1B2) {
        if (code == 0x1B5) {
            unsigned int id;

            _flushBuf(p, 32);
            id = _nextBit(p, 4);
            id = id > 10 ? 0 : id;
            extHandler[id](p);
            _nextStartCode(p);
        } else {
            _flushBuf(p, 32);
            _nextStartCode(p);
        }
    }
}

void _pictureCodingExtension(MpegSys *p)
{
    int v;

    p->f_code[0][0] = _nextBit(p, 4);
    p->f_code[0][1] = _nextBit(p, 4);
    p->f_code[1][0] = _nextBit(p, 4);
    p->f_code[1][1] = _nextBit(p, 4);
    v = _nextBit(p, 2); /* intra_dc_precision */
    *IPU_CTRL = (*IPU_CTRL & 0xFFFCFFFF) | (v << 16);
    p->picture_structure = _nextBit(p, 2);
    if (p->picStructure == 0) {
        p->picStructure = p->picture_structure;
    }
    p->top_field_first = _nextBit(p, 1);
    p->frame_pred_frame_dct = _nextBit(p, 1);
    p->concealment_motion_vectors = _nextBit(p, 1);
    v = _nextBit(p, 1); /* q_scale_type */
    *IPU_CTRL = (*IPU_CTRL & 0xFFBFFFFF) | (v << 22);
    v = _nextBit(p, 1); /* intra_vlc_format */
    *IPU_CTRL = (*IPU_CTRL & 0xFFDFFFFF) | (v << 21);
    v = _nextBit(p, 1); /* alternate_scan */
    *IPU_CTRL = (*IPU_CTRL & 0xFFEFFFFF) | (v << 20);
    p->repeat_first_field = _nextBit(p, 1);
    _nextBit(p, 1); /* chroma_420_type */
    p->progressive_frame = _nextBit(p, 1);
    if (_nextBit(p, 1) != 0) { /* composite_display_flag */
        _nextBit(p, 1);
        _nextBit(p, 3);
        _nextBit(p, 1);
        _nextBit(p, 7);
        _nextBit(p, 8);
    }
}

void _extrainfo(MpegSys *p)
{
    while (_nextBit(p, 1) != 0) {
        _flushBuf(p, 8);
    }
}

/* STA: SDK 2.5 made SDK 2.2's two statics locals, which leaves the wrap
   tracking inert */
/* STA: SDK 2.5 made SDK 2.2's two statics locals, which leaves the wrap
   tracking inert */
/* STA: SDK 2.5 made SDK 2.2's two statics locals, which leaves the wrap
   tracking inert */
/* STA: SDK 2.5 made SDK 2.2's two statics locals, which leaves the wrap
   tracking inert */
/* STA: SDK 2.5 made SDK 2.2's two statics locals, which leaves the wrap
   tracking inert */
/* STA: SDK 2.5 made SDK 2.2's two statics locals, which leaves the wrap
   tracking inert */
/* STA: SDK 2.5 made SDK 2.2's two statics locals, which leaves the wrap
   tracking inert */
/* STA: SDK 2.5 made SDK 2.2's two statics locals, which leaves the wrap
   tracking inert */
/* STA: SDK 2.5 made SDK 2.2's two statics locals, which leaves the wrap
   tracking inert */
/* STA: SDK 2.5 made SDK 2.2's two statics locals, which leaves the wrap
   tracking inert */
/* STA: SDK 2.5 made SDK 2.2's two statics locals, which leaves the wrap
   tracking inert */
void _updateTempTackData(MpegSys *p, int tr)
{
    int wrapped = 0; /* derived name */
    int lastRef = 0; /* derived name */

    if (p->picture_coding_type != 3 && tr != lastRef) {
        if (wrapped != 0) {
            wrapped = 0;
            p->tmpRefBase += 0x400;
        }
        if (tr < lastRef && p->tmpRefGOPreset == 0) {
            wrapped = 1;
        }
        p->tmpRefGOPreset = 0;
        lastRef = tr;
    }
    p->trFrameNumber = p->tmpRefBase + tr;
    if (wrapped != 0 && lastRef >= tr) {
        p->trFrameNumber = p->tmpRefBase + tr + 0x400;
    }
    p->trFrameNumberA = p->trFrameNumberA < p->trFrameNumber ? p->trFrameNumber : p->trFrameNumberA;
}

void _groupOfPicturesHeader(MpegSys *p)
{
    p->brokenLink = 0;
    p->tmpRefBase = p->trFrameNumberA + 1;
    p->tmpRefGOPreset = 1;
    _nextBit(p, 1); /* drop_frame_flag */
    _nextBit(p, 5); /* time_code_hours */
    _nextBit(p, 6); /* time_code_minutes */
    _nextBit(p, 1);
    _nextBit(p, 6); /* time_code_seconds */
    _nextBit(p, 6); /* time_code_pictures */
    p->closed_gop = _nextBit(p, 1);
    p->broken_link = _nextBit(p, 1);
    _extensionAndUserData(p);
}

void _quantMatrixExtension(MpegSys *p)
{
    if ((p->load_intra_quantizer_matrix = _nextBit(p, 1)) != 0) {
        _waitIpuIdle(p);
        _sendIpuCommand(p, 0x50000000);
        _waitIpuIdle(p);
    }
    if ((p->load_non_intra_quantizer_matrix = _nextBit(p, 1)) != 0) {
        _waitIpuIdle(p);
        _sendIpuCommand(p, 0x58000000);
        _waitIpuIdle(p);
    }
    if (_nextBit(p, 1) != 0) {
        _Error(p, "load_chroma_intra_quantizer_matrix == 1");
    }
    if (_nextBit(p, 1) != 0) {
        _Error(p, "load_chroma_non_intra_quantizer_matrix == 1");
    }
}

void _pictureDisplayExtension(MpegSys *p)
{
    int n;
    int i;

    if (p->progressive_sequence != 0) {
        if (p->repeat_first_field != 0) {
            n = p->top_field_first != 0 ? 3 : 2;
        } else {
            n = 1;
        }
    } else {
        if (p->picture_structure != 3) {
            n = 1;
        } else {
            n = p->repeat_first_field != 0 ? 3 : 2;
        }
    }
    for (i = 0; i < n; i++) {
        p->frame_center_horizontal_offset[i] = _nextBit(p, 16);
        _nextBit(p, 1);
        p->frame_center_vertical_offset[i] = _nextBit(p, 16);
        _nextBit(p, 1);
    }
}

/* STA: SDK 2.5 keeps none of the fields */
/* STA: SDK 2.5 keeps none of the fields */
/* STA: SDK 2.5 keeps none of the fields */
/* STA: SDK 2.5 keeps none of the fields */
/* STA: SDK 2.5 keeps none of the fields */
/* STA: SDK 2.5 keeps none of the fields */
/* STA: SDK 2.5 keeps none of the fields */
/* STA: SDK 2.5 keeps none of the fields */
void _copyrightExtension(MpegSys *p)
{
    _nextBit(p, 1); /* copyright_flag */
    _nextBit(p, 8); /* copyright_identifier */
    _nextBit(p, 1); /* original_or_copy */
    /* seven reserved bits, then the marker bit before each field */
    _nextBit(p, 7);
    _nextBit(p, 1);
    _nextBit(p, 20);
    _nextBit(p, 1);
    _nextBit(p, 22);
    _nextBit(p, 1);
    _nextBit(p, 22);
}

int _decPicture(MpegSys *p)
{
    int pq;
    int r;

    if (p->picture_structure == 3 && p->isSecondField != 0) {
        _Error(p, "odd number of field pictures");
        p->isSecondField = 0;
    }
    switch (p->picture_structure) {
    case 3:
        pq = (int)p->curFrame;
        break;
    case 1:
        pq = (int)p->curTop;
        break;
    case 2:
        pq = (int)p->curBot;
        break;
    default:
        pq = (int)p->curFrame;
        _Error(p, "unknown picture sutructure");
        break;
    }
    r = _pictureData0(p);
    if (r != 0) {
        *(int *)(pq + 0x28) = 1;
    }
    return r;
}

void _outputFrame(MpegSys *p, int frame, int refCount)
{
    MpegSys *pq = p;

    if (refCount != 0) {
        int *top;
        int *bot;

        if (p->picture_structure == 3) {
            if (p->picture_coding_type == 3) {
                top = p->zFrame;
            } else {
                top = p->forwFrame;
            }
            _dispRefImage(p, top, frame - 1);
        } else {
            if (p->picture_coding_type == 3) {
                top = p->zTop;
                bot = p->zBot;
            } else {
                top = p->forwTop;
                bot = p->forwBot;
            }
            _dispRefImageField(p, top, bot, frame - 1);
        }
    }
    if (pq->ptmState == 1) {
        pq->ptmState = 2;
    }
}

/* The reference images are record pointers.  The two 64-bit stamps are
   written through the record seen as long longs. */
int _updateRefImage(MpegSys *p, int second)
{
    int *out = 0;
    int ret = 0;
    int n = p->picture_structure == 3 ? 2 : 4;
    MpegSys *r = p;

    if (p->picture_coding_type == 3) {
        p->curFrame = p->zFrame;
        p->curTop = p->zTop;
        p->curBot = p->zBot;
        if (r->iCount + r->pCount >= n) {
            r->brokenLink = 0;
            p->broken_link = 0;
            p->closed_gop = 0;
        }
        if ((r->brokenLink != 0 || p->broken_link != 0) && p->closed_gop == 0) {
            p->forwFrame[0x28 / 4] = 0;
            p->forwTop[0x28 / 4] = 0;
            p->forwBot[0x28 / 4] = 0;
        }
        r->brokenLink = 0;
        p->broken_link = 0;
        if (p->picture_structure == 3) {
            if ((p->forwFrame[0x28 / 4] == 1 || p->closed_gop != 0) && p->backFrame[0x28 / 4] == 1) {
                ret = 1;
            }
        } else {
            if (((p->forwTop[0x28 / 4] == 1 && p->forwBot[0x28 / 4] == 1) || p->closed_gop != 0) &&
                p->backTop[0x28 / 4] == 1 && p->backBot[0x28 / 4] == 1) {
                ret = 1;
            }
        }
    } else {
        if (second == 0) {
            int *t;
            t = p->forwFrame;
            p->forwFrame = p->backFrame;
            p->backFrame = t;
            t = p->forwTop;
            p->forwTop = p->backTop;
            p->backTop = t;
            t = p->forwBot;
            p->forwBot = p->backBot;
            p->backBot = t;
        }
        p->curFrame = p->backFrame;
        p->curTop = p->backTop;
        p->curBot = p->backBot;
        if (p->picture_structure == 3) {
            if (p->picture_coding_type != 2 || p->forwFrame[0x28 / 4] == 1) {
                ret = 1;
            }
        } else {
            int *q = p->picture_structure == 1 ? p->backBot : p->backTop;
            if (p->picture_coding_type != 2 || (second != 0 && q[0x28 / 4] == 1) ||
                (p->forwTop[0x28 / 4] == 1 && p->forwBot[0x28 / 4] == 1)) {
                ret = 1;
            }
        }
    }
    switch (p->picture_structure) {
    case 3:
        out = p->curFrame;
        break;
    case 1:
        out = p->curTop;
        break;
    case 2:
        out = p->curBot;
        break;
    }
    out[0x28 / 4] = 0;
    ((long long *)out)[0x18 / 8] = p->headerPts;
    ((long long *)out)[0x20 / 8] = p->headerDts;
    out[0x2C / 4] = p->picture_coding_type;
    out[0x30 / 4] = p->picture_structure;
    out[0x34 / 4] = p->progressive_sequence;
    out[0x38 / 4] = p->progressive_frame;
    out[0x3C / 4] = p->top_field_first;
    out[0x40 / 4] = p->repeat_first_field;
    out[0x44 / 4] = p->frame_center_horizontal_offset[0];
    out[0x48 / 4] = p->frame_center_horizontal_offset[1];
    out[0x4C / 4] = p->frame_center_horizontal_offset[2];
    out[0x50 / 4] = p->frame_center_vertical_offset[0];
    out[0x54 / 4] = p->frame_center_vertical_offset[1];
    out[0x58 / 4] = p->frame_center_vertical_offset[2];
    out[0x5C / 4] = p->display_horizontal_size;
    out[0x60 / 4] = p->display_vertical_size;
    return ret;
}

int _isOutSizeOK(MpegSys *p, int *pq)
{
    MpegSys *c = p;
    int h = c->buffHeight;
    int flag;
    if (h != 0) {
        flag = c->buffWidth >= pq[0x4 / 4] && h >= pq[0x8 / 4];
    } else {
        flag = c->buffSize >= pq[0xC / 4] * pq[0x10 / 4];
    }
    if (flag == 0) {
        char buf[0x100];
        sprintf(buf, "Too small buffer size for %dx%d picture\n", pq[0x4 / 4], pq[0x8 / 4]);
        _Error(p, buf);
    }
    return flag;
}

void _cpr8(MpegSys *p, int *im)
{
    int sstride;
    int n;
    int j;
    MpegSys *r = p;
    int dstride;
    int src = im[0] & 0x0FFFFFFF;
    int qwc;
    int e;
    int dst = r->imageBuff & 0x0FFFFFFF;
    int i;

    if (p->picture_structure == 3 || r->buffHeight == 0) {
        e = r->buffHeight;
        sstride = im[0x10 / 4] * 0x180;
        qwc = sstride >> 4;
        if (e != 0) {
            dstride = (e >> 4) * 0x180;
        } else {
            dstride = sstride;
        }
        n = 1;
    } else {
        e = r->buffHeight;
        sstride = (im[0x10 / 4] >> 1) * 0x180;
        qwc = sstride >> 4;
        dstride = (e >> 4) * 0xC0;
        n = 2;
    }
    for (j = 0; j < n; j++) {
        int d = dst;

        for (i = 0; i < im[0xC / 4]; i++) {
            int intr;

            intr = DIntr();
            *D9_SADR = 0;
            *D9_MADR = src;
            *D9_QWC = qwc;
            *D9_CHCR = 0x101;
            if (intr) {
                EIntr();
            }
            while (*D9_CHCR & 0x100) {}
            intr = DIntr();
            *D8_SADR = 0;
            *D8_MADR = d;
            *D8_QWC = qwc;
            *D8_CHCR = 0x100;
            if (intr) {
                EIntr();
            }
            while (*D8_CHCR & 0x100) {}
            while (*D8_QWC != 0) {}
            d += dstride;
            src += sstride;
        }
        dst += r->buffSize * 0xC0;
    }
}

int _markOutput(MpegSys *p)
{
    int ret = 1;

    if (p->outState != 2) {
        p->outState = 2;
        p->frameBase = p->totalFrames;
    }
    p->isOutputPicture = ret;
    return ret;
}

void _getPtsDtsFlags(MpegSys *p, int *img, long long *pts, long long *dts, long long *flags)
{
    MpegSys *s = p;
    long long t;
    int show;
    int last;
    int carry;

    if (s->usePtsGap != 0) {
        t = *(long long *)&img[0x18 / 4];
        if (t < 0 && (last = s->lastPts) >= 0) {
            show = (int)s->lastShow;
            carry = (int)((long long)(show & 1) * (s->ptsGap & 1) * (s->halfCount & 1));
            *pts = last + ((int)((s->ptsGap * show) >> 1) + carry);
            if ((long long)(show & 1) * (s->ptsGap & 1) != 0) {
                s->halfCount = s->halfCount + 1;
            }
        } else {
            *pts = t;
        }
    } else {
        *pts = *(long long *)&img[0x18 / 4];
    }
    if (s->ptmState == 2) {
        long long v = s->ptm;

        if (v >= 0) {
            *pts = v;
            s->ptmState = 0;
            s->ptm = -1;
        }
    }
    *dts = *(long long *)&img[0x20 / 4];
    *flags = ((long long)img[0x34 / 4] << 8) | ((long long)img[0x38 / 4] << 7) |
             ((long long)img[0x3C / 4] << 6) | ((long long)img[0x40 / 4] << 5) |
             ((long long)img[0x30 / 4] << 3) | img[0x2C / 4];
}

/* the display count of a picture by its repeat and field flags */
unsigned int _showCount[16] = {2, 0, 2, 0, 2, 3, 2, 3, 0, 0, 0, 0, 2, 4, 0, 6};

void _dispRefImage(MpegSys *p, int *img, int frame)
{
    MpegSys *r = p;

    _getPtsDtsFlags(p, img, &p->mp->pts, &p->mp->dts, &p->mp->flags);
    r->lastPts = p->mp->pts;
    r->lastShow = _showCount[(int)(p->mp->flags >> 5) & 0xF];
    r->dispWidth = img[0x5C / 4];
    r->dispHeight = img[0x60 / 4];
    r->centerOffX[0] = img[0x44 / 4];
    r->centerOffX[1] = img[0x48 / 4];
    r->centerOffX[2] = img[0x4C / 4];
    r->centerOffY[0] = img[0x50 / 4];
    r->centerOffY[1] = img[0x54 / 4];
    r->centerOffY[2] = img[0x58 / 4];
    if (_isOutSizeOK(p, img) != 0 && img[0x28 / 4] == 1) {
        if (r->csc != 0) {
            _csc_storeRefImage(r, img); /* STA: SDK 2.5 csc */
        } else {
            _cpr8(p, img);
        }
        _markOutput(p);
    }
}

/* a field pair goes out as one frame: both fields' stamps on the handle, and
 * the stamp, show count and output geometry in the decoder record */
void _dispRefImageField(MpegSys *p, int *top, int *bot, int frame)
{
    MpegSys *r = p;
    int *f;
    int *s;
    int m = 0;

    if (p->picture_structure == 2) {
        f = top;
        s = bot;
        m = 0x40;
    } else {
        f = bot;
        s = top;
    }
    _getPtsDtsFlags(p, f, &p->mp->pts, &p->mp->dts, &p->mp->flags);
    r->lastPts = p->mp->pts;
    r->lastShow = 1;
    _getPtsDtsFlags(p, s, &p->mp->pts2nd, &p->mp->dts2nd, &p->mp->flags2nd);
    r->lastPts = p->mp->pts2nd;
    r->lastShow = 1;
    p->mp->flags |= m;
    p->mp->flags2nd |= m;
    r->dispWidth = f[0x5C / 4];
    r->dispHeight = f[0x60 / 4];
    r->centerOffX[0] = f[0x44 / 4];
    r->centerOffX[1] = s[0x48 / 4];
    r->centerOffY[0] = f[0x50 / 4];
    r->centerOffY[1] = s[0x54 / 4];
    if (_isOutSizeOK(p, top) != 0 && top[0x28 / 4] == 1 && bot[0x28 / 4] == 1) {
        top[0x10 / 4] = top[0x10 / 4] * 2;
        if (r->csc != 0) {
            _csc_storeRefImage(r, top); /* STA: SDK 2.5 csc */
        } else {
            _cpr8(p, top);
        }
        top[0x10 / 4] = top[0x10 / 4] >> 1;
        _markOutput(p);
    }
}

/* STA: SDK 2.5 moved the reference fetch's DMA chain out of _motionComp0:
   the chain lives in the member's .bss and channel 9 (to scratchpad) runs it
   with interrupts off */
static long long sprTagBuf[64] __attribute__((aligned(64))); /* derived name; DMA tags, cache-line aligned */

/* TODO(STA): TEMPORARY inline asm, to be removed: retail's instructions for
   _sendRefTags, which the
   C below reproduces but for its i/tag register choice.  The C, kept for
   the next attempt:

   void _sendRefTags(MpegSys *p) /* derived name * /
   {
       long long *tag = (long long *)(((int)sprTagBuf & 0x0FFFFFFF) | 0x20000000);
       int cnt = p->mbcont.rec[p->mbcont.cur].count;
       int i;
       int intr;

       for (i = 0; i < cnt; i++) {
           int id;
           long long a1;
           tag[0] = ((long long)((int)p->mbcont.rec[p->mbcont.cur].srcAddr[0][i] & 0x0FFFFFFF) << 32) | (3 << 28) | 0x30;
           a1 = (long long)((int)p->mbcont.rec[p->mbcont.cur].srcAddr[1][i] & 0x0FFFFFFF) << 32;
           id = i == cnt - 1 ? 0 : 3;
           tag[2] = a1 | ((long long)id << 28) | 0x30;
           tag += 4;
       }
       __asm__ __volatile__("sync");
       intr = DIntr();
       *D9_SADR = p->mbcont.rec[p->mbcont.cur].refBuf;
       *D9_TADR = (int)sprTagBuf;
       *D9_QWC = 0;
       *D9_CHCR = 0x105;
       if (intr) {
           EIntr();
       }
   }
*/
__asm__(".section .text\n"
        "    .set noat\n"
        "    .set noreorder\n"
        "    .align 3\n"
        "    .globl _sendRefTags\n"
        "    .type _sendRefTags, @function\n"
        "_sendRefTags:\n"
        "      addiu      $29, $29, -0x40\n"
        "      addiu      $5, $0, 0x140\n"
        "      sd         $18, 0x20($29)\n"
        "      lui        $2, (0xFFFFFFF >> 16)\n"
        "      sd         $16, 0x0($29)\n"
        "      lui        $18, %hi(sprTagBuf)\n"
        "      sd         $31, 0x30($29)\n"
        "      daddu      $16, $4, $0\n"
        "      sd         $17, 0x10($29)\n"
        "      addiu      $4, $18, %lo(sprTagBuf)\n"
        "      ori        $2, $2, (0xFFFFFFF & 0xFFFF)\n"
        "      daddu      $11, $0, $0\n"
        "      lw         $24, 0x810($16)\n"
        "      and        $4, $4, $2\n"
        "      mult       $3, $24, $5\n"
        "      addu       $5, $3, $16\n"
        "      lui        $3, (0x20000010 >> 16)\n"
        "      lw         $12, 0x6BC($5)\n"
        "      blez       $12, .L001080A8\n"
        "       or        $10, $4, $3\n"
        "      addiu      $15, $16, 0x598\n"
        "      addiu      $14, $16, 0x5A8\n"
        "      addiu      $13, $12, -0x1\n"
        "      addiu      $17, $16, 0x590\n"
        "  .L00108028:\n"
        "      addiu      $3, $0, 0x140\n"
        "      xor        $2, $11, $13\n"
        "      mult       $3, $24, $3\n"
        "      sll        $4, $11, 2\n"
        "      addiu      $5, $0, 0x3\n"
        "      lui        $6, (0xFFFFFFF >> 16)\n"
        "      movz       $5, $0, $2\n"
        "      ori        $6, $6, (0xFFFFFFF & 0xFFFF)\n"
        "      dsll       $5, $5, 28\n"
        "      lui        $9, (0x30000030 >> 16)\n"
        "      ori        $9, $9, (0x30000030 & 0xFFFF)\n"
        "      addu       $4, $4, $3\n"
        "      addiu      $8, $0, 0x30\n"
        "      addu       $2, $14, $4\n"
        "      addiu      $11, $11, 0x1\n"
        "      lw         $3, 0x0($2)\n"
        "      addu       $4, $15, $4\n"
        "      lw         $2, 0x0($4)\n"
        "      slt        $7, $11, $12\n"
        "      and        $3, $3, $6\n"
        "      and        $2, $2, $6\n"
        "      dsll32     $3, $3, 0\n"
        "      or         $3, $3, $5\n"
        "      dsll32     $2, $2, 0\n"
        "      or         $2, $2, $9\n"
        "      or         $3, $3, $8\n"
        "      sd         $2, (0x20000000 & 0xFFFF)($10)\n"
        "      sd         $3, (0x20000010 & 0xFFFF)($10)\n"
        "      bnez       $7, .L00108028\n"
        "       addiu     $10, $10, (0x20000020 & 0xFFFF)\n"
        "      b          .L001080AC\n"
        "       nop\n"
        "  .L001080A8:\n"
        "      addiu      $17, $16, 0x590\n"
        "  .L001080AC:\n"
        "      jal        DIntr\n"
        "       nop\n"
        "      sync\n"
        "      lw         $6, 0x810($16)\n"
        "      addiu      $3, $0, 0x140\n"
        "      lui        $7, (0x1000D480 >> 16)\n"
        "      lui        $8, (0x1000D430 >> 16)\n"
        "      mult       $4, $6, $3\n"
        "      ori        $7, $7, (0x1000D480 & 0xFFFF)\n"
        "      addiu      $10, $18, %lo(sprTagBuf)\n"
        "      ori        $8, $8, (0x1000D430 & 0xFFFF)\n"
        "      lui        $3, (0x1000D420 >> 16)\n"
        "      addiu      $9, $0, 0x105\n"
        "      ori        $3, $3, (0x1000D420 & 0xFFFF)\n"
        "      addu       $6, $4, $17\n"
        "      lw         $5, 0x0($6)\n"
        "      lui        $4, (0x1000D400 >> 16)\n"
        "      ori        $4, $4, (0x1000D400 & 0xFFFF)\n"
        "      sw         $5, 0x0($7)\n"
        "      sw         $10, 0x0($8)\n"
        "      sw         $0, 0x0($3)\n"
        "      sw         $9, 0x0($4)\n"
        "      beqz       $2, .L00108120\n"
        "       ld        $31, 0x30($29)\n"
        "      ld         $18, 0x20($29)\n"
        "      ld         $17, 0x10($29)\n"
        "      ld         $16, 0x0($29)\n"
        "      j          EIntr\n"
        "       addiu     $29, $29, 0x40\n"
        "  .L00108120:\n"
        "      ld         $18, 0x20($29)\n"
        "      ld         $17, 0x10($29)\n"
        "      ld         $16, 0x0($29)\n"
        "      jr         $31\n"
        "       addiu     $29, $29, 0x40\n"
        "    .size _sendRefTags, . - _sendRefTags\n"
        "    .set reorder\n"
        "    .set at\n");

/* STA: SDK 2.5: channel 3 (from the IPU) into scratchpad */
void _ipuToSpr(int addr, int size) /* derived name */
{
    int intr = DIntr();

    *D3_MADR = (addr & 0x0FFFFFFF) | 0x80000000;
    *D3_QWC = size >> 4;
    *D3_CHCR = 0x100;
    if (intr) {
        EIntr();
    }
}
