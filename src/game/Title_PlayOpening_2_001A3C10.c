#include "common.h"
typedef struct { char pad[0x14]; unsigned char : 3; unsigned char f : 1; } BF_14_3_1;
typedef union { u32 w; struct { u8 r, g, b, a; } c; } Col;
typedef struct { s32 idx; u8 pad4[0x38]; u8 c0, c1, c2, c3; } Item;
typedef struct { u32 n; Item *items; } List;
typedef struct { u8 pad[0x8]; List *list; } Res;
typedef struct { s32 st; s32 fl; s8 x8; } S;
extern s32 D_001FD870[];
extern Vec D_001F3310;
extern f32 D_00202264;
extern s32 D_004A4390[];
extern struct { unsigned char : 2; unsigned char f : 1; char pad[15]; } D_004A43AC;
extern s32 D_004A4394[];
extern u8 D_004A43A2[];
void Title_PlayOpening_2_001A3C10(void *arg0);
void Title_ResetOnEvent_0_001A3C70(void *arg0);
void Title_DrawLogo_0_001A3CC0(void);
void Title_UpdateWrap_0_001A3EB0(s32 arg0);
void Title_HandleEvent_0_001A3EC0(S *s);
void Title_Reset_0_001A3F80(void);
void Title_Draw_0_001A3FB0(void);
Res* MenuLayout_Get_1_00189050(s32);
s32 MenuLayout_GetSub_1_00189020(s32);
void Ui_DrawSpriteRotated_1_00182080(s32, f32, Vec *, Vec *, Col *, s32);
void Ui_DrawElem_1_00182C10(Item *, s32);

/* Title_PlayOpening_2_001A3C10 */
void Title_PlayOpening_2_001A3C10(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0) == 0) {
        GsPkt_EndLayer_1_00155900();
        Movie_Play_2_0017FF70((s32) D_001FD870);
        GsPkt_SetLayer_1_00154700(5, 0);
        ((BF_14_3_1 *)arg0)->f = 1;
    }
}

/* Title_ResetOnEvent_0_001A3C70 */
#define Title_Reset_0_001A3F80 Title_Reset_0_001A3F80__as_Title_ResetOnEvent_0_001A3C70
int Title_Reset_0_001A3F80__as_Title_ResetOnEvent_0_001A3C70();
void Title_ResetOnEvent_0_001A3C70(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0) == 0x16) {
        Title_Reset_0_001A3F80();
        M2C_FIELD(arg0, s8 *, 8) = 5;
        M2C_FIELD(arg0, s32 *, 4) = 0;
        M2C_FIELD(arg0, s32 *, 0) = 0x1F;
    }
}
#undef Title_Reset_0_001A3F80

/* Title_DrawLogo_0_001A3CC0 */
void Title_DrawLogo_0_001A3CC0(void) {
    u32 i;
    List *l;
    s32 base;
    f32 t;

    l = MenuLayout_Get_1_00189050(3)->list;
    base = MenuLayout_GetSub_1_00189020(3);
    {
    Vec a = D_001F3310;
    Vec b = {0};
    Col col;
    col.c.r = col.c.g = col.c.b = 2;
    col.c.a = 0xFF;
    Ui_DrawSpriteRotated_1_00182080(0, 0.0f, &a, &b, &col, 0);
    }
    for (i = 0; i < l->n; i++) {
        l->items[i].c2 = 0xFF;
        l->items[i].c1 = 0xFF;
        l->items[i].c0 = 0xFF;
        t = 30.0f;
        if (D_00202264 < t) {
            l->items[i].c3 = (s32)(127.0f - 127.0f * (t - D_00202264) / t);
        } else if (!(D_00202264 <= 150.0f)) {
            l->items[i].c3 = 0;
        } else if (!(D_00202264 < 120.0f)) {
            l->items[i].c3 = (s32)(127.0f - 127.0f * (D_00202264 - 120.0f) / t);
        }
        Ui_DrawElem_1_00182C10(&l->items[i], base + l->items[i].idx * 8);
    }
}

/* Title_UpdateWrap_0_001A3EB0 */
#define Title_HandleEvent_0_001A3EC0 Title_HandleEvent_0_001A3EC0__as_Title_UpdateWrap_0_001A3EB0
int Title_HandleEvent_0_001A3EC0__as_Title_UpdateWrap_0_001A3EB0();
void Title_UpdateWrap_0_001A3EB0(s32 arg0) {
    Title_HandleEvent_0_001A3EC0((void *) arg0);
}
#undef Title_HandleEvent_0_001A3EC0

/* Title_HandleEvent_0_001A3EC0 */
void Title_HandleEvent_0_001A3EC0(S *s) {
    switch (s->st) {
    case 25:
        D_00202264 = 0.0f;
        break;
    case 27:
    case 0:
        break;
    case 22:
        if (!(D_00202264 < 150.0f)) {
            s->x8 = 4;
            s->fl = 0;
            s->st = 26;
        }
        D_00202264 += 1.0f;
        break;
    case 26:
    case 28:
    case 30:
        break;
    }
    if (s->fl & 8) {
        s->x8 = 4;
        s->fl = 0;
        s->st = 26;
    }
}

/* Title_Reset_0_001A3F80 */
void Title_Reset_0_001A3F80(void)
{
    D_004A4390[0] = 0;
    D_004A43AC.f = 1;
}

/* Title_Draw_0_001A3FB0 */
void Title_Draw_0_001A3FB0(void) {
    if ((*D_004A4394) == 2) {
        if ((*D_004A43A2) == 0xD) {
            goto block_3;
        }
    } else {
block_3:
        Menu_SetFlags_0_0018A310(4);
    }
    UiAnim_UpdateAll_1_0017F5C0();
    Menu_DrawBackground_0_00187B20(0);
}
