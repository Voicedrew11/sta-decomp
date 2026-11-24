typedef struct { unsigned char p : 5; unsigned char v : 1; } BF_5_1;
extern char * D_002022E4;

unsigned int func_00145620(void) {
    return ((BF_5_1 *)(*(char **)(D_002022E4 + 0x518) + 0x521))->v;
}
