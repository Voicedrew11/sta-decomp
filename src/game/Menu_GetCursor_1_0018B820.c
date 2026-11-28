#include "common.h"
extern s32 D_00202120[2];
s32 Menu_GetCursor_1_0018B820(s32 i);
void Menu_SetCursor_1_0018B840(s32 i, s32 v);

/* Menu_GetCursor_1_0018B820 */
s32 Menu_GetCursor_1_0018B820(s32 i)
{
    return D_00202120[i];
}

/* Menu_SetCursor_1_0018B840 */
void Menu_SetCursor_1_0018B840(s32 i, s32 v)
{
    D_00202120[i] = v;
}
