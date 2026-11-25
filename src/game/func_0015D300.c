#include "common.h"
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
#define DEG(d) (3.1415927f * (d) / 180.0f)
typedef struct { Vec v0; Vec a[4]; Vec b[4]; Vec c; } D30;
extern Mtx D_001F2170;
extern Vec D_001F2060[];
extern Vec D_001F2070[];
extern Vec D_001F2080[];
extern Vec D_001F20C0[];
extern Vec D_001F2100[];
extern Vec D_001F2110[];
extern D30 D_0030D0E0;
void func_00102B78(f32, Mtx *, Mtx *);
void func_00102CC8(f32, Mtx *, Mtx *);
void func_00102A60(Vec *, Vec *);

void func_0015D300(void) {
    Mtx m;
    s32 i;

    for (i = 0; i < 4; i++) {
        func_00102B78(WRAP(DEG(D_001F2080[i].y)), &m, &D_001F2170);
        func_00102CC8(WRAP(DEG(D_001F2080[i].x)), &m, &m);
        D_0030D0E0.a[i].x = m.m[0].x;
        D_0030D0E0.a[i].y = m.m[0].y;
        D_0030D0E0.a[i].z = m.m[0].z;
        D_0030D0E0.a[i].w = D_001F2080[i].w;
        D_0030D0E0.b[i].x = D_001F20C0[i].x;
        D_0030D0E0.b[i].y = D_001F20C0[i].y;
        D_0030D0E0.b[i].z = D_001F20C0[i].z;
    }
    D_001F2110[0].x = D_001F2060[0].x;
    D_001F2110[0].y = D_001F2060[0].y;
    D_001F2110[0].z = D_001F2060[0].z;
    D_001F2110[0].w = D_001F2060[0].w;
    D_0030D0E0.v0.x = D_001F2070[0].x;
    D_0030D0E0.v0.y = D_001F2070[0].y;
    D_0030D0E0.v0.z = D_001F2070[0].z;
    D_0030D0E0.v0.w = D_001F2070[0].w;
    func_00102A60(&D_0030D0E0.c, D_001F2100);
}
