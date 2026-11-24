typedef struct { unsigned char p : 2; unsigned char v : 1; } BF_2_1;

void func_00167640(char *a0, int a1) {
    if (a0) {
        ((BF_2_1 *)(a0 + 0x188))->v = a1;
    }
}
