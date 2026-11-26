char *func_00165130(char *, int);
int func_00195B10(int);
int func_0018AC90(int, int);

void func_0017ECD0(char *a0) {
    char *p = func_00165130(a0, 1);
    int q = func_00195B10(*(int *)(a0 + 8));
    int v = 3;
    if (q) {
        v = func_0018AC90(q, 0);
    }
    *p = v;
}
