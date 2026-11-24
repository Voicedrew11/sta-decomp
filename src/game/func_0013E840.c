typedef struct { unsigned char p : 2; unsigned char v : 1; } BF_2_1;
typedef struct { unsigned char p : 1; unsigned char v : 1; } BF_1_1;

void func_0013E840(char * a0, int a1) {
    ((BF_2_1 *)(a0 + 0x5B2))->v = a1;
}

void func_0013E860(char * a0, int a1) {
    ((BF_1_1 *)(a0 + 0x5B2))->v = a1;
}
