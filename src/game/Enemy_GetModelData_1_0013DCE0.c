typedef struct { char pad[0x4A8]; int **q; } Hold;

int *Enemy_GetModelData_1_0013DCE0(Hold *h)
{
    if (h->q)
        return (int *)((char *)*h->q + 0x10);
    return 0;
}
