#include "common.h"
#include "actor.h"
typedef struct { u8 pad[8]; s32 x8; s32 pC; s32 x10; } Arg;
f32 *Script_GetArgPtr_2_00165130(Arg *, s32);
s32 MapObj_GetNodeIndex_0_001B7840(s32, s32);
s8 *MapObj_Find_1_001B19A0(s32);
s8 *Mdl_GetFrameData_0_001715B0(s32);
void sceVu0CopyVector(Vec *, void *);
void sceVu0CopyMatrix(Mtx *, void *);
void sceVu0SubVector(Vec *, Vec *, Vec *);
f32 sceVu0InnerProduct(Vec *, Vec *);
f32 sqrtf(f32);

void MapCmd_GetDistToObject_0_0017D000(Arg *a0) {
    Vec b;
    Mtx m;
    Vec a;
    f32 *out;
    s32 idx;
    s8 *o;
    s8 *e;
    s8 *mm;
    s8 *p;

    out = Script_GetArgPtr_2_00165130(a0, 2);
    idx = MapObj_GetNodeIndex_0_001B7840(a0->x8, a0->x10);
    if (idx >= 0) {
        o = MapObj_Find_1_001B19A0(a0->x8);
        if (o != NULL) {
            e = *(s8 **)(o + 0x180) + idx * 0x80;
            if (e != NULL) {
                mm = Mdl_GetFrameData_0_001715B0(*(s32 *)(e + 0x40));
                if (mm != NULL) {
                    p = D_002022E4->unk518 + 0x180;
                    if (p != NULL) {
                        sceVu0CopyVector(&b, p + 0x40);
                        sceVu0CopyMatrix(&m, mm + 0x200);
                        sceVu0SubVector(&a, &m.m[3], &b);
                        *out = sqrtf(sceVu0InnerProduct(&a, &a));
                    }
                }
            }
        }
    }
}
