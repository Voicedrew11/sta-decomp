/* libkernl.a(intr.o) */
#include <eekernel.h>
#include <eeregs.h>
#include <libkernl_internal.h>

/* R5900 opcodes with no C spelling.  Defined in this member. */
#define SYNC() __asm__ __volatile__("sync" : : : "memory")
/* COP0 Status ($12), bit 16 = interrupts enabled.  Taken as an lvalue: the
   wrappers mask the word in place. */
#define MFC0_STATUS(dst) __asm__ __volatile__("mfc0 %0, $12" : "=r"(dst))
#define COP0_STATUS_EIE 0x10000

/* STA: SDK 2.5's intr.o starts with this: whether Status.IE is clear */
int _kIntrDisabled(void) /* derived name */
{
    int s;
    MFC0_STATUS(s);
    return (s ^ 1) & 1;
}

int DisableIntc(int cause)
{
    int eie;
    int rv;
    MFC0_STATUS(eie);
    eie &= COP0_STATUS_EIE;
    if (eie) {
        DIntr();
    }
    rv = _DisableIntc(cause);
    SYNC();
    if (eie) {
        EIntr();
    }
    return rv;
}

int EnableIntc(int cause)
{
    int eie;
    int rv;
    MFC0_STATUS(eie);
    eie &= COP0_STATUS_EIE;
    if (eie) {
        DIntr();
    }
    rv = _EnableIntc(cause);
    SYNC();
    if (eie) {
        EIntr();
    }
    return rv;
}

int DisableDmac(int channel)
{
    int eie;
    int rv;
    MFC0_STATUS(eie);
    eie &= COP0_STATUS_EIE;
    if (eie) {
        DIntr();
    }
    rv = _DisableDmac(channel);
    SYNC();
    if (eie) {
        EIntr();
    }
    return rv;
}

int EnableDmac(int channel)
{
    int eie;
    int rv;
    MFC0_STATUS(eie);
    eie &= COP0_STATUS_EIE;
    if (eie) {
        DIntr();
    }
    rv = _EnableDmac(channel);
    SYNC();
    if (eie) {
        EIntr();
    }
    return rv;
}

int iEnableIntc(int cause)
{
    int r = _iEnableIntc(cause);
    SYNC();
    return r;
}

int iDisableIntc(int cause)
{
    int r = _iDisableIntc(cause);
    SYNC();
    return r;
}

int iEnableDmac(int channel)
{
    int r = _iEnableDmac(channel);
    SYNC();
    return r;
}

int iDisableDmac(int channel)
{
    int r = _iDisableDmac(channel);
    SYNC();
    return r;
}
