#include "common.h"
typedef struct { s16 n; s8 v[14]; } E;
extern E *D_0020217C;
s8 func_00195B80(s32 i, s32 *p) {
    s32 k = *p;
    if (k < 0) k = D_0020217C[i].n - 1;
    if (k > D_0020217C[i].n - 1) k = 0;
    *p = k;
    return D_0020217C[i].v[k];
}
