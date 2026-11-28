#include "common.h"
typedef struct { char pad[0xA8]; s32 a8; char pac[4]; f32 v[4]; } Obj;
extern f32 D_003139A0[4];
void FxProc_NopA_2_0014DA00(void);
void FxProc_NopB_2_0014DA10(void);
void FxProc_NopC_2_0014DA20(void);
void FxProc_InitAtOrigin_0_0014DA30(Obj *o);
void sceVu0CopyVector(f32 *v0, f32 *v1);

/* FxProc_NopA_2_0014DA00 */
void FxProc_NopA_2_0014DA00(void) {

}

/* FxProc_NopB_2_0014DA10 */
void FxProc_NopB_2_0014DA10(void) {

}

/* FxProc_NopC_2_0014DA20 */
void FxProc_NopC_2_0014DA20(void) {

}

/* FxProc_InitAtOrigin_0_0014DA30 */
void FxProc_InitAtOrigin_0_0014DA30(Obj *o)
{
    sceVu0CopyVector(o->v, D_003139A0);
    o->a8 = 0;
}
