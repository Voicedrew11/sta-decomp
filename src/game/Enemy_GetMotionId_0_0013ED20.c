#include "m2c.h"
#include "common.h"
typedef struct { s32 *p; } P;
typedef struct { char pad[0x4A8]; P *p; char p1[0xF5]; unsigned char : 3; unsigned char f : 1; char p2[0x170]; u16 h; } Obj;
s32 Enemy_GetMotionId_0_0013ED20(s8 *arg0);
s32 Enemy_GetTargetHandle_0_0013EDE0(Obj *o);

/* Enemy_GetMotionId_0_0013ED20 */
s32 Enemy_GetMotionId_0_0013ED20(s8 *arg0)
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

/* Enemy_GetTargetHandle_0_0013EDE0 */
s32 Enemy_GetTargetHandle_0_0013EDE0(Obj *o)
{
    s32 r;
    if (o->f)
        r = o->h;
    else if (o->p)
        r = *o->p->p;
    else
        r = 0;
    return r;
}
