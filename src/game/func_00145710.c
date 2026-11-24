extern char * D_002022E4;
void func_00102A60(int, char *);

char * func_00145710(void) {
    return *(char **)(D_002022E4 + 0x518) + 0x20;
}

void func_00145720(int a0) {
    func_00102A60(a0, *(char **)(D_002022E4 + 0x518) + 0x20);
}
