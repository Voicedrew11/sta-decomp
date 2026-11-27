/* libkernl.a(tlbfunc.o): SDK 2.5's TLB and exception handler hooks and
 * InitTLBFunctions, which _InitSys calls last (STA: not in kfiv-decomp; the
 * member and function names are derived, after the kernel calls they
 * install).  Copy, kCopy, GetEntryAddress and setup are kfiv-decomp's
 * intr.c's. */
#include <eekernel.h>
#include <eeregs.h>
#include <libkernl_internal.h>

/* the hand-written TLB refill and exception trap code (tlbtrap.s), which
   follows this member; the syscall table and the handlers point into it */
extern char _kTLBTrap[];

/* The member's .data: the kernel-mode TLB handler InitTLBFunctions copies to
   0x80075000 (0x330 B of R5900 code and its tables, linked at that address,
   so the words carry no relocation), the TLB refill function and exception
   handler table the trap code calls through, the entry InitTLBFunctions reads
   back, and the syscall table it installs: {number, handler} pairs, the first
   three given, the other five looked up with GetEntryAddress. */
static unsigned int tlb_handler[204] /* derived name */ = {
    0x3C028007, 0x0000282D, 0x24435300, 0x00000000, 0x8C620000, 0x14820003, 0x24A50001, 0x03E00008,
    0x8C620004, 0x2CA20006, 0x1440FFF9, 0x24630008, 0x03E00008, 0x0000102D, 0x00051602, 0x304300F0,
    0x24020030, 0x10620014, 0x2C620031, 0x10400009, 0x24020010, 0x1062000E, 0x2C620011, 0x1040000A,
    0x24020020, 0x1060000C, 0x2402FFFF, 0x10000014, 0x00000000, 0x24020050, 0x10620005, 0x2C620051,
    0x10400003, 0x24020040, 0x10620003, 0x00000000, 0x03E00008, 0x2402FFFF, 0x40842800, 0x40855000,
    0x40861000, 0x40871800, 0x0000040F, 0x42000006, 0x0000040F, 0x42000008, 0x0000040F, 0x40020000,
    0x03E00008, 0x00000000, 0x2C820030, 0x1040000B, 0x2402FFFF, 0x40840000, 0x40852800, 0x40865000,
    0x40871000, 0x40881800, 0x0000040F, 0x42000002, 0x0000040F, 0x03E00008, 0x0080102D, 0x03E00008,
    0x00000000, 0x00000000, 0x2C820030, 0x14400003, 0x00000000, 0x03E00008, 0x2402FFFF, 0x40840000,
    0x0000040F, 0x42000001, 0x0000040F, 0x40022800, 0xACA20000, 0x40035000, 0xACC30000, 0x40021000,
    0xACE20000, 0x40031800, 0xAD030000, 0x03E00008, 0x0080102D, 0x00000000, 0x40845000, 0x0000040F,
    0x42000008, 0x0000040F, 0x40040000, 0x04810003, 0x00000000, 0x10000009, 0x2404FFFF, 0x42000001,
    0x0000040F, 0x40022800, 0xACA20000, 0x40031000, 0xACC30000, 0x40021800, 0xACE20000, 0x03E00008,
    0x0080102D, 0x00000000, 0x27BDFFD0, 0xFFB00010, 0x0080802D, 0x32020FFF, 0x14400007, 0xFFBF0020,
    0x3C02000F, 0x2603FFFF, 0x3442FFFE, 0x0043102B, 0x14400003, 0x3C047000, 0x1000003B, 0x2402FFFF,
    0x03A0282D, 0x34844000, 0x37A60004, 0x0C01D456, 0x37A70008, 0x0040282D, 0x04A10009, 0x00000000,
    0x12000031, 0x0000102D, 0x40053000, 0x24A20001, 0x40823000, 0x0000040F, 0x10000013, 0x00000000,
    0x16000011, 0x24A2FFFF, 0x3C03E001, 0x00021340, 0x00433021, 0x40023000, 0x2442FFFF, 0x40823000,
    0x40850000, 0x40802800, 0x40865000, 0x40801000, 0x40801800, 0x0000040F, 0x42000002, 0x0000040F,
    0x10000019, 0x0000102D, 0x3C02FFFF, 0x26041000, 0x3442F000, 0x3C067000, 0x00822024, 0xAFA00000,
    0x02021024, 0x00042182, 0x00021182, 0x3484001F, 0x3442001F, 0x34C64000, 0xAFA20004, 0xAFA40008,
    0x40850000, 0x0000182D, 0x40832800, 0x40865000, 0x40821000, 0x40841800, 0x0000040F, 0x42000002,
    0x0000040F, 0x00A0102D, 0xDFBF0020, 0xDFB00010, 0x03E00008, 0x27BD0030, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000055, 0x80075038, 0x00000056, 0x800750C8, 0x00000057, 0x80075108, 0x00000058, 0x80075158,
    0x00000059, 0x800751A8, 0x00000003, 0x80075330,
};

/* read by the hand-written trap code (tlbtrap.s) */
void *_kTLBRefillFunc = 0; /* derived name */

void *_kExceptionHandler[16] = {0}; /* derived name */

int _kEntry3 = 0; /* derived name: GetEntryAddress(3), read by the exec wrappers */

int kCopy(int *dst, int *src, unsigned int n);

static int tlb_syscalls[16] /* derived name */ = {
    90, (int)kCopy, 91, 0x80075000, 84, (int)(_kTLBTrap + 0x140), 85, 0,
    86, 0, 87, 0, 88, 0, 89, 0,
};


/* the 32 MB TLB layout InitTLB32MB loads: the kernel entries (wired), the
   default and extended mappings, as {PageMask, EntryHi, EntryLo0, EntryLo1} */
typedef struct { /* field names derived */
    int pagemask;
    int hi;
    int lo0;
    int lo1;
} TlbEntry; /* derived name */

typedef struct {      /* field names derived */
    int nKernel;      /* 0x00 */
    int nDefault;     /* 0x04 */
    int nExtended;    /* 0x08 */
    int wired;        /* 0x0C, set by InitTLB32MB */
    TlbEntry *kernel; /* 0x10 */
    TlbEntry *def;    /* 0x14 */
    TlbEntry *ext;    /* 0x18 */
} TlbTable; /* derived name */

static TlbEntry tlb_kernel[13] /* derived name */ = {
    {0x00000000, 0x70000000, 0x80000007, 0x00000007},
    {0x00006000, 0xFFFF8000, 0x00001E1F, 0x00001F1F},
    {0x00000000, 0x10000000, 0x00400017, 0x00400053},
    {0x00000000, 0x10002000, 0x00400097, 0x004000D7},
    {0x00000000, 0x10004000, 0x00400117, 0x00400157},
    {0x00000000, 0x10006000, 0x00400197, 0x004001D7},
    {0x00000000, 0x10008000, 0x00400217, 0x00400257},
    {0x00000000, 0x1000A000, 0x00400297, 0x004002D7},
    {0x00000000, 0x1000C000, 0x00400313, 0x00400357},
    {0x00000000, 0x1000E000, 0x00400397, 0x004003D7},
    {0x0001E000, 0x11000000, 0x00440017, 0x00440415},
    {0x0001E000, 0x12000000, 0x00480017, 0x00480415},
    {0x01FFE000, 0x1E000000, 0x00780017, 0x007C0017},
};

static TlbEntry tlb_default[18] /* derived name */ = {
    {0x0007E000, 0x00080000, 0x0000201F, 0x0000301F},
    {0x0007E000, 0x00100000, 0x0000401F, 0x0000501F},
    {0x0007E000, 0x00180000, 0x0000601F, 0x0000701F},
    {0x001FE000, 0x00200000, 0x0000801F, 0x0000C01F},
    {0x001FE000, 0x00400000, 0x0001001F, 0x0001401F},
    {0x001FE000, 0x00600000, 0x0001801F, 0x0001C01F},
    {0x007FE000, 0x00800000, 0x0002001F, 0x0003001F},
    {0x007FE000, 0x01000000, 0x0004001F, 0x0005001F},
    {0x007FE000, 0x01800000, 0x0006001F, 0x0007001F},
    {0x0007E000, 0x20080000, 0x00002017, 0x00003017},
    {0x0007E000, 0x20100000, 0x00004017, 0x00005017},
    {0x0007E000, 0x20180000, 0x00006017, 0x00007017},
    {0x001FE000, 0x20200000, 0x00008017, 0x0000C017},
    {0x001FE000, 0x20400000, 0x00010017, 0x00014017},
    {0x001FE000, 0x20600000, 0x00018017, 0x0001C017},
    {0x007FE000, 0x20800000, 0x00020017, 0x00030017},
    {0x007FE000, 0x21000000, 0x00040017, 0x00050017},
    {0x007FE000, 0x21800000, 0x00060017, 0x00070017},
};

static TlbEntry tlb_extended[8] /* derived name */ = {
    {0x0007E000, 0x30100000, 0x0000403F, 0x0000503F},
    {0x0007E000, 0x30180000, 0x0000603F, 0x0000703F},
    {0x001FE000, 0x30200000, 0x0000803F, 0x0000C03F},
    {0x001FE000, 0x30400000, 0x0001003F, 0x0001403F},
    {0x001FE000, 0x30600000, 0x0001803F, 0x0001C03F},
    {0x007FE000, 0x30800000, 0x0002003F, 0x0003003F},
    {0x007FE000, 0x31000000, 0x0004003F, 0x0005003F},
    {0x007FE000, 0x31800000, 0x0006003F, 0x0007003F},
};

/* tlbfunc.o's .bss: 0x1018 bytes that no code in the program reaches (the
   gap between iopreset's and tlbtrap's .bss); unused here as in retail */
static unsigned char tlb_bss[0x1018]; /* derived name */

static TlbTable tlb_table /* derived name */ = {13, 18, 8, 0, tlb_kernel, tlb_default, tlb_extended};

void *_kSetTLBRefillFunc(void *func) /* derived name */
{
    _kTLBRefillFunc = func;
    SetVTLBRefillHandler(1, _kTLBTrap);
    SetVTLBRefillHandler(2, _kTLBTrap);
    SetVTLBRefillHandler(3, _kTLBTrap);
    return func;
}

unsigned int _kSetExceptionHandler(int cause, void *handler) /* derived name */
{
    void *old;

    if ((unsigned int)(cause - 1) >= 13) {
        return -1;
    }
    old = _kExceptionHandler[cause];
    _kExceptionHandler[cause] = handler;
    if ((unsigned int)(cause - 1) < 3) {
        SetVTLBRefillHandler(cause, _kTLBTrap + 0x240);
    } else {
        SetVCommonHandler(cause, _kTLBTrap + 0x240);
    }
    return (unsigned int)old;
}

/* syscall 90 is Copy(dst, src, len); the leaf ignores its arguments, the
   kernel reads them out of $a0..$a2. */
void Copy(char *dst, char *src, int len)
{
    __asm__ __volatile__("addiu $3, $0, 90\n\tsyscall 0" : : : "$3", "memory");
}

int kCopy(int *dst, int *src, unsigned int n)
{
    unsigned int i;
    n >>= 2;
    for (i = 0; i < n; i++) {
        *dst++ = *src++;
    }
    return 0;
}

/* An EE syscall leaf (`addiu $3,$zero,NUM; syscall 0`, the `jr $31; nop`
   from gcc's epilogue) that takes an argument and returns the kernel's $v0:
   syscall 91 is GetEntryAddress(num). */
int GetEntryAddress(int num)
{
    __asm__ __volatile__("addiu $3, $0, 91\n\tsyscall 0" : : : "$3", "memory");
}

/* this member's own file static setup (initsys.o holds the global of the
   same name); InitTLBFunctions calls it. */
static void setup(int num, int addr)
{
    __asm__ __volatile__("addiu $3, $0, 116\n\tsyscall 0" : : : "$3", "memory");
}

void InitTLBFunctions(void)
{
    unsigned int i;

    setup(tlb_syscalls[0], tlb_syscalls[1]);
    Copy((char *)0x80075000, (char *)tlb_handler, 0x330);
    FlushCache(0);
    FlushCache(2);
    setup(tlb_syscalls[2], tlb_syscalls[3]);
    setup(tlb_syscalls[4], tlb_syscalls[5]);
    for (i = 3; i < 8; i++) {
        setup(tlb_syscalls[i * 2], GetEntryAddress(tlb_syscalls[i * 2]));
    }
    _kEntry3 = GetEntryAddress(3);
}

/* The TLB kernel calls (syscalls 85..89; the negative numbers are the
   interrupt-context versions).  Names derived. */
int PutTLBEntry(int pagemask, int hi, int lo0, int lo1)
{
    __asm__ __volatile__("addiu $3, $0, 85\n\tsyscall 0" : : : "$3", "memory");
}

int iPutTLBEntry(int pagemask, int hi, int lo0, int lo1)
{
    __asm__ __volatile__("addiu $3, $0, -85\n\tsyscall 0" : : : "$3", "memory");
}

int _SetTLBEntry(unsigned int index, int pagemask, int hi, int lo0, int lo1)
{
    __asm__ __volatile__("addiu $3, $0, 86\n\tsyscall 0" : : : "$3", "memory");
}

/* entries 13..47: below are the wired kernel ones */
int SetTLBEntry(unsigned int index, int pagemask, int hi, int lo0, int lo1)
{
    if (index - 13 >= 0x23) {
        return -1;
    }
    return _SetTLBEntry(index, pagemask, hi, lo0, lo1);
}

int iSetTLBEntry(unsigned int index, int pagemask, int hi, int lo0, int lo1)
{
    __asm__ __volatile__("addiu $3, $0, -86\n\tsyscall 0" : : : "$3", "memory");
}

int GetTLBEntry(unsigned int index, int *pagemask, int *hi, int *lo0, int *lo1)
{
    __asm__ __volatile__("addiu $3, $0, 87\n\tsyscall 0" : : : "$3", "memory");
}

int iGetTLBEntry(unsigned int index, int *pagemask, int *hi, int *lo0, int *lo1)
{
    __asm__ __volatile__("addiu $3, $0, -87\n\tsyscall 0" : : : "$3", "memory");
}

int ProbeTLBEntry(int hi, int *pagemask, int *lo0, int *lo1)
{
    __asm__ __volatile__("addiu $3, $0, 88\n\tsyscall 0" : : : "$3", "memory");
}

int iProbeTLBEntry(int hi, int *pagemask, int *lo0, int *lo1)
{
    __asm__ __volatile__("addiu $3, $0, -88\n\tsyscall 0" : : : "$3", "memory");
}

int ExpandScratchPad(unsigned int page)
{
    __asm__ __volatile__("addiu $3, $0, 89\n\tsyscall 0" : : : "$3", "memory");
}

int _InitTLB(void);
int InitTLB32MB(void);

/* STA: SDK 2.5 resets the TLB itself on a 32 MB machine */
int InitTLB(void)
{
    if (GetMemorySize() == 0x2000000) {
        return InitTLB32MB();
    }
    return _InitTLB();
}

int InitTLB32MB(void) /* derived name */
{
    register int i __asm__("$25");
    TlbTable *t = &tlb_table;
    TlbEntry *e;
    int n;
    int j;
    unsigned int va;

    kprintf("# TLB spad=0 kernel=1:%d default=%d:%d extended=%d:%d\n", t->nKernel - 1, t->nKernel,
            t->nKernel + t->nDefault - 1, t->nKernel + t->nDefault,
            t->nKernel + t->nDefault + t->nExtended - 1);
    __asm__ __volatile__("mtc0 $0, $6\n\tsync.p");
    n = tlb_table.nKernel;
    i = 0;
    if (n > 0x30) {
        kprintf("# TLB over flow (1)");
        Exit(1);
    }
    for (e = t->kernel; i < n; i++, e++) {
        _SetTLBEntry(i, e->pagemask, e->hi, e->lo0, e->lo1);
    }
    t = &tlb_table;
    n = i + t->nDefault;
    if (n > 0x30) {
        kprintf("# TLB over flow (2)");
        Exit(1);
    }
    for (e = t->def; i < n; i++, e++) {
        _SetTLBEntry(i, e->pagemask, e->hi, e->lo0, e->lo1);
    }
    t = &tlb_table;
    t->wired = i;
    __asm__ __volatile__("mtc0 %0, $6\n\tsync.p" : : "r"(i));
    if (t->nExtended > 0) {
        n = i + t->nExtended;
        if (n > 0x30) {
            kprintf("# TLB over flow (3)");
            Exit(1);
        }
        for (e = t->ext; i < n; i++, e++) {
            _SetTLBEntry(i, e->pagemask, e->hi, e->lo0, e->lo1);
        }
    }
    /* the rest map the scratchpad window; the shifted index is what the
       function returns */
    j = i;
    i <<= 13;
    if (j < 0x30) {
        va = 0xE0000000 + i;
        do {
            _SetTLBEntry(j, 0, va, 0, 0);
            j++;
            va += 0x2000;
        } while (j < 0x30);
    }
    return i;
}
