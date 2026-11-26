#include "m2c.h"
typedef struct { s32 type; s32 a; s32 b; s32 c; u8 pad[0x20]; } Msg;
typedef struct { u8 pad[0x1A]; u16 v; u8 pad2[0x14]; } E30;
typedef struct { u8 pad[0x53]; u8 f; u8 pad2[0x2C]; } E80;
typedef struct { s32 id; u8 pad[0x6A]; u16 n; u8 pad2[0xC8]; E30 *e30; u8 pad3[0x44]; E80 *e80; } Obj;
void func_00123C40(void *, s32, s32);
s32 func_00179F80(Msg *);
s32 func_001B9610(Obj *, s32);
extern s32 D_00201E80;
extern s8 D_00202030;

s32 func_001B8F70(s16 arg0) {
    Msg msg;
    E30 *e;
    Obj *o;
    s32 i;
    s32 j;
    s32 m;
    s32 ret;
    s32 r;
    s32 id;
    Obj ***pp;

    pp = (Obj ***)&D_00201E80 + 2;
    ret = 0;
    j = 0;
    do {
        if (*pp != NULL) {
            o = **pp;
            if (o != NULL) {
                for (i = 0; i < o->n; i++) {
                    e = &o->e30[i];
                    if (((u64)((s64)o->e80[i].f << 0x3E) >> 0x3F) == 0 && func_001B9610(o, i) != 0) {
                        m = e->v % 100;
                        id = o->id;
                        if (m == 0) {
                            r = 0;
                        } else {
                            D_00202030 = arg0;
                            func_00123C40(&msg, 0, 0x30);
                            msg.type = 3;
                            msg.a = m;
                            msg.b = id;
                            msg.c = i;
                            r = func_00179F80(&msg);
                        }
                        ret |= r;
                    }
                }
            }
        }
        j++;
        pp++;
    } while (j < 2);
    return ret;
}
