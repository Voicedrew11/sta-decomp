#include "m2c.h"
typedef struct { s32 pad0; s32 a0; u8 pad8[0x28]; } Item;
typedef struct { u32 n; Item *items; } Grp;
typedef struct { s32 idx; u8 pad4[0x3C]; } Ent;
typedef struct { u32 n; Ent *e; } List;
void func_00128580(s32, s32);
void func_00177570(s32);
extern s32 D_002020DC;
extern List *D_0049F8A0[];
extern Grp D_0049FFD0[];
extern s32 D_004A01D4[];
extern u32 D_004A01D8[];

void func_00189080(void) {
    List **pl;
    Grp *grps;
    u32 i;
    List *l;
    u32 j;
    u32 k;
    Grp *g;

    i = 0;
    if (i < D_004A01D8[0]) {
        pl = D_0049F8A0;
        grps = D_0049FFD0;
        do {
            l = pl[0x1BC];
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
        } while (i < D_004A01D8[0]);
    }
    func_00128580(D_002020DC, D_004A01D4[0]);
}
