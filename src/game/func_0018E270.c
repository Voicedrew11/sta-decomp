#include "common.h"

typedef struct { s32 idx; char p4[0x3C]; } E;
typedef struct { u32 n; E *e; } L;
typedef struct { L *l[13]; } G;
G *func_00189050(s32 i);
u8 *func_00189020(s32 i);
void func_001829B0(E *e, u8 *p, void (*f)(void), s32 d);
void func_0018E320(void);
void func_00187B20(s32 a);
void func_00181420(void);

void func_0018E270(void)
{
    u32 i;
    L *l;
    u8 *b;
    l = func_00189050(0)->l[12];
    b = func_00189020(0);
    for (i = 0; i < l->n; i++)
        func_001829B0(&l->e[i], b + l->e[i].idx * 8, func_0018E320, 0);
    func_00187B20(0);
    func_00181420();
}
