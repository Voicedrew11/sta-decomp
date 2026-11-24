extern int D_00201FF8;
extern int D_00201FFC;
extern int D_00202000;
void func_001549D0(void);
void func_00155900(void);
void func_001548F0(int);

void func_0016B280(void) {
    if (D_00201FF8) {
        func_001549D0();
        func_00155900();
        func_001548F0(0);
        D_00201FF8 = 0;
    }
    D_00201FFC = 0;
    D_00202000 = 0;
}
