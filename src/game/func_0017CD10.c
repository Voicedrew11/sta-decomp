char * func_00165130(char *, int);
int func_001CE200(int);

int func_0017CD10(char * a0) {
    int v2;
    char * t1;
    int t3;
    v2 = *(int *)(a0 + 0x8);
    t1 = func_00165130(a0, 1);
    t3 = func_001CE200(v2);
    *(int *)t1 = t3;
    return t3;
}
