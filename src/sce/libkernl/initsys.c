/* libkernl.a(initsys.o), SDK 2.5 (SAB: rewritten from the retail code;
 * kfiv-decomp's SDK 2.2 member only had setup, InitSysCall and _InitSys).
 * _InitSys now also creates libc's malloc semaphores, finds the kernel's
 * syscall table (FindAddress, syscall 131, over kernel memory for the two
 * handlers it installs), and calls InitOsd and InitTLBFunctions.  The
 * function and variable names other than _InitSys and setup are derived. */
#include <eekernel.h>
#include <libkernl_internal.h>

void InitAlarm(void);
void InitOsd(void);
void InitTLBFunctions(void);

static int *syscall_table = 0; /* derived name */

static int *FindAddress(int *p, int *end, int val);
static int kCopy(int *dst, int *src, unsigned int n);

static int initsys_syscalls[4] /* derived name */ = {
    131, (int)FindAddress, 90, (int)kCopy,
};

int __malloc_sema = 0;  /* derived name: __malloc_lock waits on it */
int __malloc_sema2 = 0; /* derived name */

void InitMallocSema(void) /* derived name */
{
    struct SemaParam a;
    struct SemaParam b;

    a.maxCount = 1;
    a.initCount = 1;
    b.maxCount = 1;
    b.initCount = 1;
    __malloc_sema = CreateSema(&a);
    __malloc_sema2 = CreateSema(&b);
}

/* syscall 90 is Copy(dst, src, len); the leaf ignores its arguments, the
   kernel reads them out of $a0..$a2. */
static void Copy(void *dst, void *src, int len)
{
    __asm__ __volatile__("addiu $3, $0, 90\n\tsyscall 0" : : : "$3", "memory");
}

static int kCopy(int *dst, int *src, unsigned int n)
{
    unsigned int i;
    n >>= 2;
    for (i = 0; i < n; i++) {
        *dst++ = *src++;
    }
    return 0;
}

/* the handler installed as syscall 131: the first word from p to end that
   holds val */
static int *FindAddress(int *p, int *end, int val)
{
    while (*p != val && p < end) {
        p++;
    }
    if (p >= end) {
        p = 0;
    }
    return p;
}

/* syscall 131 */
static int *_FindAddress(int *p, int *end, int val) /* derived name */
{
    __asm__ __volatile__("addiu $3, $0, 131\n\tsyscall 0" : : : "$3", "memory");
}

int GetSyscallHandler(int num) /* derived name */
{
    int v;

    Copy(&v, syscall_table + num, 4);
    return v;
}

static void setup(int num, int addr);

void InitSyscallTable(void) /* derived name */
{
    int *a;
    int *b;
    int *ta;
    int *tb;

    setup(initsys_syscalls[0], initsys_syscalls[1]);
    setup(initsys_syscalls[2], initsys_syscalls[3]);
    a = _FindAddress((int *)0x80000000, (int *)0x80080000, (int)FindAddress);
    b = _FindAddress((int *)0x80000000, (int *)0x80080000, (int)kCopy);
    ta = a - 131;
    tb = b - 90;
    while (ta != tb) {
        if (ta < tb) {
            a = _FindAddress(a + 1, (int *)0x80080000, (int)FindAddress);
            ta = a - 131;
        } else {
            b = _FindAddress(b + 1, (int *)0x80080000, (int)kCopy);
            tb = b - 90;
        }
    }
    syscall_table = ta;
}

static void setup(int num, int addr)
{
    __asm__ __volatile__("addiu $3, $0, 116\n\tsyscall 0" : : : "$3", "memory");
}

void _InitSys(void)
{
    InitMallocSema();
    InitSyscallTable();
    InitAlarm();
    InitThread();
    InitOsd();
    InitTLBFunctions();
}
