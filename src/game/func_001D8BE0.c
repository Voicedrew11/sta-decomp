#include "common.h"

extern char D_004B7840[];
extern char D_004B7C40[];
extern char D_004B7C90[];
void *func_001D8AB0(s32 fno, void *data, s32 size);
void sceSifInitRpc(u32 mode);
s32 GetThreadId(void);
void sceSifSetRpcQueue(void *q, s32 thread);
void sceSifRegisterRpc(void *serve, s32 cmd, void *(*func)(s32, void *, s32), void *buf, void *cfunc, void *cbuf, void *q);
void *sceSifRpcLoop(void *q);

void func_001D8BE0(void)
{
    sceSifInitRpc(0);
    sceSifSetRpcQueue(D_004B7C90, GetThreadId());
    sceSifRegisterRpc(D_004B7C40, 0x102A, func_001D8AB0, D_004B7840, NULL, NULL, D_004B7C90);
    sceSifRpcLoop(D_004B7C90);
}
