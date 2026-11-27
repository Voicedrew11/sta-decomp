#include "common.h"
typedef struct { u8 pad[0x1A]; u16 x1A; u8 p[0x14]; } It;
typedef struct { u8 pad[0x6E]; u16 n; u8 p[0xC8]; It *items; } Obj;
Obj *MapObj_Find_1_001B19A0(s32);
void MapObj_StopAnimImpl_0_001B80B0(s32, s32);
static inline s32 find(s32 a, s32 k) {
    Obj *o = MapObj_Find_1_001B19A0(a);
    s32 i;
    if (o == 0) return -1;
    for (i = 0; i < o->n; i++) {
        if (k == o->items[i].x1A % 100) return i;
    }
    return -1;
}
void MapObj_StopAnim_1_001B7C10(s32 a, s32 k) {
    MapObj_StopAnimImpl_0_001B80B0(a, find(a, k));
}

