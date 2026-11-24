int func_001DA4F0(int);

int func_0012C1B0(void) {
    int i = 0;
    int n = 0;
    do {
        if (func_001DA4F0(i) == 1) {
            n++;
        }
        i++;
    } while (i < 0x40);
    return n;
}
