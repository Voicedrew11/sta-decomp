#include "m2c.h"
u16 *func_00188D30(u16 *s, u8 *out);
u16 *func_00188AF0(u16 *s, u8 *out);
#define STEP_I if (*s != '#' || *s == 0) return s; s++; if (*s == '#') return s; switch (*s) { case 'C': case 'c': s = func_00188D30(s + 1, out); }
static inline u16 *g(u16 *s, u8 *out) {
    STEP_I
    STEP_I
    STEP_I
    STEP_I
    return func_00188AF0(s, out);
}

u16 *func_00188AF0(u16 *s, u8 *out) {
    if (*s != '#' || *s == 0) return s;
    s++;
    if (*s == '#') return s;
    switch (*s) { case 'C': case 'c': s = func_00188D30(s + 1, out); }
    return g(s, out);
}
