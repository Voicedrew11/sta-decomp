typedef struct { unsigned char p : 7; unsigned char v : 1; } BF_7_1;
extern unsigned char D_002F2078[];

void func_00159310(int a0) {
    ((BF_7_1 *)D_002F2078)->v = a0;
}
