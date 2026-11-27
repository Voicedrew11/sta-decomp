#include "common.h"
typedef struct { Vec p; f32 x10; f32 x14; f32 x18; u8 x1C; u8 x1D; u8 x1E; u8 x1F; u16 x20; u8 x22; u8 p23[0xD]; } E;
typedef struct { u8 p[0x10]; Vec x10; u8 p20[0x5E]; u16 n; u8 p80[0xEC]; E *e; } O;
void sceVu0CopyVector(Vec *, Vec *);
void sceVu0AddVector(Vec *, Vec *, Vec *);
void PointLightGroup_Clear_0_0015C6D0(s32);
void PointLight_Add_0_0015C730(s32, Vec *, f32, f32, f32, f32, u8, u8, u8, u8, u16, u8);

void Map_SetupPointLights_0_001B7190(O *o, s32 a) {
    Vec base;
    Vec v;
    s32 i;
    s32 off;
    E *e;
    sceVu0CopyVector(&base, &o->x10);
    PointLightGroup_Clear_0_0015C6D0(a);
    i = 0;
    if (i < o->n) {
        off = 0;
        do {
        e = (E *)((u8 *)o->e + off);
        sceVu0CopyVector(&v, &e->p);
        sceVu0AddVector(&v, &v, &base);
        v.w = e->p.w;
        PointLight_Add_0_0015C730(a, &v, v.w, e->x18, e->x10, e->x14, e->x1C, e->x1D, e->x1E, e->x1F, e->x20, e->x22);
        i++;
        off += 0x30;
        } while (i < o->n);
    }
}
