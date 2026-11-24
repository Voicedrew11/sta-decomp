#include "m2c.h"
extern s8 *D_002022E4;

void func_001C8F30(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
s32 temp_v1;
s8 *var_v1;
if (D_002022E4 == 0 ) {
var_v1 = 0 ;
} else {
temp_v1 = (*(s32 *)((s8 *)(D_002022E4) + (0x518))) ;
if (temp_v1 == 0) {
var_v1 = 0 ;
} else {
var_v1 = (signed char *)(temp_v1 + 0x180);
}
}
if (var_v1 != 0 ) {
(*(f32 *)((s8 *)(var_v1) + (0x438))) = arg0;
(*(f32 *)((s8 *)(var_v1) + (0x43C))) = arg1;
(*(f32 *)((s8 *)(var_v1) + (0x440))) = arg2;
(*(f32 *)((s8 *)(var_v1) + (0x444))) = arg3;
(*(s32 *)((s8 *)(var_v1) + (0x434))) = 0;
(*(s32 *)((s8 *)(var_v1) + (0x430))) = 0;
}
}
