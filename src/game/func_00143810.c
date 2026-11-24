unsigned char func_00143810(char *a0, unsigned char a1, unsigned char a2) {
    if (a1 == a2) {
        return 0xFF;
    }
    return ((unsigned char (*)[256])(a0 + 0x10))[a1][a2];
}
