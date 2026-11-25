#include "common.h"
typedef struct { s16 v; s16 id; } E;
extern E **D_0020216C;
s32 func_001959E0(s32 id) { s32 i; E *base = *D_0020216C; E *e = base; for (i = 0; i < 24; i++, e++) { if (id == e->id) return base[i].v; } return -1; }
