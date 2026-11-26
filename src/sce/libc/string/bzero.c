/* libc.a member bzero.o (STA: not in kfiv-decomp; newlib's bzero) */
void bzero(void *b, unsigned int length)
{
    char *ptr = (char *)b;

    while (length--)
        *ptr++ = 0;
}
