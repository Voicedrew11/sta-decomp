typedef struct { unsigned char p : 2; unsigned char v : 1; } BF_2_1;
typedef struct { unsigned char p : 1; unsigned char v : 1; } BF_1_1;
typedef struct { unsigned char v : 1; } BF_0_1;

void func_0013EBF0(char * a0, int a1) {
    ((BF_2_1 *)(a0 + 0x5B0))->v = a1;
}

void func_0013EC10(char * a0, int a1) {
    ((BF_1_1 *)(a0 + 0x5B0))->v = a1;
}

void func_0013EC30(char * a0, int a1) {
    ((BF_0_1 *)(a0 + 0x5B0))->v = a1;
}
