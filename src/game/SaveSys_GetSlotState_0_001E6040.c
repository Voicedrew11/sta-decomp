/* The first word of 0x400-byte record `index`. */

typedef struct { int a, b, c; char pad[0x400 - 12]; } Rec;
extern Rec D_004BC394[];

int SaveSys_GetSlotState_0_001E6040(int index)
{
    return D_004BC394[index].a;
}
