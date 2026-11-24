extern int D_00201C28;
extern int D_00201E98;
extern int D_00201E9C;
extern int D_00201EA4;
extern int D_00201EA8;

int func_0019A790(void);

void func_0012C0A0(void) {
    D_00201C28 = 0x12;
    D_00201EA4 = 1;
    D_00201EA8 = 1;
    D_00201E98 = 1;
    D_00201E9C = 1;
}

void func_0012C0C0(void) {
    D_00201EA4 = 0;
    D_00201C28 = 0x12;
    D_00201EA8 = 0;
    D_00201E98 = 1;
    D_00201E9C = 0;
}

int func_0012C0E0(void) {
    return !func_0019A790();
}
