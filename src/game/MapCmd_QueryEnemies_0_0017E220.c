/* cf. KFIV's LinkedPoint_StartDefault (kfiv-decomp src/game/model/linked_point.c). */

typedef struct { char pad[8]; int kind; } Point;
void EnemyScr_BroadcastQuery_0_00141380(int, int);

void MapCmd_QueryEnemies_0_0017E220(Point *p)
{
    if (p->kind == 1)
        EnemyScr_BroadcastQuery_0_00141380(0x80, 0);
}
