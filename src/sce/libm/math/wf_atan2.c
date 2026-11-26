/* libm.a member wf_atan2.o (STA: this game's libm is built with _IEEE_LIBM: the
 * wrapper only calls the kernel) */
float __ieee754_atan2f(float, float);

float atan2f(float y, float x)
{
    return __ieee754_atan2f(y, x);
}
