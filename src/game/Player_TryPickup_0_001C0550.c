#include "m2c.h"
typedef struct {
    u8 pad[0x39C];
    u32 b39C:8;
    u32 b8:6;
    u32 m:4;
    u32 n:4;
    u32 o:6;
    u32 r:4;
    u8 pad3A0[0x414 - 0x3A0];
    void *x414;
} S;
typedef struct { u8 pad[0x9C]; s16 x9C; } R;
typedef struct { u8 pad[0x518]; u8 *x518; } A;
R *ItemObj_FindPickTarget_0_001AC3E0(void);
s32 Inventory_CanCarry_0_001CBE40(s32);
void Msg_ShowById_1_0018B0E0(s32);
R *Chest_CheckOpen_0_001B9360(void);

s32 Player_TryPickup_0_001C0550(A *a0) {
    S *s;
    R *r;
    s = (S *)(a0->x518 + 0x180);
    s->x414 = 0;
    r = ItemObj_FindPickTarget_0_001AC3E0();
    if (r) {
        if (Inventory_CanCarry_0_001CBE40(r->x9C)) {
            s->m = 1;
            s->n = 0;
            s->x414 = r;
        } else {
            Msg_ShowById_1_0018B0E0(0xCC);
        }
        return 1;
    }
    r = Chest_CheckOpen_0_001B9360();
    if (r) {
        s->m = 1;
        s->n = 0;
        s->x414 = r;
        return 1;
    }
    return 0;
}
