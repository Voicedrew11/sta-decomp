#include "m2c.h"
typedef struct { s32 x0; u8 pad[0x3C]; } Item;
typedef struct { u32 n; Item *items; } List;
typedef struct { s32 x0; s32 x4; u8 x8; } Obj;
List **func_00189050(s32);
s8 *func_00189020(s32);
void func_00182050(s32);
void func_001829B0(Item *, s8 *, void (*)(), s32);
void func_00187B20(s32);
void func_00181420(void);
void func_00193AF0();
extern s32 D_004A1180[];
extern f32 D_004A118C[];

void func_00193880(Obj *o) {
    u32 i;
    List *l;
    s8 *b;
    l = *func_00189050(4);
    b = func_00189020(4);
    if (o->x8 == 10) {
        D_004A118C[0] += 16.0f;
    } else {
        D_004A118C[0] -= 16.0f;
    }
    func_00182050(D_004A118C[0]);
    for (i = 0; i < l->n; i++) {
        func_001829B0(&l->items[i], b + l->items[i].x0 * 8, func_00193AF0, D_004A1180[0]);
    }
    func_00187B20(0);
    func_00181420();
    func_00182050(0x80);
}
