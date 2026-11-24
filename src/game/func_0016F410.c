typedef struct { unsigned char p : 3; unsigned char v : 1; } BF_3_1;

void func_0016F410(char * a0, int a1, int a2) {
    *(int *)(a0 + 0x2C) = a1;
    ((BF_3_1 *)(a0 + 0x3C))->v = a2;
}
