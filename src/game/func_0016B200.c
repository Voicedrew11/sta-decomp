typedef struct { unsigned char p : 3; unsigned char v : 1; } BF_3_1;

void func_0016B200(char * a0, int a1) {
    ((BF_3_1 *)(*(char **)(a0 + 0x210) + 0x94))->v = a1;
}
