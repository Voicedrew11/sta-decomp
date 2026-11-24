void func_0015A470(int, int, int, int);
extern int D_00201E94;
int func_00159D10(int);
int func_0015ABD0(int);
int func_0015A350(int);
void func_0015A2F0(int, char *);

void func_0014DC50(char * a0) {
    func_0015A470(*(int *)(a0 + 0x1C), *(int *)(a0 + 0x14), 0x80000, 0);
}

int func_0014DC70(char * a0, int a1) {
    int t1;
    int t2;
    int t3;
    t1 = func_00159D10(a1);
    t2 = func_0015ABD0(t1);
    *(int *)(a0 + 0x1C) = t2;
    t3 = func_0015A350(t2);
    *(int *)(a0 + 0x4) = t3;
    *(int *)(a0 + 0x8) = *(int *)(a0 + 0x4);
    *(int *)(a0 + 0x34) = D_00201E94;
    func_0015A2F0(*(int *)(a0 + 0x1C), a0 + 0x20);
    return 1;
}
