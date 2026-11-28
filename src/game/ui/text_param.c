typedef struct { unsigned char v : 3; } BF_0_3;
typedef struct { unsigned char p : 3; unsigned char v : 1; } BF_3_1;
typedef struct { unsigned char p : 4; unsigned char v : 1; } BF_4_1;

void TextParam_Init_1_00187A90(char * a0, int a1, int a2) {
    *(long long *)a0 = 0;
    *(int *)(a0 + 0x14) = 0;
    *(int *)(a0 + 0x24) = 0x3f800000;
    *(int *)(a0 + 0x20) = 0x3f800000;
    *(int *)(a0 + 0x18) = (0x3dcc0000 | 0xcccd);
    *(int *)(a0 + 0x1C) = (0x3fcc0000 | 0xcccd);
    *(unsigned short *)(a0 + 0xC) = 0;
    *(unsigned short *)(a0 + 0xE) = 0;
    ((BF_4_1 *)(a0 + 0x8))->v = 0;
    *(int *)(a0 + 0x28) = a1;
    *(unsigned short *)(a0 + 0x10) = a2;
    *(unsigned short *)(a0 + 0x12) = 0;
    ((BF_0_3 *)(a0 + 0x8))->v = 0;
    ((BF_3_1 *)(a0 + 0x8))->v = 0;
}
