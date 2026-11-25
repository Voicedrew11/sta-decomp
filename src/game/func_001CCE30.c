#include "m2c.h"
typedef struct { u8 pad[0xA]; u16 xA; u8 pad2[0x29 - 0xC]; u8 x29; u8 pad3[0x90 - 0x2A]; } It;
typedef struct { u8 pad[0xA2]; u8 a; u8 b; u8 c[2]; } St;
It *func_001AFC90(void);
u8 *func_001C9BA0(void);

void func_001CCE30(void) {
    It *it;
    u8 *s;
    s32 i;
    s32 t;

    it = func_001AFC90();
    s = func_001C9BA0();
    for (i = 0; i < 10; i++) {
        t = ((s16 *)s)[i + 0x40];
        if ((u32)(t + 1) > 1) {
            if (i == 9 && it[t].xA == 0 && it[t].x29 == 5) {
                if ((s32)((St *)(s + t * 4))->a <= 0 && (s32)((St *)(s + t * 4))->b <= 0) {
                    ((s16 *)s)[i + 0x40] = -1;
                }
            } else if ((s32)((St *)(s + t * 4))->a <= 0) {
                ((s16 *)s)[i + 0x40] = -1;
            }
        }
    }
}
