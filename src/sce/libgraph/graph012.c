/* libgraph.a member graph012.o */
#include <eekernel.h>
#include <stdio.h>
#include <eeregs.h>

#define GS_SYNCPATH_DUMP()                                                                         \
    scePrintf("\t<D1_CHCR=%08x:", *D1_CHCR);                                                          \
    scePrintf("D1_TADR=%08x:", *D1_TADR);                                                             \
    scePrintf("D1_MADR=%08x:", *D1_MADR);                                                             \
    scePrintf("D1_QWC=%08x>\r\n", *D1_QWC);                                                           \
    scePrintf("\t<D2_CHCR=%08x:", *D2_CHCR);                                                          \
    scePrintf("D2_TADR=%08x:", *D2_TADR);                                                             \
    scePrintf("D2_MADR=%08x:", *D2_MADR);                                                             \
    scePrintf("D2_QWC=%08x>\r\n", *D2_QWC);                                                           \
    scePrintf("\t<VIF1_STAT=%08x:", *VIF1_STAT);                                                      \
    scePrintf("GIF_STAT=%08x>\r\n", *GIF_STAT);                                                       \
    return -1

int sceGsSyncPath(int mode, unsigned short timeout)
{
    unsigned int i = 0;
    int r;
    int v;

    if (mode == 0) {
        while (*D1_CHCR & 0x100) {
            if (i++ > 0x1000000) {
                scePrintf("sceGsSyncPath: DMA Ch.1 does not terminate\r\n");
                GS_SYNCPATH_DUMP();
            }
        }
        while (*D2_CHCR & 0x100) {
            if (i++ > 0x1000000) {
                scePrintf("sceGsSyncPath: DMA Ch.2 does not terminate\r\n");
                GS_SYNCPATH_DUMP();
            }
        }
        while (*VIF1_STAT & 0x1F000003) {
            if (i++ > 0x1000000) {
                scePrintf("sceGsSyncPath: VIF1 does not terminate\r\n");
                GS_SYNCPATH_DUMP();
            }
        }
        __asm__ __volatile__("cfc2.ni %0, $vi29" : "=r"(v));
        while (v & 0x100) {
            if (i++ > 0x1000000) {
                scePrintf("sceGsSyncPath: VU1 does not terminate\r\n");
                GS_SYNCPATH_DUMP();
            }
            __asm__ __volatile__("cfc2.ni %0, $vi29" : "=r"(v));
        }
        while (*GIF_STAT & 0xC00) {
            if (i++ > 0x1000000) {
                scePrintf("sceGsSyncPath: GIF does not terminate\r\n");
                GS_SYNCPATH_DUMP();
            }
        }
        return 0;
    }
    r = 0;
    if (*D1_CHCR & 0x100) {
        r |= 1;
    }
    if (*D2_CHCR & 0x100) {
        r |= 2;
    }
    if (*VIF1_STAT & 0x1F000003) {
        r |= 4;
    }
    __asm__ __volatile__("cfc2.ni %0, $vi29" : "=r"(v));
    if (v & 0x100) {
        r |= 8;
    }
    if (*GIF_STAT & 0xC00) {
        r |= 0x10;
    }
    return r;
}
