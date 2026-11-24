extern char * D_00201FA8;
void func_0013EEB0(int, unsigned char);
void func_0013EB40(int, unsigned char);
void func_0013EF80(int, int);

void func_001450D0(char * a0) {
    func_0013EEB0(*(int *)(D_00201FA8 + 0x154), *(unsigned char *)(a0 + 0x8));
}

void func_001450E0(char * a0) {
    func_0013EB40(*(int *)(D_00201FA8 + 0x154), *(unsigned char *)(a0 + 0x8));
}

void func_001450F0(void) {
    func_0013EF80(*(int *)(D_00201FA8 + 0x154), 0xff);
}
