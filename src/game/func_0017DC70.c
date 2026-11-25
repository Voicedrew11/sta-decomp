typedef struct { char pad[0x10]; int id; } S;
int *func_00165130(S *, int);
int func_001B17E0(int *);

void func_0017DC70(S *s)
{
    int *r = func_00165130(s, 0);
    int id = s->id;
    int t = -1;

    *r = func_001B17E0(&t);
    if (t != id)
        *r = -1;
}
