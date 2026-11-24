void func_0013E3F0(char *a0, unsigned char a1, short a2) {
    ((short *)(a0 + 0x6B4))[a1] = a2;
}

unsigned short func_0013E410(char *a0) {
    return ((unsigned short *)(a0 + 0x6B4))[*(unsigned char *)(a0 + 0x5B0) & 1];
}
