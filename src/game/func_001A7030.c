#include "m2c.h"
typedef struct { u8 pad[0x160]; u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:5; u8 pad2[3]; void *h; u8 pad3[0x170-0x168]; } S;
typedef struct { u8 pad[0x2E2]; u8 idx; u8 pad2[0x40-0x2E3+0x2E2]; } T;
typedef struct { u8 pad[0x124]; void *h[8]; } U;
typedef struct { u8 pad[0x7C]; s32 n; u8 pad1[0x9A-0x80]; u8 map[0x4B0-0x9A]; T *t; u8 pad2[0x518-0x4B4]; s8 *u; S *s; } O;
void func_00167640(void *, s32);

void func_001A7030(O *arg0, s32 arg1, s32 arg2) {
    s8 *u;
    T *t;
    S *s;
    s32 i;

    u = (s8 *)arg0->u;
    t = arg0->t;
    if (arg0->s != NULL) {
        for (i = 0; i < arg0->n; i++) {
            s = &arg0->s[i];
            if (s != NULL && s->h != NULL) {
                if (s->b2 && arg2 == 0) {
                    func_00167640(s->h, 0);
                } else {
                    func_00167640(s->h, arg1);
                }
            }
        }
    }
    if (u != NULL && t != NULL) {
        for (i = 0; i < 8; i++, t = (T *)((s8 *)t + 0x40), u += 4) {
            s = &arg0->s[arg0->map[M2C_FIELD(t, u8 *, 0x2E2)]];
            if (M2C_FIELD(u, void **, 0x124) != NULL) {
                if (s != NULL && s->b2 && arg2 == 0) {
                    func_00167640(M2C_FIELD(u, void **, 0x124), 0);
                } else {
                    func_00167640(M2C_FIELD(u, void **, 0x124), arg1);
                }
            }
        }
    }
}
