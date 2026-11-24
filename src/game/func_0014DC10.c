#include "m2c.h"

s32 func_0014DC10(s8 *arg0)
{
  s8 *temp_a0;
  temp_a0 = *((s8 **) (arg0 + 0x1C));
  if (temp_a0 != 0)
  {
    func_0015AB80(temp_a0);
  }
  *((s8 **) (((s8 *) arg0) + 0x1C)) = 0;
  return 1;
}
