void func_001C9410(void);
extern char * D_002022E4;
void func_00102A60(int, int);

void func_00145760(void) {
    func_001C9410();
}

int func_00145770(void) {
    return *(int *)(D_002022E4 + 0x518);
}

void func_00145780(int a0) {
    func_00102A60(a0, *(int *)(D_002022E4 + 0x518));
}
