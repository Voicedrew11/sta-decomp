#include "m2c.h"
typedef struct { s8 d[0x140]; } E;
typedef struct { s8 pad[6]; u16 n; s8 pad2[0x38]; s8 data[1]; } O;
extern s32 D_00201F2C;
void Mdl_Animate_2_00171BB0(void *, O *, u8, u8, u16, f32);
void memcpy(void *, void *, s32);
void Mtx_Lerp_2_0015EB20(E *, E *, E *, f32);

void Mdl_BlendMotion_0_00171980(O *obj, u16 a1, s32 start, s32 count, f32 f, f32 g) {
    s8 buf[0x13F80];
    E *src;
    s32 i;

    if (g == 1.0f) {
        Mdl_Animate_2_00171BB0((void *)((s32)obj->data + D_00201F2C * (obj->n * 0x140 + 0x200)), obj, start, count, a1, f);
        return;
    }
    src = (E *)((s32)obj->data + D_00201F2C * (obj->n * 0x140 + 0x200));
    memcpy(buf, src, obj->n * 0x140 + 0x200);
    Mdl_Animate_2_00171BB0(buf, obj, start, count, a1, f);
    for (i = start; i < start + count; i++) {
        Mtx_Lerp_2_0015EB20(src + i + 1, src + i + 1, (E *)buf + i + 1, g);
    }
}
