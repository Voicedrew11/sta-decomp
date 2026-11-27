#include "m2c.h"
typedef union { u32 w; struct { u8 r, g, b, a; } c; } Col;
typedef struct { u32 w[15]; Col col; } Buf;
typedef struct { u8 pad[0x94]; u8 x94; } P;
typedef struct { u8 pad[0x20]; u16 x20; u8 pad22[0x6E]; } E;
typedef struct { s32 k0; s32 k4; u8 t8; u8 pad[7]; } K;
extern s32 D_00201D60;
extern s32 D_00201D64;
extern f32 D_002021D0;
extern f32 D_002020D4;
extern K D_004A30E0[];
P *PlayerData_Get_2_001C9BA0(void);
s32 Equip_GetSlotItem_1_001CCD90(s32);
E *Item_GetTable_1_001AFC90(void);
s32 Item_GetCategory_0_001AFBD0(s32);
void Color_Pulse_1_00187960(f32, Col *);
void Color_Double_0_001878A0(f32, Col *);
void Ui_DrawElem_1_00182C10(Buf *, s32);
static inline s32 kind(s32 idx, E *e) {
    if (idx < 0) return -1;
    Item_GetCategory_0_001AFBD0(idx);
    switch (e->x20) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 14:
        return 1;
    case 2: case 4: case 6: case 9: case 11: case 12: case 13: case 15: case 16: case 17: case 18: case 19:
        return 2;
    }
    return -1;
}

void Hud_DrawShortcuts_0_0019BBE0(Buf *src, s32 a1, s32 key) {
    u32 i;
    P *p;
    s32 idx;
    K *k;
    E *e;
    Buf buf;

    p = PlayerData_Get_2_001C9BA0();
    if (D_00201D64 != (p->x94 & 1) || D_00201D60 != (s16)Equip_GetSlotItem_1_001CCD90(0)) {
        D_00201D64 = p->x94 & 1;
        D_00201D60 = (s16)Equip_GetSlotItem_1_001CCD90(0);
        D_002021D0 = 150.0f;
    }
    i = 0;
    k = D_004A30E0;
    do {
        if (key == k->k0 || key == k->k4) {
            buf = *src;
            if (k->t8 == 2) {
                buf.col.c.a = buf.col.c.a * 48 / 128;
            } else if (k->t8 == 1) {
                buf.col.w = 0x80101080;
                Color_Pulse_1_00187960(D_002020D4, &buf.col);
            }
            idx = (s16)Equip_GetSlotItem_1_001CCD90(0);
            e = &Item_GetTable_1_001AFC90()[idx];
            switch (kind(idx, e)) {
            case 0:
                break;
            case 1:
                if (i == 6 && !(p->x94 & 1)) {
                    Color_Double_0_001878A0(D_002020D4, &buf.col);
                    if (!(D_002021D0 <= 0.0f)) D_002021D0 -= 1.0f;
                }
                if (i == 5 && (p->x94 & 1) == 1) {
                    if (!(D_002021D0 <= 0.0f)) D_002021D0 -= 1.0f;
                }
                break;
            case 2:
                if (i == 6 || i == 5) {
                    Color_Double_0_001878A0(D_002020D4, &buf.col);
                    if (!(D_002021D0 <= 0.0f)) D_002021D0 -= 1.0f;
                }
                break;
            }
            idx = (s16)Equip_GetSlotItem_1_001CCD90(1);
            e = &Item_GetTable_1_001AFC90()[idx];
            switch (kind(idx, e)) {
            case 1:
                if (i == 5 && (p->x94 & 1) == 1) {
                    Color_Double_0_001878A0(D_002020D4, &buf.col);
                    if (!(D_002021D0 <= 0.0f)) D_002021D0 -= 1.0f;
                }
                break;
            }
            Ui_DrawElem_1_00182C10(&buf, a1);
        }
        i++;
        k++;
    } while (i < 7);
}
