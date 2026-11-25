#include "m2c.h"
typedef struct { u8 t:3; u8 r:5; u8 pad[3]; u8 c0:4; u8 c4:1; u8 c5:3; } S;
typedef struct { u8 pad[0x10]; S s; u8 pad2[0x94 - 0x15]; u8 f0:3; u8 f3:1; u8 f4:4; } M;
typedef struct { u8 d[0x80]; } Sub;
typedef struct {
    u8 pad[0x188];
    u16 b0:1; u16 b1:1; u16 b2:2; u16 b4:1; u16 b5:2; u16 cnt:8; u16 b15:1;
    u8 g0:1; u8 g1:7;
    u8 pad2[0x210 - 0x18B];
    M *m[(0x270 - 0x210) / 4];
    Sub sub[24];
    u8 pad3[0xED0 - 0x270 - 24 * 0x80];
} E;
typedef struct { u8 pad[0x90]; E *e; u16 k; u8 pad2[0x120 - 0x96]; } B;
typedef struct { u16 prev; u16 next; u16 x4; } L;
typedef struct { u8 a:2; u8 b:1; u8 c:5; } BF;
void func_00168480(E *, Sub *, M *, S *);
void func_00167C90(E *, Sub *, M *, S *);
void func_001679E0(u16);
void func_001549D0(void);
void func_00154700(s32, s32);
void func_00154610(s32, s32);
void func_00155900(void);
extern u8 D_00201FE0;
extern s32 D_00201FE4;
extern s32 D_00201F2C;
extern u16 D_00201CA4;
extern B *D_00201FC0;
extern L *D_00201FD4;
extern BF D_00222A50[];
extern E D_003407E0[];

void func_00168A40(void) {
    s32 i;
    s32 j;
    s32 saved;
    E *e;
    u16 idx;

    if (D_00201FE0 == 1) {
        saved = D_00201F2C;
        D_00201F2C = D_00201FE4;
    } else if (D_00201FE0 == 2) {
        if (D_00201F2C == !(D_00201FE4 != 0)) return;
    }
    D_00222A50[0].b = 1;
    func_001679E0(D_00201CA4);
    for (idx = D_00201CA4; idx != 0xFFFF; idx = D_00201FD4[idx].next) {
        volatile B *b = &D_00201FC0[idx];
        M *m = b->e->m[b->k];
        S *s = &m->s;
        E *be = b->e;
        if (be->b1 && be->g0) {
            switch (s->t) {
            case 0:
            case 1:
                func_00168480(be, &be->sub[b->k], m, s);
                break;
            case 2:
                func_00167C90(be, &be->sub[b->k], m, s);
                break;
            }
        }
    }
    for (i = 0, e = D_003407E0; i < 0x100; i++, e++) {
        if (e->b0 && !e->b4) {
            func_001549D0();
            if (e->m[0]->f3) {
                func_00154700(5, 0);
            } else {
                func_00154610(5, 0);
            }
            for (j = 1; j < e->cnt; j++) {
                Sub *sub = &e->sub[j];
                M *m = e->m[j];
                S *s = &m->s;
                if (e->b1 && e->g0 && !s->c4) {
                    switch (s->t) {
                    case 0:
                    case 1:
                        func_00168480(e, sub, m, s);
                        break;
                    case 2:
                        func_00167C90(e, sub, m, s);
                        break;
                    }
                }
            }
            func_00155900();
        }
    }
    D_00222A50[0].b = 0;
    if (D_00201FE0 == 1) D_00201F2C = saved;
}
