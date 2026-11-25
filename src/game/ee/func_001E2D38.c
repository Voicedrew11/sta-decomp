/* Copy four words into the camera block at 0x4C.
 * cf. KFIV's Menu_MoveItemAfter-like word copies; the pointer is reloaded
 * after every store (ee-gcc without strict aliasing). */

typedef struct { char pad[0x4C]; int w[4]; } Cam;
extern Cam *D_00201E60;

void func_001E2D38(int *src)
{
    D_00201E60->w[0] = src[0];
    D_00201E60->w[1] = src[1];
    D_00201E60->w[2] = src[2];
    D_00201E60->w[3] = src[3];
}
