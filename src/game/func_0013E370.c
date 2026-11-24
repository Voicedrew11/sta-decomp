typedef struct { unsigned char p : 6; unsigned char v : 2; } BF_6_2;
typedef struct { unsigned char p : 5; unsigned char v : 1; } BF_5_1;

void func_0013E370(char *a0) {
    if (((BF_6_2 *)(a0 + 0x5B2))->v < 2) {
        if (((BF_5_1 *)(a0 + 0x5B2))->v) {
            *(float *)(a0 + 0x5DC) = *(float *)(*(char **)(*(char **)(a0 + 0x518) + 0x198) + 4);
        }
    } else {
        *(float *)(a0 + 0x5DC) = *(float *)(*(char **)(*(char **)(a0 + 0x518) + 0x198) + 4);
    }
}
