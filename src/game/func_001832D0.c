#include "m2c.h"
extern u8 D_0048D140[];
extern u8 D_0048D141[];
extern u8 D_0048D142[];
extern u8 D_0048D143[];
extern s8 D_0048D170[];
typedef struct 
{
  s32 a;
  s8 *b;
} S __attribute__((aligned(16)));
void func_00182C10(s8 *, S *);

void func_001832D0(s8 *arg0, s32 arg1, s32 arg2)
{
  S s = {0};
  s8 *t1;
  u8 *a3;
  u8 *a1;
  t1 = D_0048D170 + (arg1 * 0x30);
  *((s32 *) t1) = arg2;
  s.a = 1;
  a3 = D_0048D140 + (arg1 * 4);
  s.b = t1;
  *((f32 *) (((s8 *) arg0) + 0x34)) = 1.0f;
  *((f32 *) (((s8 *) arg0) + 0x38)) = 1.0f;
  *a3 = 0xFF;
  D_0048D141[arg1 * 4] = 0xFF;
  D_0048D142[arg1 * 4] = 0xFF;
  a1 = D_0048D143 + (arg1 * 4);
  if ((*a1) > 0xD0)
  {
    *a1 = 0xFF;
  }
  else
  {
    *a1 += 0x20;
  }
  *((f32 *) (((s8 *) arg0) + 0x3C)) = *((f32 *) (D_0048D140 + (arg1 * 4)));
  if ((*((s32 *) (((s8 *) t1) + 4))) != 0)
  {
    func_00182C10(arg0, &s);
  }
  else
  {
    *((s32 *) (D_0048D140 + (arg1 * 4))) = 0;
  }
}
