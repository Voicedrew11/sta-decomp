/* libkernl.a: SDK 2.5's exec wrappers (STA: not in kfiv-decomp; member and
 * helper names derived).  ExecPS2, LoadExecPS2, Exit and ExecOSD reset the
 * TLB (InitTLB, in tlbfunc.o) before the kernel call, and the exec calls
 * first copy their arguments into kernel memory at _kEntry3 with Copy
 * installed as a byte copy. */
#include <eekernel.h>
#include <string.h>
#include <libkernl_internal.h>

extern int _kEntry3;
void InitTLB(void);
int _ExecPS2(void *entry, void *gp, int argc, char **argv);
void _LoadExecPS2(const char *name, int argc, char **argv);
void _Exit(int status);
void _ExecOSD(int argc, char **argv);

/* syscall 90 is Copy(dst, src, len); the leaf ignores its arguments, the
   kernel reads them out of $a0..$a2. */
static int Copy(void *dst, void *src, int len)
{
    __asm__ __volatile__("addiu $3, $0, 90\n\tsyscall 0" : : : "$3", "memory");
}

static int kCopy(char *dst, char *src, unsigned int n)
{
    unsigned int i;
    for (i = 0; i < n; i++) {
        *dst++ = *src++;
    }
    return 0;
}

static void setup(int num, int addr)
{
    __asm__ __volatile__("addiu $3, $0, 116\n\tsyscall 0" : : : "$3", "memory");
}

static int exec_syscalls[2] /* derived name */ = {90, (int)kCopy};

static char *SetArg(const char *name, int argc, char **argv) /* derived name */
{
    int *table = (int *)_kEntry3;
    char *p = (char *)(_kEntry3 + 0x40);
    char *ret = p;
    int n;

    setup(exec_syscalls[0], exec_syscalls[1]);
    argc = (argc < 16) ? argc : 15;
    Copy(table++, &p, 4);
    n = strlen(name) + 1;
    Copy(p, (void *)name, n);
    p += n;
    if (argc > 0) {
        char **av = argv;

        do {
            Copy(table++, &p, 4);
            argc--;
            n = strlen(*av) + 1;
            Copy(p, *av, n);
            av++;
            p += n;
        } while (argc != 0);
    }
    return ret;
}

static void ResetTLB(void) /* derived name */
{
    InitTLB();
}

int ExecPS2(void *entry, void *gp, int argc, char **argv)
{
    SetArg("", argc, argv);
    ResetTLB();
    return _ExecPS2(entry, gp, argc, (char **)(_kEntry3 + 4));
}

void LoadExecPS2(const char *name, int argc, char **argv)
{
    char *p = SetArg(name, argc, argv);

    ResetTLB();
    _LoadExecPS2(p, argc, (char **)(_kEntry3 + 4));
}

void Exit(int status)
{
    ResetTLB();
    _Exit(status);
}

void ExecOSD(int argc, char **argv)
{
    SetArg("", argc, argv);
    ResetTLB();
    _ExecOSD(argc, (char **)(_kEntry3 + 4));
}
