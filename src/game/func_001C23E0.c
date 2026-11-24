#include "m2c.h"
typedef struct { u8 lo:4; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; } BF;
typedef struct {
    u8 pad0[0x396]; s8 x396; u8 pad1; s16 x398;
    u8 pad2[0x3CC - 0x39A]; s8 x3cc; u8 pad3[8]; u8 x3d5; BF f; u8 pad4[9]; u16 x3e0[8];
} Sub;
typedef struct { u8 pad[0x180]; Sub s; } Obj2;
typedef struct { u8 pad[0x516]; s8 x516; } Hd;
typedef struct { u8 pad[0x518]; s8 *x518; } Obj;
typedef struct { u8 pad[0x20]; f32 x20, x24, x28, x2c; } Arg;
void func_001CA880(s32);
void func_001C6D40(u8);
extern Obj *D_002022E4;
static inline Sub *getsub(void) {
    Obj *o = D_002022E4;
    if (o == NULL) return NULL;
    if (o->x518 == NULL) return NULL;
    return (Sub *)(o->x518 + 0x180);
}

void func_001C23E0(Obj *arg0, Arg *arg1) {
    s8 *h = arg0->x518;
    Sub *s = (Sub *)(h + 0x180);
    u8 k = 0;
    f32 f;
    if (((Hd *)h)->x516 > 0 && s->x3d5 == 0) {
        f = arg1->x28;
        if (!(f <= 0.5f)) {
            k = 1;
            if (!(arg1->x20 <= f)) k = 2;
            if (!(arg1->x24 <= f)) k = 4;
        } else {
            f = arg1->x2c;
            if (!(f <= 0.5f)) {
                k = 3;
                if (!(arg1->x20 <= f)) k = 2;
                if (!(arg1->x24 <= f)) k = 4;
            } else {
                if (!(arg1->x20 <= 0.5f)) k = 2;
                if (!(arg1->x24 <= 0.5f)) k = 4;
            }
        }
        if ((u8)k == 0) {
            s->x3cc = k;
            s->f.b6 = 0;
            s->f.b4 = 0;
            return;
        }
        if (s->f.b4 == 0 && (u8)k != s->x3cc) {
            s->x3cc = k;
            s->f.b6 = 0;
        } else {
            s->x3cc = k;
            s->f.b6 = 1;
            s->f.b4 = 0;
        }
        if (s->f.b6 == 0) {
            Sub *p = getsub();
            if (p != NULL) {
                p->x3e0[0] = 0xFFFF; p->x3e0[1] = 0xFFFF; p->x3e0[2] = 0xFFFF; p->x3e0[3] = 0xFFFF;
                p->x3e0[4] = 0xFFFF; p->x3e0[5] = 0xFFFF; p->x3e0[6] = 0xFFFF; p->x3e0[7] = 0xFFFF;
            }
            func_001CA880(k);
            s->x398 = 0;
            s->x396--;
            func_001C6D40(k);
        }
    }
}
