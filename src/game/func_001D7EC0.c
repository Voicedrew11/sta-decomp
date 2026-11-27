#include "common.h"
#include "include_asm.h"
typedef struct { s32 status; void *entry; void *stack; s32 stackSize; void *gpReg; s32 initPriority; s32 currentPriority; u32 attr; u32 option; s32 waitType; s32 waitId; s32 wakeupCount; } TP;
typedef char *va_list;
typedef struct { u8 pad[0x24]; void *serve; u8 pad28[0x8]; } CD;
extern char D_001FE6C0[];
extern s32 D_004B9EF0[];
extern u8 D_004B7A40[];
extern u8 D_004B7CB0[];
extern s32 D_00201E38;
extern s32 D_00202300;
extern s32 _gp;
extern int D_004B7EB0[];
extern s32 D_002022FC;
extern s32 D_004B7C40[];
extern s32 D_004B7C90[];
extern s32 D_004B7A40__as_func_001D8340[];
extern s32 D_004B7A40__as_func_001D8350[];
extern s32 D_004B7A40__as_func_001D84F0[];
extern u8 D_004B9EF0__as_func_001D8680[];
extern CD D_004B9EF0__as_func_001D8890;
extern s32 D_004B7A40__as_func_001D8960[];
extern char D_004B7840[];
void func_001D7EC0(void);
void func_001D7FD0(void);
void func_001D80C0(s32 d, s32 e);
s32 func_001D80E0(s32 size);
s32 func_001D8210(void);
void func_001D8320(int index, int value);
s32* func_001D8340(void);
s32 func_001D8350(s32 a, s32 b, s32 c, s32 d, s32 e, void *src);
s32 func_001D84F0(s32 a, s32 b, s32 c, s32 d);
s32 func_001D85D0(s32 a0, s32 a1, s32 a2);
s32 func_001D8680(s32 a, s32 b, s32 c, ...);
void func_001D87F0(s32 a, u16 b, u16 c);
s32 func_001D8810(void);
s32 func_001D8820(void);
s32 func_001D8890(void);
s32 func_001D8960(s32 a, s32 b, s32 c, s32 d, u32 e);
void func_001D8BE0(void);
s32 printf(const char*, ...);
s32 sceSifCheckStatRpc(void *);
s32 sceSifAllocIopHeap(s32);
s32 CreateThread(TP *);
s32 StartThread(s32, void *);
void DeleteThread(s32);
void TerminateThread(s32);
void sceSifRemoveRpc(s32 *, s32 *);
void sceSifRemoveRpcQueue(s32 *);
s32 sceSifBindRpc(CD *, u32, s32);
void sceSifCallRpc(void *, u32, u32, void *, s32, void *, s32, void *, void *);
s32 func_001D8960__as_func_001D7EC0(s32, s32, s32, s32, s32);
s32 func_001D8960__as_func_001D7FD0(s32, s32, s32, s32, s32);
void func_001D8680__as_func_001D80C0(s32 a, s32 b, s32 c, u16 d, u16 e);
s32 func_001D8960__as_func_001D80E0(s32, s32, s32, s32, s32);
s32 func_001D8960__as_func_001D8210(s32, s32, s32, s32, s32);
s32 func_001D8960__as_func_001D8350(s32, s32, s32, s32, s32);
s32 func_001D8960__as_func_001D84F0(s32, s32, s32, s32, s32);
s32 func_001D8960__as_func_001D85D0(s32, s32, s32, s32, s32);
void printf__as_func_001D8680(const char *, ...);
s32 func_001D8960__as_func_001D8680(s32, s32, s32, s32, s32);
void func_001D8680__as_func_001D87F0(s32 a, s32 b, s32 c, ...);
s32 sceSifCheckStatRpc__as_func_001D8890(CD *);
void func_001D8960__as_func_001D8890(s32, s32, s32, s32, s32);
void* func_001D8AB0(s32 fno, void *data, s32 size);
void sceSifInitRpc(u32 mode);
s32 GetThreadId(void);
void sceSifSetRpcQueue(void *q, s32 thread);
void sceSifRegisterRpc(void *serve, s32 cmd, void *(*func)(s32, void *, s32), void *buf, void *cfunc, void *cbuf, void *q);
void* sceSifRpcLoop(void *q);

/* func_001D7EC0_ */
/* func_001D7EC0 */
void func_001D7EC0(void) {
    u8 *d;
    s32 r, t;
    s32 n;
    s32 i;
    d = (u8 *)(((u32)D_004B7A40 & 0x0FFFFFFF) | 0x20000000);
    n = 10000000; goto check;
loop:
    if (n < 0) { printf(D_001FE6C0); r = -1; goto out; }
    n--;
check:
    t = sceSifCheckStatRpc(D_004B9EF0); r = 1; if (t == r) goto loop;
out:
    if (r < 0) return;
    if (D_004B7CB0) for (i = 0; i < 0x200; i++) d[i] = D_004B7CB0[i];
    func_001D8960__as_func_001D7EC0(0, 1, 0x200, 0, 0x80000);
}

/* func_001D7FD0 */
void func_001D7FD0(void) {
    s32 r, t;
    s32 n;
    s32 i;
    n = 10000000; goto check;
loop:
    if (n < 0) { printf(D_001FE6C0); r = -1; goto out; }
    n--;
check:
    t = sceSifCheckStatRpc(D_004B9EF0); r = 1; if (t == r) goto loop;
out:
    if (r >= 0) func_001D8960__as_func_001D7FD0(0, 1, 0, 0x200, 0x70000);
    for (i = 0x1FF; i >= 0; i--) D_004B7CB0[i] = D_004B7A40[i];
}

/* func_001D80C0 */

void func_001D80C0(s32 d, s32 e)
{
    func_001D8680__as_func_001D80C0(0, 1, 0x60000, d, e);
}

/* func_001D80E0 */
s32 func_001D80E0(s32 size) {
    s32 r, t;
    s32 n;
    s32 v;
    s32 p = 0;
    n = 10000000; goto check; loop: if (n < 0) { printf(D_001FE6C0); r = -1; goto out; } n--; check: t = sceSifCheckStatRpc(D_004B9EF0); r = 1; if (t == r) goto loop; out:
    if (r < 0) v = -1; else v = func_001D8960__as_func_001D80E0(0, 1, 0, 4, 0x30000);
    if (v >= size) {
        p = sceSifAllocIopHeap(size);
    } else {
        n = 10000000; goto check2; loop2: if (n < 0) { printf(D_001FE6C0); r = -1; goto out2; } n--; check2: t = sceSifCheckStatRpc(D_004B9EF0); r = 1; if (t == r) goto loop2; out2:
        if (r >= 0) func_001D8960__as_func_001D80E0(0, 1, 0, 4, 0x30000);
    }
    return p;
}

/* func_001D8210 */
/* .bss, from the top down (CodeWarrior writes it in reverse) */
u8 D_004B7EF0[0x2000];
static inline s32 st(void) {
    TP tp;
    s32 id;
    tp.entry = func_001D8BE0;
    tp.initPriority = 0x30;
    tp.stack = D_004B7EF0;
    tp.stackSize = 0x2000;
    tp.gpReg = &_gp;
    id = CreateThread(&tp);
    if (id >= 0) {
        D_00201E38 = id;
        StartThread(id, 0);
        return 1;
    }
    return 0;
}
s32 func_001D8210(void) {
    s32 r, t;
    s32 n;
    if (D_00202300 == 0) {
        if (st() != 0) {
            n = 10000000; goto check; loop: if (n < 0) { printf(D_001FE6C0); r = -1; goto out; } n--; check: t = sceSifCheckStatRpc(D_004B9EF0); r = 1; if (t == r) goto loop; out:
            if (r >= 0) func_001D8960__as_func_001D8210(0, 1, 0, 4, 0x20000);
            D_00202300 = 1;
        }
        return 1;
    }
    return 0;
}

/* func_001D8320 */
/* Store a word into the table at 0x4B7EB0. */


void func_001D8320(int index, int value)
{
    D_004B7EB0[index] = value;
}

/* func_001D8340 */

s32 *func_001D8340(void) {
    return D_004B7A40__as_func_001D8340;
}

/* func_001D8350 */
s32 func_001D8350(s32 a, s32 b, s32 c, s32 d, s32 e, void *src) {
    u8 *dst = (u8 *)(((u32)D_004B7A40__as_func_001D8350 & 0x0FFFFFFF) | 0x20000000);
    s32 n = 10000000;
    s32 r;
    s32 i;
    goto cond;
body:
    if (n < 0) { printf(D_001FE6C0); r = -1; goto out; }
    n--;
cond:
    { s32 t = sceSifCheckStatRpc(D_004B9EF0); r = 1; if (t == 1) goto body; }
out:
    if (r < 0) return -1;
    if (src != NULL) {
        for (i = 0; i < c; i++) dst[i] = ((u8 *)src)[i];
    }
    return func_001D8960__as_func_001D8350(a, b, c, d, e);
}

/* func_001D84F0 */
s32 func_001D84F0(s32 a, s32 b, s32 c, s32 d) {
    s32 n = 10000000;
    s32 r;
    goto cond;
body:
    if (n < 0) { printf(D_001FE6C0); r = -1; goto out; }
    n--;
cond:
    { s32 t = sceSifCheckStatRpc(D_004B9EF0); r = 1; if (t == 1) goto body; }
out:
    if (r < 0) return -1;
    *(s32 *)(((u32)D_004B7A40__as_func_001D84F0 & 0x0FFFFFFF) | 0x20000000) = d;
    return func_001D8960__as_func_001D84F0(a, b, 4, 4, c);
}

/* func_001D85D0 */
s32 func_001D85D0(s32 a0, s32 a1, s32 a2) {
    s32 r, t;
    s32 n;
    n = 10000000; goto check; loop: if (n < 0) { printf(D_001FE6C0); r = -1; goto out; } n--; check: t = sceSifCheckStatRpc(D_004B9EF0); r = 1; if (t == r) goto loop; out: if (r < 0) return -1; return func_001D8960__as_func_001D85D0(a0, a1, 0, 4, a2);
}

/* func_001D8680 */
#define va_start(ap, parm) ((ap) = (char *)__builtin_next_arg(parm) - ((__builtin_args_info(2) >= 8) ? 0 : (8 - __builtin_args_info(2)) * 8))
#define va_arg(ap, T) (*(T *)(((ap) += 8) - 8))

s32 func_001D8680(s32 a, s32 b, s32 c, ...) {
    s32 cnt;
    s32 *p;
    s32 r;
    va_list ap;
    p = (s32 *)(((u32)D_004B7A40 & 0x0FFFFFFF) | 0x20000000);
    cnt = 10000000;
    goto chk;
top:
    if (cnt < 0) {
        printf__as_func_001D8680(D_001FE6C0);
        r = -1;
        goto out;
    }
    cnt--;
chk:
    if (sceSifCheckStatRpc(D_004B9EF0__as_func_001D8680) == 1) goto top;
    r = 1;
out:
    if (r < 0) return -1;
    va_start(ap, c);
    p[0] = va_arg(ap, s32);
    p[1] = va_arg(ap, s32);
    p[2] = va_arg(ap, s32);
    p[3] = va_arg(ap, s32);
    p[4] = va_arg(ap, s32);
    p[5] = va_arg(ap, s32);
    p[6] = va_arg(ap, s32);
    p[7] = va_arg(ap, s32);
    return func_001D8960__as_func_001D8680(a, b, 0x20, 4, c);
}

/* func_001D87F0 */

void func_001D87F0(s32 a, u16 b, u16 c)
{
    func_001D8680__as_func_001D87F0(0, 1, 0x40000, a, b, c);
}

/* func_001D8810 */
s32 func_001D8810(void) {
    return D_002022FC;
}

/* func_001D8820 */
s32 func_001D8820(void) {
    if ((D_002022FC != 0) && (D_00202300 != 0)) {
        TerminateThread(D_00201E38);
        DeleteThread(D_00201E38);
        sceSifRemoveRpc(D_004B7C40, D_004B7C90);
        sceSifRemoveRpcQueue(D_004B7C90);
    }
    D_002022FC = 0;
    D_00202300 = 0;
    return 1;
}

/* func_001D8890 */
s32 func_001D8890(void) {
    s32 i;
    s32 r;
    if (D_002022FC == 1) return 0;
    D_00202300 = 0;
    do {
        sceSifBindRpc(&D_004B9EF0__as_func_001D8890, 0x101A, 0);
    } while (D_004B9EF0__as_func_001D8890.serve == 0);
    i = 10000000;
    goto cond;
body:
    if (i < 0) { printf(D_001FE6C0); r = -1; goto done; }
    i--;
cond:
    if (sceSifCheckStatRpc__as_func_001D8890(&D_004B9EF0__as_func_001D8890) == 1) goto body;
    r = 1;
done:
    if (r >= 0) func_001D8960__as_func_001D8890(0, 1, 0, 4, 0x10000);
    D_002022FC = 1;
    return 1;
}

/* func_001D8960 */
s32 func_001D8960(s32 a, s32 b, s32 c, s32 d, u32 e) {
    s32 m;
    s32 *buf;
    s32 n;
    s32 r;
    m = !(b != 0);
    buf = D_004B7A40__as_func_001D8960;
    c = (c + 0xF) & ~0xF;
    if (c > 0x200) c = 0x200;
    d = (d + 0xF) & ~0xF;
    if (d > 0x200) d = 0x200;
    n = 10000000;
    goto cond;
body:
    if (n < 0) { printf(D_001FE6C0); r = -1; goto out; }
    n--;
cond:
    { s32 t = sceSifCheckStatRpc(D_004B9EF0); r = 1; if (t == 1) goto body; }
out:
    if (r < 0) return -1;
    sceSifCallRpc(D_004B9EF0, ((a << 28) & 0xF0000000) | (e & 0x0FFFFFFF), m, buf, c, buf, d, 0, 0);
    return buf[0];
}

/* text_001D8AB0 */
INCLUDE_ASM(func_001D8AB0);

/* func_001D8BE0 */

void func_001D8BE0(void)
{
    sceSifInitRpc(0);
    sceSifSetRpcQueue(D_004B7C90, GetThreadId());
    sceSifRegisterRpc(D_004B7C40, 0x102A, func_001D8AB0, D_004B7840, NULL, NULL, D_004B7C90);
    sceSifRpcLoop(D_004B7C90);
}
