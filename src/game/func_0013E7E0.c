typedef struct { unsigned char p : 2; unsigned char v : 1; } BF_2_1;

void func_0013E7E0(char *a0, unsigned char a1) {
    if (((BF_2_1 *)(a0 + 0x5B3))->v != a1) {
        ((BF_2_1 *)(a0 + 0x5B3))->v = a1;
        *(float *)(a0 + 0x5C0) = 1.0f;
    }
}
