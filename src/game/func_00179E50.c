#include "m2c.h"

s8 *func_00179E50(s32 arg0, s32 arg1)
{
  s32 sp5C;
  s8 *var_s0;
  s32 temp_s3;
  s32 temp_v1;
  sp5C = 0;
  var_s0 = (signed char *) func_001A5460(&sp5C);
  if (var_s0 != 0)
  {
    loop_1:
    if (func_0013EE30(var_s0) == 0)
    {
      temp_s3 = func_0013ED20(var_s0) & 0xFF;
      temp_v1 = func_0013EDE0(var_s0) & 0xFF;
      if (((temp_s3 & 0xFF) == arg1) && ((temp_v1 & 0xFF) == arg0))
      {
        return var_s0;
      }
    }

    var_s0 = (signed char *) func_001A5460(&sp5C);
    if (var_s0 == 0)
    {
      goto block_7;
    }
    goto loop_1;
  }
  block_7:
  return 0;

}
