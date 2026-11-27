#include "common.h"

/* rodata_001FCB08: the game's data at 0x001FCB08..., one object per label. */
#pragma explicit_zero_data on

const char D_001FCB08[0x10] __attribute__((aligned(8))) = "HP %4d/%4d\000\000\000\000\000\000";
const char D_001FCB18[0x10] __attribute__((aligned(8))) = "MP %4d/%4d\000\000\000\000\000\000";
const char D_001FCB28[0x8] = { 0x20, 0x25, 0x64, 0, 0, 0, 0, 0 };
const char D_001FCB30[0x8] = { 0x20, 0x2b, 0x25, 0x64, 0, 0, 0, 0 };
const char D_001FCB38[0x7] = "/%3.1f\000";
static const u8 pad_001FCB3F[0x1] __attribute__((aligned(1))) = { 0 };
