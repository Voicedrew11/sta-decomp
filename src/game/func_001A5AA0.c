#include "m2c.h"
typedef f32 Mtx[4][4];
typedef struct { u8 pad[0x30]; } Elem;
typedef struct { u8 pad[0x138]; Elem *base; } Tbl;
typedef struct { u8 pad[0x40]; s32 id; } Inf;
typedef struct {
    u8 pad0[0xC0];
    Tbl *tbl;       /* 0xC0 */
    s32 padC4;
    Elem *cur;      /* 0xC8 */
    Inf *inf;       /* 0xCC */
    Mtx m;          /* 0xD0 */
    s32 x110;
    s32 x114;
} Obj;
typedef struct { u8 pad[0x10]; Obj *obj; } Arg;
extern Mtx D_001F2170;
void sceVu0CopyMatrix(Mtx, Mtx);
void sceVu0MulMatrix(Mtx, Mtx, Mtx);
s8 *func_001715B0(s32);
void func_001B1A20(Tbl *, s32, s32);

u8 func_001A5AA0(u16 *flag, Arg *a, Mtx out) {
    Mtx m1;
    Mtx m2;
    Mtx m3;
    s8 *p;
    u8 i;
    u8 j;
    u8 changed = 0;

    sceVu0CopyMatrix(out, D_001F2170);
    if (a->obj->cur != NULL) {
        p = func_001715B0(a->obj->inf->id);
        sceVu0CopyMatrix(m1, a->obj->m);
        sceVu0CopyMatrix(m2, (f32 (*)[4])(p + 0x200));
        sceVu0CopyMatrix(a->obj->m, m2);
        if (a->obj->x114 == a->obj->x110) {
            for (i = 0; i < 4; i++) {
                for (j = 0; j < 4; j++) {
                    if (m1[i][j] != m2[i][j]) {
                        changed = 1;
                    }
                }
            }
            if (changed) {
                sceVu0CopyMatrix(m3, D_001F2170);
                m3[0][0] = m1[0][0];
                m3[0][1] = m1[1][0];
                m3[0][2] = m1[2][0];
                m3[0][3] = 0.0f;
                m3[1][0] = m1[0][1];
                m3[1][1] = m1[1][1];
                m3[1][2] = m1[2][1];
                m3[1][3] = 0.0f;
                m3[2][0] = m1[0][2];
                m3[2][1] = m1[1][2];
                m3[2][2] = m1[2][2];
                m3[2][3] = 0.0f;
                m3[3][3] = 0.0f;
                sceVu0MulMatrix(out, m2, m3);
                out[3][0] = m2[3][0] - m1[3][0];
                out[3][1] = m2[3][1] - m1[3][1];
                out[3][2] = m2[3][2] - m1[3][2];
                out[3][3] = 1.0f;
            }
        }
        if (*flag == 0) {
            func_001B1A20(a->obj->tbl, a->obj->cur - a->obj->tbl->base, 1);
        }
    }
    return changed;
}
