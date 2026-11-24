#include "m2c.h"

s32 func_001B7840(s32 arg0, s32 arg1)
{
  s32 var_a2;
  s8 *temp_v0;
  u16 temp_a0;
  s8 *var_a1;
  temp_v0 = (signed char *) func_001B19A0(arg0);
  if (temp_v0 == 0)
  {
    return -1;
  }
  temp_a0 = *((u16 *) (((s8 *) temp_v0) + 0x6E));
  var_a2 = 0;
  if (0 < ((s32) temp_a0))
  {
    var_a1 = *((s8 **) (((s8 *) temp_v0) + 0x138));
    loop_5:
    if (arg1 == (((s32) (*((u16 *) (((s8 *) var_a1) + 0x1A)))) % 100))
    {
      return var_a2;
    }

    var_a2 += 1;
    var_a1 += 0x30;
    if (var_a2 >= ((s32) temp_a0))
    {
      goto block_9;
    }
    goto loop_5;
  }
  block_9:
  return -1;

}
