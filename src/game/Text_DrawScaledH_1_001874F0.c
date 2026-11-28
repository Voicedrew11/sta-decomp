#include "common.h"
typedef union { u32 w; struct { u8 r, g, b, a; } c; } C_Text_DrawScaledH_1_001874F0;
typedef struct { u8 a:3; u8 c:1; u8 d:1; u8 e:3; } BF;
typedef struct {
    f32 x0;
    f32 x4;
    BF x8;
    u8 pad9[3];
    s16 xC;
    u8 padE[6];
    f32 x14;
    u8 pad18[8];
    f32 x20;
    f32 x24;
    s8 *x28;
} T;
typedef struct { u32 w; } C_Text_Draw_2_001875C0;
typedef struct { f32 x; f32 y; u8 b:3; u8 r:5; u8 p9[0xB]; f32 x64; u8 p68[8]; f32 z; f32 x74; } S;
typedef union { u32 w; struct { u8 r, g, b, a; } c; } C_Text_DrawCentered_1_00187680;
void Text_DrawScaledH_1_001874F0(s16 h, s8 *str, u32 a, C_Text_DrawScaledH_1_001874F0 col, f32 x, f32 y, f32 sc);
void Text_Draw_2_001875C0(char *str, s32 k, C_Text_Draw_2_001875C0 c, f32 x, f32 y, f32 z);
void Text_DrawCentered_1_00187680(s8 *str, u32 a, s16 h, C_Text_DrawCentered_1_00187680 col, f32 x, f32 y, f32 sc);
u32 strlen(void *);
void TextParam_Init_1_00187A90(void *, void *, u64);
s32 Text_Render_2_00188010(void *, C_Text_DrawScaledH_1_001874F0);

/* Text_DrawScaledH_1_001874F0 */
void Text_DrawScaledH_1_001874F0(s16 h, s8 *str, u32 a, C_Text_DrawScaledH_1_001874F0 col, f32 x, f32 y, f32 sc) {
    T t;
    if (str == 0) return;
    TextParam_Init_1_00187A90(&t, str, strlen(str));
    t.x0 = x;
    t.x4 = y;
    t.xC = h;
    t.x8.a = a;
    t.x24 = 1.0f;
    t.x20 = sc;
    t.x14 = 4096.0f;
    Text_Render_2_00188010(&t, col);
}

/* Text_Draw_2_001875C0 */
#define strlen strlen__as_Text_Draw_2_001875C0
u32 strlen__as_Text_Draw_2_001875C0(char *);
#define TextParam_Init_1_00187A90 TextParam_Init_1_00187A90__as_Text_Draw_2_001875C0
void TextParam_Init_1_00187A90__as_Text_Draw_2_001875C0(S *, char *, u64);
#define Text_Render_2_00188010 Text_Render_2_00188010__as_Text_Draw_2_001875C0
void Text_Render_2_00188010__as_Text_Draw_2_001875C0(S *, C_Text_Draw_2_001875C0);
void Text_Draw_2_001875C0(char *str, s32 k, C_Text_Draw_2_001875C0 c, f32 x, f32 y, f32 z) {
    S s;
    if (str != NULL) {
        TextParam_Init_1_00187A90(&s, str, strlen(str));
        s.x74 = 1.0f;
        s.b = k;
        s.x = x;
        s.y = y;
        s.x64 = 4096.0f;
        s.z = z;
        Text_Render_2_00188010(&s, c);
    }
}
#undef strlen
#undef TextParam_Init_1_00187A90
#undef Text_Render_2_00188010

/* Text_DrawCentered_1_00187680 */
#define Text_Render_2_00188010 Text_Render_2_00188010__as_Text_DrawCentered_1_00187680
s32 Text_Render_2_00188010__as_Text_DrawCentered_1_00187680(void *, C_Text_DrawCentered_1_00187680);

void Text_DrawCentered_1_00187680(s8 *str, u32 a, s16 h, C_Text_DrawCentered_1_00187680 col, f32 x, f32 y, f32 sc) {
    T t;
    if (str == 0) {
        return;
    }
    TextParam_Init_1_00187A90(&t, str, strlen(str));
    t.x0 = x;
    t.x4 = y;
    t.x8.a = a;
    t.x24 = 1.0f;
    t.x20 = sc;
    t.x14 = 4096.0f;
    t.x8.d = 1;
    t.xC = h;
    Text_Render_2_00188010(&t, col);
}
#undef Text_Render_2_00188010
