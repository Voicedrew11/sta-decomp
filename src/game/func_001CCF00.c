char * func_001C9BA0(void);
void func_001CCF50(char *, int, int);
int func_001CEDC0(int);

int func_001CCF00(int a0, int a1) {
    char * t1;
    t1 = func_001C9BA0();
    func_001CCF50(t1 + 0x80, a0, a1);
    return func_001CEDC0(3);
}
