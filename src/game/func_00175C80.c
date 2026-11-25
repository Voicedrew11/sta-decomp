/* Clear a manager of four 0x310-byte items and mark each item unused. */

void *memset(void *, int, unsigned int);

typedef struct { int id; char pad[0x30C]; } Item;
typedef struct { int a, b; Item item[4]; } Mgr;
extern Mgr D_00437DC0;

void func_00175C80(void)
{
    int i;

    memset(&D_00437DC0, 0, sizeof(Mgr));
    for (i = 3; i >= 0; i--)
        D_00437DC0.item[i].id = -1;
}
