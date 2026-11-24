extern char * D_00201FA8;
void func_0013E7E0(int, int);
void func_0013E7C0(int, int);
void func_0013E890(int, unsigned char);

void func_00144D50(void) {
    func_0013E7E0(*(int *)(D_00201FA8 + 0x154), 1);
}

void func_00144D60(void) {
    func_0013E7C0(*(int *)(D_00201FA8 + 0x154), 1);
}

void func_00144D70(char * a0) {
    func_0013E890(*(int *)(D_00201FA8 + 0x154), *(unsigned char *)(a0 + 0x8));
}
