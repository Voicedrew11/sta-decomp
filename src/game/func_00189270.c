#include "m2c.h"
typedef struct { s32 pad0; s32 a0; u8 pad8[0x28]; } Item;
typedef struct { u32 n; Item *items; } Grp;
typedef struct { s32 idx; u8 pad4[0x3C]; } Ent;
typedef struct { u32 n; Ent *e; } List;
void func_00128580(s32, s32);
void func_00177570(s32);
extern s32 D_002020DC;
extern List *D_0049F8A0[];
extern Grp D_0049FD80[];
extern Grp D_0049FB30[];
extern Grp D_004A06C0[];
extern s32 D_0049FF84[];
extern u32 D_0049FF88[];
extern s32 D_0049FD34[];
extern u32 D_0049FD38[];
extern s32 D_004A08C4[];
extern u32 D_004A08C8[];

void func_00189270(void) {

    {
    List **pl;
    Grp *grps;
    u32 i;
    List *l;
    u32 j;
    u32 k;
    Grp *g;
    i = 0;
    if (i < D_0049FF88[0]) {
        pl = D_0049F8A0;
        grps = D_0049FD80;
        do {
            l = pl[0x128];
            if (l != NULL) {
                for (j = 0; j < l->n; j++) {
                    g = &grps[l->e[j].idx];
                    for (k = 0; k < g->n; k++) {
                        if (g->items[k].a0 != 0) {
                            func_00177570(g->items[k].a0);
                        }
                    }
                }
            }
            i++;
            pl++;
        } while (i < D_0049FF88[0]);
    }
    }
    func_00128580(D_002020DC, D_0049FF84[0]);

    {
    List **pl;
    Grp *grps;
    u32 i;
    List *l;
    u32 j;
    u32 k;
    Grp *g;
    i = 0;
    if (i < D_0049FD38[0]) {
        pl = D_0049F8A0;
        grps = D_0049FB30;
        do {
            l = pl[0x94];
            if (l != NULL) {
                for (j = 0; j < l->n; j++) {
                    g = &grps[l->e[j].idx];
                    for (k = 0; k < g->n; k++) {
                        if (g->items[k].a0 != 0) {
                            func_00177570(g->items[k].a0);
                        }
                    }
                }
            }
            i++;
            pl++;
        } while (i < D_0049FD38[0]);
    }
    }
    func_00128580(D_002020DC, D_0049FD34[0]);

    {
    List **pl;
    Grp *grps;
    u32 i;
    List *l;
    u32 j;
    u32 k;
    Grp *g;
    i = 0;
    if (i < D_004A08C8[0]) {
        pl = D_0049F8A0;
        grps = D_004A06C0;
        do {
            l = pl[0x378];
            if (l != NULL) {
                for (j = 0; j < l->n; j++) {
                    g = &grps[l->e[j].idx];
                    for (k = 0; k < g->n; k++) {
                        if (g->items[k].a0 != 0) {
                            func_00177570(g->items[k].a0);
                        }
                    }
                }
            }
            i++;
            pl++;
        } while (i < D_004A08C8[0]);
    }
    }
    func_00128580(D_002020DC, D_004A08C4[0]);
}
