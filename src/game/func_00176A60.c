extern int D_0020200C;
extern long long D_00202010;
extern char D_00438A30[];
extern char D_00438A70[];
extern char D_0043F080[];
extern int D_004830F0[];
extern int D_004830F4[];
void func_0010BCA0(int);
void func_00178D20(void);
void func_00178C00(char *, int);
int func_00123C40(char *, int, int);
void func_00176440(int);
int func_001549D0(void);

int func_00176A60(void) {
    D_004830F4[0] = 0;
    D_004830F0[0] = 1;
    func_0010BCA0(0);
    func_00178D20();
    func_00178C00(D_00438A70, 0x6610);
    func_00178C00(D_0043F080, 0x40000);
    D_0020200C = 0;
    D_00202010 = 0;
    return func_00123C40(D_00438A30, 0, 0x33);
}

int func_00176AE0(void) {
    func_00176440(0);
    return func_001549D0();
}
