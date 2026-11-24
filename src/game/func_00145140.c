extern char * D_00201FA8;
char * func_00165130(int, int);
int func_0013E220(int);

int func_00145140(int a0) {
    int v2;
    char * t1;
    int t3;
    v2 = *(int *)(D_00201FA8 + 0x154);
    t1 = func_00165130(a0, 0);
    t3 = func_0013E220(v2);
    *(unsigned char *)t1 = t3;
    return t3;
}
