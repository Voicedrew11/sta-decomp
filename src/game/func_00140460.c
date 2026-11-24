void func_00102A60(int, int);

int func_00140460(char * a0) {
    return *(int *)(*(char **)(a0 + 0x518) + 0x198);
}

void func_00140470(char * a0, int a1) {
    func_00102A60(a1, *(int *)(*(char **)(a0 + 0x518) + 0x198));
}
