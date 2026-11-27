#include "common.h"
typedef struct { s32 f0; u8 pad4[0xC]; s32 f10; u8 pad14[0x258 - 0x14]; } Slot;
typedef struct { s32 h0; u32 count; u8 pad8[0x294 - 8]; Slot s[1]; } Mgr;
s8 Script_Exec_2_00166170(Mgr *, Slot *);
extern Mgr *D_00201FA4;
extern Slot *D_00201FA8;
s32 Script_RunEvent_2_00166C10(Mgr *o, s32 i) {
    Mgr *save;
    Slot *save2;
    Slot *s;
    s32 r;
    save = D_00201FA4;
    save2 = D_00201FA8;
    D_00201FA4 = o;
    r = 0;
    if (o->s[i].f0) {
        s = &o->s[i];
        D_00201FA8 = s;
        if (s->f10 == 0) {
            r = Script_Exec_2_00166170(o, s);
            if (r == 0) s->f0 = 0;
        } else {
            s->f10--;
        }
        D_00201FA8 = save2;
    }
    D_00201FA4 = save;
    return r;
}
