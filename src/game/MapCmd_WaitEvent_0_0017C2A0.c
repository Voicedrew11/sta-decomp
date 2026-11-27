#include "m2c.h"
typedef struct { u8 pad0[8]; u8 x8; u8 pad9[7]; s32 x10; } P;
s32 *Script_GetArgPtr_2_00165130(P *, s32);
void Game_SetBusy_1_0012C030(s32);
extern s32 D_00202038;

void MapCmd_WaitEvent_0_0017C2A0(P *p) {
    s32 dummy;
    s32 *r;
    s32 mode;
    u8 m;
    s32 kind;

    m = p->x8;
    kind = p->x10;
    r = Script_GetArgPtr_2_00165130(p, 2);
    if (r == NULL) {
        *r = 0;
        r = &dummy;
    } else {
        *r = 1;
    }
    mode = m;
    if (mode < 0 || mode >= 2) {
        *r = 0;
        return;
    }
    switch (kind) {
    case 0:
        switch (mode) {
        case 0:
            if (D_00202038 <= 0) { *r = 0; } else { D_00202038--; *r = 1; }
            break;
        case 1:
            if (D_00202038 >= 0xFF) { *r = 0; } else { D_00202038++; *r = 1; }
            break;
        }
        break;
    case 1:
        switch (mode) {
        case 0:
            if (D_00202038 <= 0) { *r = 0; } else { D_00202038--; *r = 1; }
            break;
        case 1:
            if (D_00202038 != 0) { *r = 0; } else { D_00202038++; *r = 1; }
            break;
        }
        break;
    case 2:
        switch (mode) {
        case 0:
            break;
        case 1:
            if (D_00202038 >= 0xFF) { *r = 0; } else { D_00202038++; *r = 1; }
            break;
        }
        break;
    default:
        *r = 0;
        break;
    }
    if (D_00202038 == 0) {
        Game_SetBusy_1_0012C030(0);
    } else if (D_00202038 > 0) {
        Game_SetBusy_1_0012C030(1);
    }
}
