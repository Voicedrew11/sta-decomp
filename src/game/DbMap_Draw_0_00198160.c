#include "m2c.h"
typedef union { u32 w; u8 b[4]; } Col;
typedef struct { f32 x, y; } V2;
typedef struct { u32 idx; s32 f4; u8 pad8[0x24]; f32 x; f32 y; u8 pad34[0xC]; } Ent;
typedef struct { u32 n; Ent *p; } L;
typedef struct { u8 pad[0x1C]; L *l; } O;
extern f32 D_00201D44;
extern s32 D_002021A8;
extern s32 D_004A1450[];
extern s32 D_004A18B0[];
void DbMap_Draw_0_00198160(u8 *arg0);
void DbMap_DrawRing_0_001982A0(s32 arg, f32 ang);
void Menu_SetFlags_0_0018A310(s32);
f32 Approachf_3_00187770(f32, f32, f32);
s32 DbMap_GetName_0_00195A30(s32);
void Text_Draw_2_001875C0(s32, s32, Col, f32, f32, f32);
void UiAnim_UpdateAll_1_0017F5C0(void);
void Menu_DrawFrame_0_00185390(f32, s32, s32, s32);
O* MenuLayout_Get_1_00189050(s32);
s8* MenuLayout_GetSub_1_00189020(s32);
void Menu_DrawBackground_0_00187B20(s32);
f32 Vec2_Angle_1_00187460(V2 *, V2 *);
f32 sinf(f32);
f32 cosf(f32);
f32 sqrtf(f32);
void DbMapProc_DrawInfo_1_00198570(void);
void Ui_DrawList_1_001829B0(Ent *, s8 *, void (*)(void), s32);

/* DbMap_Draw_0_00198160 */
void DbMap_Draw_0_00198160(u8 *arg0) {
    Col c;
    s32 s;

    s = D_004A1450[D_004A18B0[0]];
    Menu_SetFlags_0_0018A310(0xE);
    if (arg0[8] == 0x19) {
        D_00201D44 = Approachf_3_00187770(D_00201D44, -0.02f, 3.5f);
    } else {
        D_00201D44 = Approachf_3_00187770(D_00201D44, -2.99f, 3.5f);
    }
    if (!(D_00201D44 <= -2.99f)) {
        DbMap_DrawRing_0_001982A0(s, D_00201D44);
    }
    if (s >= 0) {
        s32 h = DbMap_GetName_0_00195A30(s);
        c.w = 0x80FFFFFF;
        Text_Draw_2_001875C0(h, 2, c, 622.0f, 17.0f, 1.0f);
    }
    UiAnim_UpdateAll_1_0017F5C0();
    Menu_DrawFrame_0_00185390(D_00201D44, 1, D_002021A8, D_004A18B0[0]);
}

/* DbMap_DrawRing_0_001982A0 */
void DbMap_DrawRing_0_001982A0(s32 arg, f32 ang) {
    u32 i;
    L *l;
    s8 *base;
    Ent e;
    V2 q;
f32 d, a, t, dx, dy;
    l = MenuLayout_Get_1_00189050(2)->l;
    base = MenuLayout_GetSub_1_00189020(2);
    Menu_DrawBackground_0_00187B20(0);
    for (i = 0; i < l->n; i++) {
        e = l->p[i];
        {
        V2 p = {0};
        if (e.f4 == 100 || e.f4 == 200) {
            p.x = -70.0f;
            p.y = 276.0f;
        q.x = e.x;
        q.y = e.y;
        dx = e.x - -70.0f;
        dy = e.y - 276.0f;
        d = sqrtf(dx * dx + dy * dy);
        t = Vec2_Angle_1_00187460(&q, &p);
        a = t + ang;
        e.x = -70.0f + d * sinf(a);
        e.y = 276.0f + d * cosf(a);
        } else {
            p.x = 735.0f;
            p.y = 129.0f;
        q.x = e.x;
        q.y = e.y;
        dx = e.x - 735.0f;
        dy = e.y - 129.0f;
        d = sqrtf(dx * dx + dy * dy);
        t = Vec2_Angle_1_00187460(&q, &p);
        a = t + ang;
        e.x = 735.0f + d * sinf(a);
        e.y = 129.0f + d * cosf(a);
        }
        }
        Ui_DrawList_1_001829B0(&e, base + l->p[i].idx * 8, DbMapProc_DrawInfo_1_00198570, arg);
    }
}
