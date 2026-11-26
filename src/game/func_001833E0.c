#include "m2c.h"
typedef struct { s32 first; s32 x; u8 b0:1; u8 b1:1; u8 b2:1; } O;
typedef struct { s32 a; s8 *p; s32 b[2]; f32 f[8]; } Ent;
typedef struct { u8 b[0x100]; } Buf;
extern s32 D_001F2740[];
extern u8 D_001FC9C0[];
extern u8 D_001FC9D8[];
extern O *D_0048D110[];
extern Ent D_0048D170[];
void sprintf(void *, void *, s32);
O *func_001E1570(void *, s32);
void func_00177570(s8 *);
s8 *func_00177AF0(s32, s32);
s32 func_00177F80(void *);
static inline O **getp(s32 i) { return &D_0048D110[i]; }

void func_001833E0(s32 arg0, s32 arg1) {
    Ent *e; O *o; s32 x; s32 *cur; O **pp;
    e = &D_0048D170[arg1];
    if (arg0 <= 0) {
        pp = getp(arg1);
        if (*pp != NULL && (*pp)->b2) {
            if (e->p != NULL) {
                func_00177570(e->p);
                e->p = NULL;
                D_001F2740[arg1] = -1;
                *pp = NULL;
            }
        }
        return;
    }
    cur = &D_001F2740[arg1];
    if (arg0 != *cur) {
        pp = getp(arg1);
        o = *pp;
        if (o != NULL && o->b1) return;
        *cur = arg0;
        if (o != NULL && o->b2) {
            if (e->p != NULL) {
                func_00177570(e->p);
                e->p = NULL;
            }
        }
        {
            Buf s = {0};
            sprintf(&s, D_001FC9C0, *cur);
            *pp = func_001E1570(&s, arg1);
        }
        e->f[0] = 4.0f;
        e->f[1] = 4.0f;
        e->f[2] = 50.0f;
        e->f[3] = 50.0f;
        e->f[4] = 0.0f;
        e->f[5] = 0.0f;
        e->f[6] = 64.0f;
        e->f[7] = 64.0f;
    }
    pp = getp(arg1);
    o = *pp;
    if (o != NULL && !o->b1 && !o->b2 && o->b0) {
        u8 buf2[16];
        sprintf(buf2, D_001FC9D8, *cur);
        if ((x = (*pp)->first) != 0) {
            e->p = func_00177AF0(func_00177F80(buf2), x);
            (*(O **)((s8 *)D_0048D110 + arg1 * 4))->b2 = 1;
        }
    }
}
