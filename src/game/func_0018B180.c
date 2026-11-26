#include "m2c.h"
typedef struct { u32 n; s32 *list; } Lst;
void func_001829B0(s32 *, s32, void (*)(), s32 *);
s8 *func_00189050(s32);
s32 func_00189020(s32);
void func_0018B380();
extern s32 D_004A0F90[];
extern void (*D_004A0F9C[])(s8 *);
extern s32 D_004A0FAC[];

void func_0018B180(s8 *arg0) {
    u32 i;
    Lst *l;
    s32 base;
    s32 off;
    s32 *d;
    s32 *e;

    l = *(Lst **)(func_00189050(0) + 0x28);
    base = func_00189020(0);
    if (*(u8 *)(arg0 + 0xA) == 2) {
        D_004A0FAC[0] -= 0xC;
        if (D_004A0FAC[0] < 0) {
            *(u8 *)(arg0 + 0xA) = 0;
            *(u8 *)(arg0 + 0xB) = 0;
        }
    } else {
        D_004A0FAC[0] += 0xC;
    }
    if ((s16)D_004A0FAC[0] < 0) {
        D_004A0FAC[0] = 0;
    }
    if ((s16)D_004A0FAC[0] > 0x7F) {
        D_004A0FAC[0] = 0x7F;
    }
    i = 0;
    if (i < l->n) {
        d = D_004A0F90;
        off = 0;
        do {
            e = (s32 *)((s8 *)l->list + off);
            func_001829B0(e, base + *e * 8, func_0018B380, d);
            i++;
            off += 0x40;
        } while (i < l->n);
    }
    if (D_004A0F9C[0] != NULL) {
        D_004A0F9C[0](arg0);
    }
}
