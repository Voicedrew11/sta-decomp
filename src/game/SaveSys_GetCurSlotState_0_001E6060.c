/* The first word of the current record (index at 0x2023E4). cf. SaveSys_GetSlotState_0_001E6040. */

typedef struct { int a, b, c; char pad[0x400 - 12]; } Rec;
extern Rec D_004BC394[];
extern int D_002023E4;

int SaveSys_GetCurSlotState_0_001E6060(void)
{
    return D_004BC394[D_002023E4].a;
}
