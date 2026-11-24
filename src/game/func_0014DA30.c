extern char D_003139A0[];
int func_00102A60(char *, char *);

int func_0014DA30(char * a0) {
    int t1;
    t1 = func_00102A60(a0 + 0xB0, D_003139A0);
    *(int *)(a0 + 0xA8) = 0;
    return t1;
}
