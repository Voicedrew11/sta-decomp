#include "common.h"

typedef struct { s32 x0; char p4[0x10]; s32 fd; s32 x18; } F;
s32 sceClose(s32 fd);

void File_Close_2_0015AB80(F *f)
{
    if (f->fd >= 0) {
        sceClose(f->fd);
        f->fd = -1;
    }
    f->x18 = 0;
    f->x0 = 0;
}
