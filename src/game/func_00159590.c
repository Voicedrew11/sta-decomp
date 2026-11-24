typedef struct { unsigned char p : 5; unsigned char v : 1; } BF_5_1;
extern unsigned char D_002F2078[];
extern char D_002F1A80[];
typedef struct { unsigned char p : 4; unsigned char v : 1; } BF_4_1;
extern char D_002F1A60[];
typedef struct { unsigned char p : 2; unsigned char v : 1; } BF_2_1;
typedef struct { unsigned char p : 1; unsigned char v : 1; } BF_1_1;
extern char D_002F19CC[];
typedef struct { unsigned char v : 1; } BF_0_1;
extern char D_002F19C0[];

char *func_00159590(int a0) {
    ((BF_5_1 *)D_002F2078)->v = a0 != 0;
    return D_002F1A80;
}

char *func_001595C0(int a0) {
    ((BF_4_1 *)D_002F2078)->v = a0 != 0;
    return D_002F1A60;
}

void func_001595F0(int a0) {
    ((BF_2_1 *)D_002F2078)->v = a0 != 0;
}

char *func_00159620(int a0) {
    ((BF_1_1 *)D_002F2078)->v = a0 != 0;
    return D_002F19CC;
}

char *func_00159650(int a0) {
    ((BF_0_1 *)D_002F2078)->v = a0 != 0;
    return D_002F19C0;
}
