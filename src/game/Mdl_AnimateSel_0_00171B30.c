#include "common.h"
typedef struct { s8 pad[4]; u8 x4; u8 p5; u16 n; s8 pad2[0x38]; s8 data[1]; } O;
void Mdl_Animate_2_00171BB0(void *, O *, u8, u8, u16, f32);
void Mdl_AnimateSel_0_00171B30(O *obj, u16 a1, s32 sel, f32 f) {
    Mdl_Animate_2_00171BB0((void *)((s32)obj->data + sel * (obj->n * 0x140 + 0x200)), obj, obj->x4, obj->n, a1, f);
}
