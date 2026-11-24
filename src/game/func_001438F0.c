char * func_00165130(int, int);
int func_001AA740(void);

int func_001438F0(int a0) {
    char * t1;
    int t2;
    t1 = func_00165130(a0, 0);
    t2 = func_001AA740();
    *(unsigned char *)t1 = t2;
    return t2;
}
