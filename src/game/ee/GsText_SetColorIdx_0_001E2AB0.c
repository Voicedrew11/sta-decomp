typedef struct { char pad[0x40]; float x, y; int x48, x4C; char pad2[0x20]; float v[4]; } Cam;
extern Cam *D_00201E60;

void GsText_SetColorIdx_0_001E2AB0(int v)
{
    D_00201E60->x4C = v;
    D_00201E60->x48 = v;
}
