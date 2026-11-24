void func_00170250(char *, int);
int func_001531A0(char *, char *);

int func_001745D0(char * a0, char * a1) {
    func_00170250(a0, *(int *)*(char **)a1);
    return func_001531A0(a0 + 0x34, a1);
}
