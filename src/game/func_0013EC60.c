typedef struct { unsigned char p : 1; unsigned char v : 1; } BF_1_1;
typedef struct { unsigned char p : 3; unsigned char v : 1; } BF_3_1;

unsigned int func_0013EC60(char *a0, unsigned char a1) {
    return ((BF_1_1 *)(((char **)(a0 + 0x4B4))[a1] + 0x2D))->v;
}

unsigned int func_0013EC80(char *a0, unsigned char a1) {
    return ((BF_3_1 *)(((char **)(a0 + 0x4B4))[a1] + 0x2D))->v;
}
