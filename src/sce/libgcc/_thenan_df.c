/* libgcc.a member _thenan_df.o (from fp-bit.c, double): the NaN fp-bit
 * hands back for an invalid operation */
#include "dp-bit.h"

const fp_number_type_d __thenan_df = {CLASS_SNAN, 0, 0, 0, {0}};
