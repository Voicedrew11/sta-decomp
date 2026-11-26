/* libm.a member wf_pow.o (SAB: this game's libm is built with _IEEE_LIBM: the
 * wrapper only calls the kernel) */
float __ieee754_powf(float, float);

float powf(float x, float y)
{
    return __ieee754_powf(x, y);
}
