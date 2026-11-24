extern char * D_00201ED0;
void func_00102A60(char *, int, int, int);
int func_00131640(void);

int func_001315A0(int a0, int a1, int a2) {
    *(int *)(D_00201ED0 + 0x30) = a0;
    *(unsigned char *)(D_00201ED0 + 0xE) = 4;
    *(unsigned short *)(D_00201ED0 + 0xA) = (a1 & 0xff);
    *(int *)(D_00201ED0 + 0x20) = 0;
    *(int *)(D_00201ED0 + 0x34) = 0;
    func_00102A60(D_00201ED0 + 0x10, a2, a2, 4);
    return func_00131640();
}
