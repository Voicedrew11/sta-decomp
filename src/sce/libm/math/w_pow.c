/* libm.a member w_pow.o (STA: this game's libm is built with _IEEE_LIBM: the
 * wrapper only calls the kernel) */
double __ieee754_pow(double, double);

double pow(double x, double y)
{
    return __ieee754_pow(x, y);
}
