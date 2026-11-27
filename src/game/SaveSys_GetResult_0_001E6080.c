/* The current record's second word, and its third through `third`. */

typedef struct { int a, b, c; char pad[0x400 - 12]; } Rec;
extern Rec D_004BC394[];
extern int D_002023E4;

int SaveSys_GetResult_0_001E6080(int *third)
{
    int i = D_002023E4;

    if (third)
        *third = D_004BC394[i].c;
    return D_004BC394[i].b;
}
