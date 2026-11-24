typedef struct { unsigned char p : 6; unsigned char v : 1; } BF_6_1;
typedef struct { unsigned char p : 5; unsigned char v : 1; } BF_5_1;

void func_0013E490(char * a0, int a1) {
    ((BF_6_1 *)(a0 + 0x5B4))->v = a1;
}

void func_0013E4B0(char * a0, int a1) {
    ((BF_5_1 *)(a0 + 0x5B4))->v = a1;
}
