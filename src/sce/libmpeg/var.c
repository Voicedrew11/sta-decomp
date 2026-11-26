/* libmpeg.a(var.o).  No code.  SAB: SDK 2.5 keeps the decoder state in the
 * decoder record (MpegSys), so the member holds only the default quantizer
 * matrices.  The default intra matrix is 64-byte aligned for its DMA to the
 * IPU. */
#include <eeregs.h>
#include <libmpeg.h>
#include <libmpeg_internal.h>

/* the default intra matrix, which _setDefaultQM sends to the IPU by DMA
   channel 4; on its own 64-byte line */
unsigned char _defIQM[64] __attribute__((aligned(64))) = {
    8,  16, 16, 19, 16, 19, 22, 22, 22, 22, 22, 22, 26, 24, 26, 27, 27, 27, 26, 26, 26, 26,
    27, 27, 27, 29, 29, 29, 34, 34, 34, 29, 29, 29, 27, 27, 29, 29, 32, 32, 34, 34, 37, 38,
    37, 35, 35, 34, 35, 38, 38, 40, 40, 40, 48, 48, 46, 46, 56, 56, 58, 69, 69, 83};

unsigned char _defNIQM[64] = {16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
                              16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
                              16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
                              16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16};
