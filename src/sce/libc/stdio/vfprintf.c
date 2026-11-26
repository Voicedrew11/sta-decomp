/* libc.a member vfprintf.o */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <reent.h>
#include <unistd.h>
#include <libc_internal.h>
#include <locale.h>

/* The stdio stream, as this libc lays it out: __sbprintf builds one on its own
   stack so a line-buffered stream is written through a full-size buffer. */
#define __SNBF 0x0002
#define __SERR 0x0040
#define BUFSIZ 1024
#define EOF (-1)

/* fvwrite.h */
struct __siov {
    const void *iov_base; /* 0x0 */
    int iov_len;          /* 0x4 */
};

struct __suio {
    struct __siov *uio_iov; /* 0x0 */
    int uio_iovcnt;         /* 0x4 */
    int uio_resid;          /* 0x8 */
};

/* __sprint, a file static (sce/libc/stdio/vfiprintf.c holds the global of
   the same name). */
static int __sprint(fp, uio)
Fil *fp;

register struct __suio *uio;

{
    register int err;

    if (uio->uio_resid == 0) {
        uio->uio_iovcnt = 0;
        return (0);
    }
    err = __sfvwrite(fp, uio);
    uio->uio_resid = 0;
    uio->uio_iovcnt = 0;
    return (err);
}

/* __sbprintf, a file static (sce/libc/stdio/vfiprintf.c holds the global of
   the same name). */
static int __sbprintf(Fil *fp, const char *fmt, void *ap)
{
    int ret;
    Fil fake;
    unsigned char buf[BUFSIZ];

    /* copy the important variables */
    fake.data = fp->data;
    fake.flags = fp->flags & ~__SNBF;
    fake.file = fp->file;
    fake.cookie = fp->cookie;
    fake.write = fp->write;

    /* set up the buffer */
    fake.bf.base = fake.p = buf;
    fake.bf.size = fake.w = sizeof(buf);
    fake.lbfsize = 0;

    /* do the work, then copy any error status */
    ret = vfprintf(&fake, fmt, ap);
    if (ret >= 0 && fflush(&fake))
        ret = EOF;
    if (fake.flags & __SERR)
        fp->flags |= __SERR;
    return ret;
}

/* newlib's vfprintf.c, the FLOATING_POINT (non INTEGER_ONLY) build of the
   member: VFPRINTF is `vfprintf`, _VFPRINTF_R is `_vfprintf_r`, and
   _NO_LONGLONG stays defined (WANT_PRINTF_LONG_LONG is off), which is why the
   [diouxX] accumulator is a 64-bit `unsigned long` and the base conversions go
   through __udivdi3 / __umoddi3. */
typedef char *va_list;

#define va_arg(ap, type) (*(type *)((ap += 8) - 8))

typedef int wchar_t;

/* floatio.h */
#define MAXEXP 308
#define MAXFRACT 39
#define BUF (MAXEXP + MAXFRACT + 1)
#define DEFPREC 6
#define __SLBF 0x0001
#define __SNBF 0x0002
#define __SRD 0x0004
#define __SWR 0x0008
#define __SRW 0x0010
#define __SEOF 0x0020
#define __SERR 0x0040
#define NULL 0

/* called with a double; math.h and s_isinf.c/s_isnan.c take the bits as a long long */
extern int isinf(double d);
extern int isnan(double d);

#define _REENT (_impure_ptr)
#define CHECK_INIT(fp)                                                                             \
    do {                                                                                           \
        if ((fp)->data == 0)                                                                       \
            (fp)->data = _REENT;                                                                   \
        if (!(fp)->data->sdidinit)                                                                 \
            __sinit((fp)->data);                                                                   \
    } while (0)
#define cantwrite(fp) ((((fp)->flags & __SWR) == 0 || (fp)->bf.base == NULL) && __swsetup(fp))
#define __sferror(p) ((p)->flags & __SERR)
#define to_digit(c) ((c) - '0')
#define is_digit(c) ((unsigned)to_digit(c) <= 9)
#define to_char(n) ((n) + '0')
#define ALT 0x001
#define HEXPREFIX 0x002
#define LADJUST 0x004
#define LONGDBL 0x008
#define LONGINT 0x010
#define QUADINT 0x020
#define SHORTINT 0x040
#define ZEROPAD 0x080
#define FPT 0x100

/* mprec.h's view of a double, for cvt's sign test. */
union double_union {
    double d;
    unsigned int i[2];
};

#define word0(x) (x.i[1])
#define Sign_bit ((unsigned int)0x80000000L)

static char *cvt(Reent *data, double value, int ndigits, int flags, char *sign, int *decpt, int ch,
                 int *length);

static int exponent(char *p0, int exp, int fmtch);

int vfprintf(fp, fmt0, ap)
Fil *fp;

const char *fmt0;

va_list ap;

{
    CHECK_INIT(fp);
    return _vfprintf_r(fp->data, fp, fmt0, ap);
}

/* TODO(STA): TEMPORARY inline asm, to be removed: _vfprintf_r is retail's
 * instructions until the C below matches.  The C is kept (under #if 0) for
 * the next attempt; delete the asm and the #if 0 once it compiles to the
 * same bytes.  tools/asm2inline.py generated the block. */
#if 0
int _vfprintf_r(data, fp, fmt0, ap)
Reent *data;

Fil *fp;

const char *fmt0;

va_list ap;

{
    register char *fmt;           /* format string */
    register int ch;              /* character from fmt */
    register int n, m;            /* handy integers (short term usage) */
    register char *cp;            /* handy char pointer (short term usage) */
    register struct __siov *iovp; /* for PRINT macro */
    register int flags;           /* flags as above */
    int ret;                      /* return value accumulator */
    int width;                    /* width from format (%8d), or 0 */
    int prec;                     /* precision from format (%.3d), or -1 */
    char sign;                    /* sign prefix (' ', '+', '-', or \0) */
    wchar_t wc;
    char *decimal_point = localeconv()->decimal_point;
    char softsign;  /* temporary negative sign for floats */
    double _double; /* double precision arguments %[eEfgG] */
    int expt;       /* integer value of exponent */
    int expsize;    /* character count for expstr */
    int ndig;       /* actual number of digits returned by cvt */
    char expstr[7]; /* buffer for exponent string */

    unsigned long _uquad; /* integer arguments %[diouxX] */

    enum { OCT, DEC, HEX } base; /* base for [diouxX] conversion */

    int dprec;   /* a copy of prec if [diouxX], 0 otherwise */
    int realsz;  /* field size expanded by dprec */
    int size;    /* size of converted field or string */
    char *xdigs; /* digits for [xX] conversion */
#define NIOV 8
    struct __suio uio;       /* output information: summary */
    struct __siov iov[NIOV]; /* ... and individual io vectors */
    char buf[BUF];           /* space for %c, %[diouxX], %[eEfgG] */
    char ox[2];              /* space for 0x hex-prefix */
    int state = 0;           /* mbtowc calls from library must not change state */

#define PADSIZE 16 /* pad chunk size */
    static const char blanks[PADSIZE] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                                         ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    static const char zeroes[PADSIZE] = {'0', '0', '0', '0', '0', '0', '0', '0',
                                         '0', '0', '0', '0', '0', '0', '0', '0'};

#define PRINT(ptr, len)                                                                            \
    {                                                                                              \
        iovp->iov_base = (ptr);                                                                    \
        iovp->iov_len = (len);                                                                     \
        uio.uio_resid += (len);                                                                    \
        iovp++;                                                                                    \
        if (++uio.uio_iovcnt >= NIOV) {                                                            \
            if (__sprint(fp, &uio))                                                                \
                goto error;                                                                        \
            iovp = iov;                                                                            \
        }                                                                                          \
    }
#define PAD(howmany, with)                                                                         \
    {                                                                                              \
        if ((n = (howmany)) > 0) {                                                                 \
            while (n > PADSIZE) {                                                                  \
                PRINT(with, PADSIZE);                                                              \
                n -= PADSIZE;                                                                      \
            }                                                                                      \
            PRINT(with, n);                                                                        \
        }                                                                                          \
    }
#define FLUSH()                                                                                    \
    {                                                                                              \
        if (uio.uio_resid && __sprint(fp, &uio))                                                   \
            goto error;                                                                            \
        uio.uio_iovcnt = 0;                                                                        \
        iovp = iov;                                                                                \
    }

#define SARG()                                                                                     \
    (flags & LONGINT    ? va_arg(ap, long)                                                         \
     : flags & SHORTINT ? (long)(short)va_arg(ap, int)                                             \
                        : (long)va_arg(ap, int))
#define UARG()                                                                                     \
    (flags & LONGINT    ? va_arg(ap, unsigned long)                                                \
     : flags & SHORTINT ? (unsigned long)(unsigned short)va_arg(ap, int)                           \
                        : (unsigned long)va_arg(ap, unsigned int))

    /* sorry, fprintf(read_only_file, "") returns EOF, not 0 */
    if (cantwrite(fp))
        return (EOF);

    /* optimise fprintf(stderr) (and other unbuffered Unix files) */
    if ((fp->flags & (__SNBF | __SWR | __SRW)) == (__SNBF | __SWR) && fp->file >= 0)
        return (__sbprintf(fp, fmt0, ap));

    fmt = (char *)fmt0;
    uio.uio_iov = iovp = iov;
    uio.uio_resid = 0;
    uio.uio_iovcnt = 0;
    ret = 0;

    /*
     * Scan the format for conversions (`%' character).
     */
    for (;;) {
        cp = fmt;
        while ((n = _mbtowc_r(_REENT, &wc, fmt, MB_CUR_MAX, &state)) > 0) {
            fmt += n;
            if (wc == '%') {
                fmt--;
                break;
            }
        }
        if ((m = fmt - cp) != 0) {
            PRINT(cp, m);
            ret += m;
        }
        if (n <= 0)
            goto done;
        fmt++; /* skip over '%' */

        flags = 0;
        dprec = 0;
        width = 0;
        prec = -1;
        sign = '\0';

    rflag:
        ch = *fmt++;
    reswitch:
        switch (ch) {
        case ' ':
            if (!sign)
                sign = ' ';
            goto rflag;
        case '#':
            flags |= ALT;
            goto rflag;
        case '*':
            if ((width = va_arg(ap, int)) >= 0)
                goto rflag;
            width = -width;
            /* FALLTHROUGH */
        case '-':
            flags |= LADJUST;
            goto rflag;
        case '+':
            sign = '+';
            goto rflag;
        case '.':
            if ((ch = *fmt++) == '*') {
                n = va_arg(ap, int);
                prec = n < 0 ? -1 : n;
                goto rflag;
            }
            n = 0;
            while (is_digit(ch)) {
                n = 10 * n + to_digit(ch);
                ch = *fmt++;
            }
            prec = n < 0 ? -1 : n;
            goto reswitch;
        case '0':
            flags |= ZEROPAD;
            goto rflag;
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            n = 0;
            do {
                n = 10 * n + to_digit(ch);
                ch = *fmt++;
            } while (is_digit(ch));
            width = n;
            goto reswitch;
        case 'L':
            flags |= LONGDBL;
            goto rflag;
        case 'h':
            flags |= SHORTINT;
            goto rflag;
        case 'l':
            if (*fmt == 'l') {
                fmt++;
                flags |= QUADINT;
            } else {
                flags |= LONGINT;
            }
            goto rflag;
        case 'q':
            flags |= QUADINT;
            goto rflag;
        case 'c':
            *(cp = buf) = va_arg(ap, int);
            size = 1;
            sign = '\0';
            break;
        case 'D':
            flags |= LONGINT;
            /*FALLTHROUGH*/
        case 'd':
        case 'i':
            _uquad = SARG();
            if ((long)_uquad < 0) {
                _uquad = -_uquad;
                sign = '-';
            }
            base = DEC;
            goto number;
        case 'e':
        case 'E':
        case 'f':
        case 'g':
        case 'G':
            if (prec == -1) {
                prec = DEFPREC;
            } else if ((ch == 'g' || ch == 'G') && prec == 0) {
                prec = 1;
            }

            if (flags & LONGDBL) {
                _double = (double)va_arg(ap, long double);
            } else {
                _double = va_arg(ap, double);
            }

            /* do this before tricky precision changes */
            if (isinf(_double)) {
                if (_double < 0)
                    sign = '-';
                cp = "Inf";
                size = 3;
                break;
            }
            if (isnan(_double)) {
                cp = "NaN";
                size = 3;
                break;
            }

            flags |= FPT;
            cp = cvt(data, _double, prec, flags, &softsign, &expt, ch, &ndig);
            if (ch == 'g' || ch == 'G') {
                if (expt <= -4 || expt > prec)
                    ch = (ch == 'g') ? 'e' : 'E';
                else
                    ch = 'g';
            }
            if (ch <= 'e') { /* 'e' or 'E' fmt */
                --expt;
                expsize = exponent(expstr, expt, ch);
                size = expsize + ndig;
                if (ndig > 1 || flags & ALT)
                    ++size;
            } else if (ch == 'f') { /* f fmt */
                if (expt > 0) {
                    size = expt;
                    if (prec || flags & ALT)
                        size += prec + 1;
                } else /* "0.X" */
                    size = prec + 2;
            } else if (expt >= ndig) { /* fixed g fmt */
                size = expt;
                if (flags & ALT)
                    ++size;
            } else
                size = ndig + (expt > 0 ? 1 : 2 - expt);

            if (softsign)
                sign = '-';
            break;
        case 'n':
            if (flags & LONGINT)
                *va_arg(ap, long *) = ret;
            else if (flags & SHORTINT)
                *va_arg(ap, short *) = ret;
            else
                *va_arg(ap, int *) = ret;
            continue; /* no output */
        case 'O':
            flags |= LONGINT;
            /*FALLTHROUGH*/
        case 'o':
            _uquad = UARG();
            base = OCT;
            goto nosign;
        case 'p':
            /* NOSTRICT */
            _uquad = (unsigned long)(unsigned long)va_arg(ap, void *);
            base = HEX;
            xdigs = "0123456789abcdef";
            flags |= HEXPREFIX;
            ch = 'x';
            goto nosign;
        case 's':
            if ((cp = va_arg(ap, char *)) == NULL)
                cp = "(null)";
            if (prec >= 0) {
                char *p = memchr(cp, 0, prec);

                if (p != NULL) {
                    size = p - cp;
                    if (size > prec)
                        size = prec;
                } else
                    size = prec;
            } else
                size = strlen(cp);
            sign = '\0';
            break;
        case 'U':
            flags |= LONGINT;
            /*FALLTHROUGH*/
        case 'u':
            _uquad = UARG();
            base = DEC;
            goto nosign;
        case 'X':
            xdigs = "0123456789ABCDEF";
            goto hex;
        case 'x':
            xdigs = "0123456789abcdef";
        hex:
            _uquad = UARG();
            base = HEX;
            /* leading 0x/X only if non-zero */
            if (flags & ALT && _uquad != 0)
                flags |= HEXPREFIX;

            /* unsigned conversions */
        nosign:
            sign = '\0';
        number:
            if ((dprec = prec) >= 0)
                flags &= ~ZEROPAD;

            cp = buf + BUF;
            if (_uquad != 0 || prec != 0) {
                switch (base) {
                case OCT:
                    do {
                        *--cp = to_char(_uquad & 7);
                        _uquad >>= 3;
                    } while (_uquad);
                    /* handle octal leading 0 */
                    if (flags & ALT && *cp != '0')
                        *--cp = '0';
                    break;

                case DEC:
                    /* many numbers are 1 digit */
                    while (_uquad >= 10) {
                        *--cp = to_char(_uquad % 10);
                        _uquad /= 10;
                    }
                    *--cp = to_char(_uquad);
                    break;

                case HEX:
                    do {
                        *--cp = xdigs[_uquad & 15];
                        _uquad >>= 4;
                    } while (_uquad);
                    break;

                default:
                    cp = "bug in vfprintf: bad base";
                    size = strlen(cp);
                    goto skipsize;
                }
            }
            size = buf + BUF - cp;
        skipsize:
            break;
        default: /* "%?" prints ?, unless ? is NUL */
            if (ch == '\0')
                goto done;
            /* pretend it was %c with argument ch */
            cp = buf;
            *cp = ch;
            size = 1;
            sign = '\0';
            break;
        }

        realsz = dprec > size ? dprec : size;
        if (sign)
            realsz++;
        else if (flags & HEXPREFIX)
            realsz += 2;

        /* right-adjusting blank padding */
        if ((flags & (LADJUST | ZEROPAD)) == 0)
            PAD(width - realsz, blanks);

        /* prefix */
        if (sign) {
            PRINT(&sign, 1);
        } else if (flags & HEXPREFIX) {
            ox[0] = '0';
            ox[1] = ch;
            PRINT(ox, 2);
        }

        /* right-adjusting zero padding */
        if ((flags & (LADJUST | ZEROPAD)) == ZEROPAD)
            PAD(width - realsz, zeroes);

        /* leading zeroes from decimal precision */
        PAD(dprec - size, zeroes);

        /* the string or number proper */
        if ((flags & FPT) == 0) {
            PRINT(cp, size);
        } else {             /* glue together f_p fragments */
            if (ch >= 'f') { /* 'f' or 'g' */
                if (_double == 0) {
                    /* kludge for __dtoa irregularity */
                    PRINT("0", 1);
                    if (expt < ndig || (flags & ALT) != 0) {
                        PRINT(decimal_point, 1);
                        PAD(ndig - 1, zeroes);
                    }
                } else if (expt <= 0) {
                    PRINT("0", 1);
                    PRINT(decimal_point, 1);
                    PAD(-expt, zeroes);
                    PRINT(cp, ndig);
                } else if (expt >= ndig) {
                    PRINT(cp, ndig);
                    PAD(expt - ndig, zeroes);
                    if (flags & ALT)
                        PRINT(".", 1);
                } else {
                    PRINT(cp, expt);
                    cp += expt;
                    PRINT(".", 1);
                    PRINT(cp, ndig - expt);
                }
            } else { /* 'e' or 'E' */
                if (ndig > 1 || flags & ALT) {
                    ox[0] = *cp++;
                    ox[1] = '.';
                    PRINT(ox, 2);
                    if (_double || flags & ALT == 0) {
                        PRINT(cp, ndig - 1);
                    } else /* 0.[0..] */
                        /* __dtoa irregularity */
                        PAD(ndig - 1, zeroes);
                } else /* XeYYY */
                    PRINT(cp, 1);
                PRINT(expstr, expsize);
            }
        }
        /* left-adjusting padding (always blank) */
        if (flags & LADJUST)
            PAD(width - realsz, blanks);

        /* finally, adjust ret */
        ret += width > realsz ? width : realsz;

        FLUSH(); /* copy out the I/O vectors */
    }
done:
    FLUSH();
error:
    return (__sferror(fp) ? EOF : ret);
    /* NOTREACHED */
}
#endif
__asm__(".section .text\n"
        "    .set noat\n"
        "    .set noreorder\n"
        "    .align 3\n"
        "    .globl _vfprintf_r\n"
        "    .type _vfprintf_r, @function\n"
        "_vfprintf_r:\n"
        "    addiu      $29, $29, -0x290\n"
        "    sd         $16, 0x240($29)\n"
        "    daddu      $16, $6, $0\n"
        "    sd         $22, 0x270($29)\n"
        "    daddu      $22, $7, $0\n"
        "    sw         $4, 0x1E4($29)\n"
        "    sd         $17, 0x248($29)\n"
        "    sd         $18, 0x250($29)\n"
        "    sd         $19, 0x258($29)\n"
        "    sd         $20, 0x260($29)\n"
        "    sd         $21, 0x268($29)\n"
        "    sd         $23, 0x278($29)\n"
        "    sd         $30, 0x280($29)\n"
        "    sd         $31, 0x288($29)\n"
        "    jal        localeconv\n"
        "    sw        $5, 0x1E8($29)\n"
        "    lw         $4, 0x1E8($29)\n"
        "    lw         $2, 0x0($2)\n"
        "    lhu        $3, 0xC($4)\n"
        "    sw         $2, 0x1F4($29)\n"
        "    andi       $2, $3, 0x8\n"
        "    beqz       $2, .L00126718\n"
        "    sw        $0, 0x1D8($29)\n"
        "    lw         $2, 0x10($4)\n"
        "    bnel       $2, $0, .L00126734\n"
        "    andi      $3, $3, 0x1A\n"
        ".L00126718:\n"
        "    jal        __swsetup\n"
        "    lw        $4, 0x1E8($29)\n"
        "    bnez       $2, .L00127CF0\n"
        "    addiu     $2, $0, -0x1\n"
        "    lw         $5, 0x1E8($29)\n"
        "    lhu        $3, 0xC($5)\n"
        "    andi       $3, $3, 0x1A\n"
        ".L00126734:\n"
        "    addiu      $2, $0, 0xA\n"
        "    bne        $3, $2, .L00126768\n"
        "    addiu     $19, $29, 0x20\n"
        "    lw         $6, 0x1E8($29)\n"
        "    lh         $2, 0xE($6)\n"
        "    bltz       $2, .L00126768\n"
        "    daddu     $4, $6, $0\n"
        "    daddu      $6, $22, $0\n"
        "    jal        __sbprintf\n"
        "    daddu     $5, $16, $0\n"
        "    b          .L00127CF4\n"
        "    ld        $16, 0x240($29)\n"
        "    nop\n"
        ".L00126768:\n"
        "    sw         $0, 0x18($29)\n"
        "    sw         $19, 0x10($29)\n"
        "    daddu      $18, $16, $0\n"
        "    sw         $0, 0x14($29)\n"
        "    sw         $0, 0x1EC($29)\n"
        "    nop\n"
        ".L00126780:\n"
        "    daddu      $21, $18, $0\n"
        "    addiu      $17, $0, 0x25\n"
        ".L00126788:\n"
        "    lui        $2, %hi(_impure_ptr)\n"
        "    lui        $3, %hi(D_001F1688)\n"
        "    lw         $4, %lo(_impure_ptr)($2)\n"
        "    addiu      $5, $29, 0x1D4\n"
        "    lw         $7, %lo(D_001F1688)($3)\n"
        "    daddu      $6, $18, $0\n"
        "    jal        _mbtowc_r\n"
        "    addiu     $8, $29, 0x1D8\n"
        "    daddu      $16, $2, $0\n"
        "    blezl      $16, .L001267C8\n"
        "    subu      $17, $18, $21\n"
        "    lw         $2, 0x1D4($29)\n"
        "    bne        $2, $17, .L00126788\n"
        "    addu      $18, $18, $16\n"
        "    addiu      $18, $18, -0x1\n"
        "    subu       $17, $18, $21\n"
        ".L001267C8:\n"
        "    beqz       $17, .L00126824\n"
        "    nop\n"
        "    sw         $17, 0x4($19)\n"
        "    sw         $21, 0x0($19)\n"
        "    addiu      $19, $19, 0x8\n"
        "    lw         $2, 0x14($29)\n"
        "    lw         $3, 0x18($29)\n"
        "    addiu      $2, $2, 0x1\n"
        "    addu       $3, $3, $17\n"
        "    slti       $4, $2, 0x8\n"
        "    sw         $3, 0x18($29)\n"
        "    bnez       $4, .L00126818\n"
        "    sw        $2, 0x14($29)\n"
        "    lw         $4, 0x1E8($29)\n"
        "    jal        __sprint\n"
        "    addiu     $5, $29, 0x10\n"
        "    bnez       $2, .L00127CDC\n"
        "    lw        $2, 0x1E8($29)\n"
        "    addiu      $4, $29, 0x20\n"
        "    daddu      $19, $4, $0\n"
        ".L00126818:\n"
        "    lw         $5, 0x1EC($29)\n"
        "    addu       $5, $5, $17\n"
        "    sw         $5, 0x1EC($29)\n"
        ".L00126824:\n"
        "    blez       $16, .L00127CBC\n"
        "    lw        $2, 0x18($29)\n"
        "    sb         $0, 0x1D1($29)\n"
        "    addiu      $18, $18, 0x1\n"
        "    sw         $0, 0x204($29)\n"
        "    daddu      $23, $0, $0\n"
        "    sw         $0, 0x1F0($29)\n"
        "    addiu      $20, $0, -0x1\n"
        ".L00126844:\n"
        "    lbu        $4, 0x0($18)\n"
        ".L00126848:\n"
        "    sll        $2, $4, 24\n"
        "    addiu      $18, $18, 0x1\n"
        "    sra        $17, $2, 24\n"
        ".L00126854:\n"
        "    addiu      $3, $17, -0x20\n"
        ".L00126858:\n"
        "    sltiu      $2, $3, 0x59\n"
        "    beqz       $2, .L00126F28\n"
        "    sll       $2, $3, 2\n"
        "    lui        $3, %hi(.Ljtbl_001FA980)\n"
        "    addu       $3, $3, $2\n"
        "    lw         $3, %lo(.Ljtbl_001FA980)($3)\n"
        "    jr         $3\n"
        "    nop\n"
        ".L00126878:\n"
        "    lb         $2, 0x1D1($29)\n"
        "    bnel       $2, $0, .L00126848\n"
        "    lbu       $4, 0x0($18)\n"
        "    b          .L001268C4\n"
        "    addiu     $2, $0, 0x20\n"
        "    nop\n"
        ".L00126890:\n"
        "    b          .L00126844\n"
        "    ori       $23, $23, 0x1\n"
        ".L00126898:\n"
        "    daddu      $2, $22, $0\n"
        "    addiu      $22, $22, 0x8\n"
        "    lw         $2, 0x0($2)\n"
        "    bgez       $2, .L00126844\n"
        "    sw        $2, 0x1F0($29)\n"
        "    negu       $2, $2\n"
        "    sw         $2, 0x1F0($29)\n"
        ".L001268B4:\n"
        "    b          .L00126844\n"
        "    ori       $23, $23, 0x4\n"
        "    nop\n"
        ".L001268C0:\n"
        "    addiu      $2, $0, 0x2B\n"
        ".L001268C4:\n"
        "    lbu        $4, 0x0($18)\n"
        "    b          .L00126848\n"
        "    sb        $2, 0x1D1($29)\n"
        ".L001268D0:\n"
        "    lb         $17, 0x0($18)\n"
        "    addiu      $2, $0, 0x2A\n"
        "    bne        $17, $2, .L00126900\n"
        "    addiu     $18, $18, 0x1\n"
        "    daddu      $2, $22, $0\n"
        "    lw         $16, 0x0($2)\n"
        "    daddu      $20, $16, $0\n"
        "    slti       $2, $20, -0x1\n"
        "    beqz       $2, .L00126844\n"
        "    addiu     $22, $22, 0x8\n"
        "    b          .L00126844\n"
        "    addiu     $20, $0, -0x1\n"
        ".L00126900:\n"
        "    addiu      $2, $17, -0x30\n"
        "    sltiu      $2, $2, 0xA\n"
        "    beqz       $2, .L00126938\n"
        "    daddu     $16, $0, $0\n"
        ".L00126910:\n"
        "    sll        $2, $16, 2\n"
        "    addu       $2, $2, $16\n"
        "    sll        $2, $2, 1\n"
        "    addu       $2, $2, $17\n"
        "    lb         $17, 0x0($18)\n"
        "    addiu      $16, $2, -0x30\n"
        "    addiu      $2, $17, -0x30\n"
        "    sltiu      $2, $2, 0xA\n"
        "    bnez       $2, .L00126910\n"
        "    addiu     $18, $18, 0x1\n"
        ".L00126938:\n"
        "    daddu      $20, $16, $0\n"
        "    slti       $2, $20, -0x1\n"
        "    bnel       $2, $0, .L00126854\n"
        "    addiu     $20, $0, -0x1\n"
        "    b          .L00126858\n"
        "    addiu     $3, $17, -0x20\n"
        ".L00126950:\n"
        "    b          .L00126844\n"
        "    ori       $23, $23, 0x80\n"
        ".L00126958:\n"
        "    daddu      $16, $0, $0\n"
        "    nop\n"
        ".L00126960:\n"
        "    sll        $2, $16, 2\n"
        "    addu       $2, $2, $16\n"
        "    sll        $2, $2, 1\n"
        "    addu       $2, $2, $17\n"
        "    lb         $17, 0x0($18)\n"
        "    addiu      $16, $2, -0x30\n"
        "    addiu      $2, $17, -0x30\n"
        "    sltiu      $2, $2, 0xA\n"
        "    bnez       $2, .L00126960\n"
        "    addiu     $18, $18, 0x1\n"
        "    b          .L00126854\n"
        "    sw        $16, 0x1F0($29)\n"
        ".L00126990:\n"
        "    b          .L00126844\n"
        "    ori       $23, $23, 0x8\n"
        ".L00126998:\n"
        "    b          .L00126844\n"
        "    ori       $23, $23, 0x40\n"
        ".L001269A0:\n"
        "    lb         $3, 0x0($18)\n"
        "    addiu      $2, $0, 0x6C\n"
        "    bne        $3, $2, .L001269C0\n"
        "    lbu       $4, 0x0($18)\n"
        "    addiu      $18, $18, 0x1\n"
        ".L001269B4:\n"
        "    b          .L00126844\n"
        "    ori       $23, $23, 0x20\n"
        "    nop\n"
        ".L001269C0:\n"
        "    b          .L00126848\n"
        "    ori       $23, $23, 0x10\n"
        ".L001269C8:\n"
        "    daddu      $2, $22, $0\n"
        "    addiu      $22, $22, 0x8\n"
        "    lbu        $3, 0x0($2)\n"
        "    addiu      $21, $29, 0x60\n"
        "    addiu      $30, $0, 0x1\n"
        "    b          .L00126F38\n"
        "    sb        $3, 0x0($21)\n"
        "    nop\n"
        ".L001269E8:\n"
        "    ori        $23, $23, 0x10\n"
        ".L001269EC:\n"
        "    andi       $2, $23, 0x10\n"
        "    beqz       $2, .L00126A08\n"
        "    daddu     $2, $22, $0\n"
        "    addiu      $22, $22, 0x8\n"
        "    b          .L00126A28\n"
        "    ld        $16, 0x0($2)\n"
        "    nop\n"
        ".L00126A08:\n"
        "    andi       $2, $23, 0x40\n"
        "    beqz       $2, .L00126A20\n"
        "    daddu     $2, $22, $0\n"
        "    addiu      $22, $22, 0x8\n"
        "    b          .L00126A28\n"
        "    lh        $16, 0x0($2)\n"
        ".L00126A20:\n"
        "    addiu      $22, $22, 0x8\n"
        "    lw         $16, 0x0($2)\n"
        ".L00126A28:\n"
        "    bgez       $16, .L00126E08\n"
        "    addiu     $3, $0, 0x1\n"
        "    addiu      $2, $0, 0x2D\n"
        "    dsubu      $16, $0, $16\n"
        "    b          .L00126E08\n"
        "    sb        $2, 0x1D1($29)\n"
        ".L00126A40:\n"
        "    addiu      $2, $0, -0x1\n"
        "    bne        $20, $2, .L00126A58\n"
        "    addiu     $2, $0, 0x67\n"
        "    b          .L00126A70\n"
        "    addiu     $20, $0, 0x6\n"
        "    nop\n"
        ".L00126A58:\n"
        "    beq        $17, $2, .L00126A68\n"
        "    addiu     $2, $0, 0x47\n"
        "    bne        $17, $2, .L00126A74\n"
        "    andi      $2, $23, 0x8\n"
        ".L00126A68:\n"
        "    addiu      $2, $0, 0x1\n"
        "    movz       $20, $2, $20\n"
        ".L00126A70:\n"
        "    andi       $2, $23, 0x8\n"
        ".L00126A74:\n"
        "    daddu      $2, $22, $0\n"
        "    ld         $2, 0x0($2)\n"
        "    sd         $2, 0x1F8($29)\n"
        "    ld         $4, 0x1F8($29)\n"
        "    jal        isinf\n"
        "    addiu     $22, $22, 0x8\n"
        "    beqz       $2, .L00126AC8\n"
        "    nop\n"
        "    ld         $4, 0x1F8($29)\n"
        "    daddu      $5, $0, $0\n"
        "    jal        dpcmp\n"
        "    nop\n"
        "    bgez       $2, .L00126AB8\n"
        "    lui       $2, %hi(.LD_001FA900)\n"
        "    addiu      $2, $0, 0x2D\n"
        "    sb         $2, 0x1D1($29)\n"
        "    lui        $2, %hi(.LD_001FA900)\n"
        ".L00126AB8:\n"
        "    addiu      $30, $0, 0x3\n"
        "    b          .L00126F3C\n"
        "    addiu     $21, $2, %lo(.LD_001FA900)\n"
        "    nop\n"
        ".L00126AC8:\n"
        "    ld         $4, 0x1F8($29)\n"
        "    jal        isnan\n"
        "    nop\n"
        "    beqz       $2, .L00126AE8\n"
        "    lui       $2, %hi(.LD_001FA908)\n"
        "    addiu      $30, $0, 0x3\n"
        "    b          .L00126F3C\n"
        "    addiu     $21, $2, %lo(.LD_001FA908)\n"
        ".L00126AE8:\n"
        "    ori        $23, $23, 0x100\n"
        "    lw         $4, 0x1E4($29)\n"
        "    ld         $5, 0x1F8($29)\n"
        "    daddu      $6, $20, $0\n"
        "    daddu      $7, $23, $0\n"
        "    addiu      $8, $29, 0x1D0\n"
        "    addiu      $9, $29, 0x1DC\n"
        "    daddu      $10, $17, $0\n"
        "    jal        cvt\n"
        "    addiu     $11, $29, 0x1E0\n"
        "    daddu      $21, $2, $0\n"
        "    addiu      $2, $0, 0x67\n"
        "    beq        $17, $2, .L00126B28\n"
        "    addiu     $2, $0, 0x47\n"
        "    bne        $17, $2, .L00126B58\n"
        "    lw        $7, 0x1DC($29)\n"
        ".L00126B28:\n"
        "    lw         $7, 0x1DC($29)\n"
        "    slti       $2, $7, -0x3\n"
        "    bnez       $2, .L00126B48\n"
        "    addiu     $2, $0, 0x65\n"
        "    slt        $2, $20, $7\n"
        "    beql       $2, $0, .L00126B58\n"
        "    addiu     $17, $0, 0x67\n"
        "    addiu      $2, $0, 0x65\n"
        ".L00126B48:\n"
        "    xori       $4, $17, 0x67\n"
        "    addiu      $3, $0, 0x45\n"
        "    daddu      $17, $2, $0\n"
        "    movn       $17, $3, $4\n"
        ".L00126B58:\n"
        "    slti       $2, $17, 0x66\n"
        "    beql       $2, $0, .L00126BA8\n"
        "    addiu     $2, $0, 0x66\n"
        "    addiu      $7, $7, -0x1\n"
        "    daddu      $6, $17, $0\n"
        "    daddu      $4, $29, $0\n"
        "    daddu      $5, $7, $0\n"
        "    jal        exponent\n"
        "    sw        $7, 0x1DC($29)\n"
        "    sw         $2, 0x200($29)\n"
        "    lw         $2, 0x1E0($29)\n"
        "    lw         $6, 0x200($29)\n"
        "    slti       $3, $2, 0x2\n"
        "    beqz       $3, .L00126BA0\n"
        "    addu      $30, $6, $2\n"
        "    andi       $2, $23, 0x1\n"
        "    beqz       $2, .L00126C0C\n"
        "    lb        $2, 0x1D0($29)\n"
        ".L00126BA0:\n"
        "    b          .L00126C08\n"
        "    addiu     $30, $30, 0x1\n"
        ".L00126BA8:\n"
        "    bne        $17, $2, .L00126BD8\n"
        "    lw        $5, 0x1E0($29)\n"
        "    blez       $7, .L00126C08\n"
        "    addiu     $30, $20, 0x2\n"
        "    bnez       $20, .L00126BCC\n"
        "    daddu     $30, $7, $0\n"
        "    andi       $2, $23, 0x1\n"
        "    beqz       $2, .L00126C0C\n"
        "    lb        $2, 0x1D0($29)\n"
        ".L00126BCC:\n"
        "    addu       $2, $7, $20\n"
        "    b          .L00126C08\n"
        "    addiu     $30, $2, 0x1\n"
        ".L00126BD8:\n"
        "    slt        $2, $7, $5\n"
        "    bnez       $2, .L00126BF8\n"
        "    andi      $2, $23, 0x1\n"
        "    beqz       $2, .L00126C08\n"
        "    daddu     $30, $7, $0\n"
        "    b          .L00126C08\n"
        "    addiu     $30, $7, 0x1\n"
        "    nop\n"
        ".L00126BF8:\n"
        "    bgtzl      $7, .L00126C08\n"
        "    addiu     $30, $5, 0x1\n"
        "    subu       $2, $5, $7\n"
        "    addiu      $30, $2, 0x2\n"
        ".L00126C08:\n"
        "    lb         $2, 0x1D0($29)\n"
        ".L00126C0C:\n"
        "    beqz       $2, .L00126F3C\n"
        "    addiu     $2, $0, 0x2D\n"
        "    b          .L00126F3C\n"
        "    sb        $2, 0x1D1($29)\n"
        "    nop\n"
        ".L00126C20:\n"
        "    andi       $2, $23, 0x10\n"
        "    beqz       $2, .L00126C48\n"
        "    andi      $2, $23, 0x40\n"
        "    daddu      $3, $22, $0\n"
        "    addiu      $22, $22, 0x8\n"
        "    lw         $2, 0x0($3)\n"
        "    lw         $3, 0x1EC($29)\n"
        "    b          .L00126780\n"
        "    sd        $3, 0x0($2)\n"
        "    nop\n"
        ".L00126C48:\n"
        "    beqz       $2, .L00126C68\n"
        "    daddu     $3, $22, $0\n"
        "    addiu      $22, $22, 0x8\n"
        "    lw         $2, 0x0($3)\n"
        "    lw         $4, 0x1EC($29)\n"
        "    b          .L00126780\n"
        "    sh        $4, 0x0($2)\n"
        "    nop\n"
        ".L00126C68:\n"
        "    addiu      $22, $22, 0x8\n"
        "    lw         $2, 0x0($3)\n"
        "    lw         $5, 0x1EC($29)\n"
        "    b          .L00126780\n"
        "    sw        $5, 0x0($2)\n"
        "    nop\n"
        ".L00126C80:\n"
        "    ori        $23, $23, 0x10\n"
        ".L00126C84:\n"
        "    andi       $2, $23, 0x10\n"
        "    beqz       $2, .L00126CA0\n"
        "    daddu     $2, $22, $0\n"
        "    addiu      $22, $22, 0x8\n"
        "    b          .L00126CC0\n"
        "    ld        $16, 0x0($2)\n"
        "    nop\n"
        ".L00126CA0:\n"
        "    andi       $2, $23, 0x40\n"
        "    beqz       $2, .L00126CB8\n"
        "    daddu     $2, $22, $0\n"
        "    addiu      $22, $22, 0x8\n"
        "    b          .L00126CC0\n"
        "    lhu       $16, 0x0($2)\n"
        ".L00126CB8:\n"
        "    addiu      $22, $22, 0x8\n"
        "    lwu        $16, 0x0($2)\n"
        ".L00126CC0:\n"
        "    b          .L00126E04\n"
        "    daddu     $3, $0, $0\n"
        ".L00126CC8:\n"
        "    lui        $2, %hi(.LD_001FA910)\n"
        "    daddu      $3, $22, $0\n"
        "    addiu      $2, $2, %lo(.LD_001FA910)\n"
        "    lw         $16, 0x0($3)\n"
        "    addiu      $22, $22, 0x8\n"
        "    ori        $23, $23, 0x2\n"
        "    sw         $2, 0x20C($29)\n"
        "    addiu      $3, $0, 0x2\n"
        "    b          .L00126E04\n"
        "    addiu     $17, $0, 0x78\n"
        ".L00126CF0:\n"
        "    daddu      $2, $22, $0\n"
        "    lw         $21, 0x0($2)\n"
        "    bnez       $21, .L00126D08\n"
        "    addiu     $22, $22, 0x8\n"
        "    lui        $2, %hi(.LD_001FA928)\n"
        "    addiu      $21, $2, %lo(.LD_001FA928)\n"
        ".L00126D08:\n"
        "    bltz       $20, .L00126D40\n"
        "    daddu     $5, $0, $0\n"
        "    daddu      $4, $21, $0\n"
        "    jal        memchr\n"
        "    daddu     $6, $20, $0\n"
        "    beqz       $2, .L00126F38\n"
        "    daddu     $30, $20, $0\n"
        "    subu       $30, $2, $21\n"
        "    slt        $2, $20, $30\n"
        "    beql       $2, $0, .L00126F3C\n"
        "    sb        $0, 0x1D1($29)\n"
        "    b          .L00126F38\n"
        "    daddu     $30, $20, $0\n"
        "    nop\n"
        ".L00126D40:\n"
        "    jal        strlen\n"
        "    daddu     $4, $21, $0\n"
        "    b          .L00126F38\n"
        "    daddu     $30, $2, $0\n"
        ".L00126D50:\n"
        "    ori        $23, $23, 0x10\n"
        ".L00126D54:\n"
        "    andi       $2, $23, 0x10\n"
        "    beqz       $2, .L00126D70\n"
        "    daddu     $2, $22, $0\n"
        "    addiu      $22, $22, 0x8\n"
        "    b          .L00126D90\n"
        "    ld        $16, 0x0($2)\n"
        "    nop\n"
        ".L00126D70:\n"
        "    andi       $2, $23, 0x40\n"
        "    beqz       $2, .L00126D88\n"
        "    daddu     $2, $22, $0\n"
        "    addiu      $22, $22, 0x8\n"
        "    b          .L00126D90\n"
        "    lhu       $16, 0x0($2)\n"
        ".L00126D88:\n"
        "    addiu      $22, $22, 0x8\n"
        "    lwu        $16, 0x0($2)\n"
        ".L00126D90:\n"
        "    b          .L00126E04\n"
        "    addiu     $3, $0, 0x1\n"
        ".L00126D98:\n"
        "    lui        $2, %hi(.LD_001FA930)\n"
        "    b          .L00126DB0\n"
        "    addiu     $2, $2, %lo(.LD_001FA930)\n"
        "    nop\n"
        ".L00126DA8:\n"
        "    lui        $2, %hi(.LD_001FA910)\n"
        "    addiu      $2, $2, %lo(.LD_001FA910)\n"
        ".L00126DB0:\n"
        "    sw         $2, 0x20C($29)\n"
        "    andi       $2, $23, 0x10\n"
        "    beqz       $2, .L00126DD0\n"
        "    daddu     $2, $22, $0\n"
        "    addiu      $22, $22, 0x8\n"
        "    b          .L00126DF0\n"
        "    ld        $16, 0x0($2)\n"
        "    nop\n"
        ".L00126DD0:\n"
        "    andi       $2, $23, 0x40\n"
        "    beqz       $2, .L00126DE8\n"
        "    daddu     $2, $22, $0\n"
        "    addiu      $22, $22, 0x8\n"
        "    b          .L00126DF0\n"
        "    lhu       $16, 0x0($2)\n"
        ".L00126DE8:\n"
        "    addiu      $22, $22, 0x8\n"
        "    lwu        $16, 0x0($2)\n"
        ".L00126DF0:\n"
        "    andi       $2, $23, 0x1\n"
        "    beqz       $2, .L00126E04\n"
        "    addiu     $3, $0, 0x2\n"
        "    ori        $2, $23, 0x2\n"
        "    movn       $23, $2, $16\n"
        ".L00126E04:\n"
        "    sb         $0, 0x1D1($29)\n"
        ".L00126E08:\n"
        "    bltz       $20, .L00126E18\n"
        "    sw        $20, 0x204($29)\n"
        "    addiu      $2, $0, -0x81\n"
        "    and        $23, $23, $2\n"
        ".L00126E18:\n"
        "    bnez       $16, .L00126E2C\n"
        "    addiu     $21, $29, 0x1BC\n"
        "    lw         $6, 0x204($29)\n"
        "    beqz       $6, .L00126F1C\n"
        "    subu      $2, $29, $21\n"
        ".L00126E2C:\n"
        "    addiu      $2, $0, 0x1\n"
        "    beq        $3, $2, .L00126ECC\n"
        "    sltiu     $2, $16, 0xA\n"
        "    beqz       $3, .L00126E60\n"
        "    addiu     $4, $0, 0x7\n"
        "    addiu      $2, $0, 0x2\n"
        "    beq        $3, $2, .L00126EE8\n"
        "    lui       $2, %hi(.LD_001FA948)\n"
        "    addiu      $21, $2, %lo(.LD_001FA948)\n"
        "    jal        strlen\n"
        "    daddu     $4, $21, $0\n"
        "    b          .L00126F3C\n"
        "    daddu     $30, $2, $0\n"
        ".L00126E60:\n"
        "    and        $2, $16, $4\n"
        "    dsrl       $16, $16, 3\n"
        "    daddiu     $2, $2, 0x30\n"
        "    addiu      $21, $21, -0x1\n"
        "    andi       $3, $2, 0xFF\n"
        "    bnez       $16, .L00126E60\n"
        "    sb        $3, 0x0($21)\n"
        "    andi       $2, $23, 0x1\n"
        "    beqz       $2, .L00126F18\n"
        "    addiu     $2, $0, 0x30\n"
        "    beql       $3, $2, .L00126F1C\n"
        "    subu      $2, $29, $21\n"
        "    addiu      $21, $21, -0x1\n"
        "    b          .L00126F18\n"
        "    sb        $2, 0x0($21)\n"
        "    nop\n"
        ".L00126EA0:\n"
        "    jal        __umoddi3\n"
        "    addiu     $5, $0, 0xA\n"
        "    daddu      $4, $16, $0\n"
        "    daddiu     $2, $2, 0x30\n"
        "    addiu      $21, $21, -0x1\n"
        "    andi       $2, $2, 0xFF\n"
        "    addiu      $5, $0, 0xA\n"
        "    jal        __udivdi3\n"
        "    sb        $2, 0x0($21)\n"
        "    daddu      $16, $2, $0\n"
        "    sltiu      $2, $16, 0xA\n"
        ".L00126ECC:\n"
        "    beqz       $2, .L00126EA0\n"
        "    daddu     $4, $16, $0\n"
        "    daddiu     $2, $16, 0x30\n"
        "    addiu      $21, $21, -0x1\n"
        "    andi       $2, $2, 0xFF\n"
        "    b          .L00126F18\n"
        "    sb        $2, 0x0($21)\n"
        ".L00126EE8:\n"
        "    addiu      $4, $0, 0xF\n"
        "    nop\n"
        ".L00126EF0:\n"
        "    lw         $3, 0x20C($29)\n"
        "    and        $2, $16, $4\n"
        "    dsll32     $2, $2, 0\n"
        "    dsra32     $2, $2, 0\n"
        "    addiu      $21, $21, -0x1\n"
        "    addu       $2, $3, $2\n"
        "    dsrl       $16, $16, 4\n"
        "    lbu        $3, 0x0($2)\n"
        "    bnez       $16, .L00126EF0\n"
        "    sb        $3, 0x0($21)\n"
        ".L00126F18:\n"
        "    subu       $2, $29, $21\n"
        ".L00126F1C:\n"
        "    b          .L00126F3C\n"
        "    addiu     $30, $2, 0x1BC\n"
        "    nop\n"
        ".L00126F28:\n"
        "    beqz       $17, .L00127CB8\n"
        "    addiu     $21, $29, 0x60\n"
        "    addiu      $30, $0, 0x1\n"
        "    sb         $17, 0x0($21)\n"
        ".L00126F38:\n"
        "    sb         $0, 0x1D1($29)\n"
        ".L00126F3C:\n"
        "    lw         $5, 0x204($29)\n"
        "    daddu      $4, $30, $0\n"
        "    daddu      $6, $30, $0\n"
        "    lb         $3, 0x1D1($29)\n"
        "    slt        $2, $4, $5\n"
        "    lbu        $4, 0x1D1($29)\n"
        "    movz       $5, $6, $2\n"
        "    sw         $30, 0x208($29)\n"
        "    beqz       $3, .L00126F70\n"
        "    sw        $5, 0x208($29)\n"
        "    addiu      $5, $5, 0x1\n"
        "    b          .L00126F80\n"
        "    sw        $5, 0x208($29)\n"
        ".L00126F70:\n"
        "    lw         $3, 0x208($29)\n"
        "    andi       $2, $23, 0x2\n"
        "    addu       $3, $2, $3\n"
        "    sw         $3, 0x208($29)\n"
        ".L00126F80:\n"
        "    andi       $5, $23, 0x84\n"
        "    bnez       $5, .L00127070\n"
        "    sw        $5, 0x210($29)\n"
        "    lw         $6, 0x1F0($29)\n"
        "    lw         $2, 0x208($29)\n"
        "    subu       $16, $6, $2\n"
        "    blez       $16, .L00127070\n"
        "    slti      $2, $16, 0x11\n"
        "    bnez       $2, .L00127020\n"
        "    lui       $7, %hi(.LD_001FA8E0)\n"
        "    addiu      $6, $0, 0x10\n"
        "    addiu      $20, $7, %lo(.LD_001FA8E0)\n"
        "    sw         $6, 0x4($19)\n"
        "    nop\n"
        ".L00126FB8:\n"
        "    sw         $20, 0x0($19)\n"
        "    addiu      $19, $19, 0x8\n"
        "    lw         $2, 0x14($29)\n"
        "    lw         $3, 0x18($29)\n"
        "    addiu      $2, $2, 0x1\n"
        "    addiu      $3, $3, 0x10\n"
        "    slti       $4, $2, 0x8\n"
        "    sw         $3, 0x18($29)\n"
        "    bnez       $4, .L00127008\n"
        "    sw        $2, 0x14($29)\n"
        "    lw         $4, 0x1E8($29)\n"
        "    addiu      $5, $29, 0x10\n"
        "    sq         $6, 0x220($29)\n"
        "    jal        __sprint\n"
        "    sq        $7, 0x230($29)\n"
        "    lq         $6, 0x220($29)\n"
        "    bnez       $2, .L00127CD8\n"
        "    lq        $7, 0x230($29)\n"
        "    addiu      $3, $29, 0x20\n"
        "    daddu      $19, $3, $0\n"
        ".L00127008:\n"
        "    addiu      $16, $16, -0x10\n"
        "    slti       $2, $16, 0x11\n"
        "    beql       $2, $0, .L00126FB8\n"
        "    sw        $6, 0x4($19)\n"
        "    b          .L00127024\n"
        "    sw        $16, 0x4($19)\n"
        ".L00127020:\n"
        "    sw         $16, 0x4($19)\n"
        ".L00127024:\n"
        "    addiu      $2, $7, %lo(.LD_001FA8E0)\n"
        "    sw         $2, 0x0($19)\n"
        "    addiu      $19, $19, 0x8\n"
        "    lw         $3, 0x14($29)\n"
        "    lw         $2, 0x18($29)\n"
        "    addiu      $3, $3, 0x1\n"
        "    addu       $2, $2, $16\n"
        "    slti       $4, $3, 0x8\n"
        "    sw         $2, 0x18($29)\n"
        "    bnez       $4, .L0012706C\n"
        "    sw        $3, 0x14($29)\n"
        "    lw         $4, 0x1E8($29)\n"
        "    jal        __sprint\n"
        "    addiu     $5, $29, 0x10\n"
        "    bnez       $2, .L00127CDC\n"
        "    lw        $2, 0x1E8($29)\n"
        "    addiu      $4, $29, 0x20\n"
        "    daddu      $19, $4, $0\n"
        ".L0012706C:\n"
        "    lbu        $4, 0x1D1($29)\n"
        ".L00127070:\n"
        "    beqz       $4, .L001270C8\n"
        "    addiu     $2, $0, 0x1\n"
        "    addiu      $3, $29, 0x1D1\n"
        "    sw         $2, 0x4($19)\n"
        "    sw         $3, 0x0($19)\n"
        "    addiu      $19, $19, 0x8\n"
        "    lw         $3, 0x14($29)\n"
        "    lw         $2, 0x18($29)\n"
        "    addiu      $3, $3, 0x1\n"
        "    addiu      $2, $2, 0x1\n"
        "    slti       $4, $3, 0x8\n"
        "    sw         $2, 0x18($29)\n"
        "    bnez       $4, .L0012712C\n"
        "    sw        $3, 0x14($29)\n"
        "    lw         $4, 0x1E8($29)\n"
        "    jal        __sprint\n"
        "    addiu     $5, $29, 0x10\n"
        "    bnez       $2, .L00127CDC\n"
        "    lw        $2, 0x1E8($29)\n"
        "    addiu      $5, $29, 0x20\n"
        "    b          .L0012712C\n"
        "    daddu     $19, $5, $0\n"
        ".L001270C8:\n"
        "    andi       $2, $23, 0x2\n"
        "    beqz       $2, .L0012712C\n"
        "    addiu     $2, $0, 0x30\n"
        "    addiu      $4, $0, 0x2\n"
        "    sb         $2, 0x1C0($29)\n"
        "    addiu      $3, $29, 0x1C0\n"
        "    sb         $17, 0x1C1($29)\n"
        "    sw         $4, 0x4($19)\n"
        "    sw         $3, 0x0($19)\n"
        "    addiu      $19, $19, 0x8\n"
        "    lw         $3, 0x14($29)\n"
        "    lw         $2, 0x18($29)\n"
        "    addiu      $3, $3, 0x1\n"
        "    addiu      $2, $2, 0x2\n"
        "    slti       $4, $3, 0x8\n"
        "    sw         $2, 0x18($29)\n"
        "    bnez       $4, .L0012712C\n"
        "    sw        $3, 0x14($29)\n"
        "    lw         $4, 0x1E8($29)\n"
        "    jal        __sprint\n"
        "    addiu     $5, $29, 0x10\n"
        "    bnez       $2, .L00127CDC\n"
        "    lw        $2, 0x1E8($29)\n"
        "    addiu      $6, $29, 0x20\n"
        "    daddu      $19, $6, $0\n"
        ".L0012712C:\n"
        "    lw         $3, 0x210($29)\n"
        "    addiu      $2, $0, 0x80\n"
        "    bne        $3, $2, .L00127220\n"
        "    lw        $4, 0x204($29)\n"
        "    lw         $4, 0x1F0($29)\n"
        "    lw         $5, 0x208($29)\n"
        "    subu       $16, $4, $5\n"
        "    blez       $16, .L00127220\n"
        "    lw        $4, 0x204($29)\n"
        "    slti       $2, $16, 0x11\n"
        "    bnez       $2, .L001271D0\n"
        "    lui       $7, %hi(.LD_001FA8F0)\n"
        "    addiu      $6, $0, 0x10\n"
        "    addiu      $20, $7, %lo(.LD_001FA8F0)\n"
        "    sw         $6, 0x4($19)\n"
        ".L00127168:\n"
        "    sw         $20, 0x0($19)\n"
        "    addiu      $19, $19, 0x8\n"
        "    lw         $2, 0x14($29)\n"
        "    lw         $3, 0x18($29)\n"
        "    addiu      $2, $2, 0x1\n"
        "    addiu      $3, $3, 0x10\n"
        "    slti       $4, $2, 0x8\n"
        "    sw         $3, 0x18($29)\n"
        "    bnez       $4, .L001271B8\n"
        "    sw        $2, 0x14($29)\n"
        "    lw         $4, 0x1E8($29)\n"
        "    addiu      $5, $29, 0x10\n"
        "    sq         $6, 0x220($29)\n"
        "    jal        __sprint\n"
        "    sq        $7, 0x230($29)\n"
        "    lq         $6, 0x220($29)\n"
        "    bnez       $2, .L00127CD8\n"
        "    lq        $7, 0x230($29)\n"
        "    addiu      $2, $29, 0x20\n"
        "    daddu      $19, $2, $0\n"
        ".L001271B8:\n"
        "    addiu      $16, $16, -0x10\n"
        "    slti       $2, $16, 0x11\n"
        "    beql       $2, $0, .L00127168\n"
        "    sw        $6, 0x4($19)\n"
        "    b          .L001271D4\n"
        "    sw        $16, 0x4($19)\n"
        ".L001271D0:\n"
        "    sw         $16, 0x4($19)\n"
        ".L001271D4:\n"
        "    addiu      $2, $7, %lo(.LD_001FA8F0)\n"
        "    sw         $2, 0x0($19)\n"
        "    addiu      $19, $19, 0x8\n"
        "    lw         $3, 0x14($29)\n"
        "    lw         $2, 0x18($29)\n"
        "    addiu      $3, $3, 0x1\n"
        "    addu       $2, $2, $16\n"
        "    slti       $4, $3, 0x8\n"
        "    sw         $2, 0x18($29)\n"
        "    bnez       $4, .L0012721C\n"
        "    sw        $3, 0x14($29)\n"
        "    lw         $4, 0x1E8($29)\n"
        "    jal        __sprint\n"
        "    addiu     $5, $29, 0x10\n"
        "    bnez       $2, .L00127CDC\n"
        "    lw        $2, 0x1E8($29)\n"
        "    addiu      $3, $29, 0x20\n"
        "    daddu      $19, $3, $0\n"
        ".L0012721C:\n"
        "    lw         $4, 0x204($29)\n"
        ".L00127220:\n"
        "    subu       $16, $4, $30\n"
        "    blez       $16, .L00127300\n"
        "    andi      $2, $23, 0x100\n"
        "    slti       $2, $16, 0x11\n"
        "    bnez       $2, .L001272B0\n"
        "    lui       $7, %hi(.LD_001FA8F0)\n"
        "    addiu      $6, $0, 0x10\n"
        "    addiu      $20, $7, %lo(.LD_001FA8F0)\n"
        "    sw         $6, 0x4($19)\n"
        "    nop\n"
        ".L00127248:\n"
        "    sw         $20, 0x0($19)\n"
        "    addiu      $19, $19, 0x8\n"
        "    lw         $2, 0x14($29)\n"
        "    lw         $3, 0x18($29)\n"
        "    addiu      $2, $2, 0x1\n"
        "    addiu      $3, $3, 0x10\n"
        "    slti       $4, $2, 0x8\n"
        "    sw         $3, 0x18($29)\n"
        "    bnez       $4, .L00127298\n"
        "    sw        $2, 0x14($29)\n"
        "    lw         $4, 0x1E8($29)\n"
        "    addiu      $5, $29, 0x10\n"
        "    sq         $6, 0x220($29)\n"
        "    jal        __sprint\n"
        "    sq        $7, 0x230($29)\n"
        "    lq         $6, 0x220($29)\n"
        "    bnez       $2, .L00127CD8\n"
        "    lq        $7, 0x230($29)\n"
        "    addiu      $5, $29, 0x20\n"
        "    daddu      $19, $5, $0\n"
        ".L00127298:\n"
        "    addiu      $16, $16, -0x10\n"
        "    slti       $2, $16, 0x11\n"
        "    beql       $2, $0, .L00127248\n"
        "    sw        $6, 0x4($19)\n"
        "    b          .L001272B4\n"
        "    sw        $16, 0x4($19)\n"
        ".L001272B0:\n"
        "    sw         $16, 0x4($19)\n"
        ".L001272B4:\n"
        "    addiu      $2, $7, %lo(.LD_001FA8F0)\n"
        "    sw         $2, 0x0($19)\n"
        "    addiu      $19, $19, 0x8\n"
        "    lw         $3, 0x14($29)\n"
        "    lw         $2, 0x18($29)\n"
        "    addiu      $3, $3, 0x1\n"
        "    addu       $2, $2, $16\n"
        "    slti       $4, $3, 0x8\n"
        "    sw         $2, 0x18($29)\n"
        "    bnez       $4, .L001272FC\n"
        "    sw        $3, 0x14($29)\n"
        "    lw         $4, 0x1E8($29)\n"
        "    jal        __sprint\n"
        "    addiu     $5, $29, 0x10\n"
        "    bnez       $2, .L00127CDC\n"
        "    lw        $2, 0x1E8($29)\n"
        "    addiu      $6, $29, 0x20\n"
        "    daddu      $19, $6, $0\n"
        ".L001272FC:\n"
        "    andi       $2, $23, 0x100\n"
        ".L00127300:\n"
        "    bnel       $2, $0, .L00127328\n"
        "    slti      $2, $17, 0x66\n"
        "    sw         $30, 0x4($19)\n"
        "    sw         $21, 0x0($19)\n"
        "    addiu      $19, $19, 0x8\n"
        "    lw         $2, 0x14($29)\n"
        "    lw         $3, 0x18($29)\n"
        "    addiu      $2, $2, 0x1\n"
        "    b          .L00127B60\n"
        "    addu      $3, $3, $30\n"
        ".L00127328:\n"
        "    bnez       $2, .L00127930\n"
        "    lw        $2, 0x1E0($29)\n"
        "    ld         $4, 0x1F8($29)\n"
        "    daddu      $5, $0, $0\n"
        "    jal        dpcmp\n"
        "    nop\n"
        "    bnez       $2, .L001274C0\n"
        "    lw        $3, 0x1DC($29)\n"
        "    addiu      $16, $0, 0x1\n"
        "    lui        $2, %hi(.LD_001FA968)\n"
        "    sw         $16, 0x4($19)\n"
        "    addiu      $2, $2, %lo(.LD_001FA968)\n"
        "    sw         $2, 0x0($19)\n"
        "    addiu      $19, $19, 0x8\n"
        "    lw         $3, 0x14($29)\n"
        "    lw         $2, 0x18($29)\n"
        "    addiu      $3, $3, 0x1\n"
        "    addiu      $2, $2, 0x1\n"
        "    slti       $4, $3, 0x8\n"
        "    sw         $2, 0x18($29)\n"
        "    bnez       $4, .L0012739C\n"
        "    sw        $3, 0x14($29)\n"
        "    lw         $4, 0x1E8($29)\n"
        "    jal        __sprint\n"
        "    addiu     $5, $29, 0x10\n"
        "    bnez       $2, .L00127CDC\n"
        "    lw        $2, 0x1E8($29)\n"
        "    addiu      $3, $29, 0x20\n"
        "    daddu      $19, $3, $0\n"
        ".L0012739C:\n"
        "    lw         $2, 0x1DC($29)\n"
        "    lw         $3, 0x1E0($29)\n"
        "    slt        $2, $2, $3\n"
        "    bnel       $2, $0, .L001273C0\n"
        "    sw        $16, 0x4($19)\n"
        "    andi       $2, $23, 0x1\n"
        "    beqz       $2, .L00127B94\n"
        "    andi      $2, $23, 0x4\n"
        "    sw         $16, 0x4($19)\n"
        ".L001273C0:\n"
        "    lw         $2, 0x14($29)\n"
        "    lw         $4, 0x1F4($29)\n"
        "    lw         $3, 0x18($29)\n"
        "    addiu      $2, $2, 0x1\n"
        "    sw         $4, 0x0($19)\n"
        "    addiu      $19, $19, 0x8\n"
        "    addiu      $3, $3, 0x1\n"
        "    slti       $4, $2, 0x8\n"
        "    sw         $3, 0x18($29)\n"
        "    bnez       $4, .L00127408\n"
        "    sw        $2, 0x14($29)\n"
        "    lw         $4, 0x1E8($29)\n"
        "    jal        __sprint\n"
        "    addiu     $5, $29, 0x10\n"
        "    bnez       $2, .L00127CDC\n"
        "    lw        $2, 0x1E8($29)\n"
        "    addiu      $5, $29, 0x20\n"
        "    daddu      $19, $5, $0\n"
        ".L00127408:\n"
        "    lw         $2, 0x1E0($29)\n"
        "    addiu      $16, $2, -0x1\n"
        "    blez       $16, .L00127B94\n"
        "    andi      $2, $23, 0x4\n"
        "    slti       $2, $16, 0x11\n"
        "    bnez       $2, .L00127490\n"
        "    lui       $7, %hi(.LD_001FA8F0)\n"
        "    addiu      $20, $0, 0x10\n"
        "    addiu      $17, $7, %lo(.LD_001FA8F0)\n"
        "    sw         $20, 0x4($19)\n"
        ".L00127430:\n"
        "    sw         $17, 0x0($19)\n"
        "    addiu      $19, $19, 0x8\n"
        "    lw         $2, 0x14($29)\n"
        "    lw         $3, 0x18($29)\n"
        "    addiu      $2, $2, 0x1\n"
        "    addiu      $3, $3, 0x10\n"
        "    slti       $4, $2, 0x8\n"
        "    sw         $3, 0x18($29)\n"
        "    bnez       $4, .L00127478\n"
        "    sw        $2, 0x14($29)\n"
        "    lw         $4, 0x1E8($29)\n"
        "    addiu      $5, $29, 0x10\n"
        "    jal        __sprint\n"
        "    sq        $7, 0x230($29)\n"
        "    bnez       $2, .L00127CD8\n"
        "    lq        $7, 0x230($29)\n"
        "    addiu      $6, $29, 0x20\n"
        "    daddu      $19, $6, $0\n"
        ".L00127478:\n"
        "    addiu      $16, $16, -0x10\n"
        "    slti       $2, $16, 0x11\n"
        "    beql       $2, $0, .L00127430\n"
        "    sw        $20, 0x4($19)\n"
        "    b          .L00127494\n"
        "    sw        $16, 0x4($19)\n"
        ".L00127490:\n"
        "    sw         $16, 0x4($19)\n"
        ".L00127494:\n"
        "    addiu      $2, $7, %lo(.LD_001FA8F0)\n"
        "    sw         $2, 0x0($19)\n"
        "    addiu      $19, $19, 0x8\n"
        "    lw         $3, 0x14($29)\n"
        "    lw         $2, 0x18($29)\n"
        "    addiu      $3, $3, 0x1\n"
        "    addu       $2, $2, $16\n"
        "    slti       $4, $3, 0x8\n"
        "    sw         $2, 0x18($29)\n"
        "    b          .L00127B6C\n"
        "    sw        $3, 0x14($29)\n"
        ".L001274C0:\n"
        "    bgtz       $3, .L001276A8\n"
        "    lw        $2, 0x1E0($29)\n"
        "    addiu      $16, $0, 0x1\n"
        "    lui        $2, %hi(.LD_001FA968)\n"
        "    sw         $16, 0x4($19)\n"
        "    addiu      $2, $2, %lo(.LD_001FA968)\n"
        "    sw         $2, 0x0($19)\n"
        "    addiu      $19, $19, 0x8\n"
        "    lw         $3, 0x14($29)\n"
        "    lw         $2, 0x18($29)\n"
        "    addiu      $3, $3, 0x1\n"
        "    addiu      $2, $2, 0x1\n"
        "    slti       $4, $3, 0x8\n"
        "    sw         $2, 0x18($29)\n"
        "    bnez       $4, .L0012751C\n"
        "    sw        $3, 0x14($29)\n"
        "    lw         $4, 0x1E8($29)\n"
        "    jal        __sprint\n"
        "    addiu     $5, $29, 0x10\n"
        "    bnez       $2, .L00127CDC\n"
        "    lw        $2, 0x1E8($29)\n"
        "    addiu      $3, $29, 0x20\n"
        "    daddu      $19, $3, $0\n"
        ".L0012751C:\n"
        "    lw         $2, 0x1DC($29)\n"
        "    bnel       $2, $0, .L00127538\n"
        "    sw        $16, 0x4($19)\n"
        "    lw         $2, 0x1E0($29)\n"
        "    beqz       $2, .L00127B94\n"
        "    andi      $2, $23, 0x4\n"
        "    sw         $16, 0x4($19)\n"
        ".L00127538:\n"
        "    lw         $2, 0x14($29)\n"
        "    lw         $4, 0x1F4($29)\n"
        "    lw         $3, 0x18($29)\n"
        "    addiu      $2, $2, 0x1\n"
        "    sw         $4, 0x0($19)\n"
        "    addiu      $19, $19, 0x8\n"
        "    addiu      $3, $3, 0x1\n"
        "    slti       $4, $2, 0x8\n"
        "    sw         $3, 0x18($29)\n"
        "    bnez       $4, .L00127580\n"
        "    sw        $2, 0x14($29)\n"
        "    lw         $4, 0x1E8($29)\n"
        "    jal        __sprint\n"
        "    addiu     $5, $29, 0x10\n"
        "    bnez       $2, .L00127CDC\n"
        "    lw        $2, 0x1E8($29)\n"
        "    addiu      $5, $29, 0x20\n"
        "    daddu      $19, $5, $0\n"
        ".L00127580:\n"
        "    lw         $2, 0x1DC($29)\n"
        "    negu       $16, $2\n"
        "    blezl      $16, .L00127658\n"
        "    sw        $21, 0x0($19)\n"
        "    slti       $2, $16, 0x11\n"
        "    bnez       $2, .L00127608\n"
        "    lui       $7, %hi(.LD_001FA8F0)\n"
        "    addiu      $20, $0, 0x10\n"
        "    addiu      $17, $7, %lo(.LD_001FA8F0)\n"
        "    sw         $20, 0x4($19)\n"
        ".L001275A8:\n"
        "    sw         $17, 0x0($19)\n"
        "    addiu      $19, $19, 0x8\n"
        "    lw         $2, 0x14($29)\n"
        "    lw         $3, 0x18($29)\n"
        "    addiu      $2, $2, 0x1\n"
        "    addiu      $3, $3, 0x10\n"
        "    slti       $4, $2, 0x8\n"
        "    sw         $3, 0x18($29)\n"
        "    bnez       $4, .L001275F0\n"
        "    sw        $2, 0x14($29)\n"
        "    lw         $4, 0x1E8($29)\n"
        "    addiu      $5, $29, 0x10\n"
        "    jal        __sprint\n"
        "    sq        $7, 0x230($29)\n"
        "    bnez       $2, .L00127CD8\n"
        "    lq        $7, 0x230($29)\n"
        "    addiu      $6, $29, 0x20\n"
        "    daddu      $19, $6, $0\n"
        ".L001275F0:\n"
        "    addiu      $16, $16, -0x10\n"
        "    slti       $2, $16, 0x11\n"
        "    beql       $2, $0, .L001275A8\n"
        "    sw        $20, 0x4($19)\n"
        "    b          .L0012760C\n"
        "    sw        $16, 0x4($19)\n"
        ".L00127608:\n"
        "    sw         $16, 0x4($19)\n"
        ".L0012760C:\n"
        "    addiu      $2, $7, %lo(.LD_001FA8F0)\n"
        "    sw         $2, 0x0($19)\n"
        "    addiu      $19, $19, 0x8\n"
        "    lw         $3, 0x14($29)\n"
        "    lw         $2, 0x18($29)\n"
        "    addiu      $3, $3, 0x1\n"
        "    addu       $2, $2, $16\n"
        "    slti       $4, $3, 0x8\n"
        "    sw         $2, 0x18($29)\n"
        "    bnez       $4, .L00127654\n"
        "    sw        $3, 0x14($29)\n"
        "    lw         $4, 0x1E8($29)\n"
        "    jal        __sprint\n"
        "    addiu     $5, $29, 0x10\n"
        "    bnez       $2, .L00127CDC\n"
        "    lw        $2, 0x1E8($29)\n"
        "    addiu      $2, $29, 0x20\n"
        "    daddu      $19, $2, $0\n"
        ".L00127654:\n"
        "    sw         $21, 0x0($19)\n"
        ".L00127658:\n"
        "    lw         $2, 0x1E0($29)\n"
        "    sw         $2, 0x4($19)\n"
        "    addiu      $19, $19, 0x8\n"
        "    lw         $2, 0x14($29)\n"
        "    lw         $3, 0x18($29)\n"
        "    lw         $4, 0x1E0($29)\n"
        "    addiu      $2, $2, 0x1\n"
        "    slti       $5, $2, 0x8\n"
        "    sw         $2, 0x14($29)\n"
        "    addu       $3, $3, $4\n"
        "    bnez       $5, .L00127B90\n"
        "    sw        $3, 0x18($29)\n"
        "    lw         $4, 0x1E8($29)\n"
        "    jal        __sprint\n"
        "    addiu     $5, $29, 0x10\n"
        "    bnez       $2, .L00127CDC\n"
        "    lw        $2, 0x1E8($29)\n"
        "    addiu      $3, $29, 0x20\n"
        "    b          .L00127B90\n"
        "    daddu     $19, $3, $0\n"
        ".L001276A8:\n"
        "    slt        $2, $3, $2\n"
        "    bnez       $2, .L00127820\n"
        "    sw        $21, 0x0($19)\n"
        "    lw         $2, 0x1E0($29)\n"
        "    sw         $2, 0x4($19)\n"
        "    addiu      $19, $19, 0x8\n"
        "    lw         $2, 0x14($29)\n"
        "    lw         $3, 0x18($29)\n"
        "    lw         $5, 0x1E0($29)\n"
        "    addiu      $2, $2, 0x1\n"
        "    slti       $4, $2, 0x8\n"
        "    sw         $2, 0x14($29)\n"
        "    addu       $3, $3, $5\n"
        "    bnez       $4, .L00127704\n"
        "    sw        $3, 0x18($29)\n"
        "    lw         $4, 0x1E8($29)\n"
        "    jal        __sprint\n"
        "    addiu     $5, $29, 0x10\n"
        "    bnez       $2, .L00127CDC\n"
        "    lw        $2, 0x1E8($29)\n"
        "    addiu      $4, $29, 0x20\n"
        "    lw         $5, 0x1E0($29)\n"
        "    daddu      $19, $4, $0\n"
        ".L00127704:\n"
        "    lw         $2, 0x1DC($29)\n"
        "    subu       $16, $2, $5\n"
        "    blez       $16, .L001277E0\n"
        "    andi      $2, $23, 0x1\n"
        "    slti       $2, $16, 0x11\n"
        "    bnez       $2, .L00127790\n"
        "    lui       $7, %hi(.LD_001FA8F0)\n"
        "    addiu      $20, $0, 0x10\n"
        "    addiu      $17, $7, %lo(.LD_001FA8F0)\n"
        "    sw         $20, 0x4($19)\n"
        "    nop\n"
        ".L00127730:\n"
        "    sw         $17, 0x0($19)\n"
        "    addiu      $19, $19, 0x8\n"
        "    lw         $2, 0x14($29)\n"
        "    lw         $3, 0x18($29)\n"
        "    addiu      $2, $2, 0x1\n"
        "    addiu      $3, $3, 0x10\n"
        "    slti       $4, $2, 0x8\n"
        "    sw         $3, 0x18($29)\n"
        "    bnez       $4, .L00127778\n"
        "    sw        $2, 0x14($29)\n"
        "    lw         $4, 0x1E8($29)\n"
        "    addiu      $5, $29, 0x10\n"
        "    jal        __sprint\n"
        "    sq        $7, 0x230($29)\n"
        "    bnez       $2, .L00127CD8\n"
        "    lq        $7, 0x230($29)\n"
        "    addiu      $5, $29, 0x20\n"
        "    daddu      $19, $5, $0\n"
        ".L00127778:\n"
        "    addiu      $16, $16, -0x10\n"
        "    slti       $2, $16, 0x11\n"
        "    beql       $2, $0, .L00127730\n"
        "    sw        $20, 0x4($19)\n"
        "    b          .L00127794\n"
        "    sw        $16, 0x4($19)\n"
        ".L00127790:\n"
        "    sw         $16, 0x4($19)\n"
        ".L00127794:\n"
        "    addiu      $2, $7, %lo(.LD_001FA8F0)\n"
        "    sw         $2, 0x0($19)\n"
        "    addiu      $19, $19, 0x8\n"
        "    lw         $3, 0x14($29)\n"
        "    lw         $2, 0x18($29)\n"
        "    addiu      $3, $3, 0x1\n"
        "    addu       $2, $2, $16\n"
        "    slti       $4, $3, 0x8\n"
        "    sw         $2, 0x18($29)\n"
        "    bnez       $4, .L001277DC\n"
        "    sw        $3, 0x14($29)\n"
        "    lw         $4, 0x1E8($29)\n"
        "    jal        __sprint\n"
        "    addiu     $5, $29, 0x10\n"
        "    bnez       $2, .L00127CDC\n"
        "    lw        $2, 0x1E8($29)\n"
        "    addiu      $6, $29, 0x20\n"
        "    daddu      $19, $6, $0\n"
        ".L001277DC:\n"
        "    andi       $2, $23, 0x1\n"
        ".L001277E0:\n"
        "    beqz       $2, .L00127B90\n"
        "    addiu     $3, $0, 0x1\n"
        "    lui        $2, %hi(.LD_001FA970)\n"
        "    sw         $3, 0x4($19)\n"
        "    addiu      $2, $2, %lo(.LD_001FA970)\n"
        "    sw         $2, 0x0($19)\n"
        "    addiu      $19, $19, 0x8\n"
        "    lw         $3, 0x14($29)\n"
        "    lw         $2, 0x18($29)\n"
        "    addiu      $3, $3, 0x1\n"
        "    addiu      $2, $2, 0x1\n"
        "    slti       $4, $3, 0x8\n"
        "    sw         $2, 0x18($29)\n"
        "    b          .L00127B6C\n"
        "    sw        $3, 0x14($29)\n"
        "    nop\n"
        ".L00127820:\n"
        "    lw         $2, 0x1DC($29)\n"
        "    sw         $2, 0x4($19)\n"
        "    addiu      $19, $19, 0x8\n"
        "    lw         $2, 0x14($29)\n"
        "    lw         $3, 0x18($29)\n"
        "    lw         $7, 0x1DC($29)\n"
        "    addiu      $2, $2, 0x1\n"
        "    slti       $4, $2, 0x8\n"
        "    sw         $2, 0x14($29)\n"
        "    addu       $3, $3, $7\n"
        "    bnez       $4, .L00127870\n"
        "    sw        $3, 0x18($29)\n"
        "    lw         $4, 0x1E8($29)\n"
        "    jal        __sprint\n"
        "    addiu     $5, $29, 0x10\n"
        "    bnez       $2, .L00127CDC\n"
        "    lw        $2, 0x1E8($29)\n"
        "    addiu      $3, $29, 0x20\n"
        "    lw         $7, 0x1DC($29)\n"
        "    daddu      $19, $3, $0\n"
        ".L00127870:\n"
        "    addiu      $3, $0, 0x1\n"
        "    lui        $2, %hi(.LD_001FA970)\n"
        "    sw         $3, 0x4($19)\n"
        "    addiu      $2, $2, %lo(.LD_001FA970)\n"
        "    sw         $2, 0x0($19)\n"
        "    addiu      $19, $19, 0x8\n"
        "    lw         $3, 0x14($29)\n"
        "    addu       $21, $21, $7\n"
        "    lw         $2, 0x18($29)\n"
        "    addiu      $3, $3, 0x1\n"
        "    addiu      $2, $2, 0x1\n"
        "    slti       $4, $3, 0x8\n"
        "    sw         $2, 0x18($29)\n"
        "    bnez       $4, .L001278C8\n"
        "    sw        $3, 0x14($29)\n"
        "    lw         $4, 0x1E8($29)\n"
        "    jal        __sprint\n"
        "    addiu     $5, $29, 0x10\n"
        "    bnez       $2, .L00127CDC\n"
        "    lw        $2, 0x1E8($29)\n"
        "    addiu      $4, $29, 0x20\n"
        "    daddu      $19, $4, $0\n"
        ".L001278C8:\n"
        "    sw         $21, 0x0($19)\n"
        "    lw         $3, 0x1DC($29)\n"
        "    lw         $2, 0x1E0($29)\n"
        "    subu       $2, $2, $3\n"
        "    sw         $2, 0x4($19)\n"
        "    addiu      $19, $19, 0x8\n"
        "    lw         $3, 0x14($29)\n"
        "    lw         $4, 0x1E0($29)\n"
        "    lw         $5, 0x1DC($29)\n"
        "    addiu      $3, $3, 0x1\n"
        "    lw         $2, 0x18($29)\n"
        "    slti       $6, $3, 0x8\n"
        "    subu       $4, $4, $5\n"
        "    sw         $3, 0x14($29)\n"
        "    addu       $2, $2, $4\n"
        "    bnez       $6, .L00127B90\n"
        "    sw        $2, 0x18($29)\n"
        "    lw         $4, 0x1E8($29)\n"
        "    jal        __sprint\n"
        "    addiu     $5, $29, 0x10\n"
        "    bnez       $2, .L00127CDC\n"
        "    lw        $2, 0x1E8($29)\n"
        "    addiu      $5, $29, 0x20\n"
        "    b          .L00127B90\n"
        "    daddu     $19, $5, $0\n"
        "    nop\n"
        ".L00127930:\n"
        "    slti       $2, $2, 0x2\n"
        "    beql       $2, $0, .L0012794C\n"
        "    lbu       $3, 0x0($21)\n"
        "    andi       $2, $23, 0x1\n"
        "    beqz       $2, .L00127AF8\n"
        "    addiu     $2, $0, 0x1\n"
        "    lbu        $3, 0x0($21)\n"
        ".L0012794C:\n"
        "    addiu      $21, $21, 0x1\n"
        "    addiu      $4, $0, 0x2E\n"
        "    addiu      $5, $0, 0x2\n"
        "    sb         $3, 0x1C0($29)\n"
        "    addiu      $2, $29, 0x1C0\n"
        "    sb         $4, 0x1C1($29)\n"
        "    sw         $5, 0x4($19)\n"
        "    sw         $2, 0x0($19)\n"
        "    addiu      $19, $19, 0x8\n"
        "    lw         $3, 0x14($29)\n"
        "    lw         $2, 0x18($29)\n"
        "    addiu      $3, $3, 0x1\n"
        "    addiu      $2, $2, 0x2\n"
        "    slti       $4, $3, 0x8\n"
        "    sw         $2, 0x18($29)\n"
        "    bnez       $4, .L001279AC\n"
        "    sw        $3, 0x14($29)\n"
        "    lw         $4, 0x1E8($29)\n"
        "    jal        __sprint\n"
        "    addiu     $5, $29, 0x10\n"
        "    bnez       $2, .L00127CDC\n"
        "    lw        $2, 0x1E8($29)\n"
        "    addiu      $6, $29, 0x20\n"
        "    daddu      $19, $6, $0\n"
        ".L001279AC:\n"
        "    ld         $4, 0x1F8($29)\n"
        "    daddu      $5, $0, $0\n"
        "    jal        dpcmp\n"
        "    nop\n"
        "    beqz       $2, .L00127A20\n"
        "    lw        $2, 0x1E0($29)\n"
        "    sw         $21, 0x0($19)\n"
        "    lw         $2, 0x1E0($29)\n"
        "    addiu      $2, $2, -0x1\n"
        "    sw         $2, 0x4($19)\n"
        "    addiu      $19, $19, 0x8\n"
        "    lw         $3, 0x18($29)\n"
        "    lw         $2, 0x14($29)\n"
        "    lw         $4, 0x1E0($29)\n"
        "    addiu      $2, $2, 0x1\n"
        "    addu       $3, $3, $4\n"
        "    slti       $5, $2, 0x8\n"
        "    addiu      $3, $3, -0x1\n"
        "    sw         $2, 0x14($29)\n"
        "    bnez       $5, .L00127B40\n"
        "    sw        $3, 0x18($29)\n"
        "    lw         $4, 0x1E8($29)\n"
        "    jal        __sprint\n"
        "    addiu     $5, $29, 0x10\n"
        "    bnez       $2, .L00127CDC\n"
        "    lw        $2, 0x1E8($29)\n"
        "    addiu      $2, $29, 0x20\n"
        "    b          .L00127B40\n"
        "    daddu     $19, $2, $0\n"
        ".L00127A20:\n"
        "    addiu      $16, $2, -0x1\n"
        "    blez       $16, .L00127B44\n"
        "    lw        $6, 0x200($29)\n"
        "    slti       $2, $16, 0x11\n"
        "    bnez       $2, .L00127AA8\n"
        "    lui       $7, %hi(.LD_001FA8F0)\n"
        "    addiu      $20, $0, 0x10\n"
        "    addiu      $17, $7, %lo(.LD_001FA8F0)\n"
        "    sw         $20, 0x4($19)\n"
        "    nop\n"
        ".L00127A48:\n"
        "    sw         $17, 0x0($19)\n"
        "    addiu      $19, $19, 0x8\n"
        "    lw         $2, 0x14($29)\n"
        "    lw         $3, 0x18($29)\n"
        "    addiu      $2, $2, 0x1\n"
        "    addiu      $3, $3, 0x10\n"
        "    slti       $4, $2, 0x8\n"
        "    sw         $3, 0x18($29)\n"
        "    bnez       $4, .L00127A90\n"
        "    sw        $2, 0x14($29)\n"
        "    lw         $4, 0x1E8($29)\n"
        "    addiu      $5, $29, 0x10\n"
        "    jal        __sprint\n"
        "    sq        $7, 0x230($29)\n"
        "    bnez       $2, .L00127CD8\n"
        "    lq        $7, 0x230($29)\n"
        "    addiu      $3, $29, 0x20\n"
        "    daddu      $19, $3, $0\n"
        ".L00127A90:\n"
        "    addiu      $16, $16, -0x10\n"
        "    slti       $2, $16, 0x11\n"
        "    beql       $2, $0, .L00127A48\n"
        "    sw        $20, 0x4($19)\n"
        "    b          .L00127AAC\n"
        "    sw        $16, 0x4($19)\n"
        ".L00127AA8:\n"
        "    sw         $16, 0x4($19)\n"
        ".L00127AAC:\n"
        "    addiu      $2, $7, %lo(.LD_001FA8F0)\n"
        "    sw         $2, 0x0($19)\n"
        "    addiu      $19, $19, 0x8\n"
        "    lw         $3, 0x14($29)\n"
        "    lw         $2, 0x18($29)\n"
        "    addiu      $3, $3, 0x1\n"
        "    addu       $2, $2, $16\n"
        "    slti       $4, $3, 0x8\n"
        "    sw         $2, 0x18($29)\n"
        "    bnez       $4, .L00127B40\n"
        "    sw        $3, 0x14($29)\n"
        "    lw         $4, 0x1E8($29)\n"
        "    jal        __sprint\n"
        "    addiu     $5, $29, 0x10\n"
        "    bnez       $2, .L00127CDC\n"
        "    lw        $2, 0x1E8($29)\n"
        "    addiu      $4, $29, 0x20\n"
        "    b          .L00127B40\n"
        "    daddu     $19, $4, $0\n"
        ".L00127AF8:\n"
        "    sw         $21, 0x0($19)\n"
        "    sw         $2, 0x4($19)\n"
        "    addiu      $19, $19, 0x8\n"
        "    lw         $3, 0x14($29)\n"
        "    lw         $2, 0x18($29)\n"
        "    addiu      $3, $3, 0x1\n"
        "    addiu      $2, $2, 0x1\n"
        "    slti       $4, $3, 0x8\n"
        "    sw         $2, 0x18($29)\n"
        "    bnez       $4, .L00127B40\n"
        "    sw        $3, 0x14($29)\n"
        "    lw         $4, 0x1E8($29)\n"
        "    jal        __sprint\n"
        "    addiu     $5, $29, 0x10\n"
        "    bnez       $2, .L00127CDC\n"
        "    lw        $2, 0x1E8($29)\n"
        "    addiu      $5, $29, 0x20\n"
        "    daddu      $19, $5, $0\n"
        ".L00127B40:\n"
        "    lw         $6, 0x200($29)\n"
        ".L00127B44:\n"
        "    sw         $29, 0x0($19)\n"
        "    sw         $6, 0x4($19)\n"
        "    addiu      $19, $19, 0x8\n"
        "    lw         $2, 0x14($29)\n"
        "    lw         $3, 0x18($29)\n"
        "    addiu      $2, $2, 0x1\n"
        "    addu       $3, $3, $6\n"
        ".L00127B60:\n"
        "    slti       $4, $2, 0x8\n"
        "    sw         $3, 0x18($29)\n"
        "    sw         $2, 0x14($29)\n"
        ".L00127B6C:\n"
        "    bnez       $4, .L00127B94\n"
        "    andi      $2, $23, 0x4\n"
        "    lw         $4, 0x1E8($29)\n"
        "    jal        __sprint\n"
        "    addiu     $5, $29, 0x10\n"
        "    bnez       $2, .L00127CDC\n"
        "    lw        $2, 0x1E8($29)\n"
        "    addiu      $2, $29, 0x20\n"
        "    daddu      $19, $2, $0\n"
        ".L00127B90:\n"
        "    andi       $2, $23, 0x4\n"
        ".L00127B94:\n"
        "    beqz       $2, .L00127C68\n"
        "    lw        $3, 0x1F0($29)\n"
        "    lw         $4, 0x208($29)\n"
        "    subu       $16, $3, $4\n"
        "    blez       $16, .L00127C70\n"
        "    lw        $6, 0x208($29)\n"
        "    slti       $2, $16, 0x11\n"
        "    bnez       $2, .L00127C28\n"
        "    lui       $7, %hi(.LD_001FA8E0)\n"
        "    addiu      $20, $0, 0x10\n"
        "    addiu      $17, $7, %lo(.LD_001FA8E0)\n"
        "    sw         $20, 0x4($19)\n"
        "    nop\n"
        ".L00127BC8:\n"
        "    sw         $17, 0x0($19)\n"
        "    addiu      $19, $19, 0x8\n"
        "    lw         $2, 0x14($29)\n"
        "    lw         $3, 0x18($29)\n"
        "    addiu      $2, $2, 0x1\n"
        "    addiu      $3, $3, 0x10\n"
        "    slti       $4, $2, 0x8\n"
        "    sw         $3, 0x18($29)\n"
        "    bnez       $4, .L00127C10\n"
        "    sw        $2, 0x14($29)\n"
        "    lw         $4, 0x1E8($29)\n"
        "    addiu      $5, $29, 0x10\n"
        "    jal        __sprint\n"
        "    sq        $7, 0x230($29)\n"
        "    bnez       $2, .L00127CD8\n"
        "    lq        $7, 0x230($29)\n"
        "    addiu      $5, $29, 0x20\n"
        "    daddu      $19, $5, $0\n"
        ".L00127C10:\n"
        "    addiu      $16, $16, -0x10\n"
        "    slti       $2, $16, 0x11\n"
        "    beql       $2, $0, .L00127BC8\n"
        "    sw        $20, 0x4($19)\n"
        "    b          .L00127C2C\n"
        "    sw        $16, 0x4($19)\n"
        ".L00127C28:\n"
        "    sw         $16, 0x4($19)\n"
        ".L00127C2C:\n"
        "    addiu      $2, $7, %lo(.LD_001FA8E0)\n"
        "    sw         $2, 0x0($19)\n"
        "    lw         $3, 0x14($29)\n"
        "    lw         $2, 0x18($29)\n"
        "    addiu      $3, $3, 0x1\n"
        "    addu       $2, $2, $16\n"
        "    slti       $4, $3, 0x8\n"
        "    sw         $2, 0x18($29)\n"
        "    bnez       $4, .L00127C68\n"
        "    sw        $3, 0x14($29)\n"
        "    lw         $4, 0x1E8($29)\n"
        "    jal        __sprint\n"
        "    addiu     $5, $29, 0x10\n"
        "    bnez       $2, .L00127CDC\n"
        "    lw        $2, 0x1E8($29)\n"
        ".L00127C68:\n"
        "    lw         $6, 0x208($29)\n"
        "    lw         $3, 0x1F0($29)\n"
        ".L00127C70:\n"
        "    lw         $4, 0x1F0($29)\n"
        "    slt        $2, $6, $3\n"
        "    lw         $3, 0x18($29)\n"
        "    lw         $5, 0x1EC($29)\n"
        "    movz       $4, $6, $2\n"
        "    addu       $5, $5, $4\n"
        "    beqz       $3, .L00127CA4\n"
        "    sw        $5, 0x1EC($29)\n"
        "    lw         $4, 0x1E8($29)\n"
        "    jal        __sprint\n"
        "    addiu     $5, $29, 0x10\n"
        "    bnez       $2, .L00127CDC\n"
        "    lw        $2, 0x1E8($29)\n"
        ".L00127CA4:\n"
        "    addiu      $6, $29, 0x20\n"
        "    sw         $0, 0x14($29)\n"
        "    b          .L00126780\n"
        "    daddu     $19, $6, $0\n"
        "    nop\n"
        ".L00127CB8:\n"
        "    lw         $2, 0x18($29)\n"
        ".L00127CBC:\n"
        "    beqz       $2, .L00127CD4\n"
        "    lw        $4, 0x1E8($29)\n"
        "    jal        __sprint\n"
        "    addiu     $5, $29, 0x10\n"
        "    bnez       $2, .L00127CDC\n"
        "    lw        $2, 0x1E8($29)\n"
        ".L00127CD4:\n"
        "    sw         $0, 0x14($29)\n"
        ".L00127CD8:\n"
        "    lw         $2, 0x1E8($29)\n"
        ".L00127CDC:\n"
        "    lw         $4, 0x1EC($29)\n"
        "    lhu        $3, 0xC($2)\n"
        "    addiu      $2, $0, -0x1\n"
        "    andi       $3, $3, 0x40\n"
        "    movz       $2, $4, $3\n"
        ".L00127CF0:\n"
        "    ld         $16, 0x240($29)\n"
        ".L00127CF4:\n"
        "    ld         $17, 0x248($29)\n"
        "    ld         $18, 0x250($29)\n"
        "    ld         $19, 0x258($29)\n"
        "    ld         $20, 0x260($29)\n"
        "    ld         $21, 0x268($29)\n"
        "    ld         $22, 0x270($29)\n"
        "    ld         $23, 0x278($29)\n"
        "    ld         $30, 0x280($29)\n"
        "    ld         $31, 0x288($29)\n"
        "    jr         $31\n"
        "    addiu     $29, $29, 0x290\n"
        "    .size _vfprintf_r, . - _vfprintf_r\n"
        "    .section .rodata\n"
        ".align 4\n"
        ".LD_001FA8E0:\n"
        ".word 0x20202020\n"
        ".word 0x20202020\n"
        ".word 0x20202020\n"
        ".word 0x20202020\n"
        ".LD_001FA8F0:\n"
        ".word 0x30303030\n"
        ".word 0x30303030\n"
        ".word 0x30303030\n"
        ".word 0x30303030\n"
        ".align 2\n"
        ".LD_001FA900:\n"
        ".asciz \"Inf\"\n"
        ".align 2\n"
        ".align 2\n"
        ".asciz \"\"\n"
        ".align 2\n"
        ".align 2\n"
        ".LD_001FA908:\n"
        ".asciz \"NaN\"\n"
        ".align 2\n"
        ".align 2\n"
        ".asciz \"\"\n"
        ".align 2\n"
        ".LD_001FA910:\n"
        ".word 0x33323130\n"
        ".word 0x37363534\n"
        ".word 0x62613938\n"
        ".word 0x66656463\n"
        ".word 0x00000000\n"
        ".word 0x00000000\n"
        ".align 2\n"
        ".LD_001FA928:\n"
        ".asciz \"(null)\"\n"
        ".align 2\n"
        ".align 2\n"
        ".LD_001FA930:\n"
        ".asciz \"0123456789ABCDEF\"\n"
        ".align 2\n"
        ".align 2\n"
        ".asciz \"\"\n"
        ".align 2\n"
        ".align 2\n"
        ".LD_001FA948:\n"
        ".asciz \"bug in vfprintf: bad base\"\n"
        ".align 2\n"
        ".align 2\n"
        ".asciz \"\"\n"
        ".align 2\n"
        ".LD_001FA968:\n"
        ".word 0x00000030\n"
        ".word 0x00000000\n"
        ".LD_001FA970:\n"
        ".word 0x0000002E\n"
        ".word 0x00000000\n"
        ".word 0x00000000\n"
        ".word 0x00000000\n"
        ".align 4\n"
        ".Ljtbl_001FA980:\n"
        ".word .L00126878\n"
        ".word .L00126F28\n"
        ".word .L00126F28\n"
        ".word .L00126890\n"
        ".word .L00126F28\n"
        ".word .L00126F28\n"
        ".word .L00126F28\n"
        ".word .L00126F28\n"
        ".word .L00126F28\n"
        ".word .L00126F28\n"
        ".word .L00126898\n"
        ".word .L001268C0\n"
        ".word .L00126F28\n"
        ".word .L001268B4\n"
        ".word .L001268D0\n"
        ".word .L00126F28\n"
        ".word .L00126950\n"
        ".word .L00126958\n"
        ".word .L00126958\n"
        ".word .L00126958\n"
        ".word .L00126958\n"
        ".word .L00126958\n"
        ".word .L00126958\n"
        ".word .L00126958\n"
        ".word .L00126958\n"
        ".word .L00126958\n"
        ".word .L00126F28\n"
        ".word .L00126F28\n"
        ".word .L00126F28\n"
        ".word .L00126F28\n"
        ".word .L00126F28\n"
        ".word .L00126F28\n"
        ".word .L00126F28\n"
        ".word .L00126F28\n"
        ".word .L00126F28\n"
        ".word .L00126F28\n"
        ".word .L001269E8\n"
        ".word .L00126A40\n"
        ".word .L00126F28\n"
        ".word .L00126A40\n"
        ".word .L00126F28\n"
        ".word .L00126F28\n"
        ".word .L00126F28\n"
        ".word .L00126F28\n"
        ".word .L00126990\n"
        ".word .L00126F28\n"
        ".word .L00126F28\n"
        ".word .L00126C80\n"
        ".word .L00126F28\n"
        ".word .L00126F28\n"
        ".word .L00126F28\n"
        ".word .L00126F28\n"
        ".word .L00126F28\n"
        ".word .L00126D50\n"
        ".word .L00126F28\n"
        ".word .L00126F28\n"
        ".word .L00126D98\n"
        ".word .L00126F28\n"
        ".word .L00126F28\n"
        ".word .L00126F28\n"
        ".word .L00126F28\n"
        ".word .L00126F28\n"
        ".word .L00126F28\n"
        ".word .L00126F28\n"
        ".word .L00126F28\n"
        ".word .L00126F28\n"
        ".word .L00126F28\n"
        ".word .L001269C8\n"
        ".word .L001269EC\n"
        ".word .L00126A40\n"
        ".word .L00126A40\n"
        ".word .L00126A40\n"
        ".word .L00126998\n"
        ".word .L001269EC\n"
        ".word .L00126F28\n"
        ".word .L00126F28\n"
        ".word .L001269A0\n"
        ".word .L00126F28\n"
        ".word .L00126C20\n"
        ".word .L00126C84\n"
        ".word .L00126CC8\n"
        ".word .L001269B4\n"
        ".word .L00126F28\n"
        ".word .L00126CF0\n"
        ".word .L00126F28\n"
        ".word .L00126D54\n"
        ".word .L00126F28\n"
        ".word .L00126F28\n"
        ".word .L00126DA8\n"
        ".word 0x00000000\n"
        "    .section .text\n"
        "    .set reorder\n"
        "    .set at\n");

static char *cvt(data, value, ndigits, flags, sign, decpt, ch, length)
Reent *data;

double value;

int ndigits, flags, *decpt, ch, *length;

char *sign;

{
    int mode, dsgn;
    char *digits, *bp, *rve;
    union double_union tmp;

    if (ch == 'f') {
        mode = 3; /* ndigits after the decimal point */
    } else {
        /* To obtain ndigits after the decimal point for the 'e'
         * and 'E' formats, round to ndigits + 1 significant
         * figures.
         */
        if (ch == 'e' || ch == 'E') {
            ndigits++;
        }
        mode = 2; /* ndigits significant digits */
    }

    tmp.d = value;
    if (word0(tmp) & Sign_bit) { /* this will check for < 0 and -0.0 */
        value = -value;
        *sign = '-';
    } else
        *sign = '\000';
    digits = _dtoa_r(data, value, mode, ndigits, decpt, &dsgn, &rve);
    if ((ch != 'g' && ch != 'G') || flags & ALT) { /* Print trailing zeros */
        bp = digits + ndigits;
        if (ch == 'f') {
            if (*digits == '0' && value)
                *decpt = -ndigits + 1;
            bp += *decpt;
        }
        if (value == 0) /* kludge for __dtoa irregularity */
            rve = bp;
        while (rve < bp)
            *rve++ = '0';
    }
    *length = rve - digits;
    return (digits);
}

static int exponent(p0, exp, fmtch)
char *p0;

int exp, fmtch;

{
    register char *p, *t;
    char expbuf[MAXEXP];

    p = p0;
    *p++ = fmtch;
    if (exp < 0) {
        exp = -exp;
        *p++ = '-';
    } else
        *p++ = '+';
    t = expbuf + MAXEXP;
    if (exp > 9) {
        do {
            *--t = to_char(exp % 10);
        } while ((exp /= 10) > 9);
        *--t = to_char(exp);
        for (; t < expbuf + MAXEXP; *p++ = *t++)
            ;
    } else {
        *p++ = '0';
        *p++ = to_char(exp);
    }
    return (p - p0);
}
