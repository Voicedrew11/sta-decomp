#include "common.h"
typedef struct { u16 p0, p2; u16 x4; u16 p6; } E;
typedef struct { u8 pad[0x10]; s32 x10; u16 n14, n16, n18, p1A, n1C, n1E, n20; u8 pad2[0x1E]; u8 data[1]; } O;
void func_001758B0(u16, s32);
void func_00170E90(O **arg0) {
    O *o; s32 i; E *e; o = *arg0; i = 0; e = (E *)((u8 *)(s32)((u8 *)((s32)((u8 *)((s32)((u8 *)((s32)((u8 *)o + 0x40) + o->n14 * 16) + o->n16 * 8)) + o->n18 * 4)) + o->n1C * 0x50) + o->n1E * 4);
    for (; i < o->n20; i++) {
        func_001758B0(e->x4, o->x10);
        e++;
    }
}
