/* Compiler probe: functions from the two gcc-built game modules
 * (0x1D3A90-0x1D7EC0, 0x1E19A0-0x1E5E80) that ee-gcc 2.96-ee-001003-1
 * -O2 -G 8 -fno-strict-aliasing compiles to the retail bytes. Used by
 * tools/probe_compiler.py; not part of the build. Types and names are
 * guesses. */

typedef unsigned int u32;
typedef unsigned short u16;

extern int D_004B6418[][4];
/* gcc 2.9 scales the index differently */
int func_001D6FE8(int a, int b) { return D_004B6418[a][b]; }

int func_001E1FD8(u16 x) { return x * 144; }

typedef struct { char pad[0x40]; float x, y; int x48, x4C; char pad2[0x20]; float v[4]; } Cam;
extern Cam *D_00201E60;

/* the pointer is reloaded after each store only without strict aliasing */
void func_001E2A48(float *v)
{
    D_00201E60->x = v[0];
    D_00201E60->y = v[1];
}
void func_001E2AB0(int v) { D_00201E60->x4C = v; D_00201E60->x48 = v; }
void func_001E2B60(float a, float b, float c, float d)
{
    D_00201E60->v[0] = a; D_00201E60->v[1] = c; D_00201E60->v[2] = b; D_00201E60->v[3] = d;
}

u32 *func_001E52B8(u32 *p, u32 a, u32 b, u32 c, u32 d)
{
    p[0] = a; p[1] = b; p[2] = c; p[3] = d;
    return p + 4;
}
