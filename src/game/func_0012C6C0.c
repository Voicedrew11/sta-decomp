extern unsigned char D_0022EC15[];
void func_001DA8F0(int, short);

void func_0012C6C0(int a0) {
    int i;
    D_0022EC15[0] = 0;
    for (i = 0; i < 4; i++) {
        func_001DA8F0(i, a0);
    }
}
