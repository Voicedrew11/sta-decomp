/* libc.a member abs.o (STA: not in kfiv-decomp; newlib's abs) */
int abs(int i)
{
    return (i < 0) ? -i : i;
}
