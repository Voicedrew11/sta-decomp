#include "m2c.h"

void func_001CEBA0(void)
{
  s8 *new_var;
  s32 var_a0;
  s32 var_a1;
  u16 temp_v1;
  var_a1 = func_001C9BA0();
  var_a0 = 0;
  do
  {
    new_var = (s8 *) var_a1;
    temp_v1 = *((u16 *) (new_var + 0x70));
    if (temp_v1 != 0)
    {
      *((u16 *) (new_var + 0x70)) = (u16) (temp_v1 - 1);
    }
    var_a0 += 1;
    var_a1 += 2;
  }
  while (var_a0 < 6);
}
