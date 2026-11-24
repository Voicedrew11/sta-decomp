extern char *D_00201FC0;

char *func_00163C40(char *a0) {
    unsigned short i = *(unsigned short *)(a0 + 0xA0);
    if (i == 0xFFFF) {
        return 0;
    }
    return D_00201FC0 + i * 0x120;
}
