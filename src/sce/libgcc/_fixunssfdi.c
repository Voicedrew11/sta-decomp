/* libgcc.a member _fixunssfdi.o (STA: libgcc2.c's __fixunssfdi; not in kfiv-decomp) */
#include "libgcc2.h"

typedef unsigned int USItype;

typedef long long DItype;

typedef unsigned long long UDItype;

typedef float SFtype;

typedef double DFtype;

#define WORD_SIZE 32
#define HIGH_WORD_COEFF (((UDItype)1) << WORD_SIZE)

DItype __fixunssfdi(SFtype original_a)
{
    /* Convert the SFtype to a DFtype, because that is surely not going
       to lose any bits.  */
    DFtype a = original_a;
    DFtype b;
    UDItype v;

    if (a < 0)
        return 0;

    /* Compute high word of result, as a flonum.  */
    b = (a / HIGH_WORD_COEFF);
    /* Convert that to fixed (but not to DItype!),
       and shift it into the high word.  */
    v = (USItype)b;
    v <<= WORD_SIZE;
    /* Remove high part from the DFtype, leaving the low part as flonum.  */
    a -= (DFtype)v;
    /* Convert that to fixed (but not to DItype!) and add it in.  */
    if (a < 0)
        v -= (USItype)(-a);
    else
        v += (USItype)a;

    return v;
}
