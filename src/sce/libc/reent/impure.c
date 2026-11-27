/* libc.a member impure.o */
#include <reent.h>

/* newlib's _REENT_INIT: the three standard streams are the record's own
   sf[0..2], the locale is "C", and one field 0xA8 bytes in starts at 1.
   This newlib's struct _reent is 0x2F0 bytes, one word more than the part
   of it reent.h describes. */
static struct {
    Reent r;
    int tail;
} impure_data = {{
    0, &impure_data.r.sf[0], &impure_data.r.sf[1], &impure_data.r.sf[2], 0, "", 0, "C",
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, {[0x48] = 1},
}};

Reent *_impure_ptr = &impure_data.r;
