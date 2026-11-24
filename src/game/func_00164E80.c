extern char *D_00201FA4;

void func_00164E80(void) {
    int i;
    for (i = 0; i < *(int *)(D_00201FA4 + 4); i++) {
        *(int *)(D_00201FA4 + i * 0x258 + 0x294) = 0;
    }
}
