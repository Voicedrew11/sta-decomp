typedef struct { unsigned char p : 3; unsigned char v : 1; } BF_3_1;

void func_00167240(char *a0) {
    ((BF_3_1 *)(a0 + 0x188))->v = 1;
}
