#include "common.h"
void func_001AB690();
void func_00128580(s32, s32);                    /* extern */
void func_0014DAB0(s32);                         /* extern */
void func_0014DB10(void (*)());                  /* extern */
void memset(s32 *, s32, s32);            /* extern */
extern s32 D_00202288;
extern s32 D_0020228C;
extern s32 D_00202290;
extern s32 D_004B4B70[];
extern s32 D_004B4B74[];
extern s32 D_004B4B80[];
extern s32 D_004B4B88[];

void func_001AF980(void) {
    func_001AFA20();
    memset(D_004B4B70, 0, 0x1C);
    func_0014DB10(func_001AB690);
    if ((*D_004B4B80) != 0) {
        func_00128580(D_00202290, (*D_004B4B80));
    }
    if ((*D_004B4B74) != 0) {
        func_0014DAB0((*D_004B4B74));
        (*D_004B4B74) = 0;
    }
    (*D_004B4B80) = 0;
    D_00202288 = 0;
    (*D_004B4B74) = 0;
    D_0020228C = 0;
    (*D_004B4B70) = 0;
    (*D_004B4B88) = 0;
}
