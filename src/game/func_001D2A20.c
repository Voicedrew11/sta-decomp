typedef struct { unsigned char p : 2; unsigned char v : 1; } BF_2_1;

unsigned int func_001D2A20(char * a0) {
    return ((BF_2_1 *)(*(char **)(a0 + 0x4B0) + 0x2AD))->v;
}
