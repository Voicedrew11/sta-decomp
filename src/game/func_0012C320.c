extern char D_0022CBC0[];
void func_001313A0(void);
void func_0012F880(void);

void func_0012C320(void) {
    char *p;
    int i;
    func_001313A0();
    func_0012F880();
    p = D_0022CBC0;
    i = 0;
    do {
        if (p[0]) {
            p[0xE] = 1;
        }
        i++;
        p += 0x80;
    } while (i < 0x3F);
}
