#include "m2c.h"
typedef struct { s32 next; s32 len; s32 f8; s32 dsz; } Ent;
typedef struct { s8 *src; s8 *dst; s32 len; s32 z; } Req;
s8 *func_0015ABD0(s32);
s32 func_0015A300(s8 *);
s32 *func_00122C88(s32, s32);
void func_0015AB80(s8 *);
void func_0015A080(s32, s32 *, s32);
s8 *sceSifAllocIopHeap(s32);
void sceSifSetDma(Req *, s32);
void sceSifLoadModuleBuffer(s8 *, s32, s32);
void sceSifFreeSysMemory(s8 *);
void func_00122F10(s32 *);

void func_0015C9F0(s32 a0) {
    s32 *buf;
    s32 n;
    Ent *e;
    s32 i;
    s8 *src;
    s32 len;
    s8 *mem;
    s8 *h;
    s32 sz;
    Req r;

    h = func_0015ABD0(a0);
    sz = func_0015A300(h);
    buf = func_00122C88(0x40, sz);
    func_0015AB80(h);
    func_0015A080(a0, buf, sz);
    switch (buf[0]) {
    case 0x53585249:
        n = *(u16 *)((s8 *)buf + 0xC);
        e = (Ent *)((s8 *)buf + 0x10);
        for (i = 0; i < n; i++) {
            src = (s8 *)((s32)(e + 1) + ((e->dsz + 15) & ~15));
            len = e->len;
            mem = sceSifAllocIopHeap((len + 63) & ~63);
            r.src = src;
            r.dst = mem;
            r.len = len;
            r.z = 0;
            sceSifSetDma(&r, 1);
            sceSifLoadModuleBuffer(mem, 0, 0);
            sceSifFreeSysMemory(mem);
            e = (Ent *)((s8 *)e + e->next);
        }
        break;
    }
    func_00122F10(buf);
}
