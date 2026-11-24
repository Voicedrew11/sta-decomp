#include "m2c.h"
f32 func_0011D4A8(f32);

f32 func_00187460(s8 *arg0, s8 *arg1)
{
  f32 temp_f20;
  f32 temp_f3;
  f32 var_f0;
  var_f0 = 0.0f;
  temp_f3 = (*((f32 *) (((s8 *) arg0) + 0))) - (*((f32 *) (((s8 *) arg1) + 0)));
  temp_f20 = (*((f32 *) (((s8 *) arg0) + 4))) - (*((f32 *) (((s8 *) arg1) + 4)));
  if (temp_f3 == 0.0f)
  {
    var_f0 = 0.0f;
  }
  else
  {
    var_f0 = func_0011D4A8(temp_f3 / temp_f20);
  }
  if (temp_f20 < 0.0f)
  {
    var_f0 += 3.141592f;
  }
  return var_f0;
}
