char * func_00165130(char *, int);
int func_0013D500(unsigned char);

int func_00145100(char * a0) {
    char * t1;
    int t2;
    t1 = func_00165130(a0, 0);
    t2 = func_0013D500(*(unsigned char *)(a0 + 0x10));
    *(unsigned char *)t1 = t2;
    return t2;
}
