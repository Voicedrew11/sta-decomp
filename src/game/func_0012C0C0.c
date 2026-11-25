/* Enter mode 0x12 with only the third fade flag set. cf. func_0012C070. */

extern int D_00201C28;
extern int D_00201EA4, D_00201EA8, D_00201E98, D_00201E9C;

void func_0012C0C0(void)
{
    D_00201C28 = 0x12;
    D_00201EA4 = 0;
    D_00201EA8 = 0;
    D_00201E98 = 1;
    D_00201E9C = 0;
}
