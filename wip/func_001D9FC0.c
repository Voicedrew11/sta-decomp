/* round 3 near-miss: 15 words: temp register numbers in the 8x32 loop */
#include "common.h"
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } B;
typedef struct { s8 x0; s8 x1; s8 x2; s8 x3; } C;
extern struct { char pad[0x200]; B b[8]; C c[64]; char pad2[0xA0]; s8 t[8][32]; } D_004BA500;
extern u32 D_004BA000[];
s32 func_001D8350(s32 a, s32 b, s32 c, s32 d, s32 e, void *m);
u8 *func_001D8340(void);
static inline void cpy(void *d, void *s, u32 n) { s32 i; for (i = 0; i < n; i++) ((u8 *)d)[i] = ((u8 *)s)[i]; }
void func_001D9FC0(void) {
    u8 *s;
    s32 k;
    s32 j;
    s8 v;
    C *c;
    s = func_001D8340();
    func_001D8350(4, 1, 0, 0x20, 0x20700, NULL);
    cpy(D_004BA000, s, 0x20);
for (j = 0; j < 8; j++) {
    for (k = 0; k < 32; k++) {
        v = D_004BA500.t[j][k];
        if (!(0 > v) && v < 0x40) {
            if (D_004BA500.c[v].x2 == 1 && !((1 << k) & D_004BA000[D_004BA500.b[j].xC])) {
                D_004BA500.c[v].x2 = -1;
                D_004BA500.t[j][k] = -1;
            }
        }
    }
}
    for (j = 0; j < 0x40; j++) { c = &D_004BA500.c[j]; if (c->x2 == 1 && !((1 << c->x0) & D_004BA000[D_004BA500.b[c->x1].xC])) c->x2 = -1; } }
