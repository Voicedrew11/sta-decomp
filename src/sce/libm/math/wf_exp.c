/* libm.a member wf_exp.o (SAB: this game's libm is built with _IEEE_LIBM: the
 * wrapper only calls the kernel) */
float __ieee754_expf(float);

float expf(float x)
{
    return __ieee754_expf(x);
}
