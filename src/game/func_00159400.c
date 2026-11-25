#include "common.h"
void sceVu0CopyVector(s32 *, s32 *);         /* extern */
extern s32 D_002F1AA0[];
extern s32 D_002F1AB0[];
extern s32 D_002F1AC0[];
extern s32 D_002F1AD0[];
extern f32 D_002F1AD4[];

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x10, 0x14, 0x18, 0x1c, 0x20, 0x24], gap at: 0x8. */
void func_00159400(s32 *arg0, f32 fparg0) {
    sceVu0CopyVector(D_002F1AC0, D_002F1AA0);
    sceVu0CopyVector(D_002F1AB0, arg0);
    (*D_002F1AD4) = fparg0;
    (*D_002F1AD0) = 0;
}
