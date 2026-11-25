typedef struct { char pad[0x40]; float x, y; int x48, x4C; char pad2[0x20]; float v[4]; } Cam;
extern Cam *D_00201E60;

void func_001E2A48(float *v)
{
    D_00201E60->x = v[0];
    D_00201E60->y = v[1];
}
