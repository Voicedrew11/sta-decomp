extern char D_00437DC0[];
extern int D_00437DC8[];
extern int D_004380D8[];
extern int D_004383E8[];
extern int D_004386F8[];
int func_00123C40(char *, int, int);

int func_00175C80(void) {
    int t1;
    t1 = func_00123C40(D_00437DC0, 0, 0xc48);
    D_004386F8[0] = -1;
    D_004383E8[0] = -1;
    D_004380D8[0] = -1;
    D_00437DC8[0] = -1;
    return t1;
}
