typedef struct { char pad[0x4A8]; int **q; } Hold;

int *func_0013DCE0(Hold *h)
{
    if (h->q)
        return (int *)((char *)*h->q + 0x10);
    return 0;
}
