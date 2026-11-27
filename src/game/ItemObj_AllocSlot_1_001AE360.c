#include "obj3d.h"
typedef struct { u8 pad[8]; u16 x8; u8 padA[0x90 - 0xA]; } Ent;
typedef struct { u8 pad[8]; Obj3D *t[2][16]; } Tbl;
extern Ent *D_002022B0;
extern Tbl D_004AC5A0;
void ItemObj_Free_1_001AF4A0(Obj3D *);

Obj3D *ItemObj_AllocSlot_1_001AE360(s16 id, u8 side) {
    s32 k;
    Ent *ents;
    s32 i;
    s32 m;

    ents = D_002022B0;
    for (i = 0; i < 16; i++) {
        if (D_004AC970[side][i].x9C == -1) return &D_004AC970[side][i];
    }
    for (k = 0; k < ents[id].x8; k++) {
        for (i = 0; i < 16; i++) {
            if (ents[D_004AC5A0.t[side][i]->x9C].x8 <= k) {
                ItemObj_Free_1_001AF4A0(*(Obj3D *volatile *)&D_004AC5A0.t[side][i]);
                for (m = 0; m < 16; m++) {
                    if (D_004AC970[side][m].x9C == -1) return &D_004AC970[side][m];
                }
            }
        }
    }
    return 0;
}
