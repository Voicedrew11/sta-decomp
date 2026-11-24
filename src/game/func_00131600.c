extern char * D_00201ED0;
void func_00131640(void);

void func_00131600(int a0, int a1) {
    *(int *)(D_00201ED0 + 0x30) = a0;
    *(unsigned char *)(D_00201ED0 + 0xE) = 0;
    *(unsigned short *)(D_00201ED0 + 0xA) = (a1 & 0xff);
    *(unsigned short *)(D_00201ED0 + 0x8) = *(short *)(D_00201ED0 + 0xA);
    *(int *)(D_00201ED0 + 0x20) = 0;
    *(int *)(D_00201ED0 + 0x34) = 0;
    func_00131640();
}
