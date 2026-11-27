#include "common.h"

typedef struct { char pad[0x24]; f32 yaw; } B;
typedef struct { char pad[0x518]; B *b; } S;
extern S *D_002022E4;
f32 cosf(f32 x);
f32 sinf(f32 x);

void Player_GetRightVector_1_00145640(f32 *v)
{
    f32 a = D_002022E4->b->yaw;
    a += 1.5707964f;
    v[0] = -sinf(a);
    v[1] = 0.0f;
    v[2] = -cosf(a);
}
