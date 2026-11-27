#include "common.h"
f32 sceVu0InnerProduct();                           /* extern */
void sceVu0ScaleVector(s32, s32, f32);           /* extern */
void sceVu0SubVector(s32, s32, s32);             /* extern */

void Vec_Reflect_2_00145ED0(s32 arg0, s32 arg1, s32 arg2) {
    sceVu0ScaleVector(arg2, arg0, 2.0f * sceVu0InnerProduct());
    sceVu0SubVector(arg2, arg2, arg1);
}
