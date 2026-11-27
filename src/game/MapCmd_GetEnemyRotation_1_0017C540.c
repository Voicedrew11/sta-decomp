#include "common.h"
typedef struct { u8 b; u8 pad[7]; } W;
typedef struct { W x0; W x8; W x10; } Arg;
f32 *Script_GetArgPtr_2_00165130(Arg *, s32);
void *Event_FindEnemyByMotion_0_00179E50(u8, u8);
void Enemy_CopyRotation_2_00140440(void *, Vec *);

void MapCmd_GetEnemyRotation_1_0017C540(Arg *a) {
    f32 *p2 = Script_GetArgPtr_2_00165130(a, 2);
    f32 *p3 = Script_GetArgPtr_2_00165130(a, 3);
    f32 *p4 = Script_GetArgPtr_2_00165130(a, 4);
    void *o;
    Vec v;
    if ((o = Event_FindEnemyByMotion_0_00179E50(a->x8.b, a->x10.b)) == 0) {
        *p2 = 0.0f;
        *p3 = 0.0f;
        *p4 = 0.0f;
    } else {
        Enemy_CopyRotation_2_00140440(o, &v);
        *p2 = 180.0f * v.x / 3.1415927f;
        *p3 = 180.0f * v.y / 3.1415927f;
        *p4 = 180.0f * v.z / 3.1415927f;
    }
}
