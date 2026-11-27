#include "common.h"

typedef struct { u8 r, g, b, a; } Col;
extern char D_001FD650[];
void Text_Draw_2_001875C0(void *p, s32 n, Col c, f32 x, f32 y, f32 s);

void Pause_DrawText_2_0019E7C0(void)
{
    Col c;
    *(u32 *)&c = 0x80808080;
    Text_Draw_2_001875C0(D_001FD650, 1, c, 320.0f, 200.0f, 1.0f);
}
