#include "m2c.h"
typedef struct { u8 pad0[0xA]; u16 type; u8 pad1[0x30]; u8 max; u8 pad2[0x53]; } Rec;
typedef struct { u8 pad[8]; s8 st; u8 pad2[7]; } Out;
s32 func_001CCD90(s32);
u8 *func_001CCD30(s32);
Rec *func_001AFC90(void);
extern s16 D_001FD3F8[];
extern Out D_004A30E0[];

void func_0019C560(void) {
    s32 i;
    s32 idx;
    s32 max;
    u8 *cur;
    s16 *id;
    Out *o;
    Rec *r;
    u8 v;

    i = 0;
    max = 0;
    id = D_001FD3F8;
    o = D_004A30E0;
    do {
        idx = (s16)func_001CCD90(*id);
        cur = func_001CCD30(*id);
        r = &func_001AFC90()[idx];
        switch (r->type) {
        case 1:
            max = r->max;
            break;
        case 2:
            max = r->max;
            break;
        }
        if (cur != NULL) {
            v = *cur;
            if ((s32)(100.0f * ((f32)v / (f32)max)) < 20 || (v & 0xFF) < 5) {
                o->st = 1;
            } else {
                o->st = 0;
            }
        } else {
            o->st = 2;
        }
        i++;
        id++;
        o++;
    } while (i < 7);
}
