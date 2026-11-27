#include "actor.h"
#include "obj3d.h"
typedef struct { s32 a; s32 b; s32 c8; s32 c; } H;
typedef struct Ch {
    s32 x0;
    s32 x4;
    u32 type : 8;
    u32 off : 24;
    u16 xC;
    u16 xE;
    H h;
} Ch;
typedef struct { u8 pad[0x94]; Flags8 f94; } R;
typedef struct {
    u8 pad[0x390];
    R *x390;
    u8 pad394[0x3C0 - 0x394];
    Obj3D *x3C0;
    Obj3D *x3C4;
} S;
typedef struct { u8 pad0[0x10]; u8 **x10; } Src;
#define DATA(h) ((u8 *)((s32)(h) + 0x10) + (((h)->c + 15) & ~15))
extern s8 D_001FAB58[];
extern s32 D_0022F074[];
extern s32 D_0022F070[];
extern s32 D_0022EC44[];
extern s16 D_0022EC48[];
extern Flags8 D_0022EC43[];
extern u8 D_00201ED7;
void Se_StopGroup_0_001D9EE0(s32);

s32 Snd_BindMapSe_0_0012DA90(void) {
    S *s = (S *)(D_002022E4->unk518 + 0x180);
    Obj3D *o;
    Src ****p;
    u8 *base;
    Ch *c;
    s32 cnt;
    s32 i;
    s32 j;
    Ch *d;
    H *h;

    o = s->x390->f94.f.b0 == 0 ? s->x3C0 : s->x3C4;
    if (o == NULL || (p = (Src ****)o->x84) == NULL || *p == NULL || **p == NULL || ***p == NULL
        || (***p)->x10 == NULL || (base = *(***p)->x10) == NULL) {
        return -1;
    }
    switch (*(s32 *)base) {
    case 0x4D415453:
        c = (Ch *)(base + ((Ch *)base)->off);
        cnt = ((Ch *)base)->xE;
        for (i = 0; i < cnt; i++) {
            if (c->x0 == (D_001FAB58[0] | (D_001FAB58[1] << 8) | (D_001FAB58[2] << 16) | (D_001FAB58[3] << 24))) {
                d = (Ch *)((u8 *)c + c->off);
                for (j = 0; j < c->xE; j++) {
                    switch (d->x0) {
                    case 0x61444E53:
                        h = (H *)d;
                        if (*(s32 *)(DATA(h) + 4) != 0) {
                            D_0022F074[0] = (u8 *)d - base;
                        } else {
                            D_0022F074[0] = 0;
                        }
                        break;
                    }
                    d = (Ch *)((u8 *)d + d->x4);
                }
                break;
            }
            c = (Ch *)((u8 *)c + c->x4);
        }
        break;
    }
    D_00201ED7 = 0;
    Se_StopGroup_0_001D9EE0(3);
    if (D_0022EC43[0].f.b1) {
        D_0022F070[0] = 0;
        D_0022EC44[0] = 1;
        D_0022EC43[0].f.b1 = 0;
    }
    D_0022EC48[0] = 1;
    D_0022EC43[0].f.b0 = 1;
    D_0022EC43[0].f.b2 = 0;
    return 0;
}
