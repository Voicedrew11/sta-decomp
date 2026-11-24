#include "m2c.h"
s8 **func_0016F950(s32, s32);
extern s32 D_00202280;

s8 **func_001A7C70(s32 arg0)
{
  s8 **temp_v0;
  s8 **var_s0;
  s8 *temp_v1;
  var_s0 = 0;
  temp_v0 = func_0016F950(D_00202280, arg0);
  if (temp_v0 == 0)
  {
    return 0;
  }
  temp_v1 = *temp_v0;
  if ((((u64) (((s64) (*((u8 *) (((s8 *) temp_v1) + 0x3C)))) << 0x3B)) >> 0x3F) != 0)
  {
    var_s0 = *((s8 ***) (((s8 *) temp_v1) + 0x10));
  }
  if (var_s0 != 0)
  {
    func_00178080(var_s0);
  }
  return temp_v0;
}
