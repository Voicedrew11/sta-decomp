#include "common.h"

typedef struct { s32 h; f32 t; f32 d; s32 pad; u8 a[0x10]; u8 b[0x10]; f32 x; f32 y; s32 pad2[2]; } E;
extern E D_004BAC50[16];
extern u8 D_002023AC;
void func_0015DB60(s32 h);
void func_0015D800(s32, u8 *, u8 *, f32, f32);

void func_001E0C10(f32 dt)
{
    s32 i;
    E *e = D_004BAC50;
    for (i = 0; i < 16; i++, e++) {
        if (e->h != -1 && e->d != 0.0f) {
            f32 t = e->t - dt;
            e->t = t;
            if (t < 0.0f) {
                s32 ok;
                if (i < 0 || i >= 16)
                    ok = 0;
                else if (e->h == -1)
                    ok = 0;
                else
                    ok = 1;
                if (ok) {
                    func_0015DB60(e->h);
                    e->h = -1;
                    D_002023AC--;
                }
            } else {
                f32 r = t / e->d;
                func_0015D800(e->h, e->a, e->b, r * e->x, r * e->y);
            }
        }
    }
}
