int func_00102AD8(void);

int func_00178870(char * a0, float f0, float f1, float f2) {
    int t1;
    t1 = func_00102AD8();
    *(float *)a0 = (f0 / 1024.0f);
    *(float *)(a0 + 0x14) = (f0 / 1024.0f);
    *(float *)(a0 + 0x28) = ((f2 + f1) / (f2 - f1));
    *(float *)(a0 + 0x38) = ((-2.0f * (f2 * f1)) / (f2 - f1));
    *(int *)(a0 + 0x2C) = 0x3f800000;
    *(int *)(a0 + 0x3C) = 0;
    return t1;
}
