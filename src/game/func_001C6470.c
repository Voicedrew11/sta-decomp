#include "m2c.h"
typedef struct {
    u8 p[0x3CD]; s8 x3CD; s8 x3CE; u8 p3CF[6]; u8 x3D5;
    u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1;
    u8 c0:1; u8 c1:2; u8 c3:5;
} S;
extern s8 *D_002022E4;
void func_001C6D40(u16);

void func_001C6470(void) {
    s32 t;
    S *s;
    if (D_002022E4 == NULL) {
        s = NULL;
    } else {
        t = M2C_FIELD(D_002022E4, s32 *, 0x518);
        if (t == 0) {
            s = NULL;
        } else {
            s = (S *)(t + 0x180);
        }
    }
    if (s != NULL) {
        switch (s->x3D5) {
        case 4:
            if (s->b5) {
                func_001C6D40(5);
                s->b5 = 0;
                return;
            }
            s->x3CE = s->x3CD;
            s->b0 = 1;
            if (s->c1) {
                func_001C6D40(0);
            }
            break;
        case 8:
            if (s->c1) {
                func_001C6D40(0);
            }
            break;
        }
    }
}
