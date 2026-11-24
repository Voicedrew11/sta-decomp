typedef struct { unsigned char p : 5; unsigned char v : 1; } BF_5_1;
typedef struct { unsigned char p : 1; unsigned char v : 1; } BF_1_1;

void func_0013EE90(char * a0, int a1) {
    ((BF_5_1 *)(a0 + 0x5A1))->v = a1;
}

void func_0013EEB0(char * a0, int a1) {
    ((BF_1_1 *)(*(char **)(*(char **)(a0 + 0x518) + 0x190) + 0x120))->v = a1;
}
