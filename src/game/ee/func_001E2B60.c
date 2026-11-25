typedef struct { char pad[0x40]; float x, y; int x48, x4C; char pad2[0x20]; float v[4]; } Cam;
extern Cam *D_00201E60;

void func_001E2B60(float a, float b, float c, float d)
{
    D_00201E60->v[0] = a;
    D_00201E60->v[1] = c;
    D_00201E60->v[2] = b;
    D_00201E60->v[3] = d;
}
