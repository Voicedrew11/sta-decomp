#include "common.h"
#include "m2c.h"
typedef struct { char p[0x1D8]; u8 b0:1; } T;
typedef struct { s32 x0; char p[0x8A]; s16 x8E; } U;
typedef struct { s32 id; } O_Map_GetLightIndex_0_001B0BC0;
typedef struct { char pad[0x1D8]; u8 b0:1; } O2;
typedef struct { u8 pad[0x20]; u16 x20; u8 pad2[0x30 - 0x22]; } Ent;
typedef struct { s32 id; u8 pad[0x72]; u16 x76; u8 pad2[0x148 - 0x78]; Ent *x148; u8 pad3[0x18C - 0x14C]; u32 *x18C; u8 pad4[0x1D8 - 0x190]; u8 x1D8; } O_Map_GetGlowIndex_0_001B0C70;
extern s32 D_00201E80;
extern T **D_00201E88;
extern T **D_00201E8C;
s32* Map_FindLoaded_0_001B0AE0(s32 arg0);
void Map_SetVar_0_001B0B30(s32 arg0, s16 arg1);
s16 Map_GetLightIndex_0_001B0BC0(s32 id, s32 base);
u16 Map_GetGlowIndex_0_001B0C70(s32 arg0, s32 arg1);

/* Map_FindLoaded_0_001B0AE0 */
s32 *Map_FindLoaded_0_001B0AE0(s32 arg0) {
    if ((M2C_FIELD(&D_00201E80, s32 **, 8) != NULL) && (*M2C_FIELD(&D_00201E80, s32 **, 8) == arg0)) {
        return M2C_FIELD(&D_00201E80, s32 **, 8);
    }
    if ((M2C_FIELD(&D_00201E80, s32 **, 0xC) != NULL) && (*M2C_FIELD(&D_00201E80, s32 **, 0xC) == arg0)) {
        return M2C_FIELD(&D_00201E80, s32 **, 0xC);
    }
    return NULL;
}

/* Map_SetVar_0_001B0B30 */
void Map_SetVar_0_001B0B30(s32 arg0, s16 arg1) {
    U *r = 0;
    if ((D_00201E88 ? (*D_00201E88)->b0 != 0 : 0) && ((U *)*D_00201E88)->x0 == arg0) r = (U *)*D_00201E88;
    if ((D_00201E8C ? (*D_00201E8C)->b0 != 0 : 0) && ((U *)*D_00201E8C)->x0 == arg0) r = (U *)*D_00201E8C;
    if (r) r->x8E = arg1;
}

/* Map_GetLightIndex_0_001B0BC0 */
#define D_00201E88 D_00201E88__as_Map_GetLightIndex_0_001B0BC0
extern O_Map_GetLightIndex_0_001B0BC0 **D_00201E88__as_Map_GetLightIndex_0_001B0BC0;
#define D_00201E8C D_00201E8C__as_Map_GetLightIndex_0_001B0BC0
extern O_Map_GetLightIndex_0_001B0BC0 **D_00201E8C__as_Map_GetLightIndex_0_001B0BC0;
static inline s32 act(O_Map_GetLightIndex_0_001B0BC0 **p) { return p ? (((O2 *)*p)->b0 != 0) : 0; }
s16 Map_GetLightIndex_0_001B0BC0(s32 id, s32 base) {
    s32 r = -1;
    if (act(D_00201E88) && (*D_00201E88)->id == id) r = 0;
    if (act(D_00201E8C) && (*D_00201E8C)->id == id) r = 1;
    if (r == -1) return r;
    return base + r * 64;
}
#undef D_00201E88
#undef D_00201E8C

/* Map_GetGlowIndex_0_001B0C70 */
#define TB ((O_Map_GetGlowIndex_0_001B0C70 ***)&D_00201E80)
static inline O_Map_GetGlowIndex_0_001B0C70 *get(s32 arg0) {
    s32 var_v1;
    s32 var_v1_2;
    O_Map_GetGlowIndex_0_001B0C70 *t;
    O_Map_GetGlowIndex_0_001B0C70 *t2;
    O_Map_GetGlowIndex_0_001B0C70 *r;
    r = NULL;
    if (TB[2] != NULL) {
        var_v1 = ((*TB[2])->x1D8 & 1) != 0;
    } else {
        var_v1 = 0;
    }
    if (var_v1 != 0) {
        t = *TB[2];
        if (t->id == arg0) {
            r = t;
        }
    }
    var_v1_2 = TB[3] != NULL ? ((*TB[3])->x1D8 & 1) != 0 : 0;
    if (var_v1_2 != 0) {
        t2 = *TB[3];
        if (t2->id == arg0) {
            r = t2;
        }
    }
    return r;
}

u16 Map_GetGlowIndex_0_001B0C70(s32 arg0, s32 arg1) {
    O_Map_GetGlowIndex_0_001B0C70 *p;
    Ent *e;
    s32 i;

    p = get(arg0);
    if (p != NULL) {
        for (i = 0; i < p->x76; i++) {
            if (arg1 == p->x148[i].x20 % 100) {
                return p->x18C[i];
            }
        }
    }
    return 0;
}
#undef TB
