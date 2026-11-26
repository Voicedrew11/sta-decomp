/* libm.a member wf_acos.o (STA: this game's libm is built with _IEEE_LIBM: the
 * wrapper only calls the kernel) */
float __ieee754_acosf(float);

float acosf(float x)
{
    return __ieee754_acosf(x);
}
