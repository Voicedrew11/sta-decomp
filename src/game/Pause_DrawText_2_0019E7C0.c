#include "common.h"
typedef struct { u8 r, g, b, a; } Col;
typedef struct { s32 x0; u32 x4; u8 b8; char p9[5]; u8 bE; } Obj;
extern char D_001FD650[];
void Pause_DrawText_2_0019E7C0(void);
void Pause_HandleEvent_0_0019E810(Obj *o);
void Text_Draw_2_001875C0(void *p, s32 n, Col c, f32 x, f32 y, f32 s);
void PlayTime_Pause_1_001DF990(void);
void PlayTime_Resume_1_001DF960(void);
void Snd_PlaySe_3_00131600(s32 a, u8 b);

/* Pause_DrawText_2_0019E7C0 */
void Pause_DrawText_2_0019E7C0(void)
{
    Col c;
    *(u32 *)&c = 0x80808080;
    Text_Draw_2_001875C0(D_001FD650, 1, c, 320.0f, 200.0f, 1.0f);
}

/* Pause_HandleEvent_0_0019E810 */
void Pause_HandleEvent_0_0019E810(Obj *o)
{
    if (o->x0 == 25)
        PlayTime_Pause_1_001DF990();
    if (o->x0 == 22 && ((o->x4 & 1) || (o->x4 & 0x4000))) {
        Snd_PlaySe_3_00131600(0x65, o->bE);
        o->b8 = 18;
        o->x4 = 0;
        o->x0 = 31;
        PlayTime_Resume_1_001DF960();
    }
}
