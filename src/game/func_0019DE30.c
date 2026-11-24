#include "m2c.h"

s32 func_0019DE30(s32 arg0)
{
  s8 *new_var3;
  s8 *temp_v1;
  unsigned int new_var;
  u16 *new_var2;
  temp_v1 = (signed char *) (func_001AFC90() + (2 * (72 * (new_var = arg0))));
  new_var3 = (s8 *) temp_v1;
 do { new_var2 = (u16 *) (new_var3 + 0xA); } while (0);
  if (((*new_var2) == 0) && ((*((u8 *) (((s8 *) temp_v1) + 0x29))) == 5))
  {
    return 1;
  }
  return 0;
}
