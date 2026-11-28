#include "common.h"
typedef struct { s32 a; s32 b; s32 c8; s32 c; } H;
typedef struct Ch {
    s32 x0;
    s32 x4;
    u32 type : 8;
    u32 off : 24;
    u16 xC;
    u16 xE;
    H h;
} Ch;
typedef struct {
    u8 pad0[0x20];
    u16 x20;
    u8 pad22[8];
    u8 x2A;
    u8 x2B;
    u8 x2C;
    Flags8 x2D;
} El;
typedef struct {
    u8 pad0[0x10];
    u8 **x10;
    u16 x14;
} Src;
typedef struct {
    s32 x0;
    Src **x4;
    void *x8;
    s32 xC;
    s32 x10;
    s32 x14;
    s32 x18[24];
    s32 x78;
    s32 x7C;
    u8 pad80[0x1A];
    u8 t[4][0x100];
    u8 pad49A[6];
    s32 x4A0;
} Obj;
typedef struct { char pad[0x3C]; unsigned int : 4; unsigned int f : 1; } BF_3C_4_1;
extern s8 D_001FD960[];
extern s32 D_00202278;
extern s32 *D_00202280;
void EnemyData_Parse_0_001A7810(Obj **a0, Src **a1);
void EnemyData_ParseWrap_0_001A7C60(void **arg0, void **arg1, u32 arg2, s8 arg3, void *arg4, void *arg5, s32 arg6, s32 arg7);
u8** EnemyData_LoadTextures_0_001A7C70(s32 arg0);
void* Pool_Alloc_3_001288C0(s32, s32);

/* EnemyData_Parse_0_001A7810 */
#define DATA(h) ((u8 *)((s32)(h) + 0x10) + (((h)->c + 15) & ~15))

void EnemyData_Parse_0_001A7810(Obj **a0, Src **a1) {
    s32 dbc1;
    s32 dbc2;
    u8 *base;
    Obj *o;
    s32 n;
    s32 rcs;
    Ch *c;
    Ch *d;
    H *h;
    u32 i;
    u32 j;
    u32 cnt;
    s32 k;
    s32 m;
    El *e;
    s32 tbl[24];

    dbc2 = 0;
    dbc1 = 0;
    n = 0;
    rcs = 0;
    o = *a0;
    base = *(*a1)->x10;
    switch (*(s32 *)base) {
    case 0x4D415453:
        c = (Ch *)(base + ((Ch *)base)->off);
        cnt = ((Ch *)base)->xE;
        for (i = 0; i < cnt; i++) {
            if (c->x0 == (D_001FD960[0] | (D_001FD960[1] << 8) | (D_001FD960[2] << 16) | (D_001FD960[3] << 24))) break;
            c = (Ch *)((u8 *)c + c->x4);
        }
        d = (Ch *)((u8 *)c + c->off);
        for (i = 0; i < c->xE; i++) {
            switch (d->x0) {
            case 0x61444243:
                h = &d->h;
                dbc1 = DATA(h) - base;
                h = (H *)((u8 *)h + h->a);
                dbc2 = DATA(h) - base;
                break;
            case 0x61545043:
                h = &d->h;
                tbl[n++] = DATA(h) - base;
                break;
            case 0x61524353:
                h = &d->h;
                rcs = DATA(h) - base;
                if (h->b == 0) rcs = 0;
                break;
            }
            d = (Ch *)((u8 *)d + d->x4);
        }
        break;
    }
    o->x8 = Pool_Alloc_3_001288C0(D_00202278, n * 0x170 + 0x640);
    o->x4 = a1;
    o->x10 = dbc1;
    o->x14 = dbc2;
    o->x4A0 = rcs;
    for (k = 0; k < 0x100; k++) {
        o->t[0][k] = 0xFF;
        o->t[1][k] = 0xFF;
        o->t[2][k] = 0xFF;
        o->t[3][k] = 0xFF;
    }
    for (k = 0; k < n; k++) {
        e = (El *)(base + tbl[k]);
        for (m = e->x2A; m < e->x2A + e->x2B; m++) {
            o->t[0][m] = k;
            if (e->x2D.f.b4) o->t[1][m] = (u8)k;
            if (e->x2D.f.b5) o->t[2][m] = k;
            if (e->x20) o->t[3][m] = k;
        }
    }
    for (k = 0; k < n; k++) {
        o->x18[k] = tbl[k];
    }
    o->x78 = (*a1)->x14;
    o->x7C = n;
}

/* EnemyData_ParseWrap_0_001A7C60 */
#define EnemyData_Parse_0_001A7810 EnemyData_Parse_0_001A7810__as_EnemyData_ParseWrap_0_001A7C60
void EnemyData_Parse_0_001A7810__as_EnemyData_ParseWrap_0_001A7C60(void **arg0, void **arg1, u32 arg2, s8 arg3, void *arg4, void *arg5, s32 arg6, s32 arg7);

void EnemyData_ParseWrap_0_001A7C60(void **arg0, void **arg1, u32 arg2, s8 arg3, void *arg4, void *arg5, s32 arg6, s32 arg7)
{
    EnemyData_Parse_0_001A7810(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}
#undef EnemyData_Parse_0_001A7810

/* EnemyData_LoadTextures_0_001A7C70 */
u8 **EnemyData_LoadTextures_0_001A7C70(s32 arg0) {
    u8 *temp_3;
    u8 **temp_2;
    s32 **var_16;

    var_16 = (s32 **) (NULL);
    temp_2 = (u8 **) (Tex_LoadArchive_0_0016F950(D_00202280, (u8 **) arg0));
    if (temp_2 == NULL) {
        return NULL;
    }
    temp_3 = (u8 *) (*temp_2);
    if (((BF_3C_4_1 *)temp_3)->f != 0) {
        var_16 = (s32 **) (M2C_FIELD(temp_3, s32 ***, 0x10));
    }
    if (var_16 != NULL) {
        Tex_RegisterTtix_0_00178080(var_16);
    }
    return (u8 **) (temp_2);
}
