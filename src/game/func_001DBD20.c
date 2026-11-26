#include "common.h"
typedef struct { s8 a; s8 b; s8 c; u8 d; } E;
extern struct { char pad[0x280]; E e[0x68]; u8 t[16][32]; } D_004BA500;
void func_001DBD20(u8 *a) {
    s32 n = *a; u8 *p = a + 1; while (n--) { u8 i = p[0]; u8 j = p[1]; s8 c = p[2]; E *e = &D_004BA500.e[i]; p += 3; if (c >= 0) { e->b = j; e->a = c; e->c = 1; D_004BA500.t[j][e->a] = i; } else { e->c = -1; e->b = -1; } }
}
