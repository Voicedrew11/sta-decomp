extern char *D_00201FA8;
void func_0013E710(int, int);
void func_0013E6F0(int, int);

void func_00144370(unsigned char *a0) {
    int p = *(int *)(D_00201FA8 + 0x154);
    unsigned char b;
    b = a0[0x10];
    if (a0[8]) {
        func_0013E710(p, 1);
    }
    if (b) {
        func_0013E6F0(p, 1);
    }
}
