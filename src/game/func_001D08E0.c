#include "common.h"
typedef struct { u8 pad[0x26]; u8 b[6]; u16 h[8]; u8 pad3C[0x54]; } E;
typedef struct { u8 v; u8 pad[3]; } B4;
extern E D_004B5EF0[7];
extern u8 D_004B5DD0[];
u8 *func_001C9BA0(void);
void memset(void *, s32, s32);
void func_001D1240(E *, s16, u8);
#define D D_004B5EF0
#define SH(i) out[i] = base[i] + (D[0].h[i] + D[1].h[i] + D[2].h[i] + D[3].h[i] + D[4].h[i] + D[5].h[i] + D[6].h[i])
#define SB(i, k) st[i] = D[0].b[k] + D[1].b[k] + D[2].b[k] + D[3].b[k] + D[4].b[k] + D[5].b[k] + D[6].b[k]
#define CH(i) if (out[i] < 0) out[i] = 0; if (out[i] > 999) out[i] = 999
#define CB(i) if (*(s16 *)&st[i] < 0) st[i] = 0; if (*(s16 *)&st[i] > 100) st[i] = 100

void func_001D08E0(s16 *out, s32 *st, s16 *a, B4 *b) {
    u16 *base;
    s32 i;

    base = (u16 *)(func_001C9BA0() + 0x20);
    memset(out, 0, 0x10);
    for (i = 2; i < 9; i++) { func_001D1240(&((E *)D_004B5DD0)[i], a[i], b[i].v); }
    SH(0); SH(1); SH(2); SH(3); SH(4); SH(5); SH(6); SH(7);
    CH(0); CH(1); CH(2); CH(3); CH(4); CH(5); CH(6); CH(7);
    if (st != 0) {
        memset(st, 0, 0x20);
        SB(0, 0); SB(1, 1); SB(2, 2); SB(3, 4); SB(4, 3); SB(5, 5);
        CB(0); CB(1); CB(2); CB(3); CB(4); CB(5);
    }
}
