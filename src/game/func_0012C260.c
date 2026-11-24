extern char D_0022CBC0[];

void func_0012C260(void) {
    char *p = D_0022CBC0;
    int i = 0;
    do {
        if (p[0] && p[0xF] && p[0xE] == 2) {
            p[3] = 1;
            p[0xE] = 3;
            p[0x6E] = 0;
        }
        i++;
        p += 0x80;
    } while (i < 0x3F);
}
