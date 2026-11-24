typedef struct { unsigned char p : 2; unsigned char v : 1; } BF_2_1;
typedef struct { unsigned char p : 3; unsigned char v : 1; } BF_3_1;

unsigned int func_0013E820(char * a0) {
    return ((BF_2_1 *)(a0 + 0x5B3))->v;
}

unsigned int func_0013E830(char * a0) {
    return ((BF_3_1 *)(a0 + 0x5B2))->v;
}
