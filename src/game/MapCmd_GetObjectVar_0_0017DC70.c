typedef struct { char pad[0x10]; int id; } S;
int *Script_GetArgPtr_2_00165130(S *, int);
int MapObj_GetCount_0_001B17E0(int *);

void MapCmd_GetObjectVar_0_0017DC70(S *s)
{
    int *r = Script_GetArgPtr_2_00165130(s, 0);
    int id = s->id;
    int t = -1;

    *r = MapObj_GetCount_0_001B17E0(&t);
    if (t != id)
        *r = -1;
}
