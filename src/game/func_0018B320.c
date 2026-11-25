#include "common.h"

typedef struct { f32 v[9]; } M;
extern M D_004A0F90;

void func_0018B320(M *m)
{
    if (m)
        D_004A0F90 = *m;
}
