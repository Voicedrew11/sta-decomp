extern char * D_00201FA8;
void func_0013C420(int, unsigned char, short, int);

void func_001452A0(char * a0) {
    func_0013C420(*(int *)(D_00201FA8 + 0x154), *(unsigned char *)(a0 + 0x8), *(short *)(a0 + 0x10), 1);
}

void func_001452C0(char * a0) {
    *(unsigned char *)(*(char **)(D_00201FA8 + 0x154) + 0x609) = *(signed char *)(a0 + 0x8);
}
