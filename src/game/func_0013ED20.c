#include "m2c.h"

s32 func_0013ED20(s8 *arg0)
{
  s8 **temp_v1;
  u16 new_var;
  s8 *var_v0;
  if (((u64) (((s64) (*((u8 *) (((s8 *) arg0) + 0x5A1)))) << 0x3C)) >> 0x3F)
  {
    return (((s32) (*((u16 *) (((s8 *) arg0) + 0x710)))) % 100) & 0xFF;
  }
  temp_v1 = *((s8 ***) (((s8 *) arg0) + 0x4A8));
  new_var = *((u16 *) (((s8 *) arg0) + 0x4AC));
  if (temp_v1 != 0)
  {
    if (1)
    {
    }
    var_v0 = (signed char *) ((*((s32 *) (((s8 *) (*temp_v1)) + 0x13C))) + ((new_var & 0xFFFF) * 0x54));
  }
  else
  {
    var_v0 = 0;
  }
  if (var_v0 != 0)
  {
    return (((s32) (*((u16 *) (((s8 *) var_v0) + 0x1A)))) % 100) & 0xFF;
  }
  return (((s32) (*((u16 *) (((s8 *) arg0) + 0x710)))) % 100) & 0xFF;
}
