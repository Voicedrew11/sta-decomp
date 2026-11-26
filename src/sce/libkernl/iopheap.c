/* libkernl.a(iopheap.o) */

#include <sifrpc.h>
#include <string.h>
#include <sifcmd.h>

/* iopheap.o's .data: -1 until sceSifInitIopHeap has bound the server */
static int iopheap_bind = -1; /* derived name */

/* the member's .bss: the heap server's client record and the RPC buffers,
   each on its own 64-byte DMA line */
static sceSifRpcClientData heapClient __attribute__((aligned(64))); /* derived name */
static int heapRecv __attribute__((aligned(64)));                   /* derived name */
/* STA: SDK 2.5 has one argument block for every call (three words for
   sceSifAllocSysMemory) */
static int heapArg[3] __attribute__((aligned(64)));                 /* derived name */

int sceSifInitIopHeap(void)
{
    int i;
    int ret;
    int val;
    for (;;) {
        ret = sceSifBindRpc(&heapClient, 0x80000003, 0);
        if (ret < 0)
            return -1;
        val = heapClient.serve;
        if (val != 0) {
            iopheap_bind = 0;
            break;
        }
        /* IOP-side retry back-off: spin 0x100000 times, no memory touched. */
        i = 0x100000;
        do {
            i--;
        } while (i != -1);
    }
    return 0;
}

int sceSifAllocIopHeap(int size)
{
    int ret = iopheap_bind;
    if (ret < 0)
        return 0;
    heapArg[0] = size;
    ret = sceSifCallRpc(&heapClient, 1, 0, heapArg, 4, &heapRecv, 4, 0, 0);
    if (ret >= 0)
        return heapRecv;
    return 0;
}

/* STA: new in SDK 2.5 */
void *sceSifAllocSysMemory(int type, int size, void *addr)
{
    int ret = iopheap_bind;
    if (ret < 0)
        return 0;
    heapArg[0] = size;
    heapArg[1] = type;
    heapArg[2] = (int)addr;
    ret = sceSifCallRpc(&heapClient, 4, 0, heapArg, 0xC, &heapRecv, 4, 0, 0);
    if (ret >= 0)
        return (void *)heapRecv;
    return 0;
}

int sceSifFreeIopHeap(int addr)
{
    int v2 = iopheap_bind;
    if (v2 < 0)
        return 0;
    heapArg[0] = addr;
    v2 = sceSifCallRpc(&heapClient, 2, 0, heapArg, 4, &heapRecv, 4, 0, 0);
    if (v2 < 0)
        return -1;
    return heapRecv;
}

/* The LoadIopHeap RPC request block: the address argument at offset 0, the
 * module name copied in at offset 4, and i + 5 bytes sent, so the record is
 * one int followed by a 252-byte name and the sent length is the name length
 * plus the int plus the terminator. */
/* STA: new in SDK 2.5 */
int sceSifFreeSysMemory(int addr)
{
    return sceSifFreeIopHeap(addr);
}

typedef struct {    /* field names derived */
    int addr;       /* 0x00 */
    char name[252]; /* 0x04 */
} SifHeapReq;       /* derived name */

/* the LoadIopHeap RPC's send buffer, on its own 64-byte DMA line like the
   buffers above */
static SifHeapReq heapLoadReq __attribute__((aligned(64))); /* derived name */

int sceSifLoadIopHeap(char *name, void *addr)
{
    int i;

    if (iopheap_bind < 0) {
        return 0;
    }
    /* the terminator test reads the byte back out of the destination */
    for (i = 0; i < 252; i++) {
        heapLoadReq.name[i] = name[i];
        if (heapLoadReq.name[i] == 0) {
            break;
        }
    }
    if (i == 252) {
        heapLoadReq.name[251] = 0;
        i = 251;
    }
    heapLoadReq.addr = (int)addr;
    heapLoadReq.name[251] = 0;
    if (sceSifCallRpc(&heapClient, 3, 0, &heapLoadReq, i + 5, &heapRecv, 4, 0, 0) >= 0) {
        return heapRecv;
    }
    return -1;
}

/* STA: the SDK 2.5 queries (calls 5 to 9) */
unsigned int sceSifQueryMemSize(void)
{
    if (iopheap_bind < 0)
        return 0;
    if (sceSifCallRpc(&heapClient, 5, 0, 0, 0, &heapRecv, 4, 0, 0) < 0)
        return -1;
    return heapRecv;
}

unsigned int sceSifQueryMaxFreeMemSize(void)
{
    if (iopheap_bind < 0)
        return 0;
    if (sceSifCallRpc(&heapClient, 6, 0, 0, 0, &heapRecv, 4, 0, 0) < 0)
        return -1;
    return heapRecv;
}

unsigned int sceSifQueryTotalFreeMemSize(void)
{
    if (iopheap_bind < 0)
        return 0;
    if (sceSifCallRpc(&heapClient, 7, 0, 0, 0, &heapRecv, 4, 0, 0) < 0)
        return -1;
    return heapRecv;
}

unsigned int sceSifQueryBlockTopAddress(void *addr)
{
    if (iopheap_bind < 0)
        return 0;
    heapArg[0] = (int)addr;
    if (sceSifCallRpc(&heapClient, 8, 0, heapArg, 4, &heapRecv, 4, 0, 0) < 0)
        return -1;
    return heapRecv;
}

unsigned int sceSifQueryBlockSize(void *addr)
{
    if (iopheap_bind < 0)
        return 0;
    heapArg[0] = (int)addr;
    if (sceSifCallRpc(&heapClient, 9, 0, heapArg, 4, &heapRecv, 4, 0, 0) < 0)
        return -1;
    return heapRecv;
}
