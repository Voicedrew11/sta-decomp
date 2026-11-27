/* Commit a pending pair of 64-bit values. */

extern int D_00202390;
extern long long D_00202398, D_002023A0, D_00202388, D_00202380;

void PlayTime_Resume_1_001DF960(void)
{
    if (D_00202390) {
        D_00202388 = D_00202398;
        D_00202380 = D_002023A0;
        D_00202390 = 0;
    }
}
