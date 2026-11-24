typedef struct { unsigned char p : 3; unsigned char v : 1; } BF_3_1;
typedef struct { unsigned char p : 2; unsigned char v : 1; } BF_2_1;

void func_0013E620(char * a0, int a1) {
    ((BF_3_1 *)(a0 + 0x5B4))->v = a1;
}

void func_0013E640(char * a0, int a1) {
    ((BF_2_1 *)(a0 + 0x5B4))->v = a1;
}
