typedef struct { unsigned char p : 5; unsigned char v : 1; } BF_5_1;
typedef struct { unsigned char p : 4; unsigned char v : 2; } BF_4_2;

unsigned int func_0013E4D0(char * a0) {
    return ((BF_5_1 *)(a0 + 0x5B4))->v;
}

unsigned int func_0013E4E0(char * a0) {
    return ((BF_4_2 *)(a0 + 0x5B5))->v;
}
