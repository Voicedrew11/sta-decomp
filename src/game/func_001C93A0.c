#include "m2c.h"
M2C_UNK func_00102A60(s8 *, s32);
extern s8 *D_002022E4;

void func_001C93A0(s8 *arg0) {
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
func_00102A60(arg0, (*(s32 *)((s8 *)(var_v1) + (0x18))) + 0x10);
}
}
