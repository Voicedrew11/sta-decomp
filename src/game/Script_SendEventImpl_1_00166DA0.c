#include "m2c.h"
typedef struct {
    s32 a;
    s32 b;
    u16 c;
    u16 d;
} Ent;
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    u16 fC;
    u16 fE;
    s32 f10;
    s32 f14;
    Ent ent[16];
    s8 pad[0x154 - 0x18 - 16 * 0xC];
    s32 f154;
    s8 pad2[0x258 - 0x158];
} Slot;
typedef struct {
    s32 h0;
    u32 count;
    s32 *base;
    s8 pad[0x294 - 0xC];
    Slot slots[1];
} Mgr;
void Script_ResetSlot_1_00164F10(Slot *);
s32 Script_FindLabel_1_00166970(Mgr *, u32);

u32 Script_SendEventImpl_1_00166DA0(Mgr *arg0, s32 arg1, s32 arg2) {
    u32 i;
    u32 n;
    Slot *s;
    u32 j;

    i = 0;
    n = arg0->count;
    s = NULL;
    for (i = 0; i < n; i++) {
        if (arg0->slots[i].f0 == 0) {
            s = &arg0->slots[i];
            break;
        }
    }
    if (s == NULL && arg0 != NULL) {
        for (j = 0; j < arg0->count; j++) {
            if (arg0->slots[j].f0 != 0) {
                Script_ResetSlot_1_00164F10(&arg0->slots[j]);
            }
        }
    }
    s->f0 = arg1;
    s->f154 = arg2;
    s->f4 = Script_FindLabel_1_00166970(arg0, arg1 & 0xFFFF);
    s->f8 = *arg0->base + s->f4;
    s->fC = 0;
    s->fE = 0;
    s->f10 = 0;
    s->f14 = 0;
    if (s->f14 != 16) {
        s->ent[s->f14].b = s->f8 - *arg0->base;
        s->ent[s->f14].a = s->f4;
        s->ent[s->f14].c = s->fC;
        s->ent[s->f14].d = s->fE;
        s->f14++;
        s->f8 = 0;
    }
    return i;
}
