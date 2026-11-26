#include "m2c.h"
M2C_UNK func_001CE7D0(s32, M2C_UNK);
M2C_UNK func_001CEDC0(M2C_UNK, u16, s32);

void func_001CB980(u16 *arg0)
{
  s32 temp_v0;
  s32 var_v0;
  s32 var_a2;
  s8 *new_var;
  u16 *var_s0;
  u16 temp_a1;
  var_s0 = arg0;
  var_v0 = func_001C9BA0();
  var_a2 = 0;
  do
  {
    new_var = (s8 *) var_v0;
    temp_a1 = *((u16 *) (new_var + 0x20));
    *((u16 *) (new_var + 0x20)) = (u16) (temp_a1 + (*var_s0));
    if (((s16) (*((u16 *) (new_var + 0x20)))) < 0)
    {
      *((u16 *) (new_var + 0x20)) = 0U;
    }
    if (((s16) (*((u16 *) (new_var + 0x20)))) > (0x3E8 - 1))
    {
      *((u16 *) (new_var + 0x20)) = 0x3E7U;
    }
    var_a2 += 1;
    var_s0 += 1;
    var_v0 += 2;
  }
  while (var_a2 < 8);
  func_001CEDC0(3, temp_a1, var_a2);
  temp_v0 = func_001C9B60();
  if (temp_v0 != 0)
  {
    func_001CE7D0(temp_v0, 0);
    func_001CE660((s8 *) temp_v0, 0);
  }
}
