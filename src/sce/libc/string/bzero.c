/* libc.a member bzero.o (SAB: not in kfiv-decomp; newlib's bzero) */
void bzero(void *b, unsigned int length)
{
    char *ptr = (char *)b;

    while (length--)
        *ptr++ = 0;
}
