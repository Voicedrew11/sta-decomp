typedef struct { char pad[0x154]; void *p; } Ctx;
extern Ctx *D_00201FA8;
int Enemy_Get5B1b2_1_0013EA40(void *);
void Msg_Close_1_0018B0C0(void);
void Enemy_Set5B1b2_1_0013EA20(void *, int);

void EnemyCmd_Set5B1b2Notify_0_00144F00(unsigned char *a)
{
    void *p = D_00201FA8->p;
    int v = a[8];
    if (!(unsigned char)Enemy_Get5B1b2_1_0013EA40(p) && v)
        Msg_Close_1_0018B0C0();
    Enemy_Set5B1b2_1_0013EA20(p, v);
}
