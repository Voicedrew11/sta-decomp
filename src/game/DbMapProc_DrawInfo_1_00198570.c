#include "common.h"
#include "m2c.h"
typedef union {
    u32 w;
    struct { u8 r, g, b, a; } c;
} Col;
typedef struct {
    u64 a, b;
    f32 x, y;
} S;
typedef struct {
    Vec v0;
    Vec v10;
    u8 pad20[8];
    s32 x28;
    Col x2C;
    f32 x30, x34, x38, x3C;
} A;
typedef struct { s32 x0; s32 x4; u8 pad8[8]; Vec x10; Vec x20; } B;
typedef struct { u8 pad[0x54]; u8 *x54; } P_DbMapProc_DrawInfo_1_00198570;
typedef struct { u8 pad[0xE]; u8 xE; } G;
typedef struct { s32 x0; s32 x4; u8 x8; u8 pad9[5]; u8 xE; } M;
typedef struct { u128 q[2]; } Q2;
typedef struct { s32 p; s32 n; f32 f; void *fn; s32 a; s32 b; void *cb; } Arg;
typedef struct { s32 x0; u32 n; } P_DbMap_ResetLayout_0_00198D80;
extern S D_001F2FE0 __attribute__((aligned(16)));
extern s32 D_004A1450[];
extern s32 D_004A18B0[];
extern u32 D_002021A4;
extern s8 D_001FD398[];
extern s8 D_001FD3A0[];
extern s8 D_001FD3B0[];
extern s8 D_001FD3C0[];
extern s8 D_001FD3C8[];
extern s8 D_001FD3D0[];
extern s8 D_001FD3E0[];
extern s8 D_001FD3E8[];
extern s8 D_004A1770[];
extern s8 D_004A1870[];
extern f32 D_004A1884[];
extern f32 D_004A1888[];
extern f32 D_004A189C[];
extern f32 D_004A18A0[];
extern u32 D_004A18AC[];
extern s32 D_002021A8;
extern f32 D_004A18B8[];
extern Q2 D_001F2FC0;
extern u32 D_002022B8;
extern s8 D_001FD3F0[];
void DbMapProc_DrawInfo_1_00198570(A *o, s32 mode, u32 kind);
void DbMap_UpdateWrap_0_00198BD0(s32 arg0);
void DbMap_Update_0_00198BE0(M *m);
void DbMap_ResetLayout_0_00198D80(void);
s8* DbMap_GetListName_1_00198F30(s32 a);
void Ui_DrawSprite_2_00181680(s32, Vec *, Vec *, Col *, S *, u32);
void Text_Draw_2_001875C0(f32, s8 *, f32, f32, s32, u32);
void sprintf(s8 *, s8 *, ...);
void strcpy(s8 *, s8 *);
G* PlayerData_Get_2_001C9BA0(void);
P_DbMapProc_DrawInfo_1_00198570* MenuLayout_GetSub_1_00189020(s32);
s32 MapState_IsVisited_1_001AA440(u32);
u16 MapState_GetBestKillRate_0_001AA090(s32);
u16 MapState_GetKillCount_0_001A9FF0(s32);
s32 DbMap_GetKillRate_0_001959E0(s32);
void Ui_DrawWindow_0_00183650(s8 *);
void DbMap_BuildList_1_00199000(void);
void Ui_SetOffset_0_001803D0(s32, s32);
void Snd_PlaySe_3_00131600(s32, s32);
void UiAnim_SetVisible_1_0017F7C0(s32, s32, s32);
s32 UiAnim_SetTarget_1_0017F470(f32, s32, s32);
void Ui_LoadAreaImage_3_00183970(s32);
void UiAnim_SetColor_0_0017F890(s32, Q2 *, Arg *);
P_DbMap_ResetLayout_0_00198D80* DbMap_GetCount_1_001958E0(void);
void DbMapProc_Pos_0_00199110(void);
s8* DbMap_GetLocationName_1_00195AA0(s32);

/* DbMapProc_DrawInfo_1_00198570 */

/* DbMapProc_DrawInfo_1_00198570 */
static inline f32 u2f(u32 x) { return x; }
static inline s32 any(u32 k) {
    u32 i;
    for (i = 0; (s32)i < 10; i++) {
        if (!(MapState_IsVisited_1_001AA440(k * 10 + i) != 0) == 0) return 1;
    }
    return 0;
}

void DbMapProc_DrawInfo_1_00198570(A *o, s32 mode, u32 kind) {
    S s __attribute__((aligned(16)));
    Col col;
    s32 n;
    s32 k;
    f32 f;
    u32 c;
    B *b;

    s = D_001F2FE0;
    n = D_004A1450[D_004A18B0[0]] * 10;
    {
        s8 buf[0x100] = {0};

        if (kind < 300) {
            if (PlayerData_Get_2_001C9BA0()->xE == 0 && mode == 200) return;
            s.x = o->x30;
            s.y = o->x34;
            if (kind == 0) {
                o->x2C.c.r = 0x40;
                o->x2C.c.g = 0x40;
                o->x2C.c.b = 0x40;
            }
            Ui_DrawSprite_2_00181680(o->x28, &o->v0, &o->v10, &o->x2C, &s, kind);
            return;
        }
        if (kind == 500) {
            b = (B *)(MenuLayout_GetSub_1_00189020(0)->x54 + 0x390);
            col.w = 0x30808080;
            s.x = o->x38;
            s.y = o->x3C;
            Ui_DrawSprite_2_00181680(b->x4, &b->x10, &b->x20, &col, &s, kind);
        }
        if (kind == 501) {
            col.w = 0x80808080;
            sprintf(buf, D_001FD398, D_002021A4);
            Text_Draw_2_001875C0(o->x38, buf, o->x3C, 0.9f, 2, col.w);
        }
        if (mode == 100) {
            if (kind == 400) {
                col.w = 0x80808080;
                strcpy(buf, D_001FD3A0);
                Text_Draw_2_001875C0(o->x38, buf, o->x3C, 0.9f, 0, col.w);
            }
            if (kind == 401) {
                col.w = 0x80808080;
                if (n < 0) {
                    strcpy(D_004A1770, D_001FD3B0);
                    strcpy(buf, D_001FD3B0);
                } else {
                    k = n / 10;
                    if (any(n / 10)) {
                        c = MapState_GetBestKillRate_0_001AA090(k * 10);
                        f = 100.0f * (u2f(c) / (f32)DbMap_GetKillRate_0_001959E0(k));
                        if (DbMap_GetKillRate_0_001959E0(k) == 0) {
                            sprintf(buf, D_001FD3C0, (s32)f);
                        } else {
                            sprintf(buf, D_001FD3C8, (s32)f);
                        }
                    } else {
                        strcpy(buf, D_001FD3B0);
                    }
                }
                Text_Draw_2_001875C0(o->x38, buf, o->x3C, 0.9f, 0, col.w);
            }
        }
        if (PlayerData_Get_2_001C9BA0()->xE != 0 && mode == 200) {
            if (kind == 400) {
                col.w = 0x80808080;
                strcpy(buf, D_001FD3D0);
                Text_Draw_2_001875C0(o->x38, buf, o->x3C, 0.9f, 0, col.w);
            }
            if (kind == 401) {
                col.w = 0x80808080;
                if (n < 0) {
                    strcpy(D_004A1770, D_001FD3B0);
                    strcpy(buf, D_001FD3B0);
                } else {
                    k = n / 10;
                    if (any(n / 10)) {
                        c = MapState_GetKillCount_0_001A9FF0(k * 10);
                        f = 100.0f * (u2f(c) / (f32)DbMap_GetKillRate_0_001959E0(k));
                        if (DbMap_GetKillRate_0_001959E0(k) == 0) {
                            sprintf(buf, D_001FD3E0, (s32)f);
                        } else {
                            sprintf(buf, D_001FD3E8, (s32)f);
                        }
                    } else {
                        strcpy(buf, D_001FD3B0);
                    }
                }
                Text_Draw_2_001875C0(o->x38, buf, o->x3C, 0.9f, 0, col.w);
            }
        }
        if (kind == 10001) {
            D_004A189C[0] = o->x38;
            D_004A18A0[0] = o->x3C;
            D_004A1884[0] = 1.25f;
            D_004A18AC[0] = 0x80FFFFFF;
            D_004A1888[0] = 1.25f;
            Ui_DrawWindow_0_00183650(D_004A1870);
        }
    }
}

/* DbMap_UpdateWrap_0_00198BD0 */
void DbMap_UpdateWrap_0_00198BD0(s32 arg0) {
    DbMap_Update_0_00198BE0((void *) arg0);
}

/* DbMap_Update_0_00198BE0 */

void DbMap_Update_0_00198BE0(M *m) {
    s32 sel;
    s32 old;
    switch (m->x0) {
    case 0x19:
        D_004A18B0[0] = 0;
        DbMap_BuildList_1_00199000();
        DbMap_ResetLayout_0_00198D80();
        break;
    case 0x16:
        old = D_004A18B0[0];
        sel = old;
        if (m->x4 & 0x4000) {
            Ui_SetOffset_0_001803D0(-2, -2);
            Snd_PlaySe_3_00131600(0x69, m->xE);
            m->x8 = 0x18;
            m->x4 = 0;
            m->x0 = 0x1A;
            UiAnim_SetVisible_1_0017F7C0(0, 0, 1);
            return;
        }
        if (m->x4 & 0x10) {
            sel = old - 1;
        } else if (m->x4 & 0x40) {
            sel = old + 1;
        }
        if (D_002021A8 != 0) {
            sel = (sel + D_002021A8) % D_002021A8;
        }
        if (UiAnim_SetTarget_1_0017F470(old, 0, 0)) {
            if (D_004A18B0[0] != sel) {
                Snd_PlaySe_3_00131600(0x66, m->xE);
            }
            D_004A18B0[0] = sel;
        } else {
            D_004A18B8[0] = 10.0f;
        }
        break;
    }
    Ui_LoadAreaImage_3_00183970(D_004A1450[D_004A18B0[0]] * 10);
}

/* DbMap_ResetLayout_0_00198D80 */

void DbMap_ResetLayout_0_00198D80(void) {
    Q2 q;
    Arg a;
    P_DbMap_ResetLayout_0_00198D80 *p;
    u32 i;
    u32 j;
    s32 cnt;
    s32 found;

    Ui_SetOffset_0_001803D0(D_002022B8 / 10, -2);
    p = DbMap_GetCount_1_001958E0();
    if (p != 0) {
        cnt = 0;
        for (i = 1; i < p->n + 1; i++) {
            found = 0;
            for (j = 0; j < 10; j++) {
                if (MapState_IsVisited_1_001AA440(j + i * 10)) {
                    found = 1;
                }
            }
            if (found) {
                cnt++;
            }
        }
        D_002021A4 = (u32)(cnt * 100) / p->n;
        q = D_001F2FC0;
        a.p = (s32)D_004A1450;
        a.fn = DbMap_GetListName_1_00198F30;
        a.f = -3.0f;
        a.cb = DbMapProc_Pos_0_00199110;
        a.a = 0;
        a.b = 0;
        a.n = D_002021A8;
        UiAnim_SetColor_0_0017F890(0, &q, &a);
        UiAnim_SetVisible_1_0017F7C0(0, 1, 1);
        UiAnim_SetTarget_1_0017F470(D_004A18B0[0], 0, 1);
    }
}
#undef DbMapProc_DrawInfo_1_00198570
#undef DbMap_Update_0_00198BE0

/* DbMap_GetListName_1_00198F30 */

s8 *DbMap_GetListName_1_00198F30(s32 a) {
    s32 i;
    s32 found;
    s32 k;
    if (a < 0) {
        return D_001FD3B0;
    }
    found = 0;
    for (i = 0, k = a * 10; i < 10; i++, k++) {
        if (MapState_IsVisited_1_001AA440(k)) {
            found = 1;
        }
    }
    if (found) {
        sprintf(D_004A1770, D_001FD3F0, DbMap_GetLocationName_1_00195AA0(a));
        return D_004A1770;
    }
    return D_001FD3B0;
}
