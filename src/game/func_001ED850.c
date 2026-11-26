#include "common.h"
typedef struct { s32 x0; u8 pad[0x3B]; u8 b3F; } E;
typedef struct { u32 n; E *e; } L;
typedef struct { u8 pad[0x38]; L *l; } R;
typedef union { u32 w; s8 b[4]; } Col;
void func_001829A0(E *, s8 *);
void func_001875C0(s32, s32, u32, f32, f32, f32);
void func_00187B20(s32);
s8 *func_00189020(s32);
R *func_00189050(s32);
s32 func_00195B10(s32);
void func_00181420(void);
extern f32 D_00202408;

void func_001ED850(void) {
    Col col;
    u32 i;
    L *l;
    s8 *base;


    col.w = 0x80808080;
    col.b[3] = (s32)D_00202408;
    l = func_00189050(0)->l;
    base = func_00189020(0);
    for (i = 0; i < l->n; i++) {
        l->e[i].b3F = 1.95f * (f32)(s32)D_00202408;
        func_001829A0(&l->e[i], base + l->e[i].x0 * 8);
    }
    func_001875C0(func_00195B10(0x190), 1, col.w, 320.0f, 120.0f, 1.0f);
    func_00187B20(0);
    func_00181420();
}
