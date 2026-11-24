extern char D_001F3850[];
extern char D_001F3860[];
extern float D_001F3870[];
char * func_0015B900(int);
void func_00102A60(char *, char *);
int func_00102A18(char *, char *, float);
extern char D_001F3840[];

int func_001B7290(void) {
    char * t1;
    int t3;
    t1 = func_0015B900(-1);
    func_00102A60(D_001F3860, t1 + 0x20);
    t3 = func_00102A18(D_001F3850, t1 + 0x10, 255.0f);
    D_001F3870[0] = *(float *)(t1 + 0x30);
    return t3;
}

char * func_001B72F0(void) {
    return D_001F3840;
}
