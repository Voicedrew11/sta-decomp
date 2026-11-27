#include "m2c.h"
typedef struct { s32 f0; u8 pad4[0xC]; s32 f10; u8 pad14[0x258 - 0x14]; } Slot;
typedef struct { s32 h0; u32 count; u8 pad8[0x294 - 8]; Slot s[1]; } Mgr;
s8 Script_Exec_2_00166170(Mgr *, Slot *);
extern Mgr *D_00201FA4;
extern Slot *D_00201FA8;

s32 Script_RunAll_1_00166CC0(Mgr *o) {
    u32 i;
    Mgr *save;
    Slot *save2;
    Slot *s;
    save = D_00201FA4;
    D_00201FA4 = o;
    for (i = 0; i < o->count; i++) {
        if (o->s[i].f0) {
            save2 = D_00201FA8;
            s = &o->s[i];
            D_00201FA8 = s;
            if (s->f10 == 0) {
                if (Script_Exec_2_00166170(o, s) == 0) s->f0 = 0;
            } else {
                s->f10--;
            }
            D_00201FA8 = save2;
        }
    }
    D_00201FA4 = save;
    return 0;
}
