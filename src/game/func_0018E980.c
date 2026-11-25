#include "m2c.h"
typedef union { u128 q; f32 f[4]; } Q;
typedef struct { s32 idx; u8 pad[0x3C]; } Item;
typedef struct { u32 n; Item *items; } List;
typedef struct { s32 pad; List *list; } Res;
Res *func_00189050(s32);
s32 func_00189020(s32);
void func_001829B0(Item *, s32, void *, s32);
void func_00187B20(s32);
void func_00182080(s32, f32, Q *, Q *, void *, s32);
void func_00181420(void);
void func_001DCF80(void);
extern Q D_001F2D80[];
extern Q D_001F2D90[];
extern s32 D_0020212C;
extern u8 D_0020212F;
extern s32 D_00202130;

void func_0018E980(u8 *arg0) {
    Q a;
    Q b;
    u32 i;
    List *l;
    s32 base;

    a = D_001F2D80[0];
    b = D_001F2D90[0];
    if (D_00202130 != 0) {
        l = func_00189050(3)->list;
        base = func_00189020(3);
        for (i = 0; i < l->n; i++) {
            func_001829B0(&l->items[i], base + l->items[i].idx * 8, func_001DCF80, 0);
        }
        func_00187B20(0);
        if (arg0[8] == 6) {
            if (D_0020212F < 0xC) {
                D_0020212F = 0;
            } else {
                D_0020212F -= 0xC;
            }
        } else {
            D_0020212F += 0xC;
            if (D_0020212F > 0x60) {
                D_0020212F = 0x60;
            }
        }
        func_00182080(0, 0.0f, &a, &b, &D_0020212C, 0);
        func_00181420();
    }
}
