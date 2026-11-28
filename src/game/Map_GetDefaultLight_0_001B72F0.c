#include "common.h"
typedef struct { char p[0x38]; u8 x38; s8 x39; char q[6]; } S;
typedef struct { char p[0x7C]; u16 n; char q[0x168 - 0x7E]; S *s; } O_Map_FindSfxEntry_0_001B7300;
typedef struct { Vec p; Vec b; Vec c; f32 x30; f32 x34; u8 x38; u8 pad[7]; } E;
typedef struct { u8 pad[0x10]; Vec pos; u8 pad20[0x5C]; u16 n; u8 pad7E[0xEA]; E *e; } O_Map_SetupLights_0_001B7380;
extern s32 D_002022C4;
extern s32 D_002022D0;
s32* Map_GetDefaultLight_0_001B72F0(void);
S* Map_FindSfxEntry_0_001B7300(O_Map_FindSfxEntry_0_001B7300 *o, s32 id);
void Map_SetupLights_0_001B7380(O_Map_SetupLights_0_001B7380 *o, s32 idx);
void Map_SetPools_0_001B7470(s32 arg0, s32 arg1);
void sceVu0CopyVector(Vec *, Vec *);
void sceVu0AddVector(Vec *, Vec *, Vec *);
void LightGroup_Clear_0_0015B890(s32);
s32 Light_Add_0_0015B980(s32 idx, Vec *a, Vec *b, Vec *c, f32 f0, f32 f1, f32 f2, f32 f3);

/* Map_GetDefaultLight_0_001B72F0 */
s32 D_001F3840[0x4] = { 0, 0, 0, 0x46ea6000 };
s32 *Map_GetDefaultLight_0_001B72F0(void) {
    return D_001F3840;
}

/* Map_FindSfxEntry_0_001B7300 */
S *Map_FindSfxEntry_0_001B7300(O_Map_FindSfxEntry_0_001B7300 *o, s32 id) {
    s32 i;
    S *s;
    u16 n;
    if (o == NULL || id < 0 || id > 127) {
        return NULL;
    }
    n = o->n;
    s = o->s;
    for (i = 0; i < n; i++, s++) {
        if (s->x38 == 1 && s->x39 >= 0 && id == s->x39) break;
    }
    if (i == n) return NULL;
    return s;
}

/* Map_SetupLights_0_001B7380 */
void Map_SetupLights_0_001B7380(O_Map_SetupLights_0_001B7380 *o, s32 idx) {
    Vec c;
    Vec p;
    s32 i;
    E *e;
    sceVu0CopyVector(&c, &o->pos);
    LightGroup_Clear_0_0015B890(idx);
    for (i = 0; i < o->n; i++) {
        e = &o->e[i];
        if (!e->x38) {
            sceVu0CopyVector(&p, &e->p);
            sceVu0AddVector(&p, &p, &c);
            p.w = e->p.w;
            Light_Add_0_0015B980(idx, &p, &e->b, &e->c, p.w, e->b.w, e->x30, e->x34);
        }
    }
}

/* Map_SetPools_0_001B7470 */
void Map_SetPools_0_001B7470(s32 arg0, s32 arg1) {
    D_002022C4 = arg0;
    D_002022D0 = arg1;
}
