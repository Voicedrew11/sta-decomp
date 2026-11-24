typedef struct { unsigned char p : 7; unsigned char v : 1; } BF_7_1;
typedef struct { unsigned char p : 1; unsigned char v : 1; } BF_1_1;
typedef struct { unsigned char p : 6; unsigned char v : 1; } BF_6_1;
typedef struct { unsigned char p : 6; unsigned char v : 2; } BF_6_2;

void func_0013E6D0(char * a0, int a1) {
    ((BF_7_1 *)(a0 + 0x5B3))->v = a1;
}

void func_0013E6F0(char * a0, int a1) {
    ((BF_1_1 *)(a0 + 0x5B6))->v = a1;
}

void func_0013E710(char * a0, int a1) {
    ((BF_6_1 *)(a0 + 0x5B3))->v = a1;
}

void func_0013E730(char * a0, int a1) {
    ((BF_6_2 *)(a0 + 0x5B2))->v = a1;
}
