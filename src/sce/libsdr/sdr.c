/* libsdr.a, the EE side of the IOP sound library's remote interface
 * (SAB: not in ICO or kfiv-decomp; written from this game's bytes).  The
 * archive's member boundaries in this build are not known, so this file is
 * its whole run: the RPC bind, the EE-to-IOP DMA helper, the end-function
 * setter and sceSdRemote, which marshals a libsd call into one RPC. */
#include <eekernel.h>
#include <stdio.h>
#include <sifrpc.h>
#include <sifcmd.h>

/* the member's .data in link order: the build stamp, the end function
   asynchronous calls hand the RPC, and the callbacks the IOP's interrupt
   handlers name (sceSdRemote records the ones its calls install) */
static char sceSdrVersion[16] = "PsIIlibsdr  2500"; /* derived name */
static sceSifEndFunc sdr_end_func = 0;              /* derived name */
/* SAB: scalars, not arrays: ee-gcc gives a .data array eight-byte alignment */
static int sdr_unused0 = 0;  /* derived name; no code here reads these four */
static int sdr_unused1 = 0;  /* derived name */
static int sdr_unused2 = 0;  /* derived name */
static int sdr_unused3 = 0;  /* derived name */
static void *sdr_trans_cb0 = 0;  /* derived name; core 0 */
static void *sdr_trans_cb1 = 0;  /* derived name; core 1 */
static void *sdr_spu2_cb = 0;    /* derived name */
static void *sdr_trans_arg0 = 0; /* derived name; core 0 */
static void *sdr_trans_arg1 = 0; /* derived name; core 1 */
static void *sdr_spu2_arg = 0;                      /* derived name */

/* .bss: the DMA request, a buffer no code here touches, the RPC buffer (a
   cache line) and the client */
static sceSifDmaData sdr_dma;                                    /* derived name */
static unsigned int sdr_unused_buf[64] __attribute__((aligned(64))); /* derived name */
static unsigned int sdr_buf[16] __attribute__((aligned(64)));    /* derived name */
static sceSifRpcClientData sdr_cd;                               /* derived name */

int sceSdRemoteInit(void)
{
    int i;

    sceSifInitRpc(0);
    while (1) {
        if (sceSifBindRpc(&sdr_cd, 0x80000701, 0) < 0) {
            scePrintf("sceSdRemoteInit() RPC bind error!\n");
            return -1;
        }
        i = 10000;
        while (i--)
            ;
        if (sdr_cd.serve != 0) {
            break;
        }
    }
    FlushCache(0);
    return 0;
}

int sceSdTransToIOP(void *buff, unsigned int sendAddr, unsigned int size, unsigned int isBlock)
{
    unsigned int did;

    if (isBlock == 0) {
        return -1;
    }
    sdr_dma.src = (unsigned int)buff;
    sdr_dma.dest = sendAddr;
    sdr_dma.size = size;
    sdr_dma.u.attr = 0;
    did = sceSifSetDma(&sdr_dma, 1);
    if (did == 0) {
        return -1;
    }
    if (isBlock == 1) {
        while (sceSifDmaStat(did) >= 0)
            ;
    }
    return 0;
}

sceSifEndFunc sceSdRemoteSetEndFunc(sceSifEndFunc func)
{
    sceSifEndFunc old = sdr_end_func;

    sdr_end_func = func;
    return old;
}

/* the EE's va_list: the register save area, eight bytes a slot; the seven
   argument registers after arg are saved below __builtin_next_arg's answer */
#define SDR_VA_ARG(ap) (*(int *)(((ap) += 8) - 8))

int sceSdRemote(int arg, ...)
{
    char *ap;
    int command, i, mode, ret;
    sceSifEndFunc end;
    int unused[4];

    end = 0;
    ap = (char *)__builtin_next_arg(arg) - 0x38;
    command = SDR_VA_ARG(ap);
    sdr_buf[0] = (unsigned int)sdr_buf;
    {
        unsigned int *p = &sdr_buf[1];
        for (i = 0; i < 6; i++) {
            *p++ = SDR_VA_ARG(ap);
        }
    }
    mode = 0;
    if (arg == 0) {
        mode = 1;
        end = sdr_end_func;
    }

    if (command == 0x8160) {
        if (sdr_buf[1] == 0) {
            sdr_trans_cb0 = (void *)sdr_buf[2];
            sdr_trans_arg0 = (void *)sdr_buf[3];
        } else {
            sdr_trans_cb1 = (void *)sdr_buf[2];
            sdr_trans_arg1 = (void *)sdr_buf[3];
        }
    } else if (command == 0x8170) {
        sdr_spu2_cb = (void *)sdr_buf[1];
        sdr_spu2_arg = (void *)sdr_buf[2];
    }

    if (command == 0x8130 || command == 0x81A0 || command == 0x81B0) {
        sceSifCallRpc(&sdr_cd, command | sdr_buf[1], mode, (void *)sdr_buf[2], 0x40, sdr_buf, 0x40, end,
                      (void *)sdr_buf[0]);
        ret = sdr_buf[0];
    } else if (command == 0x8140) {
        sceSifCallRpc(&sdr_cd, sdr_buf[1] | 0x8140, mode, sdr_buf, 0x40, (void *)sdr_buf[2], 0x40, end,
                      (void *)sdr_buf[2]);
    } else if ((unsigned int)(command - 0x9000) <= 0xF0) {
        sceSifCallRpc(&sdr_cd, command, mode, (void *)sdr_buf[1], sdr_buf[2], sdr_buf, 0x10, end, sdr_buf);
        ret = sdr_buf[0];
    } else {
        sceSifCallRpc(&sdr_cd, command, mode, sdr_buf, 0x40, sdr_buf, 0x10, end, sdr_buf);
        ret = sdr_buf[0];
    }
    return ret;
}
