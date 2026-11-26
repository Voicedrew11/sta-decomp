/* libm.a member wf_asin.o (SAB: this game's libm is built with _IEEE_LIBM: the
 * wrapper only calls the kernel) */
float __ieee754_asinf(float);

float asinf(float x)
{
    return __ieee754_asinf(x);
}
