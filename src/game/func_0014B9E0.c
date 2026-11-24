extern int D_002022E4;
void func_00145F40(int, char *, int);

void func_0014B9E0(char * a0) {
    *(int *)(a0 + 0x5C) = 0x3f800000;
    *(float *)(a0 + 0xB0) = *(float *)(a0 + 0x64);
    *(int *)(a0 + 0xB8) = (0x47c30000 | 0x5000);
    *(int *)(a0 + 0xA8) = 0;
    func_00145F40(D_002022E4, a0 + 0xB4, 0);
}
